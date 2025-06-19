/*
 * 该脚本文件处理SameGame游戏的核心逻辑
 * 依赖QtQuick本地存储和基础模块
 */
.import QtQuick.LocalStorage 2.0 as Sql
.import QtQuick 2.0 as Quick

// 游戏全局变量定义
var maxColumn = 10;       // 棋盘最大列数
var maxRow = 15;          // 棋盘最大行数
var maxIndex = maxColumn * maxRow;  // 总块数索引上限
var board = new Array(maxIndex);    // 存储所有块对象的数组
var component;            // 用于动态创建块的组件引用
var scoresURL = "";       // 高分上传接口地址
var gameDuration;         // 记录游戏持续时间

/**
 * 计算二维坐标对应的一维索引
 * @param {number} column - 列坐标（0-based）
 * @param {number} row - 行坐标（0-based）
 * @returns {number} 一维索引值
 */
function index(column, row) {
    return column + (row * maxColumn);
}

/**
 * 开始新游戏的核心逻辑
 */
function startNewGame() {
    // 清理上一局的所有块
    for (var i = 0; i < maxIndex; i++) {
        if (board[i] != null)
            board[i].destroy();  // 销毁旧块对象
    }

    // 根据画布尺寸调整棋盘大小
    maxColumn = Math.floor(gameCanvas.width / gameCanvas.blockSize);  // 计算实际列数
    maxRow = Math.floor(gameCanvas.height / gameCanvas.blockSize);     // 计算实际行数
    maxIndex = maxRow * maxColumn;  // 更新总块数

    // 关闭所有对话框
    nameInputDialog.hide();
    dialog.hide();

    // 初始化棋盘数组
    board = new Array(maxIndex);
    gameCanvas.score = 0;  // 重置分数

    // 生成新的游戏块
    for (var column = 0; column < maxColumn; column++) {
        for (var row = 0; row < maxRow; row++) {
            board[index(column, row)] = null;
            createBlock(column, row);  // 创建新块
        }
    }

    gameDuration = new Date();  // 记录游戏开始时间
}

/**
 * 创建单个游戏块
 * @param {number} column - 块的目标列坐标
 * @param {number} row - 块的目标行坐标
 * @returns {boolean} 创建成功状态
 */
function createBlock(column, row) {
    // 初始化块组件（仅首次创建时加载）
    if (component == null)
        component = Qt.createComponent("BoomBlock.qml");  // 加载块组件定义

    // 检查组件加载状态
    if (component.status == Quick.Component.Ready) {
        // 动态创建块对象
        var dynamicObject = component.createObject(gameCanvas);
        if (dynamicObject == null) {
            console.log("error creating block");
            console.log(component.errorString());
            return false;
        }

        // 配置块属性
        dynamicObject.type = Math.floor(Math.random() * 3);  // 随机生成块类型（0-2）
        dynamicObject.x = column * gameCanvas.blockSize;     // 计算X坐标
        dynamicObject.y = row * gameCanvas.blockSize;        // 计算Y坐标
        dynamicObject.width = gameCanvas.blockSize;          // 设置宽度
        dynamicObject.height = gameCanvas.blockSize;         // 设置高度
        dynamicObject.spawned = true;                        // 标记为已生成

        // 存储到棋盘数组
        board[index(column, row)] = dynamicObject;
    } else {
        console.log("error loading block component");
        console.log(component.errorString());
        return false;
    }
    return true;
}

var fillFound;  // floodFill后找到的相连块数量
var floodBoard; // 记录已访问块的标记数组

/**
 * 处理鼠标点击事件
 * @param {number} xPos - 点击位置的X坐标
 * @param {number} yPos - 点击位置的Y坐标
 */
function handleClick(xPos, yPos) {
    // 将点击坐标转换为棋盘行列
    var column = Math.floor(xPos / gameCanvas.blockSize);  // 计算列坐标
    var row = Math.floor(yPos / gameCanvas.blockSize);     // 计算行坐标

    // 边界检查
    if (column >= maxColumn || column < 0 || row >= maxRow || row < 0)
        return;

    // 检查该位置是否有块
    if (board[index(column, row)] == null)
        return;

    // 执行洪水填充算法查找相连块
    floodFill(column, row, -1);

    // 至少需要2个相连块才能消除
    if (fillFound <= 0)
        return;

    // 计算得分：(相连块数-1)的平方
    gameCanvas.score += (fillFound - 1) * (fillFound - 1);

    // 处理块下落逻辑
    shuffleDown();

    // 检查游戏胜利条件
    victoryCheck();
}

/**
 * 洪水填充算法（递归实现）查找相连同类型块
 * @param {number} column - 当前处理的列坐标
 * @param {number} row - 当前处理的行坐标
 * @param {number} type - 目标块类型（-1表示初始调用）
 */
function floodFill(column, row, type) {
    // 检查当前位置是否有块
    if (board[index(column, row)] == null)
        return;

    var first = false;
    // 初始调用时获取目标块类型
    if (type == -1) {
        first = true;
        type = board[index(column, row)].type;

        // 初始化洪水填充状态
        fillFound = 0;
        floodBoard = new Array(maxIndex);  // 创建标记数组
    }

    // 边界检查
    if (column >= maxColumn || column < 0 || row >= maxRow || row < 0)
        return;

    // 检查是否已访问或类型不符
    if (floodBoard[index(column, row)] == 1 || (!first && type != board[index(column, row)].type))
        return;

    // 标记当前块为已访问
    floodBoard[index(column, row)] = 1;

    // 递归检查四个方向（上下左右）
    floodFill(column + 1, row, type);  // 右
    floodFill(column - 1, row, type);  // 左
    floodFill(column, row + 1, type);  // 下
    floodFill(column, row - 1, type);  // 上

    // 初始调用时处理消除逻辑（单个块不消除）
    if (first == true && fillFound == 0)
        return;     // 无法消除单个块

    // 标记该块为待销毁并从棋盘移除
    board[index(column, row)].dying = true;
    board[index(column, row)] = null;
    fillFound += 1;  // 增加相连块计数
}

/**
 * 处理块消除后的下落和左移逻辑
 */
function shuffleDown() {
    // 第一阶段：处理块下落（逐列处理）
    for (var column = 0; column < maxColumn; column++) {
        var fallDist = 0;  // 记录下落距离
        // 从下往上遍历行
        for (var row = maxRow - 1; row >= 0; row--) {
            if (board[index(column, row)] == null) {
                fallDist += 1;  // 空位置增加下落距离
            } else {
                if (fallDist > 0) {
                    // 移动块到下方空位置
                    var obj = board[index(column, row)];
                    obj.y = (row + fallDist) * gameCanvas.blockSize;  // 更新Y坐标
                    board[index(column, row + fallDist)] = obj;       // 移动到新位置
                    board[index(column, row)] = null;                 // 原位置置空
                }
            }
        }
    }

    // 第二阶段：处理列左移（逐列处理）
    var fallDist = 0;
    for (var column = 0; column < maxColumn; column++) {
        // 检查该列顶部是否有块（判断该列是否为空）
        if (board[index(column, maxRow - 1)] == null) {
            fallDist += 1;  // 空列增加左移距离
        } else {
            if (fallDist > 0) {
                // 将当前列内容左移
                for (var row = 0; row < maxRow; row++) {
                    var obj = board[index(column, row)];
                    if (obj == null)
                        continue;
                    obj.x = (column - fallDist) * gameCanvas.blockSize;  // 更新X坐标
                    board[index(column - fallDist, row)] = obj;          // 移动到新列
                    board[index(column, row)] = null;                    // 原列位置置空
                }
            }
        }
    }
}

/**
 * 检查游戏胜利条件
 */
function victoryCheck() {
    // 检查是否所有列顶部都没有块（即棋盘已清空）
    var deservesBonus = true;
    for (var column = maxColumn - 1; column >= 0; column--) {
        if (board[index(column, maxRow - 1)] != null)
            deservesBonus = false;
    }

    // 清空棋盘时奖励500分
    if (deservesBonus)
        gameCanvas.score += 500;

    // 检查游戏是否结束（清空棋盘 或 无可用移动）
    if (deservesBonus || !(floodMoveCheck(0, maxRow - 1, -1))) {
        gameDuration = new Date() - gameDuration;  // 计算游戏耗时
        nameInputDialog.showWithInput("You won! Please enter your name: ");  // 显示输入姓名对话框
    }
}

/**
 * 检查是否存在可移动的块（即是否有相连同类型块）
 * @param {number} column - 当前检查的列坐标
 * @param {number} row - 当前检查的行坐标
 * @param {number} type - 目标块类型（-1表示初始调用）
 * @returns {boolean} 是否存在可移动块
 */
function floodMoveCheck(column, row, type) {
    // 边界检查
    if (column >= maxColumn || column < 0 || row >= maxRow || row < 0)
        return false;

    // 检查该位置是否有块
    if (board[index(column, row)] == null)
        return false;

    var myType = board[index(column, row)].type;

    // 找到相同类型块
    if (type == myType)
        return true;

    // 递归检查右方和上方（避免重复检查）
    return floodMoveCheck(column + 1, row, myType) || floodMoveCheck(column, row - 1, board[index(column, row)].type);
}

/**
 * 保存本地高分记录
 * @param {string} name - 用户输入的姓名
 */
function saveHighScore(name) {
    // 上传到远程服务器（如果有配置地址）
    if (scoresURL != "")
        sendHighScore(name);

    // 使用本地存储保存记录
    var db = Sql.LocalStorage.openDatabaseSync("SameGameScores", "1.0", "Local SameGame High Scores", 100);
    var dataStr = "INSERT INTO Scores VALUES(?, ?, ?, ?)";
    var data = [name, gameCanvas.score, maxColumn + "x" + maxRow, Math.floor(gameDuration / 1000)];

    db.transaction(function(tx) {
        // 创建表（如果不存在）
        tx.executeSql('CREATE TABLE IF NOT EXISTS Scores(name TEXT, score NUMBER, gridSize TEXT, time NUMBER)');
        // 插入新记录
        tx.executeSql(dataStr, data);

        // 查询并显示标准尺寸网格的高分榜
        var rs = tx.executeSql('SELECT * FROM Scores WHERE gridSize = "12x17" ORDER BY score desc LIMIT 10');
        var r = "\nHIGH SCORES for a standard sized grid\n\n"
        for (var i = 0; i < rs.rows.length; i++) {
            r += (i + 1) + ". " + rs.rows.item(i).name + ' got ' + rs.rows.item(i).score + ' points in ' + rs.rows.item(i).time + ' seconds.\n';
        }
        dialog.show(r);  // 显示高分榜
    });
}

/**
 * 上传高分到远程服务器
 * @param {string} name - 用户姓名
 */
function sendHighScore(name) {
    var postman = new XMLHttpRequest();
    var postData = "name=" + name + "&score=" + gameCanvas.score + "&gridSize=" + maxColumn + "x" + maxRow + "&time=" + Math.floor(gameDuration / 1000);

    postman.open("POST", scoresURL, true);
    postman.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");

    // 处理响应
    postman.onreadystatechange = function() {
        if (postman.readyState == postman.DONE) {
            dialog.show("Your score has been uploaded.");  // 显示上传成功提示
        }
    }

    postman.send(postData);  // 发送POST请求
}

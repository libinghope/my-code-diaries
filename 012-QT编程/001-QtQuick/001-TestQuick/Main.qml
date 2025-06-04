// 导入Qt Quick基础模块（所有QML应用必须的核心模块，提供基础UI组件支持）
import QtQuick

/**
* 应用主窗口（QML应用的根容器）
* Window是Qt Quick提供的顶级窗口类型，用于管理应用的主界面
* 所有顶层UI元素必须作为Window的子组件存在
*/
Window {
    // 窗口宽度（640像素，设备无关像素单位）
    width: 640
    // 窗口高度（640像素）
    height: 640
    // 窗口可见性（设置为true时窗口会显示，程序启动后自动展示界面）
    visible: true
    // 窗口标题（使用qsTr处理国际化，当前为英文"Hello World"）
    title: qsTr("Hello World")

    //----------------------------------------
    /**
    * 主内容容器（红色背景的矩形区域）
    * 作为窗口内的主要内容区域，用于容纳文本和颜色选择器
    * 未设置x/y锚点时默认位于窗口左上角（0, 0）位置
    */
    Rectangle {
        // 容器唯一标识（用于内部组件引用，其他组件可通过page.id访问）
        id: page
        // 容器尺寸（宽320像素，高480像素，约为窗口一半宽度）
        width: 320; height: 480
        // 容器背景颜色（红色，使用标准颜色名称定义）
        color: "red"

        /**
        * 显示文本的组件（核心展示内容）
        * id: helloText 用于后续通过颜色选择器修改其颜色
        * 包含鼠标交互和动画效果的核心逻辑
        */
        Text {
            id: helloText
            text: "Hello world!"
            // y轴偏移量（距离父容器顶部30像素）
            y: 30
            // 水平居中锚定（相对于page容器水平居中显示）
            anchors.horizontalCenter: page.horizontalCenter
            // 字体样式（24磅字号，粗体）
            font.pointSize: 24; font.bold: true

            /**
            * 鼠标交互区域（覆盖Text组件范围）
            * id: mouseArea 用于监听鼠标按下/释放事件
            * anchors.fill: parent 表示完全覆盖父组件（Text）的区域
            */
            MouseArea { id: mouseArea; anchors.fill: parent }

            /**
            * 组件状态定义（处理交互时的属性变化）
            * 当满足when条件时激活该状态，自动应用PropertyChanges中的属性修改
            */
            states: State {
                // 状态名称（用于标识状态，可通过状态机切换）
                name: "down"
                // 触发条件（当鼠标按下时激活该状态）
                when: mouseArea.pressed == true
                // 状态激活时需要修改的属性集合
                PropertyChanges {
                    // 指定要修改的目标组件（当前Text实例）
                    target: helloText
                    // 鼠标按下时的y坐标（从初始30像素变为160像素，向下移动）
                    y: 160
                    // 旋转角度（180度，文本上下翻转）
                    rotation: 180
                    // 文字颜色（保持红色，此处可根据需求修改）
                    color: "green"
                }
            }

            /**
            * 状态过渡动画（定义状态切换时的渐变效果）
            * reversible: true 表示状态切换（激活/取消）使用相同动画
            */
            transitions: Transition {
                // 从空状态（初始状态）过渡到"down"状态
                from: ""; to: "down"
                // 动画可逆（鼠标释放时自动反向播放动画）
                reversible: true
                // ParallelAnimation并行执行多个动画（同时进行位置、旋转和颜色变化）, 还有串行动画SequenceAnimation
                ParallelAnimation {
                    /**
                    * 数值属性动画（处理y坐标和旋转角度的渐变）
                    * properties: "y, rotation" 表示同时动画这两个属性
                    * duration: 500ms 动画总时长
                    * easing.type: Easing.InOutQuad 缓动类型（先加速后减速）
                    */
                    NumberAnimation { properties: "y, rotation"; duration: 500; easing.type: Easing.InOutQuad }
                    /**
                    * 颜色属性动画（处理颜色渐变，默认作用于目标组件的color属性）
                    * duration: 500ms 与数值动画同步完成
                    */
                    ColorAnimation { duration: 500 }
                }
            }
        }

        /**
        * 颜色选择器布局（网格布局容器）
        * 用于排列6个Cell颜色选择按钮，固定在主内容容器底部
        */
        Grid {
            // 网格唯一标识（用于组件引用）
            id: colorPicker
            // 水平位置（距离主内容容器左侧4像素，保持边距）
            x: 4
            // 底部锚定（相对于page容器的底部，保留4像素边距，固定在底部）
            anchors.bottom: page.bottom; anchors.bottomMargin: 4
            // 网格行数（2行）和列数（3列），总共有6个单元格（2*3）
            rows: 2; columns: 3
            // 子组件间距（3像素，按钮之间的间隔）
            spacing: 3

            /**
            * 颜色选择按钮（使用自定义Cell组件）
            * 每个Cell设置不同的cellColor属性，并绑定点击事件修改helloText颜色
            * 假设Cell组件已定义（通常包含背景颜色和点击反馈效果）
            */
            Cell { cellColor: "red"; onClicked: helloText.color = cellColor }
            Cell { cellColor: "green"; onClicked: helloText.color = cellColor }
            Cell { cellColor: "blue"; onClicked: helloText.color = cellColor }
            Cell { cellColor: "yellow"; onClicked: helloText.color = cellColor }
            Cell { cellColor: "steelblue"; onClicked: helloText.color = cellColor }
            Cell { cellColor: "black"; onClicked: helloText.color = cellColor }
        }
    }
}
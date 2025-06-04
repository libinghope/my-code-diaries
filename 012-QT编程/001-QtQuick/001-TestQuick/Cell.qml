// 导入Qt Quick基础模块（所有QML应用必须的核心模块）
import QtQuick

/**
 * 自定义组件Cell（可复用的QML组件）
 * 根类型选择Item：QML中最基础的可视化容器类型（无默认外观，适合作为容器）
 */
Item {
    // 组件根对象的id（用于内部组件间引用）
    id: container

    /**
     * 定义属性别名（暴露内部Rectangle的color属性给外部使用）
     * property alias 允许外部通过cellColor直接访问/修改rectangle.color
     */
    property alias cellColor: rectangle.color

    /**
     * 定义点击信号（用于与父组件通信）
     * 当组件被点击时，会触发此信号并传递当前cellColor值
     */
    signal clicked(cellColor: color)

    // 组件固定尺寸（宽40像素，高25像素）
    width: 40; height: 25

    /**
     * 实际显示的矩形元素（提供可视化外观）
     * id: rectangle（内部唯一标识，用于被property alias引用）
     */
    Rectangle {
        id: rectangle
        // 边框颜色设置为白色（#FFFFFF的字符串简写形式）
        border.color: "white"
        // 锚定填充父容器（使矩形尺寸与父Item完全一致）
        anchors.fill: parent
    }

    /**
     * 鼠标交互区域（处理点击事件）
     * anchors.fill: parent 使交互区域覆盖整个组件范围
     */
    MouseArea {
        anchors.fill: parent
        // 点击事件处理：触发自定义的clicked信号，并传递当前cellColor值
        onClicked: container.clicked(container.cellColor)
    }
}
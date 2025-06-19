// 版权声明：Qt公司（2017），许可协议为Qt商业许可或BSD-3条款
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// 导入QtQuick基础模块和粒子系统模块
import QtQuick
import QtQuick.Particles

// 定义游戏中的可消除方块元素（继承自Item）
Item {
    id: block  // 元素唯一标识，用于内部属性引用

    // 方块类型属性（0:红色，1:蓝色，2:绿色）
    property int type: 0
    // 是否处于消失状态的标志位（触发销毁逻辑）
    property bool dying: false
    // 是否已生成的标志位（控制位置动画的启用）
    property bool spawned: false

    //![1] 位置动画行为（仅在spawned为true时生效）
    // x坐标变化时的弹性动画配置
    Behavior on x {
        enabled: block.spawned  // 仅当方块生成后启用动画
        SpringAnimation {
            spring: 2    // 弹性系数（值越大回弹越快）
            damping: 0.2  // 阻尼系数（值越大振动衰减越快）
        }
    }
    // y坐标变化时的弹性动画配置（与x轴参数一致）
    Behavior on y {
        SpringAnimation {
            spring: 2
            damping: 0.2
        }
    }
    //![1]

    //![2] 方块主体显示元素（图片）
    Image {
        id: img  // 图片元素标识

        anchors.fill: parent  // 填充父元素（与Item尺寸一致）
        // 根据方块类型动态设置图片资源
        source: {
            if (block.type == 0)
                return "pics/redStone.png";
                // 红色方块图片
            else if (block.type == 1)
                return "pics/blueStone.png";
                // 蓝色方块图片
            else
                return "pics/greenStone.png";// 绿色方块图片
        }
        opacity: 0  // 初始透明度（完全透明，通过状态机控制显示）

        // 透明度变化时的渐变动画（持续200ms）
        Behavior on opacity {
            NumberAnimation {
                properties: "opacity"  // 作用于opacity属性
                duration: 200          // 动画时长（毫秒）
            }
        }
    }
    //![2]

    //![3] 粒子系统（用于方块消失时的爆炸效果）
    ParticleSystem {
        id: sys  // 粒子系统标识
        anchors.centerIn: parent  // 居中于父元素（方块中心）

        // 粒子图片配置
        ImageParticle {
            // 根据方块类型动态设置粒子图片资源
            source: {
                if (block.type == 0)
                    return "pics/redStar.png";
                    // 红色粒子图片
                else if (block.type == 1)
                    return "pics/blueStar.png";
                    // 蓝色粒子图片
                else
                    return "pics/greenStar.png";// 绿色粒子图片
            }
            rotationVelocityVariation: 360  // 粒子旋转速度随机变化范围（0-360度/秒）
        }

        // 粒子发射器配置
        Emitter {
            id: particles  // 发射器标识
            anchors.centerIn: parent  // 居中于父元素（与粒子系统位置一致）
            emitRate: 0  // 持续发射速率（0表示不持续发射，仅通过burst触发）
            lifeSpan: 700  // 粒子生命周期（700ms后消失）
            // 粒子运动方向配置（随机角度，随机速度）
            velocity: AngleDirection {
                angleVariation: 360    // 角度随机范围（360度全方向）
                magnitude: 80          // 基础速度（像素/秒）
                magnitudeVariation: 40  // 速度随机变化范围（±40像素/秒）
            }
            size: 16  // 粒子初始尺寸（像素）
        }
    }
    //![3]

    //![4] 状态机（控制方块的显示/消失状态）
    states: [
        // 存活状态（方块已生成且未开始消失）
        State {
            name: "AliveState"  // 状态名称
            when: block.spawned == true && block.dying == false  // 触发条件
            // 状态属性修改：设置图片完全不透明（显示方块）
            PropertyChanges {
                img.opacity: 1
            }
        },

        // 消失状态（方块开始销毁）
        State {
            name: "DeathState"  // 状态名称
            when: block.dying == true  // 触发条件（dying属性为true时激活）
            // 状态变更脚本：立即发射50个粒子（爆炸效果）
            StateChangeScript {
                script: particles.burst(50)
            }
            // 状态属性修改：设置图片渐变为完全透明（隐藏方块）
            PropertyChanges {
                img.opacity: 0
            }
            // 状态变更脚本：1秒后销毁方块元素（释放资源）
            StateChangeScript {
                script: block.destroy(1000)
            }
        }
    ]
    //![4]
}

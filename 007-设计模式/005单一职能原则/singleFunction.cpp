/*单一只能原则的解释是，就一个类而言，应该仅有一个引起它变化的原因[ASD]。
？如果一个类承担的职责过多，就等于把这些职责耦合在一起，一个职责的变化可
能会削弱或者抑制这个类完成其他职责的能力。这种耦合会导致脆弱的设计，当变
化发生时，设计会遭受到意想不到的破坏[
*/

//例如我们要设计一个俄罗斯方块的游戏
//未进行逻辑和界面分离的设计方案如下
//假设用的是winform窗体设计
class GameForm{
    //TickTimer tick;

public:
    void createNew(){
        //创建新的方块
        }
    void moveLeft(){
        //判断是否碰撞，向左移动
        };
    void moveRight(){
        //判断是否碰撞，向右移动
    }
    void change(){
        //旋转
    }
    void timeTick(){
        //判断是否 game over
        //判断是否到底
        //判断是否消行
    };
};

/*上面的设计方案，所有的方法都在窗体内实现，耦合度太强，应该拆分成功能不同的类
这里如何判断应该拆分呢？加入说现在又要写一个web端或者andorid端的俄罗斯方块，
上面哪些代码是可以复用的呢？
很明显无法复用，只能强行copy过去，可是我们很清楚的知道，游戏的内在逻辑都是一样的，
只是呈现的方式不同罢了。
所以至少应该把游戏逻辑和界面分离开。
界面不承担游戏逻辑功能，而只专注于自己的绘制和擦除功能。
*/

class GameForm{
    public:
    void paint(GameLogic game){
        //进行绘制和擦除工作
    }
};

class GameLogic{
public:
    void createNew(){
        //创建新的方块
    }
    void moveLeft(){
        //改变x坐标的值
    }
    bool crash(){
        //碰撞检测,就抽象成了x,y坐标值的判断
    }

private:
    int gameFrame[20][10];//用二维数组来表示游戏坐标
};
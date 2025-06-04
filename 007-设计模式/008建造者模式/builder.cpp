#include <string>
#include <iostream>
using namespace std;

//角色
class Actor
{
private:
    string type;      //角色类型
    string sex;       //性别
    string face;      //脸型
    string costume;   //服装
    string hairstyle; //发型

public:
    void setType(string type)
    {
        this->type = type;
    }
    void setSex(string sex)
    {
        this->sex = sex;
    }
    void setFace(string face)
    {
        this->face = face;
    }
    void setCostume(string costume)
    {
        this->costume = costume;
    }
    void setHairstyle(string hairstyle)
    {
        this->hairstyle = hairstyle;
    }
    string getType()
    {
        return (this->type);
    }
    string getSex()
    {
        return (this->sex);
    }
    string getFace()
    {
        return (this->face);
    }

    string getCostume()
    {
        return (this->costume);
    }
    string getHairstyle()
    {
        return (this->hairstyle);
    }
};

//角色建造器：抽象建造者
class ActorBuilder
{
protected:
    Actor *actor;

public:
    void buildType();
    void buildSex();
    void buildFace();
    void buildCostume();
    void buildHairstyle();
    //工厂方法，返回一个完整的游戏角色对象
    Actor *createActor()
    {
        return new Actor;
    }
};

//英雄角色建造器：具体建造者
class HeroBuilder : public ActorBuilder
{
    void buildType()
    {
        actor->setType("英雄");
    }
    void buildSex()
    {
        actor->setSex("男");
    }
    void buildFace()
    {
        actor->setFace("英俊");
    }
    void buildCostume()
    {
        actor->setCostume("盔甲");
    }
    void buildHairstyle()
    {
        actor->setHairstyle("飘逸");
    }
};

//天使角色建造器：具体建造者
class AngelBuilder : public ActorBuilder
{

public:
    void buildType()
    {
        actor->setType("天使");
    }
    void buildSex()
    {
        actor->setSex("女");
    }
    void buildFace()
    {
        actor->setFace("漂亮");
    }
    void buildCostume()
    {
        actor->setCostume("白裙");
    }
    void buildHairstyle()
    {
        actor->setHairstyle("披肩长发");
    }
};

//恶魔角色建造器：具体建造者
class DevilBuilder : public ActorBuilder
{
public:
    void buildType()
    {
        actor->setType("恶魔");
    }
    void buildSex()
    {
        actor->setSex("妖");
    }
    void buildFace()
    {
        actor->setFace("丑陋");
    }
    void buildCostume()
    {
        actor->setCostume("黑衣");
    }
    void buildHairstyle()
    {
        actor->setHairstyle("光头");
    }
};
//游戏角色创建控制器：指挥者
class ActorController{
//逐步构建复杂产品对象
  public:
  Actor* construct(ActorBuilder* ab)
  {
   Actor* actor;
   ab->buildType();
   ab->buildSex();
   ab->buildFace();
   ab->buildCostume();
   ab->buildHairstyle();
   actor=ab->createActor();
   return actor;
  }
};
class BuilderFactory{
public:
    static ActorBuilder * getBean(string builderName){
        //此处要根据传递进来的参数生成不同的对象
        ActorBuilder* ab = new DevilBuilder;
        //ActorBuilder* ab = new AngelBuilder;
        return ab;
    }
};

int main()
  {
    ActorBuilder* ab; //针对抽象建造者编程
    ab = BuilderFactory::getBean("天使"); //通常用反射生成具体建造者对象,c++不支持
    ActorController* ac = new ActorController;
    Actor* actor;
    actor = ac->construct(ab); //通过指挥者创建完整的建造者对象
    string type = actor->getType();
    cout<<(type + "的外观：")<<endl;
    cout<<("性别：" + actor->getSex())<<endl;
    cout<<("面容：" + actor->getFace())<<endl;
    cout<<("服装：" + actor->getCostume())<<endl;
    cout<<("发型：" + actor->getHairstyle())<<endl;

    return 0;
  }
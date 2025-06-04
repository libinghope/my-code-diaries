/*策略模式
设计背景: 某商场结算系统系统，有如下几种收款方式
1、打8折
2、打7.5折
3、打6折
...
1、满500反50
2、满300反30
...
1、满100送10积分
2、满200送20积分
*/
typedef double CoefficientType; //折扣率为double
class StrategyContext;
enum ECashType
{
    NORMAL,    //无折扣
    DISCOUNT,  //打折
    MONEY_OFF, //满减
    ACCUMULATE //积分
};
//策略接口
class IStrategy
{
public:
    IStrategy(StrategyContext ctx) : ctx(ctx) {}
    virtual double getResult();

protected:
    StrategyContext ctx;
};
class NormalStrategy : public IStrategy
{
public:
    NormalStrategy(StrategyContext ctx) : IStrategy(ctx) { this->ctx = ctx; }
    virtual double getResult();
};
class DiscountStrategy : public IStrategy
{
public:
    DiscountStrategy(StrategyContext ctx) : IStrategy(ctx) { this->ctx = ctx; }
    virtual double getResult();
};

class MoneyOffStrategy : public IStrategy
{
public:
    MoneyOffStrategy(StrategyContext ctx) : IStrategy(ctx) { this->ctx = ctx; }
    virtual double getResult();
};

class AccumulateStrategy : public IStrategy
{
public:
    AccumulateStrategy(StrategyContext ctx) : IStrategy(ctx) { this->ctx = ctx; }
    virtual double getResult();
};

//与工厂模式结合
class StrategeFactory
{
public:
    static IStrategy* createStrategy(StrategyContext ctx);
};

//生成策略的上下文
class StrategyContext
{
public:
    StrategyContext(ECashType type, double money, double coefficient = 0.0);
    inline CoefficientType getCoefficient() { return coefficient; }
    inline ECashType getCashType() { return type; }
    inline double getMoney() { return money; }

private:
    ECashType type;
    CoefficientType coefficient;
    double money;
};
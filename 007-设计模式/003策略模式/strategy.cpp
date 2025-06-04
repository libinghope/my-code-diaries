#include "strategy.h"

double NormalStrategy::getResult(){
    return ctx.getMoney();
}

double DiscountStrategy::getResult(){
    return ctx.getMoney() * ctx.getCoefficient();
}

double MoneyOffStrategy::getResult(){
    return ctx.getMoney() - ctx.getMoney() / ctx.getCoefficient();
}

double AccumulateStrategy::getResult(){
    return ctx.getMoney() - ctx.getMoney() / ctx.getCoefficient();
}

IStrategy* StrategeFactory::createStrategy(StrategyContext ctx){
    IStrategy *strategy = nullptr;
    switch (ctx.getCashType())
    {
    case NORMAL:
        strategy = new NormalStrategy(ctx);
        break;
    case DISCOUNT:
        strategy = new DiscountStrategy(ctx);
        break;
    case MONEY_OFF:
        strategy = new MoneyOffStrategy(ctx);
        break;
    case ACCUMULATE:
        strategy = new AccumulateStrategy(ctx);
        break;
    default:
        break;
    }
    return strategy;
}


int main(){
    StrategyContext ctx(DISCOUNT,900,0.8);
    StrategeFactory::createStrategy(ctx)->getResult();
    return 0;
}
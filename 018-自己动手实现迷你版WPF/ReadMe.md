# 自己动手实现迷你版WPF

为什么要自己动手实现一个迷你版的WPF?

> What I can not create, I do not understand ! ————(物理学习，诺奖得主)理查德·费曼

## 一、WPF简介

WPF是微软提供的一套基于windows用户界面的开发框架，目标是加快软件的开发速度，降低维护和更新的难度和成本。这是MVVM编程思想的首次提出，它提供了统一的编程模型、语言和框架，真正做到了分离界面设计人员和开发人员的工作，同时也提供了全新的多媒体交互图形界面。

## 二、前提必要知识

 ### 1 c#语言基础
 使用WPF进行开发，需要具备c#语言的基础。

 ### 2 理解订阅模式
 
 订阅模式的实现以及发布者接口

发布者接口实现
```c#
using System;
using System.Collections.Generic;

namespace Subscription.Interface
{
    public abstract class AbstractPublisher
    {
        protected List<ISubscriber> SubscriberList {get;set;} = new List<ISubscriber>();

        public abstract void publish(string msg);

        public void Subscribe(ISubscriber subscriber)
        {
            Console.WriteLine($"新增一个订阅者:{subscriber.ToString()}");
            SubscriberList.Add(subscriber);
        }

        public void UnSubScribe(ISubscriber subscriber)
        {
            Console.WriteLine($"{subscriber.ToString()}取消了订阅!");
            SubscriberList.Remove(subscriber);
        }
    }
}
```
订阅者接口实现
```c#
namespace Subscription.Interface
{
    public Interface ISubscriber{
        void OnNewMessage(string msg);
    }
}
```
更多代码实现可查看工程代码。

 ### 3 重点理解c#中的委托(delegate)

   委托类似于c/c++中的函数指针(数组)，可以存储某个方法的引用的变量。该引用可以再运行时候被改变，特别被用于实现事件和回调方法，再c#中委托也是一个特殊的类。

 ### 4 MVVM的编程思想

 ![mvvm](https://gitee.com/libing2020/journey-of-coding/raw/master/Assets/Images/mvvm.png "MVVM")


 ## 三、几个核心问题
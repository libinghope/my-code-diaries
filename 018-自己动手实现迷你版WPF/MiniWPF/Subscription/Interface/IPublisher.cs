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
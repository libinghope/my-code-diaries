using Subscription.Interface;
using System;

namespace Subscription
{
    public class EmailUser : ISubscriber
    {
        public void OnNewMessage(string msg)
        {
            Console.WriteLine($"{UserName}收到了一封新邮件:{msg}");
        }

        public EmailUser(string name)
        {
            UserName = name;
        }

        public string UserName {get;internal set;}

        public override string ToString()
        {
            return UserName;
        }
    }
}
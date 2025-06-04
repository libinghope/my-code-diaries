using System;


namespace Subscription
{
    class Program{
        static void Main(string[] args)
        {
            EmailReminderService reminder = new EmailReminderService();
            EmailUser user1 = new EmailUser();
            EmailUser user2 = new EmailUser();

            reminder.Subscribe(user1);
            reminder.Subscribe(use2);

            reminder.Publish("懂王当选美国总统了！");

            reminder.UnSubScribe(user2);
            reminder.UnSubScribe(user1);


            Console.ReadLine();
        }
    }
}
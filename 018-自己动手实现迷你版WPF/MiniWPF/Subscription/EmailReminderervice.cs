namespace Subscription
{
    public class EmailReminderService : AbstractPublisher
    {
        public override void Publish(string msg)
        {
            foreach(var subscriber in SubscriberList)
            {
                subscriber.OnNewMessage(msg);
            }
        }
    }

}
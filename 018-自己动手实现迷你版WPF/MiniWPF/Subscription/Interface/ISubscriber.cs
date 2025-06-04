namespace Subscription.Interface
{
    public Interface ISubscriber{
        void OnNewMessage(string msg);
    }
}
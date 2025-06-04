using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MiniWPFCore.Interface
{
    public interface IMyNotifyPropertyChanged
    {
        //传统的订阅模式
        //List<ISubscriber> Subscribers { get; }

        //使用事件委托的订阅方式
        event EventHandler<MySourcePropertyChangedEventArgs> NotifyPropertyChangedEvent;
    }


    public class MySourcePropertyChangedEventArgs
    {
        public string PropertyName { get; }
        public object NewValue { get; }
        public object OldValue { get; }
        public MySourcePropertyChangedEventArgs(string propertyName, object oldValue, object newValue)
        {
            PropertyName = propertyName;
            OldValue = oldValue;
            NewValue = newValue;
        }
    }
}

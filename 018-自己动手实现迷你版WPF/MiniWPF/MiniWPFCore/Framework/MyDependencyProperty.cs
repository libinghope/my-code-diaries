using MiniWPFCore.Interface;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace MiniWPFCore.Framework
{
    public class MyDependencyProperty
    {
        public string PropertyName { get; internal set; }
        public Type PropertyType { get; internal set; }
        public Type OwnerType { get; internal set; }
        public object DefaultValue { get; internal set; }

        public Action<object, object> PropertyChangedCallBack { get; internal set; }

        //构造方法私有化，只能通过Register方法进行实例化
        private MyDependencyProperty(string name, Type propertyType, Type ownerType, object defaultVal, Action<object, object> callback = null)

        {
            PropertyName = name;
            PropertyType = propertyType;
            OwnerType = ownerType;
            DefaultValue = defaultVal;
            PropertyChangedCallBack = callback;
        }
        public static MyDependencyProperty Register(string name, Type propertyType, Type ownerType, object defaultValue, Action<object, object> callback = null)
        {
            return new MyDependencyProperty(name, propertyType, ownerType, defaultValue, callback);
        }

        public event EventHandler<DependencyPropertyChangedEventArgs> ValueChangedHandler;

        public virtual void RaiseValueChangedEvent(object sender, object oldValue, object newValue)
        {
            if (oldValue != newValue)
            {
                var e = new DependencyPropertyChangedEventArgs(PropertyName, oldValue, newValue);
                ValueChangedHandler?.Invoke(sender, e);
            }
        }
    }

    public class DependencyPropertyChangedEventArgs : EventArgs
    {
        public string PropertyName { get; internal set; }
        public object OldValue { get; set; }
        public object NewValue { get; set; }

        public DependencyPropertyChangedEventArgs(string propertyName, object oldValue, object newValue)
        {
            PropertyName = propertyName;
            OldValue = oldValue;
            NewValue = newValue;
        }
    }
}

using MiniWPFCore.Interface;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MiniWPFCore.Framework
{
    public enum BindingMode
    {
        OneWay,
        TwoWay,
        OneWayToSource
    }
    public class MyBinding
    {
        private object _Source;
        private string _SourcePropertyName;
        private MyDependencyObject _Target;
        private MyDependencyProperty _TargetProperty;

        public BindingMode Mode { get; set; } = BindingMode.TwoWay;

        public MyBinding(object source,
            string sourcePropertyName,
            MyDependencyObject target,
            MyDependencyProperty targetProperty,
            BindingMode mode = BindingMode.TwoWay)
        {
            _Source = source;
            _SourcePropertyName = sourcePropertyName;
            _Target = target;
            _TargetProperty = targetProperty;
            Mode = mode;

            //实现(Target ==> Source)的数据传递
            targetProperty.ValueChangedHandler += DependencyPropertyChanged;

            //双向绑定的时候，实现(Source ==> Target)的数据传递
            if (mode == BindingMode.TwoWay)
            {
                (_Source as IMyNotifyPropertyChanged).NotifyPropertyChangedEvent += SourcePropertyChanged;
            }
            //绑定的同时，进行一次数据同步，就是把Source的值传递到UI
            SyncValueFromSourceToTarget();
        }

        private void DependencyPropertyChanged(Object sender, DependencyPropertyChangedEventArgs e)
        {
            if ((sender as MyDependencyObject) != _Target) return;
            //此时会触发对应属性的set方法
            var property = _Source.GetType().GetProperty(_SourcePropertyName);
            object newVal = null;

            //枚举需要特别处理
            if (property.PropertyType.IsEnum)
            {
                newVal = Enum.ToObject(property.PropertyType, e.NewValue);
            }
            else
            {
                newVal = e.NewValue;
            }
            newVal = Convert.ChangeType(newVal, property.PropertyType);
            property.SetValue(_Source, newVal);
        }

        private void SourcePropertyChanged(object sender, MySourcePropertyChangedEventArgs e)
        {
            if (e.PropertyName == _SourcePropertyName && e.OldValue != e.NewValue)
            {
                SyncValueFromSourceToTarget();
            }
        }

        private void SyncValueFromSourceToTarget()
        {
            var val = _Source.GetType().GetProperty(_SourcePropertyName).GetValue(_Source);
            var property = _Target.GetType().GetProperty(_TargetProperty.PropertyName);
            var v = Convert.ChangeType(val, _TargetProperty.PropertyType);
            property.SetValue(_Target, v);
        }
    }
}

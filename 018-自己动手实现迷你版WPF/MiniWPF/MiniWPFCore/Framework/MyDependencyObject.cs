using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace MiniWPFCore.Framework
{
    public class MyDependencyObject
    {
        //TOD0 关键问题:依赖属性作为一个静态属性,被所有实例公用,为什么可以存储多个实例的不同的属性值?

        private static Dictionary<MyDependencyObject, Dictionary<MyDependencyProperty, object>> _PropertyValuesDict = new Dictionary<MyDependencyObject, Dictionary<MyDependencyProperty, object>>();

        private static int _CurrentGlobalID = 10000;
        public int GlobalID { get; internal set; }

        public MyDependencyObject()
        {
            //!相当于生成字典的key
            GlobalID = _CurrentGlobalID++;
        }

        //模拟WPF的GetValue和setValue方法
        public object MyGetVaule(MyDependencyProperty property)
        {
            object result = null;
            Dictionary<MyDependencyProperty, object> dictValue;
            if (_PropertyValuesDict.TryGetValue(this, out dictValue))
            {
                if (dictValue.TryGetValue(property, out result)) return result;
            }
            return property.DefaultValue;
        }
        public void MySetValue(MyDependencyProperty property, object val)
        {
            Dictionary<MyDependencyProperty, object> valueDict;
            object oldObject = null;

            if (_PropertyValuesDict.ContainsKey(this))
            {
                valueDict = _PropertyValuesDict[this];
                if (valueDict.ContainsKey(property))
                {
                    oldObject = valueDict[property];
                    if (oldObject == val) { return; }
                }
            }
            else
            {
                _PropertyValuesDict[this] = new Dictionary<MyDependencyProperty, object>();
            }
            _PropertyValuesDict[this][property] = val;
            property.PropertyChangedCallBack?.Invoke(oldObject, val);
            property.RaiseValueChangedEvent(this, oldObject, val);
        }

        //使用Dependency可以作为Dictionary的key
        public override bool Equals(object obj)
        {
            return GlobalID.Equals(((MyDependencyObject)obj).GlobalID);
        }

        public override int GetHashCode()
        {
            return $"{this.GetType()}{GlobalID}".GetHashCode();
        }
    }
}

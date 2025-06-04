using MiniWPFCore.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MiniWPFCore.Controls
{
    public class MyCombobox : MyDependencyObject
    {
        private ComboBox comboBox;
        public MyCombobox(ComboBox combox)
        {
            comboBox = combox;
            comboBox.SelectedIndexChanged += (sender, e) =>
            {
                SelectedIndex = comboBox.SelectedIndex;
            };
        }

        public int SelectedIndex
        {
            get { return (int)MyGetVaule(SelectedIndexProperty); }
            set
            {
                MySetValue(SelectedIndexProperty, value);
                comboBox.SelectedIndex = value;
            }
        }

        public static MyDependencyProperty SelectedIndexProperty = MyDependencyProperty.Register(
            nameof(SelectedIndex), typeof(int), typeof(MyCombobox), -1
            );
    }
}

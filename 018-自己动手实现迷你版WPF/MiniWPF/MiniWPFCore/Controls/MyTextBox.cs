using MiniWPFCore.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using TextBox = System.Windows.Forms.TextBox;

namespace MiniWPFCore.Controls
{
    public class MyTextBox : MyDependencyObject
    {
        private TextBox _TextBox;
        public MyTextBox(TextBox textBox)
        {
            _TextBox = textBox;
            _TextBox.TextChanged += (sender, e) =>
            {
                Text = textBox.Text;
            };
        }

        public string Text
        {
            get { return (string)MyGetVaule(TextProperty); }
            set
            {
                MySetValue(TextProperty, value);
                _TextBox.Text = value;
            }
        }

        public static MyDependencyProperty TextProperty = MyDependencyProperty.Register(
            nameof(Text), typeof(string), typeof(MyCombobox), ""
            );
    }
}

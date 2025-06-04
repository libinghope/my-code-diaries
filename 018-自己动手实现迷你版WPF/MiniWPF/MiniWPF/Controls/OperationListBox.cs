using MiniWPFCore.Framework;
using System.Windows.Forms;


namespace MiniWPF
{
    public class OperationListBox : MyDependencyObject
    {
        private ListBox _ListBox;

        public OperationListBox(ListBox listBox)
        {
            _ListBox = listBox;
            listBox.SelectedIndexChanged += (sender, e) =>
            {
                SelectedIndex = listBox.SelectedIndex;
            };
        }

        public int SelectedIndex
        {
            get { return (int)MyGetVaule(SelectedIndexProperty); }
            set { MySetValue(SelectedIndexProperty, value); _ListBox.SelectedIndex = value; }
        }

        public static MyDependencyProperty SelectedIndexProperty = MyDependencyProperty.Register(
            nameof(SelectedIndex), typeof(int), typeof(OperationListBox), 0
        );

    }
}
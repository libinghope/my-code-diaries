
using MiniWPFCore.Framework;
using System.Windows.Forms;

namespace MiniWPF
{

    public class SliderTextBox : MyDependencyObject
    {
        private TextBox _TextBox;
        private TrackBar _TraceBar;

        public SliderTextBox(TrackBar traceBar, TextBox textBox)
        {
            _TraceBar = traceBar;
            _TextBox = textBox;
            traceBar.ValueChanged += (sener, e) =>
            {
                textBox.Text = traceBar.Value.ToString();
                Value = traceBar.Value;
            };
        }

        public void SetRange(int min, int max)
        {
            this._TraceBar.SetRange(min, max);
        }

        public double Value
        {
            get { return (double)MyGetVaule(ValueProperty); }
            set
            {
                if (Value != value)
                {
                    MySetValue(ValueProperty, value);

                    if (_TextBox.Text != value.ToString())
                    {
                        _TextBox.Text = value.ToString();
                        _TraceBar.Value = (int)value;
                    }
                }
            }
        }


        public static MyDependencyProperty ValueProperty = MyDependencyProperty.Register(
            nameof(Value), typeof(double), typeof(SliderTextBox), 0.0
        );
    }



}
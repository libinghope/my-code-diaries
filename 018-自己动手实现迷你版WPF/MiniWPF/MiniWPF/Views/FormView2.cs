using MiniWPF.Enums;
using MiniWPF.ViewModel;
using MiniWPFCore.Controls;
using MiniWPFCore.Framework;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MiniWPF.Views
{
    public partial class FormView2 : Form
    {
        public FormView2()
        {
            InitializeComponent();
            InitControls();

            //MVVM代码
            ViewModel = new CalculatorViewModel();
            MyBinding bind1 = new MyBinding(ViewModel, "FirstNumber", this.FirstNumber_SliderTextBox, SliderTextBox.ValueProperty);
            MyBinding bind2 = new MyBinding(ViewModel, "SecondNumber", this.SecondNumber_SliderTextBox, SliderTextBox.ValueProperty);
            MyBinding bind3 = new MyBinding(ViewModel, "Operation", this.Operatore_ListBox, OperationListBox.SelectedIndexProperty);
            MyBinding bind4 = new MyBinding(ViewModel, "Result", this.Result_SliderTextBox, SliderTextBox.ValueProperty);
        }

        private CalculatorViewModel ViewModel;

        private void button1_Click(object sender, EventArgs e)
        {
            ViewModel.ComputeResult();
        }

        private void InitControls()
        {
            this.first_number_trackBar.SetRange(0, 100);
            FirstNumber_SliderTextBox = new SliderTextBox(first_number_trackBar, first_number_textBox);

            this.second_number_trackBar.SetRange(0, 100);
            SecondNumber_SliderTextBox = new SliderTextBox(second_number_trackBar, second_number_textBox);

            this.result_trackBar.SetRange(0, 100);
            Result_SliderTextBox = new SliderTextBox(result_trackBar, result_textBox);

            this.Operatore_ListBox = new OperationListBox(listBox1);
            listBox1.Items.AddRange(new object[] { CalcOperation.ADD, CalcOperation.SUB, CalcOperation.MUTI, CalcOperation.DIVIDE });
        }

        private SliderTextBox FirstNumber_SliderTextBox;
        private SliderTextBox SecondNumber_SliderTextBox;
        private OperationListBox Operatore_ListBox;
        private SliderTextBox Result_SliderTextBox;

        private void button1_Click_1(object sender, EventArgs e)
        {
            ViewModel.ComputeResult();
        }
    }
}

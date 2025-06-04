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
    public partial class FormView1 : Form
    {

        private CalculatorViewModel _CalculatorViewModel = new CalculatorViewModel();
        public FormView1()
        {
            InitializeComponent();
            InitDependencyObjects();

            MyBinding bind1 = new MyBinding(_CalculatorViewModel, "FirstNumber", this.DependencyTextBox_FirstNumber, MyTextBox.TextProperty);
            MyBinding bind2 = new MyBinding(_CalculatorViewModel, "SecondNumber", this.DependencyTextBox_SecondNumber, MyTextBox.TextProperty);
            MyBinding bind3 = new MyBinding(_CalculatorViewModel, "Operation", this.DependencyComboBox_Operation, MyCombobox.SelectedIndexProperty);
            MyBinding bind4 = new MyBinding(_CalculatorViewModel, "Result", this.DependencyTextBox_Result, MyTextBox.TextProperty);
        }

        //计算
        private void button1_Click(object sender, EventArgs e)
        {
            _CalculatorViewModel.ComputeResult();
        }

        private void InitDependencyObjects()
        {
            DependencyTextBox_FirstNumber = new MyTextBox(FirstNumber_TextBox);
            DependencyTextBox_SecondNumber = new MyTextBox(SecondNumber_TextBox);
            DependencyTextBox_Result = new MyTextBox(Result_TextBox);
            DependencyComboBox_Operation = new MyCombobox(Operation);

            this.Operation.Items.AddRange((new List<object> { CalcOperation.ADD, CalcOperation.SUB, CalcOperation.MUTI, CalcOperation.DIVIDE }).ToArray());
            this.Operation.SelectedIndex = 0;
        }

        private MyTextBox DependencyTextBox_FirstNumber;
        private MyTextBox DependencyTextBox_SecondNumber;
        private MyTextBox DependencyTextBox_Result;
        private MyCombobox DependencyComboBox_Operation;
    }
}

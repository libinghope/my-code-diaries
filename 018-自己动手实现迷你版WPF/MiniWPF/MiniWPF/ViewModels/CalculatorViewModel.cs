using MiniWPF.Enums;
using MiniWPF.Models;
using MiniWPFCore.Interface;

namespace MiniWPF.ViewModel
{
    public class CalculatorViewModel : IMyNotifyPropertyChanged
    {
        private Calculator _CalculatorModel = new Calculator();

        public event EventHandler<MySourcePropertyChangedEventArgs> NotifyPropertyChangedEvent;

        public double FirstNumber { get; set; } = 0.0;
        public double SecondNumber { get; set; } = 0.0;
        public CalcOperation Operation { get; set; } = CalcOperation.ADD;

        public double Result
        {
            get { return _Result; }
            set
            {
                if (_Result != value)
                {
                    _Result = value;
                    NotifyPropertyChangedEvent?.Invoke(
                        this, new MySourcePropertyChangedEventArgs(nameof(Result), _Result, value)
                    );
                }
            }
        }

        private double _Result = 0;

        public void ComputeResult()
        {
            switch (Operation)
            {
                case CalcOperation.ADD:
                    Result = _CalculatorModel.Add(FirstNumber, SecondNumber);
                    break;
                case CalcOperation.SUB:
                    Result = _CalculatorModel.Sub(FirstNumber, SecondNumber);
                    break;
                case CalcOperation.MUTI:
                    Result = _CalculatorModel.Muti(FirstNumber, SecondNumber);
                    break;
                case CalcOperation.DIVIDE:
                    Result = _CalculatorModel.Div(FirstNumber, SecondNumber);
                    break;
            }
        }
    }


}
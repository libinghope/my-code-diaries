namespace MiniWPF.Models{
    public class Calculator{
        public double Add(double firstNumber,double secondNumber)
        {
            return firstNumber + secondNumber;
        }

        public double Sub(double firstNumber,double secondNumber)
        {
            return firstNumber - secondNumber;
        }

        public double Muti(double firstNumber,double secondNumber)
        {
            return firstNumber * secondNumber;
        }
        public double Div(double firstNumber,double secondNumber){
            return firstNumber /secondNumber;
        }

    }
}
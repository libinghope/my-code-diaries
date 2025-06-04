namespace MiniWPF.Views
{
    partial class FormView1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            FirstNumber_TextBox = new TextBox();
            Operation = new ComboBox();
            SecondNumber_TextBox = new TextBox();
            button1 = new Button();
            Result_TextBox = new TextBox();
            SuspendLayout();
            // 
            // FirstNumber_TextBox
            // 
            FirstNumber_TextBox.Location = new Point(71, 231);
            FirstNumber_TextBox.Name = "FirstNumber_TextBox";
            FirstNumber_TextBox.Size = new Size(100, 23);
            FirstNumber_TextBox.TabIndex = 0;
            FirstNumber_TextBox.Text = "0";
            // 
            // Operation
            // 
            Operation.FormattingEnabled = true;
            Operation.Location = new Point(200, 234);
            Operation.Name = "Operation";
            Operation.Size = new Size(121, 25);
            Operation.TabIndex = 1;
            // 
            // SecondNumber_TextBox
            // 
            SecondNumber_TextBox.Location = new Point(348, 238);
            SecondNumber_TextBox.Name = "SecondNumber_TextBox";
            SecondNumber_TextBox.Size = new Size(100, 23);
            SecondNumber_TextBox.TabIndex = 2;
            SecondNumber_TextBox.Text = "0";
            // 
            // button1
            // 
            button1.Location = new Point(476, 238);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 3;
            button1.Text = "=";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // Result_TextBox
            // 
            Result_TextBox.Location = new Point(584, 243);
            Result_TextBox.Name = "Result_TextBox";
            Result_TextBox.Size = new Size(100, 23);
            Result_TextBox.TabIndex = 4;
            Result_TextBox.Text = "0";
            // 
            // FormView1
            // 
            AutoScaleDimensions = new SizeF(7F, 17F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(Result_TextBox);
            Controls.Add(button1);
            Controls.Add(SecondNumber_TextBox);
            Controls.Add(Operation);
            Controls.Add(FirstNumber_TextBox);
            Name = "FormView1";
            Text = "FormView1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox FirstNumber_TextBox;
        private ComboBox Operation;
        private TextBox SecondNumber_TextBox;
        private Button button1;
        private TextBox Result_TextBox;
    }
}
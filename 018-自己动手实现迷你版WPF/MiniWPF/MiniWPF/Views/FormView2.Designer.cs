namespace MiniWPF.Views
{
    partial class FormView2
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
            groupBox1 = new GroupBox();
            first_number_textBox = new TextBox();
            first_number_trackBar = new TrackBar();
            label1 = new Label();
            groupBox2 = new GroupBox();
            second_number_textBox = new TextBox();
            second_number_trackBar = new TrackBar();
            label2 = new Label();
            groupBox3 = new GroupBox();
            listBox1 = new ListBox();
            button1 = new Button();
            groupBox4 = new GroupBox();
            result_textBox = new TextBox();
            result_trackBar = new TrackBar();
            label3 = new Label();
            groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)first_number_trackBar).BeginInit();
            groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)second_number_trackBar).BeginInit();
            groupBox3.SuspendLayout();
            groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)result_trackBar).BeginInit();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(first_number_textBox);
            groupBox1.Controls.Add(first_number_trackBar);
            groupBox1.Controls.Add(label1);
            groupBox1.Location = new Point(55, 42);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(597, 100);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            // 
            // first_number_textBox
            // 
            first_number_textBox.Location = new Point(467, 36);
            first_number_textBox.Name = "first_number_textBox";
            first_number_textBox.Size = new Size(100, 23);
            first_number_textBox.TabIndex = 2;
            // 
            // first_number_trackBar
            // 
            first_number_trackBar.Location = new Point(106, 28);
            first_number_trackBar.Name = "first_number_trackBar";
            first_number_trackBar.Size = new Size(334, 45);
            first_number_trackBar.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(16, 40);
            label1.Name = "label1";
            label1.Size = new Size(84, 17);
            label1.TabIndex = 0;
            label1.Text = "First Number";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(second_number_textBox);
            groupBox2.Controls.Add(second_number_trackBar);
            groupBox2.Controls.Add(label2);
            groupBox2.Location = new Point(53, 348);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(597, 100);
            groupBox2.TabIndex = 1;
            groupBox2.TabStop = false;
            // 
            // second_number_textBox
            // 
            second_number_textBox.Location = new Point(467, 36);
            second_number_textBox.Name = "second_number_textBox";
            second_number_textBox.Size = new Size(100, 23);
            second_number_textBox.TabIndex = 2;
            // 
            // second_number_trackBar
            // 
            second_number_trackBar.Location = new Point(106, 28);
            second_number_trackBar.Name = "second_number_trackBar";
            second_number_trackBar.Size = new Size(334, 45);
            second_number_trackBar.TabIndex = 1;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(16, 40);
            label2.Name = "label2";
            label2.Size = new Size(103, 17);
            label2.TabIndex = 0;
            label2.Text = "Second Number";
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(listBox1);
            groupBox3.Location = new Point(99, 177);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(279, 165);
            groupBox3.TabIndex = 2;
            groupBox3.TabStop = false;
            // 
            // listBox1
            // 
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 17;
            listBox1.Location = new Point(29, 20);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(198, 123);
            listBox1.TabIndex = 0;
            // 
            // button1
            // 
            button1.Location = new Point(122, 463);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 3;
            button1.Text = "=";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click_1;
            // 
            // groupBox4
            // 
            groupBox4.Controls.Add(result_textBox);
            groupBox4.Controls.Add(result_trackBar);
            groupBox4.Controls.Add(label3);
            groupBox4.Location = new Point(59, 533);
            groupBox4.Name = "groupBox4";
            groupBox4.Size = new Size(597, 100);
            groupBox4.TabIndex = 4;
            groupBox4.TabStop = false;
            // 
            // result_textBox
            // 
            result_textBox.Location = new Point(467, 36);
            result_textBox.Name = "result_textBox";
            result_textBox.Size = new Size(100, 23);
            result_textBox.TabIndex = 2;
            // 
            // result_trackBar
            // 
            result_trackBar.Location = new Point(106, 28);
            result_trackBar.Name = "result_trackBar";
            result_trackBar.Size = new Size(334, 45);
            result_trackBar.TabIndex = 1;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(16, 40);
            label3.Name = "label3";
            label3.Size = new Size(43, 17);
            label3.TabIndex = 0;
            label3.Text = "Result";
            // 
            // FormView2
            // 
            AutoScaleDimensions = new SizeF(7F, 17F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(986, 689);
            Controls.Add(groupBox4);
            Controls.Add(button1);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Name = "FormView2";
            Text = "FormView2";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)first_number_trackBar).EndInit();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)second_number_trackBar).EndInit();
            groupBox3.ResumeLayout(false);
            groupBox4.ResumeLayout(false);
            groupBox4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)result_trackBar).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private GroupBox groupBox1;
        private Label label1;
        private TextBox first_number_textBox;
        private TrackBar first_number_trackBar;
        private GroupBox groupBox2;
        private TextBox second_number_textBox;
        private TrackBar second_number_trackBar;
        private Label label2;
        private GroupBox groupBox3;
        private ListBox listBox1;
        private Button button1;
        private GroupBox groupBox4;
        private TextBox result_textBox;
        private TrackBar result_trackBar;
        private Label label3;
    }
}
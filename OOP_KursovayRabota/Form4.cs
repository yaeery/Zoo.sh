using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OOP_KursovayRabota
{
    public partial class Form4 : Form
    {
        public static string FIO;
        public static string Number;
        public Form4()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length == 0)
            {
                label4.BackColor = label4.BackColor;
                label4.ForeColor = Color.Red;
            }
            else
            {
                label4.BackColor = label4.BackColor;
                label4.ForeColor = Color.Aqua;
            }
            if ((textBox2.Text.Length < 11) || (textBox2.Text.Length > 12))
            {
                label5.BackColor = label5.BackColor;
                label5.ForeColor = Color.Red;
            }
            else
            {
                label5.BackColor = label5.BackColor;
                label5.ForeColor = Color.Aqua;
            }
            if ((textBox1.Text.Length > 0) && ((textBox2.Text.Length >= 11) && (textBox2.Text.Length <= 12)))
            {
                FIO = textBox1.Text.ToString();
                Number = textBox2.Text.ToString();
                textBox1.Clear();
                textBox2.Clear();
                Form5 form5 = new Form5();
                form5.Show();
                this.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            textBox2.Clear();
            this.Close();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }
    }
}

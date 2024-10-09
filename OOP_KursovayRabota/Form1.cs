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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Zapolnenie_Kolonok();
            Program.newdataGridView = dataGridView1;
        }
        void Zapolnenie_Kolonok()
        {
            var colum1 = new DataGridViewTextBoxColumn();
            colum1.Width = 120;
            colum1.HeaderText = "Название";
            var colum2 = new DataGridViewTextBoxColumn();
            colum2.Width = 140;
            colum2.HeaderText = "Тип";
            var colum3 = new DataGridViewTextBoxColumn();
            colum3.Width = 200;
            colum3.HeaderText = "День недели";
            var colum4 = new DataGridViewTextBoxColumn();
            colum4.Width = 80;
            colum4.HeaderText = "Вольер";
            dataGridView1.Columns.AddRange(colum1);
            dataGridView1.Columns.AddRange(colum2);
            dataGridView1.Columns.AddRange(colum3);
            dataGridView1.Columns.AddRange(colum4);
        }
        public static  void Zapolnenie_Grid()
        {
            Program.newdataGridView.Rows.Clear();
            Program.Perenos();
            if (Program.Names.Count > 0)
            {
                for (int i = 0; i < Program.Names.Count; i++)
                {
                    Program.newdataGridView.Rows.Insert(i, Program.Names[i], Program.Classes[i], Program.Days[i], Program.Voliers[i]);
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Program.newdataGridView = dataGridView1;
            Program.Sort_Name();
            Zapolnenie_Grid();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Program.newdataGridView = dataGridView1;
            Program.Sort_Volier();
            Zapolnenie_Grid();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Program.newdataGridView = dataGridView1;
            Program.Sort_Class();
            Zapolnenie_Grid();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Program.newdataGridView = dataGridView1;
            Form2 form2 = new Form2();
            form2.Show();
        }
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form3 form3 = new Form3();
            form3.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form4 form4 = new Form4();
            form4.Show();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            Form6 form6 = new Form6();
            form6.Show();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}

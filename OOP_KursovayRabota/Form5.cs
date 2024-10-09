using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace OOP_KursovayRabota
{
    public partial class Form5 : Form
    {
        [DllImport("DLL.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern void Zapis_v_file_obchie([MarshalAs(UnmanagedType.LPTStr)]string stroka);
        string stroka;
        public Form5()
        {
            InitializeComponent();
        }

        private void Form5_Load(object sender, EventArgs e)
        {
            
            var colum1 = new DataGridViewTextBoxColumn();
            colum1.Width = 370;
            colum1.HeaderText = "";
            dataGridView1.Columns.AddRange(colum1);
            label2.Text = Form4.FIO.ToString();
            label3.Text = Form4.Number.ToString();
            Program.Perenos();
            string x = Program.Cluchainay_Exckyrsiy();
            
            for (int i = 0; i < x.Length; i++)
            {
                dataGridView1.Rows.Insert(i, Program.Names[x[i]-'0']);
                stroka = stroka + Program.Names[x[i] - '0']+ " ";
            }
        }
        void Zapis_v_File()
        {
            stroka += "\n";
            stroka += label2.Text;
            stroka += "\n";
            stroka += label3.Text;
            stroka += "\n";
            stroka += "-----";
            stroka += "\n";
            Zapis_v_file_obchie(stroka);
            stroka = "";
        }
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Zapis_v_File();
            this.Close();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}

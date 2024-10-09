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
    public partial class Form2 : Form
    {
        List<int> Indexes = new List<int>();
        public Form2()
        {
            InitializeComponent();
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        public  void button1_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < checkedListBox1.CheckedItems.Count; i++)
            {
               Indexes.Add(checkedListBox1.CheckedIndices[i] + 1);
            }
            if (Indexes.Count == 0)
            {
                for (int i = 0; i < 7; i++)
                {
                    Indexes.Add(i + 1);
                }
            }
            for (int i = 0; i < Indexes.Count; i++)
            {
                Program.Stroka += Indexes[i].ToString();
            }
            Program.newdataGridView.Rows.Clear();
            Form1.Zapolnenie_Grid();
            Program.Stroka = "";
            Indexes.Clear();
            checkedListBox1.Items.Clear();
            this.Close();
        }
    }
}

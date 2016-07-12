using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace Client
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 frm1 = new Form1();
            frm1.Show();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void btn_smu_Click(object sender, EventArgs e)
        {
            string pass = tb_p.Text;

            if (Regex.IsMatch(pass, @"^.*(?=.{4,})(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).*$"))
            {
                // do the sign up, needs to be cabolrated with the database 
              
            }
            else
            {
                MessageBox.Show("the password is not by the rules, look at the rules");
            }

        }

        private void tb_u_TextChanged(object sender, EventArgs e)
        {

        }
    }
}

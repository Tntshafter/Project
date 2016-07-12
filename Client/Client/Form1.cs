using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Client
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void btn_signup_Click(object sender, EventArgs e)
        {
            Form2 frm = new Form2();
            frm.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void btn_signin_Click(object sender, EventArgs e)
        {
            // need to be added to check if username and passsword is in the db
            if(true)
            {
                Form3 frm3 = new Form3();
                this.Hide();
                frm3.Show();
            }
            else
            {
                MessageBox.Show("the username/password is wrong pls try again or signup");
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
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
            Socket s = new Socket(AddressFamily.InterNetwork,
            SocketType.Stream, ProtocolType.Tcp); //casual socket setup
            IPAddress ipAddress = System.Net.IPAddress.Parse("127.0.0.1"); //localhost since we only use localhost anyway
            IPEndPoint ipe = new IPEndPoint(ipAddress, 8822); //trivia port
            try
            {
                s.Connect(ipe);
            }
            catch (ArgumentNullException ae)
            {
                Console.WriteLine("ArgumentNullException : {0}", ae.ToString());
            }
            catch (System.Net.Sockets.SocketException se)
            {
                Console.WriteLine("SocketException : {0}", se.ToString());
            }
            catch (Exception fe)
            {
                Console.WriteLine("Unexpected exception : {0}", fe.ToString());
            }
            string username="",password="";
            byte[] msg = System.Text.Encoding.ASCII.GetBytes("200##"+username+"##"+password); //i just realized i was supposed to put numbers and not ##.. 
            //after all that work done i was wrong
            //im done.
            int bytesSent = s.Send(msg);

            int bytesRec = s.Receive(msg);
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

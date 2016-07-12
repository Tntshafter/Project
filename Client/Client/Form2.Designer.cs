namespace Client
{
    partial class Form2
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form2));
            this.btn_back = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.tb_u = new System.Windows.Forms.TextBox();
            this.tb_p = new System.Windows.Forms.TextBox();
            this.tb_e = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.btn_smu = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btn_back
            // 
            this.btn_back.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.btn_back.Location = new System.Drawing.Point(12, 300);
            this.btn_back.Name = "btn_back";
            this.btn_back.Size = new System.Drawing.Size(82, 48);
            this.btn_back.TabIndex = 0;
            this.btn_back.Text = "BACK";
            this.btn_back.UseVisualStyleBackColor = true;
            this.btn_back.Click += new System.EventHandler(this.button1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Peru;
            this.label2.Location = new System.Drawing.Point(584, 335);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(137, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "created by Boris and Daniel";
            // 
            // tb_u
            // 
            this.tb_u.Location = new System.Drawing.Point(277, 82);
            this.tb_u.Name = "tb_u";
            this.tb_u.Size = new System.Drawing.Size(172, 20);
            this.tb_u.TabIndex = 3;
            this.tb_u.Text = "Username";
            this.tb_u.TextChanged += new System.EventHandler(this.tb_u_TextChanged);
            // 
            // tb_p
            // 
            this.tb_p.Location = new System.Drawing.Point(263, 122);
            this.tb_p.Name = "tb_p";
            this.tb_p.Size = new System.Drawing.Size(203, 20);
            this.tb_p.TabIndex = 4;
            this.tb_p.Text = "Password";
            this.tb_p.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // tb_e
            // 
            this.tb_e.Location = new System.Drawing.Point(236, 166);
            this.tb_e.Name = "tb_e";
            this.tb_e.Size = new System.Drawing.Size(253, 20);
            this.tb_e.TabIndex = 5;
            this.tb_e.Text = "Email";
            // 
            // textBox4
            // 
            this.textBox4.BackColor = System.Drawing.Color.DimGray;
            this.textBox4.ForeColor = System.Drawing.SystemColors.Info;
            this.textBox4.Location = new System.Drawing.Point(633, 5);
            this.textBox4.Multiline = true;
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(88, 115);
            this.textBox4.TabIndex = 6;
            this.textBox4.Text = "the password must be at least 4 characters long and have number, capital letter a" +
    "nd a regular letter";
            // 
            // btn_smu
            // 
            this.btn_smu.Location = new System.Drawing.Point(301, 216);
            this.btn_smu.Name = "btn_smu";
            this.btn_smu.Size = new System.Drawing.Size(124, 54);
            this.btn_smu.TabIndex = 7;
            this.btn_smu.Text = "Sign me Up";
            this.btn_smu.UseVisualStyleBackColor = true;
            this.btn_smu.Click += new System.EventHandler(this.btn_smu_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(733, 360);
            this.Controls.Add(this.btn_smu);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.tb_e);
            this.Controls.Add(this.tb_p);
            this.Controls.Add(this.tb_u);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btn_back);
            this.Name = "Form2";
            this.Text = "Sign Up";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_back;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tb_u;
        private System.Windows.Forms.TextBox tb_p;
        private System.Windows.Forms.TextBox tb_e;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.Button btn_smu;
    }
}
namespace Client
{
    partial class Form3
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form3));
            this.label1 = new System.Windows.Forms.Label();
            this.lbl_greetings = new System.Windows.Forms.Label();
            this.btn_creater = new System.Windows.Forms.Button();
            this.btn_hscore = new System.Windows.Forms.Button();
            this.btn_status = new System.Windows.Forms.Button();
            this.btn_joinr = new System.Windows.Forms.Button();
            this.btn_exit = new System.Windows.Forms.Button();
            this.btn_signout = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 26.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Italic | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label1.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.label1.Location = new System.Drawing.Point(87, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(570, 39);
            this.label1.TabIndex = 1;
            this.label1.Text = "welcome to magshimim tryivia 2016";
            // 
            // lbl_greetings
            // 
            this.lbl_greetings.AutoSize = true;
            this.lbl_greetings.BackColor = System.Drawing.Color.Transparent;
            this.lbl_greetings.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.lbl_greetings.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.lbl_greetings.Location = new System.Drawing.Point(34, 96);
            this.lbl_greetings.Name = "lbl_greetings";
            this.lbl_greetings.Size = new System.Drawing.Size(89, 37);
            this.lbl_greetings.TabIndex = 2;
            this.lbl_greetings.Text = "Hello";
            // 
            // btn_creater
            // 
            this.btn_creater.Location = new System.Drawing.Point(452, 99);
            this.btn_creater.Name = "btn_creater";
            this.btn_creater.Size = new System.Drawing.Size(108, 42);
            this.btn_creater.TabIndex = 3;
            this.btn_creater.Text = "Create Room";
            this.btn_creater.UseVisualStyleBackColor = true;
            // 
            // btn_hscore
            // 
            this.btn_hscore.Location = new System.Drawing.Point(515, 228);
            this.btn_hscore.Name = "btn_hscore";
            this.btn_hscore.Size = new System.Drawing.Size(108, 42);
            this.btn_hscore.TabIndex = 4;
            this.btn_hscore.Text = "High Score";
            this.btn_hscore.UseVisualStyleBackColor = true;
            // 
            // btn_status
            // 
            this.btn_status.Location = new System.Drawing.Point(515, 164);
            this.btn_status.Name = "btn_status";
            this.btn_status.Size = new System.Drawing.Size(108, 42);
            this.btn_status.TabIndex = 5;
            this.btn_status.Text = "My Status";
            this.btn_status.UseVisualStyleBackColor = true;
            // 
            // btn_joinr
            // 
            this.btn_joinr.Location = new System.Drawing.Point(582, 99);
            this.btn_joinr.Name = "btn_joinr";
            this.btn_joinr.Size = new System.Drawing.Size(108, 42);
            this.btn_joinr.TabIndex = 6;
            this.btn_joinr.Text = "Join Room";
            this.btn_joinr.UseVisualStyleBackColor = true;
            // 
            // btn_exit
            // 
            this.btn_exit.Location = new System.Drawing.Point(27, 296);
            this.btn_exit.Name = "btn_exit";
            this.btn_exit.Size = new System.Drawing.Size(85, 39);
            this.btn_exit.TabIndex = 7;
            this.btn_exit.Text = "Exit";
            this.btn_exit.UseVisualStyleBackColor = true;
            this.btn_exit.Click += new System.EventHandler(this.btn_exit_Click);
            // 
            // btn_signout
            // 
            this.btn_signout.Location = new System.Drawing.Point(27, 243);
            this.btn_signout.Name = "btn_signout";
            this.btn_signout.Size = new System.Drawing.Size(85, 38);
            this.btn_signout.TabIndex = 8;
            this.btn_signout.Text = "Sign out";
            this.btn_signout.UseVisualStyleBackColor = true;
            this.btn_signout.Click += new System.EventHandler(this.btn_signout_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Peru;
            this.label3.Location = new System.Drawing.Point(579, 322);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(137, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "created by Boris and Daniel";
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(728, 347);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.btn_signout);
            this.Controls.Add(this.btn_exit);
            this.Controls.Add(this.btn_joinr);
            this.Controls.Add(this.btn_status);
            this.Controls.Add(this.btn_hscore);
            this.Controls.Add(this.btn_creater);
            this.Controls.Add(this.lbl_greetings);
            this.Controls.Add(this.label1);
            this.Name = "Form3";
            this.Text = "Menu";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lbl_greetings;
        private System.Windows.Forms.Button btn_creater;
        private System.Windows.Forms.Button btn_hscore;
        private System.Windows.Forms.Button btn_status;
        private System.Windows.Forms.Button btn_joinr;
        private System.Windows.Forms.Button btn_exit;
        private System.Windows.Forms.Button btn_signout;
        private System.Windows.Forms.Label label3;
    }
}
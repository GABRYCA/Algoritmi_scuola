namespace IpScanner
{
    partial class PulsanteScansiona
    {
        /// <summary>
        /// Variabile di progettazione necessaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Pulire le risorse in uso.
        /// </summary>
        /// <param name="disposing">ha valore true se le risorse gestite devono essere eliminate, false in caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Codice generato da Progettazione Windows Form

        /// <summary>
        /// Metodo necessario per il supporto della finestra di progettazione. Non modificare
        /// il contenuto del metodo con l'editor di codice.
        /// </summary>
        private void InitializeComponent()
        {
            this.listConnessi = new System.Windows.Forms.ListBox();
            this.listDisconnessi = new System.Windows.Forms.ListBox();
            this.txtIP = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.btnStart = new System.Windows.Forms.Button();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.contatoreConnessi = new System.Windows.Forms.Label();
            this.contatoreDisconnessi = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // listConnessi
            // 
            this.listConnessi.BackColor = System.Drawing.SystemColors.WindowFrame;
            this.listConnessi.ForeColor = System.Drawing.SystemColors.Window;
            this.listConnessi.FormattingEnabled = true;
            this.listConnessi.ItemHeight = 16;
            this.listConnessi.Location = new System.Drawing.Point(12, 114);
            this.listConnessi.Name = "listConnessi";
            this.listConnessi.Size = new System.Drawing.Size(371, 324);
            this.listConnessi.TabIndex = 0;
            this.listConnessi.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // listDisconnessi
            // 
            this.listDisconnessi.BackColor = System.Drawing.SystemColors.WindowFrame;
            this.listDisconnessi.ForeColor = System.Drawing.SystemColors.Window;
            this.listDisconnessi.FormattingEnabled = true;
            this.listDisconnessi.ItemHeight = 16;
            this.listDisconnessi.Location = new System.Drawing.Point(407, 114);
            this.listDisconnessi.Name = "listDisconnessi";
            this.listDisconnessi.Size = new System.Drawing.Size(381, 324);
            this.listDisconnessi.TabIndex = 1;
            this.listDisconnessi.SelectedIndexChanged += new System.EventHandler(this.listDisconnessi_SelectedIndexChanged);
            // 
            // txtIP
            // 
            this.txtIP.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.txtIP.ForeColor = System.Drawing.Color.White;
            this.txtIP.Location = new System.Drawing.Point(137, 33);
            this.txtIP.Name = "txtIP";
            this.txtIP.Size = new System.Drawing.Size(489, 22);
            this.txtIP.TabIndex = 2;
            this.txtIP.Tag = "";
            this.txtIP.Text = "172.22.166.";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(26, 34);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(105, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "Inserire indirizzo:";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // btnStart
            // 
            this.btnStart.BackColor = System.Drawing.SystemColors.GrayText;
            this.btnStart.Location = new System.Drawing.Point(645, 33);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(143, 26);
            this.btnStart.TabIndex = 5;
            this.btnStart.Text = "Scansiona!";
            this.btnStart.UseVisualStyleBackColor = false;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // progressBar1
            // 
            this.progressBar1.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.progressBar1.Location = new System.Drawing.Point(12, 65);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(776, 23);
            this.progressBar1.TabIndex = 6;
            this.progressBar1.Click += new System.EventHandler(this.progressBar1_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(9, 95);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(71, 16);
            this.label3.TabIndex = 8;
            this.label3.Text = "Connesso:";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(404, 95);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(89, 16);
            this.label4.TabIndex = 9;
            this.label4.Text = "Disconnesso:";
            // 
            // contatoreConnessi
            // 
            this.contatoreConnessi.AutoSize = true;
            this.contatoreConnessi.Location = new System.Drawing.Point(86, 95);
            this.contatoreConnessi.Name = "contatoreConnessi";
            this.contatoreConnessi.Size = new System.Drawing.Size(14, 16);
            this.contatoreConnessi.TabIndex = 10;
            this.contatoreConnessi.Text = "0";
            this.contatoreConnessi.Click += new System.EventHandler(this.label1_Click_1);
            // 
            // contatoreDisconnessi
            // 
            this.contatoreDisconnessi.AutoSize = true;
            this.contatoreDisconnessi.Location = new System.Drawing.Point(499, 95);
            this.contatoreDisconnessi.Name = "contatoreDisconnessi";
            this.contatoreDisconnessi.Size = new System.Drawing.Size(14, 16);
            this.contatoreDisconnessi.TabIndex = 11;
            this.contatoreDisconnessi.Text = "0";
            // 
            // PulsanteScansiona
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.contatoreDisconnessi);
            this.Controls.Add(this.contatoreConnessi);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtIP);
            this.Controls.Add(this.listDisconnessi);
            this.Controls.Add(this.listConnessi);
            this.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Name = "PulsanteScansiona";
            this.Text = "IPScanner di GCA";
            this.Load += new System.EventHandler(this.PulsanteScansiona_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listConnessi;
        private System.Windows.Forms.ListBox listDisconnessi;
        private System.Windows.Forms.TextBox txtIP;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label contatoreConnessi;
        private System.Windows.Forms.Label contatoreDisconnessi;
    }
}


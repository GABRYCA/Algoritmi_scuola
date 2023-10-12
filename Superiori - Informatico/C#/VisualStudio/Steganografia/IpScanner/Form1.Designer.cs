namespace IpScanner
{
    partial class Steganografia
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
            this.ms1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.apriToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.scriviSteganografiaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.leggiSteganografiaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pb1 = new System.Windows.Forms.PictureBox();
            this.txtBox1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.labelPWD = new System.Windows.Forms.Label();
            this.txtBoxPWD = new System.Windows.Forms.TextBox();
            this.scriviAESToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.leggiAESToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ms1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb1)).BeginInit();
            this.SuspendLayout();
            // 
            // ms1
            // 
            this.ms1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.ms1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.ms1.Location = new System.Drawing.Point(0, 0);
            this.ms1.Name = "ms1";
            this.ms1.Padding = new System.Windows.Forms.Padding(5, 2, 0, 2);
            this.ms1.Size = new System.Drawing.Size(1439, 30);
            this.ms1.TabIndex = 0;
            this.ms1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.apriToolStripMenuItem1});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(46, 26);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // apriToolStripMenuItem1
            // 
            this.apriToolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.scriviSteganografiaToolStripMenuItem,
            this.leggiSteganografiaToolStripMenuItem,
            this.scriviAESToolStripMenuItem,
            this.leggiAESToolStripMenuItem});
            this.apriToolStripMenuItem1.Name = "apriToolStripMenuItem1";
            this.apriToolStripMenuItem1.Size = new System.Drawing.Size(224, 26);
            this.apriToolStripMenuItem1.Text = "Apri";
            this.apriToolStripMenuItem1.Click += new System.EventHandler(this.apriToolStripMenuItem1_Click);
            // 
            // scriviSteganografiaToolStripMenuItem
            // 
            this.scriviSteganografiaToolStripMenuItem.Name = "scriviSteganografiaToolStripMenuItem";
            this.scriviSteganografiaToolStripMenuItem.Size = new System.Drawing.Size(225, 26);
            this.scriviSteganografiaToolStripMenuItem.Text = "Scrivi steganografia";
            this.scriviSteganografiaToolStripMenuItem.Click += new System.EventHandler(this.scriviSteganografiaToolStripMenuItem_Click);
            // 
            // leggiSteganografiaToolStripMenuItem
            // 
            this.leggiSteganografiaToolStripMenuItem.Name = "leggiSteganografiaToolStripMenuItem";
            this.leggiSteganografiaToolStripMenuItem.Size = new System.Drawing.Size(225, 26);
            this.leggiSteganografiaToolStripMenuItem.Text = "Leggi steganografia";
            this.leggiSteganografiaToolStripMenuItem.Click += new System.EventHandler(this.leggiSteganografiaToolStripMenuItem_Click);
            // 
            // pb1
            // 
            this.pb1.Location = new System.Drawing.Point(206, 44);
            this.pb1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pb1.Name = "pb1";
            this.pb1.Size = new System.Drawing.Size(1221, 716);
            this.pb1.TabIndex = 1;
            this.pb1.TabStop = false;
            // 
            // txtBox1
            // 
            this.txtBox1.Location = new System.Drawing.Point(12, 62);
            this.txtBox1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.txtBox1.Multiline = true;
            this.txtBox1.Name = "txtBox1";
            this.txtBox1.Size = new System.Drawing.Size(188, 529);
            this.txtBox1.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 44);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(139, 16);
            this.label1.TabIndex = 3;
            this.label1.Text = "Testo da nascondere:";
            // 
            // button1
            // 
            this.button1.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.button1.Location = new System.Drawing.Point(12, 656);
            this.button1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(188, 104);
            this.button1.TabIndex = 4;
            this.button1.Text = "Nascondi";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(12, 764);
            this.progressBar1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(1415, 23);
            this.progressBar1.TabIndex = 5;
            // 
            // labelPWD
            // 
            this.labelPWD.AutoSize = true;
            this.labelPWD.Location = new System.Drawing.Point(12, 593);
            this.labelPWD.Name = "labelPWD";
            this.labelPWD.Size = new System.Drawing.Size(70, 16);
            this.labelPWD.TabIndex = 6;
            this.labelPWD.Text = "Password:";
            this.labelPWD.Visible = false;
            this.labelPWD.Click += new System.EventHandler(this.label2_Click);
            // 
            // txtBoxPWD
            // 
            this.txtBoxPWD.Location = new System.Drawing.Point(12, 612);
            this.txtBoxPWD.Multiline = true;
            this.txtBoxPWD.Name = "txtBoxPWD";
            this.txtBoxPWD.Size = new System.Drawing.Size(188, 39);
            this.txtBoxPWD.TabIndex = 7;
            this.txtBoxPWD.Visible = false;
            // 
            // scriviAESToolStripMenuItem
            // 
            this.scriviAESToolStripMenuItem.Name = "scriviAESToolStripMenuItem";
            this.scriviAESToolStripMenuItem.Size = new System.Drawing.Size(225, 26);
            this.scriviAESToolStripMenuItem.Text = "Scrivi AES";
            this.scriviAESToolStripMenuItem.Click += new System.EventHandler(this.scriviAESToolStripMenuItem_Click);
            // 
            // leggiAESToolStripMenuItem
            // 
            this.leggiAESToolStripMenuItem.Name = "leggiAESToolStripMenuItem";
            this.leggiAESToolStripMenuItem.Size = new System.Drawing.Size(225, 26);
            this.leggiAESToolStripMenuItem.Text = "Leggi AES";
            this.leggiAESToolStripMenuItem.Click += new System.EventHandler(this.leggiAESToolStripMenuItem_Click);
            // 
            // Steganografia
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(1439, 798);
            this.Controls.Add(this.txtBoxPWD);
            this.Controls.Add(this.labelPWD);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtBox1);
            this.Controls.Add(this.pb1);
            this.Controls.Add(this.ms1);
            this.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Steganografia";
            this.Text = "Steganografia di GCA";
            this.Load += new System.EventHandler(this.PulsanteScansiona_Load);
            this.ms1.ResumeLayout(false);
            this.ms1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip ms1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem apriToolStripMenuItem1;
        private System.Windows.Forms.PictureBox pb1;
        private System.Windows.Forms.TextBox txtBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.ToolStripMenuItem scriviSteganografiaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem leggiSteganografiaToolStripMenuItem;
        private System.Windows.Forms.Label labelPWD;
        private System.Windows.Forms.ToolStripMenuItem scriviAESToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem leggiAESToolStripMenuItem;
        private System.Windows.Forms.TextBox txtBoxPWD;
    }
}


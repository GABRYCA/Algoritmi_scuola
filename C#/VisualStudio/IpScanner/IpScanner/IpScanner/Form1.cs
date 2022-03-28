using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IpScanner
{
    public partial class PulsanteScansiona : Form
    {
        public PulsanteScansiona()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            string mioIP = txtIP.Text;

            if (mioIP == "")
            {
                MessageBox.Show("Inserisci un IP valido");
            }
            else
            {
                Task.Factory.StartNew(() =>
                {
                    MessageBox.Show("Scansione avviata!");

                });
                listConnessi.Items.Clear();
                listDisconnessi.Items.Clear();
                PingSubnet(mioIP);
            }
        }

        public void PingSubnet(string address)
        {
            Ping ping = new Ping(); // Creo pacchetto.
            PingOptions pingOptions = new PingOptions(); // Come il pacchetto deve essere inizializzato.
            pingOptions.DontFragment = true; // Non frammentare il pacchetto.
            pingOptions.Ttl = 128; // Default
            string data = "";
            for (int i = 0; i < 32; i++)
            {
                data += "A";
            }

            byte[] buffer = Encoding.ASCII.GetBytes(data);
            int timeout = 120; // Timeout in secondi.
            progressBar1.Value = 0;
            progressBar1.Maximum = 255;

            for (int i = 0; i < 255; i++)
            {
                string host = address + i;
                PingReply reply = ping.Send(host, timeout, buffer, pingOptions); // Invio il ping.
                if (reply == null)
                {
                    Console.WriteLine("Ping fallito!");
                }
                else
                {
                    if (reply.Status == IPStatus.Success)
                    {
                        listConnessi.Items.Add(host);
                    }
                    else
                    {
                        listDisconnessi.Items.Add(host);
                    }
                    progressBar1.Value = i;
                    this.Refresh();
                }
            }
            MessageBox.Show("Scansione terminata");
        }

        private void listDisconnessi_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }
    }
}

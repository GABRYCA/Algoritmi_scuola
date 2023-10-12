using System;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IpScanner
{
    public partial class PulsanteScansiona : Form
    {
        
        // Refresh del form.
        private readonly SynchronizationContext synchronizationContext;
        private CancellationTokenSource tokenCancellazione;
        private DateTime tempoPrima = DateTime.Now;

        public PulsanteScansiona()
        {
            InitializeComponent();
            synchronizationContext = SynchronizationContext.Current;
        }
        
        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        
        private async void btnStart_Click(object sender, EventArgs e)
        {

            if (tokenCancellazione != null) // Il pulsante è stato premuto per terminare.
            {
                tokenCancellazione.Cancel();
                btnStart.Text = "Scansiona!";
                MessageBox.Show("Scansione annullata!");
                return;
            }
            
            string mioIP = txtIP.Text;

            if (mioIP == "") // Controllo che l'ip non sia nullo.
            {
                MessageBox.Show("Inserisci un IP valido");
            }
            else
            {
                String[] partiIP = mioIP.Split('.'); // Split dell'ip.
                if (partiIP.Length != 4)
                {
                    MessageBox.Show("Inserire un IP valido!");
                    return;
                }

                partiIP[3] = ""; // Imposto l'ultimo a vuoto, sarà sostituito in automatico.

                mioIP = ""; // Ripulisco l'IP.
                for (int i = 0; i < partiIP.Length; i++) // Per ogni parte dell'IP.
                {
                    mioIP += partiIP[i]; // Ricostruisco l'IP.
                    if (i != partiIP.Length - 1) // Aggiungo il "." se non è l'ultima parte.
                    {
                        mioIP += ".";
                    }
                }

                Task.Factory.StartNew(() =>
                {
                    MessageBox.Show("Scansione avviata!");
                });
                progressBar1.Value = 0; // Setto barra a 0.
                progressBar1.Maximum = 255; // Dimensione massima barra.
                listConnessi.Items.Clear(); // Pulisco lista.
                listDisconnessi.Items.Clear(); // Pulisco lista.
                contatoreConnessi.Text = "0"; // Setto contatore a 0.
                contatoreDisconnessi.Text = "0"; // Setto contatore a 0
                btnStart.Text = "Termina!"; // Cambio testo pulsante.
                tokenCancellazione = new CancellationTokenSource(); // Token per cancellazione thread.

                await Task.Run(() => PingSubnet(mioIP), tokenCancellazione.Token); // Avvio thread.
            }
        }

        public async void PingSubnet(string address)
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

            for (int i = 0; i < 255; i++)
            {
                if (tokenCancellazione.IsCancellationRequested) // Controllo se è stato richiesto di terminare la scansione.
                {
                    tokenCancellazione.Dispose(); // Rilascio le risorse, non dovrebbe essere necessario.
                    tokenCancellazione = null; // Setto a nullo il token per evitare problemi.
                    return;
                }
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
                        // Aggiorno lista.
                        synchronizationContext.Post(new SendOrPostCallback(value =>
                        {
                            listConnessi.Items.Add(value);
                            contatoreConnessi.Text = (int.Parse(contatoreConnessi.Text) + 1).ToString();
                        }), host);
                    }
                    else
                    {
                        // Aggiorno lista.
                        synchronizationContext.Post(new SendOrPostCallback(value =>
                        {
                            contatoreDisconnessi.Text = (int.Parse(contatoreDisconnessi.Text) + 1).ToString();
                            listDisconnessi.Items.Add(value);
                        }), host);
                    }
                    // Aggiorno barra.
                    synchronizationContext.Post(new SendOrPostCallback(value =>
                    {
                        progressBar1.Value = (int)value;
                    }), i);
                    if ((DateTime.Now - tempoPrima).Milliseconds >= 50)
                    {
                        tempoPrima = DateTime.Now;
                    }
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

        private void PulsanteScansiona_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }
    }
}

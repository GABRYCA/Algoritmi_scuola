using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IpScanner
{
    public partial class Steganografia : Form
    {
        private string file;
        OpenFileDialog dlgFile = new OpenFileDialog();
        private Bitmap bitmap = null;
        private readonly SynchronizationContext synchronizationContext;
        private CancellationTokenSource tokenCancellazione;

        public Steganografia()
        {
            InitializeComponent();
            synchronizationContext = SynchronizationContext.Current;
        }

        private void PulsanteScansiona_Load(object sender, EventArgs e)
        {

        }

        private void apriToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            /*dlgFile.InitialDirectory = "c:\\";
            // Image filter dlg.
            dlgFile.Filter = "Image Files(*.PNG;*.BMP;*.JPG;*.GIF)|*.PNG;*.BMP;*.JPG;*.GIF|All files (*.*)|*.*";
            dlgFile.FilterIndex = 1;
            dlgFile.RestoreDirectory = true;
            
            if (dlgFile.ShowDialog() == DialogResult.OK)
            {
                // Percorso del file.
                file = dlgFile.FileName;
                
                // Visualizza nell'imagebox il file selezionato.
                pb1.SizeMode = PictureBoxSizeMode.StretchImage;
                bitmap = new Bitmap(file);
                pb1.Image = bitmap;
                button1.Text = "Nascondi";
            }*/
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            if (button1.Text == "Nascondi") // Se la modalità del pulsante è nascondi.
            {
                if (txtBox1.Text == null) // Verifica che non sia nulla la testbox.
                {
                    MessageBox.Show("Inserisci un messaggio da cifrare!");
                    return;
                }

                string testo = txtBox1.Text; // Legge valore textbox.

                if (file == null) // Verifica che sia stato selezionato un file.
                {
                    MessageBox.Show("Seleziona un'immagine prima di procedere.");
                    return;
                }

                if (bitmap.Width * bitmap.Height < testo.Length * 8) // Verifica che ci sia abbastanza spazio per cifrare il testo.
                {
                    MessageBox.Show("L'immagine selezionata non è sufficiente per contenere il messaggio.");
                    return;
                }

                progressBar1.Maximum = bitmap.Width * bitmap.Height; // Crea progressbar con dimensioni appropriate.
                progressBar1.Value = 0; // Resetta progressbar.

                Task.Factory.StartNew(() => { MessageBox.Show("Cifratura avviata!"); }); // Messaggio di avvio cifratura.

                tokenCancellazione = new CancellationTokenSource(); // Token per cancellazione thread.

                await Task.Run(() => NascondiImmagine(testo), tokenCancellazione.Token); // Avvio task.
                // Salvo l'immagine
                SaveFileDialog dialog = new SaveFileDialog(); // Creo dialogo per salvataggio.
                dialog.Filter = "Image Files(*.BMP;)|*.BMP;|All files (*.*)|*.*"; // Imposto filtro.
                dialog.FilterIndex = 1; 
                if (dialog.ShowDialog() == DialogResult.OK) // Se il dialogo è andato a buon fine.
                {
                    bitmap.Save(dialog.FileName, ImageFormat.Bmp); // Salvo l'immagine.
                }
            } 
            else if (button1.Text == "Rivela") // Se il pulsante è impostato su rivela.
            {
                if (file == null) // Verifica che il file non sia nullo.
                {
                    MessageBox.Show("Seleziona un'immagine prima di procedere.");
                    return;
                }

                progressBar1.Maximum = bitmap.Width * bitmap.Height; // Imposta dimensioni appropriate progressbar, massima teorica!
                progressBar1.Value = 0; // Resetta progressbar.
                
                RivelaImmagine();
            }
            else // Il pulsante aveva un testo non previsto.
            {
                MessageBox.Show("Qualcosa è andato storto, chiuda e riapra il programma per favore!");
            }
        }

        private async void RivelaImmagine()
        {
            string testo = ""; // Testo da rivelare.
            string tempBits = ""; // Stringa temporanea per salvare i bit.
            int bitInLettura = 0; // Contatore bit letti prima di convertire in carattere.
            for (int x = 0; x < bitmap.Width; x++)
            {
                for (int y = 0; y < bitmap.Height; y++)
                {
                    if (bitInLettura == 8) // Se ho letto 8 bit.
                    {
                        string carattere = Encoding.ASCII.GetString(OttieniBytesDaStringaBinaria(tempBits));
                        if (carattere == "^")
                        {
                            txtBox1.Text = testo;
                            MessageBox.Show("Testo letto: " + testo);
                            return;
                        }
                        testo += carattere; // Aggiungo il carattere alla stringa.
                        bitInLettura = 0; // Resetta contatore.
                        tempBits = ""; // Resetta bits temporanei.
                    }
                    Color colorePixel = bitmap.GetPixel(x, y); // Prendo il colore del pixel.
                    string stringOfBits = Convert.ToString(colorePixel.R, 2); // Converto il colore in binario.
                    tempBits += stringOfBits.Substring(stringOfBits.Length - 1); // Aggiungo ultimo bit.
                    bitInLettura++; // Incremento contatore.
                    progressBar1.Value++; // Incremento progressbar.
                }
            }
        }

        public Byte[] OttieniBytesDaStringaBinaria(String binario)
        {
            var list = new List<Byte>();
            for (int i = 0; i < binario.Length; i += 8)
            {
                String t = binario.Substring(i, 8);
                list.Add(Convert.ToByte(t, 2));
            }

            return list.ToArray();
        }

        public static string StringABinario(string testo)
        {
            StringBuilder sb = new StringBuilder();

            foreach (char c in testo)
            {
                sb.Append(Convert.ToString(c, 2).PadLeft(8, '0'));
            }
            return sb.ToString();
        }

        private void NascondiImmagine(string testo)
        {
            testo += '^'; // Aggiungo carattere di fine bandiera.
            string binario = StringABinario(testo); // Converto testo in binario.

            int bitInCodifica = 0; // Contatore bit da codificare.
            for (int x = 0; x < bitmap.Width; x++)
            {
                for (int y = 0; y < bitmap.Height; y++)
                {
                    Color colorePixel = bitmap.GetPixel(x, y); // Prendo il colore del pixel.
                    if (bitInCodifica >= binario.Length) // Se ho finito di codificare copio.
                    {
                        bitmap.SetPixel(x, y, Color.FromArgb(colorePixel.R, colorePixel.G, colorePixel.B)); // Copio il colore.
                    }
                    else // Se non ho finito di codificare.
                    { 
                        string rosso = Convert.ToString(colorePixel.R, 2); // Converto il colore in binario.
                        rosso = rosso.Substring(rosso.Length - 1); // Elimino l'ultimo bit.
                        rosso += binario[bitInCodifica]; // Aggiungo il bit da codificare.
                        bitmap.SetPixel(x, y, Color.FromArgb(Convert.ToByte(rosso, 2), colorePixel.G, colorePixel.B)); // Copio il colore.
                        bitInCodifica++;  // Incremento contatore.
                    }
                    synchronizationContext.Post(value =>
                    {
                        progressBar1.Value++;
                    }, progressBar1.Value);
                }
            }
            
            // Aggiorno bitmap.
            synchronizationContext.Post(value =>
            {
                pb1.Image = (Bitmap) value;
            }, bitmap);

            MessageBox.Show("Steganografia completata (cifratura del messaggio nell'immagine pixel rosso)!");
        }

        private void scriviSteganografiaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            dlgFile.InitialDirectory = "c:\\";
            // Image filter dlg.
            dlgFile.Filter = "Image Files(*.PNG;*.BMP;*.JPG;*.GIF)|*.PNG;*.BMP;*.JPG;*.GIF|All files (*.*)|*.*";
            dlgFile.FilterIndex = 1;
            dlgFile.RestoreDirectory = true;

            if (dlgFile.ShowDialog() == DialogResult.OK)
            {
                // Percorso del file.
                file = dlgFile.FileName;

                // Visualizza nell'imagebox il file selezionato.
                pb1.SizeMode = PictureBoxSizeMode.StretchImage;
                bitmap = new Bitmap(file);
                pb1.Image = bitmap;
                button1.Text = "Nascondi";
            }
        }

        private void leggiSteganografiaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            dlgFile.InitialDirectory = "c:\\";
            // Image filter dlg.
            dlgFile.Filter = "Image Files(*.BMP;)|*.BMP;|All files (*.*)|*.*";
            dlgFile.FilterIndex = 1;
            dlgFile.RestoreDirectory = true;

            if (dlgFile.ShowDialog() == DialogResult.OK)
            {
                // Percorso del file.
                file = dlgFile.FileName;

                // Visualizza nell'imagebox il file selezionato.
                pb1.SizeMode = PictureBoxSizeMode.StretchImage;
                bitmap = new Bitmap(file);
                pb1.Image = bitmap;
                button1.Text = "Rivela";
            }
        }
    }
}

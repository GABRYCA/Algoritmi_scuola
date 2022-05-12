using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Server
{
    internal class Program
    {
        private static Socket socket;
        public static void Main(string[] args)
        {
            // Variabili.
            string pathParole = "parole.txt";
            Socket ricevuto;
            
            Console.WriteLine("Inizializzazione server..." +
                              "\nCaricando parole da file...");
            
            // Leggo file delle parole.
            List<Parola> parole = new List<Parola>();
            using (StreamReader sr = new StreamReader(pathParole))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    parole.Add(new Parola(line));
                }
            }
            
            // Comunico numero parole trovate e avvio server.
            Console.WriteLine("\nCaricate " + parole.Count + " parole." +
                              "\nAvviando il server...");
            
            // Creo il socket.
            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            socket.Bind(new IPEndPoint(IPAddress.Any, 1313));
            
            // Avvio il server.
            Console.WriteLine("Server avviato...");
            string testoRicevuto;
            do
            {
                // Metto in listen e attendo ricezione testo.
                socket.Listen(100);
                ricevuto = socket.Accept();
                byte[] buffer = new byte[ricevuto.SendBufferSize]; // Buffer di ricezione.
                int letti = ricevuto.Receive(buffer); // Ricevo dati.
                byte[] formatted = new byte[letti]; // Array di byte formattato.
                for (int i = 0; i < letti; i++) // Leggo i Byte ricevuti.
                {
                    formatted[i] = buffer[i];
                }
                testoRicevuto = Encoding.ASCII.GetString(formatted); // Decodifico il testo ricevuto.
                
                // Controllo se il testo ricevuto è quello di stop del server.
                if (testoRicevuto == "FINE OPERAZIONI") break;
                
                // Stampo il testo ricevuto dal client.
                Console.WriteLine("\nRicevuto: " + testoRicevuto);
                
                if (testoRicevuto.Contains(";")) // Se ho ricevuto una traduzione
                {
                    parole.Add(new Parola(testoRicevuto)); // Aggiungo la parola alla lista.
                    Console.WriteLine("\nParola aggiunta: " + testoRicevuto); // Stampo la parola aggiunta.
                }
                
                // Controllo se il testoRicevuto contiene parole non presenti nella lista.
                string[] paroleSingole = testoRicevuto.Split(' ');
                List<string> paroleNonTrovate = new List<string>();
                foreach (string parola in paroleSingole) // Controllo se le singole parole sono presenti nella lista di Parola.
                {
                    bool contenuto = false;
                    foreach (Parola parolaInParole in parole) // Controllo se nelle parole sia presente quella da tradurre.
                    {
                        if (parolaInParole.italiano == parola) // Se c'è la parola in italiano, significa che è presente.
                        {
                            contenuto = true;
                        }
                    }
                    if (!contenuto) // Se non è presente nella lista.
                    {
                        Console.WriteLine("\nParola non presente: " + parola); // Stampo in console la parola non trovata.
                        if (!paroleNonTrovate.Contains(parola)) // Se non è già stata trovata prima in una lettura precedente.
                        {
                            paroleNonTrovate.Add(parola); // Aggiungo parola alla lista di parole mancanti.
                        }
                    }
                }

                if (paroleNonTrovate.Count > 0) // Se ci sono parole mancanti nella lista.
                {
                    string lineaParole = ""; // Stringa che conterrà le parole mancanti.
                    foreach (string parola in paroleNonTrovate) // Costruisco la stringa delle parole mancanti.
                    {
                        lineaParole += parola + " ";
                    }
                    byte[] bufferParole = Encoding.ASCII.GetBytes("Parole_Non_Trovate: " + lineaParole);
                    Console.WriteLine("Inviato al client: " + "Parole_Non_Trovate: " + lineaParole);
                    ricevuto.Send(bufferParole); // Invio al client le parole mancanti.
                }
                else
                {
                    foreach (Parola parola in parole) // Controllo parole.
                    {
                        if (testoRicevuto.Contains(parola.italiano)) // Controllo se presente nelle parole della stringa.
                        {
                            testoRicevuto = testoRicevuto.Replace(parola.italiano, parola.inglese); // Sostituisco la parola trovata.
                        }
                    }

                    // Invio risposta.
                    byte[] risposta = Encoding.ASCII.GetBytes("Tradotto: " + testoRicevuto);
                    ricevuto.Send(risposta);
                }
            } while (testoRicevuto != "FINE OPERAZIONE");

            // Chiudo il socket e spengo il server.
            socket.Close();
            ricevuto.Close();
            
            Console.WriteLine("Salvataggio su file in corso...");
            // Salvo su file lista parole.
            StreamWriter file = new StreamWriter(pathParole);
            foreach (Parola parola in parole)
            {
                file.WriteLine(parola.ToString());
            }
            file.Close();
            Console.WriteLine("Fine salvataggio e chiuso server con successo!");
        }
    }

    public class Parola
    {
        public string italiano;
        public string inglese;
        
        public Parola(string italiano, string inglese)
        {
            this.italiano = italiano;
            this.inglese = inglese;
        }

        public Parola(string insieme)
        {
            string[] parole = insieme.Split(';');
            italiano = parole[0];
            inglese = parole[1];
        }

        public override string ToString()
        {
            return italiano + ";" + inglese;
        }
    }
}
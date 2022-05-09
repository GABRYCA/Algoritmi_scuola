using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Server
{
    internal class Program
    {
        // Creo socket.
        private static Socket socket;
        public static void Main(string[] args)
        {
            // Variabili globali.
            string numeroStringa = "";
            Socket ricevuto;
            
            // Comunico azioni server.
            Console.WriteLine("Genero un numero casuale tra 0 e 100...");
            // Genero numero casuale tra 0 e 100 da indovinare.
            Random random = new Random();
            int numero = random.Next(1, 101);
            Console.WriteLine("Numero casuale generato: " + numero);
            
            // Creo il socket.
            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            socket.Bind(new IPEndPoint(IPAddress.Any, 1313));
            
            // Avvio il server in Listen e attendo la ricezione di dati.
            Console.WriteLine("Server avviato...");
            do
            {
                socket.Listen(100);
                ricevuto = socket.Accept();
                byte[] buffer = new byte[ricevuto.SendBufferSize]; // Buffer di ricezione.
                int letti = ricevuto.Receive(buffer); // Ricevo dati.
                byte[] formatted = new byte[letti]; // Array di byte formattato.
                for (int i = 0; i < letti; i++) // Leggo i Byte ricevuti.
                {
                    formatted[i] = buffer[i];
                }
                numeroStringa = Encoding.ASCII.GetString(formatted); // Decodifico il numero.
                Console.WriteLine("Numero ricevuto: " + numeroStringa); // Stampo il numero ricevuto dal client.
                
                int numeroRicevuto = int.Parse(numeroStringa); // Converto il numero ricevuto in int.
                
                if (numeroRicevuto == numero) // Se il numero è uguale a quello generato.
                {
                    Console.WriteLine("Hai indovinato il numero!");
                    ricevuto.Send(Encoding.ASCII.GetBytes("Hai indovinato il numero!"));
                    break;
                }
                
                if (numeroRicevuto > numero) // Se il numero è maggiore di quello generato.
                {
                    Console.WriteLine("Il numero che hai inserito e' maggiore di quello da indovinare!");
                    ricevuto.Send(Encoding.ASCII.GetBytes("Il numero che hai inserito e' maggiore di quello da indovinare!"));
                }
                else // Se il numero è minore di quello generato.
                {
                    Console.WriteLine("Il numero che hai inserito e' minore di quello da indovinare!");
                    ricevuto.Send(Encoding.ASCII.GetBytes("Il numero che hai inserito e' minore di quello da indovinare!"));
                }
                
            } while (numeroStringa != "stop");
            
            // Chiudo il socket e spengo il server.
            socket.Close();
            ricevuto.Close();
            Console.WriteLine("Fine del gioco!");
        }
    }
}
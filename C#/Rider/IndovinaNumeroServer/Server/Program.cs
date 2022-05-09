using System;
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
            string numeroStringa = "";
            Socket ricevuto;
            
            Console.WriteLine("Genero un numero casuale tra 0 e 100...");
            // Genero numero casuale tra 0 e 100 da indovinare.
            Random random = new Random();
            int numero = random.Next(0, 100);
            Console.WriteLine("Numero casuale generato: " + numero);
            
            // Creo il socket.
            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            socket.Bind(new IPEndPoint(IPAddress.Any, 1313));
            
            Console.WriteLine("Server avviato...");
            do
            {
                socket.Listen(100);
                ricevuto = socket.Accept();
                byte[] buffer = new byte[ricevuto.SendBufferSize];
                int letti = ricevuto.Receive(buffer);
                byte[] formatted = new byte[letti];
                for (int i = 0; i < letti; i++)
                {
                    formatted[i] = buffer[i];
                }
                numeroStringa = Encoding.ASCII.GetString(formatted);
                Console.WriteLine("Numero ricevuto: " + numeroStringa);
                
                int numeroRicevuto = int.Parse(numeroStringa);
                
                if (numeroRicevuto == numero)
                {
                    Console.WriteLine("Hai indovinato il numero!");
                    ricevuto.Send(Encoding.ASCII.GetBytes("Hai indovinato il numero!"));
                    break;
                }
                
                if (numeroRicevuto > numero)
                {
                    Console.WriteLine("Il numero che hai inserito e' maggiore di quello da indovinare!");
                    ricevuto.Send(Encoding.ASCII.GetBytes("Il numero che hai inserito e' maggiore di quello da indovinare!"));
                }
                else
                {
                    Console.WriteLine("Il numero che hai inserito e' minore di quello da indovinare!");
                    ricevuto.Send(Encoding.ASCII.GetBytes("Il numero che hai inserito e' minore di quello da indovinare!"));
                }
                
            } while (numeroStringa != "stop");
            socket.Close();
            ricevuto.Close();
            Console.WriteLine("Fine del gioco!");
        }
    }
}
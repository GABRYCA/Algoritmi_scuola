using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace DizionarioTraduttore
{
    internal class Program
    {

        private static Socket socket;
        public static void Main(string[] args)
        {
            // Creo l'IPEndPoint.
            var server = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 1313);

            // Creo il socket.
            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            
            string testoInserito;
            do
            {
                try
                {
                    // Mi connetto al server.
                    socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    socket.Connect(server);

                    // Chiedo testo da tradurre all'utente.
                    Console.Write("\nInserire testo da tradurre (o 'FINE OPERAZIONI' per chiudere): ");
                    testoInserito = Console.ReadLine();

                    // Invio il testo al server.
                    socket.Send(Encoding.ASCII.GetBytes(testoInserito));

                    // Controllo se il testo inserito è quello di stop.
                    if (testoInserito == "FINE OPERAZIONI") break;

                    // Ricevo la risposta.
                    var buffer = new byte[1024];
                    var bytesLetti = socket.Receive(buffer);
                    var risposta = Encoding.ASCII.GetString(buffer, 0, bytesLetti);

                    // Controllo se ho ricevuto dal server un testo comunicante delle parole da tradurre.
                    if (!risposta.Contains("Parole_Non_Trovate:"))
                    {
                        Console.WriteLine(risposta);
                    }
                    else
                    {
                        // Traduzione parole mancanti.
                        Console.WriteLine("\nAlcune parole mancanti nella traduzione!" +
                                          "\n\nInserire traduzione per le parole: ");
                        string[] paroleDaTradurre = risposta.Split(' ');

                        socket.Close(); // Chiudo socket.
                        for (int i = 1; i < paroleDaTradurre.Length - 1; i++)
                        {
                            // Mi connetto al server.
                            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                            socket.Connect(server);

                            Console.Write("Inserire traduzione parola: " + paroleDaTradurre[i]
                                                                         + "\nTraduzione: ");
                            string traduzione = Console.ReadLine();
                            Console.WriteLine("Inviato al server: " + paroleDaTradurre[i] + ";" + traduzione + "\n");
                            socket.Send(Encoding.ASCII.GetBytes(paroleDaTradurre[i] + ";" + traduzione));
                            socket.Close(); // Chiudo socket.
                        }
                    }
                    socket.Close();
                }
                catch (SocketException e) // Errore di connessione.
                {
                    Console.WriteLine("Errore durante la connessione, forse il server è offline?");
                    break;
                }
            } while (testoInserito != "FINE OPERAZIONI");
            socket.Close(); // Chiudo socket se aperto.
            Console.WriteLine("Fine programma!");
        }
    }
}
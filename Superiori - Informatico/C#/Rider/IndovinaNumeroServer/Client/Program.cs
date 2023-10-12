using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Client
{
    internal class Program
    {
        // Socket.
        private static Socket socket;

        public static void Main(string[] args)
        {
            // Creo l'IPEndPoint.
            var server = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 1313);

            // Creo il socket.
            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            // Variabili globali.
            var testoInserito = "";
            var tentativi = 0;
            do // Ciclo.
            {
                try // Potrebbero avvenire l'errore di connessione.
                {
                    // Mi connetto al server.
                    socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    socket.Connect(server);

                    // Chiedo un numero all'utente fino a quando non inserisce un numero valido.
                    var nonValidoNumero = false;
                    Console.WriteLine("Tentativo n." + (tentativi + 1)); // Comunico numero tentativo.
                    do
                    {
                        // Chiedo input utente.
                        Console.Write("Inserire il numero per provare a indovinare: ");
                        testoInserito = Console.ReadLine();

                        // Se il testo è uguale a stop, fermo tutto.
                        if (testoInserito == "Stop") break;


                        // Verifico che sia un numero valido.
                        try
                        {
                            if (testoInserito != null) int.Parse(testoInserito);
                        }
                        catch (FormatException ignored)
                        {
                            // Comunico errore.
                            Console.WriteLine("Il numero inserito non e' valido!");
                            nonValidoNumero = true;
                        }
                    } while (nonValidoNumero);

                    // Se il testo è uguale a stop, fermo tutto.
                    if (testoInserito == "Stop") break;

                    // Incremento contatore tentativi e lo invio al server.
                    tentativi++;
                    socket.Send(Encoding.ASCII.GetBytes(testoInserito));
                    Console.WriteLine("Numero inviato!\n");

                    // Ricevo stringa da socket a cui ho inviato.
                    var bytes = new byte[1024];
                    var bytesRec = socket.Receive(bytes);
                    var testoRicevuto = Encoding.ASCII.GetString(bytes, 0, bytesRec);

                    // Stampo esito tentativo.
                    Console.WriteLine(testoRicevuto + "\n");

                    // Se ho indovinato il numero, fermo tutto e comunico il numero di tentativi.
                    if (testoRicevuto == "Hai indovinato il numero!")
                    {
                        // Comunico numero tentativi.
                        Console.WriteLine("Gioco finito, numero tentativi: " + tentativi);
                        break;
                    }

                    // Chiudo il Socket.
                    socket.Close();
                }
                catch (Exception e)
                {
                    // Errore durante la connessione.
                    Console.WriteLine("Errore durante la connessione: " + e.Message);
                    socket.Close();
                    break;
                }
            } while (testoInserito != "Stop");

            // Chiudo il socket e comunico la fine del gioco.
            socket.Close();
            Console.WriteLine("Fine gioco!");
        }
    }
}
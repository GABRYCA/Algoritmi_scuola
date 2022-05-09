using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Client
{
    internal class Program
    {
        private static Socket socket;

        public static void Main(string[] args)
        {
            var server = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 1313);

            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            var testoInserito = "";
            var tentativi = 0;
            do
            {
                try
                {
                    // Mi connetto al server.
                    socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    socket.Connect(server);

                    var nonValidoNumero = false;
                    do
                    {
                        Console.WriteLine("Tentativo n." + (tentativi + 1));
                        Console.Write("Inserire il numero per provare a indovinare: ");
                        testoInserito = Console.ReadLine();
                        tentativi++;

                        if (testoInserito == "Stop") break;


                        try
                        {
                            if (testoInserito != null) int.Parse(testoInserito);
                        }
                        catch (FormatException ignored)
                        {
                            Console.WriteLine("Il numero inserito non e' valido!");
                            nonValidoNumero = true;
                        }
                    } while (nonValidoNumero);

                    if (testoInserito == "Stop") break;

                    socket.Send(Encoding.ASCII.GetBytes(testoInserito));
                    Console.WriteLine("Numero inviato!\n");

                    // Ricevo stringa da socket a cui ho inviato.
                    var bytes = new byte[1024];
                    var bytesRec = socket.Receive(bytes);
                    var testoRicevuto = Encoding.ASCII.GetString(bytes, 0, bytesRec);

                    Console.WriteLine(testoRicevuto + "\n");

                    if (testoRicevuto == "Hai indovinato il numero!")
                    {
                        Console.WriteLine("Gioco finito, numero tentativi: " + tentativi);
                        break;
                    }

                    socket.Close();
                }
                catch (Exception e)
                {
                    Console.WriteLine("Errore durante la connessione: " + e.Message);
                    socket.Close();
                    break;
                }
            } while (testoInserito != "Stop");

            socket.Close();
            Console.WriteLine("Fine gioco!");
        }
    }
}
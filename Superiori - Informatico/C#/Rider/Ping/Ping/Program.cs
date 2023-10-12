using System;
using System.IO;
using System.Text;
using System.Net.NetworkInformation;

namespace Ping
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            System.Net.NetworkInformation.Ping ping = new System.Net.NetworkInformation.Ping(); // Creo pacchetto.
            PingOptions pingOptions = new PingOptions(); // Come il pacchetto deve essere inizializzato.
            pingOptions.DontFragment = true; // Non frammentare il pacchetto.
            pingOptions.Ttl = 128; // Default
            string data = "";
            string host = "8.8.8.8";
            for (int i = 0; i < 32; i++)
            {
                data += "A";
            }

            byte[] buffer = Encoding.ASCII.GetBytes(data);
            int timeout = 1024;

            TimeSpan inizio = DateTime.Now.TimeOfDay;

            PingReply reply = ping.Send(host, timeout, buffer, pingOptions); // Invio il ping.
            if (reply == null)
            {
                Console.WriteLine("Ping fallito!");
                return;
            }

            TimeSpan fine = DateTime.Now.TimeOfDay;

            if (reply.Status == IPStatus.Success)
            {
                Console.WriteLine("Ping effettutato con successo.");
                Console.WriteLine("Tempo di risposta: " + (fine - inizio).TotalMilliseconds + " ms");
                Console.WriteLine("Tempo di ritardo: " + reply.RoundtripTime + " ms");
                Console.WriteLine("TTL: " + reply.Options.Ttl);
                Console.WriteLine("Dati ricevuti: " + reply.Buffer.Length + " bytes");
                Console.WriteLine("Indirizzo IP: " + reply.Address);
            }
            else
            {
                Console.WriteLine("Ping fallito.");
                if (reply.Status == IPStatus.TimedOut)
                {
                    Console.WriteLine("Ping fallito: timeout.");
                    return; // Se il ping fallisce, esco.
                }

                if (reply.Status == IPStatus.DestinationHostUnreachable)
                {
                    Console.WriteLine("Ping fallito: destinazione non raggiungibile. (Host non raggiungibile)");
                    return;
                }

                if (reply.Status == IPStatus.DestinationNetworkUnreachable)
                {
                    Console.WriteLine("Ping fallito: destinazione non raggiungibile. (Network)");
                    return;
                }

                if (reply.Status == IPStatus.DestinationPortUnreachable)
                {
                    Console.WriteLine("Ping fallito: destinazione non raggiungibile. (Port)");
                    return;
                }

                if (reply.Status == IPStatus.DestinationProtocolUnreachable)
                {
                    Console.WriteLine("Ping fallito: destinazione non raggiungibile. (Protocollo)");
                    return;
                }

                if (reply.Status == IPStatus.DestinationScopeMismatch)
                {
                    Console.WriteLine("Ping fallito: destinazione non raggiungibile. (Scope)");
                    return;
                }

                if (reply.Status == IPStatus.DestinationUnreachable)
                {
                    Console.WriteLine("Ping fallito: destinazione non raggiungibile. (Destinazione)");
                    return;
                }

                if (reply.Status == IPStatus.HardwareError)
                {
                    Console.WriteLine("Ping fallito: hardware error.");
                    return;
                }

                if (reply.Status == IPStatus.IcmpError)
                {
                    Console.WriteLine("Ping fallito: icmp error.");
                    return;
                }
            }
        }
    }
}
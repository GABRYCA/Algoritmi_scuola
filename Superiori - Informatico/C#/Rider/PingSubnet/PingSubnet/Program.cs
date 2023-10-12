using System;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading;

namespace PingSubnet
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            //Console.WriteLine("PingSubnet senza thread: ");
            //PingSubnet("172.22.166.");
            Console.WriteLine("PingSubnet con thread:");
            pingSubnetThread("172.22.166.");
        }

        public static void PingSubnet(string address)
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
                string host = address + i;
                PingReply reply = ping.Send(host, timeout, buffer, pingOptions); // Invio il ping.
                if (reply == null)
                {
                    Console.WriteLine("Ping fallito!");
                    return;
                }

                if (reply.Status == IPStatus.Success)
                {
                    Console.WriteLine("\nPing effettutato con successo.");
                    Console.WriteLine("Tempo di risposta: " + reply.RoundtripTime + " ms");
                    Console.WriteLine("Indirizzo IP: " + reply.Address);
                }
                else
                {
                    Console.WriteLine("\nPing fallito!");
                    Console.WriteLine("Indirizzo IP testato: " + host);
                }
            }
        }

        public static void pingSubnetThread(string address)
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

            Thread t1 = new Thread(() => pingThread(address, buffer, timeout, pingOptions, ping, 0, 127)), 
                t2 = new Thread(() => pingThread(address, buffer, timeout, pingOptions, ping, 127, 255));
            
            t1.Start();
            t2.Start();

            t1.Join();
            t2.Join();
        }

        public static void pingThread(string address, byte[] buffer, int timeout, PingOptions pingOptions, Ping ping, int inizio, int fine)
        {
            for (int i = inizio; i < fine; i++)
            {
                string host = address + i;
                PingReply reply = ping.Send(host, timeout, buffer, pingOptions); // Invio il ping.
                if (reply == null)
                {
                    Console.WriteLine("Ping fallito!");
                    return;
                }

                if (reply.Status == IPStatus.Success)
                {
                    Console.WriteLine("\nPing effettutato con successo.");
                    Console.WriteLine("Tempo di risposta: " + reply.RoundtripTime + " ms");
                    Console.WriteLine("Indirizzo IP: " + reply.Address);
                }
                else
                {
                    Console.WriteLine("\nPing fallito!");
                    Console.WriteLine("Indirizzo IP testato: " + host);
                }
            }
        }
    }
}
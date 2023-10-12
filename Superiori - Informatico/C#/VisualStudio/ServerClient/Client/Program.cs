using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
// Applicazione lato Client
namespace Client
{
    internal class Program
    {
        static Socket sck;
        static void Main(string[] args)
        {
            sck = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            //IPEndPoint localEndPoint= new IPEndPoint(IPAddress.Parse("127.0.0.1"),1235);
            IPEndPoint remoteEndPoint= new IPEndPoint(IPAddress.Parse("127.0.0.1"), 1234);
            string testo="";
            bool errore=false;
            do
            {
                try
                {
                    sck = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                    sck.Connect(remoteEndPoint);
                    
                    Console.WriteLine("Inserisci il testo");
                    testo = Console.ReadLine();
                    byte[] data = Encoding.ASCII.GetBytes(testo);

                    sck.Send(data);
                    Console.WriteLine("testo inviato");
                    //Console.ReadLine();
                    sck.Close();



                }
                catch (Exception ex)
                {
                    Console.WriteLine("Impossibile connettersi {0}",ex.Message);
                    errore=true;
                    

                }
            } while (testo != "<EOF>" && !errore);
            
        }
    }
}

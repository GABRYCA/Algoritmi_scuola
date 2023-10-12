using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
// Applicazione lato Server
namespace Server
{
    internal class Program
    {
        static byte[] Buffer { get; set; }
        static Socket sck;
        static void Main(string[] args)
            
        {
            string strData;
            
            Socket accepted;
            IPEndPoint localEndPoint=new IPEndPoint(IPAddress.Any, 1234);
            sck = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            sck.Bind(localEndPoint);
            Console.WriteLine("Server start");

            do {
                sck.Listen(100);
                
                accepted = sck.Accept();
                
                Buffer = new byte[accepted.SendBufferSize];
                string messaggio = Buffer.ToString();
                int bytesRead = accepted.Receive(Buffer);
                byte[] formatted = new byte[bytesRead];
                for (int i = 0; i < bytesRead; i++)
                {
                    formatted[i] = Buffer[i];
                }
                strData = Encoding.ASCII.GetString(formatted);

                
                Console.WriteLine(strData);
                 
            } while (strData!="<EOF>");
            sck.Close();
            accepted.Close();
            Console.WriteLine("Server stop");
            Console.Read();


        }
    }
}

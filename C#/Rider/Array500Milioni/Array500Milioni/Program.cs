using System;
using System.Threading;

namespace Array500Milioni
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Random mioRandom = new Random();
            int dimensioneArray = 500000000;
            int[] array = new int[dimensioneArray];
            
            Console.WriteLine("Inizio generazione vettore con " + dimensioneArray + " valori senza thread...");

            TimeSpan start_time = DateTime.Now.TimeOfDay;

            for (int i = 0; i < dimensioneArray; i++)
            {
                array[i] = mioRandom.Next(0, 101);
            }

            TimeSpan end_time = DateTime.Now.TimeOfDay;

            Console.WriteLine("Fine generazione, tempo impiegato caricamento senza thread: " + (end_time - start_time).Milliseconds);
            
            Console.WriteLine("\nInizio generazione vettore con " + dimensioneArray + " valori con thread...");

            Thread t1 = new Thread(() => generazione(array, 0, 100000000)),
                t2 = new Thread(() => generazione(array, 100000001, 200000000)),
                t3 = new Thread(() => generazione(array, 200000001, 300000000)),
                t4 = new Thread(() => generazione(array, 300000001, 400000000)),
                t5 = new Thread(() => generazione(array, 400000001, 500000000));

            start_time = DateTime.Now.TimeOfDay;
            
            t1.Start();
            t2.Start(); 
            t3.Start(); 
            t4.Start(); 
            t5.Start();
            
            t1.Join(); 
            t2.Join(); 
            t3.Join(); 
            t4.Join(); 
            t5.Join();

            end_time = DateTime.Now.TimeOfDay;
            
            Console.WriteLine("Fine generazione, tempo impiegato caricamento con thread: " + (end_time - start_time).Milliseconds);

            int ris1 = 0, ris2 = 0, ris3 = 0, ris4 = 0, ris5 = 0;
            t1 = new Thread(() => { ris1 = media(array, 0, 100000000); });
            t2 = new Thread(() => { ris2 = media(array, 100000001, 200000000); });
            t3 = new Thread(() => { ris3 = media(array, 200000001, 300000000); });
            t4 = new Thread(() => { ris4 = media(array, 300000001, 400000000); });
            t5 = new Thread(() => { ris5 = media(array, 400000001, 500000000); });

            start_time = DateTime.Now.TimeOfDay;

            t1.Start();
            t2.Start();
            t3.Start();
            t4.Start();
            t5.Start();

            t1.Join();
            t2.Join();
            t3.Join();
            t4.Join();
            t5.Join();

            int mediaFin = (ris1 + ris2 + ris3 + ris4 + ris5) / 5;

            end_time = DateTime.Now.TimeOfDay;

            Console.WriteLine("\nTempo impiegato media con thread: " + (end_time - start_time).Milliseconds +
                              "\nRis1: " + ris1 +
                              "\nRis2: " + ris2 +
                              "\nRis3: " + ris3 +
                              "\nRis4: " + ris4 +
                              "\nRis5: " + ris5 +
                              "\nMedia: " + mediaFin);

            start_time = DateTime.Now.TimeOfDay;

            long somma = 0;
            for (int i = 0; i < dimensioneArray; i++)
            {
                somma += array[i];
            }

            mediaFin = (int) (somma / dimensioneArray);

            end_time = DateTime.Now.TimeOfDay;

            Console.WriteLine("\nTempo impiegato media senza thread: " + (end_time - start_time).Milliseconds +
                              "\nMedia: " + mediaFin);
        }

        // Ritorna media.
        public static int media(int[] vettore, int inizio, int fine)
        {
            long somma = 0;
            for (int i = inizio; i < fine; i++)
            {
                somma += vettore[i];
            }

            return (int) (somma / (fine - inizio));
        }

        public static void generazione(int[] vettore, int inizio, int fine)
        {
            Random random = new Random();
            for (int i = inizio; i < fine; i++)
            {
                vettore[i] = random.Next(0, 101);
            }
        }
    }
}
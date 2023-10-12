using System;
using System.IO;

namespace StreamReaderAndWriter {
    internal class Program 
    {
        static void Main(string[] args) 
        {
            
            Console.WriteLine("StreamReaderAndWriter di G.C. 4BITI.");
            string nomeFile = @"C:\Users\gabry\CLionProjects\Algoritmi_scuola\C#\Rider\StreamReaderAndWriter\originale.txt";
            string nomeDestinazione = @"C:\Users\gabry\CLionProjects\Algoritmi_scuola\C#\Rider\StreamReaderAndWriter\copia.txt";
            
            Console.WriteLine("Leggo file: " + nomeFile);
            StreamReader fileOriginale = new StreamReader(nomeFile);
            
            if (File.Exists(nomeDestinazione)) // Verifico se il file esiste gia' e nel caso lo cancello.
            {
                File.Delete(nomeDestinazione);
                Console.WriteLine("Un file " + nomeDestinazione + " esisteva gia' ed e' stato cancellato.");
            }
            
            StreamWriter fileCopia = new StreamWriter(nomeDestinazione);

            Console.WriteLine("Inizio copia del File " + nomeFile + " in " + nomeDestinazione + "!");
            int numeroRighe = 0;
            string lineaLetta = null; // Linea letta.
            do
            {
                lineaLetta = fileOriginale.ReadLine();
                if (lineaLetta != null)
                {
                    fileCopia.WriteLine(lineaLetta);
                    numeroRighe++;
                }
            } while (lineaLetta != null);
            fileCopia.Close(); // Chiude StreamWriter per salvare.
            Console.WriteLine("Copiate " + numeroRighe + " righe nel file " + nomeDestinazione);
        }
    }
}
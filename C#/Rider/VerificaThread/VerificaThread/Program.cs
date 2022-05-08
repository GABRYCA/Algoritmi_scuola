using System;
using System.IO;
using System.Net;
using System.Text.RegularExpressions;
using System.Threading;

namespace VerificaThread
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            // Variabili.
            string urlDownload = "http://87.250.78.140/DivinaCommedia.txt";
            //string path = @"C:\Users\Public\Downloads\DivinaCommedia.txt";
            //string inferno = @"C:\Users\Public\Downloads\Inferno.txt", purgatorio = @"C:\Users\Public\Downloads\Purgatorio.txt", paradiso = @"C:\Users\Public\Downloads\Paradiso.txt";
            string path = @"DivinaCommedia.txt";
            string inferno = @"Inferno.txt", purgatorio = @"Purgatorio.txt", paradiso = @"Paradiso.txt";

            // Download del file.
            Console.WriteLine("\n+----------------------------");
            Console.WriteLine("Inizio download...");
            WebClient client = new WebClient();
            client.DownloadFile(urlDownload, path);
            Console.WriteLine("Fine download!");
            Console.WriteLine("+----------------------------");

            // Divido il file in tre file, uno per categoria.
            Console.WriteLine("\nInizio divisione...");
            string[] linee = File.ReadAllLines(path);
            
            // Creo i threads.
            Thread t1 = new Thread(() => DividiCapitolo(inferno, linee, "  INFERNO", "  PURGATORIO"));
            Thread t2 = new Thread(() => DividiCapitolo(purgatorio, linee, "  PURGATORIO", "  PARADISO"));
            Thread t3 = new Thread(() => DividiCapitolo(paradiso, linee, "  PARADISO", "  - - - - - - - - - - - - - - - - - - - - - - -"));
            
            // Avvio i threads.
            Console.WriteLine("\n+----------------------------");
            Console.WriteLine("| Avviando threads...");
            t1.Priority = ThreadPriority.Highest; // Ho messo la priorità per farli terminare in ordine e non usare
                                                  // variabili globali che stampano i dati dopo, cambia poco.
            t1.Start();
            Console.WriteLine("| Avviato primo thread...");
            t2.Priority = ThreadPriority.AboveNormal; // Ho messo la priorità per farli terminare in ordine e non usare
                                                      // variabili globali che stampano i dati dopo, cambia poco.
            t2.Start();
            Console.WriteLine("| Avviato secondo thread...");
            t3.Start();
            Console.WriteLine("| Avviato terzo thread...");
            Console.WriteLine("+----------------------------");

            // Join dei threads.
            t1.Join();
            t2.Join();
            t3.Join();
            Console.WriteLine("\nTerminati threads!");
            
            // Premere un tasto per chiudere.
            Console.WriteLine("\nPremere un tasto per chiudere...");
            Console.ReadKey();

            Console.WriteLine("\nFine programma!");
        }

        public static void DividiCapitolo(string path, string[] linee, string nomeCategoria, string nomeCategoriaSuccessiva)
        {
            StreamWriter writer = new StreamWriter(path); // Creo il file.
            
            // Contatori.
            int numeroVolteTitolo = 0; 
            int numeroRighe = 0;
            for (int i = 0; i < linee.Length; i++)
            {
                if (linee[i] == nomeCategoria)
                {
                    do
                    {
                        writer.WriteLine(linee[i]); // Scrivo riga nel file.

                        if (linee[i].ToUpper().Contains(nomeCategoria.Trim())) // Conto numero di volte in cui è stato trovato il titolo.
                        {
                            //numeroVolteTitolo++;
                            numeroVolteTitolo += Regex.Matches(linee[i].ToUpper(), nomeCategoria.Trim()).Count;
                        }

                        if (!string.IsNullOrEmpty(linee[i])) // Conto numero di righe ma solamente se non è vuota o nulla.
                        {
                            numeroRighe++;
                        }

                        i++;
                    } while (i < linee.Length && linee[i] != nomeCategoriaSuccessiva); // Controllo di non essere alla fine delle linee o alla categoria successiva.
                    break;
                }
            }
            writer.Close(); // Chiudo il file.
            // Stampo esiti.
            Console.WriteLine("\n+---------------------------------------------------------------------------------------------" +
                              "\n| Fine scrittura categoria: " + nomeCategoria.Trim() + 
                              "\n| Il numero di volte in cui è stato trovato il nome del titolo del capitolo " + nomeCategoria.Trim() + " è: [" + numeroVolteTitolo + "]" + 
                              "\n| Il numero di linee del capitolo " + nomeCategoria.Trim() + " è: [" + numeroRighe + "]" +
                              "\n+---------------------------------------------------------------------------------------------");
        }
    }
}
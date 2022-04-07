using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Threading;

namespace PreparazioneVerifica
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string pathCartellaDownload =
                @"C:\Users\gabry\CLionProjects\Algoritmi_scuola\C#\VisualStudio\PreparazioneVerifica\PreparazioneVerifica\Immagini";
            string pathFileLinks =
                @"C:\Users\gabry\CLionProjects\Algoritmi_scuola\C#\VisualStudio\PreparazioneVerifica\PreparazioneVerifica\Links.txt";

            List<Immagine> immagini = new List<Immagine>();
            
            // Leggo i vari link.
            StreamReader fileLinks = new StreamReader(pathFileLinks);
            string rigaLetta;
            while ((rigaLetta = fileLinks.ReadLine()) != null)
            {
                immagini.Add(new Immagine(rigaLetta));
            }
            
            Console.WriteLine("Trovati " + immagini.Count + " link. \n" +
                              "\nInizio download...\n");
            
            TimeSpan tempoInizio = DateTime.Now.TimeOfDay;
            
            // Scarico le immagini.
            List<Thread> threads = new List<Thread>();
            foreach (Immagine immagine in immagini)
            {
                Thread thread = new Thread(() => downloadImmagine(pathCartellaDownload, immagine));
                threads.Add(thread);
                thread.Start();
            }
            
            // Aspetto che tutti i thread abbiano finito.
            foreach (Thread thread in threads)
            {
                thread.Join();
            }
            
            TimeSpan tempoFine = DateTime.Now.TimeOfDay;
            
            Console.WriteLine("\nDownload completato di " + immagini.Count + ".\n" +
                              "Tempo impiegato: " + (tempoFine - tempoInizio).TotalSeconds + " secondi.");
        }

        public static void downloadImmagine(string pathDownload, Immagine immagine)
        {
            Console.WriteLine("Download in corso da " + immagine.GetUrl() + " di " + immagine.GetNome() + "...");
            WebClient webClient = new WebClient();
            try
            {
                webClient.DownloadFile(immagine.GetUrl(), pathDownload + "\\" + immagine.GetNome());
            }
            catch (WebException e)
            {
                Console.WriteLine("!!!Errore durante il download dell'immagine " + immagine.GetNome() + " dall'url " + immagine.GetUrl() + "!!!");
                return;
            }
            Console.WriteLine("Download completato di " + immagine.GetNome() + ".");
        }
    }

    class Immagine
    {
        private string nome;
        private string url;

        public Immagine(string url)
        {
            this.url = url;
            nome = url.Substring(url.LastIndexOf('/') + 1);
        }
        
        public string GetNome()
        {
            return nome;
        }
        
        public string GetUrl()
        {
            return url;
        }
    }
}
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Threading;

namespace EsVerificaThread
{
    internal class Program
    {
        
        static string downloadPath = @"C:\Users\Public\Downloads\PALLANZA2001-2021Riepilog.csv"; // Scarico il file nella cartella dei Downloads.
        static string resultsPath = @"C:\Users\Public\Downloads\Risultati.csv"; // Salvo il risultato in un file.
        static string linkDownload = @"http://87.250.78.140/PALLANZA2001-2021Riepilog.csv"; // Link del file da scaricare.

        private static int annoPiuPiovoso;
        private static int annoMenoPiovoso;
        private static double temperaturaMassimaAssoluta;
        private static double temperaturaMinimaAssoluta = int.MaxValue;
        
        private static List<Anno> anni = new List<Anno>();
        static void Main(string[] args)
        {

            Console.WriteLine("Sto scaricando il file, attendere...");
            // Scarico il file nel percorso specificato.
            WebClient webClient = new WebClient();
            webClient.DownloadFile(linkDownload, downloadPath);

            Console.WriteLine("Scaricato il file con successo!");
            
            Console.WriteLine("\nSto caricando i giorni dal file, attendere...");
            List<Giorno> giorni = new List<Giorno>();
            // Carico da file i giorni.
            StreamReader reader = new StreamReader(downloadPath);
            reader.ReadLine(); // Salto la prima riga.
            do
            {
                string riga = reader.ReadLine();
                if (riga != null)
                {
                    giorni.Add(new Giorno(riga));
                }
            } while (!reader.EndOfStream);
            reader.Close();
            
            Console.WriteLine("Caricati " + giorni.Count + " giorni con successo!");
            
            Calcoli(giorni);
        }

        public static void Calcoli(List<Giorno> giorni)
        {
            for (int i = 2001; i <= 2021; i++) // Aggiungo anni vuoti alla lista di Anni.
            {
                Anno anno = new Anno();
                anno.setAnno(i);
                anni.Add(anno);
            }
            
            Thread tAnnuale = new Thread(() => Annuali(giorni));
            Thread tMensile = new Thread(() => Mensili(giorni));
            tAnnuale.Start();
            tMensile.Start();
            tAnnuale.Join();
            tMensile.Join();
            
            Console.WriteLine("\nScrittura risultati su file...");
            StreamWriter writer = new StreamWriter(resultsPath);
            
            writer.WriteLine("AnnoPiuPiovoso:;" + annoPiuPiovoso);
            writer.WriteLine("AnnoMenoPiovoso:;" + annoMenoPiovoso);
            writer.WriteLine("TemperaturaMassimaAssoluta:;" + temperaturaMassimaAssoluta);
            writer.WriteLine("TemperaturaMinimaAssoluta:;" + temperaturaMinimaAssoluta);
            writer.WriteLine("Anno;MediaPrecipitazioni;MediaTemperatura;TemperaturaMassima;MesePiuPiovoso;MesePiuAsciutto");
            foreach (Anno anno in anni)
            {
                writer.WriteLine(anno.ToString());
            }
            writer.Close();
            Console.WriteLine("Fine scrittura risultati su file!");
        }

        public static void Annuali(List<Giorno> giorni)
        {
            Console.WriteLine("\nCalcoli annuali...");
            // Per ogni anno.
            annoPiuPiovoso = 0;
            annoMenoPiovoso = 0;
            double precipitazioniAnnoPiu = 0;
            double precipitazioniAnnoMeno = int.MaxValue;
            for (int i = 2001; i <= 2021; i++)
            {
                // Media precipitazioni.
                double temperaturaMassimaAnno = 0;
                double mediaPrecipitazioni = 0;
                double mediaTempuratura = 0;
                
                // Per ogni giorno.
                foreach (Giorno giorno in giorni)
                {
                    if (giorno.data.Year == i)
                    {
                        mediaPrecipitazioni += giorno.precipitazione;
                        mediaTempuratura += giorno.tempMedia;
                        
                        if (giorno.tempMax > temperaturaMassimaAnno)
                        {
                            temperaturaMassimaAnno = giorno.tempMax;
                        }
                    }
                    
                    if (giorno.tempMin < temperaturaMinimaAssoluta)
                    {
                        temperaturaMinimaAssoluta = giorno.tempMin;
                    }
                    
                    if (giorno.tempMax > temperaturaMassimaAssoluta)
                    {
                        temperaturaMassimaAssoluta = giorno.tempMax;
                    }
                }

                double totaleAnnuo = mediaPrecipitazioni;
                mediaPrecipitazioni /= giorni.Count(g => g.data.Year == i); // Lambda, conta quanti ogni anno.
                mediaTempuratura /= giorni.Count(g => g.data.Year == i); // Lambda, conta quanti ogni anno.

                if (totaleAnnuo > precipitazioniAnnoPiu)
                {
                    precipitazioniAnnoPiu = totaleAnnuo;
                    annoPiuPiovoso = i;
                }
                if (totaleAnnuo < precipitazioniAnnoMeno)
                {
                    precipitazioniAnnoMeno = totaleAnnuo;
                    annoMenoPiovoso = i;
                }
                
                foreach (Anno anno in anni) // Setto media annua.
                {
                    if (anno.anno == i)
                    {
                        anno.setMediaPrecipitazioni(mediaPrecipitazioni);
                        anno.setMediaTemperatura(mediaTempuratura);
                        anno.setTemperaturaMassima(temperaturaMassimaAnno);
                    }
                }
            }
            Console.WriteLine("Fine cancoli annuali!");
        }

        public static void Mensili(List<Giorno> giorni)
        {
            Console.WriteLine("\nCalcoli mensili...");
            // Per ogni anno.
            for (int i = 2001; i <= 2021; i++)
            {
                int mesePiuPiovoso = 0;
                double precipitazioniMesePiu = 0;
                int meseMenoPiovoso = 0;
                double precipitazioniMeseMeno = int.MaxValue;
                for (int j = 1; j <= 12; j++)
                {
                    double totaleMensile = 0;
                    foreach (Giorno giorno in giorni)
                    {
                        if (giorno.data.Year == i && giorno.data.Month == j) // Se è il mese corrente.
                        {
                            totaleMensile += giorno.precipitazione;
                        }
                    }
                    if (totaleMensile < precipitazioniMeseMeno)
                    {
                        precipitazioniMeseMeno = totaleMensile;
                        meseMenoPiovoso = j;
                    }
                    if (totaleMensile > precipitazioniMesePiu)
                    {
                        precipitazioniMesePiu = totaleMensile;
                        mesePiuPiovoso = j;
                    }
                }

                foreach (Anno anno in anni) // Setto media annua precipitazioni.
                {
                    if (anno.anno == i)
                    {
                        anno.setMesePiuPiovoso(mesePiuPiovoso);
                        anno.setMesePiuAsciutto(meseMenoPiovoso);
                    }
                }
            }
            Console.WriteLine("Fine calcoli mensili!");
        }
    }

    public class Anno
    {
        public int anno;
        public double mediaPrecipitazioni;
        public int mesePiuPiovoso;
        public int mesePiuAsciutto;
        public double mediaTemperatura;
        public double temperaturaMassima;

        public Anno()
        {
        }
        
        public void setAnno(int anno)
        {
            this.anno = anno;
        }
        
        public void setMediaPrecipitazioni(double media)
        {
            this.mediaPrecipitazioni = media;
        }

        public void setMediaTemperatura(double media)
        {
            this.mediaTemperatura = media;
        }
        
        public void setTemperaturaMassima(double temperatura)
        {
            this.temperaturaMassima = temperatura;
        }
        
        public void setMesePiuPiovoso(int mesePiuPiovoso)
        {
            this.mesePiuPiovoso = mesePiuPiovoso;
        }
        
        public void setMesePiuAsciutto(int mesePiuAsciutto)
        {
            this.mesePiuAsciutto = mesePiuAsciutto;
        }

        public override string ToString()
        {
            return anno + ";" + Math.Round(mediaPrecipitazioni, 2) + ";" + Math.Round(mediaTemperatura, 2) + ";" + temperaturaMassima + ";" + mesePiuPiovoso + ";" + mesePiuAsciutto;
        }
    }

    public class Giorno
    {
        public DateTime data;
        public double precipitazione;
        public double tempMedia;
        public double tempMax;
        public double tempMin;
        

        public Giorno(String data, double precipitazione, double tempMedia, double tempMax, double tempMin)
        {
            this.data = Convert.ToDateTime(data);
            this.precipitazione = precipitazione;
            this.tempMedia = tempMedia;
            this.tempMax = tempMax;
            this.tempMin = tempMin;
        }

        public Giorno(String riga)
        {
            riga.Replace(',', '.');
            string[] parti = riga.Split(';');
            try {
            data = Convert.ToDateTime(parti[0]);
            precipitazione = Convert.ToDouble(parti[1]);
            tempMedia = Convert.ToDouble(parti[2]);
            tempMax = Convert.ToDouble(parti[3]);
                tempMin = Convert.ToDouble(parti[4]);
            }
            catch (FormatException ignore)
            {
            }
        }
    }
}

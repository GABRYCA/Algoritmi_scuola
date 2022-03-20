using System;
using System.Collections.Generic;
using System.IO;

namespace AnalisiScrutinio
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Analisi scrutinio di G.C. 4BITI.");

            string pathStudenti =
                @"C:\Users\gabry\CLionProjects\Algoritmi_scuola\C#\Rider\AnalisiScrutinio\studenti.txt";
            string pathMaterie = @"C:\Users\gabry\CLionProjects\Algoritmi_scuola\C#\Rider\AnalisiScrutinio\materie.txt";
            string pathVoti = @"C:\Users\gabry\CLionProjects\Algoritmi_scuola\C#\Rider\AnalisiScrutinio\voti.txt";
            
            Console.WriteLine("Caricamento studenti...");

            List<Studente> studenti = new List<Studente>();

            int contatore = 0;
            string datoLetto = null;
            StreamReader readerStudenti = new StreamReader(pathStudenti);
            do
            {
                datoLetto = readerStudenti.ReadLine();
                if (datoLetto != null)
                {
                    contatore++;
                    string[] parti = datoLetto.Split(';');
                    studenti.Add(new Studente(parti[0], parti[1]));
                }
            } while (datoLetto != null);
            readerStudenti.Close();
            
            Console.WriteLine("Caricamento nome e cognome di "+ contatore + " studenti completato!");
            Console.WriteLine("\nInizio caricamento materie...");
            
            contatore = 0;
            List<string> materie = new List<string>();
            StreamReader readerMaterie = new StreamReader(pathMaterie);
            do
            {
                datoLetto = readerMaterie.ReadLine();
                if (datoLetto != null)
                {
                    contatore++;
                    materie.Add(datoLetto);
                }
            } while (datoLetto != null);
            readerMaterie.Close();

            for (int i = 0; i < studenti.Count; i++)
            {
                studenti[i].setMaterie(materie);
            }
            
            Console.WriteLine("Caricate con successo " + contatore + " materie!");
            Console.WriteLine("\nInizio caricamento voti...");

            contatore = 0;
            StreamReader readerVoti = new StreamReader(pathVoti);
            do
            {
                datoLetto = readerVoti.ReadLine();
                if (datoLetto != null)
                {
                    string[] parti = datoLetto.Split(';');
                    List<int> voti = new List<int>();
                    for (int i = 0; i < parti.Length; i++)
                    {
                        voti.Add(int.Parse(parti[i]));
                    }
                    studenti[contatore].setVoti(voti);
                    contatore++;
                }
            } while (datoLetto != null);
            readerVoti.Close();
            
            Console.WriteLine("Caricati con successo i voti di " + contatore + " alunni!");
            Console.WriteLine("\nTutti i dati dei File sono stati caricati! Fine punto 1!\n");

            int scelta = 0;
            do
            {
                Console.WriteLine("\nSelezionare uno studente o scrivere -1 per uscire...");
                for (int i = 0; i < studenti.Count; i++)
                {
                    Console.WriteLine(i + " -> " + studenti[i].getNome() + " " + studenti[i].getCognome());
                }
                Console.Write("Scelta: ");
                scelta = int.Parse(Console.ReadLine() ?? string.Empty);
                Console.WriteLine();

                if (scelta == -1)
                {
                    break;
                }

                if (scelta < -1 || scelta >= studenti.Count)
                {
                    Console.WriteLine("Valore non valido!");
                }
                else
                {
                    Console.WriteLine("Info " + studenti[scelta].getNome() + " " + studenti[scelta].getCognome() + ":");
                    int votoMinimo = 11;
                    int votoMassimo = -1;
                    int media = 0;
                    int contatoreMinimo = 0;
                    int contatoreMassimo = 0;
                    int debiti = 0;
                    List<int> voti = studenti[scelta].getVoti();
                    for (int i = 0; i < voti.Count; i++)
                    {
                        if (voti[i] < 6)
                        {
                            Console.WriteLine("Debito con voto " + voti[i] + " di " + materie[i] + ".");
                            debiti++;
                        }
                        media += voti[i];
                        if (voti[i] < votoMinimo)
                        {
                            votoMinimo = voti[i];
                            contatoreMinimo = i;
                        }

                        if (voti[i] > votoMassimo)
                        {
                            votoMassimo = voti[i];
                            contatoreMassimo = i;
                        }
                    }

                    media /= voti.Count;
                    Console.WriteLine("Voto minimo: " + votoMinimo + " della materia " + materie[contatoreMinimo] + ".");
                    Console.WriteLine("Voto massimo: " + votoMassimo + " della materia " + materie[contatoreMassimo] + ".");
                    Console.WriteLine("Media: " + media + ".");
                    if (debiti == 0)
                    {
                        Console.WriteLine("Promosso!");
                    } else if (debiti <= 3)
                    {
                        Console.WriteLine("Giudizio sospeso.");
                    } else
                    {
                        Console.WriteLine("Respinto!");
                    }

                    Console.Write("\nPremere un pulsante per continuare...");
                    Console.ReadKey();
                    Console.WriteLine("\n");
                }
            } while (scelta != -1);

            do
            {
                Console.WriteLine("Selezionare una materia o scrivere -1 per uscire...");
                for (int i = 0; i < materie.Count; i++)
                {
                    Console.WriteLine(i + " -> " + materie[i]);
                }
                Console.Write("Scelta: ");
                scelta = int.Parse(Console.ReadLine() ?? string.Empty);

                if (scelta == -1)
                {
                    break;
                }

                if (scelta < -1 || scelta >= materie.Count)
                {
                    Console.WriteLine("Valore non valido!");
                }
                else
                {
                    Console.WriteLine("\nInfo materia " + materie[scelta]);
                    int votoMassimo = -1;
                    int votoMinimo = 11;
                    int contatoreMassimo = 0;
                    int contatoreMinimo = 0;
                    int media = 0;
                    for (int i = 0; i < studenti.Count; i++)
                    {
                        List<int> voti = studenti[i].getVoti();
                        if (voti[scelta] < votoMinimo)
                        {
                            votoMinimo = voti[scelta];
                            contatoreMinimo = i;
                        }

                        if (voti[scelta] > votoMassimo)
                        {
                            votoMassimo = voti[scelta];
                            contatoreMassimo = i;
                        }

                        media += voti[scelta];
                        
                    }
                    media /= studenti.Count;
                    Console.WriteLine("Voto minimo: " + votoMinimo + " della materia " + studenti[contatoreMinimo].getNome() + " " + studenti[contatoreMinimo].getCognome() + ".");
                    Console.WriteLine("Voto massimo: " + votoMassimo + " della materia " + studenti[contatoreMassimo].getNome() + " " + studenti[contatoreMassimo].getCognome() + ".");
                    Console.WriteLine("Media: " + media + ".");
                    Console.Write("\nPremere un pulsante per continuare...");
                    Console.ReadKey();
                    Console.WriteLine("\n");
                }
            } while (scelta != -1);
            Console.WriteLine("\nFine programma!");
        }
    }

    public class Studente
    {
        private string nome, cognome;
        private List<string> materie;
        private List<int> voti;

        public Studente(string nome, string cognome, List<string> materie, List<int> voti)
        {
            this.nome = nome;
            this.cognome = cognome;
            this.materie = materie;
            this.voti = voti;
        }

        public Studente(string nome, string cognome)
        {
            this.nome = nome;
            this.cognome = cognome;
        }

        public string getNome()
        {
            return nome;
        }

        public string getCognome()
        {
            return cognome;
        }

        public List<string> getMaterie()
        {
            return materie;
        }

        public List<int> getVoti()
        {
            return voti;
        }

        public void setNome(string nome)
        {
            this.nome = nome;
        }

        public void setCognome(string cognome)
        {
            this.cognome = cognome;
        }

        public void setMaterie(List<string> materie)
        {
            this.materie = materie;
        }

        public void setVoti(List<int> voti)
        {
            this.voti = voti;
        }
    }
}
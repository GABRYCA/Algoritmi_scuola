using System;

class Esempio
{
    public static void Main()
    {
        bicicletta MiaBici = new bicicletta("Graziella","Bianca");
        bicicletta TuaBici = new bicicletta("Legnano");
        bicicletta SuaBici = new bicicletta();
        bicicletta altrabici = new bicicletta("Bianchi","Rossa");
        
        MiaBici.FaiUnaPedalata();
        TuaBici.FaiUnaPedalata();
        
        int velocita = MiaBici.DammiVelocita(3);
        System.Console.WriteLine("Velocità:"+velocita);
        //MiaBici.modello = "Graziella";
       //MiaBici.colore = "Bianco";
        System.Console.WriteLine("Modello Miabici:" + MiaBici.Modello);
        System.Console.WriteLine("Colori Miabici:" + MiaBici.Colore);
        System.Console.WriteLine("Modello Tuabici:" + TuaBici.Modello);
        System.Console.WriteLine("Colori Tuabici:" + TuaBici.Colore);
        System.Console.WriteLine("Modello Suabici:" + SuaBici.Modello);
        System.Console.WriteLine("Colori Suabici:" + SuaBici.Colore);
    }
}
public class bicicletta
{
    private string modello;        
    public string Modello   // property
    {
        get { return modello; }
        set { modello = value; }
    }
    private  string colore;
    public string Colore   // property
    {
        get { return colore; }
        set { colore = value; }
    }

    public bool IsInitialized;
    public bicicletta(String Model,String Color)
    {
        IsInitialized = true;
        modello = Model;
        colore = Color;
    }
    public bicicletta()
    {
        IsInitialized = true;
        modello = "Nessuno";
        colore = "Nessuno";
    }
    public bicicletta(String Model)
    {
        IsInitialized = true;
        modello = Model;
        colore = "Nessuno";
        
    }

    public void FaiUnaPedalata()
    {
        System.Console.WriteLine("Faccio una pedalata.");
    }

    public int DammiVelocita(int marcia)
    {
        return marcia * 2;
    }

}

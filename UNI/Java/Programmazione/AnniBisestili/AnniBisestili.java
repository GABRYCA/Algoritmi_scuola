import java.util.Scanner;

public class AnniBisestili {
    public static void main(String[] args){

        // Inizializzo Scanner
        Scanner in = new Scanner(System.in);

        // Chiedo input
        System.out.print("Inserire fino a che anno si vogliono sapere i bisestili: ");
        int anno = in.nextInt();

        // Verifico che l'input sia valido
        if (anno < 0) {
            System.out.println("L'anno inserito non e' valido, per favore riprovare!");
            return;
        }
        

        // Generazione anni nel vettore (Non necessario ma per allenarci con i vettori, lo facciamo lo stesso)
        System.out.println("Inizializzando anni dallo 0 all'anno inserito nel vettore...");

        int[] anni = new int[anno+1];
        for(int i = 0; i < anni.length; i++){
            anni[i] = i;
        }

        System.out.println("Inizializzazione completata! Ecco gli anni bisestili: ");

        // Ricerca anni bisestili e stampa (Inoltre vengono salvati nel vettore anniBisestili)
        int[] anniBisestili = new int[(anni.length / 4) + 1];
        int contPosBisestili = 0;
        for (int i = 0; i < anni.length; i++){
            if (anni[i] % 4 == 0) {
                System.out.println("Bisestile: " + anni[i]);
                anniBisestili[contPosBisestili] = anni[i]; // Salvo
                contPosBisestili++; // Incrememnto per prendere la posizione successiva del vettore con gli anni bisestili salvati.
            }
        }

        System.out.println("Trovati: " + contPosBisestili + " anni bisestili! \nFine del programma!");
    }
}
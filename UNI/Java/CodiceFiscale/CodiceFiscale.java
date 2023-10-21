import java.util.Scanner;

public class CodiceFiscale {
    public static void main(String[] args){
        
        Scanner in = new Scanner(System.in);

        System.out.print("Inserire il proprio codice fiscale: ");
        String input = in.nextLine();

        if (input == "") {
            System.out.println("Il codice fiscale non può essere vuoto!");
            return;
        }

        // Uppercase
        input = input.toUpperCase();

        if (codiceFiscaleValido(input)) {
            System.out.println("Il codice fiscale è valido!");
        } else {
            System.out.println("Il codice fiscale NON è valido!");
        }
        
        return;
    }

    /**
     * Metodo che ritorna TRUE se il codice fiscale ha una struttura valida, FALSE altrimenti con descrizione.
     * 
     * @param String codiceFiscale
     * @return boolean
     * */ 
    public static boolean codiceFiscaleValido(String codiceFiscale){

        if (codiceFiscale.length() != 16) {
            System.out.println("Lunghezza non valida, il codice fiscale deve essere lungo 16 caratteri!");
            return false;
        }

        for (int i = 0; i < 16; i++){
            char carattereControllo = codiceFiscale.charAt(i);
            if (i < 6 && Character.isDigit(carattereControllo)) {
                System.out.println("Problema in posizione: " + (i+1) + " (non è un carattere)");
                return false;
            }
            if ((i >= 6 && i < 8) && !Character.isDigit(carattereControllo)) {
                System.out.println("Problema in posizione: " +  (i+1) + " -> (" + carattereControllo + ") (non è un numero)");
                return false;
            }
            if (i == 8 && Character.isDigit(carattereControllo)) {
                System.out.println("Problema in posizione: " + (i+1) + " -> (" + carattereControllo + ") (non è un carattere)");
                return false;
            }
            if ((i > 8 && i < 11) && !Character.isDigit(carattereControllo)) {
                System.out.println("Problema in posizione: " + (i+1) + " -> (" + carattereControllo + ") (non è un numero)");
                return false;
            }
            if (i == 11 && Character.isDigit(carattereControllo)) {
                System.out.println("Problema in posizione: " + (i+1) + " -> (" + carattereControllo + ") (non è un carattere)");
                return false;
            }
            if ((i > 11 && i < 15) && !Character.isDigit(carattereControllo)) {
                System.out.println("Problema in posizione: " + (i+1) + " -> (" + carattereControllo + ") (non è un numero)");
                return false;
            }
            if (i == 15 && Character.isDigit(carattereControllo)) {
                System.out.println("Problema in posizione: " + (i+1) +  " -> (" + carattereControllo + ") (non è un carattere)");
                return false;
            }
        }

        return true;
    }
}
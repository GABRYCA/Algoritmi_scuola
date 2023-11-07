import java.util.Random;

class Esercizio2 {
    public static void main(String[] args){

        Random rand = new Random();
        
        int numeroDaCercare = 4;
        int maxRange = 10;
        int numeroNumeriMatrice = 10;
        int[][] matrice = new int[numeroNumeriMatrice][numeroNumeriMatrice];

        for (int i = 0; i < numeroNumeriMatrice; i++){
            for (int j = 0; j < numeroNumeriMatrice; j++){
                matrice[i][j] = rand.nextInt(maxRange);
            }
        }

        // Cerco duplicati
        int contatore = 0;
        for (int i = 0; i < numeroNumeriMatrice; i++){
            for (int j = 0; j < numeroNumeriMatrice; j++){
                if (matrice[i][j] == numeroDaCercare) {
                    contatore++;
                }
            }
        }

        System.out.println("Numero duplicati di " + numeroDaCercare + " trovati: " + contatore);
    }
}
package me.gca;

public class Main {
    final static int TANTI = 8;
    final static int MAX = 30;
    public static void main(String[] args) {
        // Creo il vettore di TANTI elementi.
        int mioVettore[] = new int[TANTI];
        // Riempio il vettore con numeri vasuali tra 0 e MAX.
        for (int x = 0; x < mioVettore.length; x++){
            mioVettore[x] = (int) (MAX * Math.random());
        }
        // Visualizzo il contenuto del vettore.
        for (int x = 0; x < mioVettore.length; x++){
            System.out.print(mioVettore[x] + " ");
        }
    }
}

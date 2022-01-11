package me.gca;


public class Main {
    public static void main(String[] args) {

        int[] numeri = {10,8,-9,9,15,6,3};

        AlberoBin alberoBin = new AlberoBin();

        alberoBin.creaDaVettore(numeri, 0, numeri.length);

        // radice, sinistra, destro etc.
        alberoBin.preorder1();
        // sinistra, destro, radice etc.
        alberoBin.postorder1();
        // sinistra, radice, destro etc.
        alberoBin.inorder1();

        System.out.print("\n\n" + alberoBin.toString());
    }
}

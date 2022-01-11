package me.gca;


public class Main {
    public static void main(String[] args) {

        int[] numeri = {10,8,-9,9,15,6,3};

        AlberoBin alberoBin = new AlberoBin();

        alberoBin.creaDaVettore(numeri, 0, numeri.length);

        alberoBin.preorder1();
        alberoBin.postorder1();
        alberoBin.inorder1();

        System.out.print("\n\n" + alberoBin.toString());
    }
}

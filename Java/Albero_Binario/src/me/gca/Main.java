package me.gca;


public class Main {
    public static void main(String[] args) {

        int[] numeri = {10,8,-9,0,15,0,3};

        AlberoBin alberoBin = new AlberoBin();

        alberoBin.crea_da_array(numeri, 0, numeri.length);

        alberoBin.preorder1();
        alberoBin.postorder1();
        alberoBin.inorder1();

        System.out.print("\n\n" + alberoBin.toString());
    }
}

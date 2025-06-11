package dato;

import java.util.Random;

public class Consumatore extends Thread {
    private final Magazzino magazzino;

    public Consumatore(String nome, Magazzino magazzino) {
        super(nome);
        this.magazzino = magazzino;
    }

    @Override
    public void run() {
        Random random = new Random();
        while (true) {
            try {
                Prodotto p = magazzino.preleva();
                System.out.println(getName() + " ha consumato: " + p);
                // Simula il tempo di consumo
                Thread.sleep(random.nextInt(1500));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
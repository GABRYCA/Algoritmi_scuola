package me.gca;

public class Studente {

    private int max = 100;
    private int min = 50;
    private int range = max - min + 1;
    private String nome;
    private int[] voti = new int[3];

    /**
     * Costrutto Studente, creo uno studente con 3 voti casuali e il nome inserito nella chiamata.
     *
     * @param nome - String.
     * */
    public Studente(String nome){
        this.nome = nome;
        for (int i = 0; i < voti.length; i++){
            voti[i] = (int) (Math.random() * range) + min;
        }
    }

    /**
     * Creo uno studente con dei voti specificati da me oltre al nome.
     *
     * @param nome - String.
     * @param voto1 - int.
     * @param voto2 - int.
     * @param voto3 - int.
     * */
    public Studente(String nome, int voto1, int voto2, int voto3){
        this.nome = nome;
        this.voti = new int[]{voto1, voto2, voto3};
    }

    public void setVoto1(int voto1) {
        this.voti[0] = voto1;
    }

    public void setVoto2(int voto2) {
        this.voti[1] = voto2;
    }

    public void setVoto3(int voto3) {
        this.voti[2] = voto3;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getVoto1() {
        return voti[0];
    }

    public int getVoto2() {
        return voti[1];
    }

    public int getVoto3() {
        return voti[2];
    }

    public String getNome() {
        return nome;
    }

    public int[] getVoti(){
        return voti;
    }
}

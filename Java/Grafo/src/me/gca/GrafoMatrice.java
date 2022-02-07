package me.gca;

import java.util.ArrayList;
import java.util.List;

public class GrafoMatrice extends Nodo {

    private List<Nodo> nodi = new ArrayList<>();
    private int[][] adiacenze = new int[0][0];

    public GrafoMatrice(){}

    public void addNodo(Nodo nodo){
        int vecchiaDimensione = adiacenze.length;
        int[][] tempAdiacenze = new int[vecchiaDimensione+1][vecchiaDimensione+1];
        nodi.add(nodo);

        for (int i = 0; i <= vecchiaDimensione; i++){
            for (int j = 0; j <= vecchiaDimensione; j++) {
                if (i < vecchiaDimensione && j < vecchiaDimensione) {
                    tempAdiacenze[i][j] = adiacenze[i][j];
                } else {
                    tempAdiacenze[i][j] = 0;
                }
            }
        }

        adiacenze = tempAdiacenze;
    }

    /**
     * Aggiungi un arco, se non presente ritorna vero, se gia' presente ritorna falso.
     *
     * @param nodo
     * @param nodo2
     * @return
     */
    public boolean addArco(Nodo nodo, Nodo nodo2){
        int pos1 = 0;
        int pos2 = 0;
        for (Nodo nodoLetto : nodi){
            if (nodoLetto == nodo){
                break;
            } else {
                pos1++;
            }
        }

        for (Nodo nodoLetto: nodi){
            if (nodoLetto == nodo2){
                break;
            } else {
                pos2++;
            }
        }

        if (adiacenze[pos1][pos2] == 1){
            return false;
        }

        adiacenze[pos1][pos2] = 1;
        return true;
    }

    /**
     * Ritorna vero se rimosso con successo, false se non rimosso perche' gia' zero.
     *
     * @param nodo
     * @param nodo2
     * @return
     */
    public boolean rimuoviArco(Nodo nodo, Nodo nodo2){
        int pos1 = 0;
        int pos2 = 0;
        for (Nodo nodoLetto : nodi){
            if (nodoLetto == nodo){
                break;
            } else {
                pos1++;
            }
        }

        for (Nodo nodoLetto: nodi){
            if (nodoLetto == nodo2){
                break;
            } else {
                pos2++;
            }
        }
        if (adiacenze[pos1][pos2] == 0){
            return false;
        }

        adiacenze[pos1][pos2] = 0;
        return true;
    }

    public void stampaNodi(){
        int pos = 0;
        for (Nodo nodo : nodi){
            Util.printfn(pos + " -> " + nodo);
            pos++;
        }
    }

    public void stampaAdiacenze(){
        for (int i = 0; i < adiacenze.length; i++){
            Util.printfn("\n");
            for (int j = 0; j < adiacenze.length; j++){
                Util.printf(adiacenze[i][j] + "\t");
            }
        }
    }

    public boolean isPosValida(int posNodo){
        return posNodo >= 0 && posNodo < nodi.size();
    }

    public Nodo getNodoPos(int posNodo){
        if (!isPosValida(posNodo)){
            return null;
        }
        return nodi.get(posNodo);
    }
}

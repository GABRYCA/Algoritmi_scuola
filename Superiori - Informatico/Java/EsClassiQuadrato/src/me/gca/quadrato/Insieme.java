package me.gca.quadrato;

public class Insieme {

    Quadrato q1;
    Quadrato q2;

    public Insieme() {}

    /**
     * Ritorna vero se il primo e il secondo quadrato intersecano tra loro, falso se non.
     * Usa le coordinate X e Y in alto a sinistra e la misura del lato.
     *
     * @param q1
     * @param q2
     * @return
     */
    public boolean sovrapposizione(Quadrato q1, Quadrato q2){
        this.q1 = q1;
        this.q2 = q2;
        return q1.getX() + q1.getLato() > q2.getX() && q1.getX() < q2.getX() + q2.getLato() && q1.getY() + q1.getLato() > q2.getY() && q1.getY() < q2.getY() + q2.getLato();
    }

    /**
     * Ritorna l'area di interseziene tra i due quadrati.
     *
     * @return
     */
    public int area(){
        /*int area = 0;
        if (sovrapposizione(q1, q2)) {
            // Trovo punti di intersezione

            System.out.println("(" + x1 + ", " + y1 + ") (" + x2 + ", " + y2 + ")");
            area = (x2 - x1) * (y2 - y1);
        }*/
        return (q1.getX() + q1.getLato() - q2.getX()) * (q1.getY() + q1.getLato() - q2.getY());
    }



}

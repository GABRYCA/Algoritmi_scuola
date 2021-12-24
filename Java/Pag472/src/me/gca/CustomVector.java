package me.gca;

import java.util.Vector;

public class CustomVector extends Vector{

    /**
     * Clone.
     * */
    public static Vector clone(Vector v){
        return v;
    }

    /**
     * Verifica se è già ordinato.
     * */
    public static boolean ordinato(Vector v){
        for (int i = 0; i < v.size(); i++){
            try {
                if (v.get(i + 1) != null && (int) v.get(i) > (int) v.get(i + 1)){
                    return false;
                }
            } catch (NullPointerException ex){
                return true;
            }
        }
        return true;
    }
}

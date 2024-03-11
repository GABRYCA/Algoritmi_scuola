class Esercizio1 {
    public static void main(String[] args){
        if (args.length == 0) {
            System.out.println("Scrivere qualcosa -> Frase mancante");
            return;
        }

        System.out.println("La frase è composta da: " + numCaratteriFrase(args) + " caratteri.");
        System.out.println("La frase è composta da: " + numStringFrase(args) + " parole.");
        System.out.println("La parola più corta della frase è: " + stringPiuCortaFrase(args));
        System.out.println("La parola più lunga della frase è: " + stringPiuLungaFrase(args));
    }

    public static int numCaratteriParola(String parola){
        return parola.length();
    }

    public static int numStringFrase(String[] frase){
        return frase.length;
    }

    public static int numCaratteriFrase(String[] frase){ // Attenzione, non conta gli spazi! (per contare gli spazi, sommare parole.length e sottrarre uno)
        int tot = 0;
        for (int i = 0; i < frase.length; i++){
            tot += numCaratteriParola(frase[i]);
        }
        return tot;
    }

    public static String stringPiuLungaFrase(String[] frase){
        String piuLunga = frase[0];

        for (int i = 1; i < frase.length; i++){
            if (numCaratteriParola(piuLunga) < numCaratteriParola(frase[i])) {
                piuLunga = frase[i];
            }
        }

        return piuLunga;
    }

    public static String stringPiuCortaFrase(String[] frase){
        String piuCorta = frase[0];

        for (int i = 1; i < frase.length; i++){
            if (numCaratteriParola(piuCorta) > numCaratteriParola(frase[i])) {
                piuCorta = frase[i];
            }
        }

        return piuCorta;
    }
    
}
enum CorsiSportivi {
    TENNIS {
        public String getOrario(){
            return "lun-ven 9:00-11:00";
        }
    },
    PALLAVOLO {
        public String getOrario(){
            return "lun-ven 11:00-13:00";
        }
    };
    public abstract String getOrario();
    public String schemaCorso(){
        return (this.ordinal() + 1) + " " + this.name() +  " " + this.getOrario();
    }
}

class CorsiSportiviEs {
    
    public static void main(String[] args){

        CorsiSportivi tennis = CorsiSportivi.TENNIS;
        CorsiSportivi pallavolo = CorsiSportivi.PALLAVOLO;

        System.out.println(tennis.schemaCorso());
        System.out.println(pallavolo.schemaCorso());

        System.out.println("Con metodo statico: ");

        System.out.println(schemaCorso(tennis));
        System.out.println(schemaCorso(pallavolo));
    }

    public static String schemaCorso(CorsiSportivi corso){
        return corso.schemaCorso();
    }
}

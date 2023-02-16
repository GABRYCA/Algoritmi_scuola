package eu.anonymousgca.databeans;

import java.util.ArrayList;

public class ValutazioniBean {

    private ArrayList<ValutazioneTPSBean> valutazioniTPS;

    public ValutazioniBean() {
        valutazioniTPS = new ArrayList<>();
    }

    public ArrayList<ValutazioneTPSBean> getValutazioniTPS() {
        return valutazioniTPS;
    }

    public void setValutazioniTPS(ArrayList<ValutazioneTPSBean> valutazioniTPS) {
        this.valutazioniTPS = valutazioniTPS;
    }

    public void addValutazioneTPS(ValutazioneTPSBean valutazioneTPS) {
        valutazioniTPS.add(valutazioneTPS);
    }

    public void removeValutazioneTPS(ValutazioneTPSBean valutazioneTPS) {
        valutazioniTPS.remove(valutazioneTPS);
    }

    public void removeValutazioneTPS(int index) {
        valutazioniTPS.remove(index);
    }

    public ValutazioneTPSBean getValutazioneTPS(int index) {
        return valutazioniTPS.get(index);
    }

    public int size() {
        return valutazioniTPS.size();
    }
}

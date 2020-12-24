package it.gabryca;

import java.util.concurrent.ThreadLocalRandom;

public class MasterMindComputer extends Util {

    public void masterMindComputer(int max, int min, int dimensioni, int[] mioVettore, int nCifre, int nTentativi){

        // Dichiaro variabili
        int nValSbagliati = 0, vinto = 0, nPersona, nPersonaVar, nUniciProvati = 0;
        int[] vetValSbagliati = new int[10];
        int[] nPersonaVet = new int[4];
        int[] vetUniciProvati = new int[1000];
        nTentativi = 0;

        // Chiedo in input all'utente il numero da indovinare
        printf("\nInserisci il numero che dovrà indovinare il pc: ");
        nPersona = getScanner().nextInt();

        // Creo una seconda variabile uguale perchè spesso per motivi sconosciuti e in modo completamente casuale, modificava la variabile
        nPersonaVar = nPersona;

        // Genera tutti i valori possibili
        dimensioni = trovaValori(dimensioni, mioVettore);

        // Richiamo funzione che divide il numero unico in singoli numeri in un vettore
        singoloValVet(nCifre, nPersonaVet, nPersonaVar);

        while (vinto == 0){

            nTentativi++;

            // Richiamo funzione che divide il numero unico in singoli numeri in un vettore
            singoloValVet(nCifre, nPersonaVet, nPersonaVar);

            // Dichiaro ulteriori variabili
            int numeriTrovati = 0, numeriTrovatiNoPos = 0;
            int[] vetNumGenPC = new int[nCifre];

            // Messaggio
            printf("\n\n\nPer favore attendere...");

            // Rimuove dalla lista dei valori possibili quelli non possibili
            // for (int i = 0; i < dimensioni; i++){

            //    int[] valoreDaVerificareSingolCifre = new int[nCifre];

            //    singoloValVet(nCifre, valoreDaVerificareSingolCifre, mioVettore[i]);

            //    for (int j = 0; j < nCifre; j++){
            //        if (valorePresenteInVet(nValSbagliati, valoreDaVerificareSingolCifre[j], vetValSbagliati)){
            //            rimuoviPerPos(dimensioni, mioVettore, i);
            //            dimensioni--;
            //        }
            //    }
            //}

            // Messaggio e richiamo funzioni per mostrare i valori
            // printf("\n\nLe possibilità si sono ridotte alle seguenti: ");
            // mostraValori(dimensioni, mioVettore);

            // Valore bandiera
            int valValido = 1, valUnico = 0;
            while (valValido != 0) {
                valValido = 0;
                int contenuto = 0, numeriGenPC = 0;
                // Crea un nuovo valore da provare senza i valori non validi e condizioni varie
                while (numeriGenPC != nCifre) {
                    vetNumGenPC[numeriGenPC] = ThreadLocalRandom.current().nextInt(min, max + 1);
                    if (!valorePresenteInVet(nValSbagliati, vetNumGenPC[numeriGenPC], vetValSbagliati) &&
                            !valorePresenteInVet(numeriGenPC, vetNumGenPC[numeriGenPC], vetNumGenPC)) {
                        numeriGenPC++;
                    }
                }

                // Ulteriori condizioni
                if (nPersonaVet[3] != 0 && vetNumGenPC[3] != 0) {

                    // Valore unico completo
                    valUnico = ((10 * vetNumGenPC[3] + vetNumGenPC[2]) * 10 + vetNumGenPC[1]) * 10 +
                            vetNumGenPC[0];

                    // Verifica se il valore è già stato provato in precedenza per non ripeterlo ancora
                    for (int i = 0; i < nUniciProvati; i++) {
                        if (vetUniciProvati[i] == valUnico){
                            valValido++;
                        }
                    }

                    // Verifica se il valore è contenuto tra quelli possibili
                    for (int i = 0; i < dimensioni; i++) {
                        if (valUnico == mioVettore[i] && contenuto == 0) {
                            contenuto++;
                        }
                    }

                    // Se entrambi le variabili sono uguali a 0, allora incrementa valValido che fa ripetere il while
                    if (contenuto == 0 && valValido == 0) {
                        valValido++;
                    }
                }
            }

            // Aggiunge il valore unico generato al vettore dei valori provati
            if (valUnico != 0){
                vetUniciProvati[nUniciProvati] = valUnico;
                nUniciProvati++;
            }

            // Verifica [] o () per il computer in modo virtuale, salvando i dati utili per
            // Trovare il valore in un turno successivo
            for (int i = 0; i < nCifre; i++) {

                // La cifra che sta provando
                int valInTentativo = vetNumGenPC[i];

                // La prima condizione verifica se la cifra è nella stessa posizione della cifra
                // Del numero inserito dall'utente da indovinare.
                // La seconda verifica se questo è solamente contenuto.
                // La terza, aggiunge il valore (se sbagliato e non già presente in precedenza) al vettore
                // dei valori non validi.
                if (valInTentativo == nPersonaVet[i]){
                    numeriTrovati++;
                } else if (valorePresenteInVet(nCifre, valInTentativo, nPersonaVet)){
                    numeriTrovatiNoPos++;
                } else if (!valorePresenteInVet(nValSbagliati, valInTentativo, vetValSbagliati)) {
                    vetValSbagliati[nValSbagliati] = valInTentativo;
                    nValSbagliati++;
                }
            }

            // Stampa [] o (), dove [] sono i valori trovati sia per posizione che per valore esatto
            // Mentre i () sono quelli solamente presenti
            printf("\n\nNumeri PC:");
            for (int i = 0; i < numeriTrovati; i++) {
                printf("[]");
            }
            for (int i = 0; i < numeriTrovatiNoPos; ++i) {
                printf("()");
            }

            // Se sono stati trovati 4 numeri validi nella posizione corretta, incrementa vinto ed esce dal while, finendo il gioco.
            if (numeriTrovati == 4){
                vinto++;
            }
        }

        // Fine
        printf("\n\nAlgoritmo finito, il numero dell'utente era " + nPersona + "." +
                "\nSono stati necessari " + nTentativi + " tentativi!");

    }

}

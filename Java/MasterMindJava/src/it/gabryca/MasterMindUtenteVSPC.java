package it.gabryca;

import java.util.concurrent.ThreadLocalRandom;

public class MasterMindUtenteVSPC extends Util {

    public void masterMindUtenteVSPC(int[] mioVettore, int max, int min, int nCifre, int nCifreGenerate){

        // Dichiaro variabili
        int nPersona, nPersonaVar;
        int[] nPersonaVet = new int[nCifre];

        // Chiedo input all'utente
        printf("\nInserisci il numero che dovrà indovinare il pc: ");
        nPersona = getScanner().nextInt();

        // Doppia dichiarazione di un valore perchè ogni tanto veniva modificato o comunque cambiava valore per motivi sconosciuti
        nPersonaVar = nPersona;

        // Divide in singole cifre in un vettore un numero
        singoloValVet(nCifre, nPersonaVet, nPersonaVar);

        //
        genValDivInVet1(mioVettore, max, min, nCifre, nCifreGenerate);

        // Numeri generati con successo, lo comunico e inizio.
        printfn("\nGenerato con successo un numero con " + nCifre + " cifre! Inizia il gioco...");

        // Inizializzo diverse variabili
        int finito = 0, nNumeriSbagliati = 0, nTurno = 0;
        int[] nProvatiPCSbagliati = new int[10];
        int[] vetPCCorPos = new int[nCifre];
        int[] nProvatoPCVet = new int[nCifre];

        // Inizializza a zero i valori nel vettore
        for (int i = 0; i < nCifre; i++) {
            vetPCCorPos[i] = 0;
        }

        // Continua fino a quando finiscono i tentativi oppure vince
        while (finito == 0) {

            // NECESSARIO PERCHè C++ ha un bug che dopo 2 cicli mi corrompe questo vettore perchè (ipotesi) è vettori vengono sovrascritti da qualcosa
            nPersonaVar = nPersona;
            singoloValVet(nCifre, nPersonaVet, nPersonaVar);

            // Dichiaro variabili
            int cifreIndovinatePersona = 0, cifreIndovinatePC = 0, cifrePersonaNoPos = 0, cifrePCNoPos = 0;
            int numeroProvatoPersona;
            int[] numeroProvatoPersonaVet = new int[nCifre];

            // NECESSARIO PERCHè C++ dopo 2 cicli mi corrompe questo vettore.
            nPersonaVar = nPersona;
            singoloValVet(nCifre, nPersonaVet, nPersonaVar);

            // Variabile bandiera che servirebbe, se non fosse commentato a causa di un problema sconosciuto
            // A verificare se tutti i valori nel vettore dei valori validi trovati, sono presenti nel
            // numero generato che andrà a fare il nuovo tentativo del computer
            int tuttiValPres = 1;
            while (tuttiValPres != 0) {
                tuttiValPres = 0;
                // Variabile bandiera che conta quante cifre valide sono state generate
                int valAgg = 0;
                while (valAgg < nCifre) {

                    // Verifica se si sta modificando un numero nel vettore che ha già una posizione corretta, nel
                    // caso lo sia, salta questa parte.
                    if (vetPCCorPos[valAgg] != 1) {

                        // Metodi sperimentali ma con un ragionamento simile al vecchio
                        nProvatoPCVet[valAgg] = ThreadLocalRandom.current().nextInt(min, max + 1);
                        while (valorePresenteInVet(valAgg, nProvatoPCVet[valAgg], nProvatoPCVet)) {
                            nProvatoPCVet[valAgg] = ThreadLocalRandom.current().nextInt(min, max + 1);
                        }

                        // Condizioni per un numero valido
                        // Nuovo metodo per verificare che un numero generato casuale è già stato provato ed era sbagliato in precedenza
                        // Nuovo metodo che verifica se un numero è già stato generato in precedenza e aggiunto al vettore (evitare doppioni)
                        if (!(valorePresenteInVet(nNumeriSbagliati, nProvatoPCVet[valAgg], nProvatiPCSbagliati)) &&
                                !(valorePresenteInVet(valAgg, nProvatoPCVet[valAgg], nProvatoPCVet))) {
                            valAgg++;
                        }

                    } else {
                        valAgg++;
                    }
                }
                // Controlla per ogni valore presente nel vettore dei valori validi trovati, se questo è presente
                // nel vettore del numero che sto per provare come tentativo, se un valore del vettore dei numeri validi
                // non è presente nel numero finale, incrementa il valore bandiera che invaliderà la condizione del while
                // e quindi farà rifare il loop per generare un nuovo numero
                // L'unico problema è che venendo aggiunti spesso anche dei valori non validi per motivi sconosciuti
                // e a volte anche doppi, questo metodo si invalida, quindi l'ho commentato.
                //for (int i = 0; i < nValTrov; i++) {
                //    if (!valorePresenteInVet(nCifre, vetNValTrov[nValTrov], nProvatoPCVet)){
                //        tuttiValPres++;
                //    }
                //}
            }

            // Incremento il numero dei turni passati
            nTurno++;

            // Comunica il numero del turno
            printf("\n///////////////////////////// \n" +
                    "\nQuesto è il " + nTurno + "° turno...\n");

            // Messaggio che comunica output PC man mano mentre esegue la strategia
            printf("\nPC: ");

            // Per ogni cifra nel vettore esegue un ciclo
            for (int i = 0; i < nCifre; i++) {

                // Variabile doppia perchè nProvatoPCVet[i] tende a cambiare valore a caso
                int numeroDaAggiungere = nProvatoPCVet[i];

                // Sperimentale, nuova versione con funzione creata apposta
                if (!valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet) && !valorePresenteInVet(nNumeriSbagliati, numeroDaAggiungere , nProvatiPCSbagliati)){
                    // Aggiunge il numero all'insieme
                    nProvatiPCSbagliati[nNumeriSbagliati] = numeroDaAggiungere;
                    nNumeriSbagliati++;
                }

                // Se il valore è contenuto nel vettore del numero da indovinare della persona, supera la prima condizione
                // Se poi questo NON è contenuto nel vettore dei numeri validi, supera anche la seconda condizione
                // L'unico problema con questo, è che per qualche motivo mi aggiunge anche dei valori non validi, ignorando
                // Totalmente il primo if, e a volte anche il secondo mettendoli quindi doppi
                // Per questo l'ho commentato
                //if (valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet)){
                //    if (!valorePresenteInVet(nValTrov, numeroDaAggiungere, vetNValTrov)){
                //        vetNValTrov[nValTrov] = numeroDaAggiungere;
                //        nValTrov++;
                //    }
                //}

                // Strategia del computer
                // Verifica se il valore provato è uguale e nella stessa posizione, quindi quadrato in output di solito
                if (numeroDaAggiungere == nPersonaVet[i]){
                    // Setta a 1 il valore nel vettore per comunicare che in questa posizione il numero è corretto
                    // e nella posizione giusta, quindi non è da modificare in futuro
                    vetPCCorPos[i] = 1;
                    // Incrementa il numero delle cifre indovinate, se questo diventa uguale a nCifre allora il
                    // PC ha trovato il numero
                    cifreIndovinatePC++;
                    // Output
                    // printf(GREEN "[%d]" RESET, nPersonaVet[i]);
                } else if (valorePresenteInVet(nCifre, numeroDaAggiungere, nPersonaVet)){
                    // Carino a livello visivo anche se per ora inutile praticamente, questo verifica
                    // se il numero è almeno contenuto nel numero da indovinare, quindi il computer
                    // NON conosce la posizione, comunque mette un output visivo per dare pressione
                    // all'utente e comunque è parte del gioco.
                    // printf(YELLOW "(%d)" RESET, numeroDaAggiungere);
                    cifrePCNoPos++;
                }
            }

            for (int i = 0; i < cifreIndovinatePC; i++) {
                printf("[]");
            }

            for (int i = 0; i < cifrePCNoPos; i++) {
                printf("[]");
            }

            // Chiedo input all'utente per tentare di indovinare il numero
            printf("\n\nInserisci un numero: ");
            numeroProvatoPersona = getScanner().nextInt();
            singoloValVet(nCifre, numeroProvatoPersonaVet, numeroProvatoPersona);

            // Inizia verifica dei valori inseriti dall'utente
            printf("Persona: ");
            // Persona (uso il vecchio metodo di output che va bene)
            for (int i = 0; i < nCifre; i++) {
                for (int j = 0; j < nCifre; j++) {
                    if (mioVettore[i] == numeroProvatoPersonaVet[j] && i == j){
                        // printf(GREEN "[%d]" RESET, mioVettore[i]);
                        cifreIndovinatePersona++;
                    } else if (mioVettore[i] == numeroProvatoPersonaVet[j]){
                        // printf(YELLOW "(%d)" RESET, mioVettore[i]);
                        cifrePersonaNoPos++;
                    }
                }
            }

            for (int i = 0; i < cifreIndovinatePersona; i++) {
                printf("[]");
            }

            for (int i = 0; i < cifrePersonaNoPos; i++) {
                printf("()");
            }

            // Qualcuno ha vinto? Oppure hanno vinto entrambi?
            if (cifreIndovinatePC == cifreIndovinatePersona && cifreIndovinatePC == nCifre){
                printf("\n\nComplimenti! Te e il PC avete finito nello stesso turno! Pareggio!" +
                        "\nIl tuo numero era:" + nPersona +
                        "\nIl numero del PC era: " + numeroProvatoPersona);
                finito++;
            } else if (cifreIndovinatePC == nCifre){
                printf("\n\nHai perso! Ha vinto il computer!" +
                        "\nIl tuo numero era " + nPersona);
                finito++;
            } else if (cifreIndovinatePersona == nCifre){
                printf("\n\nHai vinto e battuto il computer! Il numero " + numeroProvatoPersona +  " è corretto!");
                finito++;
            }

            // Giusto a livello di interfaccia
            printf("\n");
        }

        printf("\n/////////////////////////////");

        // Messaggio di fine
        printf("\n\nFine del gioco...");

    }
}

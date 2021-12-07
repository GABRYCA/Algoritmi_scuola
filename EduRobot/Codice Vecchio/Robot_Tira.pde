/*----------------------------------------------------- 
Author:  --<Frova, Griffini>
Date: Fri Apr 23 15:49:17 2021
Description: Main code for Entry Level

-----------------------------------------------------*/
/*********TO DO*********
[ X ] Sistemare funzione Gira fino ad angolo
[ X ] Fixare errore compilazione riga 108 - 110                //Era un semplice errore di define e tonde
[ X ] Inizializzazione delle funzioni per evitare warnings
[ ] Cucchiaio / Approcciare la palla in direzione corretta
***********************/

#define SX_N    6   // (RB6)         //Sinistra Nero
#define SX_R    7  // (RB7)          //Sinistra Rosso
#define DX_N    4   // (RB4)         //Destra Nero
#define DX_R    5  // (RB5)          //Destra Rosso
#define PUSH    21  // (RD0) PULSANTE sulla Board        Default 1 quando premo va a 0
#define US_SX    A0   // (RA0) sensore US_DX
#define US_DX    A1  // (RA1) sensore US_SX
#define IR_FRONTALE    0  //RB0    Sensore IR centrale per presa palla
#define BUZZ 24

#define SOGLIA_US 150
#define lunghezzaDefault 15
#define angoloDefault 10
#define erroreAngoloMax 15

void m_gira_dx_ind(), m_gira_sx_ind(), m_ruota_sx(), m_ruota_dx(), m_gira_dx(), m_gira_sx(), m_indietro(), m_avanti(), m_fermo(), CMPS03(void), m_ruota_sx_soft(), m_ruota_dx_soft(), m_resetPWM();
void m_centrati(), lettura_schedaPalla(), lettura_bussola(), movimento_cercaPalla(), movimento_inseguiPalla(), giraFinoAngolo(int angolo), BEEP();
int lato_bussola(), lato_campo(), dist_dx(), dist_sx(), lato_palla(), palla_sotto(), calcola_angoloTiro();

char DIR = '0', DIST = '0', BUS='0', BUS_ZERO = '0', datoSeriale;
int dirCase = 0, velDefault = 600, velGiro = 350, velAvantiSoft = 450, velGiroSoft = 350, velCorriToro = 1000, senssx = -1, sensdx = -1;
int latoCampo = 0; //0 = Centro - 1 = Sinistra - 2 = Destra
int c_cieco = 0; //Contatore per quando non vede la palla
int rangeAngoloSX, rangeAngoloDX;
int bluetoothDimostrazione = -1;    //-1 : Disabilitato, 1 : Slave, 2 : Master
int indiceBUZZ = 0, maxBUZZ = 50;
int angoloDestinazione = 192;
int bluetoothPresa = 1;
int fatto = false;

void setup() {
    Serial.begin(9600);                       //Inizializzo la seriale
    pinMode(USERLED, OUTPUT);
    pinMode(SX_N, OUTPUT);            //Motore SX, NERO
    pinMode(SX_R, OUTPUT);            //Motore SX, ROSSO
    pinMode(DX_N, OUTPUT);            //Motore DX, NERO
    pinMode(DX_R, OUTPUT);            //Motore DX, ROSSO
    pinMode(PUSH, INPUT);               //Bottone BUILTIN    Ritorna digitale
    pinMode(US_DX,INPUT);              //Sensore Ultrasuoni Destro    Ritorna analogico (mm)
    pinMode(US_SX, INPUT);             //Sensore Ultrasuoni Sinistro    Ritorna analogico (mm)
    pinMode(IR_FRONTALE, INPUT);  //Sensore IR Frontale    Ritorna digitale (Vedo palla o no)
    pinMode(BUZZ, OUTPUT);
    
    digitalWrite(USERLED, 1);            //Spengo il led
    
    I2C.master(100);
    
    //Imposto i PWM
    PWM.setFrequency(3000);      //3KHz
    PWM.setDutyCycle(CCP1,velDefault); //DX
    PWM.setDutyCycle(CCP2,velDefault); //SX
    
    delay(200);
    CMPS03();        //Prima accensione bussola
    BUS_ZERO = BUS;
    delay(1000);
    
    digitalWrite(USERLED, 0);                 //Accendo il led per segnalare l'avvenuta configurazione iniziale
    
    while(digitalRead(PUSH) == 1) {}    //Attenndo accensione con il bottone PUSH built-in
    delay(500);
    BEEP();
    digitalWrite(USERLED, 1);                //Spengo il led
    Serial.println(".PARTITO");
}

void loop() {
    //Ciclo di gioco
    
    //lettura_bussola();
    
    if(fatto) movimento_inseguiPalla();

    /*    
    lettura_schedaPalla();
    if(DIST >= 2) {
        Serial.write('#');        //Palla presa. Mando messaggio via bluetooth
        vaiAPortaNemica();
    }
    
    delay(100);
    
    /***RICEZIONE PRESA BLUETOOTH***/
    
    /* if(Serial.available()){
        datoSeriale = Serial.read();
        if(datoSeriale == '#'){
            giraFinoAngolo(128);    //Mi raddrizzo verso la mia porta
            m_avanti();            //Torno indietro
            delay(1500);
            m_centrati();
            m_fermo();
        }
    }*/
    //Controllo per inversione dei ruoli
    
	/***Manovra passo e tiro***/
    
	//Controllo per il via del secondo robot
    if(Serial.read() == 'f'){ //Se ricevo la f tramite bluetooth posso iniziare a giocare
        fatto  = true;
    }
}
    
/*********FUNZIONI************/    
void CMPS03(void)    //Routine per CMPS03 Restituisce in BUS il valore
{
    I2C.stop();                     // per resettare
    I2C.start();                    // Initiate START condition on SDA and SCL pins. Automatically cleared by hardware.
    I2C.write(0xC0);	//Address for write
    I2C.write(0x01);
    I2C.stop();
    I2C.start();
    I2C.write(0xC1);
    BUS = I2C.read();
    I2C.sendNack();
    I2C.stop();
} //CMPS03

void giraFinoAngolo(int angolo){
    //PWM.setDutyCycle(CCP1,velGiro); //DX
    //PWM.setDutyCycle(CCP2,velGiro); //SX
    if(erroreAngoloMax >= angolo){
        rangeAngoloSX = abs(erroreAngoloMax - (255 - angolo));
    } else {
        rangeAngoloSX = angolo - erroreAngoloMax;
    }
    //Calcolo margine sinistro massimo
    if(angolo + erroreAngoloMax < 255){
        rangeAngoloDX = angolo + erroreAngoloMax;
    } else {
        rangeAngoloDX = abs(erroreAngoloMax - (255 - angolo));
    }
    lettura_bussola();
    while((BUS > rangeAngoloSX && BUS < rangeAngoloDX) == false){    //Finchè non sono nel range considerato angolo, mi ruoto
        m_fermo();
        lettura_bussola();
        if(BUS > angolo){  //Angolo si trova alla mia destra
            m_ruota_sx();
            delay(3);
            m_fermo();
            lettura_bussola();
            if(BUS > rangeAngoloSX && BUS < rangeAngoloDX) break;
        } else if(BUS < angolo){
            m_ruota_dx();
            delay(3);
            m_fermo();
            lettura_bussola();
            if(BUS > rangeAngoloSX && BUS < rangeAngoloDX) break;
        }
        m_fermo();
    }
    m_resetPWM();
    //PWM.setDutyCycle(CCP1,velDefault); //DX
    //PWM.setDutyCycle(CCP2,velDefault); //SX
}

void vaiAPortaNemica(int angolo){
    angolo = 0;    //Imposto come angolo da raggiungere la porta. SE NON VA METTI calcola_angoloTiro
    rangeAngoloSX = 240;
    rangeAngoloDX = 15;
    lettura_bussola();
    while((BUS > rangeAngoloSX && BUS < rangeAngoloDX) == false){    //Finchè non sono nel range considerato angolo, mi ruoto
        lettura_bussola();
        if(lato_palla() != 1) break;
        if(BUS > angolo){  //Angolo si trova alla mia destra
            m_ruota_sx_soft();
            lettura_bussola();
            if(BUS > rangeAngoloSX && BUS < rangeAngoloDX) break;
        } else if(BUS < angolo){
            m_ruota_dx_soft();
            lettura_bussola();
            if(BUS > rangeAngoloSX && BUS < rangeAngoloDX) break;
        }
    }
}

int calcola_angoloTiro(){
    //Calcolo dell'angolo da utilizzare per puntare sempre la porta
    if(lato_campo() == 0){        //Centro
        return 0;
    } else if (lato_campo() == 1){    //Sinistra
        return lunghezzaDefault * dist_sx() / angoloDefault;
    } else if(lato_campo() == 2){    //Destra
        return (255 - (lunghezzaDefault * dist_dx() / angoloDefault));
    }
}

int palla_sotto(){
    /*
    if(digitalRead(IR_FRONTALE)) return 1;    //Ho la palla
    else return 0;    //Non ho la palla
    */
    return 1;
}

void movimento_inseguiPalla(){
     switch (lato_palla()){
         case 1:    //Avanti
             m_avanti();
             //Serial.write('1');
             break;
         case 2: //Destra
             m_ruota_dx();
             //delay(150);
             //Serial.write('2');
             break;
         case 3:    //Sinistra
             m_ruota_sx();
             //delay(150);
             //Serial.write('3');
             break;
         case 4:    //Dietro destra
             m_indietro();
             //m_gira_sx_ind();
             //Serial.write('4');
             break;
         case 5:  //Dietro sinistra
             m_indietro();
             //m_gira_dx_ind();     
             //Serial.write('5');
             break;
         case 6:    //Dietro
             m_gira_sx_ind();
             //m_indietro();
             break;
             //Serial.write('6');
         case 7:    //Non vedo la palla
             //movimento_cercaPalla();
             m_fermo();
             break;
         default:
             m_fermo();
             //Serial.write('7');
             break;
     }
}

void movimento_cercaPalla(){
    /*****FUNZIONE DI RICERCA DELLA PALLA*****/
    //Ariete, giro pazzo, centramento, indietro
    while(lato_palla() == 7){
        if(c_cieco <= 4){
            m_avanti();
            delay(50);
            c_cieco++;
            m_fermo();
        } else if (c_cieco >= 5 && c_cieco <= 8){
            //PWM.setDutyCycle(CCP1, velGiro);
            //PWM.setDutyCycle(CCP2, velGiro);
            m_ruota_sx();
            delay(50);
            //PWM.setDutyCycle(CCP1, velDefault);
            //PWM.setDutyCycle(CCP2, velDefault);
            m_resetPWM();
            m_fermo();
            c_cieco++;
        } else if(c_cieco == 9) {
             while(lato_bussola() != 0) {
            m_centrati();
            delay(150);
            }      
            m_fermo();
            c_cieco++;
        } else if(c_cieco >= 10 && c_cieco <= 12){
            m_indietro();
            delay(50);
            c_cieco++;
            m_fermo();
        } else if(c_cieco == 13){
            c_cieco = 0;
        }
    }
}

int lato_palla(){
     /**********GESTIONE DIREZIONE PALLA (Dati scheda Palla)*************/
     lettura_schedaPalla();
     if(DIR >= 3 && DIR <= 7) return 1;                            //Palla Avanti
     else if(DIR >= 8 && DIR <=10) return 2;                    //Palla a Destra
     else if(DIR == 1 || DIR == 2 || DIR == 16) return 3;  //Palla Sinistra
     else if(DIR == 11) return 4;    //Dietro destra
     else if(DIR == 14) return 5;    //Dietro sinistra
     else if(DIR == 12 || DIR == 13) return 6;                 //Palla Dietro
     else return 7;    //Non vedo la palla
}

void lettura_bussola(){
    /***********LETTURA BUSSOLA*****************/
    CMPS03();    //Lettura bussola
    
    //Correzzione direzione bussola in base al BUS_ZERO
    if(BUS > BUS_ZERO) BUS = BUS-BUS_ZERO;
    else BUS = 255 - (BUS_ZERO-BUS);
}

void lettura_schedaPalla(){
      /***********Lettura Scheda Palla*************/
      I2C.stop();
      I2C.start();
      I2C.write(0x25);
      DIR = I2C.read();    //Salvo il led acceso più rilevante
      I2C.sendAck();
      DIST = I2C.read();  //Salvo la distanza relativa al numero di sensori accesi
      I2C.sendNack();
      I2C.stop();
}

int dist_sx(){
    return analogRead(US_SX);    //Restituisce distanza sensore sinistro in millimetri
}

int dist_dx(){
    return analogRead(US_DX);    //Restituisce distanza sensore destro in millimetri
}

int lato_campo(){
    /************LETTURA SENSORI ULTRASUONI*************/
    sensdx=dist_dx();    //Lettura analogica del valore in mm della distanza sonda-echo del sensore ad ultrasuoni MB1200
    senssx=dist_sx();
    
    /****RILEVAZIONE ZONA DEL CAMPO IN BASE A DISTANZE*****/
    if(abs(sensdx-senssx)<SOGLIA_US){
        //Serial.write('0');
        return 0;
    }    //I sensori hanno la somma assoulta a 0 o +- valore di soglia.  Il robot è centrato
    else if(sensdx>senssx)  {
        //Serial.write('1');
        return 1;
    }    //Il sensore di destra ha un valore maggiore di distanza, quindi siamo a sinistra
    else{
        //Serial.write('2');
        return 2; 
    }    //Il sensore di sinistra ha un valore maggiore di distanza, quindi siamo a destra

}

int lato_bussola(){
    //Rilevazione della zona della bussola. NB La bussola incrementa il valore in senso antiorario, iniziando da 0 fino a 255
    //0 = Avanti, 1 = Alto Sinistra, 2 = Sotto Sinistra, 3 = Sotto Destra, 4 = Alto Destra
    
    lettura_bussola();    //Chiamo la lettura della bussola
    if((BUS >= 0 && BUS <= 15) || (BUS >= 235 && BUS <= 255)) return 0;    //Avanti
    else if(BUS >= 11 && BUS <= 64) return 1;           //Alto Sinistra
    else if(BUS >= 65 && BUS <= 128) return 2;         //Sotto Sinistra
    else if(BUS >= 129 && BUS <= 192) return 3;       //Sotto Destra
    else if(BUS >= 193 && BUS <= 244) return 4;       //Alto Destra
}

void m_centrati(){
    //Funzione che gira fino ad essere centrato
    //Da valutare se salvare il valore in variabile senza ricalcolare, potrebbe incidentare nel mentre
    while(1){
        //PWM.setDutyCycle(CCP1,velGiro); //DX
        //PWM.setDutyCycle(CCP2,velGiro); //SX
        if(lato_bussola() == 0) {
            //PWM.setDutyCycle(CCP1,velDefault); //DX
            //PWM.setDutyCycle(CCP2,velDefault); //SX
            m_resetPWM();
            m_fermo();
            return;    //Mi sono centrato
        }
        else if(lato_bussola() == 1 || lato_bussola() == 2){
                m_gira_sx();       //Giro a sinistra
                delay(5);
                m_fermo();
        }
        else if(lato_bussola() == 3 || lato_bussola() == 4) {
                m_gira_dx();       //Giro a sinistra
                delay(5);
                m_fermo();
        }
    }
}

void BEEP(){
        while(indiceBUZZ < maxBUZZ){
            indiceBUZZ++;
            digitalWrite(BUZZ, HIGH);
            delay(1);
            digitalWrite(BUZZ, LOW);
        }
        indiceBUZZ = 0;
}

/******FUNZIONI MOVIMENTO BASE*****/
void m_fermo()
{        
    PWM.setDutyCycle(CCP1, velDefault); //DX
    PWM.setDutyCycle(CCP2,velDefault); //SX                               
    digitalWrite(SX_N, LOW);
    digitalWrite(SX_R, LOW);
    digitalWrite(DX_N, LOW);
    digitalWrite(DX_R, LOW);
}

void m_avanti()
{
    PWM.setDutyCycle(CCP1, velDefault); //DX
    PWM.setDutyCycle(CCP2, velDefault); //SX
    digitalWrite(SX_N, LOW);
    digitalWrite(SX_R, HIGH);
    digitalWrite(DX_N, LOW);
    digitalWrite(DX_R, HIGH);
}

 void m_indietro()
{
    PWM.setDutyCycle(CCP1, velDefault); //DX
    PWM.setDutyCycle(CCP2,velDefault); //SX
    digitalWrite(SX_N, HIGH);
    digitalWrite(SX_R, LOW);
    digitalWrite(DX_N, HIGH);
    digitalWrite(DX_R, LOW);
}

 void m_gira_sx()
 {
    PWM.setDutyCycle(CCP1, velDefault); //DX
    PWM.setDutyCycle(CCP2,velDefault); //SX
    digitalWrite(SX_N, LOW);
    digitalWrite(SX_R, LOW);
    digitalWrite(DX_N, LOW);
    digitalWrite(DX_R, HIGH);
 }
 
  void m_gira_dx()
  {
     PWM.setDutyCycle(CCP1, velGiro); //DX
    PWM.setDutyCycle(CCP2,velGiro); //SX
    digitalWrite(SX_N, LOW);
    digitalWrite(SX_R, HIGH);
    digitalWrite(DX_N, LOW);
    digitalWrite(DX_R, LOW);
 }
 

 void m_ruota_dx()
{
    PWM.setDutyCycle(CCP1, velGiro); //DX
    PWM.setDutyCycle(CCP2,velGiro); //SX
    digitalWrite(SX_N, LOW);
    digitalWrite(SX_R, HIGH);
    digitalWrite(DX_N, HIGH);
    digitalWrite(DX_R, LOW);
}

 void m_ruota_sx()
{
    PWM.setDutyCycle(CCP1, velGiro); //DX
    PWM.setDutyCycle(CCP2,velGiro); //SX
    digitalWrite(SX_N, HIGH);
    digitalWrite(SX_R, LOW);
    digitalWrite(DX_N, LOW);
    digitalWrite(DX_R, HIGH);
}

 void m_gira_sx_ind()
{
    PWM.setDutyCycle(CCP1, velGiro); //DX
    PWM.setDutyCycle(CCP2,velGiro); //SX
    digitalWrite(SX_N, LOW);
    digitalWrite(SX_R, HIGH);
    digitalWrite(DX_N, LOW);
    digitalWrite(DX_R, LOW);
}

void m_gira_dx_ind()
{
    PWM.setDutyCycle(CCP1, velGiro); //DX
    PWM.setDutyCycle(CCP2,velGiro); //SX
    digitalWrite(SX_N, LOW);
    digitalWrite(SX_R, LOW);
    digitalWrite(DX_N, LOW);
    digitalWrite(DX_R, HIGH);
}

void m_ruota_sx_soft()
{
    PWM.setDutyCycle(CCP1, velGiroSoft); //DX
    PWM.setDutyCycle(CCP2,velAvantiSoft); //SX
    digitalWrite(SX_N, LOW);
    digitalWrite(SX_R, HIGH);
    digitalWrite(DX_N, LOW);
    digitalWrite(DX_R, HIGH);
}

void m_ruota_dx_soft()
{
    PWM.setDutyCycle(CCP1, velAvantiSoft); //DX
    PWM.setDutyCycle(CCP2,velGiroSoft); //SX
    digitalWrite(SX_N, LOW);
    digitalWrite(SX_R, HIGH);
    digitalWrite(DX_N, LOW);
    digitalWrite(DX_R, HIGH);
}

void m_resetPWM()
{
    PWM.setDutyCycle(CCP1, velDefault); //DX
    PWM.setDutyCycle(CCP2,velDefault); //SX
}
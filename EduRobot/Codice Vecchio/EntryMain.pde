#include <Arduino.h>

#define SX_N    6   // (RB6)         //Sinistra Nero
#define SX_R    7  // (RB7)          //Sinistra Rosso
#define DX_N    4   // (RB4)         //Destra Nero
#define DX_R    5  // (RB5)          //Destra Rosso
#define PUSH    21  // (RD0) PULSANTE sulla Board        Default 1 quando premo va a 0
#define US_SX    A0   // (RA0) sensore US_DX
#define US_DX    A1  // (RA1) sensore US_SX
#define IR_FRONTALE    0  //RB0    Sensore IR centrale per presa palla
#define BUZZ 24
#define SELETTORE1 18    //RE0
#define SELETTORE2 19    //RE1

#define SOGLIA_US 150
#define lunghezzaDefault 15
#define angoloDefault 10
#define erroreAngoloMax 15
#define tempoCiclo 400

void m_gira_dx_ind(), m_gira_sx_ind(), m_ruota_sx(), m_ruota_dx(), m_gira_dx(), m_gira_sx(), m_indietro(), m_avanti(), m_fermo(), CMPS03(void), m_ruota_sx_soft(), m_ruota_dx_soft(), m_resetPWM();
void BEEP();

int velDefault = 600;
char DIR = '0', DIST = '0', BUS='0', BUS_ZERO = '0', datoSeriale;
//int dirCase = 0, velDefault = 900, velGiro = 350, velAvantiSoft = 650, velGiroSoft = 500, velCorriToro = 1000, senssx = -1, sensdx = -1;
int dirCase = 0, velDefault = 600, velGiro = 350, velAvantiSoft = 450, velGiroSoft = 350, velCorriToro = 1000, senssx = -1, sensdx = -1;
int latoCampo = 0; //0 = Centro - 1 = Sinistra - 2 = Destra
int c_cieco = 0; //Contatore per quando non vede la palla
int rangeAngoloSX, rangeAngoloDX;
int bluetoothDimostrazione = -1;    //-1 : Disabilitato, 1 : Slave, 2 : Master
int indiceBUZZ = 0, maxBUZZ = 50;
int angoloDestinazione = 192;
int bluetoothPresa = 1;
int offsetGiroGiro = 30;
int ciclo = 0;
int emergenza = false;
char letturaSelettore1, letturaSelettore2;
//CH_SPINTA/TIRA
int fatto = false;

void setup() {
  //Imposto i PWM
    PWM.setFrequency(1000); 
}

void loop() {
      m_avanti();
}

/******FUNZIONI MOVIMENTO BASE*****/
void m_fermo()
{        
    PWM.setDutyCycle(CCP1, velDefault); //DX
    PWM.setDutyCycle(CCP2, velDefault); //SX                               
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
    delay(5000);
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
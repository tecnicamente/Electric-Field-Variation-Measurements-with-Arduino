#include <Arduino.h>
/* 18/04/2014

 prima stesura della funzione che permette di visualizzare a display la scala da 0-9 e il lampeggio DP

 in fase di accensione


 18/04/2014

 aggiunta la lettura dei valori dall'antenna



 25/04/2014

 Codice organizzato in modo modulare e testato con code::blocks 12.11 per arduino



 18/07/2014

 aggiunti tutti i canali di ingresso per il campionamento da A0 a A5

 modificato collegamento antenna che ora � diretta sull'ingresso analogico

 19/07/2014
 aggiunta stampa della versione del software
 
 25/10/2014
 risolti alcuni bug
 aggiornata la versione a 4
 inserite possibilità di settaggio dei parametri di campionamento
 */

//#include <Arduino.h> /* Necessario se usate code::blocks come ambiente di sviluppo, diversamente rimuvere */

#include "ld7.h"
/* definizione PIN antenna
 \/

 |

 |

 +--a0

 */

#define VERSIONE  4.00-25/10/2014
#define analogIn    A0
//#define FQ          1/((1/50)/2) /* frequenza di campionamento pari al doppio della frequenza che mi interessa (50 Hz) */
#define C           0.0048828125


int flag = 0;

void setup(){
    
  /*attivo la comunicazione seriale */
    Serial.begin(57600);
    Serial.print("EMF DETECTOR V. ");
    Serial.println(VERSIONE);
   
    

  
  /* definizione PIN display 7 segmenti */
    LD_setPinDisplay(1,2);
    LD_setPinDisplay(2,3);
    LD_setPinDisplay(4,4);
    LD_setPinDisplay(5,5);
    LD_setPinDisplay(6,6);
    LD_setPinDisplay(7,7);
    LD_setPinDisplay(9,8);
    LD_setPinDisplay(10,9);

  /*configurazione dei PIN */
    LD_setArduinoOutDisplay();

  /* setto tutti i pin LOW affinche siano spenti */
    LD_resetDisplay();
}


void test(void){
  /* ciclo di test solo per verificare che i numeri siano rappresentati correttamente */
  for(int i=0;i<11;i++){
    LD_writeDisplay(i);
    delay(2000);
  }
}

int segnaleAntenna(void){
  return analogRead(analogIn);
}



void loop(void){
  unsigned long t;
  
  
  int valore;
 
  /* test */ 
  if (flag ==0){
   test();
    LD_resetDisplay();
    flag=1;
  }
  

  t = millis();
  /* con t%10 campiono 100 volte al secondo, quindi a 100 Hz
     con t%5  campiono 200 volte al secondo, quindi a 200 Hz
  */

  if(t%20 ==0){
  //  if (t%60000 == 0){
  //  delay(1);
  /* refuso, si potrebbe cancellare 
    valore = segnaleAntenna();
    Serial.print(t);
    Serial.print(" ");
    Serial.print(valore * C);
    Serial.print(" ");
  */
    Serial.print(t);
    Serial.print("\t");
    
    Serial.print(analogRead(A0) * C);
    Serial.print("\t");

    Serial.print(analogRead(A1) * C);
    Serial.print("\t");

    Serial.print(analogRead(A2) * C);
    Serial.print("\t");

    Serial.print(analogRead(A3) * C);
    Serial.print("\t");

    Serial.print(analogRead(A4) * C);
    Serial.print("\t");

    Serial.println(analogRead(A5) * C);
  }

  if(t%1000 == 0){
    valore = map(valore,0,100,0,10);
    LD_writeDisplay(valore);
    //delay(1);
  }
}

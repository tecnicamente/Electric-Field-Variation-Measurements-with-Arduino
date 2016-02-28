

/* ld7.h v1.0

    La funzione

    void writeDiplay(int) permette di rapresentare i seguenti numeri e simboli sul display:

    0 --> 0

    1 --> 1

    2 --> 2

    3 --> 3

    4 --> 4

    5 --> 5

    6 --> 6

    7 --> 7

    8 --> 8

    9 --> 9

   10 --> 1.



   Se in ingresso è fornito un valore <0 il dato visualizzato è 0, se è fornito

   un valore >10 il dato vizualizzato è "1.".

*/



/* definizione dei pin di collegamento */

/* Il progetto usa un display a 7 segmenti con il seguente pinout:



        +------------+

    1---|            |---10

        |    a       |

    2---|  +---+     |---9

        | f| g |b    |

    3---|  +---+     |---8

        | e| d |c  DP|

    4---|  +---+  *  |---7

        |            |

    5---|            |---6

        +------------+



        1   g

        2   f

        3   A(C)

        4   e

        5   d

        6   DP

        7   c

        8   A(C)

        9   b

        10  a

    con la funzione  void setPinDisplay(int pinDisplay, int pinArduino)

    è possibile abbinare i pin tra arduino e diplay

*/



/* definisco ON e OFF per rendere più facile la lettura dello stato led */

#define ON LOW

#define OFF HIGH



static unsigned short int LedPin1;

static unsigned short int LedPin2;

static unsigned short int LedPin3;

static unsigned short int LedPin4;

static unsigned short int LedPin5;

static unsigned short int LedPin6;

static unsigned short int LedPin7;

static unsigned short int LedPin8;

static unsigned short int LedPin9;

static unsigned short int LedPin10;



/* funzione per l'abbinamento tra i PIN del display ed Arduino */

void LD_setPinDisplay(int pinDisplay, int pinArduino){

    if (pinDisplay == 1)    LedPin1 = pinArduino;

    if (pinDisplay == 2)    LedPin2 = pinArduino;

    if (pinDisplay == 3)    LedPin3 = pinArduino;

    if (pinDisplay == 4)    LedPin4 = pinArduino;

    if (pinDisplay == 5)    LedPin5 = pinArduino;

    if (pinDisplay == 6)    LedPin6 = pinArduino;

    if (pinDisplay == 7)    LedPin7 = pinArduino;

    if (pinDisplay == 8)    LedPin8 = pinArduino;

    if (pinDisplay == 9)    LedPin9 = pinArduino;

    if (pinDisplay == 10)   LedPin10 = pinArduino;

}



/* funzione  di visualizzazione*/

void LD_writeDisplay(int numero){



  if (numero == 0){

    digitalWrite(LedPin1,OFF);

    digitalWrite(LedPin2,ON);

    digitalWrite(LedPin4,ON);

    digitalWrite(LedPin5,ON);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,ON);

    digitalWrite(LedPin9,ON);

    digitalWrite(LedPin10,ON);

  }

  if (numero == 1){

    digitalWrite(LedPin1,OFF);

    digitalWrite(LedPin2,OFF);

    digitalWrite(LedPin4,OFF);

    digitalWrite(LedPin5,OFF);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,ON);

    digitalWrite(LedPin9,ON);

    digitalWrite(LedPin10,OFF);

  }

  if (numero == 2){

    digitalWrite(LedPin1,ON);

    digitalWrite(LedPin2,OFF);

    digitalWrite(LedPin4,ON);

    digitalWrite(LedPin5,ON);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,OFF);

    digitalWrite(LedPin9,ON);

    digitalWrite(LedPin10,ON);

  }

  if (numero == 3){

    digitalWrite(LedPin1,ON);

    digitalWrite(LedPin2,OFF);

    digitalWrite(LedPin4,OFF);

    digitalWrite(LedPin5,ON);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,ON);

    digitalWrite(LedPin9,ON);

    digitalWrite(LedPin10,ON);

  }

  if (numero == 4){

    digitalWrite(LedPin1,ON);

    digitalWrite(LedPin2,ON);

    digitalWrite(LedPin4,OFF);

    digitalWrite(LedPin5,OFF);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,ON);

    digitalWrite(LedPin9,ON);

    digitalWrite(LedPin10,OFF);

  }

  if(numero == 5){

    digitalWrite(LedPin1,ON);

    digitalWrite(LedPin2,ON);

    digitalWrite(LedPin4,OFF);

    digitalWrite(LedPin5,ON);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,ON);

    digitalWrite(LedPin9,OFF);

    digitalWrite(LedPin10,ON);

  }

  if(numero == 6){

    digitalWrite(LedPin1,ON);

    digitalWrite(LedPin2,ON);

    digitalWrite(LedPin4,ON);

    digitalWrite(LedPin5,ON);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,ON);

    digitalWrite(LedPin9,OFF);

    digitalWrite(LedPin10,ON);

  }

  if(numero == 7){

    digitalWrite(LedPin1,OFF);

    digitalWrite(LedPin2,OFF);

    digitalWrite(LedPin4,OFF);

    digitalWrite(LedPin5,OFF);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,ON);

    digitalWrite(LedPin9,ON);

    digitalWrite(LedPin10,ON);

  }

  if(numero == 8){

    digitalWrite(LedPin1,ON);

    digitalWrite(LedPin2,ON);

    digitalWrite(LedPin4,ON);

    digitalWrite(LedPin5,ON);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,ON);

    digitalWrite(LedPin9,ON);

    digitalWrite(LedPin10,ON);

  }

  if(numero ==9){

    digitalWrite(LedPin1,ON);

    digitalWrite(LedPin2,ON);

    digitalWrite(LedPin4,OFF);

    digitalWrite(LedPin5,OFF);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,ON);

    digitalWrite(LedPin9,ON);

    digitalWrite(LedPin10,ON);

  }

  if (numero == 10){

    digitalWrite(LedPin1,OFF);

    digitalWrite(LedPin2,OFF);

    digitalWrite(LedPin4,OFF);

    digitalWrite(LedPin5,OFF);

    digitalWrite(LedPin6,ON);

    digitalWrite(LedPin7,ON);

    digitalWrite(LedPin9,ON);

    digitalWrite(LedPin10,OFF);

  }

}



/* funzione per lo spegnimento del display */

void LD_resetDisplay(void){

    digitalWrite(LedPin1,OFF);

    digitalWrite(LedPin2,OFF);

    digitalWrite(LedPin4,OFF);

    digitalWrite(LedPin5,OFF);

    digitalWrite(LedPin6,OFF);

    digitalWrite(LedPin7,OFF);

    digitalWrite(LedPin9,OFF);

    digitalWrite(LedPin10,OFF);

}



/* funzione per settare conficurare i PIN di Arduino in funzione dei PIN del display */

void LD_setArduinoOutDisplay(void){

    pinMode(LedPin1,OUTPUT);

    pinMode(LedPin2,OUTPUT);

    pinMode(LedPin4,OUTPUT);

    pinMode(LedPin5,OUTPUT);

    pinMode(LedPin6,OUTPUT);

    pinMode(LedPin7,OUTPUT);

    pinMode(LedPin9,OUTPUT);

    pinMode(LedPin10,OUTPUT);

}

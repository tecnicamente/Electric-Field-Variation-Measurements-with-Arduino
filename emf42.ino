void setup(){
 /*attivo la comunicazione seriale */
 Serial.begin(57600);

}


float segnaleAntenna(void){
 /* definisco la sensibilità minima della conversione A/D */
 //const double c = 0.0048875855;
 return analogRead(A0)*0.0048875855;
}

void loop(void){
 unsigned long t;
 float valore;
 float valore5;

 //resetDisplay();
 t = millis();
 if(t%60000 ==0){
 valore = segnaleAntenna();
 valore5= analogRead(A5)*0.0048875855;
 
 Serial.print(valore,8);
 Serial.print("\t");
 Serial.print(valore5,8);
 Serial.println(" ");
 //delay(1);
 }
 
}

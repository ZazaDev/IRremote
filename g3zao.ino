#include <IRremote.h>
int RECV_PIN = 11;
float armazenavalor;
int pinoledvermelho = 5;
int pinoledverde = 6;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  pinMode(pinoledvermelho, OUTPUT);
  pinMode(pinoledverde, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); //Inicializa o receptor IR
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Valor lido: ");
    Serial.println(results.value, HEX);
    armazenavalor = (results.value);
  }
  if(results.value == 0xAF5E817 || results.value == 0xFF02FD){ //Botao OFF ou OK
    digitalWrite(pinoledvermelho, LOW);
    digitalWrite(pinoledverde, LOW);
  }
  if(results.value == 0xAF548B7 || results.value == 0xFF6897){ //Botao +Volume ou 1
    digitalWrite(pinoledvermelho, HIGH); 
  }
  if(results.value == 0xAF5A857 || results.value == 0xFF9867){ //Botao -Volume ou 2
    digitalWrite(pinoledvermelho, LOW);
  }
  if(results.value == 0xAF59867 || results.value == 0xFFB04F){ //Botao +Canal ou 3
    digitalWrite(pinoledverde, HIGH);
  }
  if(results.value == 0xAF518E7 || results.value == 0xFF30CF){ //Botao -Canal ou 4
    digitalWrite(pinoledverde, LOW);
  }
  irrecv.resume(); //Le o próximo valor
}

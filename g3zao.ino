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
  if(results.value == 0xAF5E817){ //Botao OFF
    digitalWrite(pinoledvermelho, LOW);
    digitalWrite(pinoledverde, LOW);
  }
  if(results.value == 0xAF548B7){ //Botao +Volume
    digitalWrite(pinoledvermelho, HIGH);
  }
  if(results.value == 0xAF5A857){
    digitalWrite(pinoledvermelho, LOW); //Botao -Volume
  }
  if(results.value == 0xAF59867){
    digitalWrite(pinoledverde, HIGH); //Botao +Canal
  }
  if(results.value == 0xAF518E7){
    digitalWrite(pinoledverde, LOW); //Botao -Canal
  }
  irrecv.resume(); //Le o próximo valor
}

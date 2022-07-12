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
    Serial.println("Botao OFF");
    digitalWrite(pinoledvermelho, LOW);
    digitalWrite(pinoledverde, LOW);
  }
  if(results.value == 0xAF548B7){ //Botao +Volume
    Serial.println("Botao +Volume");
    digitalWrite(pinoledvermelho, HIGH); 
  }
  if(results.value == 0xAF5A857){ //Botao -Volume
    Serial.println("Botao -Volume");
    digitalWrite(pinoledvermelho, LOW);
  }
  if(results.value == 0xAF59867){ //Botao +Canal
    Serial.println("Botao +Canal");
    digitalWrite(pinoledverde, HIGH);
  }
  if(results.value == 0xAF518E7){ //Botao -Canal
    Serial.println("Botao -Canal");
    digitalWrite(pinoledverde, LOW);
  }
  if(results.value == 0xFFFFFFF){ //Erro decode
    Serial.println("Falha ao decodificar");
  }
  irrecv.resume(); //Le o próximo valor
}

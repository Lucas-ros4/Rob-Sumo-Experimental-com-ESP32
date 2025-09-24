#include "BluetoothSerial.h"
#include <Wire.h>

BluetoothSerial SerialBT;

#define IN1 19  
#define IN2 21

#define IN3 22
#define IN4 23



void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  SerialBT.begin("Esp32_sumoV2");  //nome que vai aparecer no bluetooth
  Serial.begin(115200);

}

void loop() {
  if(SerialBT.available()){   //
    char comando = SerialBT.read();
    if(comando == '\n' || comando == '\r') return;  //ignora os comandos \n, \r

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);


    if (comando == 'F') {       // frente  
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
    }
    else if (comando == 'B') {  // tras
      digitalWrite(IN1, HIGH);
      digitalWrite(IN4,HIGH);
    }
    else if (comando == 'L') {  // esquerda  
      digitalWrite(IN1, HIGH);
      digitalWrite(IN3, HIGH);
    }
    else if (comando == 'R') {  // direita

      digitalWrite(IN2, HIGH);
      digitalWrite(IN4, HIGH);
    }
  }
}


    

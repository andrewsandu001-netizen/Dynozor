/*
Test de la commande Ping : vérifie si le servomoteur d'ID correspondant sur le bus est prêt ; la commande de diffusion ne s'applique que si un seul servomoteur est présent sur le bus.
*/

#include <SCServo.h>

SCSCL sc;

int LEDpin = 13;
void setup()
{
  pinMode(LEDpin,OUTPUT);
  digitalWrite(LEDpin, HIGH);
  Serial.begin(115200);
  Serial1.begin(1000000);
  sc.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  int ID = sc.Ping(1);
  if(!sc.getLastError()){
    digitalWrite(LEDpin, LOW);
    Serial.print("Servo ID:");
    Serial.println(ID, DEC);
    delay(100);
  }else{
    Serial.println("Ping servo ID error!");
    digitalWrite(LEDpin, HIGH);
    delay(2000);
  }
}

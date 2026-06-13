/*
Test de la commande Ping : vérifie si le servomoteur d'ID correspondant sur le bus est prêt ; la commande de diffusion ne s'applique que si un seul servomoteur est présent sur le bus.
*/

#include <SCServo.h>

HLSCL hlscl;

int LEDpin = 13;
void setup()
{
  pinMode(LEDpin,OUTPUT);
  digitalWrite(LEDpin, HIGH);
  Serial.begin(115200);
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  int ID = hlscl.Ping(1);
  if(!hlscl.getLastError()){
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

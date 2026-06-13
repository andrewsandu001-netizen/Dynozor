#include <SCServo.h>

HLSCL hlscl;

void setup()
{
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  delay(1000);
  hlscl.WheelMode(1);//servomoteur ID1 basculé en mode vitesse moteur constante
}

void loop()
{
  //Les servomoteurs (ID1/ID2) accélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse max V=60*0.732=43.92rpm, maintiennent une rotation avant à vitesse constante, avec un courant de couple max T=500*6.5=3250mA
  hlscl.WriteSpe(1, 60, 50, 500);
  delay(5000);
  
  //Les servomoteurs (ID1/ID2) décélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse 0 et arrêtent la rotation
  hlscl.WriteSpe(1, 0, 50, 500);
  delay(2000);
  
  //Les servomoteurs (ID1/ID2) accélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse max V=-60*0.732=-43.92rpm, maintiennent une rotation inverse à vitesse constante, avec un courant de couple max T=500*6.5=3250mA
  hlscl.WriteSpe(1, -60, 50, 500);
  delay(5000);
  
  //Les servomoteurs (ID1/ID2) décélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse 0 et arrêtent la rotation
  hlscl.WriteSpe(1, 0, 50, 500);
  delay(2000);
}

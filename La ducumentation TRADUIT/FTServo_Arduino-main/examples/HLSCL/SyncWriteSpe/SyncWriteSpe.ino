#include <SCServo.h>
HLSCL hlscl;

byte ID[2];
s16 Speed[2];
byte ACC[2];
u16 Torque[2];

void setup()
{
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  delay(1000);
  hlscl.WheelMode(1);//servomoteur ID1 basculé en mode vitesse constante
  hlscl.WheelMode(2);//servomoteur ID2 basculé en mode vitesse constante
  ID[0] = 1;//servomoteur ID1
  ID[1] = 2;//servomoteur ID2
  ACC[0] = 50;//accélération A=50*8.7deg/s^2
  ACC[1] = 50;//accélération A=50*8.7deg/s^2
  Torque[0] = 500;//courant de couple max T=500*6.5=3250mA
  Torque[1] = 500;//courant de couple max T=500*6.5=3250mA
}

void loop()
{
  //Les servomoteurs (ID1/ID2) accélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse max V=60*0.732=43.92rpm, puis maintiennent une vitesse constante, avec un courant de couple max T=500*6.5=3250mA
  Speed[0] = 60;
  Speed[1] = 60;
  hlscl.SyncWriteSpe(ID, 2, Speed, ACC, Torque);
  delay(5000);

  //Les servomoteurs (ID1/ID2) décélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse 0 et s'arrêtent
  Speed[0] = 0;
  Speed[1] = 0;
  hlscl.SyncWriteSpe(ID, 2, Speed, ACC, Torque);
  delay(2000);
  
  //Les servomoteurs (ID1/ID2) accélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse max V=-60*0.732=-43.92rpm, puis maintiennent une vitesse constante, avec un courant de couple max T=500*6.5=3250mA
  Speed[0] = -60;
  Speed[1] = -60;
  hlscl.SyncWriteSpe(ID, 2, Speed, ACC, Torque);
  delay(5000);

  //Les servomoteurs (ID1/ID2) décélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse 0 et s'arrêtent
  Speed[0] = 0;
  Speed[1] = 0;
  hlscl.SyncWriteSpe(ID, 2, Speed, ACC, Torque);
  delay(2000);
}

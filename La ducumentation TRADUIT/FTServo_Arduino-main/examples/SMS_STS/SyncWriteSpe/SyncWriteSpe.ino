#include <SCServo.h>
SMS_STS sms_sts;

byte ID[2];
s16 Speed[2];
byte ACC[2];

void setup()
{
  //Serial1.begin(115200);//débit en bauds du servomoteur sms_stss : 115200
  Serial1.begin(1000000);//débit en bauds du servomoteur STS : 1000000
  sms_sts.pSerial = &Serial1;
  delay(1000);
  sms_sts.WheelMode(1);//servomoteur ID1 basculé en mode vitesse constante
  sms_sts.WheelMode(2);//servomoteur ID2 basculé en mode vitesse constante
  ID[0] = 1;//servomoteur ID1
  ID[1] = 2;//servomoteur ID2
  ACC[0] = 50;//accélération A=50*8.7deg/s^2
  ACC[1] = 50;//accélération A=50*8.7deg/s^2
}

void loop()
{
  //Les servomoteurs (ID1/ID2) accélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse max V=60*0.732=43.92rpm et maintiennent une rotation avant à vitesse constante
  Speed[0] = 60;
  Speed[1] = 60;
  sms_sts.SyncWriteSpe(ID, 2, Speed, ACC);
  delay(5000);

  //Les servomoteurs (ID1/ID2) décélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse 0 et arrêtent la rotation
  Speed[0] = 0;
  Speed[1] = 0;
  sms_sts.SyncWriteSpe(ID, 2, Speed, ACC);
  delay(2000);
  
  //Les servomoteurs (ID1/ID2) accélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse max V=-60*0.732=-43.92rpm et maintiennent une rotation inverse à vitesse constante
  Speed[0] = -60;
  Speed[1] = -60;
  sms_sts.SyncWriteSpe(ID, 2, Speed, ACC);
  delay(5000);

  //Les servomoteurs (ID1/ID2) décélèrent avec A=50*8.7deg/s^2 jusqu'à la vitesse 0 et s'arrêtent
  Speed[0] = 0;
  Speed[1] = 0;
  sms_sts.SyncWriteSpe(ID, 2, Speed, ACC);
  delay(2000);
}

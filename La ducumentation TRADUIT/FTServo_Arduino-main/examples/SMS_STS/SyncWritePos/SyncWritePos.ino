#include <SCServo.h>
SMS_STS sms_sts;

byte ID[2];
s16 Position[2];
u16 Speed[2];
byte ACC[2];

void setup()
{
  //Serial1.begin(115200);//débit en bauds du servomoteur sms_stss : 115200
  Serial1.begin(1000000);//débit en bauds du servomoteur STS : 1000000
  sms_sts.pSerial = &Serial1;
  delay(1000);
  ID[0] = 1;//servomoteur ID1
  ID[1] = 2;//servomoteur ID2
  Speed[0] = 60;//vitesse max V=60*0.732=43.92rpm
  Speed[1] = 60;//vitesse max V=60*0.732=43.92rpm
  ACC[0] = 50;//accélération A=50*8.7deg/s^2
  ACC[1] = 50;//accélération A=50*8.7deg/s^2
}

void loop()
{
  //Les servomoteurs (ID1/ID2) se déplacent à la position P1=4095 avec une vitesse max V=60*0.732=43.92rpm et une accélération A=50*8.7deg/s^2
  Position[0] = 4095;
  Position[1] = 4095;
  sms_sts.SyncWritePosEx(ID, 2, Position, Speed, ACC);
  delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(erreur)

  //Les servomoteurs (ID1/ID2) se déplacent à la position P0=0 avec une vitesse max V=60*0.732=43.92rpm et une accélération A=50*8.7deg/s^2
  Position[0] = 0;
  Position[1] = 0;
  sms_sts.SyncWritePosEx(ID, 2, Position, Speed, ACC);
  delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(erreur)
}

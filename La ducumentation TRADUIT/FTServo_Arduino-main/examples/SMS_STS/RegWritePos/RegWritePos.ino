#include <SCServo.h>

SMS_STS sms_sts;

void setup()
{
  //Serial1.begin(115200);//débit en bauds du servomoteur SMS : 115200
  Serial1.begin(1000000);//débit en bauds du servomoteur STS : 1000000
  sms_sts.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  //Les servomoteurs (ID1/ID2) se déplacent à la position P1=4095 avec une vitesse max V=60*0.732=43.92rpm et une accélération A=50*8.7deg/s^2
  sms_sts.RegWritePosEx(1, 4095, 60, 50);
  sms_sts.RegWritePosEx(2, 4095, 60, 50);
  sms_sts.RegWriteAction();
  delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(erreur)

  //Les servomoteurs (ID1/ID2) se déplacent à la position P0=0 avec une vitesse max V=60*0.732=43.92rpm et une accélération A=50*8.7deg/s^2
  sms_sts.RegWritePosEx(1, 0, 60, 50);
  sms_sts.RegWritePosEx(2, 0, 60, 50);
  sms_sts.RegWriteAction();
  delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(erreur)
}

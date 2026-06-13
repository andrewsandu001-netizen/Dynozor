/*
Programmation des paramètres du servomoteur
*/

#include <SCServo.h>

int LEDpin = 13;
SMS_STS sms_sts;

void setup()
{
  pinMode(LEDpin, OUTPUT);
  //Serial1.begin(115200);//débit en bauds du servomoteur SMS : 115200
  Serial1.begin(1000000);//débit en bauds du servomoteur STS : 1000000
  sms_sts.pSerial = &Serial1;
  delay(1000);
  digitalWrite(LEDpin, LOW);
  sms_sts.unLockEprom(1);//active la fonction d'enregistrement EPROM
  sms_sts.writeByte(1, SMS_STS_ID, 2);//ID
  sms_sts.LockEprom(2);//désactive la fonction d'enregistrement EPROM
  digitalWrite(LEDpin, HIGH);
}

void loop()
{

}

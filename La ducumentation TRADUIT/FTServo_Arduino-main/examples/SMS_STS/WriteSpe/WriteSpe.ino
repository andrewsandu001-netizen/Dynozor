#include <SCServo.h>

SMS_STS sms_sts;

void setup()
{
  //Serial1.begin(115200);//débit en bauds du servomoteur SMS : 115200
  Serial1.begin(1000000);//débit en bauds du servomoteur STS : 1000000
  sms_sts.pSerial = &Serial1;
  delay(1000);
  sms_sts.WheelMode(1);//servomoteur ID1 basculé en mode vitesse moteur constante
}

void loop()
{
  //Le servomoteur (ID1) accélère avec A=50*8.7deg/s^2 jusqu'à la vitesse max V=60*0.732=43.92rpm et maintient une rotation avant à vitesse constante
  sms_sts.WriteSpe(1, 60, 50);
  delay(5000);
  
  //Le servomoteur (ID1) décélère avec A=50*8.7deg/s^2 jusqu'à la vitesse 0 et arrête la rotation
  sms_sts.WriteSpe(1, 0, 50);
  delay(2000);
  
  //Le servomoteur (ID1) accélère avec A=50*8.7deg/s^2 jusqu'à la vitesse max V=-60*0.732=-43.92rpm et maintient une rotation inverse à vitesse constante
  sms_sts.WriteSpe(1, -60, 50);
  delay(5000);
  
  //Le servomoteur (ID1) décélère avec A=50*8.7deg/s^2 jusqu'à la vitesse 0 et arrête la rotation
  sms_sts.WriteSpe(1, 0, 50);
  delay(2000);
}

#include <SCServo.h>

HLSCL hlscl;

void setup()
{
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  delay(1000);
  hlscl.EleMode(1);//servomoteur ID1basculé en mode couple moteur constant
}

void loop()
{
  //Le servomoteur (ID1) tourne vers l'avant avec un courant de couple max T=300*6.5=1950mA
  hlscl.WriteEle(1, 300);
  delay(5000);
  
  //Le servomoteur (ID1/ID2) s'arrête avec un couple de 0
  hlscl.WriteEle(1, 0);
  delay(2000);
  
  //Le servomoteur (ID1) tourne en sens inverse avec un courant de couple max T=300*6.5=1950mA
  hlscl.WriteEle(1, -300);
  delay(5000);
  
  //Le servomoteur (ID1) s'arrête avec un couple de 0
  hlscl.WriteEle(1, 0);
  delay(2000);
}

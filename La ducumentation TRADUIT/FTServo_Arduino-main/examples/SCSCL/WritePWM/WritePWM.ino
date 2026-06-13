/*
Exemple de mode moteur
*/

#include <SCServo.h>

SCSCL sc;

void setup()
{
  Serial1.begin(1000000);
  sc.pSerial = &Serial1;
  delay(1000);
  sc.PWMMode(1);//servomoteur basculé en mode PWM en boucle ouverte pour le réglage de vitesse
}

void loop()
{
  //Le servomoteur (ID1) tourne vers l'avant avec un couple maximal de 50%
  sc.WritePWM(1, 500);
  delay(2000);
  
  //Le servomoteur (ID1) arrête la rotation
  sc.WritePWM(1, 0);
  delay(2000);
  
  //Le servomoteur (ID1) tourne en sens inverse avec un couple maximal de 50%
  sc.WritePWM(1, -500);
  delay(2000);
  
  //Le servomoteur (ID1) arrête la rotation
  sc.WritePWM(1,0);
  delay(2000);
}

/*
L'exemple d'écriture standard a été validé sur SCS15 ; pour d'autres modèles de servomoteurs de la série SCS, adaptez la position, la vitesse et les paramètres de délai.
*/

#include <SCServo.h>

SCSCL sc;

void setup()
{
  Serial1.begin(1000000);
  sc.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  //Le servomoteur (ID1) se déplace à la position P1=1000 avec la vitesse max V=1500*0.059=88.5rpm
  sc.WritePos(1, 1000, 0, 1500);
  delay((1000-20)*1000/(1500) + 100);//[(P1-P0)/(V)]*1000 + 100(erreur)
  
  //Le servomoteur (ID1) se déplace à la position P0=20 avec la vitesse max V=1500*0.059=88.5rpm
  sc.WritePos(1, 20, 0, 1500);
  delay((1000-20)*1000/(1500) + 100);//[(P1-P0)/(V)]*1000 + 100(erreur)
}

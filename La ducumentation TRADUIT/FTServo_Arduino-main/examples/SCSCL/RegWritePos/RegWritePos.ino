/*
L'exemple d'écriture asynchrone a été validé sur SCS15 ; pour d'autres modèles de servomoteurs de la série SCS, adaptez la position, la vitesse et les paramètres de délai.
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
  //Les servomoteurs (ID1/ID2) se déplacent à la position P1=1000 avec la vitesse max V=1500*0.059=88.5rpm
  sc.RegWritePos(1, 1000, 0, 1500);
  sc.RegWritePos(2, 1000, 0, 1500);
  sc.RegWriteAction();
  delay((1000-20)*1000/(1500) + 100);//[(P1-P0)/(V)]*1000 + 100(erreur)
  
  //Les servomoteurs (ID1/ID2) se déplacent à la position P0=20 avec la vitesse max V=1500*0.059=88.5rpm
  sc.RegWritePos(1, 20, 0, 1500);
  sc.RegWritePos(2, 20, 0, 1500);
  sc.RegWriteAction();
  delay((1000-20)*1000/(1500) + 100);//[(P1-P0)/(V)]*1000 + 100(erreur)
}

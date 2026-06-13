/*
L'exemple d'écriture synchronisée a été validé sur SCS15 ; pour d'autres modèles de servomoteurs de la série SCS, adaptez la position, la vitesse et les paramètres de délai.
*/

#include <SCServo.h>

SCSCL sc;

byte ID[2];
u16 Position[2];
u16 Speed[2];

void setup()
{
  Serial1.begin(1000000);
  sc.pSerial = &Serial1;
  delay(1000);
  ID[0] = 1;//servomoteur ID1
  ID[1] = 2;//servomoteur ID2
  Speed[0] = 1500;//vitesse max V=1500*0.059=88.5rpm
  Speed[1] = 1500;//vitesse max V=1500*0.059=88.5rpm
}

void loop()
{
  //Les servomoteurs (ID1/ID2) se déplacent à la position P1=1000 avec la vitesse max V=1500*0.059=88.5rpm
  Position[0] = 1000;
  Position[1] = 1000;
  sc.SyncWritePos(ID, 2, Position, 0, Speed);
  delay((1000-20)*1000/(1500) + 100);//[(P1-P0)/(V)]*1000 + 100(erreur)

  //Les servomoteurs (ID1/ID2) se déplacent à la position P0=20 avec la vitesse max V=1500*0.059=88.5rpm
  Position[0] = 20;
  Position[1] = 20;
  sc.SyncWritePos(ID, 2, Position, 0, Speed);
  delay((1000-20)*1000/(1500) + 100);//[(P1-P0)/(V)]*1000 + 100(erreur)
}

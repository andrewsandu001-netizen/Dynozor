/*
Commande de lecture synchronisée, lit en retour les informations de position et de vitesse des deux servomoteurs ID1 et ID2
*/

#include <SCServo.h>

HLSCL hlscl;

uint8_t ID[] = {1, 2};
uint8_t rxPacket[4];
int16_t Position;
int16_t Speed;

void setup()
{
  Serial.begin(115200);
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  hlscl.syncReadBegin(sizeof(ID), sizeof(rxPacket), 5);//10*10*2=200us<5ms
  delay(1000);
}

void loop()
{  
  hlscl.syncReadPacketTx(ID, sizeof(ID), HLSCL_PRESENT_POSITION_L, sizeof(rxPacket));//envoi du paquet de commande de lecture synchronisée
  for(uint8_t i=0; i<sizeof(ID); i++){
    //réception du paquet de réponse de lecture synchronisée de ID[i]
    if(!hlscl.syncReadPacketRx(ID[i], rxPacket)){
     Serial.print("ID:");
     Serial.println(ID[i]);
     Serial.println("sync read error!");
     continue;//échec de réception/décodage
    }
    Position = hlscl.syncReadRxPacketToWrod(15);//décodage de 2 octets ; bit15 est le bit de direction, paramètre=0 signifie sans bit de direction
    Speed = hlscl.syncReadRxPacketToWrod(15);//décodage de 2 octets ; bit15 est le bit de direction, paramètre=0 signifie sans bit de direction
    Serial.print("ID:");
    Serial.println(ID[i]);
    Serial.print("Position:");
    Serial.println(Position);
    Serial.print("Speed:");
    Serial.println(Speed);
  }
  delay(10);
}

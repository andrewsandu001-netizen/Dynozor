/*
Commande de lecture synchronisée, lit en retour les informations de position et de vitesse des deux servomoteurs ID1 et ID2
*/

#include <SCServo.h>

SMS_STS sms_sts;

uint8_t ID[] = {1, 2};
uint8_t rxPacket[4];
int16_t Position;
int16_t Speed;

void setup()
{
  Serial.begin(115200);
  //Serial1.begin(115200);//débit en bauds du servomoteur SMS : 115200
  Serial1.begin(1000000);//débit en bauds du servomoteur STS : 1000000
  sms_sts.pSerial = &Serial1;
  sms_sts.syncReadBegin(sizeof(ID), sizeof(rxPacket), 5);//10*10*2=200us<5ms
  delay(1000);
}

void loop()
{  
  sms_sts.syncReadPacketTx(ID, sizeof(ID), SMS_STS_PRESENT_POSITION_L, sizeof(rxPacket));//envoi du paquet de commande de lecture synchronisée
  for(uint8_t i=0; i<sizeof(ID); i++){
    //réception du paquet de réponse de lecture synchronisée de ID[i]
    if(!sms_sts.syncReadPacketRx(ID[i], rxPacket)){
     Serial.print("ID:");
     Serial.println(ID[i]);
     Serial.println("sync read error!");
     continue;//échec de réception/décodage
    }
    Position = sms_sts.syncReadRxPacketToWrod(15);//décodage de 2 octets ; bit15 est le bit de direction, paramètre=0 signifie sans bit de direction
    Speed = sms_sts.syncReadRxPacketToWrod(15);//décodage de 2 octets ; bit15 est le bit de direction, paramètre=0 signifie sans bit de direction
    Serial.print("ID:");
    Serial.println(ID[i]);
    Serial.print("Position:");
    Serial.println(Position);
    Serial.print("Speed:");
    Serial.println(Speed);
  }
  delay(10);
}

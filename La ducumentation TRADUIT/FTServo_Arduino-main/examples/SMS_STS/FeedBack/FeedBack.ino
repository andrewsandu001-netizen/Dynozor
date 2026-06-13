/*
Lecture de tous les paramètres de retour du servomoteur : position, vitesse, charge, tension, température, état de mouvement, courant ;
La fonction FeedBack lit les paramètres du servomoteur dans le tampon ; la fonction Readxxx(-1) renvoie l'état correspondant depuis ce tampon ;
Fonction Readxxx(ID) : ID=-1 renvoie les paramètres du tampon FeedBack ; ID>=0 renvoie directement l'état du servomoteur ID spécifié via une instruction de lecture,
sans appeler la fonction FeedBack.
*/

#include <SCServo.h>

SMS_STS sms_sts;
int LEDpin = 13;

void setup()
{
  pinMode(LEDpin,OUTPUT);
  digitalWrite(LEDpin, HIGH);
  //Serial1.begin(115200);//débit en bauds du servomoteur SMS : 115200
  Serial1.begin(1000000);//débit en bauds du servomoteur STS : 1000000
  Serial.begin(115200);
  sms_sts.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  int Pos;
  int Speed;
  int Load;
  int Voltage;
  int Temper;
  int Move;
  int Current;
  sms_sts.FeedBack(1);
  if(!sms_sts.getLastError()){
    digitalWrite(LEDpin, LOW);
    Pos = sms_sts.ReadPos(-1);
    Speed = sms_sts.ReadSpeed(-1);
    Load = sms_sts.ReadLoad(-1);
    Voltage = sms_sts.ReadVoltage(-1);
    Temper = sms_sts.ReadTemper(-1);
    Move = sms_sts.ReadMove(-1);
    Current = sms_sts.ReadCurrent(-1);
    Serial.print("Position:");
    Serial.println(Pos);
    Serial.print("Speed:");
    Serial.println(Speed);
    Serial.print("Load:");
    Serial.println(Load);
    Serial.print("Voltage:");
    Serial.println(Voltage);
    Serial.print("Temper:");
    Serial.println(Temper);
    Serial.print("Move:");
    Serial.println(Move);
    Serial.print("Current:");
    Serial.println(Current);
    delay(10);
  }else{
    digitalWrite(LEDpin, HIGH);
    Serial.println("FeedBack err");
    delay(500);
  }
  
  Pos = sms_sts.ReadPos(1);
  if(!sms_sts.getLastError()){
    digitalWrite(LEDpin, LOW);
    Serial.print("Servo position:");
    Serial.println(Pos, DEC);
    delay(10);
  }else{
    Serial.println("read position err");
    digitalWrite(LEDpin, HIGH);
    delay(500);
  }
  
  Voltage = sms_sts.ReadVoltage(1);
  if(!sms_sts.getLastError()){
    digitalWrite(LEDpin, LOW);
    Serial.print("Servo Voltage:");
    Serial.println(Voltage, DEC);
    delay(10);
  }else{
    Serial.println("read Voltage err");
    digitalWrite(LEDpin, HIGH);
    delay(500);
  }
  
  Temper = sms_sts.ReadTemper(1);
  if(!sms_sts.getLastError()){
    digitalWrite(LEDpin, LOW);
    Serial.print("Servo temperature:");
    Serial.println(Temper, DEC);
    delay(10);
  }else{
    Serial.println("read temperature err");
    digitalWrite(LEDpin, HIGH);
    delay(500);    
  }

  Speed = sms_sts.ReadSpeed(1);
  if(!sms_sts.getLastError()){
    digitalWrite(LEDpin, LOW);
    Serial.print("Servo Speed:");
    Serial.println(Speed, DEC);
    delay(10);
  }else{
    Serial.println("read Speed err");
    digitalWrite(LEDpin, HIGH);
    delay(500);    
  }
  
  Load = sms_sts.ReadLoad(1);
  if(!sms_sts.getLastError()){
    digitalWrite(LEDpin, LOW);
    Serial.print("Servo Load:");
    Serial.println(Load, DEC);
    delay(10);
  }else{
    Serial.println("read Load err");
    digitalWrite(LEDpin, HIGH);
    delay(500);    
  }
  
  Current = sms_sts.ReadCurrent(1);
  if(!sms_sts.getLastError()){
    digitalWrite(LEDpin, LOW);
    Serial.print("Servo Current:");
    Serial.println(Current, DEC);
    delay(10);
  }else{
    Serial.println("read Current err");
    digitalWrite(LEDpin, HIGH);
    delay(500);    
  }

  Move = sms_sts.ReadMove(1);
  if(!sms_sts.getLastError()){
    digitalWrite(LEDpin, LOW);
    Serial.print("Servo Move:");
    Serial.println(Move, DEC);
    delay(10);
  }else{
    Serial.println("read Move err");
    digitalWrite(LEDpin, HIGH);
    delay(500);    
  }
  Serial.println();
}

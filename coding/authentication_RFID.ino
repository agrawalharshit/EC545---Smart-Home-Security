 
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int greenLight = 5;
int redLight = 6;
int access_denial_count = 0;
int count_down = 0;
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  pinMode(redLight,OUTPUT);  
  pinMode(greenLight,OUTPUT);  
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
  if(access_denial_count > 3) {
    Serial.println("Access denailed for more than 4 times, please try later.");
    count_down = access_denial_count;
    access_denial_count = 0; //reset;
  }
  while (count_down > 0){
    Serial.print("VIRTUAL COUNT DOWN:");
    count_down--;
    Serial.println(count_down,DEC);
    digitalWrite(redLight,HIGH); digitalWrite(greenLight,HIGH);
    delay(1000);
    digitalWrite(redLight,LOW);digitalWrite(greenLight,LOW);
    delay(1000);
  }
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "D2 65 85 19") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    digitalWrite(greenLight,HIGH);
    Serial.println();
    delay(2000);
    digitalWrite(greenLight,LOW);
    access_denial_count = 0;
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(redLight,HIGH);
    delay(2000);
    digitalWrite(redLight,LOW);
    access_denial_count++;
  }
} 
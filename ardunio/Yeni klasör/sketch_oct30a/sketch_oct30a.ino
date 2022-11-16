#include <Servo.h>
#include <Arduino.h>

const byte buzzerPin=4;
const byte trigPin=6;
const byte echoPin=7;
const byte servoPin=5;
long sure;
int mesafe;
Servo servo_motor_1;

void setup() {
pinMode(buzzerPin,OUTPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
servo_motor_1.attach(servoPin);
}

void loop() {
for(int konum=15;konum<=165;konum++) {
servo_motor_1.write(konum);
delay(150);
mesafe=mesafehesapla();
verilerigoster(konum,mesafe);
if(mesafe<=25)
{
  digitalWrite(buzzerPin,HIGH);
  delay(100);
  digitalWrite(buzzerPin,LOW);
  delay(100);
}
}
for(int konum=164;konum>15;konum--) {
servo_motor_1.write(konum);
delay(150);
mesafe=mesafehesapla();
verilerigoster(konum,mesafe);
if(mesafe<=25)
{
  digitalWrite(buzzerPin,HIGH);
  delay(100);
  digitalWrite(buzzerPin,LOW);
  delay(100);
}
}
}

int mesafehesapla() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  sure=pulseIn(echoPin,HIGH);
  mesafe=sure/2*0.034;
  return mesafe;
}
void verilerigoster(int konum,int mesafe)
{
 Serial.print("Konum (Derece):\n");
 Serial.print(konum);
 Serial.print(" ----- \n");
 Serial.print("Mesafe:\n");
 Serial.print(mesafe);
}
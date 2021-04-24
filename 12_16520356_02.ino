#include <Servo.h>          
Servo servo_0;				// Mendeklarasi servo yang dipakai (boleh 1 atau lebih)     
const int servoPin = 7;		// pin Arduino yang terhubung ke Servo 0
const int ledPin = 2;		// pin Arduino yang terhubung ke LED
int pos = 0;				// Variabel untuk menyimpan nilai posisi (derajat)

void setup()
{
  pinMode(ledPin, OUTPUT);		// pin diatur sebagai output
  servo_0.attach(servoPin);		// lokasi servo dipasang
  servo_0.write(pos);			// Inisialisasi posisi awal Servo 0 
}

void loop()
{
  digitalWrite(2, HIGH);					// LED menyala
  for (pos = 0; pos <= 90; pos += 1) {		
    servo_0.write(pos);						// Meminta servo supaya menuju posisi pada variabel "pos"
    delay(15);								// Tunggu 15 milisekon untuk servo mencapai posisi
  }
  delay(2000);								// Tunggu selama 2 detik
  
  digitalWrite(2, LOW);						// LED mati
  for (pos = 90; pos >= 0; pos -= 1) {
    servo_0.write(pos);						// Meminta servo supaya menuju posisi pada variabel "pos"
    delay(15);								// Tunggu 15 milisekon servo untuk servo mencapai posisi		
  }
  delay(2000);								// Tunggu selama 2 detik
}
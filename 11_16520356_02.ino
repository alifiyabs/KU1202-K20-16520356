int sensePin = A0;    // pin Arduino yang akan membaca output sensor
int sensorInput;      // variabel untuk menyimpan nilai output sensor
double temp;          // variabel untuk menyimpan nilai suhu (dalam celcius)

void setup()
{
  Serial.begin(9600); // memulai port serial
}

void loop()
{
  sensorInput = analogRead(sensePin);  // Membaca sensor analog
  temp = (double)sensorInput / 1024;   // Menghitung persentase dari pembacaan input
  temp = temp * 5;					   // Dikali dengan 5 volt untuk mendapatkan nilai tegangan
  temp = temp - 0.5;				   // Dikurangi dengan offset
  temp = temp * 100;				   // Mengkonversi jadi derajat celcius
  
  Serial.print("Suhu: ");
  Serial.print(temp);
  Serial.println(" Celcius");
}
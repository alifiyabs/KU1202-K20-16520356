#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);	// pin arduino yang terhubung ke LCD
const int ping_Pin = A1;				// pin arduino yang terhubung ke ultrasonic sensor		
long dur, cm;							// simpan nilai durasi dan jarak (cm)

void setup() {
  lcd.begin(16, 2);						// atur jumlah kolom dan baris LCD
  lcd.print("PING Sensor");
}

void loop() {
  cm = read_sensor_ultrasonic();
  
  /* print to LCD */
  lcd.setCursor(0,1);				// atur kursor ke kolom 0 baris 1
  lcd.print("Jarak");
  lcd.setCursor(6,1);				// atur kursor ke kolom 6 baris 1
  lcd.print(cm);					// cetak nilai jarak
  lcd.print("cm");					// cetak nilai satuan (cm)
  print_unit_cm(cm);				// cetak nilai satuan (cm)				
}

int read_sensor_ultrasonic(){
  
   /* Membaca dari ultrasonic sensor */
  
  pinMode(ping_Pin, OUTPUT);		// atur pin sebagai OUTPUT
  digitalWrite(ping_Pin, LOW);		// beri sinyal awal dengan LOW
  delayMicroseconds(2);				// jeda 2 mikro sekon
  digitalWrite(ping_Pin, HIGH);		// trigger sensor dengan sinyal HIGH
  delayMicroseconds(5);				// trigger sensor selama 5 mikro sekon
  digitalWrite(ping_Pin, LOW);		// beri sinyal LOW
  
  pinMode(ping_Pin, INPUT);			// atur pin sebagai INPUT
  dur = pulseIn(ping_Pin, HIGH);	// sinyal HIGH untuk dapat durasi dalam mikro sekon
  cm = ms_to_cm(dur);				// konversi mikro sekon ke cm
  
  if (cm >= 2 && cm <= 330){
    return cm;
  } else {
    return 0;
  }
}

long ms_to_cm(long ms) {
  // kecepatan suara 340 m/s atau 29 mikro/cm
  // dibagi dua untuk mencari jarak sensor-objek
  return ms / 29 / 2;
}

void print_unit_cm(long cm) {
  /* mencetak satuan cm */
  
  int ROW = 1;
  int ERR_Digit = 6;
  int oneDigit = 7;		// untuk satu digit
  int twoDigit = 8;		// untuk dua digit
  int threeDigit = 9;	// untuk tiga digit
  int lenUnit = 2;
}
  


  
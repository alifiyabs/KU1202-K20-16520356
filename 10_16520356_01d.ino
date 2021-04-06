int count = 0;

int counter;

void setup()
{
  pinMode(7, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  for (counter = 0; counter < 3; ++counter) {
    digitalWrite(7, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
<<<<<<< HEAD
    digitalWrite(7, LOW);
=======
    digitalWrite(7, HIGH);
>>>>>>> parent of 848a9ed (Delete 10_16520356_01d.ino)
    delay(1000); // Wait for 1000 millisecond(s)
  }
  delay(5000); // Wait for 5000 millisecond(s)
  count += (0 + 1);
  Serial.print("hello world");
  Serial.println(count);
}
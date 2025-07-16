const int tempPin = A0;
const int ledPin = 8; // Optional LED for alert

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(tempPin);
  float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage (0–5V)
  float temperatureC = (voltage - 0.5) * 100.0; // TMP36 conversion

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  if (temperatureC > 35) {
    digitalWrite(ledPin, HIGH); // Turn on LED
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}

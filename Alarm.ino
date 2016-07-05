int led = 10;
int buzzer = 11;
int trigPin = 12;
int echoPin = 13;
bool alarm = false;

void setup() {
  Serial.begin (9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  if (alarm == false) {
    digitalWrite(led, LOW);
    
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
  
    distance = (duration/2) / 29.1;
    if (distance < 60) {
      alarm = true;
    }
    if (distance >= 200 || distance <= 0){
      Serial.println("Out of range");
    } else {
      Serial.print(distance);
      Serial.println(" cm");
    }
  delay(500);
  } else {
    Serial.println("Alarm set off!");
    tone(buzzer, 1000);
    digitalWrite(led, HIGH);
    delay(1000);
    noTone(buzzer);
    digitalWrite(led, HIGH);
    delay(1000);
  }

}

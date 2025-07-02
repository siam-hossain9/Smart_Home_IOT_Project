#include <Servo.h>

// Pin definitions
#define TRIG_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 4
#define DOOR_SERVO_PIN 5
#define RAIN_SENSOR_PIN 6  // Digital output from raindrop sensor
#define CLOTHES_SERVO_PIN 7

Servo doorServo;
Servo clothesServo;

long duration;
int distance;

void setup() {
  // Initialize pin modes
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RAIN_SENSOR_PIN, INPUT);

  // Attach servos to their pins
  doorServo.attach(DOOR_SERVO_PIN);
  clothesServo.attach(CLOTHES_SERVO_PIN);

  // Start serial monitor (for debugging)
  Serial.begin(9600);
}

void loop() {
  // ----------- Automatic Door System -----------

  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Calculate distance
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If person detected within 30cm
  if (distance > 0 && distance < 30) {
    digitalWrite(BUZZER_PIN, HIGH);     // Buzz on
    doorServo.write(90);                // Open door
    delay(3000);                        // Wait for 3 seconds
    doorServo.write(0);                 // Close door
    digitalWrite(BUZZER_PIN, LOW);      // Buzz off
  }

  // ----------- Rain Detection System -----------

  if (digitalRead(RAIN_SENSOR_PIN) == LOW) {  // LOW means rain detected
    Serial.println("Rain detected! Retracting clothes...");
    clothesServo.write(90);                  // Pull back clothes
    delay(3000);                             
  } else {
    Serial.println("No rain. Clothes are safe.");
    clothesServo.write(0);                   // Keep clothes in original position
  }

  delay(500); // Short delay before next loop
}

// Pin assignments
const int trigPin = 9;
const int echoPin = 8;
const int touchPin = 7;
const int segmentPins[] = {2, 3, 4, 5, 6, 10, 11};  // Adjust based on your wiring

// Variables
int counter = 0;
const int thresholdDistance = 15;  // Distance threshold in cm
bool objectDetected = false;

// 7-Segment display digits (0 to 9)
const byte digitMap[10] = {
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01101111  // 9
};

// Function to display a digit on the 7-segment display
void displayDigit(int digit) {
  byte segments = digitMap[digit % 10];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(segments, i));
  }
}

// Ultrasonic distance measurement function
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;  // Convert to cm
}

void setup() {
  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(touchPin, INPUT);
  
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  // Initialize display
  displayDigit(counter);
}

void loop() {
  // Check distance
  long distance = getDistance();

  // Increment counter if object detected within threshold
  if (distance < thresholdDistance && !objectDetected) {
    counter++;
    if (counter > 9) counter = 0;  // Reset counter if it exceeds 9
    displayDigit(counter);
    objectDetected = true;
  }
  
  if (distance >= thresholdDistance) {
    objectDetected = false;
  }

  // Reset counter if touch sensor is pressed
  if (digitalRead(touchPin) == HIGH) {
    counter = 0;
    displayDigit(counter);
    delay(200);  // Debounce
  }
}

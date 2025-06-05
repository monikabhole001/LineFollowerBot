#define lm1 6     // Left motor forward pin
#define lm2 5     // Left motor backward pin
#define rm1 9     // Right motor forward pin
#define rm2 10    // Right motor backward pin

#define ls2 A4    // Left sensor 2 pin (analog)
#define ls1 A3    // Left sensor 1 pin (analog)
#define rs1 A2    // Right sensor 1 pin (analog)
#define rs2 A1    // Right sensor 2 pin (analog)

int l1, l2, r1, r2; // Variables to store sensor readings

void setup() {
  // Initialize motor pins as outputs
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);

  // Initialize sensor pins as inputs
  pinMode(ls2, INPUT);
  pinMode(ls1, INPUT);
  pinMode(rs1, INPUT);
  pinMode(rs2, INPUT);
}

void readsensors() {
  // Read sensors and invert the values
  // because line sensors typically output LOW when detecting line
  l1 = !digitalRead(ls1);
  l2 = !digitalRead(ls2);
  r1 = !digitalRead(rs1);
  r2 = !digitalRead(rs2);
}

void loop() {
  readsensors();  // Update sensor readings

  // Stop motors if no line is detected by any sensor
  if(l2 == 0 && l1 == 0 && r1 == 0 && r2 == 0) {
    analogWrite(lm1, 0);
    analogWrite(lm2, 0);
    analogWrite(rm1, 0);
    analogWrite(rm2, 0);
  }

  // If only the rightmost sensor detects the line, turn right
  if(l2 == 0 && l1 == 0 && r1 == 0 && r2 == 1) {
    analogWrite(lm1, 0);
    analogWrite(lm2, 0);
    analogWrite(rm1, 140);  // Move right motor forward to turn right
    analogWrite(rm2, 0);
  }

  // Add additional conditions and motor controls as per your requirements
  // For example:
  // if(l2 == 1 && l1 == 0 && r1 == 0 && r2 == 0) {
  //   // Move left motor forward to turn left
  // }

  // You can extend logic here for other sensor combinations to follow the line

  // Example: Move forward if middle sensors detect the line (to be added)

  // This code currently stops or turns right based on sensor input; you can fill in the rest
}

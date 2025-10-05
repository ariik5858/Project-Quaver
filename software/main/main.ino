#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

legController control;

void setup() {
  Serial.begin(9600);
  myServo.begin();
  myServo.setPWMFreq(60);  // Analog servos run at ~60 Hz
  delay(10);

  float theta1 = 0;
  float theta2 = 0;
  float theta3 = 0;

  ik(0, 0, -100, false, theta1, theta2, theta3);

  Serial.println("Starting test");
}

void loop() {
  
}

// myServo.setPWM(0,0,angleToPulse(135)); // theta3
// myServo.setPWM(1,0,angleToPulse(90)); // theta2
// delay(1000);

// myServo.setPWM(0,0,angleToPulse((theta3 * 180) / PI));
// myServo.setPWM(1,0,angleToPulse((theta2 * 180) / PI));
// delay(1000);

// myServo.setPWM(0,0,angleToPulse(90));
// myServo.setPWM(1,0,angleToPulse(180));
// delay(1000);

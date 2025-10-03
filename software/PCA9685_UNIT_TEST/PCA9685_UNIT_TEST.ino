#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 150  // Pulse length for 0° (adjust if needed)
#define SERVOMAX 600  // Pulse length for 180° (adjust if needed)


// Map angle to pulse width
uint16_t angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Testing PCA9685 with one servo");
  myServo.begin();
  myServo.setPWMFreq(60);  // Analog servos run at ~60 Hz
  delay(10);
}

void loop() {
  myServo.setPWM(0,0,angleToPulse(135));
  myServo.setPWM(1,0,angleToPulse(90));
   delay(1000);
  // myServo.setPWM(0,0,angleToPulse(135));
  // myServo.setPWM(1,0,angleToPulse(135));
  // delay(500);
  // myServo.setPWM(0,0,angleToPulse(120));
  // myServo.setPWM(1,0,angleToPulse(120));
  // delay(500);
  // myServo.setPWM(0,0,angleToPulse(90));
  // myServo.setPWM(1,0,angleToPulse(180));
  // delay(1000);

}
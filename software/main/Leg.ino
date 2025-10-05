Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 150  // Pulse length for 0° (adjust if needed)
#define SERVOMAX 600  // Pulse length for 180° (adjust if needed)

uint16_t angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

struct Leg {
  bool side;       // true = right, false = left
  float theta1;
  float theta2;
  float theta3;

  Leg(bool s = true) : side(s), theta1(0), theta2(0), theta3(0) {}
};

class LegController {
public:
  LegController();
  ~LegController();

  void setLegPos(int legNum, float x, float y, float z);
  Leg& getLeg(int legNum);

private:
  Leg legs[4];
};

// --- Implementation ---

LegController::LegController() {
  // Right legs: 0, 1
  for (int i = 0; i < 2; i++) {
    legs[i] = Leg(true);
  }

  // Left legs: 2, 3
  for (int i = 2; i < 4; i++) {
    legs[i] = Leg(false);
  }
}

LegController::~LegController() {
  // nothing to delete — legs are stack-allocated
}

void LegController::setLegPos(int legNum, float x, float y, float z) {
  if (legNum < 0 || legNum >= 4) return;

  Leg &leg = legs[legNum];
  ik(x, y, z, leg.side, leg.theta1, leg.theta2, leg.theta3);
}

Leg& LegController::getLeg(int legNum) {
  return legs[legNum];
}

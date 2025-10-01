float theta1 = 0;
float theta2 = 0;
float theta3 = 0;

void setup() {
  // put your setup code here, to run once:
  theta1 = 0;
  theta2 = 0;
  theta3 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  ik(0, 0, 0, false, theta1, theta2, theta3);
}

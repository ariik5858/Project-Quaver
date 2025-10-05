// Arm lengths
const float L1 = 50.7;
const float L2 = 10;
const float L3 = 100.21;
const float L4 = 50.42;
const float L5 = 100;
const float L6 = 134.16;
const float L7 = 70.94;
const float L8 = 52.5;
const float L9 = 60;
const float L10 = 24.5;

const float d1 = 86.79;
const float d2z = 25.5;
const float d2x = 19.3;

const float gamma1 = 85 * DEG_TO_RAD;  // Convert degrees to radians
const float H_PI = 1.5707963267948966;

void ik(float x, float y, float z, bool side, float &theta1, float &theta2, float &theta3) {
  Serial.println(F("=== IK Debug Start ==="));

  // -- yz plane calculations -- //
  float Ryz = sqrtf(y * y + z * z);
  Serial.print(F("Ryz = ")); Serial.println(Ryz);

  float alpha1 = acos(L1 / Ryz);
  Serial.print(F("alpha1 = ")); Serial.println(alpha1 * RAD_TO_DEG);

  float alpha2 = atan(y / z);
  Serial.print(F("alpha2 = ")); Serial.println(alpha2 * RAD_TO_DEG);

  float phi = alpha1 + alpha2;
  Serial.print(F("phi = ")); Serial.println(phi * RAD_TO_DEG);
  
  // for now the code will only look at the right side
  theta1 = phi; // right side theta
  Serial.print(F("theta1 = ")); Serial.println(theta1 * RAD_TO_DEG);
  
  // -- rotation about x-axis -- //
  float y_prime = y * cos(theta1) + z * sin(theta1);
  float z_prime = -y * sin(theta1) + z * cos(theta1);
  Serial.print(F("y' = ")); Serial.println(y_prime);
  Serial.print(F("z' = ")); Serial.println(z_prime);
  
  // -- xz plane calculations -- //
  float b1 = sqrt(x * x + z_prime * z_prime);
  Serial.print(F("b1 = ")); Serial.println(b1);

  float alpha3_prime = atan(abs(z_prime) / abs(x));
  Serial.print(F("alpha3' = ")); Serial.println(alpha3_prime * RAD_TO_DEG);

  float phi1 = atan(d2z / d2x);
  Serial.print(F("phi1 = ")); Serial.println(phi1 * RAD_TO_DEG);

  float alpha4 = phi1 + (PI - phi1);
  Serial.print(F("alpha4 = ")); Serial.println(alpha4 * RAD_TO_DEG);

  float d2 = sqrt(d2x * d2x + d2z * d2z);
  Serial.print(F("d2 = ")); Serial.println(d2);

  float b2 = sqrt(d2 * d2 + b1 * b1 - 2 * d2 * b1);
  Serial.print(F("b2 = ")); Serial.println(b2);

  float alpha5 = asin((sin(alpha4) / b2) * b1);
  Serial.print(F("alpha5 = ")); Serial.println(alpha5 * RAD_TO_DEG);

  float alpha6 = acos((L3 * L3 + L5 * L5 - b2 * b2) / (2 * L3 * L5));
  Serial.print(F("alpha6 = ")); Serial.println(alpha6 * RAD_TO_DEG);

  float alpha7 = asin((sin(alpha6) / b2) * L3);
  Serial.print(F("alpha7 = ")); Serial.println(alpha7 * RAD_TO_DEG);

  float phi2 = alpha7 + alpha5;
  Serial.print(F("phi2 = ")); Serial.println(phi2 * RAD_TO_DEG);

  float alpha8 = PI - alpha6;
  Serial.print(F("alpha8 = ")); Serial.println(alpha8 * RAD_TO_DEG);

  float b3 = sqrt(L4 * L4 + L5 * L5 - 2 * L4 * L5 * cos(alpha8));
  Serial.print(F("b3 = ")); Serial.println(b3);

  float alpha9 = asin((sin(alpha8) / b3) * L4);
  Serial.print(F("alpha9 = ")); Serial.println(alpha9 * RAD_TO_DEG);

  float alpha10 = acos((L8 * L8 + b3 * b3 - L6 * L6) / (2 * L8 * b3));
  Serial.print(F("alpha10 = ")); Serial.println(alpha10 * RAD_TO_DEG);

  float phi3 = alpha10 + alpha9;
  Serial.print(F("phi3 = ")); Serial.println(phi3 * RAD_TO_DEG);

  float alpha11 = 2 * PI - phi2 - phi3 - gamma1;
  Serial.print(F("alpha11 = ")); Serial.println(alpha11 * RAD_TO_DEG);

  float b4 = sqrt(L8 * L8 + d2 * d2 - 2 * L8 * d2 * cos(alpha11));
  Serial.print(F("b4 = ")); Serial.println(b4);

  float alpha12 = asin((sin(alpha11) / b4) * L8);
  Serial.print(F("alpha12 = ")); Serial.println(alpha12 * RAD_TO_DEG);

  float alpha13 = acos((L10 * L10 + b4 * b4 - L9 * L9) / (2 * L10 * b4));
  Serial.print(F("alpha13 = ")); Serial.println(alpha13 * RAD_TO_DEG);

  // final results
  theta2 = (phi1 + alpha12 + alpha13) - H_PI;
  theta3 = phi1 + phi2;

  Serial.print(F("theta2 = ")); Serial.println(theta2 * RAD_TO_DEG);
  Serial.print(F("theta3 = ")); Serial.println(theta3 * RAD_TO_DEG);
  Serial.println(F("=== IK Debug End ==="));
}

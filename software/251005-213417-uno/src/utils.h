/*
    utils.h - Main include file for the IK calculations
*/
#pragma once

#include <Arduino.h>

constexpr float L1 = 50.7f;
constexpr float L2 = 10.0f;
constexpr float L3 = 100.21f;
constexpr float L4 = 50.42f;
constexpr float L5 = 100.0f;
constexpr float L6 = 134.16f;
constexpr float L7 = 70.94f;
constexpr float L8 = 52.5f;
constexpr float L9 = 60.0f;
constexpr float L10 = 24.5f;

constexpr float d1 = 86.79f;
constexpr float d2z = 25.5f;
constexpr float d2x = 19.3f;
const float d2 = sqrt(d2x*d2x + d2z*d2z);

constexpr float gamma = 47.5 * DEG_TO_RAD;  // Convert degrees to radians

static inline float clampf(float num, float lo, float hi) {
    if (num < lo) return lo;
    if (num > hi) return hi;
    return num;
}

static inline float wrap(float num) {
    if (num < 0) {
        float ccwNum = num + 2*PI;
        if (ccwNum > PI) {
            return PI;
        } else {
            return ccwNum;
        }
    }
    return num;
}

static inline float safe_acos(float t) { return acosf(clampf(t, -1.0f, 1.0f)); }
static inline float safe_asin(float t) { return asinf(clampf(t, -1.0f, 1.0f)); }
static inline float sinTheta(float a, float b, float theta) { return safe_asin((a/b) * sin(theta)); }
static inline float cosTheta(float a, float b, float c) { return safe_acos((a*a + b*b - c*c) / (2*a*b)); }
static inline float cosLawC(float a, float b, float theta) { return sqrt(a*a + b*b - 2*a*b*cos(abs(theta)));}
#include "FastLED.h"

#include <SPI.h>

#include <Adafruit_GFX.h>

#include <Adafruit_ST7735.h>

#include <WiFi.h>

#define TFT_CS1 28

#define TFT_DC1 27

#define TFT_RST1 26

//number of leds in your led strip

#define NUM_LEDS 30

//Data pin

#define DATA_PIN 7

int CGColor = 1;

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS1, TFT_DC1, TFT_RST1);

String Mode = "Standard |> L+R button";

int ChosenModeInt = 0;

int chooseRoGoB = 1;

String ChosenMode[] = {

"Standard |> L+R button",

"Rainbow Static",

"Rainbow Train",

"Candle",

"Christmas Mystery",

"Garland Static",

"Blinking Garland",

"Spring",

"September leaves",

"Blinding light",

"Moonlight",

"Brightness |> L+R btn"

};

const int Push_ButtonR = 29;

int Button_StateR = LOW;

const int Push_ButtonL = 6;

int Button_StateL = LOW;

int Canndlemode = 0;

int CandlebValue = 0;

String currentScrenn = "MainMenu";

int BrightnessLevel = 100;

int r = 171;

int g = 255;

int b = 0;

int color_array_for_rainbowMode[] = { 0xff0000, 0xff0055, 0xff00af, 0xef00ff, 0x8900ff, 0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7, 0x00FF91, 0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200, 0xFF4D00, 0xff0000, 0xff0055, 0xff00af, 0xef00ff, 0x8900ff, 0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7, 0x00FF91, 0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200, 0xFF4D00, 0xff0000, 0xff0055, 0xff00af, 0xef00ff, 0x8900ff, 0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7, 0x00FF91, 0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200, 0xFF4D00, 0xff0000, 0xff0055, 0xff00af, 0xef00ff, 0x8900ff, 0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7, 0x00FF91, 0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200, 0xFF4D00, 0xff0000, 0xff0055, 0xff00af, 0xef00ff, 0x8900ff, 0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7, 0x00FF91, 0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200, 0xFF4D00, 0xff0000, 0xff0055, 0xff00af, 0xef00ff, 0x8900ff,

0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7, 0x00FF91, 0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200,

0xFF4D00, 0xff0000, 0xff0055, 0xff00af, 0xef00ff, 0x8900ff, 0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7, 0x00FF91,0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200, 0xFF4D00, 0xff0000, 0xff0055, 0xff00af, 0xef00ff, 0x8900ff, 0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7,0x00FF91, 0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200, 0xFF4D00, 0xff0000, 0xff0055, 0xff00af, 0xef00ff, 0x8900ff, 0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7, 0x00FF91, 0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200, 0xFF4D00, 0xff0000, 0xff0055, 0xff00af, 0xef00ff, 0x8900ff, 0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7, 0x00FF91, 0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200, 0xFF4D00, 0xff0000, 0xff0055,

0xff00af, 0xef00ff, 0x8900ff, 0x2300ff, 0x003cff, 0x00a2ff, 0x00fff7, 0x00FF91, 0x00FF33, 0x3CFF00, 0x89FF00, 0xF7FF00, 0xFFA200, 0xFF4D00,

};

CRGB leds[NUM_LEDS];

void setup() {

tft.initR(INITR_BLACKTAB);

tft.setRotation(1);

tft.setTextColor(0x0f00);

function (Mode);

MainMenu();

Serial.begin(115200);

FastLED.addLeds < WS2811, DATA_PIN > (leds, NUM_LEDS);

pinMode(Push_ButtonR, INPUT);

pinMode(Push_ButtonL, INPUT);

}

void MainMenu() {

currentScrenn = "MainMenu";

tft.fillScreen(0x00f0);

tft.setTextSize(1);

if (Mode == ChosenMode[0]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 5);

tft.print("1. " + ChosenMode[0]);

if (Mode == ChosenMode[1]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 15);

tft.print("2. " + ChosenMode[1]);

if (Mode == ChosenMode[2]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 25);

tft.print("3. " + ChosenMode[2]);

if (Mode == ChosenMode[3]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 35);

tft.print("4. " + ChosenMode[3]);

if (Mode == ChosenMode[4]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 45);

tft.print("5. " + ChosenMode[4]);

if (Mode == ChosenMode[5]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 55);

tft.print("6. " + ChosenMode[5]);

if (Mode == ChosenMode[6]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 65);

tft.print("7. " + ChosenMode[6]);

if (Mode == ChosenMode[7]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 75);

tft.print("8. " + ChosenMode[7]);

if (Mode == ChosenMode[8]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 85);

tft.print("9. " + ChosenMode[8]);

if (Mode == ChosenMode[9]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 95);

tft.print("10. " + ChosenMode[9]);

if (Mode == ChosenMode[10]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 105);

tft.print("11. " + ChosenMode[10]);

if (Mode == ChosenMode[11]) {

tft.setTextColor(0x0f00);

} else {

tft.setTextColor(0xffff);

}

tft.setCursor(5, 115);

tft.print(ChosenMode[11]);

}

void eraseLeds() {

for (int i = 0; i < NUM_LEDS; i++) {

leds[i] = CRGB(0, 0, 0);

}

FastLED.show();

}

void

function (String Mode) {

if (Mode == "Standard |> L+R button") {

FastLED.setBrightness(BrightnessLevel);

for (int i = 0; i < NUM_LEDS; i++) {

leds[i] = CRGB(r, g, b);

}

FastLED.show();

delay(40);

}

if (Mode == "Rainbow Static") {

FastLED.setBrightness(BrightnessLevel);

for (int i = 0; i < NUM_LEDS; i++) {

leds[i] = CRGB(color_array_for_rainbowMode[i]);

}

FastLED.show();

delay(40);

}

if (Mode == "Rainbow Train") {

eraseLeds();

for (int tr = 0; tr < NUM_LEDS; tr++) {

FastLED.setBrightness(BrightnessLevel);

for (int i = 0; i < 3; i++) {

leds[tr + i] = CRGB(color_array_for_rainbowMode[tr + i]);

}

FastLED.show();

delay(20);

for (int i = 3; i > 0; i--) {

leds[tr - i] = CRGB(0, 0, 0);

}

FastLED.show();

delay(20);

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

}

if (Mode == "Candle") {

FastLED.setBrightness(BrightnessLevel);

for (int i = 0; i < NUM_LEDS; i++) {

leds[i] = CRGB(255, 255, CandlebValue);

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

FastLED.show();

FastLED.setBrightness(CandlebValue);

if (CandlebValue > 90) {

Canndlemode = 0;

}

if (Canndlemode == 0) {

CandlebValue -= 1;

}

if (CandlebValue < 20) {

Canndlemode = 1;

}

if (Canndlemode == 1) {

CandlebValue += 1;

}

delay(5);

}

if (Mode == "Christmas Mystery") {

eraseLeds();

int NOLArr[NUM_LEDS / 2] = {};

for (int i = 0; i < NUM_LEDS / 2; i++) {

int randm_led = random(NUM_LEDS);

NOLArr[i] = randm_led;

leds[randm_led] = CRGB(255, 255, 255);

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

float delTime = 100 / BrightnessLevel;

for (int i = 0; i < BrightnessLevel; i++) {

FastLED.setBrightness(i);

delay(5 * delTime);

FastLED.show();

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

for (int i = BrightnessLevel; i > 1; i--) {

FastLED.setBrightness(i);

delay(5 * delTime);

FastLED.show();

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

FastLED.show();

}

if (Mode == "Blinking Garland") {

int GdArr[] = {

255,

255,

0,

0,

60,

255,

255,

0,

0,

0,

255,

40

};

float delTime = 100 / BrightnessLevel;

for (int i = 0; i < NUM_LEDS; i++) {

if (CGColor == 1) {

leds[i] = CRGB(GdArr[0], GdArr[1], GdArr[2]);

i++;

CGColor++;

}

if (CGColor == 2) {

leds[i] = CRGB(GdArr[3], GdArr[4], GdArr[5]);

i++;

CGColor++;

}

if (CGColor == 3) {

leds[i] = CRGB(GdArr[6], GdArr[7], GdArr[8]);

i++;

CGColor++;

}

if (CGColor == 4) {

leds[i] = CRGB(GdArr[9], GdArr[10], GdArr[11]);

CGColor = 1;

}

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

FastLED.show();

for (int i = 0; i < BrightnessLevel; i++) {

FastLED.setBrightness(i);

delay(10 * delTime);

FastLED.show();

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

for (int i = BrightnessLevel; i > 1; i--) {

FastLED.setBrightness(i);

delay(10 * delTime);

FastLED.show();

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

FastLED.show();

}

if (Mode == "Garland Static") {

FastLED.setBrightness(BrightnessLevel);

int GdArr[] = {

255,

255,

0,

0,

60,

255,

255,

0,

0,

0,

255,

40

};

for (int i = 0; i < NUM_LEDS; i++) {

if (CGColor == 1) {

leds[i] = CRGB(GdArr[0], GdArr[1], GdArr[2]);

i++;

CGColor++;

}

if (CGColor == 2) {

leds[i] = CRGB(GdArr[3], GdArr[4], GdArr[5]);

i++;

CGColor++;

}

if (CGColor == 3) {

leds[i] = CRGB(GdArr[6], GdArr[7], GdArr[8]);

i++;

CGColor++;

}

if (CGColor == 4) {

leds[i] = CRGB(GdArr[9], GdArr[10], GdArr[11]);

CGColor = 1;

}

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

FastLED.show();

}

if (Mode == "September leaves") {

eraseLeds();

int arrAutumnColors[] = {0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,

0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,

0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,

0xff0000, 0x00ff00, 0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,

0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,

0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,

0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,

0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,

0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,

0xff0000, 0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,

0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,

0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,

0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,

0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,0x64FF00,0xff0000,0x00ff00,0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

0x64FF00,

0xff0000,

0x00ff00,

0xffff00,

};

FastLED.setBrightness(BrightnessLevel);

float delTime = 100 / BrightnessLevel;

for (int i = 0; i < NUM_LEDS; i++) {

int randm_led = random(NUM_LEDS);

leds[randm_led] = CRGB(arrAutumnColors[i]);

delay(120);

FastLED.show();

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

for (int i = BrightnessLevel; i > 0; i--) {

FastLED.setBrightness(i);

delay(20 * delTime);

FastLED.show();

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

}

if (Mode == "Blinding light") {

FastLED.setBrightness(BrightnessLevel);

for (int i = 0; i < NUM_LEDS; i++) {

leds[i] = CRGB(255, 255, 255);

FastLED.show();

}

delay(50);

for (int i = 0; i < NUM_LEDS; i++) {

leds[i] = CRGB(0, 0, 0);

FastLED.show();

}

delay(50);

}

if (Mode == "Moonlight") {

FastLED.setBrightness(BrightnessLevel);

for (int i = 0; i < NUM_LEDS; i++) {

leds[i] = CRGB(220, 220, 200);

}

FastLED.show();

float delTime = 100 / BrightnessLevel;

for (int i = BrightnessLevel / 1.15; i < BrightnessLevel; i++) {

FastLED.setBrightness(i);

delay(5 * delTime);

FastLED.show();

}

for (int i = BrightnessLevel; i > BrightnessLevel / 1.15; i--) {

FastLED.setBrightness(i);

delay(5 * delTime);

FastLED.show();

}

delay(40);

}

if (Mode == "Spring") {

eraseLeds();

int arrSpringColors[] = {226, 9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197, 247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,

0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,

26,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,

9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,

9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,

168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,

212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,

9,226,

245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,

205,

245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,

130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,

246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,

107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,

196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,

118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,

40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,

242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,

231,78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,

78,33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,

33,197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,

197,247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,

247,0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,

0,26,255,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,

55,226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,

226,9,67,226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,

9,67,

226,9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,

9,168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,

168,212,9,226,245,205,245,130,246,107,196,118,40,242,231,78,33,197,247,0,26,255,226,9,67,226,9,168,

212,9,226,245,205,245,130,246,107,196,118,40,242,231,8,33,197,247,0, 26, 255,

};

int NOLArr[NUM_LEDS] = {};

FastLED.setBrightness(BrightnessLevel);

float delTime = 100 / BrightnessLevel;

for (int i = 0; i < NUM_LEDS / 1.5; i++) {

int randm_led = random(NUM_LEDS);

leds[randm_led] = CRGB(arrSpringColors[i], arrSpringColors[i + 1], arrSpringColors[i + 2]);

delay(100);

FastLED.show();

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

for (int i = BrightnessLevel; i > 0; i--) {

FastLED.setBrightness(i);

delay(8 * delTime);

FastLED.show();

if (digitalRead(Push_ButtonR) == HIGH || digitalRead(Push_ButtonL) == HIGH) {

break;

return;

}

}

}

if (Mode == "Brightness |> L+R btn") {

FastLED.setBrightness(BrightnessLevel);

for (int i = 0; i < NUM_LEDS; i++) {

leds[i] = CRGB(r, g, b);

}

FastLED.show();

delay(40);

}

}

void loadRGBScreen() {

currentScrenn = "ChangeRGB";

tft.fillScreen(0x0000);

tft.setCursor(10, 5);

tft.print("Press L+R button to choose the next color or exit");

tft.setTextSize(1);

tft.setCursor(15, 64);

tft.setTextColor(0xf000);

tft.print("R:" + String(r));

tft.setCursor(65, 64);

tft.setTextColor(0x0f00);

tft.print("G:" + String(g));

tft.setCursor(115, 64);

tft.setTextColor(0x00f0);

tft.print("B:" + String(b));

tft.setTextColor(0xffff);

tft.setCursor(10, 80);

tft.print("Press LEFT button to lower value, and RIGHT button to upper value");

}

void loadBrightnessScreen() {

tft.fillScreen(0x0000);

tft.setTextColor(0xffff);

tft.setTextSize(1);

tft.setCursor(10, 5);

tft.print("Press L+R button to exit");

tft.setCursor(40, 40);

tft.print("Brightness:" + String(BrightnessLevel));

tft.setCursor(10, 70);

tft.print("Press LEFT button to lower brightness, and RIGHT button to upper brightness");

currentScrenn = "Brightness";

}

void loop() {

Button_StateR = digitalRead(Push_ButtonR);

Button_StateL = digitalRead(Push_ButtonL);

if (Button_StateR == HIGH and Button_StateL == HIGH) {

if (Mode == "Standard |> L+R button") {

if (currentScrenn == "MainMenu") {

loadRGBScreen();

chooseRoGoB = -1;

}

if (currentScrenn == "ChangeRGB") {

chooseRoGoB += 1;

if (chooseRoGoB == 3) {

currentScrenn = "MainMenu";

chooseRoGoB = -1;

ChosenModeInt = 0;

Mode = ChosenMode[ChosenModeInt];

MainMenu();

function (Mode);

}

}

}

if (Mode == "Brightness |> L+R btn") {

int cusc = 0;

if (currentScrenn == "MainMenu") {

cusc = 0;

}

if (currentScrenn == "Brightness") {

cusc = 1;

}

switch (cusc) {

case 0:

loadBrightnessScreen();

break;

case 1:

currentScrenn = "MainMenu";

MainMenu();

function (Mode);

break;

}

}

}

if (Button_StateR == HIGH && Button_StateL == LOW) {

if (currentScrenn == "MainMenu") {

ChosenModeInt += 1;

if (ChosenModeInt == (-1)) {

ChosenModeInt = 11;

}

if (ChosenModeInt == 12) {

ChosenModeInt = 0;

}

Mode = ChosenMode[ChosenModeInt];

Serial.println(Mode);

Serial.println(ChosenMode[ChosenModeInt]);

MainMenu();

function (Mode);

}

if (currentScrenn == "ChangeRGB") {

if (chooseRoGoB == 0) {

r += 2;

if (r > 255) {

r = 0;

}

if (r < 0) {

r = 255;

}

loadRGBScreen();

}

if (chooseRoGoB == 1) {

g += 2;

if (g > 255) {

g = 0;

}

if (g < 0) {

g = 255;

}

loadRGBScreen();

}

if (chooseRoGoB == 2) {

b += 2;

if (b > 255) {

b = 0;

}

if (b < 0) {

b = 255;

}

loadRGBScreen();

}

}

if (currentScrenn == "Brightness") {

BrightnessLevel += 1;

if (BrightnessLevel == 101) {

BrightnessLevel = 0;

}

loadBrightnessScreen();

function (Mode);

}

}

if (Button_StateL == HIGH && Button_StateR == LOW) {

if (currentScrenn == "MainMenu") {

ChosenModeInt -= 1;

if (ChosenModeInt == (-1)) {

ChosenModeInt = 11;

}

if (ChosenModeInt == 12) {

ChosenModeInt = 0;

}

Mode = ChosenMode[ChosenModeInt];

Serial.println(Mode);

Serial.println(ChosenMode[ChosenModeInt]);

MainMenu();

function (Mode);

}

if (currentScrenn == "ChangeRGB") {

if (chooseRoGoB == 0) {

r -= 2;

if (r > 255) {

r = 0;

}

if (r < 0) {

r = 255;

}

loadRGBScreen();

}

if (chooseRoGoB == 1) {

g -= 2;

if (g > 255) {

g = 0;

}

if (g < 0) {

g = 255;

}

loadRGBScreen();

}

if (chooseRoGoB == 2) {

b -= 2;

if (b > 255) {

b = 0;

}

if (b < 0) {

b = 255;

}

loadRGBScreen();

}

}

if (currentScrenn == "Brightness") {

BrightnessLevel -= 1;

if (BrightnessLevel == (-1)) {

BrightnessLevel = 100;

}

loadBrightnessScreen();

function (Mode);

}

}

function (Mode);

delay(100);

}

//This code has a little modification by Northstrix

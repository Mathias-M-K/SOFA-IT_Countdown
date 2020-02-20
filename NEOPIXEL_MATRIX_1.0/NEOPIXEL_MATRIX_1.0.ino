#define FASTLED_ESP8266_NODEMCU_PIN_ORDER

#include <FastLED.h>

#define LED_PIN  3
#define COLOR_ORDER GRB
#define CHIPSET     WS2811
#define BRIGHTNESS 64

const uint8_t kMatrixWidth = 8;
const uint8_t kMatrixHeight = 8;
const bool    kMatrixSerpentineLayout = false;

uint16_t XY( uint8_t x, uint8_t y)
{
  uint16_t i;

  if ( kMatrixSerpentineLayout == false) {
    i = (y * kMatrixWidth) + x;
  }

  if ( kMatrixSerpentineLayout == true) {
    if ( y & 0x01) {
      // Odd rows run backwards
      uint8_t reverseX = (kMatrixWidth - 1) - x;
      i = (y * kMatrixWidth) + reverseX;
    } else {
      // Even rows run forwards
      i = (y * kMatrixWidth) + x;
    }
  }

  return i;
}

#define NUM_LEDS (kMatrixWidth * kMatrixHeight)

CRGB leds_plus_safety_pixel[ NUM_LEDS + 1];
CRGB* const leds( leds_plus_safety_pixel + 1);

uint16_t XYsafe( uint8_t x, uint8_t y)
{
  if ( x >= kMatrixWidth) return -1;
  if ( y >= kMatrixHeight) return -1;
  return XY(x, y);
}
//-------------------------------------------------------------------------------------------------------------------------
/*
   Alt over den her linje skal bare være der, så lad værd at fjerne det <3

   Ellers er det ret ez at bruge skræmene, bare skriv følgende
   leds[ XY(X, Y)]  = CHSV( H, S, V);
   hvor X,Y er kordinaterne på led'erne (hvor 0,0 er nede i højre hjørne)
   H,S,V er Hue, Saturation og lysstyrke
*/
//Arrays til X
int xX[] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
int xY[] = {7, 0, 6, 1, 5, 2, 4, 3, 3, 4, 2, 5, 1, 6, 0, 7};

//Arrays til hjerte
int hjerteX[] = {4, 3, 2, 1, 1, 1, 1, 2, 3, 4, 5, 5, 6, 7, 7, 7, 7, 6, 5};
int hjerteY[] = {0, 1, 2, 3, 4, 5, 6, 7, 7, 6, 7, 7, 7, 6, 5, 4, 3, 2, 1};

//Arrays til M
int mX[] = {5, 5, 5, 5, 4, 3, 3, 3, 3};
int mY[] = {2, 3, 4, 5, 4, 5, 4, 3, 2};

//Arrays til H
int hX[] = {5, 5, 5, 5, 3, 3, 3, 3, 4};
int hY[] = {2, 3, 4, 5, 2, 3, 4, 5, 4};

//Arrays til +
int plusX[] = {4, 4, 4, 5, 4, 3};
int plusY[] = {3, 4, 5, 4, 4, 4};

//Array for the number one
int oneX[] = {8, 7, 6, 5, 6, 6, 6, 6, 7};
int oneY[] = {8, 0, 0, 0, 1, 2, 3, 4, 3};

//Array for the number two
int twoX[] = {11, 5, 6, 7, 7, 7, 6, 5, 5, 5, 6, 7};
int twoY[] = {11, 0, 0, 0, 1, 2, 2, 2, 3, 4, 4, 4};

//Array for the number three
int threeX[] = {11, 7, 6, 5, 5, 5, 6, 7, 5, 5, 6, 7};
int threeY[] = {11, 0, 0, 0, 1, 2, 2, 2, 3, 4, 4, 4};

//Array for the number four
int fourX[] = {9, 5, 5, 5, 5, 5, 6, 7, 7, 7};
int fourY[] = {9, 0, 1, 2, 3, 4, 2, 2, 3, 4};

//Array for the number five
int fiveX[] = {11, 7, 6, 5, 5, 5, 6, 7, 7, 7, 6, 5};
int fiveY[] = {11, 0, 0, 0, 1, 2, 2, 2, 3, 4, 4, 4};

//Array for the number six
int sixX[] = {12, 5, 6, 7, 7, 7, 7, 7, 6, 5, 5, 5, 6};
int sixY[] = {12, 4, 4, 4, 3, 2, 1, 0, 0, 0, 1, 2, 2};

//Array for the number seven
int sevenX[] = {8, 7, 7, 6, 5, 5, 5, 5, 5};
int sevenY[] = {8, 3, 4, 4, 4, 3, 2, 1, 0};

//Array for the number eight
int eightX[] = {13, 5, 6, 7, 7, 7, 7, 7, 6, 5, 5, 5, 5, 6};
int eightY[] = {13, 4, 4, 4, 3, 2, 1, 0, 0, 0, 1, 2, 3, 2};

//Array for the number nine
int nineX[] = {10, 5, 6, 7, 7, 7, 6, 5, 5, 5, 5};
int nineY[] = {10, 4, 4, 4, 3, 2, 2, 2, 3, 1, 0};

//Array for the number zero
int zeroX[] = {12, 5, 6, 7, 7, 7, 7, 7, 6, 5, 5, 5, 5};
int zeroY[] = {12, 4, 4, 4, 3, 2, 1, 0, 0, 0, 1, 2, 3};


void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness( BRIGHTNESS );

  Serial.begin(115200);
  Serial.println("");
  Serial.println("Finished Booting");

}

void loop() {

  FastLED.setBrightness(BRIGHTNESS);

  Serial.println("Writing beginning");
  for (int i = 0; i < 100; i++) {
    writeString(String(i), 0);
    delay(250);
  }

  Serial.println("");
  Serial.println("Done writing");
  delay(5000);
  turnOff();


}

void writeString(String str, int writeDelay) {

  turnOff();

  int lengthOfString = str.length();

  if (lengthOfString == 1) {
    str = "0" + str;
    lengthOfString = 2;
  }

  int offsetValue = 0;


  Serial.println("");
  Serial.print("Lenght: ");
  Serial.println(lengthOfString);

  for (int i = 0; i < lengthOfString; i++) {
    char s = str.charAt(i);

    Serial.print("Char: "); Serial.println(s);
    Serial.print("offset: "); Serial.println(offsetValue);


    if (s == '1') {
      turnOnArray(oneX, oneY, writeDelay, offsetValue);
    } else if (s == '2') {
      turnOnArray(twoX, twoY, writeDelay, offsetValue);
    } else if (s == '3') {
      turnOnArray(threeX, threeY, writeDelay, offsetValue);
    } else if (s == '4') {
      turnOnArray(fourX, fourY, writeDelay, offsetValue);
    } else if (s == '5') {
      turnOnArray(fiveX, fiveY, writeDelay, offsetValue);
    } else if (s == '6') {
      turnOnArray(sixX, sixY, writeDelay, offsetValue);
    } else if (s == '7') {
      turnOnArray(sevenX, sevenY, writeDelay, offsetValue);
    } else if (s == '8') {
      turnOnArray(eightX, eightY, writeDelay, offsetValue);
    } else if (s == '9') {
      turnOnArray(nineX, nineY, writeDelay, offsetValue);
    } else if (s == '0') {
      turnOnArray(zeroX, zeroY, writeDelay, offsetValue);
    } else {
      turnOnArray(xX, xY, writeDelay, offsetValue);
    }
    offsetValue += 4;
  }
  Serial.println("");
}

void turnOnArray(int arrayX[], int arrayY[], int _speed, int offset) {

  int arrayLength = arrayX[0] + 1;

  //Printing arrays to make sure they're correct

  Serial.println("");
  Serial.print("arrayX: ");
  for (int i = 1; i < arrayLength; i++) {
    Serial.print(arrayX[i]);
    Serial.print(", ");
  }
  Serial.println("");
  Serial.print("arrayY: ");
  for (int i = 1; i < arrayLength; i++) {
    Serial.print(arrayY[i]);
    Serial.print(", ");
  }

  Serial.println("");

  for (int i = 1; i < arrayLength; i++) {
    leds[ XY(arrayX[i] - offset, arrayY[i])]  = CHSV( 255, 255, 255);
    FastLED.show();
    delay(_speed);
  }
}

void turnOff() {
  for (int i = 0; i < 8; i++) {
    for (int y = 0; y < 8; y++) {
      leds[ XY(i, y)]  = CHSV( 0, 0, 0);
    }
  }
}

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
int errorX[] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
int errorY[] = {7, 0, 6, 1, 5, 2, 4, 3, 3, 4, 2, 5, 1, 6, 0, 7};

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

//Array for the letter A
int aX[] = {14, 7, 7, 7, 7, 7, 6, 5, 4, 4, 4, 4, 4, 5, 6};
int aY[] = {14, 0, 1, 2, 3, 4, 4, 4, 4, 3, 2, 1, 0, 1, 1};

//Array for the letter B
int bX[] = {13, 7, 7, 7, 7, 7, 6, 5, 4, 5, 6, 4, 5, 6};
int bY[] = {13, 0, 1, 2, 3, 4, 4, 4, 3, 2, 2, 1, 0, 0};

//Array for the letter C
int cX[] = {9, 4, 5, 6, 7, 7, 7, 6, 5, 4};
int cY[] = {9, 1, 0, 0, 1, 2, 3, 4, 4, 3};

//Array for the letter D
int dX[] = {12, 7, 7, 7, 7, 7, 6, 5, 4, 4, 4, 5, 6};
int dY[] = {12, 0, 1, 2, 3, 4, 4, 4, 3, 2, 1, 0, 0};

//Array for the letter E
int eX[] = {13, 4, 5, 6, 7, 7, 7, 6, 5, 7, 7, 6, 5, 4};
int eY[] = {13, 0, 0, 0, 0, 1, 2, 2, 2, 3, 4, 4, 4, 4};

//Array for the letter F
int fX[] = {10, 7, 7, 7, 6, 5, 7, 7, 6, 5, 4};
int fY[] = {10, 0, 1, 2, 2, 2, 3, 4, 4, 4, 4};

//Array for the letter G
int gX[] = {14, 5, 4, 4, 4, 5, 6, 7, 7, 7, 7, 7, 6, 5, 4};
int gY[] = {14, 2, 2, 1, 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4};

//Array for the letter H
int hX[] = {12, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 6, 5};
int hY[] = {12, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 2, 2};

//Array for the letter I
int iX[] = {5, 7, 7, 7, 7, 7};
int iY[] = {5, 0, 1, 2, 3, 4};

//Array for the letter j
int jX[] = {6, 7, 6, 5, 5, 5, 5};
int jY[] = {6, 1, 0, 1, 2, 3, 4};

//Array for the letter k
int kX[] = {10, 7, 7, 7, 7, 7, 6, 5, 4, 5, 4};
int kY[] = {10, 0, 1, 2, 3, 4, 2, 3, 4, 1, 0};

//Array for the letter l
int lX[] = {7, 5, 6, 7, 7, 7, 7, 7};
int lY[] = {7, 0, 0, 0, 1, 2, 3, 4};

//Array for the letter m
int mX[] = {16, 3, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 7, 7};
int mY[] = {16, 0, 1, 2, 3, 4, 4, 3, 3, 2, 3, 4, 4, 3, 2, 1, 0};

//Array for the letter n
int nX[] = {12, 4, 4, 4, 4, 4, 5, 6, 7, 7, 7, 7, 7};
int nY[] = {12, 4, 3, 2, 1, 0, 2, 3, 4, 3, 2, 1, 0};

//Array for the letter o
int oX[] = {10, 4, 4, 4, 5, 6, 7, 7, 7, 6, 5};
int oY[] = {10, 3, 2, 1, 0, 0, 1, 2, 3, 4, 4};

//Array for the letter p
int pX[] = {10, 7, 7, 7, 7, 7, 6, 5, 5, 5, 6};
int pY[] = {10, 0, 1, 2, 3, 4, 4, 4, 3, 2, 2};

//Array for the letter q
int qX[] = {10,5, 5, 7, 7, 7, 6, 5, 5, 5, 6};
int qY[] = {10,0, 1, 2, 3, 4, 4, 4, 3, 2, 2};

//Array for the letter r
int rX[] = {12, 7, 7, 7, 7, 7, 6, 5, 4, 5, 6, 4, 4};
int rY[] = {12, 0, 1, 2, 3, 4, 4, 4, 3, 2, 2, 1, 0};

//Array for the letter s
int sX[] = {11, 7, 6, 5, 5, 5, 6, 7, 7, 7, 6, 5};
int sY[] = {11, 0, 0, 0, 1, 2, 2, 2, 3, 4, 4, 4};

//Array for the letter t
int tX[] = {7, 6, 6, 6, 6, 6, 7, 5};
int tY[] = {7, 0, 1, 2, 3, 4, 4, 4};

//Array for the letter u
int uX[] = {12, 4, 4, 4, 4, 4, 5, 6, 7, 7, 7, 7, 7};
int uY[] = {12, 4, 3, 2, 1, 0, 0, 0, 0, 1, 2, 3, 4};

//Array for the letter v
int vX[] = {9, 5, 5, 5, 5, 6, 7, 7, 7, 7};
int vY[] = {9, 4, 3, 2, 1, 0, 1, 2, 3, 4};

//Array for the letter w
int wX[] = {16, 3, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 7, 7};
int wY[] = {16, 4, 3, 2, 1, 0, 0, 1, 1, 2, 1, 0, 0, 1, 2, 3, 4};

//Array for the letter x
int xX[] = {9, 5, 5, 5, 5, 6, 7, 7, 7, 7};
int xY[] = {9, 4, 3, 1, 0, 2, 0, 1, 3, 4};

//Array for the letter y
int yX[] = {7, 5, 5, 6, 6, 6, 7, 7};
int yY[] = {7, 4, 3, 2, 1, 0, 3, 4};

//Array for the letter z
int zX[] = {9, 7, 6, 5, 5, 6, 7, 7, 6, 5};
int zY[] = {9, 4, 4, 4, 3, 2, 1, 0, 0, 0};

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness( BRIGHTNESS );

  Serial.begin(115200);
  Serial.println("");
  Serial.println("Finished Booting");

}

void loop() {
  FastLED.setBrightness(BRIGHTNESS);

  writeLongString("14 days left");
  delay(200);
}


void writeLongString(String str) {
  int strLength = str.length();

  //getting length in pixels
  int pixelLength = 0;

  for (int i = 0; i <= strLength; i++) {
    pixelLength += getWidth(getXArray(str.charAt(i)));
  }

  int waitTime = 200;
  for (int i = 0; i <= pixelLength + 1; i++) {
    writeString(str, 0, i * -1);
    delay(waitTime);
  }

  for (int i = -(pixelLength + 1); i <= 0; i++) {
    writeString(str, 0, i);
    delay(waitTime);
  }
}

void writeString(String str, int writeDelay, int offsetValue) {

  turnOff();

  int lengthOfString = str.length();

  if (lengthOfString == 1) {
    str = "0" + str;
    lengthOfString = 2;
  }

  for (int i = 0; i < lengthOfString; i++) {
    char s = str.charAt(i);
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
    } else if (s == 'a') {
      turnOnArray(aX, aY, writeDelay, offsetValue);
    } else if (s == 'b') {
      turnOnArray(bX, bY, writeDelay, offsetValue);
    } else if (s == 'c') {
      turnOnArray(cX, cY, writeDelay, offsetValue);
    } else if (s == 'd') {
      turnOnArray(dX, dY, writeDelay, offsetValue);
    } else if (s == 'e') {
      turnOnArray(eX, eY, writeDelay, offsetValue);
    } else if (s == 'f') {
      turnOnArray(fX, fY, writeDelay, offsetValue);
    } else if (s == 'g') {
      turnOnArray(gX, gY, writeDelay, offsetValue);
    } else if (s == 'h') {
      turnOnArray(hX, hY, writeDelay, offsetValue);
    } else if (s == 'i') {
      turnOnArray(iX, iY, writeDelay, offsetValue);
    } else if (s == 'j') {
      turnOnArray(jX, jY, writeDelay, offsetValue);
    } else if (s == 'k') {
      turnOnArray(kX, kY, writeDelay, offsetValue);
    } else if (s == 'l') {
      turnOnArray(lX, lY, writeDelay, offsetValue);
    } else if (s == 'm') {
      turnOnArray(mX, mY, writeDelay, offsetValue);
    } else if (s == 'n') {
      turnOnArray(nX, nY, writeDelay, offsetValue);
    } else if (s == 'o') {
      turnOnArray(oX, oY, writeDelay, offsetValue);
    } else if (s == 'p') {
      turnOnArray(pX, pY, writeDelay, offsetValue);
    } else if (s == 'q') {
      turnOnArray(qX, qY, writeDelay, offsetValue);
    } else if (s == 'r') {
      turnOnArray(rX, rY, writeDelay, offsetValue);
    } else if (s == 's') {
      turnOnArray(sX, sY, writeDelay, offsetValue);
    } else if (s == 't') {
      turnOnArray(tX, tY, writeDelay, offsetValue);
    } else if (s == 'u') {
      turnOnArray(uX, uY, writeDelay, offsetValue);
    } else if (s == 'v') {
      turnOnArray(vX, vY, writeDelay, offsetValue);
    } else if (s == 'w') {
      turnOnArray(wX, wY, writeDelay, offsetValue);
    } else if (s == 'x') {
      turnOnArray(xX, xY, writeDelay, offsetValue);
    } else if (s == 'y') {
      turnOnArray(yX, yY, writeDelay, offsetValue);
    } else if (s == 'z') {
      turnOnArray(zX, zY, writeDelay, offsetValue);
    } else if (isWhitespace(s)) {
      //Do Nothing
    } else {
      turnOnArray(xX, xY, writeDelay, offsetValue);
    }
    
    if(isWhitespace(s)){
      offsetValue += 2;
      continue;
    }
    
    offsetValue += (getWidth(getXArray(s))) + 1;
  }
}

void turnOnArray(int arrayX[], int arrayY[], int _speed, int offset) {

  int arrayLength = arrayX[0];
  
  for (int i = 1; i < arrayLength+1; i++) {

    if (arrayX[i] - offset > 7 || arrayX[i] - offset < 0) {
      continue;
    }

    leds[ XY(arrayX[i] - offset, arrayY[i])]  = CHSV( 255, 255, 200);

    delay(_speed);
  }
  FastLED.show();
}

void turnOff() {
  for (int i = 0; i < 8; i++) {
    for (int y = 0; y < 8; y++) {
      leds[ XY(i, y)]  = CHSV( 0, 0, 0);
    }
  }
}

int getWidth(int c[]) {

  int lowestValue = 7;

  for (int i = 1; i <= c[0]; i++) {
    if (c[i] < lowestValue) {
      lowestValue = c[i];
    }
  }
  return 8 - lowestValue;
}

int* getXArray(char s) {
  if (s == '1') {
    return oneX;
  } else if (s == '2') {
    return twoX;
  } else if (s == '3') {
    return threeX;
  } else if (s == '4') {
    return fourX;
  } else if (s == '5') {
    return fiveX;
  } else if (s == '6') {
    return sixX;
  } else if (s == '7') {
    return sevenX;
  } else if (s == '8') {
    return eightX;
  } else if (s == '9') {
    return nineX;
  } else if (s == '0') {
    return zeroX;
  } else if (s == 'a') {
    return aX;
  } else if (s == 'b') {
    return bX;
  } else if (s == 'c') {
    return cX;
  } else if (s == 'd') {
    return dX;
  } else if (s == 'e') {
    return eX;
  } else if (s == 'f') {
    return fX;
  } else if (s == 'g') {
    return gX;
  } else if (s == 'h') {
    return hX;
  } else if (s == 'i') {
    return iX;
  } else if (s == 'j') {
    return jX;
  } else if (s == 'k') {
    return kX;
  } else if (s == 'l') {
    return lX;
  } else if (s == 'm') {
    return mX;
  } else if (s == 'n') {
    return nX;
  } else if (s == 'o') {
    return oX;
  } else if (s == 'p') {
    return pX;
  } else if (s == 'q') {
    return qX;
  } else if (s == 'r') {
    return rX;
  } else if (s == 's') {
    return sX;
  } else if (s == 't') {
    return tX;
  } else if (s == 'u') {
    return uX;
  } else if (s == 'v') {
    return vX;
  } else if (s == 'w') {
    return wX;
  } else if (s == 'x') {
    return xX;
  } else if (s == 'y') {
    return yX;
  } else if (s == 'z') {
    return zX;
  } else {
    return xX;
  }
}

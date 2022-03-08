#include <FastLED.h>
#include <SoftwareSerial.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Params for width and height
const uint8_t kMatrixWidth = 11;
const uint8_t kMatrixHeight = 27;

#define OCTAVE          1
#define OCT_NORM        0
#define FHT_N           256
#define LED_PIN         5
#define LED_TYPE        WS2811
#define COLOR_ORDER     GRB
#define NUM_LEDS        (kMatrixWidth * kMatrixHeight)
#define PIXEL_PIN       5    // Data Pin of Led strip 
#define PIXEL_COUNT     30   // Number of LEDs in the strip
#define BRIGHTNESS      255   // use 96 for medium brightness
#define SPEED           50    // Speed of each Color Transition (in ms)
#define IMMEDIATELY     0    // Transition happen instantly
#define RAINBOW_SPEED   50    // Rainbow Transition speed

bool offOld = LOW;
bool WhiteOld = LOW;
bool RedOld = LOW;
bool GreenOld = LOW;
bool BlueOld = LOW;
bool TopazOld = LOW;
bool LilacOld = LOW;
bool RainbowOld = LOW;
bool rgbOld = LOW;
int  showType = 0;

int noise[] = {204, 198, 100, 85, 85, 80, 80, 80};
float noise_fact[] = {15, 7, 1.5, 1, 1.2, 1.4, 1.7, 3}; // noise level determined by playing pink noise and seeing levels [trial and error]{204,188,68,73,150,98,88,68}
float noise_fact_adj[] = {15, 7, 1.5, 1, 1.2, 1.4, 1.7, 3}; // noise level determined by playing pink noise and seeing levels [trial and error]{204,188,68,73,150,98,88,68}

SoftwareSerial BT(7, 8);  // TX, RX of the Bluetooth Module
#include <FHT.h>

CRGB leds[NUM_LEDS];

int counter2 = 0;

void setup() {
  // put your setup code here, to run once:
  BT.begin(9600);
  delay(10000);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness (255);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  ADCSRA = 0xe5; // set the adc to free running mode
  ADMUX = 0x40; // use adc0
  DIDR0 = 0x01; // turn off the digital input for adc0
}

char a;

void loop() {
  // put your main code here, to run repeatedly:
  bool off = LOW;
  bool White = LOW;
  bool Blue = LOW;
  bool Red = LOW;
  bool Green = LOW;
  bool Topaz = LOW;
  bool Lilac = LOW;
  bool Rainbow = LOW;
  bool rgb = LOW;
  bool ende;

  if (BT.available())
  {
    a = (char)BT.read();

    // turns off
    if (a == 'o')
    {
      off = HIGH;
      BT.println("");
    }
    else
    {
      off = LOW;
    }

    // case 1
    if (a == 'w')
    {
      White = HIGH;
      BT.println("");
    }
    else
    {
      White = LOW;
    }

    // case 2
    if (a == 'b')
    {
      Blue = HIGH;
      BT.println("");
    }
    else
    {
      Blue = LOW;
    }

    // case 3
    if (a == 'p')
    {
      Red = HIGH;
      BT.println("");
    }
    else
    {
      Red = LOW;
    }

    // case 4
    if (a == 'g')
    {
      Green = HIGH;
      BT.println("");
    }
    else
    {
      Green = LOW;
    }

    // case 5
    if (a == 't')
    {
      Topaz = HIGH;
      BT.println("");
    }
    else
    {
      Topaz = LOW;
    }

    // case 6
    if (a == 'l')
    {
      Lilac = HIGH;
      BT.println("");
    }
    else
    {
      Lilac = LOW;
    }

    // case 7
    if (a == 'r')
    {
      Rainbow = HIGH;
      BT.println("");
    }
    else
    {
      Rainbow = LOW;
    }

    // case 8
    if (a == 'k')
    {
      rgb = HIGH;
      BT.println("");
    }
    else
    {
      rgb = LOW;
    }
  }



  if (off == LOW && offOld == HIGH)
  {
    delay(20);

    if (off == LOW)
    {
      showType = 0  ;

      startShow(showType);
    }
  }


  if (White == LOW && WhiteOld == HIGH)
  {
    delay(20);

    if (White == LOW)
    {
      showType = 1  ;

      startShow(showType);
    }
  }


  if (Blue == LOW && BlueOld == HIGH)
  {
    delay(20);

    if (Blue == LOW)
    {
      showType = 2  ;

      startShow(showType);
    }
  }


  if (Red == LOW && RedOld == HIGH)
  {
    delay(20);

    if (Red == LOW)
    {
      showType = 3  ;

      startShow(showType);
    }
  }


  if (Green == LOW && GreenOld == HIGH)
  {
    delay(20);

    if (Green == LOW)
    {
      showType = 4  ;

      startShow(showType);
    }
  }


  if (Topaz == LOW && TopazOld == HIGH)
  {
    delay(20);

    if (Topaz == LOW)
    {
      showType = 5  ;

      startShow(showType);
    }
  }


  if (Lilac == LOW && LilacOld == HIGH)
  {
    delay(20);

    if (Lilac == LOW)
    {
      showType = 6  ;

      startShow(showType);
    }
  }


  if (Rainbow == LOW && RainbowOld == HIGH)
  {
    delay(20);

    if (Rainbow == LOW)
    {
      showType = 7  ;

      startShow(showType);
    }
  }


  if (rgb == LOW && rgbOld == HIGH)
  {
    delay(20);

    if (rgb == LOW)
    {
      showType = 8  ;

      startShow(showType);
    }
  }


  WhiteOld = White;
  RedOld = Red;
  BlueOld = Blue;
  GreenOld = Green;
  TopazOld = Topaz;
  LilacOld = Lilac;
  offOld = off;
  RainbowOld = Rainbow;
  rgbOld = rgb;
}


void startShow(int i) {
  switch (i) {
    case 0:
      break;

    case 1:
      Normal();
      break;

    case 2:
      goodjob();
      break;

    case 3:
      kevinisstupidandjenniferissmart();
      break;

    case 4:
      iamgroot();
      break;

    case 5:
      pineapple();
      break;

    case 6:
      idk();
      break;

    case 7:
      boba();
      break;

    case 8:
      sploosh();
      break;
  }
}


void Normal()
{
  int prev_j[8];
  int beat = 0;
  int prev_oct_j;
  int counter = 0;
  int prev_beat = 0;
  int led_index = 0;
  int saturation = 0;
  int saturation_prev = 0;
  int brightness = 0;
  int brightness_prev = 0;

  while (1) { // reduces jitter

    if (BT.available()) // turns off lights if user inputs 'o'
    {
      a = (char)BT.read();

      if (a == 'o')
      {
        break;
      }
    }

    cli();  // UDRE interrupt slows this way down on arduino1.0

    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_octave(); // take the output of the fht  fht_mag_log()

    // every 50th loop, adjust the volume accourding to the value on A2 (Pot)
    if (counter >= 50) {
      ADMUX = 0x40 | (1 & 0x07); // set admux to look at Analogpin A1 - Master Volume


      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      delay(1000);
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      float master_volume = (k + 0.1) / 1000 + .5; // so the valu will be between ~0.5 and 1.5
      // Serial.println (master_volume);


      for (int i = 1; i < 8; i++) {
        noise_fact_adj[i] = noise_fact[i] * master_volume;
      }

      ADMUX = 0x40 | (0 & 0x07); // set admux back to look at A0 analog pin (to read the microphone input
      counter = 0;
    }

    sei();
    counter++;


    // End of Fourier Transform code - output is stored in fht_oct_out[i].

    // i=0-7 frequency (octave) bins (don't use 0 or 1), fht_oct_out[1]= amplitude of frequency for bin 1
    // for loop a) removes background noise average and takes absolute value b) low / high pass filter as still very noisy
    // c) maps amplitude of octave to a colour between blue and red d) sets pixel colour to amplitude of each frequency (octave)

    for (int i = 1; i < 8; i++) {  // goes through each octave. skip the first 1, which is not useful

      int j;
      j = (fht_oct_out[i] - noise[i]); // take the pink noise average level out, take the asbolute value to avoid negative numbers
      if (j < 10) {
        j = 0;
      }
      j = j * noise_fact_adj[i];

      if (j < 10) {
        j = 0;
      }
      else {
        j = j * noise_fact_adj[i];
        if (j > 180) {
          if (i >= 7) {
            beat += 2;
          }
          else {
            beat += 1;
          }
        }
        j = j / 30;
        j = j * 30; // (force it to more discrete values)
      }

      prev_j[i] = j;

      //     Serial.print(j);
      //     Serial.print(" ");


      // this fills in 11 LED's with interpolated values between each of the 8 OCT values
      if (i >= 2) {
        led_index = 2 * i - 3;
        prev_oct_j = (j + prev_j[i - 1]) / 2;

        saturation = constrain(j + 30, 0, 255);
        saturation_prev = constrain(prev_oct_j + 30, 0, 255);
        brightness = constrain(j, 0, 255);
        brightness_prev = constrain(prev_oct_j, 0, 255);
        if (brightness == 255) {
          saturation = 50;
          brightness = 200;
        }
        if (brightness_prev == 255) {
          saturation_prev = 50;
          brightness_prev = 200;
        }


        for (uint8_t y = 0; y < kMatrixHeight; y++) {
          leds[XY(led_index - 1, y)] = CHSV(j + y * 30, saturation, brightness);
          if (i > 2) {
            prev_oct_j = (j + prev_j[i - 1]) / 2;
            leds[ XY(led_index - 2, y)] = CHSV(prev_oct_j + y * 30, saturation_prev, brightness_prev);
          }
        }
      }
    }



    if (beat >= 7) {
      fill_solid(leds, NUM_LEDS, CRGB::Gray);
      FastLED.setBrightness(150);


      //    FastLED.setBrightness(200);

    }
    else {
      if (prev_beat != beat) {
        FastLED.setBrightness(40 + beat * beat * 5);
        prev_beat = beat;
      }

    }

    FastLED.show();
    if (beat) {
      counter2 += ((beat + 4) / 2 - 2);
      if (counter2 < 0) {
        counter2 = 1000;
      }
      if (beat > 3 && beat < 7) {
        FastLED.delay (20);
      }
      beat = 0;
    }

    // Serial.println();
  }
}


void goodjob()
{
  int prev_j[8];
  int beat = 0;
  int prev_oct_j;
  int counter = 0;
  int prev_beat = 0;
  int led_index = 0;
  int saturation = 0;
  int saturation_prev = 0;
  int brightness = 0;
  int brightness_prev = 0;

  while (1) { // reduces jitter

    if (BT.available())
    {
      a = (char)BT.read();

      if (a == 'o')
      {
        break;
      }
    }

    cli();  // UDRE interrupt slows this way down on arduino1.0

    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_octave(); // take the output of the fht  fht_mag_log()

    // every 50th loop, adjust the volume accourding to the value on A2 (Pot)
    if (counter >= 50) {
      ADMUX = 0x40 | (1 & 0x07); // set admux to look at Analogpin A1 - Master Volume


      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      delay(1000);
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      float master_volume = (k + 0.1) / 1000 + .5; // so the valu will be between ~0.5 and 1.5
      // Serial.println (master_volume);


      for (int i = 1; i < 8; i++) {
        noise_fact_adj[i] = noise_fact[i] * master_volume;
      }

      ADMUX = 0x40 | (0 & 0x07); // set admux back to look at A0 analog pin (to read the microphone input
      counter = 0;
    }

    sei();
    counter++;


    // End of Fourier Transform code - output is stored in fht_oct_out[i].

    // i=0-7 frequency (octave) bins (don't use 0 or 1), fht_oct_out[1]= amplitude of frequency for bin 1
    // for loop a) removes background noise average and takes absolute value b) low / high pass filter as still very noisy
    // c) maps amplitude of octave to a colour between blue and red d) sets pixel colour to amplitude of each frequency (octave)

    for (int i = 1; i < 8; i++) {  // goes through each octave. skip the first 1, which is not useful

      int j;
      j = (fht_oct_out[i] - noise[i]); // take the pink noise average level out, take the asbolute value to avoid negative numbers
      if (j < 10) {
        j = 0;
      }
      j = j * noise_fact_adj[i];

      if (j < 10) {
        j = 0;
      }
      else {
        j = j * noise_fact_adj[i];
        if (j > 180) {
          if (i >= 7) {
            beat += 2;
          }
          else {
            beat += 1;
          }
        }
        j = j / 30;
        j = j * 30; // (force it to more discrete values)
      }

      prev_j[i] = j;

      //     Serial.print(j);
      //     Serial.print(" ");


      // this fills in 11 LED's with interpolated values between each of the 8 OCT values
      if (i >= 2) {
        led_index = 2 * i - 3;
        prev_oct_j = (j + prev_j[i - 1]) / 2;

        saturation = constrain(j + 30, 0, 255);
        saturation_prev = constrain(prev_oct_j + 30, 0, 255);
        brightness = constrain(j, 0, 255);
        brightness_prev = constrain(prev_oct_j, 0, 255);
        if (brightness == 255) {
          saturation = 50;
          brightness = 200;
        }
        if (brightness_prev == 255) {
          saturation_prev = 50;
          brightness_prev = 200;
        }


        for (uint8_t y = 0; y < kMatrixHeight; y++) {
          leds[XY(led_index - 1, y)] = CHSV((j + y * 30) % 85 + 127, saturation, brightness);
          if (i > 2) {
            prev_oct_j = (j + prev_j[i - 1]) / 2;
            leds[ XY(led_index - 2, y)] = CHSV((prev_oct_j + y * 30) % 85 + 127, saturation_prev, brightness_prev);
          }
        }
      }
    }



    if (beat >= 7) {
      fill_solid(leds, NUM_LEDS, CRGB::Gray);
      FastLED.setBrightness(150);


      //    FastLED.setBrightness(200);

    }
    else {
      if (prev_beat != beat) {
        FastLED.setBrightness(40 + beat * beat * 5);
        prev_beat = beat;
      }

    }

    FastLED.show();
    if (beat) {
      counter2 += ((beat + 4) / 2 - 2);
      if (counter2 < 0) {
        counter2 = 1000;
      }
      if (beat > 3 && beat < 7) {
        FastLED.delay (20);
      }
      beat = 0;
    }

    // Serial.println();
  }
}


void kevinisstupidandjenniferissmart()
{
  int prev_j[8];
  int beat = 0;
  int prev_oct_j;
  int counter = 0;
  int prev_beat = 0;
  int led_index = 0;
  int saturation = 0;
  int saturation_prev = 0;
  int brightness = 0;
  int brightness_prev = 0;

  while (1) { // reduces jitter

    if (BT.available())
    {
      a = (char)BT.read();

      if (a == 'o')
      {
        break;
      }
    }

    cli();  // UDRE interrupt slows this way down on arduino1.0

    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_octave(); // take the output of the fht  fht_mag_log()

    // every 50th loop, adjust the volume accourding to the value on A2 (Pot)
    if (counter >= 50) {
      ADMUX = 0x40 | (1 & 0x07); // set admux to look at Analogpin A1 - Master Volume


      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      delay(1000);
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      float master_volume = (k + 0.1) / 1000 + .5; // so the valu will be between ~0.5 and 1.5
      // Serial.println (master_volume);


      for (int i = 1; i < 8; i++) {
        noise_fact_adj[i] = noise_fact[i] * master_volume;
      }

      ADMUX = 0x40 | (0 & 0x07); // set admux back to look at A0 analog pin (to read the microphone input
      counter = 0;
    }

    sei();
    counter++;


    // End of Fourier Transform code - output is stored in fht_oct_out[i].

    // i=0-7 frequency (octave) bins (don't use 0 or 1), fht_oct_out[1]= amplitude of frequency for bin 1
    // for loop a) removes background noise average and takes absolute value b) low / high pass filter as still very noisy
    // c) maps amplitude of octave to a colour between blue and red d) sets pixel colour to amplitude of each frequency (octave)

    for (int i = 1; i < 8; i++) {  // goes through each octave. skip the first 1, which is not useful

      int j;
      j = (fht_oct_out[i] - noise[i]); // take the pink noise average level out, take the asbolute value to avoid negative numbers
      if (j < 10) {
        j = 0;
      }
      j = j * noise_fact_adj[i];

      if (j < 10) {
        j = 0;
      }
      else {
        j = j * noise_fact_adj[i];
        if (j > 180) {
          if (i >= 7) {
            beat += 2;
          }
          else {
            beat += 1;
          }
        }
        j = j / 30;
        j = j * 30; // (force it to more discrete values)
      }

      prev_j[i] = j;

      //     Serial.print(j);
      //     Serial.print(" ");


      // this fills in 11 LED's with interpolated values between each of the 8 OCT values
      if (i >= 2) {
        led_index = 2 * i - 3;
        prev_oct_j = (j + prev_j[i - 1]) / 2;

        saturation = constrain(j + 30, 0, 255);
        saturation_prev = constrain(prev_oct_j + 30, 0, 255);
        brightness = constrain(j, 0, 255);
        brightness_prev = constrain(prev_oct_j, 0, 255);
        if (brightness == 255) {
          saturation = 50;
          brightness = 200;
        }
        if (brightness_prev == 255) {
          saturation_prev = 50;
          brightness_prev = 200;
        }


        for (uint8_t y = 0; y < kMatrixHeight; y++) {
          leds[XY(led_index - 1, y)] = CHSV((j + y * 30) % 60 + 195, saturation, brightness);
          if (i > 2) {
            prev_oct_j = (j + prev_j[i - 1]) / 2;
            leds[ XY(led_index - 2, y)] = CHSV((prev_oct_j + y * 30) % 60 + 195, saturation_prev, brightness_prev);
          }
        }
      }
    }



    if (beat >= 7) {
      fill_solid(leds, NUM_LEDS, CRGB::Gray);
      FastLED.setBrightness(150);


      //    FastLED.setBrightness(200);

    }
    else {
      if (prev_beat != beat) {
        FastLED.setBrightness(40 + beat * beat * 5);
        prev_beat = beat;
      }

    }

    FastLED.show();
    if (beat) {
      counter2 += ((beat + 4) / 2 - 2);
      if (counter2 < 0) {
        counter2 = 1000;
      }
      if (beat > 3 && beat < 7) {
        FastLED.delay (20);
      }
      beat = 0;
    }

    // Serial.println();
  }
}

void pineapple()
{
  int prev_j[8];
  int beat = 0;
  int prev_oct_j;
  int counter = 0;
  int prev_beat = 0;
  int led_index = 0;
  int saturation = 0;
  int saturation_prev = 0;
  int brightness = 0;
  int brightness_prev = 0;

  while (1) { // reduces jitter

    if (BT.available())
    {
      a = (char)BT.read();

      if (a == 'o')
      {
        break;
      }
    }

    cli();  // UDRE interrupt slows this way down on arduino1.0

    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_octave(); // take the output of the fht  fht_mag_log()

    // every 50th loop, adjust the volume accourding to the value on A2 (Pot)
    if (counter >= 50) {
      ADMUX = 0x40 | (1 & 0x07); // set admux to look at Analogpin A1 - Master Volume


      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      delay(1000);
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      float master_volume = (k + 0.1) / 1000 + .5; // so the valu will be between ~0.5 and 1.5
      // Serial.println (master_volume);


      for (int i = 1; i < 8; i++) {
        noise_fact_adj[i] = noise_fact[i] * master_volume;
      }

      ADMUX = 0x40 | (0 & 0x07); // set admux back to look at A0 analog pin (to read the microphone input
      counter = 0;
    }

    sei();
    counter++;


    // End of Fourier Transform code - output is stored in fht_oct_out[i].

    // i=0-7 frequency (octave) bins (don't use 0 or 1), fht_oct_out[1]= amplitude of frequency for bin 1
    // for loop a) removes background noise average and takes absolute value b) low / high pass filter as still very noisy
    // c) maps amplitude of octave to a colour between blue and red d) sets pixel colour to amplitude of each frequency (octave)

    for (int i = 1; i < 8; i++) {  // goes through each octave. skip the first 1, which is not useful

      int j;
      j = (fht_oct_out[i] - noise[i]); // take the pink noise average level out, take the asbolute value to avoid negative numbers
      if (j < 10) {
        j = 0;
      }
      j = j * noise_fact_adj[i];

      if (j < 10) {
        j = 0;
      }
      else {
        j = j * noise_fact_adj[i];
        if (j > 180) {
          if (i >= 7) {
            beat += 2;
          }
          else {
            beat += 1;
          }
        }
        j = j / 30;
        j = j * 30; // (force it to more discrete values)
      }

      prev_j[i] = j;

      //     Serial.print(j);
      //     Serial.print(" ");


      // this fills in 11 LED's with interpolated values between each of the 8 OCT values
      if (i >= 2) {
        led_index = 2 * i - 3;
        prev_oct_j = (j + prev_j[i - 1]) / 2;

        saturation = constrain(j + 30, 0, 255);
        saturation_prev = constrain(prev_oct_j + 30, 0, 255);
        brightness = constrain(j, 0, 255);
        brightness_prev = constrain(prev_oct_j, 0, 255);
        if (brightness == 255) {
          saturation = 50;
          brightness = 200;
        }
        if (brightness_prev == 255) {
          saturation_prev = 50;
          brightness_prev = 200;
        }


        for (uint8_t y = 0; y < kMatrixHeight; y++) {
          leds[XY(led_index - 1, y)] = CHSV((j + y * 30) % 71 + 57, saturation, brightness);
          if (i > 2) {
            prev_oct_j = (j + prev_j[i - 1]) / 2;
            leds[ XY(led_index - 2, y)] = CHSV((prev_oct_j + y * 30) % 71 + 57, saturation_prev, brightness_prev);
          }
        }
      }
    }



    if (beat >= 7) {
      fill_solid(leds, NUM_LEDS, CRGB::Gray);
      FastLED.setBrightness(150);


      //    FastLED.setBrightness(200);

    }
    else {
      if (prev_beat != beat) {
        FastLED.setBrightness(40 + beat * beat * 5);
        prev_beat = beat;
      }

    }

    FastLED.show();
    if (beat) {
      counter2 += ((beat + 4) / 2 - 2);
      if (counter2 < 0) {
        counter2 = 1000;
      }
      if (beat > 3 && beat < 7) {
        FastLED.delay (20);
      }
      beat = 0;
    }

    // Serial.println();
  }
}


void iamgroot()
{
  int prev_j[8];
  int beat = 0;
  int prev_oct_j;
  int counter = 0;
  int prev_beat = 0;
  int led_index = 0;
  int saturation = 0;
  int saturation_prev = 0;
  int brightness = 0;
  int brightness_prev = 0;

  while (1) { // reduces jitter

    if (BT.available())
    {
      a = (char)BT.read();

      if (a == 'o')
      {
        break;
      }
    }

    cli();  // UDRE interrupt slows this way down on arduino1.0

    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_octave(); // take the output of the fht  fht_mag_log()

    // every 50th loop, adjust the volume accourding to the value on A2 (Pot)
    if (counter >= 50) {
      ADMUX = 0x40 | (1 & 0x07); // set admux to look at Analogpin A1 - Master Volume


      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      delay(1000);
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      float master_volume = (k + 0.1) / 1000 + .5; // so the valu will be between ~0.5 and 1.5
      // Serial.println (master_volume);


      for (int i = 1; i < 8; i++) {
        noise_fact_adj[i] = noise_fact[i] * master_volume;
      }

      ADMUX = 0x40 | (0 & 0x07); // set admux back to look at A0 analog pin (to read the microphone input
      counter = 0;
    }

    sei();
    counter++;


    // End of Fourier Transform code - output is stored in fht_oct_out[i].

    // i=0-7 frequency (octave) bins (don't use 0 or 1), fht_oct_out[1]= amplitude of frequency for bin 1
    // for loop a) removes background noise average and takes absolute value b) low / high pass filter as still very noisy
    // c) maps amplitude of octave to a colour between blue and red d) sets pixel colour to amplitude of each frequency (octave)

    for (int i = 1; i < 8; i++) {  // goes through each octave. skip the first 1, which is not useful

      int j;
      j = (fht_oct_out[i] - noise[i]); // take the pink noise average level out, take the asbolute value to avoid negative numbers
      if (j < 10) {
        j = 0;
      }
      j = j * noise_fact_adj[i];

      if (j < 10) {
        j = 0;
      }
      else {
        j = j * noise_fact_adj[i];
        if (j > 180) {
          if (i >= 7) {
            beat += 2;
          }
          else {
            beat += 1;
          }
        }
        j = j / 30;
        j = j * 30; // (force it to more discrete values)
      }

      prev_j[i] = j;

      //     Serial.print(j);
      //     Serial.print(" ");


      // this fills in 11 LED's with interpolated values between each of the 8 OCT values
      if (i >= 2) {
        led_index = 2 * i - 3;
        prev_oct_j = (j + prev_j[i - 1]) / 2;

        saturation = constrain(j + 30, 0, 255);
        saturation_prev = constrain(prev_oct_j + 30, 0, 255);
        brightness = constrain(j, 0, 255);
        brightness_prev = constrain(prev_oct_j, 0, 255);
        if (brightness == 255) {
          saturation = 50;
          brightness = 200;
        }
        if (brightness_prev == 255) {
          saturation_prev = 50;
          brightness_prev = 200;
        }


        for (uint8_t y = 0; y < kMatrixHeight; y++) {
          leds[XY(led_index - 1, y)] = CHSV((j + y * 30) % 60, saturation, brightness);
          if (i > 2) {
            prev_oct_j = (j + prev_j[i - 1]) / 2;
            leds[ XY(led_index - 2, y)] = CHSV((prev_oct_j + y * 30) % 60, saturation_prev, brightness_prev);
          }
        }
      }
    }



    if (beat >= 7) {
      fill_solid(leds, NUM_LEDS, CRGB::Gray);
      FastLED.setBrightness(150);


      //    FastLED.setBrightness(200);

    }
    else {
      if (prev_beat != beat) {
        FastLED.setBrightness(40 + beat * beat * 5);
        prev_beat = beat;
      }

    }

    FastLED.show();
    if (beat) {
      counter2 += ((beat + 4) / 2 - 2);
      if (counter2 < 0) {
        counter2 = 1000;
      }
      if (beat > 3 && beat < 7) {
        FastLED.delay (20);
      }
      beat = 0;
    }

    // Serial.println();
  }
}


void idk()
{
  int prev_j[8];
  int beat = 0;
  int prev_oct_j;
  int counter = 0;
  int prev_beat = 0;
  int led_index = 0;
  int saturation = 0;
  int saturation_prev = 0;
  int brightness = 0;
  int brightness_prev = 0;

  while (1) { // reduces jitter

    if (BT.available()) // turns off lights if user inputs 'o'
    {
      a = (char)BT.read();

      if (a == 'o')
      {
        break;
      }
    }

    cli();  // UDRE interrupt slows this way down on arduino1.0

    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_octave(); // take the output of the fht  fht_mag_log()

    // every 50th loop, adjust the volume accourding to the value on A2 (Pot)
    if (counter >= 50) {
      ADMUX = 0x40 | (1 & 0x07); // set admux to look at Analogpin A1 - Master Volume


      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      delay(1000);
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      float master_volume = (k + 0.1) / 1000 + .5; // so the valu will be between ~0.5 and 1.5
      // Serial.println (master_volume);


      for (int i = 1; i < 8; i++) {
        noise_fact_adj[i] = noise_fact[i] * master_volume;
      }

      ADMUX = 0x40 | (0 & 0x07); // set admux back to look at A0 analog pin (to read the microphone input
      counter = 0;
    }

    sei();
    counter++;


    // End of Fourier Transform code - output is stored in fht_oct_out[i].

    // i=0-7 frequency (octave) bins (don't use 0 or 1), fht_oct_out[1]= amplitude of frequency for bin 1
    // for loop a) removes background noise average and takes absolute value b) low / high pass filter as still very noisy
    // c) maps amplitude of octave to a colour between blue and red d) sets pixel colour to amplitude of each frequency (octave)

    for (int i = 1; i < 8; i++) {  // goes through each octave. skip the first 1, which is not useful

      int j;
      j = (fht_oct_out[i] - noise[i]); // take the pink noise average level out, take the asbolute value to avoid negative numbers
      if (j < 10) {
        j = 0;
      }
      j = j * noise_fact_adj[i];

      if (j < 10) {
        j = 0;
      }
      else {
        j = j * noise_fact_adj[i];
        if (j > 180) {
          if (i >= 7) {
            beat += 2;
          }
          else {
            beat += 1;
          }
        }
        j = j / 30;
        j = j * 30; // (force it to more discrete values)
      }

      prev_j[i] = j;

      //     Serial.print(j);
      //     Serial.print(" ");


      // this fills in 11 LED's with interpolated values between each of the 8 OCT values
      if (i >= 2) {
        led_index = 2 * i - 3;
        prev_oct_j = (j + prev_j[i - 1]) / 2;

        saturation = constrain(j + 30, 0, 255);
        saturation_prev = constrain(prev_oct_j + 30, 0, 255);
        brightness = constrain(j, 0, 255);
        brightness_prev = constrain(prev_oct_j, 0, 255);
        if (brightness == 255) {
          saturation = 50;
          brightness = 200;
        }
        if (brightness_prev == 255) {
          saturation_prev = 50;
          brightness_prev = 200;
        }


        for (uint8_t y = 0; y < kMatrixHeight; y++) {
          leds[XY(led_index - 1, y)] = CHSV((j + y * 30) % 99 + 155, saturation, brightness);
          if (i > 2) {
            prev_oct_j = (j + prev_j[i - 1]) / 2;
            leds[ XY(led_index - 2, y)] = CHSV((prev_oct_j + y * 30) % 99 + 155, saturation_prev, brightness_prev);
          }
        }
      }
    }



    if (beat >= 7) {
      fill_solid(leds, NUM_LEDS, CRGB::Gray);
      FastLED.setBrightness(150);


      //    FastLED.setBrightness(200);

    }
    else {
      if (prev_beat != beat) {
        FastLED.setBrightness(40 + beat * beat * 5);
        prev_beat = beat;
      }

    }

    FastLED.show();
    if (beat) {
      counter2 += ((beat + 4) / 2 - 2);
      if (counter2 < 0) {
        counter2 = 1000;
      }
      if (beat > 3 && beat < 7) {
        FastLED.delay (20);
      }
      beat = 0;
    }

    // Serial.println();
  }
}


void boba()
{
  int prev_j[8];
  int beat = 0;
  int prev_oct_j;
  int counter = 0;
  int prev_beat = 0;
  int led_index = 0;
  int saturation = 0;
  int saturation_prev = 0;
  int brightness = 0;
  int brightness_prev = 0;

  while (1) { // reduces jitter

    if (BT.available()) // turns off lights if user inputs 'o'
    {
      a = (char)BT.read();

      if (a == 'o')
      {
        break;
      }
    }

    cli();  // UDRE interrupt slows this way down on arduino1.0

    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_octave(); // take the output of the fht  fht_mag_log()

    // every 50th loop, adjust the volume accourding to the value on A2 (Pot)
    if (counter >= 50) {
      ADMUX = 0x40 | (1 & 0x07); // set admux to look at Analogpin A1 - Master Volume


      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      delay(1000);
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      float master_volume = (k + 0.1) / 1000 + .5; // so the valu will be between ~0.5 and 1.5
      // Serial.println (master_volume);


      for (int i = 1; i < 8; i++) {
        noise_fact_adj[i] = noise_fact[i] * master_volume;
      }

      ADMUX = 0x40 | (0 & 0x07); // set admux back to look at A0 analog pin (to read the microphone input
      counter = 0;
    }

    sei();
    counter++;


    // End of Fourier Transform code - output is stored in fht_oct_out[i].

    // i=0-7 frequency (octave) bins (don't use 0 or 1), fht_oct_out[1]= amplitude of frequency for bin 1
    // for loop a) removes background noise average and takes absolute value b) low / high pass filter as still very noisy
    // c) maps amplitude of octave to a colour between blue and red d) sets pixel colour to amplitude of each frequency (octave)

    for (int i = 1; i < 8; i++) {  // goes through each octave. skip the first 1, which is not useful

      int j;
      j = (fht_oct_out[i] - noise[i]); // take the pink noise average level out, take the asbolute value to avoid negative numbers
      if (j < 10) {
        j = 0;
      }
      j = j * noise_fact_adj[i];

      if (j < 10) {
        j = 0;
      }
      else {
        j = j * noise_fact_adj[i];
        if (j > 180) {
          if (i >= 7) {
            beat += 2;
          }
          else {
            beat += 1;
          }
        }
        j = j / 30;
        j = j * 30; // (force it to more discrete values)
      }

      prev_j[i] = j;

      //     Serial.print(j);
      //     Serial.print(" ");


      // this fills in 11 LED's with interpolated values between each of the 8 OCT values
      if (i >= 2) {
        led_index = 2 * i - 3;
        prev_oct_j = (j + prev_j[i - 1]) / 2;

        saturation = constrain(j + 30, 0, 255);
        saturation_prev = constrain(prev_oct_j + 30, 0, 255);
        brightness = constrain(j, 0, 255);
        brightness_prev = constrain(prev_oct_j, 0, 255);
        if (brightness == 255) {
          saturation = 50;
          brightness = 200;
        }
        if (brightness_prev == 255) {
          saturation_prev = 50;
          brightness_prev = 200;
        }


        for (uint8_t y = 0; y < kMatrixHeight; y++) {
          leds[XY(led_index - 1, y)] = CHSV((j + y * 30) % 72 + 100, saturation, brightness);
          if (i > 2) {
            prev_oct_j = (j + prev_j[i - 1]) / 2;
            leds[ XY(led_index - 2, y)] = CHSV((prev_oct_j + y * 30) % 72 + 100, saturation_prev, brightness_prev);
          }
        }
      }
    }



    if (beat >= 7) {
      fill_solid(leds, NUM_LEDS, CRGB::Gray);
      FastLED.setBrightness(150);


      //    FastLED.setBrightness(200);

    }
    else {
      if (prev_beat != beat) {
        FastLED.setBrightness(40 + beat * beat * 5);
        prev_beat = beat;
      }

    }

    FastLED.show();
    if (beat) {
      counter2 += ((beat + 4) / 2 - 2);
      if (counter2 < 0) {
        counter2 = 1000;
      }
      if (beat > 3 && beat < 7) {
        FastLED.delay (20);
      }
      beat = 0;
    }

    // Serial.println();
  }
}


void sploosh()
{
  int prev_j[8];
  int beat = 0;
  int prev_oct_j;
  int counter = 0;
  int prev_beat = 0;
  int led_index = 0;
  int saturation = 0;
  int saturation_prev = 0;
  int brightness = 0;
  int brightness_prev = 0;

  while (1) { // reduces jitter

    if (BT.available()) // turns off lights if user inputs 'o'
    {
      a = (char)BT.read();

      if (a == 'o')
      {
        break;
      }
    }

    cli();  // UDRE interrupt slows this way down on arduino1.0

    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_octave(); // take the output of the fht  fht_mag_log()

    // every 50th loop, adjust the volume accourding to the value on A2 (Pot)
    if (counter >= 50) {
      ADMUX = 0x40 | (1 & 0x07); // set admux to look at Analogpin A1 - Master Volume


      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      delay(1000);
      while (!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      float master_volume = (k + 0.1) / 1000 + .5; // so the valu will be between ~0.5 and 1.5
      // Serial.println (master_volume);


      for (int i = 1; i < 8; i++) {
        noise_fact_adj[i] = noise_fact[i] * master_volume;
      }

      ADMUX = 0x40 | (0 & 0x07); // set admux back to look at A0 analog pin (to read the microphone input
      counter = 0;
    }

    sei();
    counter++;


    // End of Fourier Transform code - output is stored in fht_oct_out[i].

    // i=0-7 frequency (octave) bins (don't use 0 or 1), fht_oct_out[1]= amplitude of frequency for bin 1
    // for loop a) removes background noise average and takes absolute value b) low / high pass filter as still very noisy
    // c) maps amplitude of octave to a colour between blue and red d) sets pixel colour to amplitude of each frequency (octave)

    for (int i = 1; i < 8; i++) {  // goes through each octave. skip the first 1, which is not useful

      int j;
      j = (fht_oct_out[i] - noise[i]); // take the pink noise average level out, take the asbolute value to avoid negative numbers
      if (j < 10) {
        j = 0;
      }
      j = j * noise_fact_adj[i];

      if (j < 10) {
        j = 0;
      }
      else {
        j = j * noise_fact_adj[i];
        if (j > 180) {
          if (i >= 7) {
            beat += 2;
          }
          else {
            beat += 1;
          }
        }
        j = j / 30;
        j = j * 30; // (force it to more discrete values)
      }

      prev_j[i] = j;

      //     Serial.print(j);
      //     Serial.print(" ");


      // this fills in 11 LED's with interpolated values between each of the 8 OCT values
      if (i >= 2) {
        led_index = 2 * i - 3;
        prev_oct_j = (j + prev_j[i - 1]) / 2;

        saturation = constrain(j + 30, 0, 255);
        saturation_prev = constrain(prev_oct_j + 30, 0, 255);
        brightness = constrain(j, 0, 255);
        brightness_prev = constrain(prev_oct_j, 0, 255);
        if (brightness == 255) {
          saturation = 50;
          brightness = 200;
        }
        if (brightness_prev == 255) {
          saturation_prev = 50;
          brightness_prev = 200;
        }


        for (uint8_t y = 0; y < kMatrixHeight; y++) {
          leds[XY(led_index - 1, y)] = CHSV((j + y * 30) % 100 + 50, saturation, brightness);
          if (i > 2) {
            prev_oct_j = (j + prev_j[i - 1]) / 2;
            leds[ XY(led_index - 2, y)] = CHSV((prev_oct_j + y * 30) % 100 + 50, saturation_prev, brightness_prev);
          }
        }
      }
    }



    if (beat >= 7) {
      fill_solid(leds, NUM_LEDS, CRGB::Gray);
      FastLED.setBrightness(150);


      //    FastLED.setBrightness(200);

    }
    else {
      if (prev_beat != beat) {
        FastLED.setBrightness(40 + beat * beat * 5);
        prev_beat = beat;
      }

    }

    FastLED.show();
    if (beat) {
      counter2 += ((beat + 4) / 2 - 2);
      if (counter2 < 0) {
        counter2 = 1000;
      }
      if (beat > 3 && beat < 7) {
        FastLED.delay (20);
      }
      beat = 0;
    }

    // Serial.println();
  }
}


// Param for different pixel layouts
const bool    kMatrixSerpentineLayout = true;
// Set 'kMatrixSerpentineLayout' to false if your pixels are
// laid out all running the same way, like this:

// Set 'kMatrixSerpentineLayout' to true if your pixels are
// laid out back-and-forth, like this:
uint16_t XY( uint8_t x, uint8_t y)
{
  uint16_t i;

  if ( kMatrixSerpentineLayout == false)
  {
    i = (y * kMatrixWidth) + x;
  }

  if ( kMatrixSerpentineLayout == true)
  {
    if ( y & 0x01)
    {
      // Odd rows run backwards
      uint8_t reverseX = (kMatrixWidth - 1) - x;
      i = (y * kMatrixWidth) + reverseX;

    }
    else
    {
      // Even rows run forwards
      i = (y * kMatrixWidth) + x;

    }
  }

  i = (i + counter2) % NUM_LEDS;
  return i;
}

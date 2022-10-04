#include "Adafruit_NeoPixel.h"
#include "Servo.h"
#include "SoftwareSerial.h"
#include "Iot.h"

unsigned const int rx_pin = 2;
unsigned const int tx_pin = 3;
unsigned const int num_of_pixels = 5;
unsigned const int neo_pixel_pin = 7;
unsigned const int servo_pin = 6;
unsigned const int first_pin = 8;
unsigned const int num_of_iots = 5;

Adafruit_NeoPixel neo_pixel = Adafruit_NeoPixel(num_of_pixels, neo_pixel_pin, NEO_GRB + NEO_KHZ800);
Servo servo;
SoftwareSerial hc06(rx_pin, tx_pin);
Iot iot = Iot(first_pin, num_of_iots, num_of_pixels);

void setup() {
  // put your setup code here, to run once:
  servo.attach(servo_pin);
  neo_pixel.begin();
  hc06.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  iot.GetCommandSignal(&hc06, &neo_pixel, &servo);
}

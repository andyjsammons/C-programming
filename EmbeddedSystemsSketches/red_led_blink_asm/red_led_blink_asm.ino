//----------------------------
// C Code for Blinking Red LED
//----------------------------

extern "C" //function prototypes external to C sketch
{
  void start();
  void led(byte);
}

//-------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  start();
}

void loop() {
  // put your main code here, to run repeatedly:
  led(1); delay(200);
  led(0); delay(200);
}

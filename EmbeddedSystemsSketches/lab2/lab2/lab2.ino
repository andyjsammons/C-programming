const int HI = 255;
const int LO = 0;
const int RED = 11;
const int BLUE = 10;
const bool IN = true;
const bool OUT = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void fade(int COLOR, int direction) {
  if (direction){
    for (int i = 0; i < HI + 1; i++){
      analogWrite(COLOR, i);
      delay(25);
    };
    return;
  }
  else{
    for (int i = HI; i > LO - 1; i--){
      analogWrite(COLOR, i);
      delay(25);
    }; 
  };
  return;
}

void loop() {
  fade(RED, IN);
  fade(BLUE,IN);
  fade(RED, OUT);
  fade(BLUE, OUT);
}

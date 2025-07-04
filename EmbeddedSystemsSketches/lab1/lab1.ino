const int OFF = 500;
const int DASH = 3000;
const int DOT = 1500;
const int END = 0;

typedef struct {
  char letter;
  int morse[4];
} a2m;

a2m A = {'A',{DOT,DASH,END,END}};
a2m B = {'B',{DASH,DOT,DOT,DOT}};
a2m C = {'C',{DASH,DOT,DASH,DOT}};
a2m D = {'D',{DASH,DOT,DOT,END}};
a2m E = {'E',{DOT,END,END,END}};
a2m F = {'F',{DOT,DOT,DASH,DOT}};
a2m G = {'G',{DASH,DASH,DOT,END}};
a2m H = {'H',{DOT,DOT,DOT,DOT}};
a2m I = {'I',{DOT,DOT,END,END}};
a2m J = {'J',{DOT,DASH,DASH,DASH}};
a2m K = {'K',{DASH,DOT,DASH,END}};
a2m L = {'L',{DOT,DASH,DOT,DOT}};
a2m M = {'M',{DASH,DASH,END,END}};
a2m N = {'N',{DASH,DOT,END,END}};
a2m O = {'O',{DASH,DASH,DASH,END}};
a2m P = {'P',{DOT,DASH,DASH,DOT}};
a2m Q = {'Q',{DASH,DASH,DOT,DASH}};
a2m R = {'R',{DOT,DASH,DOT,END}};
a2m S = {'S',{DOT,DOT,DOT,END}};
a2m T = {'T',{DASH,END,END,END}};
a2m U = {'U',{DOT,DOT,DASH,END}};
a2m V = {'V',{DOT,DOT,DOT,DASH}};
a2m W = {'W',{DOT,DASH,DASH,END}};
a2m X = {'X',{DASH,DOT,DOT,DASH}};
a2m Y = {'Y',{DASH,DOT,DOT,DASH}};
a2m Z = {'Z',{DASH,DASH,DOT,DOT}};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void blink(a2m letter, int letter_len){
  Serial.println(letter.letter);
  for (int i = 0; i< letter_len; ++i){
    if (letter.morse[i] == END){
      return;
    }
    digitalWrite(13, HIGH);
    delay(letter.morse[i]);
    digitalWrite(13, LOW);
    delay(OFF);
  };

}

void loop() {
  // put your main code here, to run repeatedly:
  a2m sentence[] = {L,O,O,K,O,U,T,F,O,R,T,H,E,I,C,E,B,U,R,G};
  for (int i = 0; i < sizeof(sentence)/sizeof(sentence[i]); ++i){
    blink(sentence[i],4);
  }
  digitalWrite(13,LOW);
}

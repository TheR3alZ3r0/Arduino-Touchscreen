#define MODE_1
#define PWM
int d1 = 8;
int d2 = 9;
int d3 = 10;
int d4 = 11;

int an1 = A8;
int an2 = A9;
int an3 = A10;
int an4 = A11;
int samples = 100;

int readSamples(int port, int samples) {

  int total;
  for (int i = 0; i < samples; i++) {

#ifdef PWM
    digitalWrite(d1, HIGH);
    digitalWrite(d4, HIGH);
    digitalWrite(d2, HIGH);
    digitalWrite(d3, HIGH);
#endif

    total += analogRead(port);

#ifdef PWM
    digitalWrite(d1, LOW);
    digitalWrite(d4, LOW);
    digitalWrite(d2, LOW);
    digitalWrite(d3, LOW);
#endif

  }

  return total;

}

void setup() {

  Serial.begin(19200);
  //analogReference(INTERNAL2V56);

  pinMode(an1, INPUT);
  pinMode(an2, INPUT);
  pinMode(an3, INPUT);
  pinMode(an4, INPUT);

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

  digitalWrite(d1, HIGH);
  digitalWrite(d4, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
}

void loop() {
#ifdef MODE_1

#ifdef PWM
  digitalWrite(d1, HIGH);
  digitalWrite(d4, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
#endif

  int r1 = readSamples(an1, samples);
  int r2 = readSamples(an2, samples);
  int r3 = readSamples(an3, samples);
  int r4 = readSamples(an4, samples);

#ifdef PWM
  digitalWrite(d1, LOW);
  digitalWrite(d4, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
#endif

  Serial.print(r1);
  Serial.print(",");
  Serial.print(r2);
  Serial.print(",");
  Serial.print(r3);
  Serial.print(",");
  Serial.print(r4);
  Serial.println("");
#endif
#ifdef MODE_2

  int r1 = readSamples(an1, samples);
  int r2 = readSamples(an2, samples);
  int r3 = readSamples(an3, samples);
  int r4 = readSamples(an4, samples);

  String msg = "{" + String(r1) + "," + String(r2) + "," + String(r3) + "," + String(r4) + "," + "}";

  Serial.println(msg);

#endif
}

#define echo 2 // pin ECHO di D2
#define trig 3 // pin TRIGGER di D3

int n;

void setup() {
  pinMode(trig, OUTPUT);  // set pin trigger sebagai OUTPUT
  pinMode(echo, INPUT);   // set pin echo sebagai INPUT
  Serial.begin(9600);     // memulai serial komunikasi dengan kecepatan baudrate 9600
  Serial.println("Memulai program...");
}

void loop() {
  n = bacaJarak();
  Serial.println("Jarak: "+String(n)+" cm");
  delay(300);
}

int bacaJarak(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long durasi = pulseIn(echo, HIGH);
  // Calculating the distance
  int jarak = durasi * 0.034 / 2;
  return jarak;
}

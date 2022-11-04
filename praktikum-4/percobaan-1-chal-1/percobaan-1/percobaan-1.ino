// Sambungkan pin 25 (digital) ke pin ECHO pada HC-SR04
#define ECHO_PIN 25
// Sambungkan pin 26 (digital) ke pin TRIG pada HC-SR04
#define TRIG_PIN 26

void setup() {
  // put your setup code here, to run once:
  // Set pin output dan input
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // Reset kondisi TRIG_PIN bila default-nya bernilai HIGH
  digitalWrite(TRIG_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
// Set TRIG_PIN agar memancarkan gelombang
  digitalWrite(TRIG_PIN, HIGH);
  // Matikan kembali setelah jeda waktu tertentu
  delayMicroseconds(5000);
  digitalWrite(TRIG_PIN, LOW);

  // Hitung durasi pancar gelombang (dalam mikrosekon)
  long duration = pulseIn(ECHO_PIN, HIGH);
  // Hitung jarak sebenarnya dari sensor ke benda
  int distance = duration * 0.034 / 2;
  // Tampilkan jarak pada serial monitor
  Serial.println((String) "Jarak: " + distance + " cm");
  delay(500);
}

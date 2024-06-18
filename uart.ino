//Written by Yousef Shaykholeslam
//18/3/2024

void setup() {
  // Initialize the built-in Serial port for communication with the PC
  Serial.begin(115200);

  // Initialize the Serial1 port for communication with the K210
  Serial1.begin(115200); 
  delay(1000);
}

void loop() {
  // Check if data is available from K210
  if (Serial1.available()) {
    String dataFromK210 = Serial1.readStringUntil('\n');
    Serial.print("Received from unitV: ");
    Serial.println(dataFromK210);
  }

  // Check if data is available from the PC
  if (Serial.available()) {
    String dataFromPC = Serial.readStringUntil('\n');
    Serial1.print(dataFromPC);
  }

  delay(10);
}

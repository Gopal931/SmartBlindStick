#include <SoftwareSerial.h>

SoftwareSerial GSM(11, 10); // RX, TX for SIM800L

char phone_no[] = "+918102919717"; // Replace with your phone number
#define bt_C A1 // Push button pin

void setup() {
  Serial.begin(9600);   // Serial Monitor
  GSM.begin(9600);      // SIM800L

  pinMode(bt_C, INPUT_PULLUP); // Push button with pull-up resistor
  Serial.println("Initializing...");
  initModule("AT", "OK", 1000); // Wait until module responds OK
}

void loop() {
  // Trigger via Serial Monitor
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command == "call") {
      callThenSMS();
    }
  }

  // Trigger via push button
  if (digitalRead(bt_C) == LOW) {
    delay(50); // Debounce
    if (digitalRead(bt_C) == LOW) {
      callThenSMS();
      while (digitalRead(bt_C) == LOW); // Wait until button released
    }
  }
}

// Function: Call first, then SMS
void callThenSMS() {
  // Make Call
  GSM.print("ATD");
  GSM.print(phone_no);
  GSM.println(";");
  delay(20000);        // Let it ring for 20 seconds
  GSM.println("ATH");  // Hang up
  delay(1000);

  // Send SMS
  GSM.println("AT+CMGF=1"); // Set SMS text mode
  delay(1000);
  GSM.print("AT+CMGS=\"");
  GSM.print(phone_no);
  GSM.println("\"");
  delay(1000);
  GSM.println("Emergency! Help i am facing a  problem."); // Message text
  GSM.write(26); // Ctrl+Z to send
  delay(3000);
}

// Wait for SIM800L to respond
void initModule(String cmd, char *res, int t) {
  while (1) {
    Serial.println(cmd);
    GSM.println(cmd);
    delay(100);
    while (GSM.available() > 0) {
      if (GSM.find(res)) {
        Serial.println(res);
        delay(t);
        return;
      } else {
        Serial.println("Retrying...");
      }
    }
    delay(t);
  }
}
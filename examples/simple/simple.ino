#include <WiFiProvisioner.h>

void setup() {
  Serial.begin(9600);

  // Create the WiFiProvisioner instance
  WiFiProvisioner provisioner;

  // Configure to hide additional fields
  provisioner.getConfig().SHOW_INPUT_FIELD = false; // No additional input field
  provisioner.getConfig().SHOW_RESET_FIELD = false; // No reset field

  // Set the success callback
  provisioner.onSuccess(
      [](const char *ssid, const char *password, const char *input1, const char *input2, const char *input3) {
        Serial.printf("Provisioning successful! Connected to SSID: %s\n", ssid);
        if (password) {
          Serial.printf("Password: %s\n", password);
        }
        if (input1) {
          Serial.printf("Input1: %s\n", input1);
        }
        if (input2) {
          Serial.printf("Input2: %s\n", input2);
        }
        if (input3) {
          Serial.printf("Input3: %s\n", input3);
        }
      });

  // Start provisioning
  provisioner.startProvisioning();
}

void loop() { delay(100); }

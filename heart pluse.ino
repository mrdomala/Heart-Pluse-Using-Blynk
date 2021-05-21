#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>   //including the library of SimpleTimer
SimpleTimer timer;
char auth[] ="73TSCVikfWzGAIYuABGVQ1j93f_abP9J";
char ssid[] ="ACT115527830665";    // Your WiFi credentials.
char pass[] ="77590949";  // Set password to "" for open networks.
void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000, sendUptime);
}
void sendUptime() {
  int heartrate=analogRead(A0);
  heartrate = map(heartrate, 0, 1023, 30, 100);
  Serial.print(heartrate);
  Blynk.virtualWrite(V0,heartrate);
  delay(20);
}
void loop() {
  Blynk.run();
  timer.run();
}

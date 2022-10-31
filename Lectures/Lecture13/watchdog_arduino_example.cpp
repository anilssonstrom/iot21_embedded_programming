#include <avr/wdt.h>

int counter = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("\nSystem is booting");

  pinMode(LED_BUILTIN, OUTPUT);

  // Starta Watchdog-timern
  wdt_disable();  // Stäng av timern om den var igång
  delay(3000);  // Vänta 3 sekunder, så Arduino IDE hinner programmera
  wdt_enable(WDTO_4S); // WatchDog Timeout 4 sekunder
}

void loop() {
  wdt_reset();  // Mata vakthunden!

  counter++;
  Serial.print("Counter: ");
  Serial.println(counter);
  
  if (counter >= 5)
  {
    Serial.println("Entering infinite loop!");
    while(true) {}  // Infinite loop
  }

  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

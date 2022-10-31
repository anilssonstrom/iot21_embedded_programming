#include <avr/wdt.h>

/*
	Setup: Anslut en tryck-knapp mellan jord och ingång 2
*/


int countdown = 4;
long int lastPrint = 0;

const int BUTTON_PIN = 2;  // Knappen är ansluten till input 2

void setup() {
  Serial.begin(9600);
  Serial.println("\nSystem is booting");

  /* Print Reset Reason */
  Serial.print("MCUSR: ");
  Serial.println(MCUSR);  // Reset reason lagras i "MCUSR"-registret

  if (MCUSR & (1 << PORF)) {        // Power-on Reset
    Serial.println("Cause of Reset = Power-on Reset" );
  }
  else if (MCUSR & (1 << EXTRF)) {  // External Reset
    Serial.println("Cause of Reset = External Reset" );
  }
  else if (MCUSR & (1 << BORF)) {   // Brown-Out Reset
    Serial.println("Cause of Reset = Brown-Out Reset" );
  }
  else if (MCUSR & (1 << WDRF)) {   // Watchdog Reset
    Serial.println("Cause of Reset = Watchdog Reset" );
  }
  MCUSR = 0;  // Nollställ registret så inte reset reason sparas till nästa gång av misstag

  
  pinMode(LED_BUILTIN, OUTPUT); // Pin 13: "LED_BUILTIN" är en output
  pinMode(BUTTON_PIN, INPUT_PULLUP); // PIN 2: "BUTTON_PIN" är en input med pullup-resistor

  // Starta Watchdog-timern
  wdt_disable();  // Stäng av timern om den var igång
  delay(3000);  // Vänta 3 sekunder, så Arduino IDE hinner programmera
  wdt_enable(WDTO_4S); // WatchDog Timeout 4 sekunder
}

void loop() {

  // Kolla om knappen är intryckt.
  if (digitalRead(BUTTON_PIN) == LOW) {
    wdt_reset();  // Mata vakthunden!
    countdown = 4;  // Återställ countdown till sitt startvärde
    lastPrint = 0;  // Gör att vi kan skriva ut counter igen direkt
  }
  
  // Skriv bara ut countdown en gång per sekund
  if (millis() - lastPrint > 1000) {
    Serial.println("Countdown: " + String(countdown));
    lastPrint = millis();  // Spara nuvarande tidsstämpeln

    countdown--;  // Räkna ned countdown med 1
  }
  
  delay(50); // För att simuleringen inte ska gå långsamt
}

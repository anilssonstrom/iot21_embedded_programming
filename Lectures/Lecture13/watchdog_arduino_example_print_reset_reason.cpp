#include <avr/wdt.h>

int counter = 0;

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

  // Pin 13: "LED_BUILTIN" är en output
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

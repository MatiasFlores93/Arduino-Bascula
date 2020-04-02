#include <HX711.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//codigo balanza

#define DOUT  A1
#define CLK  A0

HX711 balanza(DOUT, CLK);
//-----------------------------------------------------
#define I2C_ADDR    0x3f

LiquidCrystal_I2C             lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7);
void setup()
   {
       Serial.begin(9600);
       Serial.println(balanza.read());
       balanza.set_scale(439430.25); // Establecemos la escala
       balanza.tare(20); //El peso actual es considerado Tara.

       lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
       lcd.setBacklightPin(3,POSITIVE);
       lcd.setBacklight(HIGH);

      // lcd.home ();                   // go home
       lcd.print("Cattle Farmer");
      // lcd.setCursor ( 0, 1 );        // go to the 2nd line
      // lcd.print("");
   }
void loop() 
   {
    lcd.setCursor ( 0, 1 ); 
    lcd.print("Peso Grs: ");
    lcd.print(balanza.get_units(20),3 );
   // lcd.print("  Gr");
    delay(500);
    
    
    }

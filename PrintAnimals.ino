// If you're using Arduino 1.0 uncomment the next line:
#include "SoftwareSerial.h"
// If you're using Arduino 23 or earlier, uncomment the next line:
//#include "NewSoftSerial.h"

#include "Adafruit_Thermal.h"

#include "titolo.h"
#include "carpa.h"
#include "cigno.h"
#include "coniglio.h"
#include "iena.h"
#include "leone.h"


int printer_RX_Pin = 2;  // This is the green wire
int printer_TX_Pin = 3;  // This is the yellow wire

Adafruit_Thermal printer(printer_RX_Pin, printer_TX_Pin);
void setup(){
  Serial.begin(9600);
  while (!Serial.available());
//  pinMode(7, OUTPUT); digitalWrite(7, LOW); // To also work w/IoTP printer
  printer.begin();

  printCarpa();

  printer.feed(1);// Tell printer to sleep
  printer.wake();       // MUST call wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults

}

void printTitolo(){
  printer.printBitmap(titolo_width, titolo_height, titolo_data,true);
  printer.feed(1);
}

void printFooter(){
  printer.feed(4); 
  printer.justify('C');
  printer.setSize('S');
  printer.println("MAKER FAIRE 2014");
  printer.println("ROMA 3-5 OTTOBRE");  
  printer.println("PALAZZO STROZZI + FABLAB CASCINA");
}

void printCarpa(){
  
  printTitolo();
  printer.printBitmap(carpa_width, carpa_height, carpa_data,true);
  printer.feed(1);
  printer.justify('C');
  printer.setSize('M');
  printer.boldOn();
  printer.println("Carpa");
  printer.justify('C');
  printer.setSize('S');
  printer.boldOn();
  printer.println("Cresci forte e risali");
  printer.println("la corrente come una"); 
  printer.println("una carpa");
  printer.boldOff();
  printer.println("Proverbio giapponese");
  printer.println("");
  printer.println("Simbolo di forza e coraggio,");
  printer.println("risale i torrenti per trovare");
  printer.println("la propria strada.");
  printer.println("Sul tagliere, in attesa di");
  printer.println("essere mutilata ed uccisa,");
  printer.println("rimane impassibile, fiera, ");
  printer.println("ricordando l'atteggiamento ");
  printer.println("dei samurai in attesa");
  printer.println("dell' esecuzione.");
  printFooter();
  
}


void loop(){
  
}

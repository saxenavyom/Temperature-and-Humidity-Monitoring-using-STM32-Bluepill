

#include <Adafruit_SSD1306_STM32.h> //library for oled display

#include <Adafruit_GFX.h> //library for oled display

#include <DHT.h> //library for dht11 sensor                   
#define OLED_RESET 4 //define reset
#define DHTPIN PA1 //define data pin

#define DHTTYPE DHT11 //define dht type
  
Adafruit_SSD1306 display(OLED_RESET);

DHT dht(DHTPIN, DHTTYPE);    
void setup()

{

  

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //begin oled display

  
 

  dht.begin(); //begin dht11 display
  Serial2.begin(9600);//begin serial communication through serial 2                   
 display.display();
 delay(100);
 display.clearDisplay();//clear oled display
 display.display();
 display.setTextSize(1);//set text size
 display.setTextColor(WHITE);//set text color

}

void loop()//start loop

{

  float h = dht.readHumidity();       //Gets Humidity value

  float t = dht.readTemperature(); //Gets temperature value
  display.setCursor(0,0);//set position
  display.clearDisplay();  

 display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");//display temperature on oled
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(t); //display temperature value on oled
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  Serial2.println(t);//send temperature value through serial communication to nodemcu
  
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity: "); //display humidity on oled
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(h); //display humidity value on oled
  display.print(" %");
  Serial2.println(h); //send humidity value through serial communication to nodemcu
  
  display.display();
  delay(1000); //generate delay

}

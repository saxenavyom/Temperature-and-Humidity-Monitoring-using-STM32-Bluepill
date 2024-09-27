
 
#include <ESP8266WiFi.h> //library for esp8266
 
String apiKey = "9PHA49KFKYMZWO4G";     //  Enter your Write API key from ThingSpeak
 
const char *ssid =  "Successful Engineers 2.4G";     // replace with your wifi ssid and wpa2 key
const char *pass =  "9471946606";
const char* server = "api.thingspeak.com";
 

 
WiFiClient client;
 
void setup() 
{
       Serial.begin(9600); //begin serial communication
       delay(10);
      
 
       Serial.println("Connecting to ");//serial transmit ssid and password
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass); //connect to wifi
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}
 
void loop() 
{
  while (Serial.available()>0)            //While having data at Serial port this loop executes

     {    
      float t,h,temp,hum; //declare temperature and humidity variables
      temp=t;
      hum=h;

      float k = Serial.parseFloat(); //recieve serial data from stm32
      if(k<35)
      {
        t=k;
      }
      else
      h=k;
     
 
                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey; //send data to thinkspeak server through api
                             postStr +="&field1=";
                             postStr += String(t);
                             postStr +="&field2=";
                             postStr += String(h);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Temperature: ");
                             if(t!=0){
                             Serial.print(t); //send temperature value to thinkspeak server
                             }
                             else{
                              t=temp;
                             Serial.print(t);
                             }
                             Serial.print(" degrees Celcius, Humidity: ");
                             if(h!=0){
                             Serial.print(h); //send humidity value to thinkspeak server
                             }
                             else
                             Serial.print(hum);
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
}
}

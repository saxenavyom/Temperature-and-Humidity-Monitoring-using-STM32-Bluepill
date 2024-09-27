# Temperature-and-Humidity-Monitoring-using-STM32-Bluepill
A temperature and humidity monitoring system using an STM32 Bluepill microcontroller tracks conditions in environments like warehouses. It collects data from sensors, displays it on an OLED screen, and transmits the information to a remote device for further analysis.
# WORKING 
A temperature and humidity monitoring system using an STM32 Bluepill microcontroller and  an OLED display would work as follows:
• The system would start by initializing the microcontroller and the OLED display. • The microcontroller would then use its ADC (analog-to-digital converter) and I2C (Inter Integrated Circuit) peripherals to read the temperature and humidity data from the sensors. • The microcontroller would then perform any necessary calculations on the data, such as converting the raw sensor values into meaningful temperature and humidity values. • The microcontroller would then use the OLED display's I2C interface to send the temperature and humidity data to the display. 
• The OLED display would receive the data and use its internal drivers to display the temperature and humidity values on the screen. 
• The microcontroller could also use its communication peripherals, such as UART, to  transmit the temperature and humidity data to a remote device for further processing or analysis. 
A temperature and humidity monitoring system using an STM32 Bluepill microcontroller and a DHT11 sensor, with the data being sent to a ThingSpeak server using a NodeMCU board, would work as follows: 
• The system would start by initializing the microcontroller, the DHT11 sensor, and the NodeMCU board. 
• The microcontroller would use its ADC (analog-to-digital converter) and I2C (Inter Integrated Circuit) peripherals to read the temperature and humidity data from the DHT11 sensor. 
• The microcontroller would then perform any necessary calculations on the data, such as converting the raw sensor values into meaningful temperature and humidity values. • The microcontroller would then send the temperature and humidity data to the NodeMCU board using a serial communication protocol, such as UART. 
• The NodeMCU board would receive the data and use its built-in WiFi module to connect  to a WiFi network. 
• The NodeMCU board would then use the HTTP protocol to send the temperature and humidity data to the ThingSpeak server, using an API key to authenticate the data. • The ThingSpeak server would receive the data and store it in a database, where it can be accessed and analyzed by users. 
# APPLICATIONS 
• Monitoring the temperature and humidity in a warehouse or storage facility: A temperature  and humidity monitoring system can be used to track and maintain optimal conditions for  storing sensitive goods, such as pharmaceuticals, food products, or electronic components. 
• Monitoring the temperature and humidity in a greenhouse or agricultural setting: A  temperature and humidity monitoring system can be used to track and maintain optimal  growing conditions for plants and crops. 
• Monitoring the temperature and humidity in a museum or art gallery: A temperature and  humidity monitoring system can be used to track and maintain optimal conditions for  preserving artwork and historical artifacts. 
• Monitoring the temperature and humidity in a home or office: A temperature and humidity  monitoring system can be used to track and maintain comfortable and healthy living or  working conditions. 
# CONCLUSION 
Overall, a temperature and humidity monitoring system using an STM32 Bluepill  microcontroller can be a useful tool for tracking and maintaining optimal conditions in a  
variety of settings. 

int s0 = 14;
int s1 = 16;
int s2 = 17;



#include <Wire.h>
#include <Adafruit_ADS1015.h>
 Adafruit_ADS1115 ads(0x49);  /* Use this for the 16-bit version */
float Voltage0 = 0.0;
float Voltage1 = 0.0;
float Voltage2 = 0.0;
float Voltage3 = 0.0;
void setup(void) 
{
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);


  
  Serial.begin(115200);
  Serial.println("Hello!");

//ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
  
  ads.begin();
}

void loop(void) 
{
  int16_t adc0, adc1, adc2, adc3;

  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);
  Serial.print("AIN0: "); Serial.println(adc0);
  Serial.print("AIN1: "); Serial.println(adc1);
  Serial.print("AIN2: "); Serial.println(adc2);
  Serial.print("AIN3: "); Serial.println(adc3);
  Serial.println(" ");

Voltage0 = (adc0 * 0.1875)/1000;
Voltage1 = (adc1 * 0.1875)/1000;
Voltage2 = (adc2 * 0.1875)/1000;
Voltage3 = (adc3 * 0.1875)/1000;

Serial.print("Voltage0: ");Serial.println(Voltage0); 
Serial.print("Voltage1: ");Serial.println(Voltage1); 
Serial.print("Voltage2: ");Serial.println(Voltage2);
Serial.print("Voltage3: ");Serial.println(Voltage3);   
  delay(100);
   digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, HIGH);

//   delay(1000);
//digitalWrite(s0, LOW);
//  digitalWrite(s1, LOW);
//  digitalWrite(s2, HIGH);
}

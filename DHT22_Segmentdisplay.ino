//DHT & LED & Servo
#include "DHT.h"
#include "Adafruit_NeoPixel.h"
#include "Servo.h"
Servo myservo;
#define DHTPIN 2      
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);
int a = 9;
int b = 3;
int c = 4;
int d = 5;
int e = 12;
int f = 7;
int g = 8;
int GND1 = 10;
int GND2 = 13;
// int GND3 = 10;
// int GND4 = 9;
int dig1 = 0;
int dig2 = 0;
// int dig3 = 0;
// int dig4 = 0;
int h;
int i,j,k;
int color;
int add;
int x;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(15,15,NEO_GRB + NEO_KHZ800);
// WIFI
#include <LWiFi.h>
#include "MCS.h"

char _lwifi_ssid[] = "Feen";
//char _lwifi_ssid[] = "Lin Kevin1";
char _lwifi_pass[] = "22558992";
MCSDevice mcs("DU02SRn2", "4ma4GByKtiLp3eJa");

MCSDisplayFloat Temp("Temperature");
MCSDisplayFloat Humi("Humidity");

void setup()
{
  Serial.begin(9600);
  mcs.addChannel(Temp);
  mcs.addChannel(Humi);
  Serial.println("WIFI 連線開始");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Serial.println("WIFI 連線成功");
  Serial.println("MCS 連線開始");
  Serial.println("MCS 連線成功");while(!mcs.connected()) { mcs.connect(); }
  
  myservo.attach(17);
  pixels.begin();
  pixels.setBrightness(32);
  color = 0;
  add = 1;
  Serial.println(F("DHTxx test!"));
  dht.begin();
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  // pinMode(GND3, OUTPUT);
  // pinMode(GND4, OUTPUT);

  Serial.begin(9600);
}

void loop()
{

   while (!mcs.connected()) {
  mcs.connect();
   if (mcs.connected()) { Serial.println("MCS 已重新連線"); }
    }
  mcs.process(1);


  int h = dht.readHumidity();  
  int t = dht.readTemperature();
  
  Serial.println(t);    
  Serial.println(h);
  delay(2000); 
  Temp.set(t);
  Humi.set(h);
  //delay(100);


    digitalWrite( GND2,HIGH);
    digitalWrite( GND1,HIGH);
    dig1 = h / 10;
    dig2 = h - (dig1 * 10);
    Serial.println(dig1);
    Serial.println(dig2);
        digitalWrite( GND2, LOW);
       
        digitalWrite( GND1,LOW);  
        DisplayNumber(dig2);
        
        delay(100);
        
        digitalWrite( GND2,LOW);
        //delay(50);
        digitalWrite( GND1, LOW);   
        DisplayNumber(dig1);
        
        delay(50);
       // digitalWrite( GND1,);
        //delay(50);
       // digitalWrite( GND2,HIGH);
  
//================================================//
 if(h>68){                
   
    myservo.write(150);
    

    for (i = 0; i <= 14; i++) {
    pixels.setPixelColor(i, pixels.Color(0,color,0));
      }
    pixels.show();
    color = color + add;
    if (color >= 100) {
    add = -1;
      } 
      
    else if (color <= 0) {
    add = 1;
      }
        
  }
//==========================================//        
  if(h<46){                
   
    myservo.write(30);
    

    for (j = 0; j <= 14; j++) {
    pixels.setPixelColor(j, pixels.Color(color,0,0));
      }
    pixels.show();
    color = color + add;
    if (color >= 100) {
    add = -1;
      }
        
    else if (color <= 0) {
    add = 1;
      }    
       
  }
//==========================================// 
if(h>=46 && h<=68){                
   
    myservo.write(100);
    

    for (k = 0; k <= 14; k++) {
    pixels.setPixelColor(k, pixels.Color(0,0,0));
      }
    pixels.show();
    color = color + add;
    if (color >= 100) {
    add = -1;
      } 
    else if (color <= 0) {
    add = 1;
      }
         
  }
//==========================================//
delay(10); 
}
void DisplayNumber(int x) {
  switch (x) {
    case 0: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    
  }
}
//==============================================//
void zero()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, HIGH);
}

void one()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void two()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, HIGH);
  digitalWrite( g, LOW);
}

void three()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, LOW);
}

void four()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void five()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void six()
{
  digitalWrite( a,HIGH);
  digitalWrite( b, HIGH);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void seven()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void eight()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void nine()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

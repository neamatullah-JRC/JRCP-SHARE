
#include <SoftwareSerial.h>
SoftwareSerial CAR_BT(7, 6);

#include <JRCCAR.h>
JRCCAR car(5, 4, 3, 2);
int ena = 9;
int enb = 10;
int car_data;
int spd = 100;
void setup()
{

  Serial.begin(9600);
  CAR_BT.begin(9600);
  car.PinSetup();
  pinMode(ena , OUTPUT);
  pinMode(enb , OUTPUT);
}

void loop()
{
  
  if (CAR_BT.available() > 0) {
    car_data = CAR_BT.read();
    Serial.println(car_data);

  }

  Serial.println(car_data);
  analogWrite(ena, spd);
  analogWrite(enb , spd);

     if(car_data == 1){    car.forward();     } 
else if(car_data == 2){    car.backward();    }
else if(car_data == 3){    car.left();        } 
else if(car_data == 4){    car.right();       }
else if(car_data == 5){    car.stop();        }  
else if(car_data == 6){car.left();  delay(400);  car_data = 5;}
else if(car_data == 7){car.right();   delay(400);  car_data = 5;}
else if(car_data == 11){ spd = spd+50;}
else if(car_data == 12){ spd = spd-50;}
}



  

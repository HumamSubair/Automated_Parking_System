#include <LiquidCrystal.h>

LiquidCrystal lcd (12,11,5,4,3,2);
int contrast = 75;


byte nick[8]=
{
B00001,
B00010,
B10101,
B01010,
B10100,
B01000,
B00000
};


byte cross[8]=
{
B00000,
B10001,
B11011,
B01110,
B11011,
B10001,
B00000
};



void setup()
{


  analogWrite(6,contrast);
  lcd.begin(16,2);
  
  pinMode(53,INPUT);
  pinMode(52,INPUT);
  pinMode(51,INPUT);

  
  Serial.begin(9600);
  pinMode(13,OUTPUT);

            lcd.createChar(1,nick);

            lcd.createChar(2,cross);

    lcd.setCursor(0, 0);
    lcd.print ("slot1");
    

    lcd.setCursor(8, 0);
    lcd.print ("slot2");
    

    lcd.setCursor(0, 1);
    lcd.print ("slot3");
   

    lcd.setCursor(8, 1);
    lcd.print ("full");


    

    

}

void loop()
{
/*
Serial.println("IRSensorip  ");

    for ( int i = 51; i < 54; i++)
    {
    Serial.println(digitalRead(i));
     if(digitalRead(i)==0)
      {
      digitalWrite(13,HIGH);
      }
     else{
        digitalWrite(13,LOW);
        }
    }

*/
    if ( digitalRead(51) == 0)
    {
      lcd.setCursor(6,0);
      lcd.write(1);
    }
    else
    {
      lcd.setCursor(6,0);
      lcd.write(2);
     }

     
    if ( digitalRead(52) == 0)
    {
      lcd.setCursor(14,0);
      lcd.write(1);
    }
    else
    {
      lcd.setCursor(14,0);
      lcd.write(2);
     }

      
    if ( digitalRead(53) == 0)
    {
      lcd.setCursor(6,1);
      lcd.write(1);
    }
    else
    {
      lcd.setCursor(6,1);
      lcd.write(2);
     }


     if ( digitalRead (51) == 0 && digitalRead (52) == 0 && digitalRead (53) == 0)
    {
      lcd.setCursor(14,1);
      lcd.write(1);
    }
    else
    {
      lcd.setCursor(14,1);
      lcd.write(2);
     }
    
   delay(1000);


}

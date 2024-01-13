#include <LiquidCrystal.h> 
#include <Keypad.h> 


const byte ROWS = 4; //number of Rows
const byte COLS = 6; //number of Coloums


// Define the Keymap
char keys[ROWS][COLS] = {

 {'O','7','8','9','C','D'},
  {'Z','4','5','6','B','R'},     //assign keypad button as a words and numbers
  {'Y','1','2','3','A','X'},
  {'V','0','.','=','A','P'}

};

byte rowPins[ROWS] = { 5, 4, 3, 2 }; // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 11, 10, 9, 8, 7, 6 }; // Connect keypad COLS pins to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

const int rs = 13, en = 12, d4 = A0, d5 = A1, d6 = A2, d7 = A3; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 float Num1,Num2,Number;   //input numbers
 char key,action;
 boolean result = false;
 
void setup() {
  lcd.begin(40,2); //We are using a 40*2 LCD display
  lcd.print("       Complex CALCULATOR      "); //Display intro message
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print("        ARPON      "); 

   delay(3000); //Wait for display to show info
    lcd.clear(); //Then clean it
}

void loop() {
  
key = kpd.getKey(); //storing pressed key value in a char

if (key!=NO_KEY)
DetectButtons();

if (result==true)
CalculateResult();

DisplayResult();   
}

void DetectButtons()
{ 
     lcd.clear(); //Then clean it
    if (key=='O') //If cancel Button is pressed
    {Serial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;}
    

     if (key == '1') //If Button 1 is pressed
    {Serial.println ("Button 1"); 
    if (Number==0)
    Number=1;
    else
    Number = (Number*10) + 1; //Pressed twice
    }
    
     if (key == '4') //If Button 4 is pressed
    {Serial.println ("Button 4"); 
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; //Pressed twice
    }
    
     if (key == '7') //If Button 7 is pressed
    {Serial.println ("Button 7");
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7; //Pressed twice
    } 
  

    if (key == '0')
    {Serial.println ("Button 0"); //Button 0 is Pressed
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }
    
     if (key == '2') //Button 2 is Pressed
    {Serial.println ("Button 2"); 
     if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed twice
    }
    

     if (key == '5')
    {Serial.println ("Button 5"); 
     if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5; //Pressed twice
    }
    

     if (key == '8')
    {Serial.println ("Button 8"); 
     if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; //Pressed twice
    }   
  

    if (key == '=')
    {Serial.println ("Button Equal"); 
    Num2=Number;
    result = true;
    }
    
     if (key == '3')
    {Serial.println ("Button 3"); 
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3; //Pressed twice
    }
    
     if (key == '6')
    {Serial.println ("Button 6"); 
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9')
    {Serial.println ("Button 9");
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; //Pressed twice
    }  

      if (key == 'A' || key == 'B' || key == 'C' || key == 'D' || key == 'V' || key == 'Y' || key == 'X' || key == 'P' || key == 'Z' || key == 'R') 
  {
    Num1 = Number;    
    Number =0;
    if (key == 'A')
    {Serial.println ("Addition"); action = '+';}
     if (key == 'B')
    {Serial.println ("Subtraction"); action = '-'; }
     if (key == 'C')
    {Serial.println ("Multiplication"); action = '*';}
     if (key == 'D')
    {Serial.println ("Division"); action = '/';}  
    if (key == 'V')
    {Serial.println ("Square"); action = 'V';}
    if (key == 'Y')
    {Serial.println ("Percent"); action = '|';}
    if (key == 'X')
    {Serial.println ("Percentage"); action = '!';}
    if (key == 'P')
    {Serial.println ("Power"); action = '^';}
    if (key == 'Z')
    {Serial.println ("Modulus"); action = '%';}
    if (key == 'R')
    {Serial.println ("Exponential"); action = 'e';}

    delay(100);
  }
  
}


float CalculateResult()
{
  if (action=='+')
    Number = Num1+Num2;

  if (action=='-')
    Number = Num1-Num2;

  if (action=='*')
    Number = Num1*Num2;

  if (action=='/')
    Number = Num1/Num2;

  if (action=='V')
    Number = sqrt(Num2);

  if (action=='|')
    Number = (Num1/Num2)/100;

  if (action=='!')
    Number = Num1/100;

  if (action=='^')
    Number = pow(Num1,Num2);

  if (action=='%')
   Number = int (Num1) % int (Num2);

  if (action=='e')
   Number = exp(Num2);

}
float DisplayResult()
{
  lcd.setCursor(0,0);   // set the cursor to column 0, line 1
  lcd.print(Num1); lcd.print(action); lcd.print(Num2); 
  
  if (result==true)
  {lcd.print(" ="); lcd.print(Number);} //Display the result
  
  lcd.setCursor(0,1);   // set the cursor to column 0, line 1
  lcd.print(Number); //Display the result
}

# 1 "D:\\OneDrive - vit.ac.in\\Others\\Desktop\\sketch_jan31a\\sketch_jan31a.ino"
//Digital thermometer with Arduino and LM335 temp sensor

# 4 "D:\\OneDrive - vit.ac.in\\Others\\Desktop\\sketch_jan31a\\sketch_jan31a.ino" 2

//LCD module connections (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2,3,4,5,6,7);
void setup(){
  //set up the LCD's number of columns and rows
  lcd.begin(16,2);
}

char message1[]="Temp =  00.0 C";
char message2[]="=  00.0 F";
int Kelvin, Celsius, Faren, Farenheit;
void loop(){
delay(1000);
Kelvin=analogRead(0 /*LM335 output pin is connected to Arduino A0 pin*/) *0.489; //Read analog voltage and convert it to Kelvin(0.489=500/1024)
Celsius=Kelvin-273;
Faren=(Celsius*18)+320;
Farenheit=Faren/10;
if(Celsius<0){
  Celsius=((Celsius)>0?(Celsius):-(Celsius)); //Absolute value
  message1[6]='-'; //Put minus '-' sign
}
else
  message1[6]=' '; //Put space ' '
if(Celsius>99)
  message1[7]='1'; //Put 1(of hundred)
message1[8]=(Celsius/10)%10+48;
message1[9]=Celsius%10+48;
message1[12]=223; //Degree symbol
if(Farenheit>0)
  message2[1]=' ';
else
{
  Faren=((Faren)>0?(Faren):-(Faren));
  Farenheit=((Farenheit)>0?(Farenheit):-(Farenheit));
  message2[1]='-';
}
message2[3]=(Faren/100)%10+48;
message2[4]=(Faren/10)%10+48;
message2[6]=Faren%10+48;
message2[7]=223; //Degree symbol
if(Farenheit>99&&Farenheit<200)
  message2[2]='1';
else if(Farenheit>199)
  message2[2]='2';
else
  message2[2]=' ';
lcd.setCursor(0,0);
lcd.print(message1);
lcd.setCursor(5,1);
lcd.print(message2);
}

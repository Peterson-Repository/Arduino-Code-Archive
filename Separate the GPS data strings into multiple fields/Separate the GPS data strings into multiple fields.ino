int  commaPosition;  // the position of the next comma in the string
int  i=0;
char inData[67];   // Gets the input data 57
char inChar;       
byte index = 0;
String message;
String message1;
String message2;
String message3;
String message4;
String message5;
String message6;
String message7;
String message8;
String message9;
String message10;
String message11;
String message12;
String message13;


void setup()
{
    Serial.begin(9600);
    Serial.println("Input the GPS data ");
    Serial.println();  
}

void loop()
{
  if (Serial.available() > 0)
  {
   if (index < 60)
    {
         inChar = Serial.read();
         inData[index] = inChar;
         index++;
         inData[index] = '\0';  
         message = inData;
//         Serial.println("message"); Serial.println(message); 
         do
         {
              commaPosition = message.indexOf(',');
              if(commaPosition != -1)
              {
//                  Serial.println( message.substring(0,commaPosition));
                  message = message.substring(commaPosition+1, message.length());
                  i += (int)message.indexOf(',');
                  Serial.println();
              }
              else
              {  // here after the last comma is found
                 if(message.length() > 0) 
                 {
                  message.trim();                            // trim the white space off the string:
                    switch (i) 
                    {
                      case  0:  Serial.print(message);
                      message1 = message;
                      break;
                      case -1:  Serial.print(message);
                      message2 = message;
                      break;
                      case -2:  Serial.print(message);
                      message3 = message;
                      break;
                      case -3:  Serial.print(message);
                      message4 = message;
                      break;
                      case -4:  Serial.print(message);
                      message5 = message;
                      break;
                      case -5:  Serial.print(message);
                      message6 = message;
                      break;
                      case -6:  Serial.print(message);
                      message7 = message;
                      break;
                      case -7:  Serial.print(message); 
                      message8 = message;
                      break;                      
                      case -8:  Serial.print(message);
                      message9 = message;
                      break;
                      case -9:  Serial.print(message);
                      message10 = message;
                      break;
                      case -10: Serial.print(message);
                      message11 = message;
                      break;
                      case -11: Serial.print(message);
                      message12 = message;
                      break;
                      case -12: Serial.print(message);
                      message13 = message;
                      break;  
                    }                    
                 }
              }
           }  //do loop closing bracket
           while(commaPosition >=0);
          index = 0;
          inData[67];
    }
  }
 }


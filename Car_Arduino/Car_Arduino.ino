//Geoff Spielman
//April 23, 2016

const int led = 13;
int mA = 0, mB = 0;

String inputString = "";
boolean needChange = false;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  inputString.reserve(200);
  Serial.println("-----Start-----");
}

void loop() {

  if (needChange)
  {
    //Serial.print("Arduino rec: ");
    //Serial.println(inputString);
    Serial.print("Motor A: ");
    Serial.print(mA);
    Serial.print("   Motor B: ");
    Serial.println(mB);
    
    inputString = "";
    needChange = false;
  }
}

void serialEvent()
{
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n' || inChar == '!') //if 'end with newline' is not enabled on serial monitor, end with !
    {
      int commaIndex = inputString.indexOf(",");
      int endIndex = inputString.indexOf("!");
      if (endIndex == -1)
      {  
        endIndex = inputString.indexOf("/n");
      }
      mA = inputString.substring(0, commaIndex).toInt();
      mB = inputString.substring(commaIndex + 1, endIndex).toInt();
      needChange = true;
    } 
  }
}



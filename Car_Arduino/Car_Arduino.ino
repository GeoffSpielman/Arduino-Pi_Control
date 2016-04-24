//Geoff Spielman
//April 23, 2016

const int led = 13;
const int mtrL = 6;
const int mtrR = 5;

int mL = 0, mR = 0;

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
    Serial.print("Left Motor: ");
    Serial.print(mL);
    Serial.print("   Right Motor: ");
    Serial.println(mR);

    analogWrite(mtrL, mL);
    analogWrite(mtrR, mR);
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
      mL = inputString.substring(0, commaIndex).toInt();
      mR = inputString.substring(commaIndex + 1, endIndex).toInt();
      needChange = true;
    } 
  }
}



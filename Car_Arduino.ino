//Geoff Spielman
//April 23, 2016

const int led = 13;

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
    Serial.print("Arduino rec: ");
    Serial.println(inputString);
    int blinks = inputString.substring(0, 2).toInt();
    for (int i = 0; i < blinks; i ++)
    {
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
    }
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
    if (inChar == '\n' || inChar == '$') //if 'end with newline' is not enabled on serial monitor, end with $
    {
      needChange = true;
    }
  }
}



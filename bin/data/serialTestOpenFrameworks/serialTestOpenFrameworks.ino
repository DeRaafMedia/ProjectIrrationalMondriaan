int switchPin1 = 2;
int switchPin2 = 3;
int switchPin3 = 4;
int switchPin4 = 5;
int ledPin = 11;   

void setup()
{
  pinMode(switchPin1, INPUT);
  digitalWrite(switchPin1, HIGH);
  pinMode(switchPin2, INPUT);
  digitalWrite(switchPin2, HIGH);
  pinMode(switchPin3, INPUT);
  digitalWrite(switchPin3, HIGH);
  pinMode(switchPin4, INPUT);
  digitalWrite(switchPin4, HIGH);

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()                     
{
  if(Serial.available() > 0 && Serial.read() == 'r')
  {
    int switchValue1 = digitalRead(switchPin1);
    int switchValue2 = digitalRead(switchPin2);
    int switchValue3 = digitalRead(switchPin3);
    int switchValue4 = digitalRead(switchPin4);

    if(switchValue1 == LOW)
    {
      Serial.println('1');
      digitalWrite(ledPin, HIGH);
    }
    else if(switchValue2 == LOW)
    {
      Serial.println('2');
      digitalWrite(ledPin, HIGH);
    }
    else if(switchValue3 == LOW)
    {
      Serial.println('3');
      digitalWrite(ledPin, HIGH);
    }
    else if(switchValue4 == LOW)
    {
      Serial.println('4');
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      Serial.println('0');
      digitalWrite(ledPin, LOW);
    }
  }
}

// setup input pins
int buttonAPin = 2;
int buttonBPin = 3;
int buttonCPin = 4;
int buttonDPin = 5;

// setup output pins
int ledEPin = 10;
int ledFPin = 12;
int ledGPin = 11;

// temporary variables
int buttonAState = 0;
int buttonBState = 0;
int buttonCState = 0;
int buttonDState = 0;
bool xorAC = 0;
bool carry = 0;

void setup() {
  // put your setup code here, to run once:
  // tie input and output variables to board pins
  pinMode(ledEPin, OUTPUT);
  pinMode(ledFPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(buttonAPin, INPUT);
  pinMode(buttonBPin, INPUT);
  pinMode(buttonCPin, INPUT);
  pinMode(buttonDPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read inputs
  buttonAState = digitalRead(buttonAPin);
  buttonBState = digitalRead(buttonBPin);
  buttonCState = digitalRead(buttonCPin);
  buttonDState = digitalRead(buttonDPin);

  if ((buttonAState && !buttonCState) || (!buttonAState && buttonCState))
  {
    xorAC = HIGH;
  }
  else
  {
    xorAC = LOW;
  }

  if (buttonBState && buttonDState)
  {
    carry = HIGH;
  }
  else
  {
    carry = LOW;
  }

  if ((xorAC && !carry) || (!xorAC && carry))
  {
    digitalWrite(ledFPin, HIGH);
  }
  else
  {
    digitalWrite(ledFPin, LOW);
  }
  
  if ((buttonBState && !buttonDState) || (!buttonBState && buttonDState))
  {
    digitalWrite(ledGPin, HIGH);
  }
  else
  {
    digitalWrite(ledGPin, LOW);
  }

  if ((buttonBState && buttonDState) && (buttonAState || buttonCState) || (buttonAState && buttonCState))
  {
    digitalWrite(ledEPin, HIGH);
  }
  else
  {
    digitalWrite(ledEPin, LOW);
  }
}

/*
 * Bit-wise operators
 * c = a & b ; AND
 * c = a | b ; OR
 * c = a ^ b ; XOR
 * c = !a ; NOT
 */

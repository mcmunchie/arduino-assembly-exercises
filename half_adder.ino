// setup output pins
int SumPin = 5; // represents the 1-bit sum
int CarryPin = 4; // represents the 1-bit output

// setup input pins
int buttonApin = 12;
int buttonBpin = 11;

// temporary variables
int a0;  // 1 bit input value for A
int b0;  // 1 bit input value for B
int s0;  // sum out of 1-bit
int co;  // 1-bit Carry out

void setup() 
{
  // tie input and output variables to board pins
  pinMode(SumPin, OUTPUT);
  pinMode(CarryPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  
}

void loop() 
{
  // read inputs
  a0 = digitalRead(buttonApin);
  b0 = digitalRead(buttonBpin);
  
  // calculate outputs
  // for a half-adder the sum output
  // is the XOR of inputs: S0 = a0 XOR b0
  s0 = a0 ^ b0;
  // in a half-adder the carry out is 
  // the AND of inputs : co = a0 AND b0
  co = a0 & b0;  

  // write outputs
  digitalWrite(SumPin, s0);
  digitalWrite(CarryPin, co);
}

/*
Bit-wise operators
c = a & b ; AND
c = a | b ; OR
c = a ^ b ; XOR
c = !a ;   NOT
*/

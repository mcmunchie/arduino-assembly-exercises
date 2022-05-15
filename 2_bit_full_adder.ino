// setup output pins
int SumPin1 = 5; // represents the first 1-bit sum
int CarryPin = 4; // represents the 1-bit carry output
int SumPin0 = 3;  // represents the second 1-bit sum

// setup input pins
int buttonA1pin = 12; 
int buttonB1pin = 11;
int buttonA0pin = 10;
int buttonB0pin = 9;
int buttonCarrypin = 8;

// temporary variables
int a1; // 1-bit input value for A1
int b1; // 1-bit input value for B1
int a0; // 1-bit input value for A0
int b0; // 1-bit input value for B0
int ci; // 1-bit input Carry in
int s1; // first sum out of 1-bit
int s0; // second sum out of 1-bit
int co; // 1-bit Carry out

void setup() {
  // put your setup code here, to run once:
  // tie input and output variables to board pins
  pinMode(SumPin1, OUTPUT);
  pinMode(CarryPin, OUTPUT);
  pinMode(SumPin0, OUTPUT);
  pinMode(buttonA1pin, INPUT_PULLUP);
  pinMode(buttonB1pin, INPUT_PULLUP);
  pinMode(buttonA0pin, INPUT_PULLUP);
  pinMode(buttonB0pin, INPUT_PULLUP);
  pinMode(buttonCarrypin,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read inputs
  a1 = digitalRead(buttonA1pin);
  b1 = digitalRead(buttonB1pin);
  a0 = digitalRead(buttonA0pin);
  b0 = digitalRead(buttonB0pin);
  ci = digitalRead(buttonCarrypin);

  // calculate outputs
  // for a 2-bit full adder the first sum (sum1) output
  // is the XOR of inputs: s1 = a1 XOR b1
  s1 = (a1 ^ b1) ^ ((a0 & b0) | (co & (a0 ^ b0))); // represents A XOR B, where: A = 1 + B = 1 is equal to 0

  // in a 2-bit full adder the carry out is
  // the AND of inputs: co = a1 AND b1
  co2 = (a1 & b1) | (((a0 & b0) | (c0 & (a0 ^ b0))) & (a1 ^ b1)); // represents A AND B, where: A = 1 + B = 1 is equal to 1

  // while the second sum (sum0) output
  // is the XOR of inputs: s0 = a0 XOR b0
  s0 = (a0 ^ b0) ^ co; // same as when s1 = a1 ^ b1, but using A0 and B0

  // write outputs
  digitalWrite(SumPin1, s1);
  digitalWrite(CarryPin, co);
  digitalWrite(SumPin0, s0);
}

/*
 * Bit-wise operators
 * c = a & b ; AND
 * c = a | b ; OR
 * c = a ^ b ; XOR
 * c = !a ; NOT
 */

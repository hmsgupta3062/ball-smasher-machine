int a;  // declare an integer a to store incoming serial data

void setup() 
{
  // put your setup code here, to run once:

  // enable 6 msp pins as output
  pinMode(11,OUTPUT); 
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  
  Serial.begin(9600);  // enable serial communication

  // initially all the pins are at low state
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void loop() 
{
  // put your main code here, to run repeatedly: 
  if (Serial.available()>0)  // when the incoming byte > 0
  {
    a=Serial.parseInt();  // read the bit and store in a
    
    if ((a>1) && (a<256))
    {
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      analogWrite(13,a);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      analogWrite(9,a);
      Serial.println(a);  // Serially prints the value of a
    }
    
    else if(a==1) 
    {
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      analogWrite(13,a);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      analogWrite(9,a);
      Serial.println(a);  // Serially prints the value of a
    }
    
    else
    {
      Serial.println(a);  // Serially prints the value of a
    }
    
    delay(1000);
  }
}

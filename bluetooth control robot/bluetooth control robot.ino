char t;
 
void setup() {
pinMode(6,OUTPUT);   //left motors forward
pinMode(7,OUTPUT);   //left motors reverse
pinMode(9,OUTPUT);   //right motors forward
pinMode(8,OUTPUT);   //right motors reverse
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
}
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(9,HIGH);
  delay(1000);
  forward();

}
 
else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(6,HIGH);
  delay(1000);
  forward();
}
  
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
delay(100);
}
void stop(){
digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);  
}
void forward(){
digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);  
}
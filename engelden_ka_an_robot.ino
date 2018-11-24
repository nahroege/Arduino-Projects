const int trigPin = A5;
const int echoPin = A3;

int solYon = 13;
int sagYon = 12;
int solPwm = 11;
int sagPwm = 3;

int buzzer =A2;

long sure;
int mesafe;

void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(solYon,OUTPUT);
  pinMode(sagYon,OUTPUT);
  pinMode(solPwm,OUTPUT);
  pinMode(sagPwm,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  analogWrite(solPwm,200);
  analogWrite(sagPwm,200);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  sure = pulseIn(echoPin,LOW);
  mesafe = sure*0.034/20;
  Serial.print("mesafe");
  Serial.println(mesafe);
  if(mesafe >=0 &&mesafe<20)
{ 
  analogWrite(sagPwm,200);
  analogWrite(solPwm,200);
  digitalWrite(buzzer,HIGH);
  digitalWrite(solYon,LOW);
  digitalWrite(sagYon,LOW);
}
else if (mesafe >=20 && mesafe <=40)
{
  analogWrite(sagPwm,0);
  analogWrite(solPwm,0);
  digitalWrite(buzzer,HIGH);
  digitalWrite(solYon,HIGH);
  digitalWrite(sagYon,HIGH);
} 
  else if(mesafe > 40 && mesafe<=60)
{
  analogWrite(sagPwm,200);
 analogWrite(solPwm,200);
 digitalWrite(buzzer,HIGH);
 digitalWrite(solYon,HIGH);
digitalWrite(sagYon,HIGH); 

}

else if(mesafe > 60)
{
  analogWrite(sagPwm,0);
 analogWrite(solPwm,0);
 digitalWrite(buzzer,LOW);
 digitalWrite(solYon,LOW);
digitalWrite(sagYon,LOW); 
}
}


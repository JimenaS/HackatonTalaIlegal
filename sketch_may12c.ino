#include <Servo.h>

const int trigPin = 52;
const int echoPin = 53;
const int Led = 13;
const int Led2 = 12;
//const int Led3 = 3;
//const int Led4 = 4;
long duracion, distancia;

Servo myservo; 

int vel = 0;    
int tiempo = 50;  


void setup()
{

    Serial.begin(9600); 
    


      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
      pinMode(Led , OUTPUT);
      pinMode(Led2 , OUTPUT);
      //pinMode(Led3 , OUTPUT);
      //pinMode(Led4 , OUTPUT);
      myservo.attach(9);

 
  
}

void loop(){

   //Prueba ultrasonico
         //ultraSonico();
         //delay(tiempo);
   
   vel = 80;
   myservo.write(vel);              
      ultraSonico(); 
   delay(1500); 
   if (distancia>199){
   Serial.println("DANGER");
   digitalWrite(Led,HIGH);
   digitalWrite(Led2,HIGH);
   //digitalWrite(Led3,HIGH);
   //digitalWrite(Led4,HIGH);
   delay(1000); }   
   else{
   digitalWrite(Led,LOW);
   digitalWrite(Led2,LOW);
   //digitalWrite(Led3,LOW);
   //digitalWrite(Led4,LOW);
   }
 
 
   vel = 60;
   myservo.write(vel);              
      ultraSonico(); 
   delay(1500);
   if (distancia>199){
   Serial.println("DANGER");
   digitalWrite(Led,HIGH);
   digitalWrite(Led2,HIGH);
   //digitalWrite(Led3,HIGH);
   //digitalWrite(Led4,HIGH);
   delay(1000); }
   else{
   digitalWrite(Led,LOW);
   digitalWrite(Led2,LOW);
   //digitalWrite(Led3,LOW);
   //digitalWrite(Led4,LOW);
   }
 
 
   vel = 40;
   myservo.write(vel);              
      ultraSonico(); 
   delay(1500);
   if (distancia>199){
   Serial.println("DANGER");
   digitalWrite(Led,HIGH);
   digitalWrite(Led2,HIGH);
  // digitalWrite(Led3,HIGH);
   //digitalWrite(Led4,HIGH);
   delay(1000); }
   else{
   digitalWrite(Led,LOW);
   digitalWrite(Led2,LOW);
   //digitalWrite(Led3,LOW);
   //digitalWrite(Led4,LOW);
   }

     vel = 60;
   myservo.write(vel);              
      ultraSonico(); 
   delay(1000);
   if (distancia>199){
   Serial.println("DANGER");
   digitalWrite(Led,HIGH);
   digitalWrite(Led2,HIGH);
   //digitalWrite(Led3,HIGH);
   //digitalWrite(Led4,HIGH);
   delay(1000); }
   else{
   digitalWrite(Led,LOW);
   digitalWrite(Led2,LOW);
   //digitalWrite(Led3,LOW);
   //digitalWrite(Led4,LOW);
   }
   
}

void ultraSonico(){
    
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        duracion = pulseIn(echoPin, HIGH);
        distancia = (duracion / 2) / 29.4;
        
      
        Serial.print("Distancia: ");
        Serial.print(distancia);
        Serial.println(" cm");
        
}

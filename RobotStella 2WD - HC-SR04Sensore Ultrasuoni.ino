#define trigPin 13
#define echoPin 10

#define PWMA 5
#define AIN1 4
#define AIN2 7
#define STBY 6
#define PWMB 9
#define BIN1 8
#define BIN2 12

               
                        
 
void setup() 
{ 
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT); //ANI1 E ANI2 RUOTA SX
  pinMode(AIN2, OUTPUT); 
  pinMode(BIN1, OUTPUT); // BIN1 E BIN2 RUOTA DX
  pinMode(BIN2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(STBY, HIGH); 
  Serial.begin(115200);
   
} 
 
void loop() 
{ 
  int value=100;
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
 
    Serial.print("Ping: ");
    Serial.println(distance); 
    Serial.print("cm");
 
  

  

 int distance1= distance + 150; 

 if(distance >=5) { avanti(); }
  else            { gira(); }
  
 }

void avanti()
{
    digitalWrite( AIN1,HIGH );
    digitalWrite( AIN2,LOW );
    digitalWrite( BIN1,LOW );
    digitalWrite( BIN2,HIGH );
    
    analogWrite( PWMA,120 );
    analogWrite( PWMB,130 );
    
}


 void alt()
{
    analogWrite( PWMA,50 );
    analogWrite( PWMB,50 );
 
    digitalWrite( AIN1,LOW );
    digitalWrite( AIN2,LOW );
    digitalWrite( BIN1,LOW );
    digitalWrite( BIN2,LOW );
    
}

void indietro()
{
    digitalWrite( AIN1,LOW );
    digitalWrite( AIN2,HIGH );
    digitalWrite( BIN1,LOW );
    digitalWrite( BIN2,HIGH );
 
    analogWrite( PWMA,130 );
    analogWrite( PWMB,120 );
    
}
 void gira()
{
  // STOP x 1/2 sec
  alt();
  delay( 100 );
 
  // INDIETRO x 1/2 secondo
  indietro();
  delay( 100 );
 
  // STOP x 1/2 sec
  alt();
  delay( 100 );
 
  // Gira
  digitalWrite( AIN1,LOW );
  digitalWrite( AIN2,HIGH );
  digitalWrite( BIN1,HIGH );
  digitalWrite( BIN2,LOW );
 
  analogWrite( PWMA,130 );
  analogWrite( PWMB,120 );
  
 
 
 
  delay( 100 );
}

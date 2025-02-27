
const int soundSensorPin = 2;  
const int ledPin = 10;         
const int clapTimeout = 500;   
unsigned long lastClapTime = 0; 
int clapCount = 0;              

void setup() {
  pinMode(soundSensorPin, INPUT); 
  pinMode(ledPin, OUTPUT);        
  digitalWrite(ledPin, LOW);      
  Serial.begin(9600);             

void loop() {
  
  int soundDetected = digitalRead(soundSensorPin);

  if (soundDetected == HIGH) { 
    unsigned long currentTime = millis(); 
    
    if (currentTime - lastClapTime <= clapTimeout) {
      clapCount++;
      Serial.println("Clap detected!");
    } else {
      clapCount = 1; 
    }

    lastClapTime = currentTime; /

    if (clapCount == 2) {
      Serial.println("Double clap detected!");
      digitalWrite(ledPin, HIGH); 
      delay(2000);               
      digitalWrite(ledPin, LOW); 
      clapCount = 0;             
    }
  }

  delay(50); 
}
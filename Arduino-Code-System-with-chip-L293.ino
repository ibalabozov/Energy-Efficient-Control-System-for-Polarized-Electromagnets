int impulsLenght = 10; //prodaljitelnost na impulsa v mS.
int impulsHeight = 255; // ogranichavane na goleminata na toka (stoinosti ot 0 do 255).

void setup(){

pinMode(10, OUTPUT); //PWM izhod - upr golemina na toka.
pinMode(8, OUTPUT);  // pin 8 i 12 obrashtane na poliariteta.
pinMode(12, OUTPUT); // pin 8 i 12 obrashtane na poliariteta.
Serial.begin(9600);

while (!Serial);
Serial.println("Input 1 to Turn LED on and 2 to off");
}

void loop() {
  
if (Serial.available()){
int state = Serial.parseInt();

//UPRAVLENIE POLIARIZIRAN EL MAGNIT UP-DOWN-UP PREZ DRAIVER LN293.
if (state == 20){
digitalWrite(10, LOW);
digitalWrite(8, LOW);
digitalWrite(12, LOW);
Serial.println("System OFF");
}
if (state == 21){
analogWrite(10, impulsHeight);
digitalWrite(8, HIGH);
delay(impulsLenght);
digitalWrite(8, LOW);
digitalWrite(12, LOW);
Serial.println("MODE UP-Down");
}
if (state == 22){
analogWrite(10, impulsHeight);
digitalWrite(8, LOW);
digitalWrite(12, HIGH);
delay(impulsLenght);
digitalWrite(12, LOW);
Serial.println("MODE Down-UP");
}
}
}

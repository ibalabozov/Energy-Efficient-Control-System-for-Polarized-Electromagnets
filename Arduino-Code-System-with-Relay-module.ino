int impulsLenght = 10; //prodaljitelnost na impulsa v mS.
int impulsHeight = 255; //regulirane na toka (zadavat se stoinosti ot 0 do 255).

void setup(){

pinMode(2, OUTPUT); // pin 2 i 4 sa prez releta - obrashtane na poliariteta
pinMode(4, OUTPUT); // pin 2 i 4 sa prez releta - obrashtane na poliariteta
pinMode(6, OUTPUT); //kontrol na goleminata na toka prez tranzistor

pinMode(10, OUTPUT); //PIN 10 KONTROLIRA DRAIVER LN293 - ZA BEZOPASNOST GO IZKLUCHVAME KOGATA POLZVAME TRANZISTORA.
digitalWrite(10, LOW);

Serial.begin(9600);

while (!Serial);
Serial.println("Input 1 to Turn LED on and 2 to off");
}

void loop() {
  
if (Serial.available()){
int state = Serial.parseInt();
if (state == 1){
digitalWrite(2, LOW);
digitalWrite(4, LOW);
digitalWrite(6, LOW);
Serial.println("System is OFF");
}
if (state == 2){
digitalWrite(2, HIGH);
digitalWrite(6, HIGH);
delay(10);
digitalWrite(2, LOW);
//digitalWrite(6, LOW);
digitalWrite(4, LOW);
Serial.println("System os ON - MODE 1 : Up-Down.");
}
if (state == 3){
digitalWrite(2, LOW);
digitalWrite(4, HIGH);
analogWrite(6, 255);
delay(10);
digitalWrite(4, LOW);
analogWrite(6, 0);
Serial.println("System os ON - MODE 2 : Down-Up.");
}
if (state == 4){
Serial.println("System os ON - MODE 3 : Switching 6 times.");
digitalWrite(2, LOW);
digitalWrite(4, LOW);
for (int i = 1; i < 7; i++) {
digitalWrite(4, HIGH);
delay(10);
digitalWrite(4, LOW);
delay(2000);
digitalWrite(2, HIGH);
delay(10);
digitalWrite(2, LOW);
delay(2000);
}
digitalWrite(2, LOW);
digitalWrite(4, LOW);
}
if (state == 5){
analogWrite(6, impulsHeight);
Serial.println("System os ON - MODE 4 : Transistor ON");
}
if (state == 6){
analogWrite(6, impulsHeight);
Serial.println("System os OFF - MODE 5 : Transistor OFF");
}
if (state == 7){
analogWrite(6, impulsHeight);
Serial.println("System os ON - MODE 6 : Transistor 50%");
}



if (state == 11){
Serial.println("System is ON - MODE : Up-Down.");
analogWrite(6, 0);
digitalWrite(2, LOW);
digitalWrite(4, HIGH);
delay(50);
analogWrite(6, impulsHeight);
delay(impulsLenght);
analogWrite(6, 0);
digitalWrite(2, LOW);
digitalWrite(4, LOW);
}
if (state == 12){
Serial.println("System is ON - MODE : Down-Up.");
analogWrite(6, 0);
digitalWrite(2, HIGH);
digitalWrite(4, LOW);
delay(50);
analogWrite(6, impulsHeight);
delay(impulsLenght);
analogWrite(6, 0);
digitalWrite(2, LOW);
digitalWrite(4, LOW);
}
}
}

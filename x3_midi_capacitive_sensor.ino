#include <CapacitiveSensor.h>
CapacitiveSensor sense1 = CapacitiveSensor(2, 3);
CapacitiveSensor sense2 = CapacitiveSensor(2, 4);
CapacitiveSensor sense3 = CapacitiveSensor(2, 5);
CapacitiveSensor sense4 = CapacitiveSensor(2, 6);
CapacitiveSensor sense5 = CapacitiveSensor(2, 7);
CapacitiveSensor sense6 = CapacitiveSensor(2, 8);

CapacitiveSensor sense7 = CapacitiveSensor(9, 10);
CapacitiveSensor sense8 = CapacitiveSensor(9, 11);
CapacitiveSensor sense9 = CapacitiveSensor(9, 12);
CapacitiveSensor sense10 = CapacitiveSensor(9, 13);
CapacitiveSensor sense11 = CapacitiveSensor(9, A1);
CapacitiveSensor sense12 = CapacitiveSensor(9, A0);

//CapacitiveSensor sense13 = CapacitiveSensor(2, A1);
//CapacitiveSensor sense14 = CapacitiveSensor(2, A2);
//CapacitiveSensor sense15 = CapacitiveSensor(2, A3);
//CapacitiveSensor sense16 = CapacitiveSensor(2, A4);

int on = 0x90;
int off = 0x80;

int gv = 0x60; //generic velocity

boolean currentState1 = LOW;    //for each sensor
boolean lastState1 = LOW;
boolean currentState2 = LOW;
boolean lastState2 = LOW;
boolean currentState3 = LOW;
boolean lastState3 = LOW;
boolean currentState4 = LOW;
boolean lastState4 = LOW;
boolean currentState5 = LOW;
boolean lastState5 = LOW;
boolean currentState6 = LOW;
boolean lastState6 = LOW;
boolean currentState7 = LOW;
boolean lastState7 = LOW;
boolean currentState8 = LOW;
boolean lastState8 = LOW;
boolean currentState9 = LOW;
boolean lastState9 = LOW;
boolean currentState10 = LOW;
boolean lastState10 = LOW;
boolean currentState11 = LOW;
boolean lastState11 = LOW;
boolean currentState12 = LOW;
boolean lastState12 = LOW;

boolean lastStateBeat = LOW;

int currentVol1 = 0;
int lastBeatVol = 0;
int currentVol2 = 0;
int lastBeatVol2 = 0;

const long interval1 = 500;
const long inverval2 = 250;

long previousMillis = 0;

boolean ledState = LOW;

int pitch1, pitch2, pitch3, pitch4, pitch5, pitch6, pitch7, pitch8, pitch9, pitch10, pitch11, pitch12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(19, OUTPUT);
}

void loop() {
  int val1 = sense1.capacitiveSensor(10);
  int val2 = sense2.capacitiveSensor(10);
  int val3 = sense3.capacitiveSensor(10);
  int val4 = sense4.capacitiveSensor(10);
  int val5 = sense5.capacitiveSensor(10);
  int val6 = sense6.capacitiveSensor(10);
  
  int val7 = sense7.capacitiveSensor(40);
  int val8 = sense8.capacitiveSensor(40);
  int val9 = sense9.capacitiveSensor(40);
  int val10 = sense10.capacitiveSensor(40);
  int val11 = sense11.capacitiveSensor(40);
  int val12 = sense12.capacitiveSensor(40);

  //-int val13 = sense13.capacitiveSensor(150);
  //-int val14 = sense14.capacitiveSensor(150);
  //-int val15 = sense15.capacitiveSensor(150);
  //-int val16 = sense16.capacitiveSensor(150);
  
  //Serial.print(val1);  Serial.print("\t"); Serial.print(val2);  Serial.print("\t"); Serial.print(val3);  Serial.print("\t"); Serial.print(val4);  Serial.print("\t"); Serial.print(val5);  Serial.print("\t"); Serial.print(val6);  Serial.print("\t"); Serial.print(val7);  Serial.print("\t"); Serial.print(val8);  Serial.print("\t"); Serial.print(val9);  Serial.print("\t"); Serial.print(val10);  Serial.print("\t"); Serial.print(val11);  Serial.print("\t"); Serial.print(val12);  Serial.print("\t");
  //---Serial.print(val3);  Serial.print("\t"); Serial.print(val14);  Serial.print("\t"); Serial.print(val15);  Serial.print("\t"); Serial.print(val16);  Serial.print("\t");
  //Serial.println();

  if(val1 > 900)
    currentState1 = HIGH;
  else
    currentState1 = LOW;
  if(val2 > 900)
    currentState2 = HIGH;
  else
    currentState2 = LOW;
  if(val3 > 800)
    currentState3 = HIGH;
  else
    currentState3 = LOW;
  if(val4 > 900)
    currentState4 = HIGH;
  else
    currentState4 = LOW;
  if(val5 > 900)
    currentState5 = HIGH;
  else
    currentState5 = LOW;
  if(val6 > 900)
    currentState6 = HIGH;
  else
    currentState6 = LOW;
  if(val7 > 90)
    currentState7 = HIGH;
  else
    currentState7 = LOW;
  if(val8 > 150)
    currentState8 = HIGH;
  else
    currentState8 = LOW;
  if(val9 > 110)
    currentState9 = HIGH;
  else
    currentState9 = LOW;
  if(val10 > 105)
    currentState10 = HIGH;
  else
    currentState10 = LOW;
  if(val11 > 120)
    currentState11 = HIGH;
  else
    currentState11 = LOW;
  if(val12 > 150)
    currentState12 = HIGH;
  else
    currentState12 = LOW;

  //Serial.print(currentState1); Serial.print("\t"); Serial.println(lastState1);
  //delay(500);

  //to turn the beat on and off
  currentVol1 = analogRead(A4)/8;
  if(currentVol1 != lastBeatVol){
    MIDIMessage(176, 1, currentVol1);
    lastBeatVol = currentVol1;
  }

  currentVol2 = analogRead(A2)/8;
  if(currentVol2 != lastBeatVol2){
    MIDIMessage(177, 2, currentVol2); //the values 1, & 2 need to be different. May be obvious but I forgot about it. 
    lastBeatVol2 = currentVol2;
  }

  long currentMillis = millis();
  
  if(analogRead(A3) < 255){
    ledState = LOW;
    digitalWrite(19, ledState);
    pitch1 = 36;
    pitch2 = 37;
    pitch3 = 38;
    pitch4 = 39;
    pitch5 = 40;
    pitch6 = 41;
    pitch7 = 44;
    pitch8 = 45;
    pitch9 = 46;
    pitch10 = 47;
    pitch11 = 48;
    pitch12 = 49;
  }
  else if(analogRead(A3) < 511){
    
    if(currentMillis - previousMillis >= interval1){
      previousMillis = currentMillis;
      if(ledState == LOW)
        ledState = HIGH;
      else
        ledState = LOW;
      digitalWrite(19, ledState);
    }
    pitch1 = 52;
    pitch2 = 53;
    pitch3 = 54;
    pitch4 = 55;
    pitch5 = 56;
    pitch6 = 57;
    pitch7 = 60;
    pitch8 = 61;
    pitch9 = 62;
    pitch10 = 63;
    pitch11 = 64;
    pitch12 = 65;
  }
  else if(analogRead(A3) < 767){

    if(currentMillis - previousMillis >= inverval2){
      previousMillis = currentMillis;
      if(ledState == LOW)
        ledState = HIGH;
      else
        ledState = LOW;
      digitalWrite(19, ledState);
    }
    pitch1 = 69;
    pitch2 = 70;
    pitch3 = 71;
    pitch4 = 72;
    pitch5 = 73;
    pitch6 = 74;
    pitch7 = 77;
    pitch8 = 78;
    pitch9 = 79;
    pitch10 = 80;
    pitch11 = 81;
    pitch12 = 82;
  }
  else{
    digitalWrite(19, HIGH);
    pitch1 = 85;
    pitch2 = 86;
    pitch3 = 87;
    pitch4 = 88;
    pitch5 = 89;
    pitch6 = 90;
    pitch7 = 91;
    pitch8 = 92;
    pitch9 = 93;
    pitch10 = 94;
    pitch11 = 95;
    pitch12 = 96;
  }
  
  if(lastState1 == LOW && currentState1 == HIGH)  //if the pervious state was low and now it's high, send the ON message
   {
    MIDIButton(on, pitch1, gv);
    lastState1 = HIGH;
   }
   if(currentState1 == LOW && lastState1 == HIGH) //if the previous state was high and now it's low, send the OFF message
   {
    MIDIButton(off, pitch1, gv); //right here accidentally made it all for the second state
    lastState1 = LOW;
   }
  
   if(lastState2 == LOW && currentState2 == HIGH)
   {
    MIDIButton(on, pitch2, gv);
    lastState2 = HIGH;
   }
   if(currentState2 == LOW && lastState2 == HIGH)
   {
    MIDIButton(off, pitch2, gv);
    lastState2 = LOW;
   }

   if(lastState3 == LOW && currentState3 == HIGH)
   {
    MIDIButton(on, pitch3, gv);
    lastState3 = HIGH;
   }
   if(currentState3 == LOW && lastState3 == HIGH)
   {
    MIDIButton(off, pitch3, gv);
    lastState3 = LOW;
   }

   if(lastState4 == LOW && currentState4 == HIGH)
   {
    MIDIButton(on, pitch4, gv);
    lastState4 = HIGH;
   }
   if(currentState4 == LOW && lastState4 == HIGH)
   {
    MIDIButton(off, pitch4, gv);
    lastState4 = LOW;
   }

   if(lastState5 == LOW && currentState5 == HIGH)
   {
    MIDIButton(on, pitch5, gv);
    lastState5 = HIGH;
   }
   if(currentState5 == LOW && lastState5 == HIGH)
   {
    MIDIButton(off, pitch5, gv);
    lastState5 = LOW;
   }

   if(lastState6 == LOW && currentState6 == HIGH)
   {
    MIDIButton(on, pitch6, gv);
    lastState6 = HIGH;
   }
   if(currentState6 == LOW && lastState6 == HIGH)
   {
    MIDIButton(off, pitch6, gv);
    lastState6 = LOW;
   }

   if(lastState7 == LOW && currentState7 == HIGH)
   {
    MIDIButton(on, pitch7, gv);
    lastState7= HIGH;
   }
   if(currentState7 == LOW && lastState7 == HIGH)
   {
    MIDIButton(off, pitch7, gv);
    lastState7 = LOW;
   }

   if(lastState8 == LOW && currentState8 == HIGH)
   {
    MIDIButton(on, pitch8, gv);
    lastState8 = HIGH;
   }
   if(currentState8 == LOW && lastState8 == HIGH)
   {
    MIDIButton(off, pitch8, gv);
    lastState8 = LOW;
   }

   if(lastState9 == LOW && currentState9 == HIGH)
   {
    MIDIButton(on, pitch9, gv);
    lastState9 = HIGH;
   }
   if(currentState9 == LOW && lastState9 == HIGH)
   {
    MIDIButton(off, pitch9, gv);
    lastState9 = LOW;
   }

   if(lastState10 == LOW && currentState10 == HIGH)
   {
    MIDIButton(on, pitch10, gv);
    lastState10 = HIGH;
   }
   if(currentState10 == LOW && lastState10 == HIGH)
   {
    MIDIButton(off, pitch10, gv);
    lastState10 = LOW;
   }

   if(lastState11 == LOW && currentState11 == HIGH)
   {
    MIDIButton(on, pitch11, gv);
    lastState11 = HIGH;
   }
   if(currentState11 == LOW && lastState11 == HIGH)
   {
    MIDIButton(off, pitch11, gv);
    lastState11 = LOW;
   }

   if(lastState12 == LOW && currentState12 == HIGH)
   {
    MIDIButton(on, pitch12, gv);
    lastState12 = HIGH;
   }
   if(currentState12 == LOW && lastState12 == HIGH)
   {
    MIDIButton(off, pitch12, gv);
    lastState12 = LOW;
   }
   
  //delay(20);
}

void MIDIButton(int command, int pitch, int velocity)
  {
     Serial.write(command); Serial.write(pitch); Serial.write(velocity);
     //coulda just written in the velocity here why didn't I think of that
  }

void MIDIMessage(byte command, byte data1, byte data2) //pass values out through standard Midi Command
{
   Serial.write(command); Serial.write(data1); Serial.write(data2);
}


 const int fsrPin = 9;      // pressure btn (white wires)
 const int switchPin = 1;   //contact switch (black wires)
 
 int fsrValue = 0;      // value read from the fsr
 int switchValue = 0;   // value read from the switch
 int fsrState = 0;      // calculate state of fsr based on threshold

 int fsrThresh = 200;
 
 const int OPEN     = 1;   // clip is open, in transit (fsr low, switch low)
 const int EMPTY    = 2;   // clip is closed, no paper in (fsr high, switch high)
 const int READY    = 3;   // clip is closed, paper in place (fsr high, switch low)
 const int UNSURE   = 4;   // initial state, also error state
 
 int state = UNSURE;
 
 boolean debug = false;
 
 void setup() {
   pinMode(switchPin, INPUT);
   pinMode(fsrPin, INPUT);              // set pin to input
   digitalWrite(switchPin, HIGH);       // turn on pullup resistors
  // digitalWrite(fsrPin, HIGH);          // turn on pullup resistors

   // initialize serial communications at 9600 bps:
   Serial.begin(9600); 
 }

 void loop() {
   int newState = UNSURE;
   
   // measure inputs
   fsrValue =  analogRead(fsrPin);     // read the FSR value

   if(fsrValue > fsrThresh)
    fsrState = HIGH; //closed
   else
    fsrState = LOW; //open
   
   switchValue = digitalRead(switchPin); // read the switch value
   
   // calculate current state
   newState = calcState(fsrState,switchValue);
   if (debug){
     Serial.print("state ");
     Serial.println(state, DEC);
     Serial.print("newState ");
     Serial.println(newState, DEC);
     Serial.print("fsr value");
     Serial.println(fsrValue, DEC);
     Serial.print("fsr state");
     Serial.println(fsrState, DEC);
     Serial.print("switch ");
     Serial.println(switchValue, DEC);
   }
   // calculate change. report if change detected
   if (newState != state && newState != UNSURE){
     if (debug){
         Serial.print("change detected, old = ");
         Serial.print(state, DEC);
         Serial.print(", new = ");
         Serial.println(newState, DEC);
         
     }
     delay(50);
     // check again to make sure reading wasn't a fluke
     if (newState == calcState(fsrState,switchValue)){
       state = newState;
       if (debug){
         Serial.print("Change reported, state = ");
         Serial.println(state, DEC);
         Serial.println("");
         delay(2000);
       }
       //report change
       Serial.print(state, DEC);
     }
   }
   delay(20); 
   
   if (debug){ 
     delay(1000);
   }
   
 }
 
 int calcState(int fsr, int sw){
   int newState = UNSURE;
   if (fsr == HIGH && sw == HIGH){
     newState = EMPTY;
     if (debug){ 
       Serial.println("EMPTY");
     }
   }
   else if (fsr == HIGH && sw == LOW){
     newState = READY;
     if (debug){ 
       Serial.println("READY");
     }
   }
   else if (fsr == LOW && sw == LOW){
     newState = OPEN;
     if (debug){ 
       Serial.println("OPEN");
     }
   }
   else {
    //error 
    newState = UNSURE;
    if (debug){ 
      Serial.println("ERROR");
    }
   }
   return newState;
 }

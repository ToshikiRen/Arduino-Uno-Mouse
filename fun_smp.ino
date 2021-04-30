
void setup() 
{
  Serial.begin(9600);   // COM speed 
  pinMode(9,INPUT);     // left click
  digitalWrite(9,HIGH);

}
int prev_state=0;   // last button state
void loop() {

  int z=0,xpos=0,ypos=0;
  int x=analogRead(A0);
  int y=analogRead(A1);
  int sensitivity=5;    // sensitivity, you can adjust this based on your preferences
  if(x>=550)                     // moved up 
  xpos=map(x,550,1023,0,sensitivity); 
  if(x<=450)                   // moved down
  xpos=map(x,450,0,0,-sensitivity);   
  if(y>=550)                    // moved right
  ypos=map(y,550,1023,0,sensitivity);  
  if(y<=450)                  // moved left
  ypos=map(y,450,0,0,-sensitivity); 
  int curr_state=digitalRead(9); // read button press
  if(curr_state==1 && prev_state==0)   // if the button was pressed, rising edge detection
    z=1; // button was pressed
  else
    z=0; // button was not pressed

  // The data below it's captured using python and used to command the mouse
  if(xpos!=0 or ypos!=0 or z==1) // prints only when the joystick is moved
  {
    Serial.print(xpos);    // print the data and separating by ":"
    Serial.print(":");
    Serial.print(ypos);
    Serial.print(":");
    Serial.println(z);
  }
  // Update the state
  prev_state=curr_state;
  delay(10);         // for normal operation
}

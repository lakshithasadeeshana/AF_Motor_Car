
#include<AFMotor.h>

int speed_PWM;
AF_DCMotor Right01(1);
AF_DCMotor Right02(2);
AF_DCMotor Right03(3);
AF_DCMotor Right04(4);

int ch1,ch2,ch3,ch4,ch5,ch6;

void setup() {

  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Serial.begin(115200); 

}

void loop() {

 ch1 =pulseIn(A0,HIGH,21000);
 ch2 =pulseIn(A1,HIGH,21000);
 ch3 =pulseIn(A2,HIGH,21000);
 ch4 =pulseIn(A3,HIGH,21000);
 ch5 =pulseIn(A4,HIGH,21000);//Arming chanel
 ch6 =pulseIn(A5,HIGH,21000);

speed_PWM = 200;

  if(ch5>1500){
 digitalWrite(11,HIGH);
 digitalWrite(13,LOW);
 digitalWrite(12,LOW);

Serial.print("CH1= ");
Serial.print(ch1);
Serial.print("\t");

Serial.print("CH2= ");
Serial.print(ch2);
Serial.print("\t");

Serial.print("CH3= ");
Serial.print(ch3);
Serial.print("\t");

Serial.print("CH4= ");
Serial.print(ch4);
Serial.print("\t");

Serial.print("CH5= ");
Serial.print(ch5);
Serial.print("\t");

Serial.print("CH6= ");
Serial.print(ch6);
Serial.println("\t");

 if(ch3>1600){
  backword();
  }
else if(ch3<1300){
    
    forward();
    }
    
   else if(ch1<1300){
    Serial.println("LSS");
  dleft();
  }
  else if(ch1>1600){
  dright();
  }
  else if(ch3<1600&&ch3>1300){
     Right01.run(RELEASE);
     Right02.run(RELEASE);
     Right03.run(RELEASE);
     Right04.run(RELEASE);
      }
  else{
     Right01.run(RELEASE);
     Right02.run(RELEASE);
     Right03.run(RELEASE);
     Right04.run(RELEASE);
    }
}
else {
  Serial.println("Not Arm");
  digitalWrite(11,LOW);
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
     Right01.run(RELEASE);
     Right02.run(RELEASE);
     Right03.run(RELEASE);
     Right04.run(RELEASE);
  
  }
}//end loop


void forward(){
     Right01.setSpeed(speed_PWM);
     Right02.setSpeed(speed_PWM);
     Right03.setSpeed(speed_PWM);
     Right04.setSpeed(speed_PWM);
     
     Right01.run(FORWARD);
     Right02.run(FORWARD);
     Right03.run(FORWARD);
     Right04.run(FORWARD);
  
  }
void backword(){
     Right01.setSpeed(speed_PWM);
     Right02.setSpeed(speed_PWM);
     Right03.setSpeed(speed_PWM);
     Right04.setSpeed(speed_PWM);
     
     Right01.run(BACKWARD);
     Right02.run(BACKWARD);
     Right03.run(BACKWARD);
     Right04.run(BACKWARD);
  }

 void dleft(){
     Right01.setSpeed(speed_PWM);
     Right02.setSpeed(speed_PWM);
     Right03.setSpeed(speed_PWM);
     Right04.setSpeed(speed_PWM);
     
     Right01.run(FORWARD);
     Right02.run(FORWARD);
     Right03.run(BACKWARD);
     Right04.run(BACKWARD);
  }
   void dright(){
     Right01.setSpeed(speed_PWM);
     Right02.setSpeed(speed_PWM);
     Right03.setSpeed(speed_PWM);
     Right04.setSpeed(speed_PWM);
     
     Right01.run(BACKWARD);
     Right02.run(BACKWARD);
     Right03.run(FORWARD);
     Right04.run(FORWARD);
  }
       void sit(){

     Right01.setSpeed(0);
     Right02.setSpeed(0);
     Right03.setSpeed(0);
     Right04.setSpeed(0);
     
     Right01.run(RELEASE);
     Right02.run(RELEASE);
     Right03.run(RELEASE);
     Right04.run(RELEASE);

     }

 

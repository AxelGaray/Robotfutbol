#Robot arduino con bluethoot. Testing
#include <SoftwareSerial.h>
#include <AFMotor.h>
SoftwareSerial BT(51,50); // TX,RX

AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
AF_DCMotor Motor3(3);
AF_DCMotor Motor4(4);

int Vel = 130 ; // Define la velocidad base del Rover,130 si ponemos mas las pilas a tope de power!

void setup() 
{

BT.begin(9600) ;
pinMode(49, OUTPUT) ; // Usaremos el pin 49 como VCC de 5V
digitalWrite(49, HIGH);

}

 

void loop() 
{
Serial.write(BT.read());
if (BT.available()){

switch (BT.read())
{
    case 'F':
        Avance();
        break;
    case 'B':
        Retroceso();
        break;
    case 'R':
        giroDerecha();
        break;
    case 'L':
        giroIzquierda();
        break;
    case 'S':
        Paro();
        break;
}}}

 

void SetVel(int v1, int v2, int v3, int v4)
{
Motor1.setSpeed(v1);
Motor2.setSpeed(v2);
Motor3.setSpeed(v3);
Motor4.setSpeed(v4); 
}

void Avance()
{ 
SetVel(Vel,Vel,Vel,Vel);
Motor1.run(FORWARD) ;
Motor2.run(FORWARD);
Motor3.run(FORWARD);
Motor4.run(FORWARD); 
}

void Retroceso()
{ 
SetVel(Vel,Vel,Vel,Vel);
Motor1.run(BACKWARD) ;
Motor2.run(BACKWARD);
Motor3.run(BACKWARD);
Motor4.run(BACKWARD);
}

void Paro()
{ Motor1.run(RELEASE);
Motor2.run(RELEASE);
Motor3.run(RELEASE);
Motor4.run(RELEASE); 
}

void giroIzquierda()
{ 
SetVel( Vel, Vel, Vel, Vel) ;
Motor1.run(RELEASE) ;
Motor2.run(FORWARD);
Motor3.run(FORWARD);
Motor4.run(RELEASE); 
}

void giroDerecha()
{ 
SetVel( Vel, Vel, Vel, Vel) ;
Motor1.run(FORWARD) ;
Motor2.run(RELEASE);
Motor3.run(RELEASE);
Motor4.run(FORWARD); 
}
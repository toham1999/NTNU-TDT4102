#pragma once
#include "std_lib_facilities.h"

constexpr double pi = 3.14159265;
constexpr double gravity = 9.81;

// Del 1:

// BEGIN: 1a
// Deklarer funksjonen acclY 
double acclY();
// END: 1a

// BEGIN: 1b
// Deklarer funksjonen velY
double velY(double initVelocityY,double time);
// END: 1b

// BEGIN: 1c
// Deklarer funksjonene posX og posY
double posX(double initPositionX,double initVelocityX,double time);
double posY(double initPositionY,double initVelocityY,double time);
// END: 1c

// BEGIN: 1d
// Deklarer funksjonen printTime
void printTime(double time);
// END: 1d

// BEGIN: 1e
// Deklarer funksjonen flightTime
double flightTime(double initVelocityY);
// END: 1e

bool testDeviation(double compareOperand, double toOperand, double maxError, string name);


// Del 2:
// BEGIN: 4a
// Her skal du deklarere ALLE funksjonene i oppgave 4a
// Ber brukeren om en vinkel i grader
double getUserInputTheta();

//Ber brukeren om en startfart
double getUserInputInitVelocity();

// Konverterer fra grader til radianer
double degToRad(double deg);

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta i grader og en startfart initVelocity.
double getVelocityX(double theta, double initVelocity);
double getVelocityY(double theta, double initVelocity);

// Dekomponerer farten gitt av initVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double initVelocity);
// END: 4a

// BEGIN: 4b
double getDistanceTraveled(double velocityX, double velocityY);
// END: 4b

// BEGIN: 4c
double targetPractice(double distanceToTarget, double velocityX, double velocityY);
// END: 4c


// Del 3:

// BEGIN: 5b
// Deklarer funksjonen playTargetPractice her
void playTargetPractice();
// END: 5b

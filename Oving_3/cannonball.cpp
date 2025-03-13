#include "cannonball.h"
#include "cannonball_viz.h"
#include "utilities.h"

// BEGIN: 2a
// Implementer funksjonen acclY
double acclY() {
    return -9.81;
}
// END: 2a

// BEGIN: 2b
// Implementer funksjonen velY
double velY(double initVelocityY,double time) {
    return initVelocityY + (acclY() * time);
}
// END: 2b

// BEGIN: 2c
// Implementer funksjonene posX og posY
double posX(double initPositionX,double initVelocityX,double time) {
    return initPositionX + (initVelocityX*time);
}

double posY(double initPositionY,double initVelocityY,double time) {
    return initPositionY + (initVelocityY*time) + (acclY()*pow(time,2))/2;
}
// END: 2c

// BEGIN: 2d
// Implementer funksjonen printTime
void printTime(double time) {
    int hours = static_cast<int>(time)/3600;
    int minutes = (static_cast<int>(time)%3600)/60;
    int seconds = (static_cast<int>(time)%60);
    cout << "There is " << hours << " hours, " << minutes << " min, and " << seconds << " sec" <<endl;
}
// END: 2d

// BEGIN: 2e
// Implementer funksjonen flightTime
double flightTime(double initVelocityY) {
    return -2 * initVelocityY/acclY();
}
// END: 2e

// BEGIN: 3b
// Implementer funksjonen testDeviation

bool testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    if (abs(compareOperand - toOperand) <= maxError) {
        cout << name + " is valid." << endl;
        return true;
    }
    else {
        cout << name + " is not valid." << endl;
        return false;
    }
}
// END: 3b

// BEGIN: 4a
// Her skal du implementere ALLE funksjonene i oppgave 4a
// Ber brukeren om en vinkel i grader
double getUserInputTheta() {
    cout << "Enter an angle in degrees: ";
    double theta;
    cin >> theta;
    return theta;
}

//Ber brukeren om en startfart
double getUserInputInitVelocity() {
    cout << "Enter an initial velocity: ";
    double initVelocity;
    cin >> initVelocity;
    return initVelocity;
}

// Konverterer fra grader til radianer
double degToRad(double deg) {
    return deg * pi / 180;
}

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta i grader og en startfart initVelocity.
double getVelocityX(double theta, double initVelocity) {
    return initVelocity * cos(degToRad(theta));
}
double getVelocityY(double theta, double initVelocity) {
    return initVelocity * sin(degToRad(theta));
}

// Dekomponerer farten gitt av initVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double initVelocity) {
    return {getVelocityX(theta, initVelocity), getVelocityY(theta, initVelocity)};
}
// END: 4a

// BEGIN: 4b
double getDistanceTraveled(double velocityX, double velocityY) {
    double time = flightTime(velocityY);
    return posX(0, velocityX, time);
}
// END: 4b

// BEGIN: 4c
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    cout << fixed << setprecision(2);
    return distanceToTarget-getDistanceTraveled(velocityX,velocityY); 
}
// END: 4c


// BEGIN: 5b
void playTargetPractice() {
    int target = randomWithLimits(100,1000);
    cout << "Velkommen til kanonkule spill!" << endl;
    cout << target << endl;

    for (int i=10;i>0;i--) {
        cout << "Du har " << i << " forsøk igjen" << endl;
        double velocity = getUserInputInitVelocity();
        double theta = getUserInputTheta();
        vector <double> velocityVector = getVelocityVector(theta, velocity);


        double mytryCompared = targetPractice(target, velocityVector.at(0), velocityVector.at(1));
        double mytryTime = flightTime(velocity);

        

        if (abs(mytryCompared) < 5) {
            cout << "---Gratulerer du traff blinken---" << endl;
            cannonBallViz(target, 1000.0, velocityVector.at(0), velocityVector.at(1), 100);
            break;
        }
        else if (mytryCompared >= 5) {
            cout << "Du traff ikke blinken: " << mytryCompared << " meter for kort, flytid: " << mytryTime << " sek" << endl << endl;
            cannonBallViz(target, 1000.0, velocityVector.at(0), velocityVector.at(1), 100);
            if (i == 1) {
                cout << "Du aldri blinken, men du prøvde hardt, vurder å bytt til Dragvoll" << endl;
            }
        }
        else if (mytryCompared <= 5) {
            cout << "Du traff ikke blinken: " << abs(mytryCompared) << " meter for langt, flytid: " << mytryTime << " sek" << endl << endl;
            cannonBallViz(target, 1000.0, velocityVector.at(0), velocityVector.at(1), 100);
            if (i == 1) {
                cout << "Du aldri blinken, men du prøvde hardt, vurder å bytte til Dragvoll" << endl;
            }
        }
    }
}
// END: 5b

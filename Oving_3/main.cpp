#include "std_lib_facilities.h"
#include "cannonball.h"
#include "cannonball_viz.h"
#include "utilities.h"
double maxError = 0.001;
int main() {
	/*
	//printTime(3719);
	testDeviation(posX(0.0,50.0,5.0), 250.0, maxError, "posX(0.0,50.0,5.0)");
	vector <double> test = getVelocityVector(27.5, 15.64);
	cout << test.at(0) << ", " << test.at(1) << endl;
	cout << "Distance " << getDistanceTraveled(test.at(0), test.at(1)) << endl;
	cout << "Avvik distanse " << targetPractice(10, test.at(0), test.at(1)) << " m" << endl;

	for (int i = 0; i<5; i++){
		cout << randomWithLimits(1,90) << ", ";
	}
	cout << endl;
	*/
	playTargetPractice();
		
	return 0;
}
#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
	for (int i = 0; i < numTimes; i++)
		startValue += increment;

	return startValue;
}

// BEGIN: 1d
///*returverdi*/ incrementByValueNumTimesRef(/*param 1: startValue(ref), param 2: increment, param 3: numtimes*/){}
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
	for (int i=0;i<numTimes;i++) {
		startValue += increment;
	}
}
// END: 1d

// BEGIN: 1e
///*returverdi*/ swapNumbers(/*parametre*/){}
void swapNumbers(int& heltall_1,int& heltall_2) {
	int temp = heltall_2;
	heltall_2 = heltall_1;
	heltall_1 = temp;
}

/*
Om vi kan endre på den originale listen så er det bedre med ref, for
den bruker mindre minne pga siden vi ikke trenger å lage kopi. Ellers
er pass-by-value bedre om vi ikke vil påvirke orginalen.
*/
// END: 1e

// BEGIN: 2b
///*returverdi*/ printStudent(/*input Student*/) {}
void printStudent(const Student& stud) {
	cout << "Studenten " << stud.name << " går på linjen " 
	<< stud.studyProgram << " og er " << stud.age << " år" << endl;
}
// END: 2b

// BEGIN: 2c
///*returverdi*/ isInProgram(/*param 1: Student, param 2: string*/){}
bool isInProgram(const Student& stud,string program) {
	bool sameStudyProgram = stud.studyProgram == program;
	return sameStudyProgram;
}
// END: 2c


// BEGIN: 3a
///*returverdi*/ randomizeString(/*param 1: antall tegn, param 2: øvre grense, param 3: nedre grense */) 
string randomizeString(int numberOfSigns,char upperLimit,char lowerLimit) {
	string randomString = "";
	int upper = lowerLimit;
	int lower = upperLimit;
	random_device seed;
	default_random_engine generator(seed());
	uniform_int_distribution<int> distribution(lower,upper);
	for (int i=0;i<numberOfSigns;i++) {
		char letter = distribution(generator);
		randomString.push_back(letter);
	}
	return randomString;
}
// 65 = A, 90 = Z, a=97, z=122
// END: 3a

// BEGIN: 3c
///*returverdi*/ readInputToString(/*param 1: lengde n, param 2: øvre grense, param 3: nedre grense*/)
string readInputToString(int n,char upperLimit,char lowerLimit) 
{
	string randomString = "";
	string tempString;
	while (randomString.size() < n) 
	{
		cout << "Skriv inn minst " << n << " tegn: ";
		cin >> tempString;
		if (tempString.size() < n)
		{
			cout << "Prøv igjen med lengre ord" << endl;
			continue;
		}
		for (int i=0;i<tempString.size();i++)
		{
			if (upperLimit <= tempString.at(i) && tempString.at(i) <= lowerLimit)
			{
				randomString.push_back(tempString.at(i));
			}
			else if (upperLimit + 32 <= tempString.at(i) && tempString.at(i) <= lowerLimit + 32)
			{
				randomString.push_back(tempString.at(i)-32);
			}
		}
		if (randomString.size() < n) 
		{
			cout << "Prøv igjen med andre bokstaver" << endl;
		}
	}
	return randomString;
}
// END: 3c

// BEGIN: 3d
///*returverdi*/ countChar(/*param 1: string, param 2: char*/)
int countChar(const string& justString,char letter)
{
	return count(justString.begin(), justString.end(), letter);
}
// END: 3d

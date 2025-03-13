#include "test.h"

void testCallByValue()
{
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0 << " increment: " << increment
		 << " iterations: " << iterations << " result: " << result << '\n';
}

void testCallByReference()
{
	// BEGIN: 1d
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	cout << "v0: " << v0 << " increment: " << increment;
	incrementByValueNumTimesRef(v0, increment, iterations);
	cout << " iterations: " << iterations << " result: " << v0 << '\n';
	// END: 1d

}


void testString(){
	// 3b OG 3e gjøres inne i her
	// BEGIN: 3e
	string grades = randomizeString(8,'A','F');
	cout << "Random grades: " << grades << endl;
	
	vector<int> gradecount = {0,0,0,0,0,0};
	int gradeSum = 0;
	int index = 0;
	for (char grade : {'A','B','C','D','E','F'}) 
	{
		int tempCount = countChar(grades,grade);
		index = grade - 'A';
		gradecount[index] = tempCount;
		gradeSum += tempCount * (6 - index);
		cout << grade << ": " << tempCount << ", ";
	}
	cout << fixed << setprecision(2);
	cout << "Gradesum: " << gradeSum/grades.size() << endl;
	// END: 3e
}
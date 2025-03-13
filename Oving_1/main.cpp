// Øving 1
// Oversettelse fra Python til C++
#include "std_lib_facilities.h"

int maxOfTwo(int a, int b)   {
    // BEGIN: 2a
	if (a>b) {
        cout << "A is greater than B" << endl;
        return a;
    }
    else {
        cout << "B is greater than A" << endl;
        return b;
    }
    // END: 2a
}

int fibonacci(int n) {
    // BEGIN: 2c
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers" << endl;
    for (int x = 1; x < n+1; ++x) {
        cout << x << " " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----" << endl;
    return b;
    // END: 2c
}

int squareNumberSum(int number) {
    // BEGIN: 2d
    int totalSum = 0;
    for (int i=1; i < number+1; ++i) {
        totalSum += i * i;
        cout << i * i << endl;
    }
    cout << totalSum << endl;
    return totalSum;
    // END: 2d
}

void triangleNumbersBelow(int number) {
    // BEGIN: 2e
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << number << ":" << endl;
    while (acc<number) {
        cout << acc << endl;
        acc += num;
        num += 1;
    }
    cout << " " << endl;
    // END: 2e
}

bool isPrime(int number) {
    // BEGIN: 2f
    for (int j=2; j<number; ++j) {
        if (number % j == 0) {
            return false;
        }
    }
    return true;
    // END: 2f
}

void naivePrimeNumberSearch(int maxNumber) {
    // BEGIN: 2g
    for (int number=2; number<maxNumber; ++number) {
        if (isPrime(number)) {
            cout << number << " is a prime" << endl;
        }
    }
    // END: 2g 
}

void inputAndPrintNameAndAge() {
    // BEGIN: 2h
    string name = "hest";
    int age = 99;
    cout << "Skriv inn et navn: " << endl;
    cin >> name;
    cout << "Skriv inn alderen til " << name << ": " << endl;
    cin >> age;
    cout << name << " er " << age << " år gammel" << endl;
    // END: 2h
}

int main() {
    // BEGIN: 2b
    cout << "Oppgave a)" << endl;
    cout << maxOfTwo(5,6) << endl;
    // END: 2b
    cout << "Oppgave c)" << endl;
    cout << fibonacci(2) << endl;
    cout << "Oppgave d)" << endl;
    cout << squareNumberSum(5) << endl;
    cout << "Oppgave e)" << endl;
    triangleNumbersBelow(10);
    cout << "Oppgave f)" << endl;
    cout << isPrime(7) << endl;
    cout << "Oppgave g)" << endl;
    naivePrimeNumberSearch(14);
    cout << "Oppgave h)" << endl;
    inputAndPrintNameAndAge();

	return 0;
}

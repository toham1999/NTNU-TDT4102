//handout oving 2

#include "std_lib_facilities.h"
#include "AnimationWindow.h"


void inputAndPrintInteger() {
    // BEGIN: 1b
    cout << "Skriv inn et heltall: ";
    int choice; cin >> choice;
    cout << "Du skrev: " << choice << endl;
    // END: 1b
}

int inputInteger() {
    // BEGIN: 1c
    cout << "Skriv inn et heltall: ";
    int choice; cin >> choice;
    return choice;
    // END: 1c
}

void printSumOfInputIntegers() {
    // BEGIN: 1d
    cout << "Skriv inn 2 heltall: ";
    int choice1; cin >> choice1;
    int choice2; cin >> choice2;
    cout << "Summen er: " << choice1 + choice2 << endl;
    // END: 1d
}

bool isOdd(int n) {
    // BEGIN: 1f
    if (n % 2 == 1) {
        return true;
    }
    return false;
    // END: 1f
}

void inputIntegersAndPrintSum() {
    // BEGIN: 2a
    cout << "Skriv inn antall heltall: ";
    int n; cin >> n;
    int summ = 0;
    for (int i = 0; i < n; i++) {
        int number; cin >> number;
        summ += number;
    }
    cout << "Summen av heltallene er: " << summ << endl;
    // END: 2a
}

void inputIntegersAndPrintSumUntilStopped() {
    // BEGIN: 2b
    cout << "Skriv inn x antall heltall til 0 blir skrevet: ";
    int summ = 0;
    bool cont = true;
    int number;
    while (cont) {
        cin >> number;
        summ += number;
        if (number == 0) {
            cont = false;
        }
    }
    cout << "Summen av heltallene er: " << summ << endl;
    // END: 2b
}

double inputDouble() {
    // BEGIN: 2d
    cout << "Skriv inn et desimaltall: ";
    double choice; cin >> choice;
    return choice;
    // END: 2d
}

void convertNOKtoEUR() {
    // BEGIN: 2e
    cout << "Skriv inn summen som skal konverteres fra NOk til EUR: ";
    double choice = 0; cin >> choice;
    while (choice < 0) {
        cout << "Ugyldig verdi, prøv igjen: ";
        cin >> choice;
    }
    double eur = choice / 10.5;
    cout << "Summen er " << fixed << setprecision(2) << eur << " Euro" << endl;
    // END: 2e
}

void printMultiplicationTable() {
    // BEGIN: 2g
    cout << "Bestem høyden på tabellen: " << endl;
    int h; cin >> h;
    cout << "Bestem bredden på tabellen: " << endl;
    int b; cin >> b;
    for (int i = 1;i<=h;i++) {
        for (int j = 1;j<=b;j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
    // END: 2g
}

double discriminant(double a, double b, double c) {
    // BEGIN: 3a
    return pow(b, 2) - 4 * a * c;
    // END: 3a
}

void printRealRoots(double a=1, double b=5, double c=6) {
    // BEGIN: 3b
    double sol = discriminant(a, b, c);
    if (sol > 0) {
        cout << "Det er to løsninger: X=" << - (b - sqrt(sol)) / (2 * a) << " og X=" << -(b + sqrt(sol)) / (2 * a) << endl;
    }
    else if (sol == 0) {
        cout << "Det er en løsning: X=" << -b / (2 * a) << endl;
    }
    else {
        cout << "Det er ingen løsninger" << endl;
    }
    // END: 3b
}

void solveQuadraticEquations() {
    // BEGIN: 3c
    cout << "Skriv inn a, b og c: ";
    double a; cin >> a;
    double b; cin >> b;
    double c; cin >> c;
    printRealRoots(a, b, c);
    // END: 3c
}
void pythagoras() {
    // BEGIN: 4a
    int w = 800, h = 800;
    AnimationWindow win{100, 100, w, h, "Pythagoras"};

    // Triangle vertices
    Point point1{200, 400}; // Top-left
    Point point2{200, 500}; // Bottom-left
    Point point3{400, 500}; // Bottom-right
    win.draw_triangle(point1, point2, point3, Color::red);

    // Draw square on side a (vertical side)
    Point a1 = point1; // Top-right
    Point a2 = point2; // Bottom-right
    Point a3{point1.x - point2.y + point1.y, point1.y}; // Bottom-left
    Point a4{point2.x - point2.y + point1.y, point2.y}; // Top-left
    win.draw_quad(a1, a2, a4, a3, Color::green);

    // Draw square on side b (horizontal side)
    Point b1 = point2; // Bottom-left
    Point b2 = point3; // Bottom-right
    Point b3{point3.x, point3.y + point3.x - point2.x}; // top-right
    Point b4{point2.x, point2.y + point3.x - point2.x}; // top-left
    win.draw_quad(b1, b2, b3, b4, Color::yellow);

    // Draw square on hypotenuse c
    Point c1 = point1; // Top-left
    Point c2 = point3; // Bottom-middle
    Point c3{point3.x + (point2.y - point1.y), point3.y - (point3.x - point2.x)}; // Top-right
    Point c4{point1.x + (point2.y - point1.y), point1.y - (point3.x - point2.x)}; // top-middle
    win.draw_quad(c1, c2, c3, c4, Color::blue);

    win.wait_for_close();
    // END: 4a
}


vector<int> calculateBalance(int amount, int rate, int years) {
    // BEGIN: 5a
    vector<int> balanceVec = {amount};
    int saldo = amount;
    for (int i = 0; i < years; i++) {
        saldo += saldo * (static_cast<double>(rate) / 100);
        balanceVec.push_back(saldo);
    }
    return {balanceVec};
    // END: 5a
}

void printBalance(vector<int> balanceVec) {
    // BEGIN: 5b
    cout << setw(5) << "År" << setw(10) << "Saldo" << endl;
    for (int i = 0; i < balanceVec.size(); i++) {
        cout << setw(4) << i << setw(10) << balanceVec[i] << endl;
    }
    // END: 5b
}

int main() {
    // Oppgave 1a
    // pythagoras();
    //printBalance(calculateBalance(5000, 3, 10));
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }



    int choice = 0;
    bool cont = true;
    while (cont == true) {
        cout << "Velg funksjon; \n   0) Avslutt\n   ";   
        cout << "1) Skriv inn heltall og print\n   2) Skriv inn heltall og returner\n   3) Summer 2 heltall\n   ";
        cout << "4) Sjekk om heltall mellom 0-15 er oddetall\n   5) Skriv inn x antall heltall\n   6) Skriv inn heltall til 0 blir skrevet\n   ";
        cout << "7) Skriv ut gangetabell\n   8) Skriv ut røttene til en kvadratisk uttrykk\n   9) Konverter NOK til EUR\nAngi valg (0-9): ";
        cin >> choice;
        if (choice == 0) {
            cout << "Takk for bruk av funksjoner" << endl;
            cont = false;
        }
        else if (choice == 1) {
            inputAndPrintInteger();
        }
        else if (choice == 2) {
            int number = inputInteger();
            cout << "Du skrev: " << number << endl;
        }
        else if (choice == 3) {
            printSumOfInputIntegers();
        }
        else if (choice == 4) {
            for (int i=0;i<16;i++) {
                int number = isOdd(i);
                if (number == 1) {
                    cout << i << " er oddtall" << endl;
                }
            }
        }
        else if (choice == 5) {
            inputIntegersAndPrintSum();
        }
        else if (choice == 6) {
            inputIntegersAndPrintSumUntilStopped();
        }
        else if (choice == 7) {
            printMultiplicationTable();
        }
        else if (choice == 8) {
            solveQuadraticEquations();
        }
        else if (choice == 9) {
            convertNOKtoEUR();
        }
        else {
            cout << "Ugyldig valg" << endl;
        }
    }
    // Her kan du teste funksjonene dine ved hjelp av menysystem som beskrevet. 
    // NB: Denne delen av koden blir IKKE automatisk rettet.
    // 1e) Fordi jeg ønsker en verdi og ikke en streng som blir printet ut, er enklere å behandle en returnert verdi.
    return 0;
}
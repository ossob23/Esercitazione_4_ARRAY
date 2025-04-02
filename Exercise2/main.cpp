#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Utils.hpp"
 // g++ requires: "src/Utils.hpp"
// #include "ClassObj.hpp" // error if pragma once is not used in ClassObj

using namespace std;

int main()
{
    string inputFile = "data.txt";
    double S = 0.0;  // Inizializza S
    int n = 10;   // Esempio di inizializzazione di n, adatta a seconda delle necessità
    double* w = nullptr;  // Inizializza ptr1
    double* r = nullptr;  // Inizializza ptr2
    
    // Chiama la funzione ImportVectors passando solo i parametri necessari
    ImportVectors(inputFile, S,n,w,r);
    double sordi = ROI(n,w,r,S);
    // Stampa il valore di S
    ofstream fileout("result.txt");
    cout << fixed << setprecision(2);
    fileout<< "S = " << S<<",";
    cout << fixed << setprecision(0);
    fileout<<" n = "<<n<<endl;
    fileout<< "w = " << ArrayToString(n,w)<<endl;
    fileout<< "r = " << ArrayToString(n,r)<<endl;
    cout << fixed << setprecision(4);
    fileout << "Rate of return of the portfolio: "<<interessi(sordi,S)<<endl;
    cout << fixed << setprecision(2);
    fileout<<"V: "<<sordi<<endl;
    return 0;
}
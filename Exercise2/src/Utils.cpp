
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Utils.hpp" // g++ requires: "src/Utils.hpp"
// #include "ClassObj.hpp" // error if pragma once is not used in ClassObj

using namespace std;
bool ImportVectors(const string& inputFile, double& S,int& n,double*& w,double*& r)
{
    ifstream file(inputFile);
    if (file.fail()) {
        return false;
    }

    string line;
    if (getline(file, line)) {
        if (line.size() > 2) {
            S = stoi(line.substr(2));  // Imposta S
        }
    }
    if (getline(file, line)) {
        if (line.size() > 2) {
            n = stoi(line.substr(2));  // Imposta n
        }
    }
    getline(file,line);
    w = new double[n];
    r = new double[n];
    for (int i =0;i<n &&getline(file,line);i++){
        stringstream ss(line);
        string parte;
        getline(ss,parte,';');
        w[i]=stod(parte);
        getline(ss,parte);
        r[i]=stod(parte);
    }
    file.close();
    return true;
}
string ArrayToString(const size_t& n,
    const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
    toString<< v[i]<< " ";
    toString << "]";
    return toString.str();
}
double ROI(const size_t& n, const double* const& w, const double* const& r, double& S){
    double sordi = 0.0;
    for(unsigned int i = 0;i<n;i++)
    sordi += w[i]*S*(1+r[i]);
    return sordi;
}
double interessi(double sordi, double S){
    double interesse = sordi/S-1.0;
    return interesse;
}
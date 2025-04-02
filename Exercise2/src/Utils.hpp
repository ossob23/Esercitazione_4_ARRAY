#pragma once


using namespace std;
bool ImportVectors(const string& inputFile, double& S,int& n,double*& w,double*& r);
string ArrayToString(const size_t& n,
    const double* const& v);
double ROI(const size_t& n, const double* const& w, const double* const& r, double& S);
double interessi(double sordi, double S);
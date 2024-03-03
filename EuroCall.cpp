#include <iostream>
#include <cmath>
#include <random>
#include "EuroCall.h"

using namespace std;

default_random_engine generator;
normal_distribution<double> normalDistribution(0.0,1.0);

void EuroCall::set_d2(double sigma){
    d2 = (log(S0/K) + (r - sigma*sigma/2))/(sigma * pow(T,0.5));
}

void EuroCall::set_d1(double sigma){
    d1 = (log(S0/K) + (r + sigma*sigma/2))/(sigma * pow(T,0.5));
}

double stdNormal_cdf(double x){
    return 0.5 * erfc(-x * M_SQRT1_2);
}

double EuroCall::priceByBS(double sigma){
    set_d1(sigma);
    set_d2(sigma);
    return S0 * stdNormal_cdf(d1) - K * exp(-r * T) * stdNormal_cdf(d2);
}

double EuroCall::vegaByBS(double sigma){
    set_d1(sigma);
    set_d2(sigma);
    return S0*exp(-d2 * d2) * sqrt(T) / sqrt(2.0*M_PI);
}
#include "solver.h"
#include "EuroCall.h"
#include <iostream>
#include <chrono>

using namespace std;

class EuroCall_VolFunc
: public EuroCall{
    public:
        EuroCall_VolFunc(double T_, double K_, double S0_, double r_):EuroCall(T_, K_, S0_, r_){};
        double f(double sigma){return priceByBS(sigma);}
        double df(double sigma){return vegaByBS(sigma);}
};

int main(){
    double S0 = 100.0;
    double r = 0.1;
    double T = 1.0;
    double K = 100.0;

    EuroCall_VolFunc call(T, K, S0, r);

    double acc = pow(10.0,-4);
    double lEnd = 0.0;
    double rEnd = 1.0;
    double target = 12.56;

    auto start = std::chrono::high_resolution_clock::now();
    cout << "Yield of bond by bisect method: " << solveByBisect(&call, target, lEnd, rEnd, acc) << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, milli>(stop - start);
    cout << "Running time for bisect method: " << duration.count() << "milliseconds."<< endl;

    double x0 = 1.0;
    start = std::chrono::high_resolution_clock::now();
    cout << "Yield of bond by Newton method: " << solveByNewton(&call, target, x0, acc) << endl;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration<double, milli>(stop - start);
    cout << "Running time for Newton method: " << duration.count() << "milliseconds."<< endl;

    return 0;
}
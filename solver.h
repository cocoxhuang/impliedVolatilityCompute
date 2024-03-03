#ifndef solver_h
#define solver_h

#include <iostream>
#include <cmath>

using namespace std;

template<typename function> double solveByBisect(function* func, double target, double lEnd, double rEnd, double acc){
    double l = lEnd;
    double r = rEnd;
    double mid = (l + r)/2;
    double y_l = func->f(l) - target;
    double y_mid = func->f(mid) - target;
    while ((mid - l) > acc){
        if(y_l * y_mid < 0){
            r = mid;
        }else{
            l = mid;
            y_l = y_mid;
        }
        mid = (l+r)/2;
        y_mid = func->f(mid) - target;
    }
    return mid;
}

template<typename function> double solveByNewton(function* func, double target, double x0, double acc){
    double x_cur = x0;
    double x_next = x_cur - (func->f(x_cur) - target)/(func->df(x_cur));
    while (x_next - x_cur > acc || x_cur - x_next > acc){
        x_cur = x_next;
        x_next = x_cur - (func->f(x_cur) - target)/(func->df(x_cur));
    }
    return x_next;
}
#endif
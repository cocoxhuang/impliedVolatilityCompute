#ifndef EuroCall_h
#define EuroCall_h

class EuroCall{
    public:
        double T,K,S0,r,d1,d2;
        EuroCall(double T_, double K_, double S0_, double r_){T = T_, K = K_, S0 = S0_, r = r_;}
        void set_d2(double sigma);
        void set_d1(double sigma);
        double priceByBS(double sigma);
        double vegaByBS(double sigma);
};

#endif
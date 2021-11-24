#pragma once

#include <cmath>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
#include <QDebug>
#include "MWCDParams.h"
class MWCDModel final
{
    friend QDebug operator <<( QDebug os, const MWCDModel &model )
    {
        os << model._mwcdParams;
        return os;
    }

private:
    ~MWCDModel();
    MWCDModel();
    MWCDModel( double K, double hp, double rg,
               double u, double rw, double r1,
               double S, double re, double q,
               double h2, double fi, double Swi, double Sgr );

    MWCDModel( const MWCDModel & model )        = delete;
    MWCDModel & operator =( const MWCDModel & ) = delete;


public:
    static MWCDModel & getMWCDModel();


    static void printModelParams();


    static MWCDModel* getTestModel();


public:


    std::tuple<std::vector<double>, std::vector<double> > getBTPredicionData();// get breakthrough time predicion data


    std::tuple<std::vector<double>, std::vector<double> > getITPredicionData( const double & year );// get input time predicion data


    double getBreakthroughTime();


    void setParamFi( const double & );


    void setParamH2( const double & );


    void setParamK( const double & );


    void setParamHp( const double & );


    void setParamR1( const double & );


    void setParamS( const double & );


    void setParamRe( const double & );


    void setParamQ( const double & );


    void setModelParams( double K, double hp, double rg,
                         double u, double rw, double r1,
                         double S, double re, double q,
                         double h2, double fi, double Swi, double Sgr );


    bool paramsHasZero();


private:
    MWCDParams _mwcdParams;
};


#include "MWCDModel.h"
#include <utility>
MWCDModel::~MWCDModel()
{
    qDebug() << "~MWCDModel";
}

MWCDModel::MWCDModel() :
    _mwcdParams()
{
}

MWCDModel::MWCDModel( double K, double hp, double rg, double u, double rw, double r1, double S,
                      double re, double q, double h2, double fi, double Swi, double Sgr ) :
    _mwcdParams( K, hp, rg, u, rw, r1, S, re, q, h2, fi, Swi, Sgr )
{
    if( !_mwcdParams.hasParamIsZero() )
    {
    }
    else
    {
        qDebug() << "error: input params has 0";
    }

}

MWCDModel &MWCDModel::getMWCDModel()
{
    static MWCDModel model;
    return model;

}

void MWCDModel::printModelParams()
{
    qDebug() << MWCDModel::getMWCDModel();
}

std::tuple<std::vector<double>, std::vector<double> > MWCDModel::getBTPredicionData()
{
    if( _mwcdParams.hasParamIsZero() )
    {
        std::vector<double> x( 0 ), y( 0 );
        return std::make_tuple( x, y );
    }
    return _mwcdParams.getBTPredicionData();
}

std::tuple<std::vector<double>, std::vector<double> > MWCDModel::getITPredicionData( const double & year  )
{
    if( _mwcdParams.hasParamIsZero() )
    {
        std::vector<double> x( 0 ), y( 0 );
        return std::make_tuple( x, y );
    }
    return _mwcdParams.getITPredicionData( year );
}

MWCDModel *MWCDModel::getTestModel()
{
    return new MWCDModel( 0.2, 248.8, 0.6, 0.02,
            0.05, 80, -6.4, 570,
            200000, 80, 0.045, 0.165, 0.05 );
}

double MWCDModel::getBreakthroughTime()
{
    _mwcdParams.updatePredicion();
    return _mwcdParams.getBreakthroughTime();
}

void MWCDModel::setParamFi( const double &fi )
{
    _mwcdParams.setFi( fi );
}

double MWCDModel::getParamFi() const
{
    return _mwcdParams._fi;
}

void MWCDModel::setParamH2( const double &h2 )
{
    _mwcdParams.setH2( h2 );
}

double MWCDModel::getParamH2() const
{
    return _mwcdParams._h2;
}

void MWCDModel::setParamK( const double &K )
{
    _mwcdParams.setK( K );
}

double MWCDModel::getParamK() const
{
    return _mwcdParams._K;
}

void MWCDModel::setParamHp( const double & hp )
{
    _mwcdParams.setHp( hp );
}

double MWCDModel::getParamHp() const
{
    return _mwcdParams._hp;
}

void MWCDModel::setParamR1( const double & r1 )
{
    _mwcdParams.setR1( r1 );
}

double MWCDModel::getParamR1() const
{
    return _mwcdParams._r1;
}

void MWCDModel::setParamS( const double & S )
{
    _mwcdParams.setS( S );
}

double MWCDModel::getParamS() const
{
    return _mwcdParams._S;
}

void MWCDModel::setParamRe( const double & re )
{
    _mwcdParams.setRe( re );
}

double MWCDModel::getParamRe() const
{
    return _mwcdParams._re;
}

void MWCDModel::setParamQ( const double & Q )
{
    _mwcdParams.setQ( Q );
}

double MWCDModel::getParamQ() const
{
    return _mwcdParams._q;
}

void MWCDModel::setModelParams( double K, double hp, double rg, double u,
                                double rw, double r1, double S, double re,
                                double q, double h2, double fi, double Swi, double Sgr )
{
    _mwcdParams.setParams( K, hp, rg, u,
            rw, r1, S, re,
            q, h2, fi, Swi, Sgr );
}

bool MWCDModel::paramsHasZero()
{
    return _mwcdParams.hasParamIsZero();
}

MWCDParams MWCDModel::getMWCDParams() const
{
    return _mwcdParams;
}

void MWCDModel::setMWCDParams( const MWCDParams &params )
{
    _mwcdParams = params;
}

double MWCDModel::getModelResult()
{
    getBreakthroughTime();
}


#include "MWCDParams.h"
#include "tool.h"
#include <string>
#include <QMessageBox>
MWCDParams::MWCDParams() :
    MWCDParams( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 )
{
}

MWCDParams::MWCDParams( const double &K, const double &hp, const double &rg,
                        const double &u, const double &rw, const double &r1,
                        const double &S, const double &re, const double &q,
                        const double &h2, const double &fi, const double &Swi, const double &Sgr ) :
    _K( K ), _hp( hp ), _rg( rg ), _u( u ), _rw( rw ), _r1( r1 ), _S( S ), _re( re ), _q( q ), _h2( h2 ), _fi( fi ), _Swi( Swi ), _Sgr( Sgr ), _zTop( 0 )
{
    initParams();
}

MWCDParams::MWCDParams( const MWCDParams &params ) :
    _K( params._K ), _hp( params._hp ), _rg( params._rg ), _u( params._u ), _rw( params._rw ),
    _r1( params._r1 ), _S( params._S ), _re( params._re ), _q( params._q ), _h2( params._h2 ),
    _fi( params._fi ), _Swi( params._Swi ), _Sgr( params._Sgr ), _zTop( params._zTop )
{
}

MWCDParams::~MWCDParams()
{
    qDebug() << "~MWCDParams";
}

void MWCDParams::initParams()
{
    _BCalculation();
    _D2Calculation();
    _D1Calculation();
    _cCalculation();
    _bCalculation();
    _aCalculation();
    _tCalculation();
    _mCalculation();
}

void MWCDParams::_mCalculation()
{
    double tem1 = 0;

    //
    if( double f = pow( _b, 2.0 ) - 4 * _a * _c;
        f >= 0 )
    {
        tem1 = -_b - pow( f, 0.5 );
    }
    else
    {
        qDebug() << "error: cal_m() pow-";
    }
    double tem2 = 4 * _a * PI * _fi * ( 1 - _Swi - _Sgr );

    if( tem2 == 0 )
    {
        _m = 0;
        qDebug() << "error: cal_m() /0";
        return;
    }
    _m = tem1 / tem2;

}

void MWCDParams::_tCalculation()
{
    double tem1 = 2 * _a * PI * _fi * ( 1 - _Swi - _Sgr ) * pow( _h2, 3.0 );
    double tem2 = 0;

    if( double f = pow( _b, 2.0 ) - 4 * _a * _c;
        f >= 0 )
    {
        tem2 = -_b - pow( f, 0.5 );
    }
    else
    {
        qDebug() << "error: cal_t() pow-";
    }

    if( tem2 == 0 )
    {
        _t = 0;
        qDebug() << "error: cal_t() /0";
        return;
    }
    _t = tem1 / tem2;
}

void MWCDParams::_aCalculation()
{
    if( _hp - _D2 == 0 )
    {
        _a = 0;
        qDebug() << "error: cal_a() /0";
        return;
    }
    _a = _D1 / _hp - _D2;
}

void MWCDParams::_bCalculation()
{
    if( _r1 == 0
        || _rw == 0
        || _hp == 0
        || _h2 == 0 )
    {
        qDebug() << "error: cal_b() /0";
        _b = 0;
        return;
    }

    if( _re / _rw < 0
        || _re / _r1 < 0 )
    {
        qDebug() << "error: cal_b() log-";
        _b = 0;
        return;
    }


    double tem1 = 1 / _r1 - 1 / _rw - _S;
    double tem2 = ( log( _re / _rw ) + _S + 2 * _D1 * _q ) / _hp;
    double tem3 = log( _re / _r1 ) / _h2;
    _b = tem1 - tem2 - tem3;
}

void MWCDParams::_cCalculation()
{
    if( _rw == 0
        || _hp == 0 )
    {
        qDebug() << "error: cal_c() /0";
        _c = 0;
        return;
    }

    if( _re / _rw < 0 )
    {
        qDebug() << "error: cal_c() log-";
        _c = 0;
        return;
    }
    double tem = log( _re / _rw ) + _S;
    tem = tem * _q + _D1 * pow( _q, 2.0 );
    _c  = tem / _hp;
}

void MWCDParams::_D1Calculation()
{
    double tem1 = 2.191 * pow( 10.0, -18.0 ) * _B * _rg * _K;
    double tem2 = _u * _hp * _rw;

    if( tem2 == 0 )
    {
        qDebug() << "error: cal_D1() /0";
        _D1 = 0;
        return;
    }
    _D1 = tem1 / tem2;
}

void MWCDParams::_D2Calculation()
{
    if( _rw == 0
        || _r1 == 0
        || _u == 0 )
    {
        qDebug() << "error: cal_D2() /0";
        _D2 = 0;
        return;
    }
    double tem1 = 7.302 * pow( 10.0, -19.0 ) * _K * _B * _rg *
                  ( 1 / pow( _rw, 3 ) - 1 / pow( _r1, 3 ) );
    _D2 = tem1 / _u;
}

void MWCDParams::_BCalculation()
{
    if( _K == 0 )
    {
        qDebug() << "error: cal_B() /0";
        _B = 0;
        return;
    }
    _B = 7.644 * pow( 10.0, 10.0 ) / pow( _K, 1.5 );
}

bool MWCDParams::hasParamIsZero()
{
    if( _K == 0
        || _hp == 0
        || _rg == 0
        || _u == 0
        || _rw == 0
        || _r1 == 0
        || _S == 0
        || _re == 0
        || _q == 0
        || _h2 == 0
        || _fi == 0
        || _Swi == 0
        || _Sgr == 0 )
    {
        return true;
    }
    return false;
}

void MWCDParams::setParams( double K, double hp, double rg, double u, double rw,
                            double r1, double S, double re, double q, double h2,
                            double fi, double Swi, double Sgr )
{
    _K   = K;
    _hp  = hp;
    _rg  = rg;
    _u   = u;
    _rw  = rw;
    _r1  = r1;
    _S   = S;
    _re  = re;
    _q   = q;
    _h2  = h2;
    _fi  = fi;
    _Swi = Swi;
    _Sgr = Sgr;
    initParams();
}

void MWCDParams::setFi( const double &fi )
{
    _fi = fi;
}

void MWCDParams::setH2( const double &h2 )
{
    _h2 = h2;
}

void MWCDParams::setK( const double &K )
{
    _K = K;
}

void MWCDParams::setHp( const double &hp )
{
    _hp = hp;
}

void MWCDParams::setR1( const double &r1 )
{
    _r1 = r1;
}

void MWCDParams::setS( const double &S )
{
    _S = S;
}

void MWCDParams::setRe( const double &re )
{
    _re = re;
}

void MWCDParams::setQ( const double &q )
{
    _q = q;
}

std::tuple<std::vector<double>, std::vector<double> > MWCDParams::runPredicion( const double & time, const double &zTop )
{
    qDebug() << QString( "time = %1, zTop = %2" ).arg( time ).arg( zTop );
    std::vector<double> x, y;

    if( hasParamIsZero()
        || zTop == 0 )
    {
        return std::make_tuple( x, y );
    }

    double tem1;
    double tem2;
    double tem3;


    int    dataNum = 200;
    float  forStep = zTop / dataNum;
    double r       = 0;
    double preR    = 999999999;

    for( float i = 0; i <= zTop; i += forStep )
    {
        tem1 = log( _h2 / ( _h2 - i ) );
        tem2 = _m * time / ( _h2 * tem1 );
        tem3 = ( pow( _h2, 2 ) - pow( ( _h2 - i ), 2 ) ) / ( 2 * tem1 );

        if( tem2 - tem3 < 0 )
        {
            continue;
        }
        r = pow( tem2 - tem3, 0.5 );

        if( r <= preR )
        {
            preR = r;
            y.push_back( i );
            x.push_back( r );
        }
    }
    y.push_back( MWCDTool::keepTwoDecimal( zTop ) );
    x.push_back( 0 );
    qDebug() << "x size = " << x.size();

    for( int i = x.size() - 1; i >= 0; --i )
    {
        y.push_back( y[ i ] );
        x.push_back( -x[ i ] );
    }
    return std::make_tuple( std::move( x ), std::move( y ) );
}

std::tuple<std::vector<double>, std::vector<double> > MWCDParams::getBTPredicionData()
{
    return runPredicion( _t, _h2 );
}

std::tuple<std::vector<double>, std::vector<double> > MWCDParams::getITPredicionData( const double & year  )
{
    if( year > _t )
    {
        ////////////////
        /// 输入大于突破时间：客户端提示错误
        ///
        ////////////////
        QMessageBox::critical( NULL, QString::fromLocal8Bit( "错误" ),
                QString::fromLocal8Bit( "输入时间不能大于见水时间" ) );
        return runPredicion( year, 0 );

    }

    if( year <= 0 )
    {
        QMessageBox::critical( NULL, QString::fromLocal8Bit( "错误" ),
                QString::fromLocal8Bit( "输入时间必须大于0" ) );
        return runPredicion( year, 0 );
    }
    double a, b, c;
    double zTop1, zTop2;
    a = 1;
    b = -2 * _h2;
    c = 2 * _m * year / _h2;
    qDebug() << QString( "a = %1, b = %2, c = %3" ).arg( a ).arg( b ).arg( c );

    if( pow( b, 2 ) - 4 * a * c >= 0 )
    {
        zTop1 = ( -b + pow( b * b - 4 * a * c, 0.5 ) ) / 2 * a;
        zTop2 = ( -b - pow( b * b - 4 * a * c, 0.5 ) ) / 2 * a;

    }

    _zTop = zTop1 <= _h2
            && zTop1 > 0 ? zTop1 : zTop2;
    qDebug() << QString( "zTop1 = %1, zTop2 = %2, zTop = %3" ).arg( zTop1 ).arg( zTop2 ).arg( _zTop );

    if( _zTop > 0
        && _zTop <= _h2 )
    {
        return runPredicion( year, _zTop );
    }
    else
    {
        qDebug() << "IT predicion error: no solution";
        return runPredicion( year, 0 );
    }
}

void MWCDParams::updatePredicion()
{
    initParams();
}

double MWCDParams::getBreakthroughTime() const
{
    return _t;
}


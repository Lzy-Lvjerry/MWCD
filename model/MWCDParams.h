#pragma once

#include <QDebug>
#include <utility>
#include <cmath>
const double PI = 3.1415926;
class MWCDParams final
{
    friend QDebug operator <<( QDebug os, const MWCDParams & params )
    {
        os << "\nK = " << params._K << ", hp = " << params._hp << ", rg = " << params._rg <<
            "\nu = " << params._u << ", rw = " << params._rw << ", r1 = " << params._r1 <<
            "\nS = " << params._S << ", re = " << params._re << ", q = " << params._q <<
            "\nh2 = " << params._h2 << ", fi = " << params._fi << ", Swi = " << params._Swi <<
            ", Sgr = " << params._Sgr <<
            "\n\\\\\\\\\\\\\\\\\\ \n" <<
            "B = " << params._B << ", D1 = " << params._D1 << ", D2 = " << params._D2 << "\n" <<
            "a = " << params._a << ", b = " << params._b << ", c = " << params._c << "\n" <<
            "t = " << params._t << ", m = " << params._m << "\n";

        return os;
    }

public:
    MWCDParams();
    MWCDParams( const double & K, const double & hp, const double & rg, const double & u,
                const double & rw, const double & r1, const double & S,
                const double & re, const double & q, const double & h2,
                const double & fi, const double & Swi, const double & Sgr );

    MWCDParams( const MWCDParams & params );
    ~MWCDParams();
    MWCDParams & operator=( const MWCDParams & params )
    {
        if( this != &params )
        {
            _K   = params._K;
            _hp  = params._hp;
            _rg  = params._rg;
            _u   = params._u;
            _rw  = params._rw;
            _r1  = params._r1;
            _S   = params._S;
            _re  = params._re;
            _q   = params._q;
            _h2  = params._h2;
            _fi  = params._fi;
            _Swi = params._Swi;
            _Sgr = params._Sgr;
        }
        return *this;
    }

    bool hasParamIsZero();


    void setParams( double K, double hp, double rg,
                    double u, double rw, double r1,
                    double S, double re, double q,
                    double h2, double fi, double Swi, double Sgr );


    void setFi( const double & );


    void setH2( const double & );


    void setK( const double & );


    void setHp( const double & );


    void setR1( const double & );


    void setS( const double & );


    void setRe( const double & );


    void setQ( const double & );


    std::tuple<std::vector<double>, std::vector<double> > getBTPredicionData();// breakthrough time predicion data


    std::tuple<std::vector<double>, std::vector<double> > getITPredicionData( const double & year  ); // input time predicion data


    void updatePredicion();


    double getBreakthroughTime()const;


private:

    void initParams();


    std::tuple<std::vector<double>, std::vector<double> > runPredicion( const double & tiem, const double & zTop );


    void _mCalculation();


    void _tCalculation();


    void _aCalculation();


    void _bCalculation();


    void _cCalculation();


    void _D1Calculation();


    void _D2Calculation();


    void _BCalculation();


public:
    // ��ʽ22
    double _m = 0;//������㣩���չ�ʽ�еĲ���֮һ��m = (-b - (b^2 - 4ac)^1/2) / 4a*Pi*fi*(1-Swi-Sgr)

    // ��ʽ23
    double _t = 0; //������㣩ˮ׶ͻ��ʱ�䣺t = 2a�Ц� * (1-Swi-Sgr) * h2^3 / (-b - (b^2-4ac)^0.5)

    double _a  = 0; //������㣩����ֵ��a = D1/hp - D2     // t
    double _b  = 0; //������㣩����ֵ��b = (1/r1 - 1/rw - S) - [ln(re/rw) + S + 2*D1*q] / hp - ln(re/r1) / h2    // t m
    double _c  = 0; //������㣩����ֵ��c = ((ln(re/rw) + S) * q + D1 * q^2) / hp    // t
    double _D1 = 0; //������㣩�Ǵ���ƽ�澶�����Ĺ��Ի�����ϵ����D1 = 2.191 * 10^-18 * ( B*rg*K / u*hp*rw )   // a b
    double _D2 = 0; // (����㣩�������������Ĺ��Ի�����ϵ����D2 = 7.302 * 10^-19 * ( K*B*rg / u ) * (1/rw^3 - 1/r1^3)   // a

    double _B = 0; // ������㣩�ٶ�ϵ����B = 7.644 * 10^10 / K^1.5  (m^-1)   // D1 D2

    double _K; // (����ֵ����͸��(10^-3 * u * m^2)  // B D1 D2
    double _hp; // ������ֵ�������򿪺��(m)   // D1 a
    double _rg; // ������ֵ����������ܶ�(f)   // D1 D2
    double _u; // ������ֵ��������(mPa.s)   // D1 D2
    double _rw; // ������ֵ�����뾶(m)   //  D1 D2 b
    double _r1; //������ֵ���������������뾶(m)    // D2 b
    double _S; //������ֵ����Ƥϵ��(f)    // b
    double _re; //������ֵ�������뾶(m)    // b
    double _q; //������ֵ��������׶εײ�����(m^3 / d)    // b
    double _h2; //������ֵ��������׶εײ��߶�(m)    // b  t
    double _fi; //������ֵ����϶��(f)    // t
    double _Swi; //������ֵ������ˮ���Ͷ�(f)    // t
    double _Sgr; //������ֵ�����������Ͷ�(f)    // t

public:
    double _zTop; // �����û�����ʱ����������������߶���zֵ
};


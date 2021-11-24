#include "tool.h"

std::string MWCDTool::doubleToString( const double & num )
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

std::string MWCDTool::intToString( const int & num )
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

int MWCDTool::doubleToInt( const double &num )
{
    return num >= ( static_cast<int>( num ) + 0.5 ) ? static_cast<int>( num ) + 1 : static_cast<int>( num );
}

double MWCDTool::keepTwoDecimal( const double &num )
{
    return ( static_cast<double>( static_cast<int>( ( num + 0.005 ) * 100 ) ) ) / 100;
}


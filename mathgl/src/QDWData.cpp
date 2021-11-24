#include "QDWData.h"
#include<QDebug>
QDWData::QDWData():
    _rotate(false),
    _zoom(false)
{

}

QDWData::QDWData(const bool &rotate, const bool &zoom):
    _rotate(rotate),
    _zoom(zoom)
{

}

QDWData::~QDWData()
{
    qDebug()<<"~QDWData";
}

QDWData::QDWData(const QDWData &copy)
{
    *this = copy;
}

QDWData &QDWData::operator=(const QDWData &rhs)
{
    if(this == &rhs){
        return *this;
    }
    this->_rotate = rhs._rotate;
    this->_zoom = rhs._zoom;
    return *this;
}

void QDWData::setRotate(const bool& rotate)
{
    _rotate = rotate;
}

void QDWData::setZoom(const bool& zoom)
{
    _zoom = zoom;
}


bool QDWData::rotate() const
{
    return _rotate;
}

bool QDWData::zoom() const
{
    return _zoom;
}




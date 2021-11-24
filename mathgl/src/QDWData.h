/********************************************

  class: QDWData (QDWData.cpp)

  author: Lvjerry
  date: August 7, 2021

  QDrawWindow的数据接口

********************************************/

#pragma once

#include<string>
#include<vector>
class QDWData final
{
public:
    QDWData();
    QDWData(const bool& rotate, const bool& zoom);
    ~QDWData();
    QDWData(const QDWData&);

    QDWData& operator=(const QDWData&rhs);

public:
    void setRotate(const bool& );
    void setZoom(const bool& );

    bool rotate()const;
    bool zoom()const;


private:
    bool _rotate;
    bool _zoom;
};


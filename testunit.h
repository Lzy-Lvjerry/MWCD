#pragma once

#include"MWCDModel.h"
#include<QDebug>


class testClass{

public:
    testClass():
    a(0),b(0),c(new int(0))
    {}
    testClass(int _a,int _b, int _c):
    a(_a),b(_b), c(new int(_c))
    {}
    testClass(const testClass&copy):
    a(copy.a),b(copy.b),c(new int(*copy.c))
    {}
    ~testClass(){
        delete c;
    }
    testClass& operator = (const testClass& rhs){
        a = rhs.a;
        b = rhs.b;
        c = new int(*rhs.c);
        return *this;
    }

    void print(){
        qDebug()<<a<<b<<*c;
    }

private:
    int a;
    int b;
    int *c;
};

void test(){

    testClass t1(9,10,11);
    testClass t2(t1);
    testClass t3;
    t3 = t2;
    t1.print();
    t2.print();
    t3.print();
//    myModel *model = new myModel();
//    model->printAll();
//    delete model;



}

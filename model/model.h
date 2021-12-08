#ifndef MODEL_H
#define MODEL_H

template <class T>
class model
{
public:
    model()  = default;
    ~model() = default;

    virtual T getModelResult() = 0;


};

#endif // MODEL_H


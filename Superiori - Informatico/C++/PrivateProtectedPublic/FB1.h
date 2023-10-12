#ifndef PRIVATEPROTECTEDPUBLIC_FB1_H
#define PRIVATEPROTECTEDPUBLIC_FB1_H
#include "Base.h"

class FB1 : private Base{
private:
    int fbi1;
protected:
    int fbi2;
public:
    int fbi3;
    FB1();
};


#endif //PRIVATEPROTECTEDPUBLIC_FB1_H

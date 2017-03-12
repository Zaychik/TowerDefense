#ifndef LANDSCAPE_H
#define LANDSCAPE_H
#include <string>
#include "envirenment.h"

using std::string;

class Landscape
{

public:   
    Landscape(char *filename); //конструктор которая создает поле по тем параметрам который переда в файле
    ~Landscape() {}
    int get_width() const{return this->width;}
    int get_hight() const{return this->hight;}
    void set_width(int );
    void set_hight(int );
private:
     //Envirenment **Land;
     vector< vector<Envirenment> > Land;
     int width, hight;
};

#endif // LANDSCAPE_H

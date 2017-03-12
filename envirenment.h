#ifndef ENVIRENMENT_H
#define ENVIRENMENT_H
#include <cstdlib>
#include <cstring>
#include <list>
#include <vector>
#include "shape.h"
#include "error_msg.h"
using std::list;
using std::vector;

struct valid_values_envir
{
    int t_o ; /*тип объекта*/
    int p_w; /*свойство объекта*/
    char t_p; /* тип чего проверяем type или properties*/
    friend bool  operator==(const valid_values_envir & lh, const valid_values_envir & rh){
        return lh.t_o==rh.t_o && lh.p_w == rh.p_w && lh.t_p == rh.t_p;
    }
};

class Envirenment
{
public:
    enum Type_Object{Road, Tree, Water, Mount};
    enum Proper_way{asphalt, dirt, nature};
    Envirenment(int, int); /*конструктор для задания тип и свойства*/
//    Envirenment(int);  /*конструктор для задания тип*/
    //Envirenment();
    Type_Object get_type() const{return this->type;}
    Proper_way get_properties() const{return this->properties;}
    void set_type(int );
    void set_properties(int );
    Type_Object set_type_return(int );
    Proper_way set_properties_return(int );
    static void valid(); //процедра заполенения вектора для провекри правльности создаваемой ячеки
    static vector <valid_values_envir> v_v_e; // векторо для проверки правльности создаваемости ячейки
private:
    Type_Object type;
    Proper_way properties;
    list <Shape *> Shapelist;


};



#endif // ENVIRENMENT_H

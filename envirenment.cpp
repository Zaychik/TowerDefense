#include <algorithm>    // std::binary_search, std::sort
#include "envirenment.h"
#include "error_msg.h"

vector<valid_values_envir> Envirenment::v_v_e;

void Envirenment::valid(){
        valid_values_envir v;
        v.t_p = 't'; v.p_w = 0;
        for (int i = 0; i < 4; i++) { v.t_o = i; v_v_e.push_back(v);}
        /*асфальт или грязь только с дорогой*/
        v.t_p = 'p'; v.t_o = 0; v.p_w = 0;
        v_v_e.push_back(v);
        v.t_p = 'p'; v.t_o = 0; v.p_w = 1;
        v_v_e.push_back(v);
        /***********************************/
        v.t_p = 'p'; v.t_o = 1; v.p_w = 2;
        v_v_e.push_back(v);
        v.t_p = 'p'; v.t_o = 2; v.p_w = 2;
        v_v_e.push_back(v);
        v.t_p = 'p'; v.t_o = 3; v.p_w = 2;
        v_v_e.push_back(v);
    }
void Envirenment::set_properties(int _properties)
{
    valid_values_envir v;
    v.t_p = 'p'; v.p_w = _properties;
    v.t_o = this->get_type();
    if (std::find(v_v_e.begin(), v_v_e.end(), v) != v_v_e.end())
        this->properties = static_cast <Proper_way>(_properties);
    else throw error_msg(3, "Error parameter set_properties");
}

void Envirenment::set_type(int _type)
{
    valid_values_envir v;
    v.t_p = 't'; v.p_w = 0;
    v.t_o = _type;
    if (std::find(v_v_e.begin(), v_v_e.end(), v) != v_v_e.end())
        this->type = static_cast <Type_Object>(_type);
    else throw error_msg(3, "Error parameter set_type");
}
 Envirenment::Proper_way Envirenment::set_properties_return(int _properties)
{
     valid_values_envir v;
     v.t_p = 'p'; v.p_w = _properties;
     v.t_o = this->get_type();
     if (std::find(v_v_e.begin(), v_v_e.end(), v) != v_v_e.end())
         return static_cast <Proper_way>(_properties);
     else throw error_msg(3, "Error parameter set_properties");
}

Envirenment::Type_Object Envirenment::set_type_return(int _type)
{
    valid_values_envir v;
    v.t_p = 't'; v.p_w = 0;
    v.t_o = _type;
    if (std::find(v_v_e.begin(), v_v_e.end(), v) != v_v_e.end())
        return static_cast <Type_Object>(_type);
    else throw error_msg(3, "Error parameter set_type");
}


Envirenment::Envirenment(int _type, int _properties)
    : type(set_type_return(_type)), properties(set_properties_return(_properties)){}


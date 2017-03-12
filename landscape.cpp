#include <fstream>
#include <cstring>
#include <iostream>
#include <memory>
#include "landscape.h"
#include "error_msg.h"


using std::string;
using std::ifstream;
using std::endl;
using std::cout;
using std::ws;

void Landscape::set_hight(int _hight)
{
    if (_hight > 0) this->hight = _hight;
    else throw error_msg(3, "Error parameter set_hight");
}

void Landscape::set_width(int _width)
{
    if (_width > 0) this->width = _width;
    else throw error_msg(3, "Error parameter set_width");
}

Landscape::Landscape(char *filename)
{
    /**/

        Envirenment::valid();
        string line = "";
        string width = "", hight = "";
        ifstream file(filename);
        if (!file.is_open())
            throw error_msg(1, "File not open Landscape (filename)");
        try
        {
          getline(ws(file), width, '*');
          getline(ws(file), hight, '*');
          if ((width == "") || (hight == "")){
            file.close();
            throw error_msg(2, "File wrong format Landscape (filename)_1");
          }
          /*создадим поле размером кототрое задан в файле*/

          this->set_width(atoi(width.c_str()));
          this->set_hight(atoi(hight.c_str()));

          int width, hight;
          width = this->get_width();
          hight = this->get_hight();
          string temp_type = "";
          string temp_prop = "";

          for(size_t i = 0; i < hight; ++i)
           {
               std::vector<Envirenment> temp;
               for(size_t j = 0; j < width; ++j)
               {
                   if (file.eof())
                    throw error_msg(2, "File wrong format Landscape (filename)_2");
                   getline(ws(file), line, ';');
                   temp_type = line.substr(0, line.find(","));
                   temp_prop = line.substr(line.find(",") + 1);
                   temp.push_back(Envirenment(atoi(temp_type.c_str()), atoi(temp_prop.c_str())));
               }
               Land.push_back(temp);
           }

          /*массив есть (поле, теперь его надо заполнить*/
          while (!file.eof() )
          {
            getline(ws(file), line, ';');
            cout << line<< endl;
          }
        file.close();
        }
        catch(error_msg e)
        {
           file.close();
           throw;
        }
}

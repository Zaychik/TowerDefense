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
    if (file.is_open())
    {
      getline(ws(file), width, '*');
      getline(ws(file), hight, '*');
      if ((width == "") || (hight == "")){
        file.close();
        throw error_msg(2, "File wrong format Landscape (filename)");
      }
      /*создадим поле размером кототрое задан в файле*/
      try
      {
        this->set_width(atoi(width.c_str()));
        this->set_hight(atoi(hight.c_str()));
      }
      catch(error_msg e)
      {
         file.close();
         throw;
      }
      int width, hight;
      width = this->get_width();
      hight = this->get_hight();
      Land = new Envirenment *[width];
     /* for (int i = 0; i < width; ++i)
          Land[i] = new Envirenment[hight];*/
      /*массив есть (поле, теперь его надо заполнить*/
      while (!file.eof() )
      {
        getline(ws(file), line, ';');
        cout << line<< endl;
      }
      file.close();
    } else
    {        
        throw error_msg(1, "File not open Landscape (filename)");
    }
}

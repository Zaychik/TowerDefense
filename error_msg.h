#ifndef ERROR_MSG_H
#define ERROR_MSG_H


class error_msg
{
public:
    error_msg(int num,const char* m)
        : mess(m), number(num){}
    const char* Get_Mess() {return this->mess;}
    int Get_Number() {return this->number;}
private:
    int number;
    const char* mess;
};

#endif // ERROR_MSG_H


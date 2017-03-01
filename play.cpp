#include <iostream>
#include <fstream>
#include <cstring>
#include "landscape.h"
#include "error_msg.h"

using namespace std;

int main(int argc, char *argv[])
{

    try
    {
        Landscape L("land.txt");
    }
    catch(error_msg e)
    {
        cout << "Exception in main()\n"
                     << e.Get_Mess() << endl
                     << "Code = " << e.Get_Number() << endl;
    }


    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include "mainCLP.h"


int main(int argc,char *argv[])
{
    PARSE_ARGS;

    std::ofstream myfile;
    myfile.open (FileName);
    myfile << Message;
    myfile.close();
    return 0;
}

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(int arglen,char** args)
{
    std::string param;
    for(int i=0;i<arglen;i++)
    {
        param+=args[i];
    }
    stringstream ss;
    ss<<"name:";
    ss<<0;
    ss<<0;
    std::string a;
    ss>>a;
    std::string b = ss.str();
    std::cout<<10<<endl<<"look"<<endl;
}
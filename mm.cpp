#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
void test_stringstream()
{
    std::cout<<"test-stringstream"<<endl;
    stringstream ss;
    ss.clear();
    ss.str("");
    ss<<"name:"<<(char)0;
    std::cout<<1<<ss.str()<<endl;
    
    ss.clear();//只是清空状态
    ss.str("");//清空数据
    ss<<"name:"<<(unsigned short)0;
    std::cout<<2<<ss.str()<<endl;

    ss.clear();
    ss.str("");
    ss<<"name:"<<(unsigned int)0;
    std::cout<<3<<ss.str()<<endl;

    ss.clear();
    ss.str("");
    ss<<"name:"<<(float)0;
    std::cout<<4<<ss.str()<<endl;

    ss.clear();
    ss.str("");
    ss<<"name:"<<(double)0;
    std::cout<<5<<ss.str()<<endl;
}
int main(int arglen,char** args)
{
    std::string param;
    for(int i=0;i<arglen;i++)
    {
        param+=args[i];
    }
    std::cout<<"args"<<param<<endl;
    test_stringstream();
    printf("look me %d",100);

}
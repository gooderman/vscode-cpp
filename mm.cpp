#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <regex>
using namespace std;
void test_stringstream()
{
    std::cout << "test-stringstream" << endl;
    stringstream ss;
    ss.clear();
    ss.str("");
    ss << "name:" << (char)0;
    std::cout << 1 << ss.str() << endl;

    ss.clear(); //只是清空状态
    ss.str(""); //清空数据
    ss << "name:" << (unsigned short)0;
    std::cout << 2 << ss.str() << endl;

    ss.clear();
    ss.str("");
    ss << "name:" << (unsigned int)0;
    std::cout << 3 << ss.str() << endl;

    ss.clear();
    ss.str("");
    ss << "name:" << (float)0;
    std::cout << 4 << ss.str() << endl;

    ss.clear();
    ss.str("");
    ss << "name:" << (double)0;
    std::cout << 5 << ss.str() << endl;
}
void test_fstream()
{
    fstream ss;
}
void test_regex();
int main(int arglen, char **args)
{
    std::string param;
    for (int i = 0; i < arglen; i++)
    {
        param += args[i];
    }
    std::cout << "args" << param << endl;
    test_stringstream();
    printf("look me 我 xx %d\r\n", 100);
    test_fstream();
    test_regex();
}

void test_regex()
{
    regex re("房间号[:：\\s]{0,}(\\d+)");
    std::string ss[] = {
        "xx麻将房间号12345快来",
        "xx麻将房间号:12345,快来",
        "xx麻将房间号： 12345快来",
        "xx麻将房间号  :12345,快来",
        "xx麻将房间号：12345：快来",
        "xx麻将房间号 ：12345.快来",
        "xx麻将房间号  12345。快来",
    };
    int i = 1;
    for (auto s : ss)
    {
        smatch sm;
        auto f = regex_search(s, sm, re);
        cout << i++ << "  " << s.c_str() << endl;
        cout << "    " << f << "|" << sm.size() << "|" << sm.length();
        if (f && sm.size() > 0)
        {
            cout << "|[[  "<< sm.format("$1")<<"  ]]" << endl;
        }
        else
        {
            cout << endl;
        }
    }

    regex rpe("(\\d+)[^\\d]*(\\d+)");
    cout<<regex_replace("12345--67890",rpe,"[$2][$&][$$][$1][$`][$´]")<<endl;
    //look
}
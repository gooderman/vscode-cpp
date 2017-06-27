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

    auto sa = "123546";
    stringstream stm;
    stm<<sa;
    int dd;
    stm>>dd;
    printf("dd=%d\n",dd);
    cout << dd << "===="<<endl;
}
void test_fstream()
{
    fstream ss;
}
void test_regex();

void test_regex()
{
    regex re("房间号[:：\\s]{0,}(\\d+)");
    std::string ss[] = {
        "xx麻将ffds房间号12345快来",
        "xx麻将44f房间号:12345,快来",
        "xx麻将fa房间号： 12345快来",
        "xx麻将4人发v恶房间号  :12345,快来",
        "xx麻饿将地方房间号：12345：快来",
        "xx麻e将房间号 ：12345.快来",
        "xx3麻将房间号  12345。快来",
    };
    int i = 1;
    for (auto s : ss)
    {
        
        auto ff = s.find("xx麻将");
        if(ff==string::npos)
        {
            cout << i++ << " no match" << s.c_str() << endl;
            continue;
        }
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

void testTime()
{
    auto t1= std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::seconds(10));
    cout<<"testTime 10s="<<t1.count()<<" milliseconds"<<endl;

    auto t = std::chrono::steady_clock::now().time_since_epoch();
    auto dafaulttime = [=]()->long long{
        return t.count();//==std::chrono::nanoseconds
    };
    auto nanotimes = [=]()->long long{
        return std::chrono::duration_cast<std::chrono::nanoseconds>(t).count();
    };
    auto microtimes = [=]()->long long{
        return std::chrono::duration_cast<std::chrono::microseconds>(t).count();
    };
    auto millitime = [=]()->long long{
        return std::chrono::duration_cast<std::chrono::milliseconds>(t).count();
    };
    auto secondtime = [=]()->long long{
        return std::chrono::duration_cast<std::chrono::seconds>(t).count();
    };
    cout<<"dafaulttime      ="<<dafaulttime()<<" defaulttime"<<endl;
    cout<<"nanotimes        ="<<nanotimes()<<" nanoseconds"<<endl;
    cout<<"microtimes       ="<<microtimes()<<" microtimes"<<endl;
    cout<<"millitime        ="<<millitime()<<" milliseconds"<<endl;
    cout<<"secondtime       ="<<secondtime()<<" seconds"<<endl;
}

void testVector()
{
    auto str = std::string("abcdefg");
    std::vector<char> charvect(str.begin(), str.end()); 
    cout<<"convert str to vector=="<<charvect.data()<<endl;

    charvect.push_back('H');
    auto str1 = std::string(charvect.begin(),charvect.end());
    cout<<"convert vector to str=="<<str1<<endl;

}
void testString()
{
    std::string ss = "123456789";
    cout<<ss<<endl;
    ss.erase(5,1);
    cout<<ss<<endl;
    ss.insert(5,1,'A');
    cout<<ss<<endl;
    auto d = ss.data();
    unsigned char * p = (unsigned char*)d;
    p[0]='C';
    p[8]='K';
    cout<<ss<<endl;


}
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
    testTime();
    testVector();
    testString();
}
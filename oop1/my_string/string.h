 #ifndef __MYSTRING__
 #define __MYSTRING__
/*
     需求：定义 String 的对象   
     1.构造函数
     2.拷贝构造
     3.拷贝复制
     4.析构函数
     5.<< 运算符重载 
     注意：
        a. 数据为私有 
*/
class String
{
private:
    char* m_data;
public:
    String(const char* cstr=0);  // 构造函数
    String(const String& str);  // 拷贝构造
    String& operator = (const String& str);  // 拷贝复制
    ~String();  // 析构函数
    // c_str 指针指向字符的字符串，C风格的字符串
    // 在函数没有改变 m_data
    char* get_c_ctr() const { return m_data; }  // 返回 string 对象的指针 
};

# include <cstring>

inline
String::String(const char* cstr)  // 构造函数
// String::String(const char* cstr = 0)  // 这里不能这么写，默认值不需要在这里写出来
{
    if (cstr){
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else{
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline
String::~String()  // 析构函数
{
    delete[] m_data;
}

inline
String& String::operator=(const String& str)  // 拷贝复制  
{
    if (this == &str)  //&str 表示取地址
        return *this;
    
    delete[] m_data;  // 先删除左边；
    m_data = new char[ strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

inline
String::String(const String& str)
{
    m_data = new char[ strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

#include <iostream>
using namespace std;
inline
ostream& operator<<(ostream& os, const String& str)
{
    os << str.get_c_ctr();
    return os;
} 

 #endif
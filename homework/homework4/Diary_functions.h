#ifndef D_H
#define D_H

#include <string>
#include <vector>
#include <map>
using namespace std;

struct Diary
{
    string date;
    string content;
};//定义每一篇日记的组成格式


class DiaryManager{
private:
    string FilePath;//文件路径 
public:
    DiaryManager(const string & filepath);//构造函数的参量是文件储存路径
    void add(const Diary & D);//将新的一篇日记添加到日记文档中去,对应pdadd
    void list()const;//pdlist的缺省形式
    void list(const string & date1,const string & date2)const;//显示对应日记，pdlist
    void show(const string & date);//显示对应日期的日记
    int remove(const string & date);//删除对应日期的日记  
};//定义这个类，作用是管理所有日记

bool has_only_digits(const string& str) ;//判断一个字符串是否都由数字构成
bool is_date(string input);//判断一个字符串是否是具体日期
bool required_date(string input, string date1, string date2);//判断一个日期是否在某特定范围内
bool same_date(string input ,string date );//判断日期是否相同
#endif
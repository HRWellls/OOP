#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include "Diary_functions.h"
using namespace std;


DiaryManager::DiaryManager(const string & filepath):FilePath(filepath){
}

void DiaryManager::add(const Diary & D){
    //把所有日记全部读入向量中，遍历向量：
    //如果有重复日期，则用新日记代替重复日期的原日记
    //若没重复，则将新日记push到这个向量里。

    ifstream fin(this->FilePath);
    vector<Diary> diaries;//目前所有的日记

    //把已有日记文档读入内存
    bool first=true;
    Diary temp;//用于临时diary储存
    string input;//用于储存getline函数的读入值
    while(getline(fin,input)){
        if(is_date(input)){
            if(first)first=false;
            else diaries.push_back(temp);//把上一份日记加入向量
            temp.content="";//日记内容清零

            temp.date=input;//新日记的日期
        }
        else{
            temp.content+=input;//日记内容更新
        }
    }
    diaries.push_back(temp);//把最后一份日记加入向量

    //更新日记内容
    vector<Diary>::iterator iter;
    for(iter=diaries.begin();iter!=diaries.end();iter++){
        if((*iter).date==D.date){
            //有重复日期的情况
            *iter=D;
            break;
        }
    }
    if(iter==diaries.end()){
        //没有重复日期的情况
        diaries.push_back(D);
    }

    //把更新后的日记重新写回文档
    ofstream fout("diary.txt");
    for(iter=diaries.begin();iter!=diaries.end();iter++){
        fout<<(*iter).date<<endl<<(*iter).content<<endl;
    }    
}





void DiaryManager::list()const{
    ifstream fin(this->FilePath);
    string input;//用于储存getline函数的读入值
    while(getline(fin,input)){
        cout<<input<<endl;//把日记内容一行一行全部输出
    }
}

void DiaryManager::list(const string & date1,const string & date2)const{
    ifstream fin(this->FilePath);
    string input;//用于储存getline函数的读入值
    bool flag=false;//标记是否开始输出日记内容
    while(getline(fin,input)){
        if(is_date(input)){//如果是一个日期
            if(required_date(input,date1,date2)){//检查是否满足日期限制条件
                flag=true;
            }
            else flag=false;
        }
        //如果满足限制条件则输出日记内容
        if(flag)cout<<input<<endl;
    }    
}





void DiaryManager::show(const string & date){
    ifstream fin(this->FilePath);
    string input;//用于储存getline函数的读入值
    bool flag=false;
    bool success=false;
    while(!success && getline(fin,input)){
        if(is_date(input)){//如果是一个日期
            if(same_date(input,date)){//检查是否满足日期限制条件
                flag=true;
            }
            else{//日期不满足要求的日记
                if(flag)success=false;//如果已经输出了对应日记，则不再继续读入新的日记
                flag=false;
            }
        }
        //如果满足限制条件则输出日记内容
        if(flag)cout<<input<<endl;
    }        
}





int DiaryManager::remove(const string & date){
    ifstream fin(this->FilePath);
    vector<Diary> diaries;//目前所有的日记

    //把已有日记文档读入内存
    bool first=true;
    Diary temp;//用于临时diary储存
    string input;//用于储存getline函数的读入值
    while(getline(fin,input)){
        if(is_date(input)){
            if(first)first=false;
            else diaries.push_back(temp);//把上一份日记加入向量
            temp.content="";//日记内容清零

            temp.date=input;//新日记的日期
        }
        else{
            temp.content+=input;//日记内容更新
        }
    }
    diaries.push_back(temp);//把最后一份日记加入向量

    //更新日记内容
    vector<Diary>::iterator iter;
    for(iter=diaries.begin();iter!=diaries.end();iter++){
        if(same_date((*iter).date,date)){
            //有重复日期的情况
            iter=diaries.erase(iter);
            break;
        }
    }   

    ofstream fout("diary.txt");
    for(iter=diaries.begin();iter!=diaries.end();iter++){
        fout<<(*iter).date<<endl<<(*iter).content<<endl;
    }    
}





bool has_only_digits(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool is_date(string input) {
    istringstream ss(input);
    string year, month, day;
    int y,m,d;

    if (ss >> year>> month >> day) {
        if(has_only_digits(year)){
            if(has_only_digits(month)){
                if(has_only_digits(day)){
                    y=stoi(year);
                    m=stoi(month);
                    d=stoi(day);
                    if (y>= 1000 && y<= 9999 &&
                        m >= 1 && m <= 12 &&
                        d>= 1 && d<= 31) {return true;}
                }
            }
        }
    }
    return false;
}

bool required_date(string input, string date1, string date2){
    istringstream i(input),db(date1),de(date2);
    string year1, month1, day1,     year2, month2, day2,    year3, month3, day3;
    int y1,m1,d1,y2,m2,d2,y3,m3,d3;

    i>>year1>>month1>>day1;
    db>>year2>>month2>>day2;
    de>>year3>>month3>>day3;

    y1=stoi(year1);
    m1=stoi(month1);
    d1=stoi(day1);
    y2=stoi(year2);
    m2=stoi(month2);
    d2=stoi(day2);
    y3=stoi(year3);
    m3=stoi(month3);
    d3=stoi(day3);
    
    if(y1>=y2&&y1<=y3){
        if(m1>=m2&&m1<=m3){
            if(d1>=d2&&d1<=d3)return true;
        }
    }
    return false;
}

bool same_date(string input ,string date ){
    istringstream i(input),d(date);
    string year1, month1, day1, year2, month2, day2;
    int y1,m1,d1,y2,m2,d2;

    i>>year1>>month1>>day1;
    d>>year2>>month2>>day2;

    y1=stoi(year1);
    m1=stoi(month1);
    d1=stoi(day1);
    y2=stoi(year2);
    m2=stoi(month2);
    d2=stoi(day2);

    if(y1==y2){
        if(m1==m2){
            if(d1==d2)return true;
        }
    }
    return false;
}    

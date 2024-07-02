#include "Diary_functions.h"
#include <iostream>

int main(){
    DiaryManager DM("diary.txt");//建立一个diary对象d
    string input;//写入每一个字符
    string content;//写入每一篇日记

    string date;//写下本篇日记的时间

    cout<<"Enter TimeStamp:"<<endl;
    getline(cin,date);//输入日记时间

    cout<<"Enter diary content:"<<endl;
    while(getline(cin,input) && input != "."){//利用getline函数将cin输入的字符读入到input变量中
        content+=input;
    }//现在所有日记内容都储存在了content中

    Diary D;
    D.date=date;
    D.content=content;

    DM.add(D);
}
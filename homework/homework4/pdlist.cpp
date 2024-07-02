#include <iostream>
#include <stdlib.h>
#include "Diary_functions.h"

int main(int argc,char * argv[]){
    DiaryManager DM("diary.txt");


    if(argc == 1){//没有参数传入的情况
        DM.list();
    }else{
        string date1,date2;
        date1=argv[1];
        date1+=" ";
        date1+=argv[2];
        date1+=" ";
        date1+=argv[3];

        date2=argv[4];
        date2+=" ";
        date2+=+argv[5];
        date2+=" ";
        date2+=argv[6];
        //起始日期与截止日期。

        DM.list(date1,date2);
    }
}
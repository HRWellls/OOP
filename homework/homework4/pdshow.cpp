#include <iostream>
#include "Diary_functions.h"

int main(){
    cout<<"Please enter the date of diary you want to query"<<endl;
    string date;
    getline(cin,date);
    DiaryManager DM("diary.txt");
    cout<<"Your diary:"<<endl;
    DM.show(date); 
}
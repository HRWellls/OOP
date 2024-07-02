#include <iostream>
#include "Diary_functions.h"

int main(){
    cout<<"Please enter the date of diary you want to remove"<<endl;
    string date;
    getline(cin,date);
    DiaryManager DM("diary.txt");
    
    int result;
    result=DM.remove(date); 
    return result;
}
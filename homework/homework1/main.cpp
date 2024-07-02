#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

typedef struct a{
    string name;
    int s[3];
}Student;
//This is the typedef of struct Student
//This struct is used to record data from "in.txt"

int main(){

    ////////////////////////////input//////////////////////////
    ifstream fin("in.txt",ios::in);//read in the data from "in.txt"
    Student students[10];
    for(int i=0;i<10;i++){
        fin>>students[i].name>>students[i].s[0]>>students[i].s[1]>>students[i].s[2];
    } //using file-read 
    
    /////////////////////////processing//////////////////////////
    float aver[3];
    int min[3];
    int max[3];
    //record the 3 index of the 3 scores

    for(int i=0;i<3;i++){
        int sum=0;
        min[i]=999;
        max[i]=0;
        for(int j=0;j<10;j++){
            sum+=students[j].s[i];
            //add up all 10 scores of evey student
            if(students[j].s[i] < min[i]){
                min[i]=students[j].s[i];
            }
            //Find the minimum
            if(students[j].s[i] > max[i]){
                max[i]=students[j].s[i];
            }
            //Find the maximum
        }
        aver[i]=(float)sum/10.0;//calculate the average score of score[i]
    }




    //////////////////////////////output//////////////////////////////
    ofstream fout("out.txt");//outout the result to the "out.txt"
    fout<<setw(12)<<left<<"no"<<setw(12)<<left<<"name"<<setw(12)<<left<<"score1"
    <<setw(12)<<left<<"score2"<<setw(12)<<left<<"score3"<<setw(12)<<left<<"average"<<endl;
    //output the 1st line

    for (int i=0;i<10;i++){
        fout<<setw(12)<<left<<i
            <<setw(12)<<left<<students[i].name
            <<setw(12)<<left<<students[i].s[0]
            <<setw(12)<<left<<students[i].s[1]
            <<setw(12)<<left<<students[i].s[2]
            <<setw(12)<<left<<(float)(students[i].s[0]+students[i].s[1]+students[i].s[2])/3.0
            <<endl;
    }
    //output the specific data of 10 students

    fout<<setw(12)<<left<<""
    <<setw(12)<<left<<"average"
    <<setw(12)<<left<<aver[0]
    <<setw(12)<<left<<aver[1]
    <<setw(12)<<left<<aver[2]
    <<endl;//output average
    fout<<setw(12)<<left<<""
    <<setw(12)<<left<<"min"
    <<setw(12)<<left<<min[0]
    <<setw(12)<<left<<min[1]
    <<setw(12)<<left<<min[2]
    <<endl;//output min
    fout<<setw(12)<<left<<""
    <<setw(12)<<left<<"max"
    <<setw(12)<<left<<max[0]
    <<setw(12)<<left<<max[1]
    <<setw(12)<<left<<max[2];
    //output max
}
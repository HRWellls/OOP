#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
    string first_name,last_name,name;//读入学生姓名
    string course_name;//读入课程名字
    string match;//用于记录每一对数据（学生名字，课程名字）
    int score;//读入某门课成绩
    int number_of_students=0;//学生总人数
    int number_of_classes=0;
    map <string,int> s_total_score;//每个学生获得的总分数
    map <string,int> s_number_of_classes;//每个学生修读的总科目数目
    map <string,int> c_total_score;//每门课所有学生的分数总和
    map <string,int> c_number_of_classes;//每个课学生的修读人数
    vector <string> name_list;//所有同学名单列表
    vector <string> class_list;//课程名单向量
    map <string,int> student_class;//若某同学修读了某课程，则map<key>=1,不然map<key>=0.其中，key是student_name+course_name
    map <string,int> max;//课程最高分
    map <string,int> min;//课程最低分

    ifstream fin("data.txt",ios::in);


    while (fin>>first_name){//循环一直进行直到没有新的数据输入，用Ctrl+Z结束此循环
        fin>>last_name>>course_name>>score;//读取这一record
        name=first_name+last_name;
        match=name+" "+course_name;


        if(!count(name_list.begin(),name_list.end(),name))//把没在名单里的学生姓名加入名单
            name_list.push_back(name);

        if(!count(class_list.begin(),class_list.end(),course_name))//把不在课程名单里的课程加入名单
            class_list.push_back(course_name);
   

        s_total_score[name]+=score;//学生总分数更新
        s_number_of_classes[name]++;//学生修读总课程数更新
        c_total_score[course_name]+=score;//课程学生分数总和更新
        c_number_of_classes[course_name]++;//课程学生数目更新  
        student_class[match]=score;//表示该学生修读了这门课

        if(max[course_name]<score)
            max[course_name]=score;//更新课程最好成绩

        if(min[course_name]==0||min[course_name]>score)
            min[course_name]=score;//更新课程最差成绩

    }


    ofstream fout("out.txt");
    fout<<setw(8)<<left<<"no"<<setw(20)<<left<<"student name";//输出文件的开头行

    for(int i=0;i<class_list.size();i++)//在第一行给出不同课程的名字
        fout<<setw(12)<<left<<class_list[i];
    fout<<setw(12)<<left<<"average"<<endl;//每个学生平均成绩


    for(int i=0;i<name_list.size();i++){
        string temp1=name_list[i];//学生名字
        fout<<setw(8)<<left<<i<<setw(20)<<left<<name_list[i];//输出序号以及学生名字
        for(int j=0;j<class_list.size();j++){
            string temp2=class_list[j];//课程名字

            if(student_class[temp1+" "+temp2]==0){//该学生未修读这门课程
                fout<<setw(12)<<left<<"/";
            }
            else{//该学生修读了这门课程
                fout<<setw(12)<<left<<student_class[temp1+" "+temp2];//输出学生成绩
            }
        }
        fout<<setw(12)<<left<<((double)s_total_score[temp1])/((double)s_number_of_classes[temp1])<<endl;
    }

    fout<<"average                     ";
    for(int i=0;i<class_list.size();i++){
        string temp=class_list[i];//课程名字
        fout<<setw(12)<<left<<((double)c_total_score[temp])/((double)c_number_of_classes[temp]);//每门课程平均分
    }    
    fout<<endl;

    
    fout<<"max                         ";
    for(int i=0;i<class_list.size();i++){
        string temp=class_list[i];//课程名字
        fout<<setw(12)<<left<<max[temp];//每门课程平均分
    }    
    fout<<endl;

    fout<<"min                         ";
    for(int i=0;i<class_list.size();i++){
        string temp=class_list[i];//课程名字
        fout<<setw(12)<<left<<min[temp];//每门课程平均分
    }    
    fout<<endl;


}
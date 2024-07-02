#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <vector>
#include <ctime>

using namespace std;


class room{
public:
    string name;
    bool monster;
    bool princess;
    //if the room has the monster/princess,then these val=1;
    map <string,room*> exits;

    room(string name) : name(name), monster(false), princess(false) {}
    //默认房间都是没有公主和怪兽，方便后续“随机”添加公主和怪兽的位置

    void echo(){
        //输出房间信息
        cout << "Welcome to the " << name << ". There are " << exits.size() << " exits:";
        for (const auto& exit : exits) {
            cout << " " << exit.first;
        }
        cout << endl << "Enter your command: ";
    }

    void addway(string direction,room* new_room){
        exits[direction]=new_room;
    }
    //给房间增加出口以及通往的其他房间
};

class game{
private:
    room* currentroom;
    vector <room*> rooms;//储存所有房间
    bool game_on;//game_on=1,则游戏继续
    bool with_princess;//找到公主后开始重新返回lobby，将此val置true.

    void initial(){//开始建立房间地图
        room* lobby = new room("Lobby");
        room* eastWing = new room("East Wing");
        room* westWing = new room("West Wing");
        room* dungeon = new room("Dungeon");
        room* tower = new room("Tower");
        room* courtyard = new room("Courtyard");
        room* library = new room("Library");
        room* garden = new room("Garden");
        room* basement = new room("Basement");
        room* attic = new room("Attic");
        room* observatory = new room("Observatory");

        lobby->addway("east", eastWing);
        lobby->addway("west", westWing);
        lobby->addway("down", dungeon);
        lobby->addway("up", tower);
        eastWing->addway("west", lobby);
        westWing->addway("east", lobby);
        westWing->addway("west",library);
        library->addway("east",westWing);
        dungeon->addway("up", lobby);
        tower->addway("down", lobby);
        tower->addway("east", courtyard);
        courtyard->addway("west", tower);
        courtyard->addway("north", garden);
        garden->addway("south", courtyard);
        garden->addway("north", library);
        garden->addway("west",dungeon);
        dungeon->addway("east",garden);
        library->addway("south", garden);
        basement->addway("up", dungeon);
        dungeon->addway("down",basement);
        attic->addway("down", tower);
        attic->addway("east",library);
        library->addway("west",attic);
        tower->addway("up",attic);
        attic->addway("north", observatory);
        observatory->addway("south", attic);
        observatory->addway("west",basement);
        basement->addway("east",observatory);
        //所有的exit都是单向的！！！
        rooms.push_back(lobby);
        rooms.push_back(eastWing);
        rooms.push_back(westWing);
        rooms.push_back(dungeon);
        rooms.push_back(tower);
        rooms.push_back(courtyard);
        rooms.push_back(library);
        rooms.push_back(garden);
        rooms.push_back(basement);
        rooms.push_back(attic);
        rooms.push_back(observatory);

        // Place the monster and princess
        observatory->monster = true;
        garden->princess = true;
        
        currentroom = lobby;
    }

public:
    game():game_on(true), with_princess(false){//the game begins
        initial();
    }

    ~game() {//结束游戏后清空room
        for (room* room : rooms) {
            delete room;
        }
    }

    void start(){
        while (game_on){//游戏继续
            currentroom->echo();//显示房间信息
            string go,command;//分别用来储存go字符串和方向字符串
            cin>>go;//读入第一个单词
            if(go=="go"){//正确输入第一个单词go
                cin>>command;//读入第二个单词
                if(currentroom->exits.count(command)){
                    //如果存在这个方向的出口    
                    currentroom=currentroom->exits[command];//迭代进入下一个房间！ 

                    if(currentroom->monster){//如果房间里有怪兽
                        cout << "You've encountered a monster! Game over." << endl;
                        game_on = false; 
                        //stop the game                       
                    }

                    if(currentroom->name=="Lobby" && with_princess==true){//如果带着公主重返lobby，则游戏成功
                        cout<<"You successfully took the princess out of the crisis"<<endl;
                        game_on = false;
                        //stop the game
                    }

                    if(currentroom->princess){//如果房间里有公主
                        currentroom->princess=false;
                        with_princess=true;//遇到公主后，该房间里的公主标记消失，开始返程。

                        cout<<"You find thee princess!"<<endl;    
                        cout<<"Princess: \"My lord!Finally you found me! \""<<endl;
                        cout<<"You:\"Let's get out of here,my Princess!\""<<endl;
                        cout<<"So your return adventure begins!"<<endl;
                        //上述是找到公主后角色和公主的交流以及交互界面的提示语
                    }          
                }

                else{//第二个单词不是合法方向
                cout<<"There's no exit in this direction!"<<endl;
                }
            }
            else{//第一个单词不是go
                cout<<"Invalid command!"<<endl;
            }
        }        
    }
};



int main(){
    game temp;
    temp.start();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

vector<string>user_stats;
vector<string>computer_stats;
string user_move="u";
string computer_move="c";
bool Someone_Won = false;
vector<string>possible_moves = {"Rock","Paper","Scissor"};
void init_game();
void start_game();
void show_stats();
string who_won();
void user_chance();
void computer_chance();
int main(){
    
    bool want_to_play=false;
    char user_input = 'n';

    do{
       init_game();

       start_game();
       cout<<" Do You Want to play Again(y/n) : ";
       cin>>user_input;
       want_to_play = (user_input=='y' || user_input == 'Y')?true:false;
       if(!want_to_play){
           show_stats();
       }

    }while(want_to_play);


    return 0;
}

void init_game(){
   Someone_Won = false;
   system("cls");
}
void start_game(){
  int chance = 1;
  
  while(Someone_Won==false){
      if(chance){
        user_chance();
        chance = 0;
      }
      else{
        computer_chance();
        chance = 1;
      }
     

  }
  //system("cls");
}
void user_chance(){
   cout<<"    Your Move : ";
   cin>>user_move;


}
void computer_chance(){
  int index = rand()%3;
  computer_move = possible_moves[index];
  cout<<"   Computer's Move is : "<<possible_moves[index]<<endl;
  string who = who_won();
  //cout<<who<<endl;
  if(who=="PC"){
    user_stats.push_back("You Lose !");
    computer_stats.push_back("You Won !");
    cout<<"You Lose !"<<endl;
    Someone_Won = true;
  }
  else if(who=="I"){
    user_stats.push_back("You Won !");
    computer_stats.push_back("You Lose !");
    Someone_Won = true;
    cout<<"   You Lose !"<<endl;
  }
  else{
     user_stats.push_back("Tie !");
     computer_stats.push_back("Tie !");
  }

}
string  who_won(){  // i didn't include all possible cases because that wasn't in problem description
    if(user_move==computer_move){
        return "no one";
    }
   else if((user_move=="Rock") &&  (computer_move=="Paper")){
        return "PC";
    }
    else if((user_move=="Paper") &&  (computer_move=="Scissor")){
        return "PC";
    }
    else if((user_move=="Rock") &&  (computer_move =="Scissor")){
        return "I";
    }
    else{
        return "no one";
    }
}

void show_stats(){
  cout<<endl;
  cout<<"      Playing Stats : "<<endl;
  cout<<endl;
  int n = user_stats.size();
  for(int i=0;i<n;i++){
    cout<<"    Match : "<<i+1<<" . "<<user_stats[i]<<"      "<<computer_stats[i]<<" | "<<endl;
  }
  cout<<endl;
  cout<<endl;
  cout<<endl;
}
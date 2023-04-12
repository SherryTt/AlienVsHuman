#include <iostream> 
#include <string>
#include <stdlib.h> //For rand
#include <fstream> //For reading file
#include <unistd.h> //For sleep
#include <ctype.h> //For validation uses<isalpha>etc
#include "Design.h"

using namespace std;


class GuessWord 
{
  private:

    bool win;
    string letter,word, guessed;  //  UserGuess/AnswerWord/UserGuessedWord
    int choice,pass,score,live;   // LevelControl/Number of GameClear/TotalRemainingLives/Live

 
  public:

    void play_game(string name);       
    int level_change(int pass);           
    int random_num(int choice);
    string random_word(int random_num);
    int write_word(string word,string guessed);
    void main_page(int live,int pass);
    void result(int live,int score,int pass,string word,string name);
    void bonus_page(int live);
    void repeat_game(string name);
    
}; 

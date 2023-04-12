#include "GuessWord.h"
#include "Design.h"
#include "Exception.h"



//whole game<Combining all the function of GuessWord into this>

void GuessWord::play_game(string name)
{ 
    int num, pass=1,live=7;
    int* score = new int;
    *score = 0;
    string guessed;

    bool* status;
    status = new bool;
    myexception myex;

  do{    
        //Generating random word
        choice=level_change(pass);       
        num=random_num(choice);
        word=random_word(num);


        //Loop start
        while(live>0)
        {
              win=true;
              main_page(live,pass);
              write_word(word,guessed);

              //If guess word is correct then break while loop
              if(win==true)
              {
                break;
              }
    
                  //Getting guess
                  cout<<"\n\nletters guessed: "<<guessed<<endl;
                do{
                      cout<<"\n\nEnter a letter: ";
                      cin>>letter;

                    try    //validation
                    {     
                        if(isalpha(letter[0])) 
                        { 
                          *status=true;
                          letter = tolower(letter[0]);
                        }                         
                        else 
                        {   
                          *status=false;
                          throw myex;
                        }          
                      }
                      catch(exception& myex)   
                      {
                          cout<<myex.what()<<endl;         
                      }

                  }while(*status==false);
  

              //Display guessed latter
              guessed+=letter[0];

              //Live control
              if(word.find(letter)!= -1)
              {     
                system("clear");  //Guessed word correct no reduce live
                continue;
              }
              else
              {
                system("clear"); //Guessed word wrong -1 reduce live
                live--;
              }

            } //while loop end


      //Guess correct
      if(live>0)
      {   
          cout<<"\n\n\n\t\t\t\t Correct!!\n\n";
          cout<<"THE WORD WAS: "<<word<<endl;
          cout<<"Stage: "<<pass<<" clear!!!!!!!!!!!!"<<endl;
          sleep(2);
          ++pass;
          *score+=live;
          *status=true;
      }

      //Game over
      if(live==0)
      {   
          main_page(live,pass);//To display case 0 before gameover page
          sleep(3);
          result(live,*score,pass,word,name);
          *status=false;  
      }

      //Bonus and game complete 
      switch(pass)
      {
       case 4: 
       bonus_page(live);
       break;

       case 6: 
       result(live,*score,pass,word,name);
       *status=false;
       break;
      }
   

      //reset the parameter for next round
      word="";
      letter="";
      guessed="";
      live=7;

    }while(*status==true); //do while loop end


      delete status;
      delete score;

} //End


///////////////////////////////////////////////////////////////////////////////////////////////


//Controll the level
 int GuessWord::level_change(int pass)
{
    int choice;

        system("clear");
        if(pass<=3) //Less than pass 3 will assign choice 1
        {      
              choice=1;
        }
        else if(pass>3) //More than pass 3 will assign choice 2
        {
              choice=2;
        }
        return choice;
}




//Assign the random number depends on the choice
int GuessWord::random_num(int choice)
{
    srand(time(NULL)); 
      int random;

    if(choice==1)   
      random= (rand()%(11+1 -1))+1;  // Pick the number between 1-11

    if(choice==2)
      random= (rand()%(16+1 -12))+12; // Pick the number between 12-16

  return random;
}





//Generating random words
string GuessWord::random_word(int random_num)
{
    int counter=1; //Word list number from 1
    string line, word;

    ifstream fin;
    fin.open("word_list.txt");
    if(fin.is_open())   //File exception
    {
      while(getline(fin,line))
      {   
        if(random_num==counter)
        {  
           word=line;
           break;
        }
        counter++;
      }
    }
    else
    { 
       cout<<"Error in opening the file!"<<endl;
       exit(0);
    }
    return word;
    fin.close();
}





//Display word
int GuessWord::write_word(string word,string letter)
{ 
    for(int x=0;x<word.size();x++)
    {   
        //Display correct word with space after
        if(letter.find(word.at(x)) != -1)
            cout<<word.at(x)<< " ";
        else
        {
           //Display guess word length with "_" Only first time
            cout<<"_";
            win=false;
        }    
    }   
    return 0;
}




//Result
void GuessWord::result(int live,int score,int pass,string word,string name)
{ 
  //Game over
  if(live==0)
  {
        Design new_game1;
        new_game1.lose();

        cout<<"YOU MADE WRONG GUESS !!!!!!\n";
        cout<<"THE WORD WAS: "<<word<<endl;
        cout<<"\n";
        cout<<"You saved "<<score<<" human out of "<<pass*7<<" humans"<<endl;
        cout<<"Good try "<<name<<" ★★★"<<endl;
  }

  //Game complete
  if(live>0)
  {
      Design new_game1;
      new_game1.win();

      cout<<"Congratulations!!!\n";
      cout<<"THE WORD WAS: "<<word<<"\n";
      cout<<"\n";
      cout<<"You saved "<<score<<" human out of "<<pass*7<<" humans\n";
      cout<<"Well done!! You are the hero "<<name<<" ★★★"""<<endl;
    }

    sleep(3);
    repeat_game(name);
}
  


//Bonus page <Display after 3 round>
void GuessWord::bonus_page(int live)
{
    bool status;
    if(live==0) //To skip bonus display when it's Gameover 
    {
        status=false;
     }
    else
    {
        Design new_game1;
        new_game1.bonus();
        sleep(4);
    }
}



//Repeat Game
void GuessWord::repeat_game(string name)
{   
    char repeat;
    bool error;
    cout<<"\nWould you like to play again??? (Y - N) : ";
  do{
        cin>>repeat;  
    
        if(repeat=='y'||repeat=='Y')
        {   
            error=false;
            play_game(name);
        }   
        else if(repeat=='n'||repeat=='N')
        { 
            error=false;
            system("exit");
        }
        else
        {
          cout<<"Invalid! Enter again: ";
          error=true;    
        }
    }while(error==true);

}


//main UI
void GuessWord::main_page(int live,int pass)
{                 
  switch(live) 
  { 
    case 7:

    cout<<"                        ／￣￣￣￣＼\n";
    cout<<"　　　　             ___|) ○　○　○ (|__\n";
    cout<<"　　　　            ／＿＿＿＿＿＿＿＿＼\n";
    cout<<"　　        　 　 ￣ ＼\\＿＼\\＿_／＿／ ￣\n";
    cout<<"　　        　　　 　／　　　　　　 ＼\n";
    cout<<"       ZzzuuzzzZuzzz／　　 ξ　 　 　 \\ZzzuuzzzZuzzz \n";
    cout<<"　　    　　　　　 ／　　　　　  　　 \\ \n";
    cout<<"　　　　　　      ／　　　　　 ξ 　　　\\ \n";
    cout<<"                                                        \n";
    cout<<"            O     O    O     O     O    O　　O \n";
    cout<<"           /|\\   /|\\  /|\\   /|\\   /|\\  /|\\  /|\\ \n";
    cout<<"            /\\   /\\    /\\    /\\    /\\  /\\    /\\  \n";
    cout<<"===================================================================================\n";
    cout<<"                     TOPIC : Universe\n";
    cout<<"                     Question:"<<pass<<"/"<<5<<endl;
    cout<<""<<endl;                                                                                        
    cout<<"===================================================================================\n";
    cout<<""<<endl;
      break;
    

    case 6:   

    cout<<"                        ／￣￣￣￣＼\n";
    cout<<"　　　　             ___|) ○　○　○ (|__\n";
    cout<<"　　　　            ／＿＿＿＿＿＿＿＿＼\n";
    cout<<"　　        　 　 ￣ ＼\\＿＼\\＿_／＿／ ￣\n";
    cout<<"　　        　　　 　／　　　　　　 ＼\n";
    cout<<"                    ／ HELP MEEE      \\ \n";
    cout<<"　　    　　　　　 ／　　　　ヽoﾉ      \\ \n";
    cout<<"     ZzzuuzzzZuzzz/       　へ//        \\ZzzuuzzzZuzzz　\n";
    cout<<"                 /             >    　　 \\ \n";
    cout<<"　　　　　　    ／　　　　        　 OMG  \\ \n";
    cout<<"                                             \n";
    cout<<"            O     O           O     O    O　　O \n";
    cout<<"           /|\\   /|\\         /|\\   /|\\  /|\\  /|\\ \n";
    cout<<"            /\\   /\\           /\\    /\\  /\\    /\\  \n";
    cout<<"===================================================================================\n";
    cout<<"                     TOPIC : Universe\n";
    cout<<"                     Question:"<<pass<<"/"<<5<<endl;
    cout<<"                                              "<<1<<"/"<<7<<"people are abducted"<<endl;
    cout<<"===================================================================================\n";
    cout<<""<<endl;
    break;

    case 5:
    cout<<"                        ／￣￣￣￣＼\n";
    cout<<"　　　　             ___|) ○　○　○ (|__\n";
    cout<<"　　　　            ／＿＿＿＿＿＿＿＿＼\n";
    cout<<"　　        　 　 ￣ ＼\\＿＼\\＿_／＿／ ￣\n";
    cout<<"　　        　　　 　／　　　　　　 ＼\n";
    cout<<"                    ／ OHHoooo        \\ \n";
    cout<<"　　    　　　　　 ／　　　　ヽoﾉ      \\ \n";
    cout<<"     ZzzuuzzzZuzzz/       　へ//        \\ZzzuuzzzZuzzz　\n";
    cout<<"                 /             >    　　 \\ \n";
    cout<<"　　　　　　    ／　　　　        　 OMG  \\ \n";
    cout<<"                                             \n";
    cout<<"            O     O                  O    O　　O \n";
    cout<<"           /|\\   /|\\                /|\\  /|\\  /|\\ \n";
    cout<<"            /\\   /\\                  /\\  /\\    /\\  \n";
    cout<<"===================================================================================\n";
    cout<<"                     TOPIC : Universe\n";
    cout<<"                     Question:"<<pass<<"/"<<5<<endl;
    cout<<"                                            "<<2<<"/"<<7<<"people are abducted"<<endl;
    cout<<"===================================================================================\n";
    cout<<""<<endl;
    break;
   
    case 4:
    cout<<"                        ／￣￣￣￣＼\n";
    cout<<"　　　　             ___|) ○　○　○ (|__\n";
    cout<<"　　　　            ／＿＿＿＿＿＿＿＿＼\n";
    cout<<"　　        　 　 ￣ ＼\\＿＼\\＿_／＿／ ￣\n";
    cout<<"　　        　　　 　／　　　　　　 ＼\n";
    cout<<"                    ／ Good byee      \\ \n";
    cout<<"　　    　　　　　 ／　　　　ヽoﾉ      \\ \n";
    cout<<"     ZzzuuzzzZuzzz/       　へ//        \\ZzzuuzzzZuzzz　\n";
    cout<<"                 /             >    　　 \\ \n";
    cout<<"　　　　　　    ／　　　　        　      \\ \n";
    cout<<"                                             \n";
    cout<<"            O     O                        O　　O \n";
    cout<<"           /|\\   /|\\                      /|\\  /|\\ \n";
    cout<<"            /\\   /\\                       /\\    /\\  \n";
    cout<<"===================================================================================\n";
    cout<<"                     TOPIC : Universe\n";
    cout<<"                     Question:"<<pass<<"/"<<5<<endl;
    cout<<"                                            "<<3<<"/"<<7<<"people are abducted"<<endl;
    cout<<"===================================================================================\n";
    cout<<""<<endl;
    break;
    
    case 3:
    cout<<"                        ／￣￣￣￣＼\n";
    cout<<"　　　　             ___|) ○　○　○ (|__\n";
    cout<<"　　　　            ／＿＿＿＿＿＿＿＿＼\n";
    cout<<"　　        　 　 ￣ ＼\\＿＼\\＿_／＿／ ￣\n";
    cout<<"　　        　　　 　／　　　　　　 ＼\n";
    cout<<"                    ／ Owwwwww        \\ \n";
    cout<<"　　    　　　　　 ／　　　　ヽoﾉ      \\ \n";
    cout<<"     ZzzuuzzzZuzzz/       　へ//        \\ZzzuuzzzZuzzz　\n";
    cout<<"                 /             >    　　 \\ \n";
    cout<<"　　　　　　    ／　wow　　　             \\ \n";
    cout<<"                                             \n";
    cout<<"            O     O                          　　O \n";
    cout<<"           /|\\   /|\\                            /|\\ \n";
    cout<<"            /\\   /\\                              /\\  \n";
    cout<<"===================================================================================\n";
    cout<<"                     TOPIC : Universe\n";
    cout<<"                     Question:"<<pass<<"/"<<5<<endl;
    cout<<"                                             "<<4<<"/"<<7<<"people are abducted"<<endl;
    cout<<"===================================================================================\n";
    cout<<""<<endl;
    break;

    case 2:
    cout<<"                        ／￣￣￣￣＼\n";
    cout<<"　　　　             ___|) ○　○　○ (|__\n";
    cout<<"　　　　            ／＿＿＿＿＿＿＿＿＼\n";
    cout<<"　　        　 　 ￣ ＼\\＿＼\\＿_／＿／ ￣\n";
    cout<<"　　        　　　 　／　　　　　　 ＼\n";
    cout<<"                    ／ Oh my god      \\ \n";
    cout<<"　　    　　　　　 ／　　　　ヽoﾉ      \\ \n";
    cout<<"     ZzzuuzzzZuzzz/       　へ//        \\ZzzuuzzzZuzzz　\n";
    cout<<"                 /             >    　　 \\ \n";
    cout<<"　　　　　　    ／　awwww　　　           \\ \n";
    cout<<"                                             \n";
    cout<<"            O     O                          　　 \n";
    cout<<"           /|\\   /|\\                            \n";
    cout<<"            /\\   /\\                              \n";
    cout<<"===================================================================================\n";
    cout<<"                     TOPIC : Universe\n";
    cout<<"                     Question:"<<pass<<"/"<<5<<endl;
    cout<<"                                             "<<5<<"/"<<7<<"people are abducted"<<endl;
    cout<<"===================================================================================\n";
    cout<<""<<endl;
    break;
    
    case 1:

    cout<<"                        ／￣￣￣￣＼\n";
    cout<<"　　　　             ___|) ○　○　○ (|__\n";
    cout<<"　　　　            ／＿＿＿＿＿＿＿＿＼\n";
    cout<<"　　        　 　 ￣ ＼\\＿＼\\＿_／＿／ ￣\n";
    cout<<"　　        　　　 　／　　　　　　 ＼\n";
    cout<<"                    ／ HELP MEEE      \\ \n";
    cout<<"　　    　　　　　 ／　　　　ヽoﾉ      \\ \n";
    cout<<"     ZzzuuzzzZuzzz/       　へ//        \\ZzzuuzzzZuzzz　\n";
    cout<<"                 /             >    　　 \\ \n";
    cout<<"　　　　　　    ／　　　　        　 OMG  \\ \n";
    cout<<"                                             \n";
    cout<<"                   ＿|￣|○                          　　  \n";
    cout<<"===================================================================================\n";
    cout<<"                     TOPIC : Universe\n";
    cout<<"                     Question:"<<pass<<"/"<<5<<endl;
    cout<<"                                            "<<6<<"/"<<7<<"people are abducted"<<endl;
    cout<<"===================================================================================\n";
    cout<<""<<endl;
    break;
    
    case 0:

    cout<<"                        ／￣￣￣￣＼\n";
    cout<<"　　　　             ___|) ○　○　○ (|__\n";
    cout<<"　　　　            ／＿＿＿＿＿＿＿＿＼\n";
    cout<<"　　        　 　 ￣ ＼\\＿＼\\＿_／＿／ ￣\n";
    cout<<"　　        　　　 　／　　　　　　 ＼\n";
    cout<<"                    ／All are abducted\\ \n";
    cout<<"　　    　　　　　 ／　　　　ヽoﾉ      \\ \n";
    cout<<"     ZzzuuzzzZuzzz/       　へ//        \\ZzzuuzzzZuzzz　\n";
    cout<<"                 /             >    　　 \\ \n";
    cout<<"　　　　　　    ／　　　　       　 nooo  \\ \n";
    cout<<"                                       　　  \n";
    cout<<"===================================================================================\n";
    cout<<"                     TOPIC : Universe\n";
    cout<<"                     Question:"<<pass<<"/"<<5<<endl;
    cout<<"                                                        All are abducted"<<endl;
    cout<<"===================================================================================\n";
    cout<<""<<endl;
    break;
  }

}
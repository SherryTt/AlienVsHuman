#include "Design.h"
#include "GuessWord.h"
#include "Exception.h"



//Combining whole game
void Design::menu()
{

    bool _result;
    bool* result=&_result;
    int _option;
    int* option=&_option;

    myexception myex;
    

    
    
        cout<<"★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";
        cout<<"|                                                                        |\n";  
        cout<<"|         Welcome to Alien vs Human game!! What is you name?             |\n";
        cout<<"|                                                                        |\n";  
         cout<<"★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";
 
  //First loop for the name validation
 do{  
          cout<<"- - - > ";
          getline(cin,name);
          string name=getName();

      try{
         
           for(int i=0;i<name.length();i++)
          
    
            if(isalpha(name[i]))
            {
                 //Second loop for back to menu
              do{
        
                   system("clear");

                      cout<<"           _ _                      _    _\n";                             
                      cout<<"     /\\   | (_)                    | |  | |\n";                             
                      cout<<"    /  \\  | |_  ___ _ __ __   _____| |__| |_   _ _ __ ___   __ _ _ __\n";   
                      cout<<"   / /\\ \\ | | |/ _ | '_ \\  \\ / / __|  __  | | | | '_ ` _ \\ / _` | '_ \\ \n"; 
                      cout<<"  /  __\\  | | |  __| | | |\\ V /\\__ | |  | | |_| | | | | | | (_| | | | |\n"; 
                      cout<<" /_/    \\_|_|_|\\___|_| |_| \\_/ |___|_|  |_|\\__,_|_| |_| |_|\\__,_|_| |_|\n"; 
                      cout<<"\n";
                      cout<<"★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★ Menu ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n"; 
                      cout<<"|                                                                        |\n";                 
                      cout<<"|                             1. HELP                                    |\n";
                      cout<<"|                             2. PLAY                                    |\n";
                      cout<<"|                             3. EXIT                                    |\n";
                      cout<<"|                                                                 　　   |\n";
                      cout<<"★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";
                      cout<<"\n";
      
     
                      cout <<"Hi "<<name<<"! select the number to start! ";
                      cin>>*option;
        
                      //Validating the option value
                      try
                      {
                        if(*option>3||*option<1)  //If option is not between 1-3
                        {         
                           throw myex; 
                        }
                        else                    //If option is between 1-3
                        {
                          switch(*option)
                          {     

                                case 1:   //Instrunction page     
                                help();
                                *result=true;
                                break;

                                case 3:     //Exit: It's not in order due to jumping bypasses variable in case2
                                cout<<"See you next time!! "<<name<<endl;
                                exit(0);
                                break;

                                case 2:    //Play game
                                GuessWord mygame;
                                mygame.play_game(name);
                                *result=true;
                                break;

                          }
                        }
                      }
                      catch(exception& myex)   //Display invalid msg for the option validation
                      {
                         cout<<myex.what()<<endl;
                      }
                }while(((*option>3||*option<1)==true)||(*result==true));
                
            }
            else  //If input name is invalid
            {   
              *result=false;
              throw myex;
            }   
            
        }  
        catch(exception& myex)   //Display invalid msg for the name validation
        {
           cout<<myex.what()<<endl;  
        }

  }while(*result==false);  


    delete result;
    delete option;

}


//Instruction page
void Design::help()
{ 
    char option;
    bool result;

            
          system("clear");

          cout<<"★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";
          cout<<"|                                H E L P                                |\n";
          cout<<"★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";
          cout<<"| <Rule>                                                                |\n";
          cout<<"|You guess correct word related to Astro. Question 1-3 will be easy and |\n";
          cout<<"|after 4-5 will be difficult mode. If you clear the 5 question means    |\n";
          cout<<"|you are completed this game! You have 7attempts to guess the word.     |\n";
          cout<<"|                                                                 　　  |\n";
          cout<<"| <Story>                                                               |\n";       
          cout<<"|You are alien buster protecting a human from an aliens.                |\n";
          cout<<"|If you guess wrong, 1 human(attempt) will be taken by alien. A reminder|\n";
          cout<<"|of attempt will be your score at end of this game. How many humans you |\n";
          cout<<"|can save till end of this game! Good luck                              |\n";
          cout<<"|                                                                  　   |\n";
          cout<<"|*  [enter] to submit a word                                            |\n";
          cout<<"|                                                                  　   |\n";
          cout<<"★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n";

          cout << '\n' << "・Press any number to back to menu\n"<<endl;

          do
          {
             cin>>option;       

             if(isdigit(option))
              {
                result=true;
              }
              else
              {
                cout<<"Invalid input! Enter again: ";
                result=false;
              }
            
          }while(result==false);
             
}



//This bonus page will be displayed after 3rd round
void Design::bonus()
{

    system("clear");

    cout<<"                                         )  (  (    (\n";
    cout<<"                                         (  )  () @@  )  (( (\n";
    cout<<"                                     (      (  )( @@  (  )) ) (\n";
    cout<<"                                   (    (  ( ()( /---\\   (()( (\n";
    cout<<"     _______                            )  ) )(@ !O O! )@@  ( ) ) )\n";
    cout<<"    <   ____)                      ) (  ( )( ()@ \\ o / (@@@@@ ( ()( )\n";
    cout<<" /--|  |(  o|                     (  )  ) ((@@(@@ !o! @@@@(@@@@@)() (\n";
    cout<<"|   >   \\___|                      ) ( @)@@)@ /---\\-/---\\ )@@@@@()( )\n";
    cout<<"|  /---------+                    (@@@@)@@@( // /-----\\ \\ @@@)@@@@@(  .\n";
    cout<<"| |    \\ =========______/|@@@@@@@@@@@@@(@@@ // @ /---\\ @ \\ @(@@@(@@@ .  .\n";
    cout<<"|  \\   \\=========------\\|@@@@@@@@@@@@@@@@@ O @@@ /-\\ @@@ O @@(@@)@@ @   .\n";
    cout<<"|   \\   \\----+--\\-)))           @@@@@@@@@@ !! @@@@ % @@@@ !! @@)@@@ .. .\n";
    cout<<"|   |\\______|_)))/             .    @@@@@@ !! @@ /---\\ @@ !! @@(@@@ @ . .\n";
    cout<<" \\__==========           *        .    @@ /MM  /\\O   O/\\  MM\\ @@@@@@@. .\n";
    cout<<"    |   |-\\   \\          (       .      @ !!!  !! \\-/ !!  !!! @@@@@ .\n";
    cout<<"    |   |  \\   \\          )   -cfbd-   .  @@@@ !!     !!  .(. @.  .. .\n";
    cout<<"    |   |   \\   \\        (    /   .(  . )). ( |O  )( O! @@@@ . )      .\n";
    cout<<"    |   |   /   /         ) (      )).  ((  .) !! ((( !! @@ (. ((. .   .\n";
    cout<<"    |   |  /   /   ()  ))   ))   .( ( ( ) ). ( !!  )( !! ) ((   ))  ..\n";
    cout<<"    |   |_<   /   ( ) ( (  ) )   (( )  )).) ((/ |  (  | \\(  )) ((. ).\n";
    cout<<" ________________________________________________________________________________\n";
    cout<<"|         __          __           _ _                          _                |\n"; 
    cout<<"|         \\ \\        / /          | | |                        | |               |\n";
    cout<<"|          \\ \\  /\\  / ___  _ __ __| | |__   ___  __ _ _ __ ___ | |               |\n";
    cout<<"|           \\ \\/  \\/ / _ \\| '__/ _` | '_ \\ / _ \\/ _` | '_ ` _ \\| |               |\n";
    cout<<"|            \\  /\\  | (_) | | | (_| | |_) |  __| (_| | | | | | |_|               |\n";
    cout<<"|             \\/  \\/ \\___/|_|  \\__,_|_.__/ \\___|\\__,_|_| |_| |_(_)               |\n";
    cout<<"|                                                                                |\n";
    cout<<"|                                                                                |\n";
    cout<<"| Alien get angry!!!!!!                                                          |\n";
    cout<<"|                                                                                |\n";
    cout<<"| The guess word will be dificult mode  . . . Are you ready??                    |\n";
    cout<<"|                                                                                |\n";
    cout<<"|________________________________________________________________________________|\n"; 

}

void Design::win()
{

    system("clear");

    cout<<"  *    .                                       .   ,          *    .\n";     
    cout<<"           .       . .        *\n";
    cout<<" *   .   .'    * ,      .       .  ,                               .  ,     *    .       .  , \n";
    cout<<"   .     *     .'\n";
    cout<<"   '     .     .  *        *  .'.    .     .  *        *  .'.                  .'    * ,\n";
    cout<<"       .   ' '        .    .    '   .\n";
    cout<<".                               '      *                       BYE!!!!                  **   .   .' \n";
    cout<<"   '     .     .  *           * ,\n";
    cout<<"       .              .    .     .  *           * ,            .---.\n";
    cout<<"  .  *                            *  .'.          === == =   _/__~0_\\_     .  *                   .' \n";    
    cout<<"   '     .     .  *        *  .'.   .         ==== === == = (_________)                .    . \n";     
    cout<<"   .   .'    * ,      .       .  ,     **   .   .'    * ,      .       .  ,     *\n";
    cout<<"   .     *     .'\n";
    cout<<"   '     .     .  *        *  .'.    .     .  *                                         .   .'    *\n";
    cout<<"####################################################################################################\n";
    cout<<"     __  __ _         _                                       _      _           _\n"; 
    cout<<"    |  \\/  (_)       (_)                                     | |    | |         | |\n";
    cout<<"    | \\  / |_ ___ ___ _  ___  _ __   ___ ___  _ __ ___  _ __ | | ___| |_ ___  __| |\n";
    cout<<"    | |\\/| | / __/ __| |/ _ \\| '_ \\ / __/ _ \\| '_ ` _ \\| '_ \\| |/ _ | __/ _ \\/ _` |\n";
    cout<<"    | |  | | \\__ \\__ | | (_) | | | | (_| (_) | | | | | | |_) | |  __| ||  __| (_| |\n";
    cout<<"    |_|  |_|_|___|___|_|\\___/|_| |_|\\___\\___/|_| |_| |_| .__/|_|\\___|\\__\\___|\\__,_|\n";
    cout<<"                                                       | |\n";                         
    cout<<"                                                       |_|\n";                         
    cout<<"####################################################################################################\n";

}



void Design::lose()
{
    system("clear");

    cout<<"                               .-""""-.          .-""""-.\n";
    cout<<"                            /        \\    /        \\\n";
    cout<<"                           /_        _\\  /_        _\\\n";
    cout<<"                          // \\      / \\ // \\      / \\\n";
    cout<<"                          |\\__\\    /__/||\\__\\    /__/|\n";
    cout<<"                          \\    ||     /  \\    ||    /\n";
    cout<<"                           \\         /    \\        /\n";
    cout<<"                            \\  __   /      \\  __  /\n";
    cout<<"                      .-""""-.   '.__.'    .-""""-. '.__.'    .-""""-.\n";
    cout<<"                   /        \\ |  | /        \\ |  | /        \\\n";
    cout<<"                  /_        _\\|   /_        _\\|   /_        _\\\n";
    cout<<"                 // \\      / \\   // \\      / \\   // \\      / \\\n";
    cout<<"                 |\\__\\    /__/|  |\\__\\    /__/|  |\\__\\    /__/|\n";
    cout<<"                 \\    ||      /   \\    ||    /    \\    ||    /\n";
    cout<<"                  \\          /     \\        /      \\        /\n";
    cout<<"                    \\  __   /       \\  __  /        \\  __  /\n";
    cout<<"                      '.__.'         '.__.'          '.__.'\n";
    cout<<"                       |  |           |  |           |  |\n";
    cout<<"                       |  |           |  |           |  |\n";
    cout<<"####################################################################################################\n";
    cout<< "                   _____          __  __ ______  ______      ________ _____\n";    
    cout<<"                  / ____|   /\\   |  \\/  |  ____|/ __ \\ \\    / |  ____|  __ \\\n"; 
    cout<<"                 | |  __   /  \\  | \\  / | |__  | |  | \\ \\  / /| |__  | |__) |\n";
    cout<<"                 | | |_ | / /\\ \\ | |\\/| |  __| | |  | |\\ \\/ / |  __| |  _  /\n"; 
    cout<<"                 | |__| |/ ____ \\| |  | | |____| |__| | \\  /  | |____| | \\ \\\n" ;
    cout<<"                  \\_____/_/    \\_|_|  |_|______|\\____/   \\/   |______|_|  \\_\\\n";
    cout<<"####################################################################################################\n";
    
}


string Design::getName()
{
  return name;
}
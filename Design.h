#include <iostream>
#include <string>
#include <ctype.h> //For validation <isalpha> etc

using namespace std;

#ifndef DESIGN_H
#define DESIGN_H


class Design
{
  private:
    string name;

	public:

	  void menu();
		void help();
		void bonus();
    void win();
    void lose();
    string getName();

};
#endif

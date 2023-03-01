//Implementation file for helper header

#include "helper.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

//Menu-------------------------------------------------------------------------
void menu()
{   cout<<endl<<endl;
    cout<<"*************************************************************"<<endl;
    cout<<"Welcome to even planning app!"<<endl;
    cout<<"This app will help you keep track of your even planning tasks"<<endl;
    cout<<"*************************************************************"<<endl;
    cout<<endl<<"Here are all the tasks that need to get done: "<<endl;
}

//Getting a task function------------------------------------------------------
void getTask(char*&aTask)
{
    char newTask[100];
    cout<<endl<<endl<<"please enter the task that you have finished: ";
    cin.clear();
    cin.get(newTask, 100);
    cin.ignore();
  
    aTask = new char[strlen(newTask)+1];
   
    strcpy(aTask, newTask);
    toUpper(aTask);
}

//conver string to upper-------------------------------------------------------
void toUpper(char*word)
{
    int c = 0;
    while (word[c])
    {
        word[c] = toupper(word[c]);
        c++;
    }
}


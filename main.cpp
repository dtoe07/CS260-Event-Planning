/******************************************************************************

Created by: Dinh Nguyen
Project 5 - CS260

This program is to help planning am even, will allow user to input a aTask
and will output all the tasks that has to be done after that current task
is finished. This can also print out all the tasks from the beginning to end
in related order to make the even successful.

*******************************************************************************/

#include "graph.h"
#include "helper.h"

int main()
{
    
    Graph graph;    //Create new graph
    graph.load();   //loading data from file to graph
    char*aTask;
    int i = 0;
    
    menu();     //displaying message
    
    graph.DFS_Display();    //using DFS method to display all tasks
    
    getTask(aTask);     //getting input from user
    if(graph.getIndex(aTask, i))    //if valid input, display the remaining tasks
    {
        cout<<"The remaining tasks are:"<<endl<<endl;
        graph.display(aTask);
	cout<<endl;
    }
    else    //if not, let the user know
    {
	cout<<"There is no such task..."<<endl;
    }
    cout<<"Good luck with the even!"<<endl<<endl;
return 0;
}


//Implementation file for graph header

#include "graph.h"
#include "helper.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;
int MAXCHAR = 100;

//constructor------------------------------------------------------------------
Graph::Graph()
{
    vertex = new Vertex[tasks];
}

//Destrcutor-------------------------------------------------------------------
Graph::~Graph()
{
    for(int i = 0; i<tasks; i++)
    {
        delete[]vertex[i].task;
        Edge*edge = vertex[i].head;
        Edge*curr;
        while(edge)
        {
            curr = edge;
            edge = edge->next;
            curr->next = NULL;
            delete curr;
        }
    }
    
    delete[]vertex;
}

//Insert new task data---------------------------------------------------------
void Graph::insertTask(int index, char*aTask)
{
    if(vertex[index].task)
	delete[]vertex[index].task;
	
    vertex[index].task = new char[strlen(aTask)+1];
	strcpy(vertex[index].task,aTask);
}

//Insert new edge to Vertex----------------------------------------------------
void Graph::insertEdge(int index, int newVertexNum)
{
    if(!vertex[index].head)
        vertex[index].head = new Edge(newVertexNum);
    else
    {
        Edge*curr = new Edge(newVertexNum);
        
        curr->next = vertex[index].head;
        vertex[index].head = curr;
    }
}

//Getting task index number----------------------------------------------------
bool Graph::getIndex(char*aTask, int & index)
{
    for(int i = 0; i<tasks ; i++)
    {
        if(strcmp(vertex[i].task, aTask) == 0)
        {
            index = i;
            return true;
        }
    }
    delete[]aTask;  //release aTask memory from heap if not found
return false;
}

//Display tasks after a task is done-------------------------------------------
void Graph::display(char*aTask)
{
    int index = 0;
    getIndex(aTask, index);
    delete[]aTask;      //release aTask memory from heap if found
    
    display(vertex[index+1]);
}

void Graph::display(const Vertex & aTask)
{
    cout<<aTask.task<<endl;
    if(aTask.head)
    {
        display(vertex[aTask.head->vertexNum]);
 
        if(aTask.head->next)
            display(vertex[aTask.head->next->vertexNum]);
    }
}

/* Extra credit displaying all path to completely plan an even ***************/
void Graph::DFS_Display()
{
    bool*visited = new bool[tasks];
    for(int i = 0; i < tasks; i++)
        visited[i] = false;
        
    DFS_Display(0, visited);
    delete[]visited;
}

void Graph::DFS_Display(int v, bool visited[])
{
    visited[v] = true;
    cout<<vertex[v].task<<", ";
    for(Edge*edge = vertex[v].head; edge != NULL; edge = edge->next)
    {
        if(!visited[edge->vertexNum])
        DFS_Display(edge->vertexNum, visited);
    }
}
/*****************************************************************************/

//Loading from file-----------------------------------------------------------
void Graph::load()
{
    ifstream in;
	char newTask[MAXCHAR];
	int newVertexNum;
	int index = 0;
	char kill;
	
	in.open("tasks.txt");
	if(!in)
	{
		cerr<<"fail to open"<<endl;
		exit(1);
	}

//start taking inputs
	in.clear();
	in.get(newTask, MAXCHAR, ' ');
	in.ignore(MAXCHAR, ' ');
	
	in.clear();
	in >> kill;
	while(!in.eof())
	{
	    toUpper(newTask);
	    insertTask(index, newTask);
	    //start inserting edges if exists
	    if(kill == '@')
	    {
	        do
	        {
	            in.clear();
                in >> newVertexNum;
		
	            insertEdge(index, newVertexNum);  //Inserting new edge
	            
	            in.clear();   //getting the next separator  to compare
	            in >> kill;
	        } while(kill != '|');
	    }
	    
	    //Start taking the next task
        in.ignore(MAXCHAR, '\n');
	    in.clear();
	    in.get(newTask, MAXCHAR, ' ');
	    in.ignore(MAXCHAR, ' ');
	
	    in.clear();
	    in >> kill; 
	    
	    index++;
	  }
}

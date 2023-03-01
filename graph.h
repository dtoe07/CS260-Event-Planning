//Header file for Graph ADT

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

//Declaring a graph class to manage all the graph operations
class Graph
{
    public:
        Graph();
        ~Graph();
        void load();
        
        void insertTask(int index, char*aTask);
        void insertEdge(int index, int newVertexNum);

        void display(char*aTask);
        bool getIndex(char*aTask, int & index);
        
        //Extra credit displaying all path to completely plan an even
        void DFS_Display();
    
    private:
        //Declaring a struct to store each neighbor
        struct Edge
        {
            int vertexNum;
            Edge*next;
            Edge(const int num)
            {
                this->vertexNum = num;
                next = NULL;
            }
        
        };
        //Declaring a struct to store each Vertex of tasks
        struct Vertex
        {
            char*task;
            Edge*head;
            Vertex(){task = NULL; head = NULL;}
            
        };
        
        int tasks = 10; //number of tasks in the list
        Vertex*vertex;  //declaring vertex pointer to initialize later
        
        void display(const Vertex & aTask);
        void DFS_Display(int v, bool visited[]);
};

#endif

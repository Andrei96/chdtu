#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <unistd.h>

using namespace std;

const int n = 7;
int GraphMap[n][n] = {{0,0,0,0,0,0,0},
     //A B C D E F/*
	{0,0,1,1,0,0,0},//A 1
	{0,1,0,1,1,1,0},//B
	{0,1,1,0,0,0,1},//C 1
	{0,0,1,0,0,1,0},//D 1
	{0,0,1,0,1,0,1},//E
	{0,0,0,1,0,1,0} //F 
	// {0,0,1,1,0,0,0},//A 1
	// {0,1,0,1,1,0,0},//B
	// {0,1,1,0,0,0,1},//C 1
	// {0,0,1,0,0,1,0},//D 1
	// {0,0,0,0,1,0,1},//E
	// {0,0,0,1,0,1,0} //F 
};	// 1   1     1	
int adjacentPeaks[n][n];
int queue[n];
int countQueue = 0;

int markV[n] = {0};
struct Graph
{
	int numberOfVertex;
	int inputVertex[n];
	int vertexCount;
	int firstInputSignal;
	int firstVertexSender;

};
	Graph *A = new Graph;

 	Graph *B = new Graph;
 	

 	Graph *C = new Graph;
 	

 	Graph *D = new Graph;
 	

 	Graph *E = new Graph;
 

 	Graph *F = new Graph;
 

Graph * getVertex(int numberOfVertex){
	switch(numberOfVertex){
		case 1: return A;
		case 2: return B;
		case 3: return C;
		case 4: return D;
		case 5: return E;
		case 6: return F;
}
}

void sendSignal(Graph *vertex, int signal, int fromVertex){
	cout<<"To "<<vertex->numberOfVertex<<" from "<<fromVertex<<endl;
	if (vertex->inputVertex[fromVertex] == 0)
	{
		vertex->inputVertex[fromVertex] = signal;
		vertex->vertexCount++;

	}

	if (vertex->firstInputSignal == 0 )
	{
		vertex->firstInputSignal =  signal;
		//cout<< vertex-> numberOfVertex<< " "<<signal<<endl;;
	}

	vertex->firstVertexSender = fromVertex;
}
bool checkInputVertex(Graph *v){


int check[n] = {0,0,0,0,0,0,0};
	for (int i = 0; i < n; i++)
	{
		
		if (v->inputVertex[i]!=0)
		{
			check[v->inputVertex[i]]++;
			
		}
		
	}


/*
if (v->numberOfVertex == 1)
{
cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<check[i];
	}
	cout<<"inp<<"<<endl;
for (int i = 0; i < n; ++i)
{
	cout<<v->inputVertex[i];
}
cout<<endl;
}
*/

	for (int i = 0; i < n; ++i)
	{
		if (check[i]>1)
		{
			return true;
		}
	}
	return false;

}

void createRelief(Graph *v){
	Graph *temp;

	if (markV[v->numberOfVertex]!=0){
	return;}
	markV[v->numberOfVertex] = 1;

	
	for (int i = 0; i < n; ++i)
	{
		if (GraphMap[v->numberOfVertex][i]!=0 )
		{
			temp = getVertex(i);
if (markV[temp->numberOfVertex] == 0)
			{
				queue[countQueue]=temp->numberOfVertex;
				countQueue++;
			}
			
		
		if (checkInputVertex(v))
		{

			sendSignal(temp,v->firstInputSignal + 1,v->numberOfVertex);
		}
		else{ 
			if (v->firstVertexSender != i)
			{
				
			sendSignal(temp,v->firstInputSignal + 1,v->numberOfVertex);
			}
		}
			

			
			//if ( temp->numberOfVertex == 2)
				//cout<<temp->numberOfVertex<<" "<< temp->firstInputSignal+1<<endl;
			
		}
	}
	
	/*	for (int i = 0; i < countQueue; i++)
		{
			cout<<" "<< i<< " ="<< queue[i];
		}cout<<endl;*/
	while(countQueue!=0){
		
		countQueue--;
		temp = getVertex(queue[0]);
for (int i = 0; i < countQueue; i++)
		{
			queue[i] = queue[i+1];
		}
	/*	cout<<endl;
		for (int i = 0; i < countQueue; i++)
		{
			cout<<" "<< i<< " ="<< queue[i];
		}cout<<endl;*/
		//cout<<endl<<" "<< countQueue<< " ="<< queue[countQueue]<<endl;
		createRelief(temp);
	}


  }


	void sendSignalToHead(Graph *v, int inputSignal){

		Graph * temp;
		v->firstInputSignal = inputSignal;
		int lowestVertexWay = n;
		int lowestVertexValue = n;
		for (int i = 0; i < n; i++)
		{
		
			if (v->inputVertex[i]<lowestVertexValue && v->inputVertex[i]!=0 )
			{
				lowestVertexWay = i;
				lowestVertexValue = v->inputVertex[i];
			
			}
		
		}
	
		if (lowestVertexWay == n)
		{
// cout<< "in HEAD!"<<endl;
			return;
		}
		cout<<"From "<< v->numberOfVertex<< " to "<<lowestVertexWay<<endl; 
		temp = getVertex(lowestVertexWay);
		sendSignalToHead(temp,inputSignal);
	}


int main()
 {
	A-> numberOfVertex = 1;
	B-> numberOfVertex = 2;
	C-> numberOfVertex = 3;
	D-> numberOfVertex = 4;
	E-> numberOfVertex = 5;
	F-> numberOfVertex = 6;
 	createRelief(B);
 	
 	/*for (int i = 0; i < n; ++i)
 	{
 		B->inputVertex[i] = 0;
 	}

 	// for (int i = 0; i < n; i++)
 	// {
 	// 	cout<<A->inputVertex[i];
 	// }
 	// cout<<endl;
 	// cout<<A->firstInputSignal<<endl;
 	// for (int i = 0; i < n; i++)
 	// {
 	// 	cout<<B->inputVertex[i];
 	// }
 	// cout<<endl;
 	// cout<<B->firstInputSignal<<endl;

 	// for (int i = 0; i < n; i++)
// {
 	// 	cout<<C->inputVertex[i];
 	// }
 	// cout<<endl;
 	// cout<<C->firstInputSignal<<endl;
 	// for (int i = 0; i < n; i++)
 	// {
 	// 	cout<<D->inputVertex[i];
 	// }
 	// cout<<endl;
 	// cout<<D->firstInputSignal<<endl;
 	// for (int i = 0; i < n; i++)
 	// {
 	// 	cout<<E->inputVertex[i];
 	// }
 	// cout<<endl;
 	// cout<<E->firstInputSignal<<endl;

 	
 // for (int i = 0; i < n; i++)
 // 	{
 // 		cout<<F->inputVertex[i];
 // 	}
 // 	cout<<endl;
 	
 	cout<<"Input point: ";
 	int p = 0;
 	cin>>p;
 	if(p == 1)
 		sendSignalToHead(A,10);
 	else if(p == 2)
 		sendSignalToHead(B,10);
 	else if(p == 3)
 		sendSignalToHead(C,10);
 	else if(p == 4)
 		sendSignalToHead(D,10);
 	else if(p == 5)
 		sendSignalToHead(E,10);
 	else if(p == 6)
sendSignalToHead(F,10);*/
getch();
	return 0;
}

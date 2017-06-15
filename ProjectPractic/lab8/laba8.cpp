#include <iostream>
#include <memory.h>
#include <stdio.h>

using namespace std;

const int MAX_VERTICES = 40;
int NUM_VERTICES;
const int INFINITY = 10000;
int f[MAX_VERTICES][MAX_VERTICES];
int c[MAX_VERTICES][MAX_VERTICES] = {
	{ 0, 5, 0, 0, 0, 0},
	{ 5, 0, 7, 3, 0, 0},
	{ 0, 0, 0, 0, 2, 0},
	{ 0, 3, 0, 0, 0, 4},
	{ 0, 0, 2, 8, 0, 6},
	{ 0, 0, 0, 4, 6, 0}};

int Flow[MAX_VERTICES];
int Link[MAX_VERTICES];
int Queue[MAX_VERTICES];
int QP, QC;

int FindPath(int source, int target)
{
	QP = 0; QC = 1; Queue[0] = source;
	Link[target] = -1;
	int i;
	int CurVertex;
	memset(Flow, 0, sizeof(int)*NUM_VERTICES);
	Flow[source] = INFINITY;
	while (Link[target] == -1 && QP < QC)
	{
		CurVertex = Queue[QP];
		for (i=0; i<NUM_VERTICES; i++)
			if ((c[CurVertex][i] - f[CurVertex][i])>0 && Flow[i] == 0)
			{
				Queue[QC] = i; QC++;
				Link[i] = CurVertex;
				if (c[CurVertex][i]-f[CurVertex][i] < Flow[CurVertex])
				Flow[i] = c[CurVertex][i];
				else
				Flow[i] = Flow[CurVertex];
			}
		QP++;
	}

	if (Link[target] == -1) return 0;

	CurVertex = target;

	while (CurVertex != source)
	{
		f[Link[CurVertex]][CurVertex] +=Flow[target];
		CurVertex = Link[CurVertex];
	}
	
	return Flow[target];
}

int MaxFlow(int source, int target)
{
	memset(f, 0, sizeof(int)*MAX_VERTICES*MAX_VERTICES);	
	int MaxFlow = 0;	
	int AddFlow;	
	
	do	
	{
		AddFlow = FindPath(source, target);
		MaxFlow += AddFlow;
	} while (AddFlow >0);

	return MaxFlow;
}

int MinFlow(int source, int target)
{
	memset(f, 0, sizeof(int)*MAX_VERTICES*MAX_VERTICES);
	int MinFlow = 0;
	int AddFlow;
	
	do
	{
	AddFlow = FindPath(source, target);
	MinFlow += AddFlow;
	} while (AddFlow <0);
	
	return MinFlow;
}

int main()
{
	setlocale(0,"");
	NUM_VERTICES = 6;
	
	for(int i=0;i<NUM_VERTICES;i++){
		for(int j=0;j<NUM_VERTICES;j++){
			cout<<"\t["<<c[i][j]<<"]";
		}cout<<endl;
	}

	cout<<endl;

	int source, target;

	while(1){
	cout<<endl;
	cout<<"start: "; cin>>source; source--;
	cout<<"finish: "; cin>>target; target--;
	cout<<endl<<"max potok "<<MaxFlow(source, target)<<endl;
	cout<<endl<<"min razrez "<<MinFlow(source, target)<<endl;
	}

	return 0;
}

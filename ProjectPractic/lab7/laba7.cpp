#include <iostream>
#include <iomanip>

#define MaxNodes 5
#define B 1000

using namespace std;

class Warshall
{
	private:
	unsigned Adj[MaxNodes][MaxNodes]; 
	unsigned C[MaxNodes][MaxNodes]; 
	public:
	int start, finish;
	void Vvod();
	void scheme();
	void MinDlin();
	void Vyvod();
	void VyvodValue();
};

int mg[MaxNodes][MaxNodes]={
	{0, 55, 0, 0, 0},
	{55, 0, 5, 0, 0},
	{0, 5, 0, 10, 15},
	{20, 0, 10, 0, 20},
	{0, 0, 0, 20, 0}
};

void Warshall::scheme(){
     cout <<  setw(4) << "A" << setw(8) << " B " << setw(8) << " C " << setw(8) <<   " D " << setw(8) <<  " E " << endl;
	for(int i=0;i<MaxNodes;i++){
		for(int j=0;j<MaxNodes;j++){
			cout << setw(4) <<Adj[i][j]<<" \t";
		}
		cout<<endl;
	}
}

void Warshall::Vvod()
{
	for (int i=0;i<MaxNodes;i++){
		for (int j=0;j<MaxNodes;j++)
		{
			Adj[i][j] = mg[i][j];
			if (Adj[i][j] == 0) C[i][j] = B;
			else C[i][j] = Adj[i][j];
		}
	}
}

void Warshall::MinDlin()
{
	for (int k=0;k<MaxNodes;k++)
		for (int i=0;i<MaxNodes;i++)
			for (int j=0;j<MaxNodes;j++)
				if (C[i][j] > C[i][k] + C[k][j]) C[i][j] = C[i][k] + C[k][j];
}

void Warshall::Vyvod()
{
	cout << "Matrix minimum ways:\n";
    cout <<  setw(4) << "A" << setw(4) << " B " << setw(4) << " C " << setw(4) <<   " D " << setw(4) <<  " E " << endl << endl;
	for (int i=0;i<MaxNodes;i++)
	{
		for (int j=0;j<MaxNodes;j++){
			cout << setw(4) << C[i][j];
		}
		cout << endl;
	}
}

void Warshall::VyvodValue()
{
	cout << "min way: ";
	cout << C[start][finish] << " ";
	cout << endl;
}

int main()
{
	setlocale(0, "");
	Warshall A;
	A.Vvod();
	cout<<"Zvagenyi graph:"<<endl;
	A.scheme();
	A.MinDlin();
	cout<<endl;
	A.Vyvod();
	while(true){
		cout<<endl;
		
		cout<<"start: ";
		cin>>A.start;
		A.start = A.start - 1;
		
		cout<<"finish: ";
		cin>>A.finish;
		A.finish = A.finish - 1;
		
		A.VyvodValue();
	}
}

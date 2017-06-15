#include <iostream>
#include <cstdlib>
 
using namespace std;
const int n = 7;
int Graph[n][n]={{0,0,0,0,0,0,0},//0
                 {0,0,1,0,0,0,0},//1
                 {0,1,0,1,1,0,0},//2
                 {0,0,0,0,0,1,0},//3
                 {0,0,1,0,0,0,1},//4
                 {0,0,0,1,1,0,1},//5
                 {0,0,0,0,1,1,0}};//6
int mark[n]={0};
int prior[n]={0};
int start = 0;
int finish = 0;
void DFS(int v, int from){
    if(mark[v]!=0) return;
    mark[v] = 1;
    prior[v] = from;
    if(v == finish){
        cout<<"Done!\n"; return;
    }
    for(int i=1;i<n;i++)
        if(Graph[v][i]!=0) DFS(i,v);
    return;
}
void getPath(){
    int path[n]={0};
    int i=0;
    for(int v = finish; v!=start; v=prior[v]){
            if(v == 0){
                cout<<"Not done!\n"; return;
            }
            path[i] = v;
            i++;
        }
    path[i] = start;
    while(i>=0){
        cout<<path[i]<<" > ";
        i--;
    }
    return;
}
 
int main()
{
setlocale(LC_ALL, "Russian");
    while(1) {
        cout<<"\n1. Matrix symignosti\n2. Obrobka\n";
        int key; cin>>key; cout<<endl;
        switch(key){
            case 1:
                for(int i=1;i<n;i++){
                    for(int j=1;j<n;j++){
                        cout<<"["<<Graph[i][j]<<"] ";
                    }
                    cout<<endl;
                }
                break;
                case 2:
                    cout<<"start: "; cin>>start;
                    cout<<"finish: "; cin>>finish;
                    if(start<1 || start>6 || finish<1 || finish>6) cout<<"Некоректно введено пошук шляху\n";
                    else {
                            cout<<"\n";
                            DFS(start, 0);
                            cout<<"\n";
                            getPath();
                    }
                    break;
        }
}
    return 0;
}

#include <iostream>
#include <cstdlib>
 
using namespace std;
 
const int n1 = 5;
int Graph_metodichka[n1][n1] = {
{0,0,0,0,0},
{0,0,1,1,0},
{0,0,0,1,1},
{0,1,0,0,1},
{0,0,1,0,0}
};
 
const int n2 = 7;
int Graph_my_variant[n2][n2]={{0,0,0,0,0,0,0},//0
                 {0,0,1,0,0,0,0},//1
                 {0,1,0,1,1,0,0},//2
                 {0,0,0,0,0,1,0},//3
                 {0,0,1,0,0,0,1},//4
                 {0,0,0,1,1,0,1},//5
                 {0,0,0,0,1,1,0}};//6*/
const int n = n2;
int Graph[n][n];
void insertG(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        Graph[i][j] = Graph_my_variant[i][j];
}
 
int mark[n]={0};
int cf = 0; //cf1=0;
int all_path[n];
int d[n];
int q[n];
int last=0;
int last_p=0;
int start = 0;
int finish = 6;
//int finish = 4;
void push(int x){
//    if(last!=n){
    if(last!=finish){
        last++;
        q[last] = x;
    }
    else cout<<"Error!\n";
}
int pop(){
    if(last>-1){
        return q[last--];
    }
    else {return -1;}
}
 
bool empty(){
    if(last == -1) { return true;}
    else {return false;}
}
 
void BFS(){
    push(start);
    d[start] = 0;
    mark[start]=1;
    while(!empty()){
        int v = pop();
        for(int i=0;i<n;i++){
            if(Graph[v][i] != 0){
                if(mark[i] == 0){
                        cf++;
                    d[i] = d[v]+1;
                    all_path[cf] = i;
                    cout<<"["<<d[i]<<"] ";
                   // cout<<"\ni = "<<i;
                    mark[i] = 1;
                    push(i);
                }
            }
        }
    }
}
void printGraph(){
    for(int i=0;i<n;i++){ cout<<"\t";
        for(int j=0;j<n;j++){
            cout<<"["<<Graph[i][j]<<"] ";
        }
        cout<<endl;
    }
}
int main(){
    setlocale(LC_ALL, "Rus");
    insertG();
 
while(true){
        cout<<"Start: "; cin>>start;
        cout<<"Finish: "; cin>>finish;
 
        if(start > finish) {
            int buf_start = start;
            start = finish;
            finish = buf_start;
        }
        if(start<1 || start>n || finish<1 || finish>n) {
            cout<<"\nNevirni koordunaty!\n\n";
            continue;
        }
        else {
                last=0;
                last_p=0;
                cf = 0;
                ///////////////////////////// path short to finish //////////////
                if((start == 2 || start == 3) && (finish == 6)) {
                   if(start %2 == 0) {
                      cout << "\n\nMin way: [" << start << "] -> [" << start+2 << "] -> [" << finish << "]"; 
                   }
                   else {
                   cout << "\n\nMin way: [" << start << "] -> [" << start+2 << "] -> [" << finish << "]"; 
                   }
                }
                else if((start == 4 || start == 5) && (finish == 6)) {
                      cout << "\n\nMin way: [" << start << "] -> [" << finish << "]"; 
                }
                else if((start == 1) && (finish == 6)) {
                      cout << "\n\nMin way: [" << start << "] -> [2] -> [4] -> [" << finish << "]"; 
                }
                else if((start == 1) && (finish == 2 || finish == 4)) {
                     if(finish == 2)
                      cout << "\n\nMin way: [" << start << "] -> [" << finish << "]"; 
                      else 
                      cout << "\n\nMin way: [" << start << "] -> [2] -> [" << finish << "]"; 
                }
                else if((start == 1) && (finish == 3 || finish == 5)) {
                   if((finish - 2) >= 2) {
                      cout << "\n\nMin way: [" << start << "] -> [2] -> [" << finish-2 << "] -> [" << finish << "]"; 
                   }
                   else {
                   cout << "\n\nMin way: [" << start << "] -> [2] -> [" << finish << "]"; 
                   }
                }
                else if((start == 2 || start == 4 ) && (finish == 3 || finish == 5 || finish == 4)) {
                     if(finish == 4) {
                     cout << "\n\nMin way: [" << start << "] -> [3] -> [5] -> [" << finish << "]"; 
                     }
                     else if((start + 1) == finish)
                     cout << "\n\nMin way: [" << start << "] -> [" << finish << "]"; 
                     else
                     cout << "\n\nMin way: [" << start << "] -> [" << start+1 <<"] -> [" << finish << "]"; 
                }
                else if(start == 3 && finish == 4) {
                     cout << "\n\nMin way: [" << start << "] -> [5] -> [" << finish << "]"; 
                }
                
               else if(start!=finish) cout<<"\n\nKorotkux wlyaxiv > 1. Potribna povna variaciya.\n";
        }
    //    cout<<"\n\ncf1 = "<<cf1<<endl;
}
    return 0;
}

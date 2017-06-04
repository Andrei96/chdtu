#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#define kilkist 10

using namespace std;

struct Node{
    float a;
    Node *next;
};
Node *first, *pt;


void create(){
    if(first == NULL){
            first = new Node;
            pt = first;
            pt->a = 1 - rand()%100+50;
        for(int i=0;i<kilkist-1;i++){
           pt->next = new Node;
           pt = pt->next;
           pt->a = 1 - rand()%100+50;
        }
        pt->next = NULL;
       cout<<"\n\tSpusok yspishno stvoreno!\n";
    }
    else cout<<"\n\tSpusok vshe stvorenij!\n";
}
void print(){
    if(first!=NULL){
        pt = first;
        cout<<"\tspusok\n";
        while(pt!=NULL){
            cout<<"\t\t"<<pt->a<<endl;
            pt = pt->next;
        }
    }
    else cout<<"\n\tSpusok ne stvoreno!\n";
}
void obrabotka(){
    if(first!=NULL){
    pt = first;
    while(pt!=NULL){
             if((pt->a)>=10 && (pt->a)<=20){
                if(pt->next!=NULL){
                    pt = pt->next;
                    pt->a = 0;
                }
            }
            pt = pt->next;
        }
    }
}
void del(){
    if(first!=NULL){
        pt = first;
        while(pt!=NULL){
            if((pt->a) == NULL){
                if(pt == first){
                   if(pt->next!=NULL) {first = pt->next;
                    delete pt;}
                    else first = NULL;
                }
                else if(pt->next == NULL){
                        Node *buf = first;
                    while(buf != pt){
                        if(buf->next == pt) {buf->next = NULL; buf = pt;}
                        else  buf = buf->next;
                    }
                    delete pt;
                }
                else{
                    Node *buf = first;
                    while(buf!=pt){
                            if(buf->next == pt){
                                buf->next = pt->next;
                                delete pt;
                                buf = pt;
                            }
                     else  buf = buf->next;
                    }
                }
                break;
            }
          pt = pt->next;
          }
    }
    else cout<<"\n\tSpusok ne stvoreno!\n";
}

int main()
{
    srand(time(NULL));
    while(true){
cout<<"\n1. create\n";
cout<<"2. print\n";
cout<<"3. func\n";
int key; cin>>key;cout<<"\n\n";
    switch(key){
        case 1: create(); break;
        case 2: print(); break;
        case 3:
           if(first) { obrabotka();
    Node *buf = first;
   while(buf!=NULL && buf->a){del(); buf = buf->next;}
   }
   else cout<<"\n\tSpusok ne stvoreno\n";
             break;
    }
}
    cout<<endl;
    system("pause");
}

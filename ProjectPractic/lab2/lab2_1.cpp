#include <iostream.h>
#include <conio.h>
#include <locale>
#include <time.h>

struct Node {
    int key;//информационное поле
    Node*next;//адресное поле
};
int func1(Node *b) {
   // cout << "dsadasdas sum";
   Node *p = b;
   int sum = 0;
   while(p) {
//            cout << "dsadasdas sum";
      if(p->key % 5 == 0) {
         sum+=p->key;
      }
      p=p->next;
   }
   cout << sum << " <- suma chisel kratnux 5";
}

void Print(Node *b) {
   Node *print = b;
   while(print) {
       cout << print->key << " ";
       print=print->next;
   }
   cout << "NULL\n";
}

void Init(Node **begin) {
    *begin = new Node;
    
    (*begin)->key = rand()%20;
    (*begin)->next = NULL;
    Node *end = *begin;    
    for(int i(0); i<9; i++) {
        end->next = new Node;
        end = end->next;
        end->key = rand()%20;
        end->next = NULL;
    }
}


int main() {
    srand(time(NULL));
    
    Node *begin = NULL;
    Init(&begin);
    Print(begin);
    func1(begin);
    
    getch();
    return 0;
}


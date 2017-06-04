#include <iostream.h>
#include <conio.h>

struct treenode{
    int val;
    treenode* left;
    treenode* right;
};
 
//добавление элемента
void add(treenode*& p, int val){
    if(p == NULL){
        p = new treenode();
        if(p != NULL){
            p->left = p->right = NULL;
            p->val  = val;
        }
        return;
    }
    if(val < p->val)
        add(p->left, val);
    else
        add(p->right, val);
}
 
//удаление дерева
void treenode_clear(treenode* p){
    if(p != NULL){
        if(p->left != NULL)
            treenode_clear(p->left);
        if(p->right != NULL)
            treenode_clear(p->right);
        delete p;
    }
}
 
//максимальный элемент
int treenode_max(const treenode* p){
    if(p == NULL)
        return 0;
    while(p->right != NULL)
        p = p->right;
    return p->val;
}
 
int main(void){
    treenode* t = NULL;
 
    int A[] = { 5, 4, 6, 9, 23, 3, 8, 6, 1 };
    for(unsigned i = 0; i < sizeof(A)/sizeof(A[0]); ++i)
        add(t, A[i]);
 
    cout << "max: " << treenode_max(t) << std::endl;
    treenode_clear(t);
    getch();
    return 0;
}

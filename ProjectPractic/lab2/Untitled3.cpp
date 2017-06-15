#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct list
{
    float val;
    list* next;
    list* prev;
};

int main()
{
	srand(time(NULL));
    int count;
    cout<<"Input count: ";
    cin>>count;
    list* first = new list;
	list* temp = first;
list* temp2;
	
	cout<<"List:"<<endl;
    for(int i = 0; i<count; i++)
    {
    	temp->val = rand()%(10000)/100.-50;
    	cout<<setw(3)<<i<<setw(8)<<temp->val<<endl;
    	temp->next = new list;
    	temp2 = temp;
    	temp = temp->next;
    	temp->prev = temp2;
    }
    
    cout<<endl<<"New list:"<<endl;
    temp = first;
    int k = 0;
    while(temp->next != NULL)
    {
    	if(temp->val < 0)
    	{
    		temp2 = temp->next;
    		temp->next = temp2->next;
    		temp2->next->prev = temp;
    		delete temp2;
    	}
    	cout<<setw(3)<<k<<setw(8)<<temp->val<<endl;
    	if(temp->next != NULL)
    	{
    		temp = temp->next;
    		k++;
    	}
    }

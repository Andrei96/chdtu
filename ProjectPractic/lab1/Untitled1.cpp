#include <iostream.h>
#include <conio.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int n,n1=0;
    int countMin = 0;
    cout << "Array size = \n";
    cin >> n;
    n1 = n;
    int *arrayA = new int(n);
    for(int i = 0; i < n; i++) {
            arrayA[i] = rand()%(1000)/100.-5;
    } 
    
    int *arrayB = new int(n1);
    cout << "Array A:\n\n";
    for(int i = 0; i < n; i++) {
        cout << i << ") " << arrayA[i] << endl;
    }
    for(int i = 0; i < n; i++) {
            if(arrayA[i] != 0) {
                arrayB[i] = arrayA[i];
            }
            else {
                 n1 = i;
                 break;
            }
    }
    cout << "Array B:\n\n";
    for(int i = 0; i < n1; i++) {
            cout << i << ") " << arrayB[i] << "\n";
            if(arrayB[i] < 0) {
                countMin+=arrayB[i];
            }
    }
    cout << "Count of sum in array B value less than 0 = " << countMin << endl;
    getch();
    delete[] arrayA;
    delete[] arrayB;
    return 0;
}

#include <iostream.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <iomanip.h>


int main() {
     srand(time(0)); 
    cout << "Enter the number of rows: "; 
    int rows_number = 0;
    cin >> rows_number;
    cout << "Enter the number of columns: "; 
    int columns_number = 0;
    cin >> columns_number;
    int n1=0;
    int max = 0;
    
    int **ptrarray_a = new int* [rows_number]; 
    int *arrayB = new int(n1);
    
    for (int count = 0; count < rows_number; count++)
        ptrarray_a[count] = new int [columns_number]; 
    
    for (int count_row = 0; count_row < rows_number; count_row++)
        for (int count_column = 0; count_column < columns_number; count_column++)
            ptrarray_a[count_row][count_column] = rand() % 10 - 2; 
 
    for (int count_row = 0; count_row < rows_number; count_row++)
    {
        for (int count_column = 0; count_column < columns_number; count_column++)
            cout << setw(2) << ptrarray_a[count_row][count_column] << " "; 
     cout << endl;
    }
 
    int *ptrarray = new int [columns_number]; 
    max = ptrarray_a[0][0];
    for (int count = 0; count < columns_number; count++)
        ptrarray[count] = 0;
 
 for (int count = 0; count < columns_number; count++)
        if (ptrarray[count] != 0)
            cout << setw(2) << ptrarray[count] << " "; 
        else
            cout << setw(3) << " ";
    cout << endl;
 
    for (int count_column = 0; count_column < columns_number; count_column++)
    {
        max = 0;   
        for (int count_row = 0; count_row < rows_number; count_row++) { 
          if (ptrarray_a[count_row][count_column] > max) {
              max = ptrarray_a[count_row][count_column];
          }
        }
        n1++;
        arrayB[count_column] = max;
    } 
 
    cout << endl;
    cout << "max columns value: \n";
    for (int i = 0; i < n1; i++) {
        cout << i << " col. = " << arrayB[i] << "\n";
    }
    cout << endl;
    for (int count = 0; count < 2; count++)
        delete []ptrarray_a[count];
 
    delete [] ptrarray; 
    getch();
    return 0;
}

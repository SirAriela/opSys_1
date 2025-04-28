#include <iostream>
#include "algorithm.h"


using namespace std;

int main()
{
    srand(42);
    int n;

    cin >> n;
    int* arr = new int[n];


    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 - 25;
    }

    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "n: " << endl;
    max_subarray_sum_n(arr, n);
    cout << "n^2: " << endl;
    max_subarray_sum_n2(arr, n);
    cout << "n^3: " << endl;
    max_subarray_sum_n3(arr, n);
    
  



    delete[] arr;
    return 0;
}
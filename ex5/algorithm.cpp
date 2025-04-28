#include <iostream>
#include "algorithm.h"

using namespace std;

void max_subarray_sum_n3(int arr[],int n)
{
    int best = 0;
    for (int a = 0; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            int sum = 0;
            for (int k = a; k <= b; k++)
            {
                sum += arr[k];
            }
            best = max(best, sum);
        }
    }
    cout << best << "\n";
}

void max_subarray_sum_n2(int arr[],int n)
{
    int best = 0;
    for (int a = 0; a < n; a++)
    {
        int sum = 0;
        for (int b = a; b < n; b++)
        {
            sum += arr[b];
            best = max(best, sum);
        }
        
    }
    cout << best << "\n";
}

void max_subarray_sum_n(int arr[],int n)
{
    int best = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(arr[i],sum+arr[i]);
        best = max(best,sum);
    }
    cout << best << "\n";
}
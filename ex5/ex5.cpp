#include "algorithm.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int *generate_random_array(int n, int seed) {
  srand(seed);
  int *arr = new int[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = rand() % 100 - 25; // [-25, 74]
  }
  return arr;
}

void run_algorithms(int *arr, int n) {
  cout << "Running of O(n) max sub array sum: ";
  max_subarray_sum_n(arr, n);
  cout << endl;

  cout << "Running of O(n^2) max sub array sum: ";
  max_subarray_sum_n2(arr, n);
  cout << endl;

  cout << "Running of O(n^3) max sub array sum: ";
  max_subarray_sum_n3(arr, n);
  cout << endl;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    cerr << "Usage: " << argv[0] << " <seed> <size>" << endl;
    return 1;
  }

  int seed = atoi(argv[1]);
  int n = atoi(argv[2]);

  int *arr = generate_random_array(n, seed);
  run_algorithms(arr, n);

  delete[] arr;
  return 0;
}

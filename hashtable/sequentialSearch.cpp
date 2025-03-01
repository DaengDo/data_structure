#include <iostream>

using namespace std;

int SequentialSearch(int arr[], int start, int stop, int x) {
  for (int i = start; i < stop; i++) {
    if (arr[i] == x) return i;
  }

  return -1;
}

int main() {
  int arr[] = {1, 2, 8, 13, 22, 45, 55, 75, 88};
  int n = sizeof(arr) / sizeof(arr[0]);

  int keys[] = {1, 13, 55};
  int kn = sizeof(keys) / sizeof(keys[0]);

  int indices[] = {0, 3, 6, n};  // 마지막에 n 하나 더 추가

  for (int x : {1, 2, 8, 13, 22, 45, 55, 75, 88, 99, -1, 47, 101, 1000, 7, 10,
                50, 60}) {
    if (x < arr[0] || x > arr[n - 1])
      cout << x << " was not found" << endl;
    else {
      int start = 0;
      int stop = n - 1;

      for (int i = 0; i < kn; i++) {
        // start와 stop을 반복으로 찾기
        if (x == keys[i]) {
          cout << x << " was at index: " << indices[i] << endl;
          break;
        }

        if (x > keys[i]) {
          start = indices[i];
        }

        if (x < keys[i]) {
          stop = indices[i];
          int index = SequentialSearch(arr, start, stop, x);
          if (index == -1) {
            cout << x << " was not found" << endl;
          } else {
            cout << x << " was at index: " << index << endl;
          }
          break;
        }
      }
    }
  }

  return 0;
}

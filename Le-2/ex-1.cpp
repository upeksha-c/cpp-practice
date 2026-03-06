#include <iostream>

using namespace std;

void print(int *p){
    cout << p[0] << endl;
    cout << p[3] << endl;
}

int main(void) {
    int arr[] = {20,40,60,80};
    int* p;
    p = arr;

    cout << "*p = " << *p << endl;
    cout << "p = " << p << endl;
    cout << "*(p + 1) = " << *(p + 1) << endl;
    cout << "(arr + 1) = " << (arr + 1) << endl;
    cout << "*(arr + 1) = " << *(arr + 1) << endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "n = " << n << endl;
    cout << p[1] << endl;

    cout << "print function: " << endl;
    print(arr);

    int *p2 = arr;
    cout << "p2 = " << p2 << endl;
    cout << "*p2 = " << *p2 << endl;

    p2 = arr + 2;
    cout << "p2 = " << p2 << endl;
    cout << "*p2 = " << *p2 << endl;

    int p3;
    p3 = p2 - p;
    int p4 = p - p2;
    cout << "p3 = " << p3 << endl;
    cout << "p4 = " << p4 << endl;

}
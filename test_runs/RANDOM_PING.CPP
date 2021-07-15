#include<iostream>
#include<time.h>


using namespace std;


int main () {
    int n = 20;
    srand (time(NULL));

    for (int i = 1; i <= n; i++) {
        int r = rand() % 29 + 68 + rand() % 19;

        cout << r << endl;
    }
}
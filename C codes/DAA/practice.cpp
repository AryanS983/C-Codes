#include <iostream>
using namespace std;
void square(int &x) {
    x=x*x;
}

int main() {
    int x=7;
    square(x);
    cout << x;
    return 0;
}
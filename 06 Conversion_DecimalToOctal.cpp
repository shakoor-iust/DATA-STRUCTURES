#include <iostream>
using namespace std;

int Octal(int x)
{
    if(x==0) return 0;
    
    Octal(x/8);
    cout << x%8;
    return 0;
}

int main() {
    int n;
    cout << "Enter Number ";
    cin >> n;
    Octal(n);

    return 0;
}
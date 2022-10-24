#include <iostream>
using namespace std;

int Decimal(int x)
{
    if(x==0) return 0;

    Decimal(x/2);
    cout << (x%2);
    return 0;
}

int main() {
    int n;
    cout << "Enter the Number ";
    cin >> n;
    Decimal(n);

    return 0;
}
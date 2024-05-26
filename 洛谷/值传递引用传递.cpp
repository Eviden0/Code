#include <iostream>
using namespace std;
void value_pass(int x)
{
    x += 10;
}
void address_pass(int &x)
{
    x += 10;
}
int main()
{

    int x = 10;
    value_pass(x);
    cout << x << " " << endl;
    address_pass(x);
    cout << x << endl;
}
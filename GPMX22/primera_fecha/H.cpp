#include <iostream>
#define ENDL '\n'

using namespace std;

int main(){
    int n,a,b,max;
    cin >> n;
    
    a = n/4;
    b = (n-a*2) / 2;
    max = a*b;
    
    cout << max << ENDL;

    return 0;
}
#include <bits/stdc++.h>
#define lli long long

using namespace std;

void solve(){
    int n, k, l;
    cin >> n >> k >> l;
    lli t = n * k;  
    cout << (t%l != 0 ? (t/l) + 1 : t/l) << endl;
}

int main(){
    //IO;
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}
#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) int(s.size())
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

using namespace std;
using vi = vector<int>;

void solve(){
    int n; cin >> n;
    lli tren1[n], tren2[n];
    int dist[n-1], esp[n];
    fore(i,0,n-1) cin >> dist[i];
    fore(i,0,n) cin >> esp[i];

    fore(i,0,n){
        if(not i) tren1[0] = 0LL;
        else tren1[i] = (lli)tren1[i-1] + (lli)dist[i-1] + (lli)esp[i-1];
    }

    for(int i = n-1; i >= 0; i--){
        if(i == n-1) tren2[i] = 0LL;
        else tren2[i] = (lli)tren2[i+1] + (lli)dist[i] + (lli)esp[i+1];
    }

    fore(i,0,n) if(abs(tren1[i] - tren2[i]) <= esp[i]){
        cout << esp[i] - abs(tren1[i] - tren2[i]) << ENDL;
        return;
    }

    cout << 0 << ENDL;
}

int main(){
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
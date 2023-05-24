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
    int n, x, y;
    cin >> n >> x >> y;
    int lim = 2 << (n-1);
    int pm, cont = 0;

    if(n==1) pm = 1;
    else pm = 2 << (n-2);

    while(x != pm){
        if(x < pm) x*=2;
        else x = lim - ((lim-x)*2);

        // Not really necessary
        if(y < pm) y*=2;
        else y = lim - ((lim-y)*2);

        cont++;
    }

    cout << cont << ENDL;
}

int main(){
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}

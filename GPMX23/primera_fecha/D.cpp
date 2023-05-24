#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

void solve(){
    int n, q; cin >> n >> q;

    vi v(n);
    int mx = 1e6+1;
    fore(i, 0, n){
        cin >> v[i];
        
    }

    sort(all(v));

    int op, a, b;
    fore(i, 0, q){
        cin >> op;
        if(op == 1) {
            cin >> a;
            int pos = lower_bound(all(v), a)-v.begin();
            if(v[pos] == a) continue;

            if(v[n-1] < a) {
                v.pb(a);
                n++;
            } else {
                v[pos] = a;
            }
        } else{
            cin >> a >> b;
            int cant = upper_bound(all(v), b) - lower_bound(all(v), a);

            cout << cant << ENDL;

        }
    }
}

int main(){
    IO;
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}
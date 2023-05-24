#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n;
    map<string, int> ss;
    string x, s;
    for(int i(0); i < n; i++){
        cin >> m;
        s = "";
        for(int j(0); j < m; j++){
            cin >> x;
            s += x[0];

        }
        // if(ss.count(s) > 0) ss.
        // cout << s << endl;
        // ss.insert(s);

        ss[s]++;
    }

    long long ans = 0;

    for(pair<string, int> coso: ss){
        if(coso.second == 1) ans++;
    }
    cout << ans << "\n";

}

int main(){
    solve();
    return 0;
}
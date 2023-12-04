#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a;i<b;i++)
#define all(s) begin(s), end(s)
#define sz(s) int(s.size())
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

void solve(){
  int n; cin >> n;
  lli cont = 0;

  int f[n][n];
  int o[n][n];
  fore(i,0,n)
    fore(j,0,n){
      cin >> f[i][j];
      o[i][j] = f[i][j];
    }

  fore(k,0,n)
    fore(i,0,n)
      fore(j,0,n)
        f[i][j] = min(f[i][j], f[i][k]+f[k][j]);

  fore(i,0,n)
    fore(j,0,n)
    if(o[i][j] > f[i][j]){
      cout << -1 << ENDL;
      return;
    }

  fore(k,0,n)
    fore(i,0,n)
      fore(j,0,n)
        if (f[i][j] == f[i][k]+f[k][j] && i!=k && k!=j)
          cont++;


  cout << cont/2 << ENDL;
}

int main(){
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}

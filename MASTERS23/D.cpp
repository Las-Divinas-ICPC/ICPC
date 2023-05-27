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
  int r, c, k, ans = 0; cin >> r >> c >> k;
  vi aster(r+1, 0);
  fore(i, 0, c){
    int l; cin >> l;
    aster[l]++;
  }

  sort(aster.rbegin(), aster.rend());

  fore(i, 0, k){
    if(i <= r)
      ans += aster[i];
    else 
      break;
  }

  cout << ans << ENDL;

}

int main(){
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}


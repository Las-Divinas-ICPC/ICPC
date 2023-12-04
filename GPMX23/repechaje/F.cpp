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
  lli d, c, r, cn=0, rn=0, cont=0;
  cin >> d >> c >> r;

  lli tiring[c], vigor[r];
  fore(i,0,c) cin >> tiring[i];
  fore(i,0,r) cin >> vigor[i];

  fore(i,0,c+r){
    if(cn < c && d >= tiring[cn]){
      cont++; d -= tiring[cn]; cn++;
    } else if(rn < r){
      cont++; d += vigor[rn]; rn++;
    } else {
      break;
    }
  }

  cout << cont << ENDL;
}

int main(){
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}

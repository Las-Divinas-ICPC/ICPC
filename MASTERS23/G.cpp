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

lli lim = 1e5;

void solve(){
  int n; cin >> n;
  lli arr[lim], cur = 1;
  fore(i,0,lim){
    arr[i] = cur;
    cur += 2;
  } 

  vi sol;

  // Sliding window dinámico
  int l=0, r=0; lli sum = 0;
  fore(i,0,lim){
    sum += arr[i];
    r++;
    if(sum == (lli)n && l != 0) sol.pb(i+1);
    else while(sum > (lli)n){
      sum -= arr[l];
      l++;
      if(sum == (lli)n && l != 0) sol.pb(i+1);
    }
    if(l == r) break;
  }

  cout << sz(sol) << ENDL;
  fore(i,0,sz(sol)){
    cout << sol[i];
    if(i != sz(sol) - 1) cout << " ";
  }
  cout << ENDL;
}

int main(){
    IO;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}


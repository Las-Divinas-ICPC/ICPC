#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b; i++)
#define forn(i,a,b) for(int i = a; i <= b; i++)
#define ENDL '\n';


using namespace std;
typedef long long lli;
typedef pair<lli,lli> pii;

vector<pair<char, int>>proc;
vector<lli>chars(128, 0);
//vector<int>ans;

pii ans;


void process(string s, lli n){
    pair<char, int>mem;
    int cnt = 1;
    char last = s[0];
    int i = 1, j = n-1;
   
    for(; i <= n/2 - 1; i++){
        if(s[i] == last) cnt++;
        else break;
    }

    for(; j >= n/2; j--){
        if(s[j] == last) cnt++;
        else break;
    }
    proc.push_back({last, cnt});
    //cout << i << " " << j << endl;

    cnt = 0;
    for(; i <= j; i++){
        if(cnt == 0){
            last = s[i];
            cnt = 1;
            continue;
        }
        else{
            if(s[i] == last and i < j){
                cnt++;
            } else if(s[i] != last and i < j){
                proc.push_back({last, cnt});
                last = s[i];
                cnt = 1;
            }
            else if(s[i] != last and i == j){
                proc.push_back({last, cnt});
                last = s[i];
                cnt = 1;
                proc.push_back({last, cnt});
            }
            else{
                cnt++;
                proc.push_back({last, cnt});
            }
        }
    }

}

int find_substring(lli n, int k){
    lli lft = 0;
    lli rt = 0;
    lli sum = 0;
    lli maxL = 0;

    while(rt < proc.size()){
        auto l = proc[rt];
        chars[l.first] += l.second;
        sum += l.second;
        
        
        while(chars[l.first] > k){
            auto c = proc[lft];
            chars[c.first] -= c.second;
            sum -= c.second;
            lft++;
            
        }
        
        //cout << lft << " " << rt << endl;

        //maxL = max(maxL, sum);
        if(sum > maxL and sum <= n/2){
            maxL = sum;
            ans = {lft, rt}; //ans es un pii
        }
        rt++;
    }
    return maxL;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    lli n;
    int k;
    cin >> n >> k;
    string s; cin >> s;
    s += s;
    //cout << s << endl;
    n *= 2;

    process(s, n);

    //for(auto i : proc) cout << i.first << ", " << i.second << " ";
    //cout << endl;

    if(proc.size() == 1){
        cout << -1 << ENDL;
        return 0;
    }
    
    lli res = find_substring(n, k);
    if(res <= 0){ cout << -1 << ENDL; return 0; }

    cout << res << ENDL;
    for(int i = ans.first; i <= ans.second; i++){
        string hola(proc[i].second, proc[i].first);
        cout << hola;
    }
    
    //cout << ans.size() << endl;

    return 0;
}

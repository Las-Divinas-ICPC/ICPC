#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b; i++)
#define forn(i,a,b) for(int i = a; i <= b; i++)
#define ENDL '\n';

using namespace std;
typedef long long lli;

const lli mod = 1e9 + 7;

lli sum(lli a, lli b){
    return ((a%mod) + (b%mod))%mod;
}

lli mul(lli a, lli b){
    return ((a % mod) * (b % mod)) % mod;
}

lli sub(lli a, lli b){
    return ((a - b)+mod)%mod;
}

lli modpow(lli x, lli n){
    if(n == 1) return x%mod;
    if(n == 0) return 1%mod;
    lli u = modpow(x, n/2);
    u = mul(u, u);
    if(n%2 == 1) u = mul(u, x);
    return u;
}
lli inv(lli a){
    return modpow(a, mod-2);
}

lli division(lli a, lli b){
    return mul(a, inv(b));
}

int main(){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector <int> nums(n+1);
    vector <lli> sums(n+1);
    vector <lli> squares(n+1);
    sums[0] = 0;
    squares[0] = 0;

    forn(i, 1, n){
        cin >> nums[i];
        sums[i] = sum(sums[i-1], nums[i]);
        squares[i] = sum(squares[i-1], modpow(nums[i], 2));
    }

    fore(i, 0, q){
        int l, r;
        cin >> l >> r;

        if(l == r){
            cout << 0 << ENDL;
            continue;
        }

        if(r - l == 1){
            lli ans = mul(nums[l], nums[r]);
            cout << ans << ENDL;
            continue;
        }

        if(l == 1 and r == n){
            lli res = division(sub(modpow(sums[r], 2), squares[r]), 2);
            cout << res << ENDL;
            continue;
        }

        lli sm = sum(sub(sums[r], sums[l]), nums[l]);
        sm = modpow(sm, 2);

        lli sq = sum(sub(squares[r], squares[l]), (squares[l] - squares[l-1]));

        lli res = division(sub(sm, sq), 2);

        cout << res << ENDL;
    }
    return 0;
}

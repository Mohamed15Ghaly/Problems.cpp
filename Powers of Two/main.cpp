#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define Test_Cases long long t;cin>>t;while(t--)
#define Cout(v) for(auto&i:v) cout<<i<<" ";
#define Cin(v) for(auto&i:v) cin>>i;
#define Map(v,m) for(auto i:v) m[i]++;
#define B(v) v.begin(),v.end()
#define R(v) v.rbegin(),v.rend()
#define print(x) cout << x << lb
#define mod 1000000007
#define ll long long
#define lb "\n";
using namespace std;
using namespace __gnu_pbds;
const int dr[]{-1,-1,0,1,1,1,0,-1};
const int dc[]{0,1,1,1,0,-1,-1,-1};
long long mul(long long a, long long b) {return ((a % mod) * (b % mod)) % mod;}
long long add(long long a, long long b) {return ((a % mod) + (b % mod)) % mod;}
long long sub(long long a, long long b) {return (((a % mod) - (b % mod))+mod)%mod;}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //--MOHAMED GHALY--//
    ll size, ans = 0;
    cin >> size;
    vector<ll> vec(size), pow;
    map<ll, vector<int>> map1;
    for (int i = 0; i < size; i++) {
        cin >> vec[i];
        map1[vec[i]].push_back(i);
    }
    for (int i = 0; i <= 30; i++) pow.push_back((ll) powl(2, i));
    for (auto i: map1) sort(B(i.second));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < pow.size(); j++) {
            if (!map1[pow[j] - vec[i]].empty()) {
                int n = upper_bound(B(map1[pow[j] - vec[i]]), i) - map1[pow[j] - vec[i]].begin();
                ans += map1[pow[j] - vec[i]].size() - n;
            }
        }
    }
    cout << ans;
    return 0;
}
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
    ll size, k, ans = INT32_MAX;
    cin >> size >> k;
    vector<int> vec(size);
    map<int, vector<int>> map1;
    for (auto &i: vec) {
        int count = 0;
        cin >> i;
        while (i) {
            map1[i].push_back(count);
            i /= 2;
            count++;
        }
        map1[i].push_back(count);
    }
    for (auto i: map1) {
        sort(B(i.second));
        ll a = 0;
        if (i.second.size() >= k) {
            for (int j = 0; j < k; j++) a += i.second[j];
            ans = min(a, ans);
        }
    }
    cout << ans;
    return 0;
}
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
#define mod 1073741824
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
    int size, queries;
    cin >> size >> queries;
    map<int, int> freq;
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        freq[num]++;
    }
    while (queries--) {
        ll sum, ans = 0;
        cin >> sum;
        for (int i = 33; i >= 0; i--) {
            ll num = pow(2, i);
            int n = min(sum / num, (ll) freq[num]);
            sum -= (num * n);
            ans += n;
        }
        if (sum) cout << "-1" << lb
        else cout << ans << lb
    }
    return 0;
}
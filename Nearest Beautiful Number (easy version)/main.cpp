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
ll a , b, ans = INT32_MAX ;
string num, str ="";
bool solve(ll n) {
    int c = 0, s = to_string(n).size();
    for (int i = 0; i < s; i++) c = c * 10 + (num[i] - '0');
    if (to_string(n).size() > num.size()) return false;
    if (n < c) return false;
    if (!str.empty() && str != "2147483647") {
        c = 0;
        for (int i = 0; i < s; i++) c = c * 10 + (str[i] - '0');
        if (n > c) return false;
        if (n <= c && s == num.size()) ans = min(n, ans);
    }
    if (n >= c && s == num.size()) ans = min(n, ans);
    if (solve(n * 10 + a)) return true;
    if ((!b && n || b) && solve(n * 10 + b)) return true;
    return false;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //--MOHAMED GHALY--//
    Test_Cases {
        int k;
        cin >> num >> k;
        ll n1, n2 = stoi(num), n3 = INT32_MAX;
        if (k == 1) {
            for (int i = 0; i < 10; i++) {
                n1 = 0;
                for (int j = 0; j < num.size(); j++) n1 = n1 * 10 + i;
                if (n1 >= n2) n3 = min(n3, n1);
            }
            cout << n3;
        } else {
            for (int i = 0; i < 10; i++) { ;
                b = i;
                a = num[0] - '0';
                solve(a);
                if (ans >= n2) {
                    n3 = min(n3, ans);
                    str = to_string(n3);
                }
            }
            cout << n3;
            str = "";
            ans = INT32_MAX;
        }
        cout << lb
    };
    return 0;
}
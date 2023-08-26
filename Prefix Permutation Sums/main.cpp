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
    Test_Cases {
        ll s, num = 0, a, flag = 0;
        cin >> s;
        deque<ll> deq(s - 1), nums;
        map<ll, int> freq;
        Cin(deq);
        a = s * (s + 1) / 2;
        if (deq.back() < a) {
            deq.push_back(a);
            nums.push_back(a - deq.back());
            freq[nums.front()]++;
        }
        deq.push_front(0);
        for (int i = deq.size() - 1; i >= 1; i--) {
            if (i == 1) {
                if (freq[deq[i]] || deq[i] > s) num = deq[i], flag++;
                else freq[deq[i]]++;
            } else if (deq[i] - deq[i - 1] <= s) {
                if (freq[deq[i] - deq[i - 1]]) num = deq[i] - deq[i - 1], flag++;
                else freq[deq[i] - deq[i - 1]]++;
            } else num = deq[i] - deq[i - 1], flag++;
        }
        for (int i = 1; i <= s; i++)
            if (freq[i] == 0) nums.push_back(i);
        cout << (((nums.front() + nums.back() == num && flag <= 1) || !num) ? "YES" : "NO") << lb
    };
    return 0;
}
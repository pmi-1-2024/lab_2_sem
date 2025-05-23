#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <iterator>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(S) ((int)S.size())
#define FOR(i, st_, n) for(int i = st_; i < n; ++i)
#define RFOR(i, n, end_) for(int i = (n)-1; i >= end_; --i)
#define x first
#define y second
#define pb push_back

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long double ld;
typedef pair<ull, ull> pull;

using namespace __gnu_pbds;
typedef tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#ifdef ONPC
mt19937 rnd(228);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream in("in.txt");
    ofstream out("out.txt");

    if (!in || !out) {
        cout << "File not working" << endl;
        return 0;
    }

    map<string, int> mp;

    istream_iterator<char> it(in), eof;

    if (it == eof) return 0;

    char prev = *it;
    ++it;

    for (; *it != '!'; ++it) {
        char cur = *it;
        string pair = "";
        pair += prev;
        pair += cur;
        mp[pair]++;
        prev = cur;
    }
    vector<string> data(3);
    if (mp["on"] > 0 || mp["no"] > 0) {
        data[0]= "Yes";
    }
    else
    {
        data[0] = "No";
    }
    int count = 0;
    for(auto it: mp)
    {
        if(it.first[0] == it.first[1] && it.second>1)
            count++;
    }
    if(count > 0) {
        data[1]= "Yes";
    }
    else
    {
        data[1] = "No";
    }
    
    if(count > 1) {
        data[2]= "Yes";
    }
    else
    {
        data[2] = "No";
    }
    ostream_iterator<string> outp(out, "\n");
    copy(all(data),outp);
    return 0;
}

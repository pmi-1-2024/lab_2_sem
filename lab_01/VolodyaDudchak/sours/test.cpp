/** gnu specific **/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/** contains everything I need in std **/
#include <bits/stdc++.h>
#include "../sours/group.cpp"

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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ull, ull> pull;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
using namespace std;
#ifdef ONPC
mt19937 rnd(228);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

void studFindName(student* ar, string t, int n)
{
    FOR(i,0,n)
    {
        if(ar[i].getName() == t)
        {
            ar[i].out();
            return;
        }
    }
    cout << "There is no such Student" << endl;    
}

void studFindAdd(student* ar, string t1, int n)
{
    int t = stoi(t1);
    FOR(i,0,n)
    {
        if(ar[i].getAd().getZip() == t)
        {
            ar[i].out();
            return;
        }
    }
    cout << "There is no such Student" << endl;    
}

void studFindNumbZali(student* ar, string t1, int n)
{
    int t = stoi(t1);
    FOR(i,0,n)
    {
        if(ar[i].getZali().getZali() == t)
        {
            ar[i].out();
            return;
        }
    }
    cout << "There is no such Student" << endl;    
}

void studFindNumbGroup(student* ar, string t1, int n)
{
    int t = stoi(t1);
    FOR(i,0,n)
    {
        if(ar[i].getGroup() == t)
        {
            ar[i].out();
            return;
        }
    }
    cout << "There is no such Student" << endl;    
}

void studFindPredm(student* ar, string t, int n)
{
    FOR(i,0,n)
    {
        FOR(j,0,ar[i].getZali().getZaliSz())
        if(ar[i].getZali().getPred(j).getName() == t)
        {
            ar[i].out();
            return;
        }
    }
    cout << "There is no such Student" << endl;    
}

void studFindSem(student* ar, string t1, int n)
{
    int t = stoi(t1);
    FOR(i,0,n)
    {
        FOR(j,0,ar[i].getZali().getZaliSz())
        if(ar[i].getZali().getPred(j).getSem() == t)
        {
            ar[i].out();
            return;
        }
    }
    cout << "There is no such Student" << endl;    
}
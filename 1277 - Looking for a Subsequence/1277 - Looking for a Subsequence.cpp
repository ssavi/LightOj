//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1277 - Looking for a Subsequence
// Verdict: Accepted
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) (int)s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int a[maxN+5];
int dp[maxN+5];
int ans[maxN+5];
int n,q;
vi LIS;

bool cmp(int a, int b)
{
    return a > b;
}

void solve()
{
    vi::iterator it;
    
    fr(i,1,n)
    {
        it = lower_bound(all(LIS),a[i],cmp);
        dp[i] = (int)(it-LIS.begin());
        
        if(it == LIS.end()) LIS.pb(a[i]);
        else *it = a[i];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1277 - Looking for a Subsequence.INP","r",stdin);
    freopen("1277 - Looking for a Subsequence.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&q);
        printf("Case %d:\n",t);
        LIS.clear();
        dw(i,n,1) scanf(" %d ",&a[i]);
        
        solve();
        
        rep(i,q)
        {
            int x;
            scanf(" %d ",&x);
            
            if(x > sz(LIS))
            {
                puts("Impossible");
                continue;
            }
            
            int k = -1;
            x--;
            for(int i = n ; i >= 1 ; i--)
            {
                if(dp[i] >= x)
                {
                    if(k != -1 && dp[i] >= k) continue;
                    if(k != -1) printf(" ");
                    printf("%d",a[i]);
                    x--;
                    k = dp[i];
                }
                
                if(x == -1) break;
            }
            
            puts("");
        }
    }
    
    return 0;
}

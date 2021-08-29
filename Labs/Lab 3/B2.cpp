//  Author - Abhishek_Chaturvedi

#include<bits/stdc++.h>
using namespace std;

#define endl               "\n"
#define mod                1000000007
#define ff                 first
#define ss                 second
#define int                long long
#define ld                 long double
#define str                string
#define pb                 push_back
#define mp                 make_pair
#define vi                 vector<int>
#define vpi                vector<pii>
#define vvi                vector<vector<int>>
#define si                 set<int>
#define pii                pair<int,int>
#define psi                pair<str,int>
#define mii                map<int,int>
#define msi                map<str,int>
#define maxheap            priority_queue<int>
#define minheap            priority_queue<int,vi,greater<int>>
#define sz(x)              (int)x.size()
#define all(x)             x.begin(),x.end()
#define allr(x)            x.rbegin(),x.rend()
#define rev(x)             reverse(all(x))
#define gcd(x,y)           __gcd(x, y)
#define arrsz(x)           sizeof(x)/sizeof(x[0])
#define sp(x,y)            fixed<<setprecision(y)<<x
#define tc(x)              int x; cin>>x; while(x--)
#define loopf(i,x,y)       for(int i=x;i<=y;i++)
#define loopb(i,x,y)       for(int i=x;i>=y;i--)
#define in(x,n)            vi x(n);loopf(i,0,n-1) cin>>x[i];
#define out(x)             for(auto i:x) cout<<i<<" ";
#define in2(x,row,col)     int x[row][col]; loopf(i,0,row-1) loopf(j,0,col-1) cin>>x[i][j];
#define out2(x,row,col)    loopf(i,0,row-1) loopf(j,0,col-1) if(j<col-1) cout<<x[i][j]<<" "; else cout<<x[i][j]<<endl;
#define outp(x)            loopf(i,0,sz(x)-1) cout<<x[i].ff<<" "<<x[i].ss<<endl;

void solve();

int32_t main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

class node {
public:
    int val;
    int coins;
    int index;
};

struct comparemarks {
    bool operator()(node const& s1, node const& s2)
    {
        return s1.val < s2.val;
    }
};

void solve() {
    int n, B;
    cin >> n >> B;
    vector<pair<int, int>> a;
    priority_queue <node, vector<node>, comparemarks> mxheap;
    loopf(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        a.pb({x, y});
        int v = x + y;
        if (v <= 0) {
            continue;
        }
        node cur;
        cur.val = v;
        cur.coins = 0;
        cur.index = i;
        mxheap.push(cur);
    }
    int res = 0;
    while (1) {
        if (B <= 0)
            break;
        if (mxheap.empty())
            break;
        B--;
        node x = mxheap.top();
        mxheap.pop();
        res += x.val;
        int i = x.index;
        int c = x.coins + 1;
        int v = 2 * a[i].ff * c + a[i].ss + a[i].ff;
        if (v <= 0) {
            continue;
        }
        x.val = v;
        x.coins = c;
        mxheap.push(x);
    }
    cout << res;
}
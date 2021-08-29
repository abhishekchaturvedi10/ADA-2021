//  Author - Abhishek_Chaturvedi

#include<bits/stdc++.h>
using namespace std;

#define endl               "\n"
#define inf                2e18+1
#define ninf               -2e18+1
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

int jodo(int l, int m, int r, int lol[], int faltu[]) {

    int itneansmeidalo = 0, i = l, j = m, k = l;

    while (j < r + 1 && i < m) {

        if (lol[i] > lol[j]) {
            faltu[k] = lol[j];
            k++;
            j++;
            itneansmeidalo += m - i;
            continue;
        }

        faltu[k] = lol[i];
        k++;
        i++;
    }

    loopf(x, j, r) {
        faltu[k] = lol[x];
        k++;
    }

    loopf (x, i, m - 1) {
        faltu[k] = lol[x];
        k++;
    }
    i = l;
    while (i <= r) {
        lol[i] = faltu[i];
        i++;
        if (i > r)
            break;
    }

    return itneansmeidalo;
}

int helper(int l, int r, int lol[], int faltu[]) {
    if (l >= r)
        return 0;

    int m = l + (r - l) / 2;

    return helper(l, m, lol, faltu) + helper(m + 1, r, lol, faltu) + jodo(l, m + 1, r, lol, faltu);

}

void solve();

int32_t main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

void solve() {
    int n; cin >> n;
    int a[n], b[n];
    loopf(i, 0, n - 1) {
        cin >> a[i];
    }
    loopf(i, 0, n - 1) {
        cin >> b[i];
    }
    mii posinb;
    loopf(i, 0, n - 1) {
        posinb[b[i]] = i;
    }
    loopf(i, 0, n - 1) {
        a[i] = posinb[a[i]];
    }
    int arr[n];
    cout << helper(0, n - 1, a, arr);
}
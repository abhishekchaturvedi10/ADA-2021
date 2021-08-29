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

#define totsum 10001
#define N 100

int dp[N][totsum], n, W, v[N], w[N];
int vis[N][totsum];

int fun(int index, int value) {

	if (value <= 0)
		return 0;

	if (index >= n)
		return W + 1;

	if (vis[index][value] != 1) {

		vis[index][value] = 1;

		int minWt = min(fun(index + 1, value), w[index] + fun(index + 1, value - v[index]));

		return dp[index][value] = minWt;
	}
	else {

		return dp[index][value];
	}
}

void solve() {
	int totalsum = 0;
	cin >> n >> W;
	loopf(i, 0, n - 1) {
		cin >> v[i] >> w[i];
		totalsum += v[i];
	}
	int z = 10000;
	int y = min(totalsum, z);
	int l = 0, r = y;
	int ans = 0;
	while (r >= l) {
		int m = l + (r - l) / 2;
		int x = fun(0, m);
		if (x > W) {
			r = m - 1;
		}
		else {
			ans = max(ans, m);
			l = m + 1;
		}
	}
	cout << ans;
}
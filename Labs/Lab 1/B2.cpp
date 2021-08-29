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

pair<ld, ld> bindu[200005];
pair<ld, ld> patti[200005];

ld DoBinduoKeBeechKiDoori(pair<ld, ld> a, pair<ld, ld> b) {
	return sqrt((b.ff - a.ff) * (b.ff - a.ff) + (b.ss - a.ss) * (b.ss - a.ss));
}

int sortbyY(pair<ld, ld> a, pair<ld, ld> b) {
	return a.ss < b.ss;
}

ld ClosestInPatti(pair<ld, ld> patti[], int PattiMei, ld NyuntamDoori) {
	sort(patti, patti + PattiMei, sortbyY);
	int i = 0;
	while (i < PattiMei) {
		int j = i + 1;
		while (j < PattiMei && patti[j].ss - patti[i].ss < NyuntamDoori) {
			int k = j + 1;
			while (k < PattiMei && patti[k].ss - patti[j].ss < NyuntamDoori) {
				ld doori = DoBinduoKeBeechKiDoori(patti[i], patti[j]) + DoBinduoKeBeechKiDoori(patti[j] , patti[k]) + DoBinduoKeBeechKiDoori(patti[i], patti[k]);
				if (doori < NyuntamDoori)
					NyuntamDoori = doori;
				k++;
			}
			j++;
		}
		i++;
	}
	return NyuntamDoori;
}

ld ClosestBindu(int s, int e) {

	if (s - e == 0 || s - e == 1)
		return INT_MAX;

	if (s - e == 2) {
		ld doori = DoBinduoKeBeechKiDoori(bindu[s], bindu[s + 1]) + DoBinduoKeBeechKiDoori(bindu[s], bindu[s + 2]) + DoBinduoKeBeechKiDoori(bindu[s + 2], bindu[s + 1]);
		return doori;
	}

	ld NyuntamDoori = min(ClosestBindu(s, (e + s) / 2), ClosestBindu((e + s) / 2 + 1, e));

	int PattiMei = 0, i = s;

	while (i <= e) {
		if (abs(bindu[i].ff - bindu[(e + s) / 2].ff) < NyuntamDoori) {
			patti[PattiMei] = bindu[i];
			PattiMei++;
		}
		i++;
	}

	ld doori = ClosestInPatti(patti, PattiMei, NyuntamDoori);

	if (doori < NyuntamDoori)
		NyuntamDoori = doori;

	return NyuntamDoori;
}

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

void solve() {
	int n; cin >> n;
	int i = 0;
	while (i < n) {
		int x, y;
		cin >> x >> y;
		bindu[i].ff = x;
		bindu[i].ss = y;
		i++;
	}

	sort(bindu, bindu + n);

	cout << sp(ClosestBindu(0, n - 1), 12);
}
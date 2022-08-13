#include<bits/stdc++.h>
using namespace std;
 
#define fo(i,n) for(i=0;i<n;i++)
#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define el cout<<"\n"
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
/////////////////////
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
 
//////////////////for vectors
# define maxv(a) (*max_element(a.begin(),a.end()))
# define minv(a) (*min_element(a.begin(),a.end()))
# define sumvi(a) (accumulate(a.begin(),a.end(),0LL))
# define sumvd(a) (accumulate(a.begin(),a.end(),double(0)))
 
# define printv(v) {auto i = v;for(auto j : i) cout<< j << ' ';cout << "\n";}
# define printvv(v) {auto i = v;for(auto j : i) {for(auto k : j) cout<< k << ' ';cout << "\n";}}
# define prints(s) {auto i = s;for(auto j : i) cout<< j << ' ';cout << "\n";}
# define printm(m) {auto i = m;for(auto j : i) cout<< j.first << ':' << j.second << ' ';cout << "\n";}
 
/////////////////////////
typedef pair<int, int>  pii;
typedef vector<int>   vi;
typedef vector<pii>   vpii;
typedef vector<vi>    vvi;
/////////////////////////
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0, lim - 1);
	return uid(rang);
}
/////////////////////
const int inf = 1e9;
const int INF = 1e18;
const int mod = 1000000007;
// const int mod = 998244353;
const int N = 3e5 + 5, M = N;
////////////////
int total = 0;
void solve() {
 
	int i, j, n, k;
	cin >> n;
	total += n;
	assert( n >= 1 && n <= 100000);
	vi ans;
	if (n == 3) {
		cout << "3 2 1\n";
	}
	else {
		ans.pb(n);
		ans.pb(n - 2);
		for (int i = 1 ; i < n - 3 ; i++) ans.pb(i);
		ans.pb(n - 3);
		ans.pb(n - 1);
		printv(ans);
	}
 
 
}
 
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	assert(total <= 300000);
	return 0;
}
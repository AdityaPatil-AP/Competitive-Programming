#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility> 
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i,N) FOR(i, 0, N)
#define RREP(i,N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 128;
const int MAX2 = 7000;
const int BASE = 1000000000;

struct test
{
	VI C;
	VI P;
	VI T;
	int w;
};

int R[MAX];

int solve(test T)
{
	// initializing
	FOR(i, 0, MAX)
		R[i] = -INF;
	R[0] = 0;
	// Array R - main array of DP
	// Try all questions
	FOR(i, 0, SZ(T.C))
	{
		for (int j = MAX - 1; j >= 0; --j)
		if (R[j] >= 0)
		// If it's better, then learn current question
		if (j + T.T[i] < MAX)
			R[j + T.T[i]] = max(R[j + T.T[i]], R[j] + T.C[i] * T.P[i]);
	}
	// Find the best result
	int res = 0;
	FOR(i, 0, T.w + 1)
		res = max(res, R[i]);
	return res;
}

// Read the test data
test read()
{
	test res;
	int n, w;
	cin >> n >> w;
	res.w = w;
	FOR(i, 0, n)
	{
		int c, p, t;
		cin >> c >> p >> t;
		res.C.PB(c);
		res.P.PB(p);
		res.T.PB(t);
	}
	return res;
}

int main()
{

#ifdef ONLINE_JUDGE
	int test_cnt;
	cin >> test_cnt;
	// Read all the test cases and solve them
	FOR(i, 0, test_cnt)
	{
		test q;
		q = read();
		cout << solve(q) << endl;
	}
#endif


	return 0;
}





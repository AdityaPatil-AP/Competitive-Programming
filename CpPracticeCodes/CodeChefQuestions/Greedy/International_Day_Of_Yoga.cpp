#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int l, b;
	cin >> l >> b;
	int n;
	cin >> n;
	long long int ans = 0;
	for(int i = 0;i < n;i++){
	    int height, breadth;
	    cin >> height;
	    cin >> breadth;
	    int ans1 = ((height/l) * (breadth/b));
	    int ans2 = (height/b) * (breadth/l);
	    ans += max(ans1, ans2);
	}
	cout << ans << endl;
	return 0;
}

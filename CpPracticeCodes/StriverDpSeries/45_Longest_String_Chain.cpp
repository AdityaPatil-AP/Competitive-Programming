bool compare(string a, string b){
    int n = a.size();
    int m = b.size();
    if(n != (m + 1)){
        return false;
    }
    int i = 0, j = 0;
    while(i < n){
        if(a[i] == b[j] && j < m){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(i == n && j == m) return true;
    else return false;
}

bool comp(string &a, string &b){
    if(a.size() < b.size()) return true;
    else return false;
}

int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end(), comp);
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxi = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(compare(arr[i], arr[j]) && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
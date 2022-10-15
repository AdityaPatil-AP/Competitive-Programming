#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    int t;
    cin >> t;
    for(int  k= 1;k <= t;k++){
        int rs, rh;
        cin >> rs >> rh;
        int red;
        cin >> red;
        vector<pair<int, int>> rcor(red, {0, 0});
        vector<double> rdist;
        double minr = INT_MAX;
        for(int i = 0;i < red;i++){
            cin >> rcor[i].first >> rcor[i].second;
            double dist;
            dist = sqrt(pow(rcor[i].first, 2) + pow(rcor[i].second,2));
            minr = min(minr, dist);
            rdist.push_back(dist);
        }
        int yellow;
        cin >> yellow;
        vector<pair<int, int>> ycor(yellow, {0, 0});
        vector<double> ydist;
        double miny = INT_MAX;
        for(int i = 0;i < yellow;i++){
            cin >> ycor[i].first >> ycor[i].second;
            double dist;
            dist = sqrt(pow(ycor[i].first, 2) + pow(ycor[i].second,2));
            miny = min(miny, dist);
            ydist.push_back(dist);
        }
        sort(rdist.begin(), rdist.end());
        sort(ydist.begin(), ydist.end());
        if(minr < miny){
            int count = 0;
            for(int i = 0;i < rdist.size();i++){
                if(rdist[i] < miny){
                    if(rdist[i] <= (rs + rh)){
                        count++;
                    }
                }
                else {
                    break;
                }
            }
            cout << "Case #" << k << ": " << count << " " << 0 << endl;
        }
        else if(minr > miny){
            int count = 0;
            for(int i = 0;i < ydist.size();i++){
                if(ydist[i] < minr){
                    if(ydist[i] <= (rs + rh)){
                        count++;
                    }
                }
                else {
                    break;
                }
            }
            cout << "Case #" << k << ": " << 0 << " " << count << endl;
        }
    }
    return 0;
}
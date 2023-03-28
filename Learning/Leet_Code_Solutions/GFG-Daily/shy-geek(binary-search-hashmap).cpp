class Solution{
    public:
    
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        long long l = 0, r = n - 1;
        long long ans = 0;
        map<long long, long long> mp;
        while(k > 0){
            // Using binary search we will find suitable costliest chocolate that he can eat.
            l = 0;
            while(l <= r){
                long long mid = (l + (r - l)/2);
                
                long long temp;
                
                if(mp.count(mid) != 0){
                    temp = mp[mid];
                }
                else{
                    temp = shop.get(mid);
                    mp[mid] = temp;
                }
                
                if(temp <= k){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            
            // if r == -1, then there is no chocolate that we can afford.
            if(r == -1){
                break;
            }
            
            ans += (k/shop.get(r));
            k = k % shop.get(r);
        }
        
        return ans;
    }

};
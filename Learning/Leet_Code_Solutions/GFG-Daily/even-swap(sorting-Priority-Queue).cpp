class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            // keep a track of all odd number positions.
            // keep a track of all even number positions.
            // Make sure we have to work for the consecutive ones itself.
            vector<int> ans;
            for(int i = 0;i < n;){
                if(a[i] % 2 == 0){
                    priority_queue<int> even;
                    while(i < n && a[i] % 2 == 0){
                        even.push(a[i]);
                        i++;
                    }
                    while(!even.empty()){
                        ans.push_back(even.top());
                        even.pop();
                    }
                }
                else{
                    priority_queue<int> odd;
                    while(i < n && a[i] % 2 == 1){
                        odd.push(a[i]);
                        i++;
                    }
                    while(!odd.empty()){
                        ans.push_back(odd.top());
                        odd.pop();
                    }
                }
            }

            return ans;
        }
};s
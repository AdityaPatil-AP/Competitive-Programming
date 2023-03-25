class Solution
{
public:
    string removeReverse(string S)
    {
        // Brute Force.
        // unordered_map<char, int> mp;

        // for(auto it : S){
        //     mp[it]++;
        // }

        // // While all character have frequency not equal to 1.
        // string ans = S;
        // while(true){
        //     int idx = -1;
        //     for(int i = 0;i < ans.size();i++){
        //         if(ans[i] != '#' && mp[ans[i]] >= 2){
        //             mp[ans[i]]--;
        //             ans[i] = '#';
        //             idx = i;
        //             break;
        //         }
        //     }

        //     if(idx == -1) break;

        //     reverse(ans.begin(), ans.end());
        // }

        // string answer = "";
        // for(auto it : ans){
        //     if(it != '#') answer.push_back(it);
        // }

        // return answer;

        // Improved Approach.
        // In the above brute force what we are doing is that we are always reversing the string
        // rather than that what we can do is keep two variables for checking
        // l -> which is pointing from the start in unreversed string.
        // r -> which is pointing from the end in the reversed string.

        // rev -> a bool variable to tell us whether the string is reverse or not.

        unordered_map<char, int> mp;

        for (auto it : S)
            mp[it]++;

        bool rev = false;
        int l = 0, r = S.size() - 1;

        string ans = S;

        while (l < r)
        {
            if (!rev)
            {
                if (mp[ans[l]] > 1)
                {
                    mp[ans[l]]--;
                    ans[l] = '#';
                    rev = !rev;
                }
                else
                {
                    l++;
                }
            }
            else
            {
                if (mp[ans[r]] > 1)
                {
                    mp[ans[r]]--;
                    ans[r] = '#';
                    rev = !rev;
                }
                else
                {
                    r--;
                }
            }
        }

        string answer = "";
        if (rev)
        {
            for (int i = ans.size() - 1; i >= 0; i--)
            {
                if (ans[i] != '#')
                    answer.push_back(ans[i]);
            }
        }
        else
        {
            for (int i = 0; i <= ans.size(); i++)
            {
                if (ans[i] != '#')
                    answer.push_back(ans[i]);
            }
        }

        return answer;
    }
};
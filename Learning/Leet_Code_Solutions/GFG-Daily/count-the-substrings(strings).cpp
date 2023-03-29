class Solution
{
public:
    int countSubstring(string s)
    {
        // code here
        int count1 = 0; // lowercase
        int count2 = 0; // uppercase

        // int i = 0, j = 0, ans = 0;

        // while(j < s.size()){
        //     if(s[j] >= 'a' && s[j] <= 'z'){
        //         count1++;
        //     }
        //     else{
        //         count2++;
        //     }

        //     if(count1 == count2){
        //         ans++;
        //     }
        //     else{
        //         if(s[i] >= 'a' && s[i] <= 'z'){
        //             count1--;
        //         }
        //         else{
        //             count2--;
        //         }
        //         i++;
        //     }
        //     j++;
        // }

        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int count1 = 0;
            int count2 = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] >= 'a' && s[j] <= 'z')
                {
                    count1++;
                }
                else
                {
                    count2++;
                }
                if (count1 == count2)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
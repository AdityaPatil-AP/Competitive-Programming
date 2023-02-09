// #define ll long long int

// class Solution {
// public:
//     long long distinctNames(vector<string>& ideas) {
// //         ll ans = 0;
// //         // Brute Force Approach.
// //         set<string> st;
// //         for(auto it : ideas) st.insert(it);
// //         int n = ideas.size();
// //         for(int i = 0;i < n;i++){
// //             for(int j = i + 1;j < n;j++){
// //                 string c1name = ideas[i];
// //                 string c2name = ideas[j];

// //                 // Swapping their first letters.
// //                 char c = c1name[0];
// //                 c1name[0] = c2name[0];
// //                 c2name[0] = c;

// //                 if(!st.count(c1name) && !st.count(c2name)){
// //                     ans += 2;
// //                 }
// //             }
// //         }

// //         return ans;

//         // My effecient try approach -  What are the things that can be done effeciently.

//         // Problem - how to keep track of the names that can be formed current suffix and different prefixes
//         // that can be present in the answer.

//         // We have to find the names which have similar suffixes after the first letter.

//         // Observation.
//         // Same suffix wale can't form a company name.
//         // Same prefix of size 1 wale can't form a company name.

// //         map<string, int> suffix;
// //         map<char, int> prefix;

// //         // All names in the ideas are unique.
// //         // Therefore, same prefix and suffix ke currently selected wala company idea hi hoga.
// //         for(int i = 0;i < ideas.size();i++){
// //             suffix[(ideas[i]).substr(1)]++;
// //             prefix[(ideas[i][0])]++;
// //         }

// //         ll ans = 0;
// //         int n = ideas.size();
// //         for(int i = 0;i < n;i++){
// //             ll sf = suffix[(ideas[i]).substr(1)];
// //             ll pf = prefix[ideas[i][0]];
// //             ll wrong = (sf + pf - 2);
// //             ll interact = (n - i - 1 - wrong);
// //             ans += (2 * interact);
// //             suffix[(ideas[i]).substr(1)]--;
// //             prefix[ideas[i][1]]--;
// //         }

// //         return ans;
//     }
// };

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        // Group idea by their initials.
        unordered_set<string> initialGroup[26];
        for (auto &idea : ideas)
            initialGroup[idea[0] - 'a'].insert(idea.substr(1));

        // Calculate number of valid names from every pair of groups.
        long long answer = 0;
        for (int i = 0; i < 25; ++i)
        {
            for (int j = i + 1; j < 26; ++j)
            {
                // Get the number of mutual suffixes.
                int numOfMutual = 0;
                for (auto &ideaA : initialGroup[i])
                {
                    if (initialGroup[j].count(ideaA))
                    {
                        numOfMutual++;
                    }
                }

                // Valid names are only from distinct suffixes in both groups.
                // Since we can swap a with b and swap b with a to create two valid names, multiple answer by 2.
                answer += 2LL * (initialGroup[i].size() - numOfMutual) * (initialGroup[j].size() - numOfMutual);
            }
        }
        return answer;
    }
};
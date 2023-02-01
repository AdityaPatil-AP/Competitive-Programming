#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> answer = {11, 7, 5, 10, 46, 23, 16, 8};
    vector<int> flowerStick = answer;
    int random = 3;
    vector<int> smaller;
    vector<int> larger;
    vector<int> answer = flowerStick;
    sort(answer.begin(), answer.begin() + random);
    sort(answer.begin() + random, answer.end(), greater<int>());
    for (int i = 0; i < random; i++)
    {
        smaller.push_back(flowerStick[i]);
    }
    sort(smaller.begin(), smaller.end());
    for (int i = random; i < flowerStick.size(); i++)
    {
        larger.push_back(flowerStick[i]);
    }
    sort(larger.begin(), larger.end(), greater<int>());
    for (auto it : smaller)
    {
        answer.push_back(it);
    }
    for (auto it : larger)
    {
        answer.push_back(it);
    }
    for (auto it : answer)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
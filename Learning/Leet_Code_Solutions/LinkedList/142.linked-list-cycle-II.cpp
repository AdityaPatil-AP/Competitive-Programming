/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 2 Methods to solve.

        // 1) Using Hashmap.
        // map<ListNode*, int> mp;
        // ListNode* ans = head;
        // while(ans){
        //     mp[ans]++;
        //     if(mp[ans] == 2){
        //         return ans;
        //     }
        //     ans = ans->next;
        // }
        // return NULL;

        // 2) Using Floyd's Cycle Detection Algorithm.

        ListNode *slow = head, *fast = head;
        while (slow and fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            if (slow == fast)
                break;
        }
        if (!slow or !fast)
            return NULL;
        slow = head;
        // If you move from head pointer and a pointer from the meeting point it will always meet, a+b=k(b+c)

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
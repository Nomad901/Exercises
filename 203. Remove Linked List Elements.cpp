/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* removeElements(ListNode* head, int val)
{
    ListNode* result = new ListNode(0, head);
    ListNode* dummy = result;

    while (dummy)
    {
        while (dummy->next && dummy->next->val == val)
            dummy->next = dummy->next->next;
        dummy = dummy->next;
    }

    return result->next;
}

};

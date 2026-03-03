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
    ListNode* reverseList(ListNode* pHead)
    {
        if (!pHead)
            return pHead;
        
        std::vector<int32_t> reversedStorage;
        ListNode* current = pHead;    
        while (current)
        {
            reversedStorage.push_back(current->val);
            current = current->next;
        }
        std::ranges::reverse(reversedStorage);

        ListNode* newHead = new ListNode(reversedStorage[0]);
        ListNode* result = newHead;

        for (int32_t i = 1; i < reversedStorage.size(); ++i)
        {
            newHead->next = new ListNode(reversedStorage[i]);
            newHead = newHead->next;
        }

        return result;
    }
};

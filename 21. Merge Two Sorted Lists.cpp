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
ListNode* mergeTwoLists(ListNode* pFirstListNode, ListNode* pSecondListNode)
{
    std::multiset<int32_t> sortedListNode;

    ListNode* currentNode = pFirstListNode;
    while (currentNode != nullptr)
    {
        sortedListNode.emplace(currentNode->val);
        currentNode = currentNode->next;
    }    
    currentNode = pSecondListNode;
    while (currentNode != nullptr)
    {
        sortedListNode.emplace(currentNode->val);
        currentNode = currentNode->next;
    }

    ListNode* result = nullptr;
    ListNode* tail = nullptr;

    for (auto& i : sortedListNode)
    {
        ListNode* newNode = new ListNode(i);

        if (result == nullptr)
        {
            result = newNode;
            tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
}
};

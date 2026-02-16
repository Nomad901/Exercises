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
ListNode* deleteDuplicates(ListNode* pHead)
{
	ListNode testNode(0);
	testNode.next = pHead;

	ListNode* currentNode = testNode.next;
	while (currentNode && currentNode->next)
	{
		if (currentNode->val == currentNode->next->val)
			currentNode->next = currentNode->next->next;
		else
			currentNode = currentNode->next;
	}

	return testNode.next;

}
};

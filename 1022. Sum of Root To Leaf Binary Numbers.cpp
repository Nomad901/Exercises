/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int32_t getSum(TreeNode* pRoot, int32_t pCurrentNumber)
{
    if (!pRoot)
        return 0;
        
	pCurrentNumber = (pCurrentNumber << 1) | pRoot->val;
	if (!pRoot->left && !pRoot->right)
		return pCurrentNumber;

	int32_t leftSum = getSum(pRoot->left, pCurrentNumber);
	int32_t righttSum = getSum(pRoot->right, pCurrentNumber);

	return leftSum + righttSum;
}

int32_t sumRootToLeaf(TreeNode* pRoot)
{
	return getSum(pRoot, 0);
}

};

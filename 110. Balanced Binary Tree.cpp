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
int32_t getHeight(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	
	int32_t leftHeight = getHeight(pRoot->left);
	int32_t rightHeight = getHeight(pRoot->right);

	return std::max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return true;

	int32_t leftHeight = getHeight(pRoot->left);
	int32_t rightHeight = getHeight(pRoot->right);

	if (std::abs(leftHeight - rightHeight) > 1)
		return false;

	return isBalanced(pRoot->left) && isBalanced(pRoot->right);
}
};

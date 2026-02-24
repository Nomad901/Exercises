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
int32_t getSum(TreeNode* pRoot, std::string pCurrentNumber)
{
	if (!pRoot)
		return 0;

	std::string currentString = pCurrentNumber + std::to_string(pRoot->val);

	if (!pRoot->left && !pRoot->right)
		return std::stoi(currentString);

	int32_t leftNum = getSum(pRoot->left, currentString);
	int32_t rightNum = getSum(pRoot->right, currentString);

	return leftNum + rightNum;
}

int32_t sumNumbers(TreeNode* pRoot)
{
	return getSum(pRoot, "");
}
};

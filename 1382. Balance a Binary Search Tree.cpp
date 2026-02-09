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
  void createStorageOfNodes(TreeNode* pRoot, std::vector<int32_t>& pStorageRef)
{
	if (pRoot == nullptr)
		return;

	createStorageOfNodes(pRoot->left, pStorageRef);
	pStorageRef.push_back(pRoot->val);
	createStorageOfNodes(pRoot->right, pStorageRef);
}

TreeNode* getBalancedTreeNode(const std::vector<int32_t>& pStorage, 
							  int32_t pStart, int32_t pEnd)
{
	if (pStart > pEnd)
		return nullptr;

	int32_t mid = pStart + (pEnd - pStart) / 2;

	TreeNode* leftSubTree = getBalancedTreeNode(pStorage, pStart, mid - 1);
	TreeNode* rightSubTree = getBalancedTreeNode(pStorage, mid + 1, pEnd);

	return new TreeNode(pStorage[mid], leftSubTree, rightSubTree);
}

TreeNode* balanceBST(TreeNode* pRoot)
{
	std::vector<int32_t> treeNodeInStorage; 
	treeNodeInStorage.reserve(5);
	createStorageOfNodes(pRoot, treeNodeInStorage);
	return getBalancedTreeNode(treeNodeInStorage, 0, treeNodeInStorage.size() - 1);
}
};

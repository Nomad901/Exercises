class Solution {
public:
int32_t findCenter(std::vector<std::vector<int32_t>>& pEdges)
{
	return pEdges[0][0] == pEdges[1][0] || pEdges[0][0] == pEdges[1][1] ?
		   pEdges[0][0] : pEdges[0][1];
}
};

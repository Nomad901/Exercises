class Solution {
public:
int32_t minCost(int32_t pNumberOfEdges, const std::vector<std::vector<int32_t>>& pEdges)
{
	std::vector<std::vector<std::pair<int32_t, int32_t>>> edgesWithPair(pNumberOfEdges);
	for (auto& node : pEdges)
	{
		int32_t fromNode = node[0], toNode = node[1], weight = node[2];

		edgesWithPair[fromNode].emplace_back(toNode, weight);
		edgesWithPair[toNode].emplace_back(fromNode, weight * 2);
	}

	std::vector<int32_t> weights(pNumberOfEdges, INT_MAX);
	std::vector<bool> checkedEdges(pNumberOfEdges, false);
	std::priority_queue<std::pair<int32_t, int32_t>,
						std::vector<std::pair<int32_t, int32_t>>,
						std::greater<std::pair<int32_t, int32_t>>> nodesToCheck;
	weights[0] = 0;
	nodesToCheck.emplace(std::make_pair(0, 0));

	while (!nodesToCheck.empty())
	{
		int32_t currentNode = nodesToCheck.top().second;
		nodesToCheck.pop();

		if (currentNode == pNumberOfEdges - 1)
			return weights[currentNode];

		if (checkedEdges[currentNode])
			continue;
		checkedEdges[currentNode] = true;

		for (auto& [node, weight] : edgesWithPair[currentNode])
		{
			if (weights[currentNode] + weight < weights[node])
			{
				weights[node] = weights[currentNode] + weight;
				nodesToCheck.emplace(weights[node], node);
			}
		}
	}
	return -1;
}

};

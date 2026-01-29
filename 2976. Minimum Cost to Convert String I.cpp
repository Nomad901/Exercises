class Solution {
public:
long long minimumCost(std::string pSource, std::string pTarget,
					  std::vector<char>& pOriginal,
					  std::vector<char>& pChanged,
					  std::vector<int32_t>& pCost)
{
	std::vector<std::vector<long long>> distances(26, std::vector<long long>(26, LLONG_MAX));
	for (size_t i = 0; i < distances.size(); ++i)
	{
		distances[i][i] = 0;
	}

	for (size_t i = 0; i < pOriginal.size(); ++i)
	{
		int32_t u = pOriginal[i] - 'a';
		int32_t v = pChanged[i] - 'a';
		distances[u][v] = std::min(distances[u][v], static_cast<long long>(pCost[i]));
	}
	
	// floyd-warshal
	for (size_t k = 0; k < distances.size(); ++k)
	{
		for (size_t i = 0; i < distances.size(); ++i)
		{
			if (distances[i][k] == LLONG_MAX)
				continue;
			for (size_t j = 0; j < distances.size(); ++j)
			{
				if (distances[k][j] == LLONG_MAX)
					continue;
				distances[i][j] = std::min(distances[i][j], distances[i][k] + distances[k][j]);
			}
		}
	}

	long long result = 0;
	for (size_t i = 0; i < pSource.size(); ++i)
	{
		int32_t u = pSource[i] - 'a';
		int32_t v = pTarget[i] - 'a';

		if (u == v)
			continue;
		if (distances[u][v] == LLONG_MAX)
			return -1;
		result += distances[u][v];
	}

	return result;
}
};

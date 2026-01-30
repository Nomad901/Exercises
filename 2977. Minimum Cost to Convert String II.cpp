struct Trie
{
    Trie()
    {
        for (size_t i = 0; i < 26; ++i)
        {
            child[i] = nullptr;
        }
        id = -1;
    }

    int32_t id;
    Trie* child[26];
};

int32_t add(Trie* pTrie, std::string_view pWord, int32_t& pIndex)
{
    for (auto& ch : pWord)
    {
        int32_t ind = ch - 'a';
        if (!pTrie->child[ind])
            pTrie->child[ind] = new Trie();
        pTrie = pTrie->child[ind];
    }
    if (pTrie->id == -1)
        pTrie->id = ++pIndex;

    return pTrie->id;
}

void update(long long& currentBest, long long newCandidate)
{
    if (currentBest == -1 || newCandidate < currentBest)
        currentBest = newCandidate;
}

class Solution {
public:
    long long minimumCost(std::string_view source, std::string_view target,
                          std::vector<std::string>& original,
                          std::vector<std::string>& changed,
                          std::vector<int32_t>& cost)
    {
        int transformationCount = original.size();
        int stringLength = source.size();
        Trie* root = new Trie();
        
        int32_t uniqueStringCount = -1;
        for (size_t i = 0; i < transformationCount; ++i)
        {
            add(root, original[i], uniqueStringCount);
            add(root, changed[i], uniqueStringCount);
        }
        
        int totalNodes = uniqueStringCount + 1;
        std::vector<std::vector<int32_t>> distances(totalNodes, 
            std::vector<int32_t>(totalNodes, INF));
        
        for (int i = 0; i < totalNodes; i++) {
            distances[i][i] = 0;
        }

        for (size_t i = 0; i < transformationCount; ++i)
        {
            int32_t u = add(root, original[i], uniqueStringCount);
            int32_t v = add(root, changed[i], uniqueStringCount);
            distances[u][v] = std::min(distances[u][v], cost[i]);
        }

        for (size_t k = 0; k < totalNodes; ++k)
        {
            for (size_t i = 0; i < totalNodes; ++i)
            {
                if (distances[i][k] == INF) continue;
                for (size_t j = 0; j < totalNodes; ++j)
                {
                    if (distances[k][j] == INF) continue;
                    distances[i][j] = std::min(distances[i][j], 
                                             distances[i][k] + distances[k][j]);
                }
            }
        }

        std::vector<long long> dp(stringLength, -1);
        for (int j = 0; j < stringLength; ++j)
        {
            if (j > 0 && dp[j - 1] == -1)
                continue;
                
            long long base = (j == 0 ? 0 : dp[j - 1]);
            
            if (source[j] == target[j]) {
                update(dp[j], base);
            }
            
            Trie* u = root;
            Trie* v = root;
            
            for (int i = j; i < stringLength; ++i)
            {
                u = u->child[source[i] - 'a'];
                v = v->child[target[i] - 'a'];
                
                if (!u || !v)
                    break;
                    
                if (u->id != -1 && v->id != -1 && distances[u->id][v->id] != INF)
                {
                    long long newCost = base + distances[u->id][v->id];
                    update(dp[i], newCost);
                }
            }
        }
        
        return dp[stringLength - 1];
    }
    
private:
    const int32_t INF = INT_MAX / 2;
};

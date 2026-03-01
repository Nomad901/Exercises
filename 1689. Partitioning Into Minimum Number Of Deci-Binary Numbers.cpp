class Solution {
public:
int32_t minPartitions(std::string pNumber)
{
	std::ranges::sort(pNumber);	
	return (pNumber.back() - '0');
}
};

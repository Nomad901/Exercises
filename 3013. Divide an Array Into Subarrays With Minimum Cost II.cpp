class Container
{
public:
	Container(int32_t pNumberOfSmallestNumbers)
		: mNumberOfSmallestNumbers(pNumberOfSmallestNumbers),
		  mSumFirstNumbers(0)
	{}

	void adjust()
	{
		while (mSmallestNumbers.size() < mNumberOfSmallestNumbers &&
			   mOtherNumbers.size() > 0)
		{
			int32_t beginOfOtherNumbers = *(mOtherNumbers.begin());
			mSmallestNumbers.emplace(beginOfOtherNumbers);
			mSumFirstNumbers += beginOfOtherNumbers;
			mOtherNumbers.erase(mOtherNumbers.begin());
		}
		while (mSmallestNumbers.size() > mNumberOfSmallestNumbers)
		{
			int32_t redundantNumber = *std::prev(mSmallestNumbers.end());
			mOtherNumbers.emplace(redundantNumber);
			mSmallestNumbers.erase(std::prev(mSmallestNumbers.end()));
			mSumFirstNumbers -= redundantNumber;
		}
	}

	void add(int32_t pNumber)
	{
		if (!mOtherNumbers.empty() && pNumber >= *(mOtherNumbers.begin()))
		{
			mOtherNumbers.emplace(pNumber);
		}
		else
		{
			mSmallestNumbers.emplace(pNumber);
			mSumFirstNumbers += pNumber;
		}
		adjust();
	}

	void erase(int32_t pNumber)
	{
		auto it = mSmallestNumbers.find(pNumber);
		if (it != mSmallestNumbers.end())
		{
			mSmallestNumbers.erase(it);
			mSumFirstNumbers -= pNumber;
		}
		else
		{
			mOtherNumbers.erase(mOtherNumbers.find(pNumber));
		}
		adjust();
	}

	long long getSum()
	{
		return mSumFirstNumbers;
	}

private:
	long long mSumFirstNumbers;

	std::multiset<int32_t> mSmallestNumbers, mOtherNumbers;

	int32_t mNumberOfSmallestNumbers; 
};
class Solution {
public:
long long minimumCost(std::vector<int32_t>& pNumbers, int32_t pNumberOfSubArrays, int32_t pDist)
{
	int32_t numbersSize = pNumbers.size();

	Container container(pNumberOfSubArrays - 2);
	for (size_t i = 1; i < pNumberOfSubArrays - 1; ++i)
	{
		container.add(pNumbers[i]);
	}

	long long result = container.getSum() + pNumbers[pNumberOfSubArrays - 1];

	for (size_t i = pNumberOfSubArrays; i < numbersSize; ++i)
	{
		int32_t j = i - pDist - 1;
		if (j > 0)
			container.erase(pNumbers[j]);
		container.add(pNumbers[i - 1]);
		result = std::min(result, container.getSum() + pNumbers[i]);
	}

	return result + pNumbers[0];
}

};

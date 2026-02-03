class Solution {
public:

bool isValid(std::string pString)
{
	std::stack<int8_t> stackOfChars;

	for (auto& c : pString)
	{
		if (c == '(' || c == '[' || c == '{')
			stackOfChars.push(c);
		else
		{
			if (stackOfChars.empty())
				return false;

			if (c == ')' && stackOfChars.top() != '(' ||
				c == ']' && stackOfChars.top() != '[' ||
				c == '}' && stackOfChars.top() != '{')
				return false;
			stackOfChars.pop();
		}
	}

	return stackOfChars.empty();
}
};

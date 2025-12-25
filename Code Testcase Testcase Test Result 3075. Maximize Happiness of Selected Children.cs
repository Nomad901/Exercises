public class Solution {
        public Int64 MaximumHappinessSum(Int32[] pHappiness, Int32 pNumber)
        {
            Array.Sort(pHappiness);
            Array.Reverse(pHappiness);

            Int64 totalSum = 0;

            for (Int32 i = 0; i < pNumber; ++i)
            {
                totalSum += Math.Max(0, pHappiness[i] - i);
            }

            return totalSum;
        }
}

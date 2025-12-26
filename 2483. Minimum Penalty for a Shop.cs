public class Solution {
    public Int32 BestClosingTime(string pCustomers) {
             Int32 minPenalty = 0;
            Int32 currentPenalty = 0;
            Int32 bestHour = 0;

            for (Int32 i = 0; i < pCustomers.Length; ++i)
            {
                if (pCustomers[i] == 'Y')
                    currentPenalty--;
                else
                    currentPenalty++;

                if(currentPenalty < minPenalty)
                {
                    minPenalty = currentPenalty;
                    bestHour = i + 1;
                }
            }

            return bestHour;
    }
}

#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& data) {
     Stats stat_ret;
   
   float sum=0;
   stat_ret.average=0;
   stat_ret.min=0;
   stat_ret.max=0;
   
   if (!data.empty()) //Check data is empty or not
    {
        /*Calculate average value*/
        for (auto i : data)
        {
            sum += i;
        }
	stat_ret.average = sum / data.size();
		
	/*Find maximum value*/
        stat_ret.max = *max_element(data.begin(), data.end());
		
	/*Find minimum value*/
        stat_ret.min = *min_element(data.begin(), data.end());
    }
    else 
    {
	stat_ret.average = std::nan("");
        stat_ret.min = std::nan("");
        stat_ret.max = std::nan("");
	}
	
	return stat_ret;
}

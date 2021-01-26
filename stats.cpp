#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& data) {
     Stats stat_ret;
   
   float sum=0;
   stat_ret.s_avg=0;
   stat_ret.s_min=0;
   stat_ret.s_max=0;
   
   if (data.empty()) //Check data is empty or not
    {
        stat_ret.average = NAN;
        stat_ret.min = NAN;
        stat_ret.max = NAN;
    }
    else 
    {
		/*Calculate average value*/
        for (auto i : data)
        {
            sum += i;
        }
		stat_ret.s_avg = sum / data.size();
		
		/*Find maximum value*/
        stat_ret.max = *max_element(data.begin(), data.end());
		
		/*Find minimum value*/
        stat_ret.min = *max_element(data.begin(), data.end());
	}
	
	return stat_ret;
}

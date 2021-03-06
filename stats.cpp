#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& data) {
     Stats stat_ret;
   
   float sum=0;
   stat_ret.average=0;
   stat_ret.min=0;
   stat_ret.max=0;
   
   if (data.empty()) //Check data is empty or not
    {
	   /*if data is empty, assign structure values (average,min,max)as NAN */
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
	stat_ret.average = sum / data.size();
		
	/*Find maximum value*/
        stat_ret.max = *max_element(data.begin(), data.end());
		
	/*Find minimum value*/
        stat_ret.min = *min_element(data.begin(), data.end());
     }
	
	return stat_ret;
}

EmailAlert::EmailAlert() : emailSent(false){}
void EmailAlert::SetAlert(bool status){this->emailSent=status;}

LEDAlert::LEDAlert() : ledGlows(false){}
void LEDAlert::SetAlert(bool status){this->ledGlows=status;}

EmailAlert::~EmailAlert(){}
LEDAlert::~LEDAlert(){}

StatsAlerter::StatsAlerter(const float threshold , std::vector<IAlerter*>& alerterlist)
    :maxThreshold(threshold) , alerter(alerterlist){}

void StatsAlerter::checkAndAlert(const std::vector<float>& data)
{	
	bool set_Alert = false;
	auto stat = Statistics::ComputeStatistics(data);
	

	if(stat.max > maxThreshold)
	{
		set_Alert = true;
	}

	for(auto itr = alerter.begin();itr != alerter.end() ; ++ itr )
	{
		(*itr)->SetAlert(set_Alert );
	}
 
}

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
void EmailAlert::SetAlert(bool status){this->emailSent=true;}

LEDAlert::LEDAlert() : ledON(false){}
void LEDAlert::SetAlert(bool status){this->ledON=true;}

EmailAlert::~EmailAlert(){}
LEDAlert::~LEDAlert(){}

StatsAlerter::StatsAlerter(const float threshold , std::vector<IAlerter*>& alerterlist)
    :maxThreshold(threshold) , alerter(alerterlist){}

void StatsAlerter::checkAndAlert(const std::vector<float>& data)
{
    for (auto i : data)
    {
        if (i > maxTh)
        { 
	std::vector<IAlerter*>::iterator itr = alerter.begin();
            for (;itr != _alerts.end() ; ++ itr)
            {
               (*itr)->setAlert(true);
            }
        }
    }
}

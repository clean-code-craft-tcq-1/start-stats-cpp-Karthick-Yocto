#include<iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
typedef struct stats
{
    float average;
    float min;
    float max;
}Stats;
namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& data);
}
/* TestCase:Threshold value check and sent alert*/
class IAlerter
{
public:
    virtual ~IAlerter(){}
    virtual void SetAlert(bool status) = 0;
};

class EmailAlert : public IAlerter
{
public:
    bool emailSent;
    
    virtual ~EmailAlert();
    EmailAlert();
    virtual void SetAlert(bool status);
};

class LEDAlert : public IAlerter
{
public:
    bool ledGlows;
    
    virtual ~LEDAlert();
    LEDAlert();
    virtual void SetAlert(bool status);
};

class StatsAlerter
{
private : 
    float maxThreshold; 
    std::vector<IAlerter*> alerter; 

public : 
    StatsAlerter(const float ma, std::vector<IAlerter*>& alerterlist);

    void checkAndAlert(const std::vector<float>& data);
};

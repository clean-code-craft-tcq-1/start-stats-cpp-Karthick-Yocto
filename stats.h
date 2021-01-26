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

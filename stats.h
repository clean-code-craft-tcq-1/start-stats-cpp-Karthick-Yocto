#include <vector>
typedef struct stats
{
    float s_avg;
    float s_min;
    float s_max;
}Stats;
namespace Statistics {
    Stats ComputeStatistics(const std::vector<>& data);
}

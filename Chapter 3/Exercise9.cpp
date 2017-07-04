#include <iostream>

using namespace std;

// Consider this modification of the sales array: Because salespeople come and go throughout the year, we are now marking
// months prior to a sales agent’s hiring, or after a sales agent’s last month, with a −1. Rewrite your highest sales
// average, or highest sales median, code to compensate.

int main()
{
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
    {-1, -1, -1, -1, 328, 2653, 387, 3754, 387587, 52, 67, -1},
    {5865, 5456, 3983, -1, -1, -1, -1, 3838, 4959, 1122, 7766, -1},
    {-1, 55, 67, 99, -1, 376, 232, -1, 4546, 564, -1, -1}
    };
    int highest_agent_average = 0;
    for (int agent = 0; agent < NUM_AGENTS; agent++)
    {
        int agent_total = 0;
        int agent_month_count = 0;
        for (int month = 0; month < NUM_MONTHS; month++)
        {
            if (sales[agent][month] != -1)
            {
                agent_total += sales[agent][month];
                agent_month_count++;
            }
        }
        int agent_average = agent_total / agent_month_count;
        if (agent_average > highest_agent_average)
        {
            highest_agent_average = agent_average;
        }
    }
    cout << "Highest agent average is: " << highest_agent_average << endl;
    return 0;
}

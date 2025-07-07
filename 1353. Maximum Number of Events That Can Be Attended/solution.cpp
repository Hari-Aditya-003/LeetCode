#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int day = 0, index = 0, result = 0;
        int n = events.size();

        while (!minHeap.empty() || index < n) {
            // If no events in heap, jump to next event's start day
            if (minHeap.empty()) {
                day = events[index][0];
            }

            // Push all events starting on or before this day
            while (index < n && events[index][0] <= day) {
                minHeap.push(events[index][1]);
                index++;
            }

            // Remove all events that have already ended
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend the event with the earliest end day
            if (!minHeap.empty()) {
                minHeap.pop();
                result++;
                day++;
            }
        }

        return result;
    }
};
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// Line sweep technique

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> events;

        for(const auto& meeting:intervals){
            events[meeting.start]++;
            events[meeting.end]--;
        }

        int overLaps = 0, maxOverLaps = 0;
        for(auto &event : events){
            overLaps += event.second;
            maxOverLaps = max(overLaps, maxOverLaps);

        }
        return maxOverLaps;
    }
};

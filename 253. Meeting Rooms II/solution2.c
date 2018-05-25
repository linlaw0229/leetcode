/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
      
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> changes;
        for (auto i : intervals) {
            changes.push_back({i.start, 1});
            changes.push_back({i.end, -1});
        };
        sort(changes.begin(), changes.end());
        int rooms = 0, maxrooms = 0;
        for (auto change : changes)
            maxrooms = max(maxrooms, rooms += change.second);
        return maxrooms;
    }
};
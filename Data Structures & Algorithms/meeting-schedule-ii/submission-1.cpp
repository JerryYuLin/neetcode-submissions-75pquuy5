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

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start_times, end_times;

        for ( auto interval : intervals ) {
            start_times.push_back( interval.start );
            end_times.push_back( interval.end );
        }

        sort( start_times.begin(), start_times.end() );
        sort( end_times.begin(), end_times.end() );

        int n = start_times.size(), i = 0, j = 0, room = 0, max_room = 0;

        while ( i < n ) {
            if ( start_times[i] < end_times[j] ) {
                ++room;
                ++i;

                if ( room > max_room )
                    max_room = room;
            }
            else {
                --room;
                ++j;
            }
        }

        return max_room;
    }
};

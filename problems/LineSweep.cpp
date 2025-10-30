#include <algorithm>
#include <vector>
using namespace std;


class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
      vector<int> startTimings;
      vector<int> endTimings;
      for (Interval intv : intervals){
        startTimings.push_back(intv.start);
        endTimings.push_back(intv.end);
      }
      //sort(startTimings.begin(),startTimings.end());
      sort(endTimings.begin(),endTimings.end());
      int count(0);
      int maxCount(0);
      int j = 0;
      int i = 0; 
      for (int k = 0 ; k < startTimings.size() ; k ++ ){
        if (startTimings[i]<endTimings[j])
        {
          count ++;
          i ++;
          if (count > maxCount) maxCount = count;
        }
        else{
          count -- ;
          j ++;
        } 
      }
      return maxCount;

    }
};


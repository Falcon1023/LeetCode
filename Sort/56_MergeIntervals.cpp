#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0)
            return res;
        quickSort(intervals, 0, intervals.size()-1);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            Interval tmp = res.back();
            if (tmp.end >= intervals[i].start) {
                res.pop_back();
                intervals[i].start = (tmp.start < intervals[i].start) ? tmp.start : intervals[i].start;
                intervals[i].end = (tmp.end > intervals[i].end) ? tmp.end : intervals[i].end;
            }
            res.push_back(intervals[i]);
        }
        return res;
    }

    void quickSort(vector<Interval>& intervals, int beg, int end) {
        if (beg >= end)
            return;

        Interval tmp = intervals[end];
        int p = beg, q = end-1;
        while (true) {
            while (p < end && intervals[p].start < tmp.start)
                ++p;
            while (q >= beg && intervals[q].start >= tmp.start)
                --q;
            if (p >= q)
                break;
            swap(intervals, p, q);
        }
        swap(intervals, p, end);
        quickSort(intervals, beg, p-1);
        quickSort(intervals, p+1, end);
    }

    void swap(vector<Interval>& intervals, int p, int q) {
        Interval tmp = intervals[p];
        intervals[p] = intervals[q];
        intervals[q] = tmp;
    }
};
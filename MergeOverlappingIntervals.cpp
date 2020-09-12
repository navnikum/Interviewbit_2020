// Merge Overlapping Intervals
Asked in:  
Google
Amazon

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool mycomp(Interval a, Interval b)  {
    return a.start < b.start; 
} 
vector<Interval> Solution::merge(vector<Interval> &A) {
    int n = A.size();
    sort(A.begin(), A.end(), mycomp);
    int idx = 0;  // Stores index of last element in modified array
    for(int i = 1; i < n; i++){
        // not first interval and overlaps with the previous interval
        if(A[idx].end >= A[i].start){
            // merge prev and current intervals
            A[idx].end = max(A[idx].end, A[i].end);
            A[idx].start = min(A[idx].start, A[i].start);
        }
        else    // no overlap add to solution
        {   idx++;
            A[idx] = A[i];
        }
        
    }
    A.resize(idx+1);
    return A;
}

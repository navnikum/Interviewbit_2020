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
vector<Interval> Solution::merge(vector<Interval> &A) {
    int n = A.size();
    // in decreasing order of start time
    sort(A.begin(), A.end(), [](const Interval &a, const Interval &b) {return a.start > b.start;});
    int idx = 0; // store idx of last element in output array
    for(int i = 0; i < n; i++){
        // if not first interval and overlaps with previous
        if(idx !=0 && A[idx-1].start <= A[i].end){
            while(idx !=0 && A[idx-1].start <= A[i].end){
                // merge prev and current intervals
                A[idx-1].end = max(A[idx-1].end, A[i].end);
                A[idx-1].start = min(A[idx-1].start, A[i].start);
                idx--;
            } 
        }
        else    // no overlap add to solution
            A[idx] = A[i];
        idx++;
    }
    A.resize(idx);
    sort(A.begin(), A.end(), [](const Interval &a, const Interval &b) {return a.start < b.start;});
    return A;
}

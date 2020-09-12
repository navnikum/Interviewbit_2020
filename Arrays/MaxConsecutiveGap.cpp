// Maximum Consecutive Gap
Asked in:  
Hunan Asset

// Time Complexity : O(nlogn)
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n < 2)   return 0;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++)
        pq.push(A[i]);
    
    int diff = 0;
    int first = pq.top(); pq.pop();
    int second;
    while(pq.size() >= 1){
        int second = pq.top(); pq.pop();
        diff = max(diff, first-second);
        first = second;
    }
    return diff;
}

// Time Complexity : O(n)
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n < 2) return 0;
    int min_x= *min_element(A.begin(), A.end());
    int max_x= *max_element(A.begin(), A.end());
    int max_gap = max_x - min_x;
    double delta = (max_gap) * 1.0 / (n - 1);
    
    vector<int> min_bucket(n - 1, INT_MAX), max_bucket(n - 1, INT_MIN);
    
    for(int i = 0; i < A.size(); i++) {
        int x = A[i];
        if(x == min_x || x == max_x) 
            continue;
        
        int pos = floor((x - min_x) / delta);
        min_bucket[pos] = min(min_bucket[pos], x);
        max_bucket[pos] = max(max_bucket[pos], x);
    }
    
    int max_diff = INT_MIN;
    int prev_max = min_x;
    for(int i = 0; i < (n - 1); i++) {
        if(min_bucket[i] == INT_MAX) 
            continue; //empty bucket
        
        int curr = min_bucket[i] - prev_max;
        max_diff = max(max_diff, curr);
        prev_max = max_bucket[i];
    }
    max_diff = max(max_diff, max_x - prev_max);
    return max_diff;
}

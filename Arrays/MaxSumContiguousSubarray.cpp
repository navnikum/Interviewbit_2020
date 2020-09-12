// Max Sum Contiguous Subarray : KADANE
Facebook
Paypal
Yahoo
Microsoft
LinkedIn
Amazon
Goldman Sachs

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int cur = 0, far = INT_MIN;
    for(int i = 0; i < n; i++){
        cur = max(cur+A[i], A[i]);
        far = max(far, cur);
    }
    return far;
}

// with [s,e]
int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int cur = 0, far = INT_MIN;
    int s = 0, e = 0, start = 0;
    for(int i = 0; i < n; i++){
        cur+=A[i];
        if(cur > far){
            far = max(far, cur);
            s = start;
            e = i;
        }
        if(cur < 0){
            cur = 0;
            start = i+1;
        }
    }
    return far;
}



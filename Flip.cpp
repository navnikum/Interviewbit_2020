// Flip

vector<int> Solution::flip(string A) {
    // initially : A 0s and B 1s, finally B 0s and A 1s
    // net change in 1s : A-B , maximize this using Kadane [L,R]
    int n = A.size();
    long long cur = 0, far = 0;
    int s = 0, e = 0, start = 0;
    for(int i = 0; i<n; i++){
        cur += (A[i] == '1') ? -1: 1;
        if(far < cur){
            far = cur;
            s = start;
            e = i;
        }
        if(cur < 0){
            cur = 0;
            start = i+1;
        }
    }
    vector<int> ans;
    if(far){
        ans.push_back(s+1);
        ans.push_back(e+1);
    }
    return ans;
}

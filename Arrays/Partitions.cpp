// Partitions
Asked in:  
EzCred

// Time Complexity is O(n^2)
#include <numeric>
int Solution::solve(int n, vector<int> &v) {
    int count = 0;
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum%3 == 0) {
        int runningSum = 0;
        int prefixSum[n], suffixSum[n];
        for(int i=0; i<n; i++){
            suffixSum[i] = sum - runningSum;
            runningSum += v[i];
            prefixSum[i] = runningSum;
        }
        int req = sum/3;
        for(int i = 0; i< n-2; i++){
            if(prefixSum[i] == req){
                for(int j = i+2; j<n; j++){
                    if(suffixSum[j] == req)
                        count++;
                }
            }
        }
    }
    return count;
}

// Time Complexity is O(nlog n)
#include <numeric>
int Solution::solve(int n, vector<int> &v) {
    int count = 0;
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum%3 == 0) {
        int runningSum = 0;
        vector<int> prefixSum(n), suffixSum(n);
        for(int i=0; i<n; i++){
            suffixSum[i] = sum - runningSum;
            runningSum += v[i];
            prefixSum[i] = runningSum;
        }
        int req = sum/3;
        vector<int> fr,l;
        for(int i = 0; i< n-2; i++){
            if(prefixSum[i] == req)
                fr.push_back(i);
        }
        for(int i = 2; i< n; i++){
            if(suffixSum[i] == req)
                l.push_back(i);
        }
        for(int i = 0; i< fr.size(); i++)
            count+= l.end() - upper_bound(l.begin(), l.end(), fr[i]+1);
    }
    return count;
}

// Time Complexity is O(n)
int Solution::solve(int n, vector<int> &v) {
    int count = 0;
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum%3 == 0) {
        int req = sum/3;
        int curr = 0, x = 0;
        for(int i = 0;i < n-1; i++){
            curr += v[i];
            if(curr == 2*req)
                count += x;
            if(curr == req)
                x++;
        }
    }
    else
        return 0;
    return count;
}

// Time Complexity is O(n)
#include <numeric>
int Solution::solve(int n, vector<int> &v) {
    int ans = 0;
    vector<int> count(n, 0);
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum%3 == 0) {
        int req = sum/3;
        int curr = 0, x = 0;
    // reverse order traversal for count 
        for(int i = n-1;i >= 0; i--){
            curr += v[i];
            if(curr == req)
                count[i] = 1;
        }
        for(int i = n-2;i >= 0; i--)
            count[i] += count[i+1];
    // forward traversal for final ans
        curr = 0;
        for(int i = 0; i+2 < n; i++){
            curr += v[i];
            if(curr == req)
                ans += count[i+2];
        }
    }
    else
        return 0;
    return ans;
}

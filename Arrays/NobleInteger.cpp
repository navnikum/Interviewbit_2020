// Noble Integer

// Time Complexity : O(nlogn)
int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    for(int i = 0; i < n; i++){
        int num = upper_bound(A.begin(), A.end(), A[i]) - A.begin();
        int cnt = n - num;
        if(cnt == A[i])
            return 1;
    }
    return -1;
}

// Time Complexity : O(n)
int Solution::solve(vector<int> &A) {
    int n = A.size();
    map<int, int> mp; // to iterate in order
    for(int i = 0; i < n; i++){
        mp[A[i]]++;
    }
    int sum = 0;
    for(auto it = mp.rbegin(); it != mp.rend(); it++){
        if(it->first == sum)
            return 1;
        sum += it->second;
    }
    return -1;
}

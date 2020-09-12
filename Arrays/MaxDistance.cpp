// Max Distance
Asked in:  
Google
Amazon
Microsoft

// Time complexity : O(nlogn)
int Solution::maximumGap(const vector<int> &v) {
    int n = v.size();
    if(n == 0)  return -1;
    if(n == 1)  return 0;
    vector< pair<int, int>> A;
    for(int i = 0; i < n; i++)
        A.push_back({v[i], i});
        
    sort(A.begin(), A.end());
    int j = A[n-1].second;
    int ans = 0;
    for(int i = n-2; i >= 0; i--){
        ans = max(ans, j - A[i].second);
        j = max(j, A[i].second);
    }
    return ans;
}

// Time complexity : O(n)
int Solution::maximumGap(const vector<int> &v) {
    int n = v.size();
    if(n == 0)  return -1;
    if(n == 1)  return 0;
    // Lmin : min till i; Rmax : max from i
    vector<int>  Lmin(n), Rmax(n);
    Lmin[0] = v[0], Rmax[n-1] = v[n-1];
    for(int i = 1; i < n; i++)
        Lmin[i] = min(Lmin[i-1], v[i]);
    for(int i = n-2; i >= 0; i--)
        Rmax[i] = max(Rmax[i+1], v[i]);
        
    // Traverse left to right to find optimum j - i, similar to merge() of MergeSort
    int ans = -1, i = 0, j = 0;
    while(i < n && j < n){
        if(Lmin[i] <= Rmax[j]){
            ans = max(ans, j - i);
            j++;
        }
        else 
            i++;
    }
    return ans;
}

// Kth Row of Pascal's Triangle
Asked in:  
Google

vector<vector<int> > pascal(int A) {
    int n = A;
    if(n == 0) return {};
    if(n == 1) return {{1}};
    vector<vector<int> > v(n);
    v[0] = {1};
    v[1] = {1, 1};
    for(int i = 2; i < n; i++){
        v[i].push_back(1);
        for(int j = 1; j < v[i-1].size(); j++)
            v[i].push_back(v[i-1][j-1] + v[i-1][j]);
        v[i].push_back(1);
    }
    return v;
}
vector<int> Solution::getRow(int A) {
    vector<vector<int> > p = pascal(A+1);
    return p[A];
}


// using only O(k) extra space
vector<int> Solution::getRow(int A) {
    vector<int> r(A+1);
    r[0] = 1;
    int a = 1;
    for(int i = 1; i<=A; i++){
        a = (a*(A-i+1)/i); // using nCr formula
        r[i] = a;
    }
    return r;
}

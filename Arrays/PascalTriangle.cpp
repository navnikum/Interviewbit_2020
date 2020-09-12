// Pascal Triangle
Asked in:  
Google
Amazon

vector<vector<int> > Solution::solve(int A) {
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

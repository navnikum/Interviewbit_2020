// Anti Diagonals
Asked in:  
Microsoft
Adobe

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> > v(2*(n-1)+1);
    vector<int> diagonal;
    if(n == 0)
        return v;
    for(int i = 0; i <= 2*(n-1); i++){
        for(int j = 0; j <= i ; j++){
            int k = i-j;
            if(j >= n || k >= n)
                continue;
            //diagonal.push_back(A[j][k]);
            v[i].push_back(A[j][k]);
        }
        //v.push_back(diagonal);
        //diagonal.clear();
    }
    return v;
}

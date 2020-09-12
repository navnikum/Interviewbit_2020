// SetMatrixZeros
Asked in:  
Oracle
Amazon

void Solution::setZeroes(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size(), i, j;
    bool row0has0 = false;
    for(j = 0; j < n; j++){
        if(A[0][j] == 0)
        row0has0 = true;
    }
    bool col0has0 = false;
    for(i = 0; i < m; i++){
        if(A[i][0] == 0)
        col0has0 = true;
    }
    // use first row and first column as storage
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(A[i][j] == 0){
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    
    for(i = 1; i < m; i++)
        for(j = 1; j < n; j++)
            if(A[i][0] == 0 || A[0][j] == 0)
                A[i][j] = 0;
                
    if(row0has0)
        for(j = 0; j < n; j++)
            A[0][j] = 0;
    
    if(col0has0)
        for(i = 0; i < m; i++)
            A[i][0] = 0;
    
}

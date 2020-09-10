// Spiral Order Matrix II
Asked in:  
Microsoft
JP Morgan
Amazon

vector<vector<int> > Solution::generateMatrix(int A) {
    int n = A;
    vector< vector<int> > v(n, vector<int>(n, 0));
    int top = 0, bottom = n-1;
    int left = 0, right = n-1;
    int dir = 0, i, k = 1;
    while(top <= bottom && left <= right){
        if(dir == 0) // L to R
        {
            for(i = left; i <= right; i++)  
                v[top][i] = k++;
            top++;
        }
        else if(dir == 1) // top to Bottom
        {
            for(i = top; i <= bottom; i++)
                v[i][right] = k++;
            right--;
        }
        else if(dir == 2) // R to L
        {
            for(i = right; i >= left; i--)
                v[bottom][i] = k++;
            bottom--;
        }
        else if(dir == 3) // bottom to top
        {
            for(i = bottom; i >= top; i--)
                v[i][left] = k++;
            left++;
        }
        dir = (dir+1)%4;
    }
    return v;
}


vector<vector<int> > Solution::generateMatrix(int A) {
    int n = A;
    vector< vector<int> > v(n, vector<int>(n, 0));
    int top = 0, bottom = n-1;
    int left = 0, right = n-1;
    int i, k = 1;
    while(k <= n*n){
        for(i = left; i <= right; i++)  
            v[top][i] = k++;
        top++;
      
        for(i = top; i <= bottom; i++)
            v[i][right] = k++;
        right--;
        
        for(i = right; i >= left; i--)
            v[bottom][i] = k++;
        bottom--;
        
        for(i = bottom; i >= top; i--)
            v[i][left] = k++;
        left++;
        
    }
    return v;
}

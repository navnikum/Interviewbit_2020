// Spiral Order Matrix I
Asked in:  
Microsoft
JP Morgan
Amazon
Flipkart
Adobe

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    int t=0, b=m-1, l=0, r=n-1;
    int dir = 0; // dir = 0 :  LtoR, 1 : TtoB, 2 : RtoL, 3, BtoT
    vector<int> v;
    while(t<=b && l<=r){
        if(dir==0){
            for(int i = l; i <= r; i++)
                v.push_back(A[t][i]);
            t++;
        }
        else if(dir==1){
            for(int i = t; i<= b; i++)
                v.push_back(A[i][r]);
            r--;
        }
        else if(dir==2){
            for(int i = r; i>= l; i--)
                v.push_back(A[b][i]);
            b--;
        }
        else if(dir==4){
            for(int i =b; i>= t; i--)
                v.push_back(A[i][l]);
            l++;
        }
        dir= (dir+1) % 4;
    }
    return v;
}

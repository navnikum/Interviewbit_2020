// Triplets with Sum between given range

// Time complexity : O(nlogn) : sort with 3 pointers: 2 fwd and 1 reverse
int Solution::solve(vector<string> &A) {
    int n = A.size();
    vector<double> v;
    for(int i = 0; i < n; i++){
    	double val = stod(A[i]);
    	if(val < 2.0)
        	v.push_back(val);
	}
  //a contains all nos. lesser than 2 converted in double
  n = v.size();
  if(n<3) return 0;
  sort(v.begin(), v.end());
  int i = 0, j = 1, k = n-1;
	while(i<j && j<k && k<n){
        if(v[i] + v[j] + v[k] >= 2)    k--;
        else if(v[i] + v[j] + v[k] <= 1){
            if(j-i == 1)
                j++;
            else
                i++;
        }
        else
            return 1;
    }
    return 0;
}

// Time complexity : O(nlogn) : sort and check
int Solution::solve(vector<string> &A) {
    int n = A.size();
    vector<double> v;
    for(int i = 0; i < n; i++){
    	double val = stod(A[i]);
    	if(val < 2.0)
        	v.push_back(val);
	}
  //a contains all nos. lesser than 2 converted in double
  n = v.size();
  if(n<3) return 0;
  sort(v.begin(), v.end());
  double sum = v[0]+v[1]+v[2];
  if(sum >= 2.0)    
      return 0;
  sum=v[n-1]+v[n-2]+v[n-3];
  if(sum <= 1)  
      return 0;
  return 1;
}

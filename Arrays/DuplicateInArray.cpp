// Find Duplicate in Array

Asked in:  
Amazon
VMWare
Riverbed

//METHOD 1 - NAIVE APPROACH
//Double loop, returns first duplicate encountered in linear traversal
//T=O(n^2), S=O(1)
int Solution::repeatedNumber(const vector<int>&A) {
    for(int i=0;i<A.size();i++) {
        for(int j=i+1;j<A.size();j++) {
            if(A[j]==A[i])
                return A[j];
        }
    }
    return -1;
}

//METHOD 2 - USING SUMMATION
//works for single duplicte only
//T=O(n), S=O(1)
int Solution::repeatedNumber(const vector<int>&A) {
int sum = accumulate(A.begin(),A.end(),0);
    int ans = sum-(A.size()*(A.size()-1)/2);
    return (ans<A.size()) ? ans : -1;
}

//METHOD 3 - USING XOR
//works for single duplicate only
//T=O(n), S=O(1)
int Solution::repeatedNumber(const vector<int>&A) {
// accumulate all XORs of A[i]
    int ans = accumulate(A.begin(),A.end(),0,[](int p, int q){return p^q;});
    for(int i=1;i<A.size();i++)
        ans^=i;
    return (ans<A.size())?ans:-1;    
}

//METHOD 4 - SORTING SEARCHING
//works for all cases, returns smallest duplicate
//T=O(nlong), S=O(1) for non-const array, S=O(n) for const array
int Solution::repeatedNumber(const vector<int>&A) {
    vector<int>B=A;//copy needed since array in const
    sort(B.begin(),B.end());
    for(int i=1;i<B.size();i++) {
        if(B[i]==B[i-1])
            return B[i];
    }
    return -1;
}

//METHOD 5 - BUCKETING APPROACH 
//works for all cases, return a duplicate, not necessarily first duplicate
// T=O(n), S=O(root(n))
int Solution::repeatedNumber(const vector<int>&A) {
    int n=A.size()-1;
    int bucket=int(sqrt(n));
    vector<int>buckets(ceil((n+1)*1.0/bucket),0);
    for(int i=0;i<A.size();i++)
        buckets[(A[i]-1)/bucket]++;
    int check=buckets.size()-1;
    for(int i=0;i<buckets.size();i++) {
        if(buckets[i]>bucket) {    
            check=i;
            break;
        }
    }
    map<int,int>counts;
    int left=check*bucket+1;
    int right=(check+1)*bucket+1;
    for(int i=0;i<A.size();i++) {
        if(A[i]>=left && A[i]<right) {
            counts[A[i]]++;
            if(counts[A[i]]>1)
                return A[i];
        }
    }
    return -1;
}

//METHOD 6 - USING HASHMAP
//works for all cases, returns first duplicate encountered in linear traversal
//T=O(n), S=O(n)
int Solution::repeatedNumber(const vector<int>&A) {
    unordered_map<int,int>counts;
    for(int i=0;i<A.size();i++)
        counts[A[i]]++;
    for(auto it:counts) {
        if(it.second>1)
            return it.first;
    }
    return -1;
}

//Method 7 - FLOYD'S TORTOISE AND HARE
//works for all cases if duplicate number is guaranteed(can be tweaked to get -1 otherwise)
//returns a duplicate, not necessarily first duplicate
//T=O(n), S=O(1)
int Solution::repeatedNumber(const vector<int>&A)
{
    int tortoise=A[0],hare=A[0];
    while(true) {
        tortoise=A[tortoise];
        hare=A[A[hare]];
        if(tortoise==hare)
            break;
    }
    //stuck in infinite while loop if no duplicates
    //can be tweaked to get -1 in such cases, modify accordingly
    tortoise=A[0]; 
    while(tortoise!=hare) {
        tortoise=A[tortoise];
        hare=A[hare];
    }
    return tortoise;
}


// BUCKETING with comments
int Solution::repeatedNumber(const vector<int>&A) {
    int n=A.size()-1;
    int bucket=int(sqrt(n)); //size of bucket
    vector<int>buckets(ceil((n+1)*1.0/bucket),0); //number of buckets
    for(int i=0;i<A.size();i++)
        buckets[(A[i]-1)/bucket]++; //frequency of A[i] will be stored by bucket index (A[i]-1)/bucket                        
    int check=buckets.size()-1; //initally set to last bucket index
    for(int i=0;i<buckets.size();i++) {
        if(buckets[i]>bucket) //check if a bucket overflows 
        {    
            check=i; //store overflown bucket index
            break;
        }
    }
    map<int,int>counts; //max size of this map will be sqrt(n)
    int left=check*bucket+1; //left bound of bucket elements
    int right=(check+1)*bucket+1; //right bound of bucket elements
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>=left && A[i]<right)//update frequency of elements belonging to this bucket
        {
            counts[A[i]]++;
            if(counts[A[i]]>1)//if an element occurs more than once, return it
                return A[i];
        }
    }
    return -1;// no duplicate
}

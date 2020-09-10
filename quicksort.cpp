// QuickSort

void quicksort(vector<int>&arr, int left, int right){
    int min = (left + right)/2;

    int i = left;
    int j = right;
    int pivot = arr[min];

    while(left < j || i < right){
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
 
        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else{
            if(left < j)
                quicksort(arr, left, j);
            if(i < right)
                quicksort(arr,i,right);
            return;
        }
    }
}

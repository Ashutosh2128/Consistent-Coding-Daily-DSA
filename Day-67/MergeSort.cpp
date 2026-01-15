class Solution {
  public:
    void mergeSortHelper(vector<int>& arr, int s, int mid, int e) {
        int firstLen = mid - s + 1;
        int secondLen = e - mid;
        
        int* arr1 = new int[firstLen];
        int* arr2 = new int[secondLen];
        
        int index = s;
        for(int i = 0; i < firstLen; i++) {
            arr1[i] = arr[index++];
        }
        
        for(int i = 0; i < secondLen; i++) {
            arr2[i] = arr[index++];
        }
        
        //now arr1 and arr2 is both are sorted array. we need to merge to sorted array
        int leftIdx = 0;
        int rightIdx = 0;
        index = s;
        
        while(leftIdx < firstLen && rightIdx < secondLen) {
            if(arr1[leftIdx] <= arr2[rightIdx]) {
                arr[index++] = arr1[leftIdx++];
            }
            else {
                arr[index++] = arr2[rightIdx++];
            }
        }
        
        while(leftIdx < firstLen) {
            arr[index++] = arr1[leftIdx++];
        }
        
        while(rightIdx < secondLen) {
            arr[index++] = arr2[rightIdx++];
        }
        
        delete[] arr1;
        delete[] arr2;
    }
  
    void merge(vector<int>& arr, int s, int e) {
        if(s == e) return;
        
        int mid = s + (e - s) / 2;
        
        merge(arr, s, mid);
        merge(arr, mid+1, e);
        
        mergeSortHelper(arr, s, mid, e);
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        merge(arr, l, r);
    }
};
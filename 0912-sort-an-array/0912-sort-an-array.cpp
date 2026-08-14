class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end){
        vector<int> mergevec(end-start+1);
        int left = start;
        int right = mid + 1;
        int index = 0;

        while(left<=mid && right<=end){
            if(nums[left] <= nums[right]){
                mergevec[index] = nums[left];
                left++;
                index++;
            }

            else{
                mergevec[index] = nums[right];
                right++;
                index++;
            }
        }

        while(left <= mid){
            mergevec[index] = nums[left];
            left++;
            index++;
         } 

         while(right <= end){
            mergevec[index] = nums[right];
            right++;
            index++;
         }

         index = 0;
         while(start <= end){
            nums[start] = mergevec[index];
            start++;
            index++;
         }
    }

    void mergesort(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }

        int mid = start + (end - start) / 2;
        mergesort(nums, start, mid);
        mergesort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};
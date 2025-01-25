class Solution {
public:
    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int count = 0;
        int i = low;
        int j = mid + 1;

        while (i <= mid) {
            while (j <= high && arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - mid - 1);
            i++;
        }

        return count;
    }

    void merge(vector<int>& arr, int low, int mid, int high) {
        int i = low, j = mid + 1, k = 0;
        vector<int> temp(high - low + 1);

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= high) {
            temp[k++] = arr[j++];
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high, int& count) {
        if (low < high) {
            int mid = low + (high - low) / 2;

            // Sort left half
            mergeSort(arr, low, mid, count);

            // Sort right half
            mergeSort(arr, mid + 1, high, count);

            // Count reverse pairs
            count += countPairs(arr, low, mid, high);

            // Merge both halves
            merge(arr, low, mid, high);
        }
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums, 0, nums.size() - 1, count);
        return count;
    }
};

class MedianFinder {
public:
    vector<int> arr;

    MedianFinder() {
    }
    
    void addNum(int num) {
        int l = 0;
        int r = arr.size() - 1;
        int insert_index = arr.size();

        while (l <= r) {
            int mid = (l + r) / 2;

            if (arr[mid] < num) {
                l = mid + 1;
            } else {
                insert_index = mid;
                r = mid - 1;
            }
        }

        arr.insert(arr.begin() + insert_index, num);
    }
    
    double findMedian() {
        int n = arr.size();

        if (n % 2 == 0) {
            return (arr[n/2] + arr[n/2 - 1]) / 2.0;
        }

        return arr[n/2];
    }
};
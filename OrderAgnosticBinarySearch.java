public class OrderAgnosticBinarySearch {
    public static int orderAgnosticBinarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == arr[mid]) {
                return mid;
            }
            // Ascending order
            if (arr[start] < arr[end]) {
                if (target > arr[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            // Descending order
            else {
                if (target > arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr1 = {2, 4, 6, 9, 11, 12, 14, 20, 36, 48};
        int[] arr2 = {90, 75, 18, 12, 6, 4, 3, 1};
        int target1 = 36;
        int target2 = 75;
        System.out.println(orderAgnosticBinarySearch(arr1, target1));
        System.out.println(orderAgnosticBinarySearch(arr2, target2));
    }
}
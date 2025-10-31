import java.util.*;

public class BinarySearch {
    // Iterative Binary Search
    public static int Iterative(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid; // Element found
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1; // Element not found
    }

    // Recursive Binary Search
    public static int Recursive(int[] arr, int low, int high, int target) {
        if (low > high)
            return -1;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return Recursive(arr, low, mid - 1, target);
        else
            return Recursive(arr, mid + 1, high, target);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter elements in sorted order:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter target element to search: ");
        int target = sc.nextInt();

        // Iterative version
        int resultIterative = Iterative(arr, target);

        // Recursive version
        int resultRecursive = Recursive(arr, 0, n - 1, target);

        if (resultIterative != -1)
            System.out.println("Element found at index (iterative): " + resultIterative);
        else
            System.out.println("Element not found (iterative).");

        if (resultRecursive != -1)
            System.out.println("Element found at index (recursive): " + resultRecursive);
        else
            System.out.println("Element not found (recursive).");

        sc.close();
    }
}

Aim
To design and implement an efficient algorithm to find the minimum element in a rotated sorted array that may contain duplicate values.

Objectives
- To apply a modified binary search technique that handles array rotation and duplicate elements.

- To correctly eliminate halves of the search space by comparing the midpoint with the rightmost element.

- To handle the ambiguous case where the midpoint equals the rightmost element by safely shrinking the right boundary.

- To analyze time and space complexity of the solution.

- To validate the solution using test cases and edge cases.

Hardware Requirement
Standard desktop/laptop with minimum 4 GB RAM, dual-core processor, and keyboard/mouse.

Software Requirement
- Operating System: Windows / Linux / macOS

- C++ Compiler: GCC/Clang

- Java Development Kit (JDK 8 or above)

- IDE: VS Code / Code::Blocks / IntelliJ / Eclipse 

Description of Program
The program uses a modified binary search that compares the midpoint value with the rightmost element to locate the minimum. If the midpoint is greater than the rightmost element, the minimum must lie in the right half, so the left pointer moves past mid. If the midpoint is less than the rightmost element, the minimum is in the left half including mid, so the right pointer moves to mid. When both are equal, it is impossible to determine which side the minimum is on, so the right boundary is decremented by one to safely reduce the search space without losing the minimum. The loop ends when lo equals hi, pointing to the minimum element.

C++ Code
#include <iostream>

#include <vector>

using namespace std;

 

int findMin(vector<int>& nums) {

    int lo = 0, hi = nums.size() - 1;

    while (lo < hi) {

        int mid = lo + (hi - lo) / 2;

        if (nums[mid] > nums[hi])

            // Minimum is in the right half

            lo = mid + 1;

        else if (nums[mid] < nums[hi])

            // Minimum is in the left half (including mid)

            hi = mid;

        else

            // nums[mid] == nums[hi]: cannot decide, shrink right

            hi--;

    }

    return nums[lo];

}

 

int main() {

    int n;

    cin >> n;

    vector<int> nums( n );

    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << findMin(nums);

}

Java Code
import java.util.*;

public class FindMinRotatedII {

    public static int findMin(int[] nums) {

        int lo = 0, hi = nums.length - 1;

        while (lo < hi) {

            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi])

                // Minimum is in the right half

                lo = mid + 1;

            else if (nums[mid] < nums[hi])

                // Minimum is in the left half (including mid)

                hi = mid;

            else

                // nums[mid] == nums[hi]: cannot decide, shrink right

                hi--;

        }

        return nums[lo];

    }

 

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] nums = new int[n];

        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

        System.out.println(findMin(nums));

    }

}

 

Input / Output Examples
Input

Output

nums = [1,3,5]

1

nums = [2,2,2,0,1]

0

nums = [3,3,1,3]

1

nums = [1,1,1,1,1]

1

nums = [4,5,6,7,0,1,4]

0

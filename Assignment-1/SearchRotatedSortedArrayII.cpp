#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] == target)
        {
            return true;
        }

        if(nums[left] == nums[mid] && nums[mid] == nums[right])
        {
            left++;
            right--;
        }

        else if(nums[left] <= nums[mid])
        {
            if(target >= nums[left] && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        else
        {
            if(target > nums[mid] && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    if(search(nums, target))
        cout << "True";
    else
        cout << "False";

    return 0;
}

#include <iostream>

int lower_bound(int* arr, int target, int size)
{
    int start = 0;
    int end = size;
    while(start < end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] < target) start = mid + 1;
        else end = mid;
    }
    return start;
}

int main()
{
    const int SIZE = 10;
    int arr[SIZE] = {1,2,3,4,4,4,4,4,4,5};
    int target = 4;
    std::cout << "first position of target is: " << lower_bound(arr, target, SIZE) << std::endl;
    return 0;
}


//                              Explanation Of The Algorithm

/*
🔍 What lower_bound actually does:
It returns first index i such that arr[i] >= target

🧠 Key Idea
    We are not searching for an exact value.
    we are searching for a BOUNDARY:
So the array is conceptually divided into two parts:
    LEFT --> values < target
    RIGHT --> values >= target
We want the first index of the RIGHT part.

⚙️ Algorithm Walkthrough
    while(start < end)
❗Why start < end (NOT <=)?
Because:
    We are shrinking to a single valid answer
    When start == end, we already found it -> stop

If you used <=, you'd risk:
    Infinite loop
    or skipping the answer

🔁 What happens in each step?
    int mid = start + (end - start) / 2;

Case 1:
    if(arr[mid] < target)
        start = mid + 1;

Why start = mid + 1 instead of start = mid ?
    if arr[mid] < target, then:
👉 mid is definitely in the LEFT part(bad zone)

So:
    mid cannot be the answer
    everything before mid also cannot be answer

✅ Move right:
    start = mid + 1

Case 2:
    else
        end = mid;

Why NOT mid - 1?
    If arr[mid] >= target, then:
👉 mid could be the answer
So we must NOT discard it
Instead:
    end = mid
This keeps mid in the search range.


🧩 Mental Model (VERY IMPORTANT)
Think:

"I am shrinking the range until only one valid candidate remains"

Not:

"I am checking every possible match"
*/
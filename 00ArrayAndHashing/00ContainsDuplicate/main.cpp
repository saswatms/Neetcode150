#include <bits/stdc++.h>

using namespace std;

// * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// ! Comparing each value with every other value.
// bool containsDuplicate(vector<int> &nums)
// { // ? Time Complexity = O(n^2), Space Complexity = O(1)
// for (int i = 0; i < nums.size(); ++i)
// {
// for (int j = i + 1; j < nums.size(); ++j)
// {
// if (nums[i] == nums[j])
// {
// return true;
// }
// }
// }
// return false;
// }

// ! First Sorting then Comparing each value with every adjacent value.
// bool containsDuplicate(vector<int> &nums)
// { // ? Time Complexity = O(nlog(n)), Space Complexity = O(1)
// sort(nums.begin(), nums.end());
// for (int i = 0; i < nums.size(); i++)
// if (nums[i] == nums[i + 1])
// return true;
// return false;
// }

// ! Uniquely storing each value in hash set then checking if it's repeated or not before updating hash set.
bool containsDuplicate(vector<int> &nums)
{ // ? Time Complexity = O(n), Space Complexity = O(n)
    unordered_set<int> S;
    for (int num : nums)
    {
        if (S.find(num) != S.end())
            return true;
        S.insert(num);
    }
    return false;
}

// ! This is not part of questions, this is sample Set code.
class Person;

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << "Contains Duplicate? " << containsDuplicate(nums) << endl;

    // Set Example
    set<Person, greater<>> Set = {{20, "John"}, {3, "Saswat"}, {18, "Vamp"}};
    for (auto &e : Set)
    {
        cout << e.age << " " << e.name << endl;
    }
    return 0;
}

// * References
/*
=> Set: [1](Unique values), [2](Ordered data)
Search, Insertion and Removal have logarithmic complexity O(log(n))
Internally implemented using Red-Black Tree.
If we wan't to store user defined data types(class, enums, structures), we'll have to provide compare functions.
we can pass the order like given below:
set<int, std::greater<>> for descending order, set<int> or set<int, std::less<>> for ascending order
|| --------------------------------------------------------------------------------------------------------------------------------------------- ||
=> Unordered_Set: [1](Unique values)
Search, Insertion and Removal have average constant complexity O(1)
Internally implemented using Hashing.
*/

class Person
{
public:
    float age;
    string name;
    // ! The below line is the compare function part.
    bool operator<(const Person &rhs) const { return age < rhs.age; } //? It's comparing on the basis of their age variable. (Ascending Operator) {It is Default}
    bool operator>(const Person &rhs) const { return age > rhs.age; } //? It's comparing on the basis of their age variable. (Descending Operator)
};

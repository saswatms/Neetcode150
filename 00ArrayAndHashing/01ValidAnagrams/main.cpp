#include <bits/stdc++.h>
using namespace std;

// * Given two strings s and t, return true if t is an anagram of s, and false otherwise. An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// ! Sort and compare both string.
// bool isAnagram(string s, string t)
// { // ? Time complexity = O(s*log(s)+t*log(t)) & Space complexity = O(1)
//     if (s.length() != t.length())
//         return false;
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] != t[i])
//         {
//             return false;
//         }
//     }
//     return true;
//     or
//     return s==t;
// }

// ! Put values in a hash maps, loop any string put the value in hash map if it comes on 's' remove if it comes in 't', in the end if hash map isn't empty return false.
// bool isAnagram(string s, string t)
// { // ? Time complexity = O(s) & Space complexity = O(s)
//     if (s.length() != t.length())
//         return false;
//     unordered_map<char, int> Map;
//     for (int i = 0; i < s.length(); i++)
//     {
//         Map[s[i]]++;
//         Map[t[i]]--;
//     }
//     for (auto i : Map)
//     {
//         if (i.second)
//             return false;
//     }
//     return true;
// }

// ! We can use an array because english alphabet has only 26 letters, then repeat what we've done above
bool isAnagram(string s, string t)
{ // ? Time complexity = O(s) & Space complexity = O(1) => Here's space complexity is constant of 26 letter that's why it's O(1)
    if (s.length() != t.length())
        return false;
    vector<int> count(26);
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (auto i : count)
    {
        if (i)
            return false;
    }
    return true;
}

int main()
{
    string s = "anagram", t = "nagaram";
    cout << "Is anagram valid? " << isAnagram(s, t) << endl;
    return 0;
}

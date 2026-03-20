#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool hasDuplicate(const vector<int> &a) {
  unordered_set<int> seen;
  seen.reserve(a.size()); // opcional: mejora rendimiento evitando rehashes
  for (int x : a) {
    auto res = seen.insert(x); // res es pair<iterator,bool>
    if (!res.second)
      return true; // second == false -> ya existía -> duplicado
  }
  return false;
}

int main() {
  vector<int> nums1 = {1, 3, 2, 1};
  vector<int> nums2 = {1, 2, 3, 4};
  vector<int> nums3 = {20, 30, 21, 46, 7, 8, 12, 1235, 12};

  cout << boolalpha; // imprime true/false en vez de 1/0

  cout << "nums1 tiene duplicado? " << hasDuplicate(nums1) << '\n';
  cout << "nums2 tiene duplicado? " << hasDuplicate(nums2) << '\n';
  cout << "nums3 tiene duplicado? " << hasDuplicate(nums3) << '\n';
  return 0;
}

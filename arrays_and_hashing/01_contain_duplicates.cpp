#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool hasDuplicate_set(const vector<int> &a) {
  unordered_set<int> seen;
  seen.reserve(a.size()); // opcional: mejora rendimiento evitando rehashes
  for (int x : a) {
    auto res = seen.insert(x); // res es pair<iterator,bool>
    if (!res.second)
      return true; // second == false -> ya existía -> duplicado
  }
  return false;
}

bool hasDuplicate_map(const vector<int> &a) {
  unordered_map<int, int> seen;
  seen.reserve(a.size());
  for (int x : a) {
    if (++seen[x] > 1)
      return true;
  }
  return false;
}

bool hasDuplicate_bruteForce(const vector<int> &a) {
  for (size_t x = 0; x < a.size(); ++x) {
    for (size_t j = x + 1; j < a.size(); ++j) {
      if (a[x] == a[j]) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  vector<int> nums1 = {1, 3, 2, 1};
  vector<int> nums2 = {1, 2, 3, 4};
  vector<int> nums3 = {20, 30, 21, 46, 7, 8, 12, 1235, 12};

  int select = 0;
  cout << "1)map\n2)set\n3)Brute Force\nSelect a number: ";
  cin >> select;
  cout << boolalpha; // imprime true/false en vez de 1/0

  auto runTest = [&](vector<int> &vec, int choice) {
    if (choice == 1)
      return hasDuplicate_map(vec);
    if (choice == 2)
      return hasDuplicate_set(vec);
    return hasDuplicate_bruteForce(vec);
  };

  cout << "nums1 duplciate?" << runTest(nums1, select) << "\n";
  cout << "nums2 duplicate?" << runTest(nums2, select) << "\n";
  cout << "nums3 duplicate?" << runTest(nums3, select) << "\n";

  return 0;
}

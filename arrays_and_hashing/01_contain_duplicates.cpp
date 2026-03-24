#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool hasDuplicate_set(
    const vector<int>
        &a) { // use '&' to reference a variable, avoid use more memory.
  unordered_set<int> seen; // unordered_set es un hash set, no mantiene orden
  seen.reserve(a.size());  // .reserve() useful to avoid rehashing, rehasing is
                           // when the compiler need to add more memory space to
                           // some data structure.
  for (int x : a) { // is the same (int x : a) than for (size_t i = 0; i <
                    // a.size(); ++i)
    auto res =
        seen.insert(x); // insert respond whit a object who have 2 properties,
                        // first is the value and second is a boolean that
                        // indicate if the value was inserted or not.
    if (!res.second)
      return true;
  }
  return false;
}

bool hasDuplicate_map(const vector<int> &a) {
  unordered_map<int, int> seen;
  seen.reserve(a.size());
  for (int x : a) {
    if (++seen[x] >
        1) // ++seen[x] is the same than seen[x] = seen[x] + 1, but is more
           // efficient because it avoid to access twice to the map.
      return true;
  }
  return false;
}

bool hasDuplicate_bruteForce(const vector<int> &a) {
  for (size_t x = 0; x < a.size();
       ++x) { // size_t is the type of integer who return size(), this type just
              // can be postive.
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
  cout << boolalpha; // configure cout to print boolean values as true/false
                     // instead of 1/0

  auto runTest = [&](vector<int> &vec,
                     int choice) { // labdafunction usseful to avoid use memory
                                   // when you use just 1 time a function;
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

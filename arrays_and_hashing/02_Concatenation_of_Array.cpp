#include <iostream>
#include <vector>

using namespace std;

// using reserve and insert
vector<int> getConcatenation_Reserve(vector<int> &nums) {
  vector<int> res = nums;
  res.reserve(2 * nums.size()); // initialize the capacity but not fill the
                                // vector with elements
  res.insert(res.end(), nums.begin(),
             nums.end()); // insert get three parameters: (1) position to insert
                          // (2) where start of the range (3) end of the range
  return res;
}

// using for loop , pre filling the vector
vector<int> getConcatenation_Manual(vector<int> &nums) {
  int n = nums.size();
  vector<int> res(2 * n);
  for (int i = 0; i < n; i++) {
    res[i] = nums[i];
    res[i + n] = nums[i];
  }
  return res;
}

void print(vector<int> v) {
  cout << "[ ";
  for (int x : v)
    cout << x << " ";
  cout << "]" << endl;
}

int main() {
  vector<int> datos = {1, 2, 1};
  int opcion = 0;

  cout << "1)  Reserve/Insert\n2) Manual (For)\nSelect: ";
  cin >> opcion;

  // Lambda function to execute the selected algorithm
  auto executeAlgo = [&](vector<int> &v) -> vector<int> {
    if (opcion == 1)
      return getConcatenation_Reserve(v);
    return getConcatenation_Manual(v);
  };

  vector<int> result = executeAlgo(datos);

  cout << "Result final: ";
  print(result);

  return 0;
}

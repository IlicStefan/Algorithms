#include <bits/stdc++.h>

using namespace std;


class PermutationsPrinter {
private:
  int n;
  vector<int> permutation;
  vector<bool> chosen;

  void printPermutation() {
    cout << "{ ";
    for(auto x : permutation)
      cout << x << " ";
    cout << "}\n";
  }

public:
  explicit PermutationsPrinter(int size_of_permutations)
    : n(size_of_permutations),
      chosen(size_of_permutations, false)
  {
    permutation.reserve(n);
  }
  
  void print() {
    if((int)permutation.size() == n) {
      printPermutation();
    }
    else {
      for(int i = 1; i <= n; i++) {
	if(chosen[i])
	  continue;
	chosen[i] = true;
	permutation.push_back(i);
	print();
	chosen[i] = false;
	permutation.pop_back();
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  PermutationsPrinter aPermutationsPrinter(n);

  aPermutationsPrinter.print();
  
  return 0;
}

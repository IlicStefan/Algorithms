#include <iostream>
#include <vector>

class PermutationsPrinter {
private:
  int n;
  std::vector<int> permutation;
  std::vector<bool> chosen;

  void printPermutation() {
    std::cout << "{ ";
    for(auto x : permutation)
      std::cout << x << " ";
    std::cout << "}\n";
  }

public:
  explicit PermutationsPrinter(int size_of_permutations)
    : n(size_of_permutations),
      chosen(size_of_permutations, false)
  {
    permutation.reserve(n);
  }
  
  void print() {
    if(static_cast<int>(permutation.size()) == n) {
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
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  PermutationsPrinter aPermutationsPrinter(n);

  aPermutationsPrinter.print();
  
  return 0;
}

#include <iostream>
#include <vector>
#include <numeric>

class UnionFind {
private:
  int n;
  std::vector<int> data;
  std::vector<int> size;
  int number_of_components;
  
  int root(int p) {
    int r = p;
    while(data[r] != r) {
      r = data[r];
    }

    while(data[p] != r) {
      data[p] = r;
      p = data[p];
    }

    return p;
  }
  
public:

  explicit UnionFind(int number_of_objects)
    : n(number_of_objects),
      data(n),
      size(n, 1),
      number_of_components(number_of_objects)
  {
    std::iota(std::begin(data), std::end(data), 0);
  }
  
  bool isConnected(int p, int q) {
    return root(p) == root(q);
  }

  void connect(int p, int q) {
    int rp = root(p);
    int rq = root(q);

    if(rp == rq)
      return;

    if(size[rp] >= size[rq]) {
      data[rq] = data[rp];
      size[rq] += size[rp];
    }
    else {
      data[rp] = data[rq];
      size[rp] += size[rq];
    }

    number_of_components--;
  }

  int getNumberOfComponents() {
    return number_of_components;
  }

};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  UnionFind uf(n);

  
  for(int p, q; std::cin >> p >> q;) {
    if(!uf.isConnected(p, q)) {
      std::cout << "Connecting (" << p << ", " << q << ") ";
      uf.connect(p, q);
    }

    std::cout << "Number of components: "
      << uf.getNumberOfComponents()
      << std::endl;
  }
  
  return 0;
}

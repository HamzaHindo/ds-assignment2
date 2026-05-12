#include <vector>

template <typename T> class Heap {
public:
  Heap();
  ~Heap();
  void insert(const T &value);
  T extract();
  T peek() const;
  bool isEmpty() const;
  int size() const;

private:
  std::vector<T> data;
  void heapifyUp(int index);
  void heapifyDown(int index);
  void swap(int i, int j);
};

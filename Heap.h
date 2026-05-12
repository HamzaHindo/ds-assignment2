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
  const std::vector<T> &getData() const;

private:
  std::vector<T> data;
  void heapifyUp(int index);
  void heapifyDown(int index);
  void swap(int i, int j);
};

template <typename T> Heap<T>::Heap() {}

template <typename T> Heap<T>::~Heap() {}

template <typename T> void Heap<T>::insert(const T &value) {
  data.push_back(value);
  heapifyUp(data.size() - 1);
}

template <typename T> T Heap<T>::extract() {
  T root = data[0];
  data[0] = data.back();
  data.pop_back();
  if (!data.empty()) {
    heapifyDown(0);
  }
  return root;
}

template <typename T> T Heap<T>::peek() const {
  return data[0];
}

template <typename T> bool Heap<T>::isEmpty() const {
  return data.empty();
}

template <typename T> int Heap<T>::size() const {
  return data.size();
}

template <typename T> const std::vector<T> &Heap<T>::getData() const {
  return data;
}

template <typename T> void Heap<T>::heapifyUp(int index) {
  if (index == 0) return;
  int parent = (index - 1) / 2;
  if (data[index] < data[parent]) {
    swap(index, parent);
    heapifyUp(parent);
  }
}

template <typename T> void Heap<T>::heapifyDown(int index) {
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < (int)data.size() && data[left] < data[smallest]) {
    smallest = left;
  }
  if (right < (int)data.size() && data[right] < data[smallest]) {
    smallest = right;
  }

  if (smallest != index) {
    swap(index, smallest);
    heapifyDown(smallest);
  }
}

template <typename T> void Heap<T>::swap(int i, int j) {
  T temp = data[i];
  data[i] = data[j];
  data[j] = temp;
}
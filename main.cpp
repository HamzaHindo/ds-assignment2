#include "EmergencyRoomController.h"
#include <iostream>
#include <queue>
#include <vector>

void testUsingHeap() {
  std::cout << "===== TEST USING CUSTOM HEAP =====" << std::endl;
  EmergencyRoomController erc;

  erc.addPatient({1, "Alice", 5, 1});
  erc.addPatient({2, "Bob", 3, 2});
  erc.addPatient({3, "Charlie", 8, 3});
  erc.addPatient({4, "David", 2, 4});
  erc.addPatient({5, "Eve", 10, 5});
  erc.addPatient({6, "Frank", 1, 6});
  erc.addPatient({7, "Grace", 7, 7});
  erc.addPatient({8, "Hank", 4, 8});
  erc.addPatient({9, "Ivy", 6, 9});
  erc.addPatient({10, "Jack", 9, 10});
  erc.addPatient({11, "Kate", 3, 11});
  erc.addPatient({12, "Leo", 8, 12});
  erc.addPatient({13, "Mia", 5, 13});
  erc.addPatient({14, "Noah", 2, 14});
  erc.addPatient({15, "Olivia", 10, 15});
  erc.addPatient({16, "Paul", 1, 16});
  erc.addPatient({17, "Quinn", 7, 17});
  erc.addPatient({18, "Rose", 4, 18});
  erc.addPatient({19, "Sam", 6, 19});
  erc.addPatient({20, "Tina", 9, 20});

  std::cout << "Total patients inserted: " << erc.countPatients() << std::endl;

  std::cout << "\n--- Treating patients in priority order ---" << std::endl;
  while (erc.countPatients() > 0) {
    Patient next = erc.nextPatient();
    std::cout << "Next: ID=" << next.id << " | Name=" << next.name
              << " | Severity=" << next.severity
              << " | Arrival=" << next.arrivalTime << std::endl;
    erc.treatPatient();
  }
  std::cout << "All patients treated.\n" << std::endl;
}

void testUsingPriorityQueue() {
  std::cout << "===== TEST USING STL PRIORITY_QUEUE =====" << std::endl;
  std::priority_queue<Patient, std::vector<Patient>, PatientComparator> pq;

  pq.push({1, "Alice", 5, 1});
  pq.push({2, "Bob", 3, 2});
  pq.push({3, "Charlie", 8, 3});
  pq.push({4, "David", 2, 4});
  pq.push({5, "Eve", 10, 5});
  pq.push({6, "Frank", 1, 6});
  pq.push({7, "Grace", 7, 7});
  pq.push({8, "Hank", 4, 8});
  pq.push({9, "Ivy", 6, 9});
  pq.push({10, "Jack", 9, 10});
  pq.push({11, "Kate", 3, 11});
  pq.push({12, "Leo", 8, 12});
  pq.push({13, "Mia", 5, 13});
  pq.push({14, "Noah", 2, 14});
  pq.push({15, "Olivia", 10, 15});
  pq.push({16, "Paul", 1, 16});
  pq.push({17, "Quinn", 7, 17});
  pq.push({18, "Rose", 4, 18});
  pq.push({19, "Sam", 6, 19});
  pq.push({20, "Tina", 9, 20});

  std::cout << "Total patients inserted: " << pq.size() << std::endl;

  std::cout << "\n--- Treating patients in priority order ---" << std::endl;
  while (!pq.empty()) {
    Patient next = pq.top();
    std::cout << "Next: ID=" << next.id << " | Name=" << next.name
              << " | Severity=" << next.severity
              << " | Arrival=" << next.arrivalTime << std::endl;
    pq.pop();
  }
  std::cout << "All patients treated.\n" << std::endl;
}

int main() {
  testUsingHeap();
  testUsingPriorityQueue();
  return 0;
}
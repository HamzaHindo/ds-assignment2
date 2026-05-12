
#include <string>

struct Patient {
  int id;
  std::string name;
  int severity;
  int arrivalTime;
};

// This Comparator will be used in Priority Queue for part two
// Priority: higher severity first, if equal then earlier arrival first
struct PatientComparator {
  bool operator()(const Patient &p1, const Patient &p2) {
    if (p1.severity != p2.severity) {
      return p1.severity < p2.severity;
    }
    return p1.arrivalTime > p2.arrivalTime;
  }
};

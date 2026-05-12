
#include <string>

enum Severity { Low = 1, lowMedium = 2, Medium = 3, MediumHigh = 4, High = 5 };

struct Patient {
  int id;
  std::string name;
  Severity severity;
  int arrivalTime;
};

struct PatientComparator {
  bool operator()(const Patient &p1, const Patient &p2) {
    if (p1.arrivalTime == p2.arrivalTime) {
      return p1.severity < p2.severity;
    }
    return p1.arrivalTime > p2.arrivalTime;
  }
};

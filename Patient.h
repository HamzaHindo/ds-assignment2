#include <string>
#include <iostream>
#include <iomanip>

struct Patient {
  int id;
  std::string name;
  int severity;
  int arrivalTime;

  bool operator<(const Patient &other) const {
    if (severity == other.severity) {
      return arrivalTime < other.arrivalTime;
    }
    return severity > other.severity;
  }

  bool operator>(const Patient &other) const {
    return other < *this;
  }
};

inline std::ostream &operator<<(std::ostream &os, const Patient &p) {
  os << std::left << std::setw(3) << p.id << "| " << std::setw(10) << p.name
     << "| " << std::setw(8) << p.severity << "| " << std::setw(6)
     << p.arrivalTime;
  return os;
}

struct PatientComparator {
  bool operator()(const Patient &p1, const Patient &p2) {
    if (p1.severity == p2.severity) {
      return p1.arrivalTime > p2.arrivalTime;
    }
    return p1.severity < p2.severity;
  }
};
#include "EmergencyRoomController.h"
#include <stdexcept>

void EmergencyRoomController::addPatient(const Patient &patient) {
  patientHeap.insert(patient);
}

void EmergencyRoomController::treatPatient() {
  if (patientHeap.isEmpty()) {
    throw std::runtime_error("No patients to treat");
  }
  patientHeap.extract();
}

Patient EmergencyRoomController::nextPatient() {
  if (patientHeap.isEmpty()) {
    throw std::runtime_error("No patients waiting");
  }
  return patientHeap.peek();
}

void EmergencyRoomController::updatePatientSeverity(int patientId,
                                                    int newSeverity) {
  std::vector<Patient> temp;
  Patient target;
  bool found = false;

  while (!patientHeap.isEmpty()) {
    Patient current = patientHeap.extract();
    if (current.id == patientId) {
      current.severity = newSeverity;
      target = current;
      found = true;
    } else {
      temp.push_back(current);
    }
  }

  if (found) {
    temp.push_back(target);
    for (const auto &patient : temp) {
      patientHeap.insert(patient);
    }
  }
}

void EmergencyRoomController::printWaitingPatients() const {
  std::cout << "ID | Name      | Severity | Arrival Time" << std::endl;
  std::cout << "---+-----------+----------+--------------" << std::endl;
  const auto &patients = patientHeap.getData();
  for (const auto &patient : patients) {
    std::cout << patient << std::endl;
  }
}

int EmergencyRoomController::countPatients() const {
  return patientHeap.size();
}
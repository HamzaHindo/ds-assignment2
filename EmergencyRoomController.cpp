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
                                                    Severity newSeverity) {
  throw std::runtime_error("Implementation missing `void "
                           "EmergencyRoomController::updatePatientSeverity(int "
                           "patientId, Severity newSeverity)`");
}

void EmergencyRoomController::printWaitingPatients() const {
  throw std::runtime_error("Implementation missing `void "
                           "EmergencyRoomController::printWaitingPatients() "
                           "const`");
}

int EmergencyRoomController::countPatients() const {
  return patientHeap.size();
}

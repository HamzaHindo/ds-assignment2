#include "Heap.h"
#include "Patient.h"
#include <iostream>

class EmergencyRoomController {
private:
  Heap<Patient> patientHeap;

public:
  void addPatient(const Patient &patient);
  void treatPatient();
  Patient nextPatient();
  void updatePatientSeverity(int patientId, int newSeverity);
  void printWaitingPatients() const;
  int countPatients() const;
};
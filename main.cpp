#include "EmergencyRoomController.h"
#include <iostream>

int main() {
  EmergencyRoomController erc;

  erc.addPatient({1, "Alice", Medium, 10});
  erc.addPatient({2, "Bob", High, 5});
  erc.addPatient({3, "Charlie", Low, 15});

  std::cout << "All waiting patients:" << std::endl;
  erc.printWaitingPatients();

  std::cout << "Next patient to treat: " << erc.nextPatient().name << std::endl;

  erc.treatPatient();
  std::cout << "Next patient to treat after treating one: "
            << erc.nextPatient().name << std::endl;

  erc.updatePatientSeverity(3, High);
  std::cout << "Next patient to treat after updating severity: "
            << erc.nextPatient().name << std::endl;

  std::cout << "All waiting patients:" << std::endl;
  erc.printWaitingPatients();
  return 0;
}

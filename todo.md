# Project TODO: Emergency Room Priority System (Heap)

## Overview
This project implements a hospital emergency room priority queue using a **custom max-heap** with `std::vector`. Patients are prioritized by:
1. **Higher severity first** (DESC)
2. **Earlier arrival first** (ASC) — tiebreaker

## ✅ Already Done
- [x] `Heap.h` — Template class **declared** (constructor, insert, extract, peek, isEmpty, size, heapifyUp/Down, swap)
- [x] `EmergencyRoomController.h` — All method signatures declared
- [x] `EmergencyRoomController.cpp` — Partially implemented:
  - `addPatient` — inserts into heap
  - `treatPatient` — extracts top
  - `nextPatient` — peeks top
  - `countPatients` — returns heap size
- [x] `Patient.h` — `Patient` struct, `Severity` enum (1–5), and `PatientComparator`
- [x] `main.cpp` — Basic demo with 3 patients

---

## 🛠 TODO List (Assign to teammate)

### 1. Implement Heap Methods (`Heap.h`)
**Priority: HIGH**
- Implement `Heap()` constructor and `~Heap()` destructor
- Implement `insert(const T &value)` — append to vector, then `heapifyUp`
- Implement `extract()` — swap root with last, pop back, `heapifyDown`, return old root
- Implement `peek() const` — return `data[0]` (top of heap)
- Implement `isEmpty() const` — check if `data.empty()`
- Implement `size() const` — return `data.size()`
- Implement `heapifyUp(int index)` — compare with parent, swap if higher priority, recurse up
- Implement `heapifyDown(int index)` — compare with children, swap with higher priority child, recurse down
- Implement `swap(int i, int j)` — swap two elements in `data`

> **Note:** `Heap.h` is a **template class**, so implementation must be in the header (or included at the bottom). You cannot separate `.cpp` for templates unless you explicitly instantiate them.

---

### 2. Fix Patient Comparator / Severity Range
**Priority: HIGH**
- Current `Severity` enum goes from `Low=1` to `High=5`
- Assignment requires **severity 1–10** → consider changing `Severity` to `int` or extending the enum
- Fix `PatientComparator` (in `Patient.h`) to match required priority:
  - **Primary:** Higher `severity` first (max-heap behavior)
  - **Secondary:** Lower `arrivalTime` first (tiebreaker)
- Ensure comparator is used correctly inside `Heap<T>` (or make `Heap` accept a comparator template parameter)

---

### 3. Finish EmergencyRoomController (`EmergencyRoomController.cpp`)
**Priority: HIGH**
- [ ] `updatePatientSeverity(int patientId, Severity newSeverity)`
  - Find patient by `id` inside `Heap<Patient>`
  - Update their `severity`
  - **Re-heapify** accordingly (check if need heapifyUp or heapifyDown)
  - ⚠️ This is tricky because heap is not a search structure; consider adding a lookup mechanism or rebuild heap after update
- [ ] `printWaitingPatients() const`
  - Print all patients in **level order** (i.e., vector order)
  - Display: `ID | Name | Severity | ArrivalTime`

---

### 4. Expand `main.cpp` for Part 2 Analysis
**Priority: MEDIUM**
- Insert **20+ patients** with random/varied severity and arrival times
- Add a second section using **`std::priority_queue<Patient, vector<Patient>, PatientComparator>`**
- Compare:
  - Time complexity of insert / extract
  - Ease of use (manual heap vs STL)
  - Code readability and maintainability
- Print clear separators and labels in output

---

### 5. Write Report / Documentation
**Priority: MEDIUM**
Create a document (e.g., `REPORT.md` or include in `readme.md`) covering:
- [ ] **How heap works:** Explain heap property, heapifyUp/Down, vector representation
- [ ] **Why it's efficient:** $O(\log n)$ insert and extract, $O(1)$ peek, vs $O(n)$ for unsorted array or $O(\log n)$ for balanced BST
- [ ] **Comparison with other structures:**
  - Array / Linked List: $O(n)$ insert or extract
  - BST: $O(\log n)$ but more complex, not cache-friendly
  - `std::priority_queue`: easier but less flexible (no update by ID)
- [ ] **Sample Run Output:** Paste terminal output from `main.cpp`

---

## 🚧 Constraints & Warnings
- **NOT allowed to use STL `priority_queue` in Part 1** (the core `Heap` implementation)
- `Heap` uses `std::vector<Patient>` for internal storage
- `EmergencyRoomController` should be the only interface used in `main.cpp`
- Make sure to handle empty heap cases (throw or print warnings)

---

## 💡 Optional Enhancements
- Add `displayAll(int &count)` method to `Heap` if needed for the report
- Add timestamps or an `arrivalTime` counter generator in `main.cpp`
- Add error handling / input validation
- Unit tests for heap operations

---

## 📝 Files to Modify
| File | What to do |
|------|-----------|
| `Heap.h` | Add implementations to all declared methods |
| `Patient.h` | Adjust `Severity` range and fix `PatientComparator` |
| `EmergencyRoomController.cpp` | Implement `updatePatientSeverity` and `printWaitingPatients` |
| `main.cpp` | Expand to 20+ patients, add STL comparison, clean output |
| `readme.md` | Write full report and sample run |

---

## Questions?
Ask the team lead if anything is unclear — especially around:
- How to search/update inside a heap (by patient ID)
- Whether to keep `Severity` as enum or switch to `int`

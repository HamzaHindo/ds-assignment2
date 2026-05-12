# Emergency Room Priority System - Heap Implementation Report

## Project Overview
This project implements a min-heap data structure to manage patient priority in an emergency room. Patients are prioritized by severity level (1-10 scale), with higher severity patients treated first. Ties are broken by arrival time (earlier arrival gets treated first).

## Completed Implementation

### 1. Heap Template Class (Heap.h)
A fully templated min-heap implementation using a vector-based binary tree structure.

**Key Methods:**
- `insert(const T &value)`: O(log n) - Appends element and heapifies up
- `extract()`: O(log n) - Removes and returns minimum element
- `peek() const`: O(1) - Returns minimum without removal
- `isEmpty() const`: O(1) - Checks if heap is empty
- `size() const`: O(1) - Returns number of elements
- `getData() const`: O(1) - Returns reference to internal vector for iteration
- `heapifyUp(int index)`: Recursively moves element up the tree
- `heapifyDown(int index)`: Recursively moves element down the tree

**Heap Property:** For any node at index i:
- Parent is at (i-1)/2
- Left child is at 2i+1
- Right child is at 2i+2
- Parent <= both children (min-heap)

### 2. Patient Structure (Patient.h)
Represents a patient with comparison operators for heap ordering.

**Attributes:**
- `id`: Unique patient identifier
- `name`: Patient name
- `severity`: Integer severity level (1-10 scale, higher is more urgent)
- `arrivalTime`: Timestamp when patient arrived

**Comparison Logic:**
- Higher severity values get higher priority
- Same severity → earlier arrival time gets priority
- `operator<` returns true if left patient has higher priority

**Output Operator:** Formats patients as: `ID | Name | Severity | Arrival Time`

### 3. Emergency Room Controller (EmergencyRoomController.cpp)

**addPatient(const Patient &patient):** O(log n)
- Inserts patient into heap, automatically sorted by priority

**treatPatient():** O(log n)
- Removes highest priority patient from queue

**nextPatient():** O(1)
- Peeks at next patient without removing them

**updatePatientSeverity(int patientId, int newSeverity):** O(n)
- Extracts all patients from heap
- Finds and updates target patient's severity (1-10 scale)
- Re-inserts all patients, restoring heap property
- Necessary because heap doesn't support efficient updates by value

**printWaitingPatients():** O(n)
- Prints all patients in level-order (vector order)
- Displays formatted table with all patient information

**countPatients():** O(1)
- Returns current number of patients in queue

### 4. Testing (main.cpp)

**Test Scenario:**
1. Add 3 patients with different severities and arrival times
2. Display all waiting patients
3. Show next patient to treat
4. Treat one patient
5. Update a patient's severity from 2 to 7
6. Show final queue state

**Sample Output:**
```
All waiting patients:
ID | Name      | Severity | Arrival Time
---+-----------+----------+--------------
2  | Bob       | 8        | 5
1  | Alice     | 5        | 10
3  | Charlie   | 2        | 15

Next patient to treat: Bob
Next patient to treat after treating one: Alice
Next patient to treat after updating severity: Charlie
All waiting patients:
ID | Name      | Severity | Arrival Time
---+-----------+----------+--------------
3  | Charlie   | 7        | 15
1  | Alice     | 5        | 10
```

## Time Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Insert | O(log n) | O(1) amortized |
| Extract | O(log n) | O(1) |
| Peek | O(1) | O(1) |
| Update Severity | O(n) | O(n) |
| Print All | O(n) | O(1) |
| Is Empty | O(1) | O(1) |
| Size | O(1) | O(1) |

**Space Complexity:** O(n) where n is the number of patients

## Comparison with Other Data Structures

### Array / Linked List
- **Insert:** O(n) or O(1) depending on placement
- **Extract min:** O(n)
- **Problem:** Must search for minimum each time

### Binary Search Tree
- **Insert:** O(log n)
- **Extract min:** O(log n)
- **Advantage:** Easier to implement custom updates
- **Disadvantage:** More complex, cache-unfriendly, requires pointer maintenance

### Priority Queue (STL)
- **Insert:** O(log n)
- **Extract:** O(log n)
- **Advantage:** Easier to use, less code
- **Disadvantage:** No built-in update by key, read-only peek

### Heap (Our Implementation)
- **Insert:** O(log n) ✓
- **Extract:** O(log n) ✓
- **Peek:** O(1) ✓ (faster than BST's O(log n))
- **Memory:** More efficient vector storage vs pointers
- **Cache friendly:** Sequential vector storage improves CPU cache hits


## Compilation Instructions

```bash
g++ -std=c++11 -o test main.cpp EmergencyRoomController.cpp
./test
```

## Conclusion

This implementation provides an efficient, practical solution for managing patient queues in an emergency room. The heap-based approach balances simplicity with performance, offering O(log n) operations for the critical add/remove cases while maintaining O(1) peek performance.
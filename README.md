# 📋 Online Complaint Management System

> A console-based complaint tracking application built in **C++** using parallel arrays, structured functions, and safe input handling — no classes or enums required.

---

## 📌 Overview

This project implements a simple yet complete **Online Complaint Management System** as part of **Case Study 130**. It allows users to register complaints, track their status, update resolutions, and view records — all through an interactive terminal menu.

---

## ✨ Features

| Feature | Description |
|---|---|
| 📝 Register Complaint | Save name, category, and description with an auto-assigned ID |
| 📋 View All Complaints | List every complaint with current status |
| 🔍 View by ID | Look up full details of a specific complaint |
| 🔄 Update Status | Change status through Pending → In Progress → Resolved → Closed |
| 🛡️ Input Validation | Handles non-integer input without crashing or infinite loops |
| 🔒 Closed Guard | Prevents re-updating complaints that are already closed |

---

## 🖥️ Sample Output

```
============================================
   ONLINE COMPLAINT MANAGEMENT SYSTEM
============================================

----- MENU -----
1. Register Complaint
2. View All Complaints
3. View Complaint by ID
4. Update Status
5. Exit
Enter Choice: 1

--------------------------------------------
        REGISTER NEW COMPLAINT
--------------------------------------------
Enter Your Name        : Alice
Enter Category         : Billing
Enter Description      : Charged twice for the same order.

  Complaint Registered Successfully!
  Complaint ID : 1001
  Status       : Pending
--------------------------------------------
```

---

## 🗂️ Project Structure

```
complaint-management/
│
├── complaint_management.cpp    # Main source file (all logic)
└── README.md                   # This file
```

---

## ⚙️ How to Compile & Run

### Using g++ (Linux / macOS / MinGW)
```bash
g++ -o cms complaint_management.cpp -std=c++17
./cms
```

### Using Visual Studio (Windows)
1. Create a new **Empty C++ Project**
2. Add `complaint_management.cpp` to the project
3. Go to **Project → Properties → C/C++ → Language**
4. Set **C++ Language Standard** to `ISO C++17`
5. Set **Precompiled Headers** to `Not Using Precompiled Headers`
6. Press `Ctrl+F5` to build and run

---

## 🔁 Program Flow

```
START
  │
  ▼
Display Menu
  │
  ▼
Read Choice (with input validation)
  │
  ├── 1 → Register Complaint
  │         ├── Validate fields not empty
  │         └── Save to arrays, status = "Pending"
  │
  ├── 2 → View All Complaints (loop through arrays)
  │
  ├── 3 → View by ID (findIndex → print details)
  │
  ├── 4 → Update Status
  │         ├── findIndex → check not Closed
  │         ├── Select new status (1–4)
  │         └── Optional resolution note
  │
  └── 5 → Exit → END
```

---

## 🧠 Concepts Used

- **Parallel arrays** — each index represents one complaint across multiple arrays
- **Functions** — each operation is isolated in its own function
- **`cin` error recovery** — `cin.clear()` + `cin.ignore()` prevents infinite loops on bad input
- **`getline()`** — reads full sentences including spaces
- **Linear search** — `findIndex()` scans the ID array to locate a complaint
- **Status flow** — plain strings (`"Pending"`, `"In Progress"`, `"Resolved"`, `"Closed"`) managed with `if/else if`

---

## ⚠️ Known Limitation

The system stores up to **100 complaints** per session (defined by `const int MAX = 100`). Data is **not saved to a file** — all records are lost when the program exits.

---

## 🐛 Bugs Fixed

| Bug | Cause | Fix |
|---|---|---|
| Infinite loop on letter input | `cin` enters fail state | `readInt()` with `cin.clear()` + `cin.ignore()` |
| Empty complaint registered | No field validation | Check `.empty()` before saving |
| Closed complaint re-updated | No status guard | Block update if `status == "Closed"` |
| 9 VS compiler errors | `count` clashes with `std::count` | Renamed to `complaintCount` |

---

## 📚 Learning Outcomes

- Understanding service request workflows in software
- Applying structured programming without OOP
- Implementing safe and robust terminal input handling
- Managing state using arrays and conditional logic

---

## 👤 Author

**Case Study 130** — C++ Programming Assignment  
*Object-Oriented / Structured Programming Course*

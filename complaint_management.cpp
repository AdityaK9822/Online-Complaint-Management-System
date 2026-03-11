#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

int    ids[MAX];
string names[MAX];
string descriptions[MAX];
string categories[MAX];
string statuses[MAX];
string resolutions[MAX];
int    complaintCount = 0;
int    nextId = 1001;

void divider() {
    cout << "--------------------------------------------\n";
}

// ── Safe integer input: clears cin on bad input ───────
int readInt() {
    int val;
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  Invalid input. Enter a number: ";
    }
    return val;
}

int findIndex(int id) {
    for (int i = 0; i < complaintCount; i++) {
        if (ids[i] == id) return i;
    }
    return -1;
}

void registerComplaint() {
    if (complaintCount >= MAX) {
        cout << "System is full. Cannot register more complaints.\n";
        return;
    }

    divider();
    cout << "        REGISTER NEW COMPLAINT\n";
    divider();

    cin.ignore();

    cout << "Enter Your Name        : ";
    getline(cin, names[complaintCount]);

    cout << "Enter Category         : ";
    getline(cin, categories[complaintCount]);

    cout << "Enter Description      : ";
    getline(cin, descriptions[complaintCount]);

    // Validate: reject empty inputs
    if (names[complaintCount].empty() || categories[complaintCount].empty() || descriptions[complaintCount].empty()) {
        cout << "\n  [!] All fields are required. Complaint not registered.\n";
        divider();
        return;
    }

    ids[complaintCount]         = nextId++;
    statuses[complaintCount]    = "Pending";
    resolutions[complaintCount] = "";

    cout << "\n  Complaint Registered Successfully!\n";
    cout << "  Complaint ID : " << ids[complaintCount] << "\n";
    cout << "  Status       : " << statuses[complaintCount] << "\n";

    complaintCount++;
    divider();
}

void viewAll() {
    divider();
    cout << "           ALL COMPLAINTS\n";
    divider();

    if (complaintCount == 0) {
        cout << "No complaints registered yet.\n";
        divider();
        return;
    }

    for (int i = 0; i < complaintCount; i++) {
        cout << "ID          : " << ids[i] << "\n";
        cout << "Name        : " << names[i] << "\n";
        cout << "Category    : " << categories[i] << "\n";
        cout << "Description : " << descriptions[i] << "\n";
        cout << "Status      : " << statuses[i] << "\n";
        if (resolutions[i] != "")
            cout << "Resolution  : " << resolutions[i] << "\n";
        divider();
    }
}

void viewById() {
    divider();
    cout << "        VIEW COMPLAINT DETAILS\n";
    divider();

    cout << "Enter Complaint ID: ";
    int id = readInt();

    int i = findIndex(id);
    if (i == -1) {
        cout << "  [!] Complaint ID " << id << " not found.\n";
        divider();
        return;
    }

    cout << "ID          : " << ids[i] << "\n";
    cout << "Name        : " << names[i] << "\n";
    cout << "Category    : " << categories[i] << "\n";
    cout << "Description : " << descriptions[i] << "\n";
    cout << "Status      : " << statuses[i] << "\n";
    if (resolutions[i] != "")
        cout << "Resolution  : " << resolutions[i] << "\n";
    divider();
}

void updateStatus() {
    divider();
    cout << "        UPDATE COMPLAINT STATUS\n";
    divider();

    cout << "Enter Complaint ID: ";
    int id = readInt();

    int i = findIndex(id);
    if (i == -1) {
        cout << "  [!] Complaint ID " << id << " not found.\n";
        divider();
        return;
    }

    // Prevent updating a closed complaint
    if (statuses[i] == "Closed") {
        cout << "  [!] This complaint is already Closed and cannot be updated.\n";
        divider();
        return;
    }

    cout << "Current Status: " << statuses[i] << "\n\n";
    cout << "Select New Status:\n";
    cout << "  1. Pending\n";
    cout << "  2. In Progress\n";
    cout << "  3. Resolved\n";
    cout << "  4. Closed\n";
    cout << "Choice: ";

    int choice = readInt();
    cin.ignore();

    if      (choice == 1) statuses[i] = "Pending";
    else if (choice == 2) statuses[i] = "In Progress";
    else if (choice == 3) statuses[i] = "Resolved";
    else if (choice == 4) statuses[i] = "Closed";
    else {
        cout << "  [!] Invalid choice. Status not changed.\n";
        divider();
        return;
    }

    if (choice == 3 || choice == 4) {
        cout << "Enter Resolution Note (press Enter to skip): ";
        getline(cin, resolutions[i]);
    }

    cout << "\n  Status Updated Successfully!\n";
    cout << "  New Status : " << statuses[i] << "\n";
    divider();
}

int main() {
    cout << "============================================\n";
    cout << "   ONLINE COMPLAINT MANAGEMENT SYSTEM\n";
    cout << "============================================\n";

    int choice;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Register Complaint\n";
        cout << "2. View All Complaints\n";
        cout << "3. View Complaint by ID\n";
        cout << "4. Update Status\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";

        choice = readInt();

        if      (choice == 1) registerComplaint();
        else if (choice == 2) viewAll();
        else if (choice == 3) viewById();
        else if (choice == 4) updateStatus();
        else if (choice == 5) cout << "\nGoodbye!\n";
        else                  cout << "  [!] Invalid option. Try again.\n";

    } while (choice != 5);

    return 0;
}
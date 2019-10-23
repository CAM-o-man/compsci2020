#include "Student.h"
#include "Class.h"
#include <iostream>
#include <string>

using namespace std;
/*
LAST KNOWN DEBUG OUTPUT:
'HonourRoll.exe' (Win32): Loaded 'C:\compsci2020\HonourRoll\Debug\HonourRoll.exe'. Symbols loaded.
'HonourRoll.exe' (Win32): Loaded 'C:\Windows\SysWOW64\ntdll.dll'.
'HonourRoll.exe' (Win32): Loaded 'C:\Windows\SysWOW64\kernel32.dll'.
'HonourRoll.exe' (Win32): Loaded 'C:\Windows\SysWOW64\KernelBase.dll'.
'HonourRoll.exe' (Win32): Loaded 'C:\Windows\SysWOW64\msvcp140d.dll'.
'HonourRoll.exe' (Win32): Loaded 'C:\Windows\SysWOW64\vcruntime140d.dll'.
'HonourRoll.exe' (Win32): Loaded 'C:\Windows\SysWOW64\ucrtbased.dll'.
The thread 0x1b38 has exited with code 0 (0x0).
The thread 0x4a98 has exited with code 0 (0x0).
The thread 0x152c has exited with code 0 (0x0).
Exception thrown: read access violation.
**this** was 0x9AC9906C.

The program '[19088] HonourRoll.exe' has exited with code 0 (0x0).

LAST KNOWN COMPILER OUTPUT:
1>------ Build started: Project: HonourRoll, Configuration: Debug Win32 ------
1>Source.cpp
1>C:\compsci2020\HonourRoll\HonourRoll\Source.cpp(60,22): warning C4838: conversion from 'int' to 'unsigned int' requires a narrowing conversion
1>HonourRoll.vcxproj -> C:\compsci2020\HonourRoll\Debug\HonourRoll.exe
1>Done building project "HonourRoll.vcxproj".
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========

*/



bool checkRoll(Student s) { //FIXME: Exception thrown: read access violation. \n **this** was 0x9AC9906C
	unsigned int count = s.getClassCount(); //probable location of above error. Perhaps the error comes from passing a reference as an object to function?
	if (!(count >= 5 && count <= 8)) {
		return false;
	}
	unsigned int avg = s.getAvg();
	if (!(avg >= 90)) {
		return false;
	}
	return true;
}

int main() {
	cout << "Welcome, student! Please enter your full name." << endl;
	string name;
	cin.ignore();
	getline(cin, name);
	Student stud = Student(name);
	retry:
	cout << "Welcome, student! Please enter the number of courses you are taking." << endl;
	int coursenum;
	cin >> coursenum;
	if (cin.fail()) {
		cin.clear();
		cout << "That's not a number. Please try again." << endl;
		goto retry;
	}
	if (coursenum > 8) {
		cout << "Hey! What are you trying to pull?" << endl;
		cout << "That's not a legal number of courses!" << endl;
		goto retry;
	}
	unsigned int tmpgrade;
	string tmpname;
	for (int i = 0; i < coursenum; i++) {
		cout << "Please enter the name of your course." << endl;
		cin.ignore();
		getline(cin, tmpname);
		cout << "Now, please enter your grade in said course." << endl;
		cin >> tmpgrade;
		if (cin.fail()) {
			cin.clear();
			cout << "That's not a number. Please try again." << endl;
			i--;
			continue;
		}
		if (tmpgrade > 100) {
			cout << "That's not a valid grade. Please try again." << endl;
			i--;
			continue;
		}
		Class newclass = { tmpgrade, tmpname };
		stud.addClass(newclass);
	}

	if (checkRoll(stud)) {
		cout << "Congratulations, " << stud.getName() << " you have made the honour roll!" << endl;
	} else {
		cout << "Unfortunately, " << stud.getName() << ", you have not made the honour roll." << endl;
	}
	return 0;
}
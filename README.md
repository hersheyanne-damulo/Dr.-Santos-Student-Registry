Student Registry System
This is a C program I built for managing student records. It’s a console-based application that helps keep track of student details like ID, Name, Major, GPA, and total credits.

About the Project
I created this to practice using structs, arrays, and basic menu-driven control flow in C. It’s a handy way to store and look up data for up to 10 students at a time.

How it Works
When you run the program, it gives you a simple menu where you can:

Add Students: Enter data for as many students as you want (up to the capacity limit).

Display All: View a clean table of everyone currently in the registry.

Search:

Find someone quickly by their ID.

List students who hit a certain GPA target.

See everyone under a specific Major.

Getting Started
To run this on your own machine, you just need a C compiler:

Compile the code:

Bash
gcc -o registry your_filename.c
Run it:

On Windows: registry.exe

On Mac/Linux: ./registry

Notes
The current limit is set to 10 students (MAX_STUDENTS).

Since this is a simple in-memory program, the data will reset every time you close the application.

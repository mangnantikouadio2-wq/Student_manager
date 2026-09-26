# Student Manager Program

A simple student manager command-line program written in C.

## Features

- Add and remove students
- Add and remove students' marks
- Modify students' names and marks
- Calculate students' average
- Calculate the class average
- Sort students by name
- Sort students by average
- Save the student list as a CSV file
- Load the CSV file to continue managing the data

## Project structure

```text
student_manager/
├── loader.c    # handle loading and saving features
├── main.c      # provide the CLI interactions
├── README.md
├── stats.c     # handle statistical calculationds
├── student.h   # header
├── students.c  # handle student features
└── todo.md     # the project specifications
```

## How it works

A student is represented as a structure containig their name, marks, average and number of ratings. The program works on a list of student elements by adding,
removing, or sorting them.
The sort algorithm implemented is a merge sort algorithm as it offers a good time complexity.
The student list can be sorted by names or by averages and only ascending order is supported for now.
The CLI engine works by interacting with the user and calling the appropriate feature to perform the actions wanted by the user.
After the job is done, the data is saved in a CSV file called "student.csv"(this is an arbitrary name, the ability to specify a file name is not supported yet)
at the first run of the program.
On the second and subsequent runs, the saved CSV is loaded so that the user can continue performing the actions they want, this provides data persistence.<br />
<em>PS: Note that the program can load any CSV file that matches the format it supports on subsequent runs, you just have to change the CSV name in main.c before
compiling the program</em>.

## Future Improvements

- Sort in decreasing order
- Let the user decide of the name of the saved file
- Display the status of the list
- Provide a graphical interface

# cmd-student-database-system
Object Oriented Programming - SCS1209<br/>

### Problem
A program is required that will do some processing of student records such as awarding grades
and displaying various statistical summaries. The subject data is stored in a file on a subject by
subject basis, each subject containing details of students enrolled and mark received. The
problem is to be solved using an object oriented approach.<br/>
### Description of Class and its functionality
The subject data is stored on a file (subjdata.txt) in the format given below. The subject data
will need to be maintained by your program in an array that is to be loaded into main memory
when the program first starts. Data needs to be kept sorted by student ID within each subject.
The subject class must have operations to provide the functionality as described on the
following. The decisions with regard to which members should be private or public, used of
friend functions, and how functions are to be implemented is left to you.
When the program starts it should automatically read the data stored in subjdata.txt into an
array of objects of the type described above into main memory. The program should
automatically calculate and store a grade for each student (on a subject by subject basis)
according to the following:<br/><br/>
`x = numeric score Grade`<br/>
`x < 30 F`<br/>
`30 <= x < 40 D`<br/>
`40 <= x < 55 C`<br/>
`55 <= x < 70 B`<br/>
`70 <= x A`<br/>

The array used to store the student details for each subject should be sorted to allow more
efficient searching to be effected. After loading the file into memory and allocating grades your
program should display a menu that has the following options:<br/>

1. Display Subject
2. Display Student
3. Display Subject Summary
4. Save Summaries
5. Exit Program<br/>

Option One (1) is selected when the user wants to display a specific subject’s details. The
user is prompted to enter a 7 character subject code that is searched for in the array. If found,
all details of that subject are displayed (i.e. Student IDs, Marks, Grades), or alternatively an
error message displayed. These details should be held on the screen until the user presses a key
to continue, at which point the menu is to be redisplayed.<br/>

Option two (2) is selected when the user wants to display a single student’s details. The user
is prompted to enter a student number that is searched for in each of the subjects. The first two
digits of the student number represents last two digits of the year. Details of results in each
subject should be displayed if the student is found or an error message displayed. These details
should be held on the screen until the user presses a key to continue, at which point the menu
is to be redisplayed.<br/>

Option three (3) is selected when the user wants to display the summary of details from a
specific subject. The user is prompted to enter a subject code that is searched for in the array.
If found, a listing indicating the average mark, Standard deviation and number of each grade
allocated is displayed. These details should be held on the screen until the user presses a key to
continue, at which point the menu is to be redisplayed.<br/>

Option four (4) is selected when the user wishes to save on disk the summaries of all subjects.
The details are to be saved in the file (summdata.txt). Refer the following example which
indicates the format of the file.<br/>

`SCS1201 50 A 15.4% B 17.2% C 32.0% D 19.8% E 15.6%`
`…….`<br/>
`…….`<br/>

There should be a single space between each of the values on each line. The data shown here
corresponds to the example shown indicating the format of the input file.<br/>

Option five (5) is selected when the user wishes to exit the program.<br/>
Constant values and file format<br/>

The following declarations need to be included in your program:

`cons int MAXSUBJECTS = 10`<br/>
`cons int MAXSTUDENTS = 100`

So that you know how to read the data from the file subjdata.txt the following format has been
adopted:<br/>

`SCS1201 50`<br/>
`17000001 23`<br/>
`17000002 43`<br/>
`…….`<br/>
`…….`<br/>
`SCS1202 45`<br/>
`17000002 56`<br/>
`17000003 65`<br/>
`…….`<br/>
`…….`<br/>

The following should be noted in reference to the file structure depicted.<br/>
The first data item is the subject code (7 characters), the next data item on the same line
indicates the number of students in that subject (3 digits) and the following n lines indicates the
student number (8 digits) and the raw mark (out of 100) received.

# **CS201 – Spring 2021-2022**

**Take-Home Exam 2**

**Due April 17**** th****, Sunday, 23:55 (Sharp Deadline)**

**Introduction**

The aim of this homework is to practice on functions and if-else statements.

**Description**

In this homework, you will write a C++ program that calculates the calories the user has burned, compares it to their goal, and recommends exercises depending on how far they are from their goal.

The user will first input his/her name in the main function of your program. Other inputs will be asked in a different function, where a second prompt will be received that wants the user to enter his/her weight in terms of kilograms. Then, the user will be prompted to enter the average speed and how many minutes (s)he spent walking, running, and cycling in a week, respectively. The last input will be how many calories the user aims to burn in that week. All in these prompts, your program should refer to the user with his/her name.

After the inputs are completed, in another function, your program will check whether these inputs are valid or not. The weight, speed and minute inputs have some predefined ranges that they are supposed to be in. If they are out of range, your program should display certain messages. The ranges and messages are given below:

| **Range** | **Message** |
| --- | --- |
| weight \< 30 | Weight out of range! |
| --- | --- |
| speed \< 4 OR speed \> 30 | Speed out of range! |
| minute \< 0 OR minute \> 2000 | Minute out of range! |

Note that the order of the input checks is important. Firstly, weight should be checked. If it is out of range, you should not continue with the calculations. If weight is valid, then the speed should be checked. Again, if it is out of range, then your program should not continue with the calculations. If speed is valid, then the minute should be checked. If all of them are valid, only then your program should proceed to the calculations (HINT: Use if-else statements). Also, note that you should first check the inputs for walking, then running, then cycling.

After the input check is done, your program should continue with the calculations in a separate function. In that function, you should first calculate how many calories have been burned for each exercise. For that, first you should determine the MET values of each exercise, which are as indicated in the table below.

| **Exercise** | **Speed** | **MET** |
| --- | --- | --- |
| Walking | \>= 4, \< 6.5 | 4 |
| Walking | \>= 6.5 | 6.5 |
| Running | \>=4, \< 11 | 9 |
| Running | \>= 11 | 12.5 |
| Cycling | \>= 4, \< 20 | 6 |
| Cycling | \>= 20, \< 25 | 8 |
| Cycling | \>= 25 | 10.5 |

You should also have a separate function to determine the MET values. This function should determine the MET values using if-else statements and at the end, it should return the corresponding MET value for a given exercise.

After all the MET values for all exercises are determined, in the function where your program is supposed to do all the calculations, you will calculate how many calories have been burned for each exercise.

**calorie burn = weight x MET**

The above formula gives the calorie burn for a specific exercise with a given MET value for one hour. The important point here is that your program will get the number of minutes the user spent on an exercise. So, after you have calculated the calorie burn for an hour, you need to convert it to one minute, and then multiply that with the number of minutes that was given as input. Then, your program should sum all the calorie burns to get the total and afterwards, it should get the difference between the goal calories and total calories.

After everything is calculated, your program will make use of another function. This function will be used to display the output to the user. Firstly, your program should display the calorie burn separately for each exercise, and then it should display the total calorie burn. Thereafter, what your program should display depends on the goal and the total calorie values.

If the goal is the same as the total, then your program should print the following:

**"Congratulations! You have reached your goal!"**

If the total is greater than the goal, then your program should print the following, where the bold and italicized "_ **difference** _" will be calculated by your program:

**"You have surpassed your goal! You can eat something worth** _ **difference** _ **calories :)"**

If the goal is greater than the total, then your program should print the following, where the bold and italicized _ **variables** _ will be calculated by your program:

**"You did not reach your goal by** _ **difference** _ **calories.**

**You need to walk** _ **minuteCalculation** _ **minutes more to reach your goal or,**

**You need to run** _ **minuteCalculation** _ **minutes more to reach your goal or,**

**You need to do cycling** _ **minuteCalculation** _ **minutes more to reach your goal."**

All of steps described above should also be done again for a second user. The functions are explained more in detail below.

Your take-home exams will be automatically graded using GradeChecker, so it is very important to satisfy the exact same output given in the sample runs. You can utilize GradeChecker ([http://learnt.sabanciuniv.edu/GradeChecker/](http://learnt.sabanciuniv.edu/GradeChecker/)) to check whether your implementation is working in the expected way. To be able to use GradeChecker, you should upload all of your files used in the take-home exam ( **only** _your\_main\_cpp_ file for this take-home exam). Additionally, you should submit all of your files to SUCourse ( **only** _your\_main\_cpp_ file for this take-home exam) **without zipping** them. **Just a reminder, you will see a character ¶ which refers to a newline in your expected output.**

**The name of your main source (cpp) file should be in the expected format:**"SUCourseUsername\_THEnumber.cpp" (all lowercase letters). Please check the submission procedures of the take-home exam, which are listed at the end of this document.

**Use of Functions (EXTREMELY IMPORTANT)**

**You have to follow the specifications below for function declaration and callings. The grading criteria will include proper use of these parametric functions. Do NOT use any global variables (variables defined outside the functions) to avoid parameter use. Unnecessary code duplication will cause grade reduction as well.**

In the first homework, you were not supposed to implement any functions. However, in this homework you are expected to (actually you have to) use some function(s). The guidance about using functions in this homework is below.

A total of five user-defined functions (other than the main) must be implemented in this homework. On top of these functions, you may of course use other functions, if you want. In the main function, your program will ask the name of the user, and then call the _ **getInput** _ function. After that, your program will ask again for a second user's name, and call the _ **getInput** _ function again for that user. The function explanations are stated as below:

1. _ **getInput** _ **:** A void function that takes _username_ as its only parameter, and asks the user for their weight, speed and minutes spent on three exercises (walking, running, cycling), and weekly calorie burn goal. This function will call the _ **inputCheck** _function in if-else statements, and then call the function _ **computeResults** _if _ **inputCheck** _returns true for all arguments.

1. _ **inputCheck** _ **:** A non-void function (returns true/false result to the caller) that takes _speed_, _weight_ and _minute_as its parameters, and checks whether they are in the range that they are supposed to be or not. If they're not in the range, the function will display an appropriate message and return false. Otherwise, it will return true.

1. _ **calculateMET** _ **:** A non-void function (returns a result to the caller) that takes _speed_and _exercise_as its parameters, and determines what the MET value is depending on the speed. The parameter exercise is of type string and it is the name of the exercise. In if-else statements, you can first check the exercise, then speed, and then determine the MET. At the end of the function, it should return the calculated MET value.

1. _ **computeResults** _ **:** A void function that takes _weight __,_ _goal__ ,_ _speedWalk __,_ _speedRun__ ,_ _speedCycling __,_ _minWalk__ ,_ _minRun_and_minCycling_as its parameters, and does all the necessary computations. First of all, your program will need the MET values for each exercise. So, you need to call the _ **calculateMET** _function from this function, separately for each exercise. After all three MET values are determined, your program will calculate the calories burned for each of them. Then, your program should compute the total calories burned, and also calculate the difference between the goal calories and total calories as it will be needed later. Then you will call _ **displayResults** _ function from this function.

1. _ **displayResults** _ **:** A void function that takes _difference __,_ _total__ ,_ _weight __,_ _walkMET__ ,_ _runMET __,_ _cyclingMET__ ,_ _walkCalorie__,_ _runCalorie_and_cycleCalorie_as its parameters and displays the required stuff. Your program will first print calories burned for each exercise and the total calories, and then according to the difference, your program will print appropriate messages as explained above.

**No abrupt program termination please!**

Especially during the input check, you may want to stop the execution of the program at a specific place in the program. Although there are ways of doing this in C++, it is not a good programming practice to abruptly stop the execution in the middle of the program. Therefore, your program flow should continue until the end of the main function and finish there.

| **VERY IMPORTANT!** Your programs will be compiled, executed and evaluated automatically; therefore you should definitely follow the rules for prompts, inputs and outputs. See **Sample Runs** section for some examples. **Order**  **of inputs and outputs** must be in the abovementioned format.
**Prompts**  **for inputs and outputs** must be **exactly the same** with examples.
Following these rules is crucial for grading, otherwise our software will not be able to process your outputs and you will lose some grades in the best scenario. |
| --- |

| **IMPORTANT!** If your code does not compile, you will get **zero**. Please be careful about this and double check your code before submission. |
| --- |

**Sample Runs**

Below, we provide some sample runs of the program that you will develop. The _italic_ and **bold** phrases are inputs taken from the user. You should follow the input order in these examples and the prompts that your program will display **must** be **exactly the same** as given in the following examples.

**Note: The sample runs have been updated as of Apr 14, 2022. See below for sample runs that are compatible with Grade Checker cases.**

_ **Sample Run 1** _

Please enter your name: **Baris**

Welcome Baris, please enter your weight(kg): **75**

Baris, please enter speed(km/h) and minutes spent in a week for the activities below.

Walking: **4 100**

Running: **4 150**

Cycling: **20 80**

Baris, please enter your weekly calorie burn goal: **2987.5**

From walking, you burned 500 calories.

From running, you burned 1687.5 calories.

From cycling, you burned 800 calories.

You burned 2987.5 calories.

Congratulations! You have reached your goal!

Please enter your name: **Gulsen**

Welcome Gulsen, please enter your weight(kg): **58.6**

Gulsen, please enter speed(km/h) and minutes spent in a week for the activities below.

Walking: **3 120**

Running: **4 100**

Cycling: **2 90**

Gulsen, please enter your weekly calorie burn goal: **1000**

Speed out of range!

_ **Sample Run 2** _

Please enter your name: **Duygu**

Welcome Duygu, please enter your weight(kg): **30**

Duygu, please enter speed(km/h) and minutes spent in a week for the activities below.

Walking: **6.5 120**

Running: **11 60**

Cycling: **25 200**

Duygu, please enter your weekly calorie burn goal: **2120**

From walking, you burned 390 calories.

From running, you burned 375 calories.

From cycling, you burned 1050 calories.

You burned 1815 calories.

You did not reach your goal by 305 calories.

You need to walk 93.8462 minutes more to reach your goal or,

You need to run 48.8 minutes more to reach your goal or,

You need to do cycling 58.0952 minutes more to reach your goal.

Please enter your name: **Inanc**

Welcome Inanc, please enter your weight(kg): **29.9**

Inanc, please enter speed(km/h) and minutes spent in a week for the activities below.

Walking: **6.5 120**

Running: **11 60**

Cycling: **25 200**

Inanc, please enter your weekly calorie burn goal: **2120**

Weight out of range!

_ **Sample Run 3** _

Please enter your name: **HAKAN**

Welcome HAKAN, please enter your weight(kg): **90**

HAKAN, please enter speed(km/h) and minutes spent in a week for the activities below.

Walking: **29 2000**

Running: **31 1999**

Cycling: **25 150**

HAKAN, please enter your weekly calorie burn goal: **1205**

Speed out of range!

Please enter your name: **Nisa**

Welcome Nisa, please enter your weight(kg): **45**

Nisa, please enter speed(km/h) and minutes spent in a week for the activities below.

Walking: **29 2000**

Running: **4 150**

Cycling: **25 2001**

Nisa, please enter your weekly calorie burn goal: **1500**

Minute out of range!

_ **Sample Run 4** _

Please enter your name: **Simge**

Welcome Simge, please enter your weight(kg): **150**

Simge, please enter speed(km/h) and minutes spent in a week for the activities below.

Walking: **6.5 2000**

Running: **11 2000**

Cycling: **20 2000**

Simge, please enter your weekly calorie burn goal: **135000**

From walking, you burned 32500 calories.

From running, you burned 62500 calories.

From cycling, you burned 40000 calories.

You burned 135000 calories.

Congratulations! You have reached your goal!

Please enter your name: **Akif**

Welcome Akif, please enter your weight(kg): **89.4**

Akif, please enter speed(km/h) and minutes spent in a week for the activities below.

Walking: **4.5 100**

Running: **10.9 20**

Cycling: **24.7 94**

Akif, please enter your weekly calorie burn goal: **5210.5**

From walking, you burned 596 calories.

From running, you burned 268.2 calories.

From cycling, you burned 1120.48 calories.

You burned 1984.68 calories.

You did not reach your goal by 3225.82 calories.

You need to walk 541.245 minutes more to reach your goal or,

You need to run 240.553 minutes more to reach your goal or,

You need to do cycling 270.622 minutes more to reach your goal.

_ **Sample Run 5** _

Please enter your name: **Peter**

Welcome Peter, please enter your weight(kg): **65**

Peter, please enter speed(km/h) and minutes spent in a week for the activities below.

Walking: **4 120**

Running: **6 1006**

Cycling: **5 30**

Peter, please enter your weekly calorie burn goal: **3500**

From walking, you burned 520 calories.

From running, you burned 9808.5 calories.

From cycling, you burned 195 calories.

You burned 10523.5 calories.

You have surpassed your goal! You can eat something worth 7023.5 calories :)

Please enter your name: **Mary**

Welcome Mary, please enter your weight(kg): **45**

Mary, please enter speed(km/h) and minutes spent in a week for the activities below.

Walking: **4.5 30**

Running: **5.2 60**

Cycling: **5.9 94**

Mary, please enter your weekly calorie burn goal: **850.5**

From walking, you burned 90 calories.

From running, you burned 405 calories.

From cycling, you burned 423 calories.

You burned 918 calories.

You have surpassed your goal! You can eat something worth 67.5 calories :)

**General Rules and Guidelines about Homeworks**

The following rules and guidelines will be applicable to all take-home exams, unless otherwise noted.

- **How to get help?**

You can use GradeChecker ([http://learnt.sabanciuniv.edu/GradeChecker/](http://learnt.sabanciuniv.edu/GradeChecker/)) to check your expected grade. Just a reminder, you will see a character ¶ which refers to a newline in your expected output.

You may ask questions to TAs (Teaching Assistants) or LAs (Learning Assistants) of CS201. Office hours of TAs/LAs are at the [course website](https://sites.google.com/sabanciuniv.edu/cs201).

- **What and Where to Submit**

You should prepare (or at least test) your program using MS Visual Studio 2012 C++ (Windows users) or using xcode (macOS users).

It'd be a good idea to write your name and last name in the program (as a comment line of course). Do not use any Turkish characters anywhere in your code (not even in comment parts). If your name and last name is "İnanç Arın", and if you want to write it as comment; then you must type it as follows:
_// Inanc Arin_

Submission guidelines are below. Since the grading process will be automatic, students are expected to strictly follow these guidelines. If you do not follow these guidelines, your grade will be 0.

- Name your submission file as follows:
  - Use only English alphabet letters, digits or underscore in the file names. Do not use blank, Turkish characters or any other special symbols or characters.
  - Name your cpp file that contains your program as follows:
 " **SUCourseUsername\_THEnumber.cpp**"
  - Your SUCourse user name is actually your SUNet username, which is used for checking sabanciuniv emails. Do NOT use any spaces, non-ASCII and Turkish characters in the file name ( **use only lowercase letters** ). For example, if your SUCourse username is " **altop**", then the file name should be: **altop\_the2** _ **.cpp** _ (please only use lowercase letters).
  - Do not add any other character or phrase to the file name.
- Please make sure that this file is the latest version of your take-home exam program.
- Submit your work **through SUCourse only**! You can use GradeChecker only to see if your program can produce the correct outputs both in the correct order and in the correct format. It will not be considered as the official submission. You must submit your work to SUCourse. You will receive no credits if you submit by any other means (email, paper, etc.).
- If you would like to resubmit your work, you should first remove the existing file(s). This step is very important. If you do not delete the old file(s), we will receive both files and the old one may be graded.

- **Grading, Review and Objections**

Be careful about the automatic grading: Your programs will be graded using an automated system. Therefore, you should follow the guidelines on the input and output order. Moreover, you should also use the same text as given in the "Sample Runs" section. Otherwise, the automated grading process will fail for your take-home exam, and you may get a zero, or in the best scenario, you will lose points.

Grading:

- There is NO late submission. You need to submit your take-home exam before the deadline. Please be careful that SUCourse time and your computer time may have 1-2 minutes differences. You need to take this time difference into consideration.
- Successful submission is one of the requirements of the take-home exam. If, for some reason, you cannot successfully submit your take-home exam and we cannot grade it, your grade will be 0.
- If your code does not work because of a syntax error, then we cannot grade it; and thus, your grade will be 0.
- Please submit your **own** work only. It is really easy to find "similar" programs!
- Plagiarism will not be tolerated. Please check our plagiarism policy given in the [Syllabus](https://sucourse.sabanciuniv.edu/plus/pluginfile.php/429633/mod_folder/content/0/Syllabus%20Spring%202022%20%28202102%29.pdf?forcedownload=1) or on the [course website](https://sites.google.com/sabanciuniv.edu/cs201).

### **Plagiarism will not be tolerated!**

Grade announcements: Grades will be posted in SUCourse, and you will get an Announcement at the same time. You will find the grading policy and test cases in that announcement.

Grade objections: It is your right to object to your grade if you think there is a problem, but before making an objection please try the steps below and if you still think there is a problem, contact the TA that graded your take-home exam from the email address provided in the comment section of your announced take-home exam grade or attend the specified objection hour in your grade announcement.

- Check the comment section in the take-home exam tab to see the problem with your take-home exam.

- Download the file you submitted to SUCourse and try to compile it.

- Check the test cases in the announcement and try them with your code.

- Compare your results with the given results in the announcement.

_ **Good Luck!** _

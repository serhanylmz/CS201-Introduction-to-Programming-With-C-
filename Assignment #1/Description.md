# **CS201 – Spring 2021-2022**

**Take-Home Exam 1**

– **CS201 Course Numeric Grade Calculation –**

**Due April 3**** rd****, Sunday, 23:55 (Sharp Deadline)**

**Introduction**

The aim of this take-home exam is to practice on the basics of C++ (input, output, assignment, arithmetic, etc.) and decision making (conditional if statements). The use of if statement is due to the nature of the problem; that is, you cannot finish this take-home exam without using decision making.

**Description**

In CS201, weights of the grading items on the course numeric grade are as given in Table 1. However, the weighted average is not the only criterion in letter grading, and thus, in the calculation of the course numeric grade.

Table1. Tentative Grading for CS201

| **GRADING ITEM** | **PERCENTAGE** |
| --- | --- |
| Participation | 7% |
| Take-Home Exams | 25% |
| Midterm Exam | 33% |
| Final Exam | 35% |

Here are some of the rules, which will be used in this take-home exam:

- If your exams' weighted average (((MT \* 0.33) + (FNL \* 0.35))/0.68) is below 30, you will fail the course even if your total grade is equal or above the overall passing grade.
- All of the assigned take-home exams will be taken into consideration in the course numeric grade and each take-home exam will have equal weight.

Apart from the aforementioned rules, the contribution of the take-home exams to the course numeric grade is calculated according to the formula given below:

![](RackMultipart20221106-1-fvjmre_html_599566f936443d4a.png)

You may check the [Syllabus](https://sucourse.sabanciuniv.edu/plus/pluginfile.php/429633/mod_folder/content/0/Syllabus%20Spring%202022%20%28202102%29.pdf?forcedownload=1) or the [course website](https://sites.google.com/sabanciuniv.edu/cs201) to get the complete version of the grading schema of CS201 for the Spring 2021-2022 semester.

In this take-home exam, you will implement a C++ program that calculates the course numeric grade of a CS201 student. The inputs to your program will be (i) name of the student, (ii) midterm and final exam grades, (iii) take-home exam grades, and (iv) the number of days attended recitations of the student. Your program will then calculate the weighted exam average, take-home exam average, a ratio, percentage of participation and the course numeric grade, based on some conditions as described below.

During designing the algorithm for your program, you will follow the below listed _assumptions_in this take-home exam:

- There is no make-up exam for the regular midterm and final exams.
- There are a total of 4 (four) take-home exams, and the student has submitted a work for each of those take-home exams.
- There will be 13 weeks of recitation in a semester due to midterm week.

You may implement your algorithm all in the _main_ function, i.e. you are not expected to write any user-defined functions, but of course you can write some, if you prefer to do so.

Your take-home exams will be automatically graded using GradeChecker, so it is very important to satisfy the exact same output given in the sample runs. You can utilize GradeChecker ([http://learnt.sabanciuniv.edu/GradeChecker/](http://learnt.sabanciuniv.edu/GradeChecker/)) to check whether your implementation is working in the expected way. To be able to use GradeChecker, you should upload all of your files used in the take-home exam ( **only** _your\_main\_cpp_ file for this take-home exam). Additionally, you should submit all of your files to SUCourse ( **only** _your\_main\_cpp_ file for this take-home exam) **without zipping** them. **Just a reminder, you will see a character ¶ which refers to a newline in your expected output.**

**The name of your main source (cpp) file should be in the expected format:**"SUCourseUsername\_THEnumber.cpp" (all lowercase letters). Please check the submission procedures of the take-home exam, which are listed at the end of this document.

**Inputs, Flow of the Program and Outputs**

The inputs of the program and their order are explained below. It is extremely important to follow this order with the same characters since we automatically process your programs. _ **Thus, your work will be graded as 0 unless the order is entirely correct** _. Please see the "Sample Runs" section for some examples.

The prompts of the input statements to be used has to be exactly the same as the prompts of the "Sample Runs".

At the beginning of your program, the user will be prompted to enter his/her name as the first input. The name of the user should be displayed whenever appropriate in the prompts and in the output text. Please see the "Sample Runs" section for some examples.

After the user enters his/her name, (s)he will be asked to provide his/her midterm and final exam grades. Once inputted, your program will calculate the weighted exam average as given below:

**weighted\_exam\_grade = 0.33 x midterm\_grade + 0.35 x final\_grade**

**weighted\_exam\_avg = weighted\_exam\_grade / 0.68**

If the weighted exam average of the user is below 30, (s)he will fail the course due to the course rules given before.

**Hint : avg\_grade\_to\_pass = (30.0 \* 0.33 + 30.0 \* 0.35) / 0.68**

In such a case, your program will display an appropriate message, and then, _your program will finish__without_ _even getting or prompting for the other inputs_.

On the other hand, if the weighted exam average of the user is equal to or greater than 30, then your program will continue. This time, the user will be asked to enter the grades of his/her 4 take-home exams. Once inputted, your program will calculate and display the average of those, and it will also calculate the ratio between weighted exam average and take-home exam average, which is to be calculated as given below:

**ratio = take\_home\_avr / weighted\_exam\_avr**

Thereafter, your program will calculate and display the points earned from the take-home exams depending on the schema below:

![](RackMultipart20221106-1-fvjmre_html_2b10bfd500d04618.png)

Then, your program will prompt for the recitation attendance of the user. You can calculate the percentage of participation as given below:

**participation = recitation\_attendance / 13 \* 100**

Lastly, your program will calculate and display the course numeric grade of the user, which is to be calculated as given below:

**course\_numeric\_grade = participation \* 0.07
 + take-home\_grade \* 0.25
 + midterm\_grade \* 0.33
 + final\_exam\_grade \* 0.35**

You may assume that the user will always enter positive values correctly for all inputs. Therefore, you do not need to perform any kind of input checks.

Please refer to the "Sample Runs" section for some examples and further details.

| **IMPORTANT!**
If your code does not compile, then you will get **zero**. Please be careful about this and double check your code before submission. |
| --- |

| **VERY IMPORTANT!** Your programs will be compiled, executed and evaluated automatically; therefore you should definitely follow the rules for prompts, inputs and outputs. See **Sample Runs** section for some examples.
- **Order**  **of inputs and outputs** must be in the mentioned format.
Following these rules is crucial for grading, otherwise our software will not be able to process your outputs and you will lose some points in the best scenario.
 |
| --- |

**Sample Runs**

Below, we provide some sample runs of the program that you will develop. The _italic_ and **bold** phrases are inputs taken from the user. You have to display the required information in the same order and with the same words and characters as below.

## _ **Sample Run 1** _

The purpose of this program is to calculate your CS201 grade. What is your name? _ **Naz** _

Hello Naz, what are your midterm and final exam grades? _ **34 20** _

Naz, your weighted exam average is less than 30, you will fail the course!

##


## _ **Sample Run 2** _

The purpose of this program is to calculate your CS201 grade. What is your name? _ **Ece** _

Hello Ece, what are your midterm and final exam grades? _ **86 75.5** _

What are the grades of your 4 take-home exams? _ **100 90.5 75 95** _

You'll get all the points earned from take-home exams!

How many days have you attended recitations? _ **11** _

Ece, your grade for CS201 is: 83.2593

##


## _ **Sample Run 3** _

The purpose of this program is to calculate your CS201 grade. What is your name? _ **Berk** _

Hello Berk, what are your midterm and final exam grades? _ **50.5 35** _

What are the grades of your 4 take-home exams? _ **96 88 90 75** _

You'll get 82.7238 from the points earned from take-home exams!

How many days have you attended recitations? _ **10** _

Berk, your grade for CS201 is: 54.9806

##


## _ **Sample Run 4** _

The purpose of this program is to calculate your CS201 grade. What is your name? _ **Can** _

Hello Can, what are your midterm and final exam grades? _ **25 35** _

What are the grades of your 4 take-home exams? _ **100 95 100 90** _

You'll get NONE of the points earned from take-home exams!

How many days have you attended recitations? _ **9** _

Can, your grade for CS201 is: 25.3462

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
  - Your SUCourse user name is actually your SUNet username, which is used for checking sabanciuniv emails. Do NOT use any spaces, non-ASCII and Turkish characters in the file name ( **use only lowercase letters** ). For example, if your SUCourse username is " **altop**", then the file name should be: **altop\_the1** _ **.cpp** _ (please only use lowercase letters).
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

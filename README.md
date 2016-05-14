# Practical-Programming-in-C
I have decided to improve my knowledge in C, so I have started this course which has been totally amazing.
I highly recommend to take this course for the ones who are interested in learning about C.
This course has been very challenging, and the problem sets and projects are really pragmatic.

When I started learning about C, I was reading a really good book: Head First C which sincerely is an excellent book.
However, this book does not offer challenging problems or exercises, so I started to look for a course to fill these requirements, and fortunately I found this at MIT OpenCourseWare.

The purpose of this README is to track how well (or badly) I am doing this course, and I would also like to provide some advice for the ones who are interested in taking this course too.
Therefore, for every lecture, I will include a brief summary, while for every project or problem set I will describe the difficulties and insights I got.

## Problem Set 6 - Part A
### Pointers to pointers. Multidimensional arrays. Stacks and Queues.
#### Problem 6.1: Four-Function Calculator
The goal of this problem was to implement a simple four-function calculator using stacks and queues.
The input for this program is a space-delimited infix expression (e.g. 3 + 5 * 9) which has to be evaluated following the order of operations for a mathematical expression.
In addition, this calculator has to handle the unary negation operator (  - ).
Another feature of this calculator is that this has to be able to deal with parentheses.

##### Observations
This exercise has a couple of helper files.
Frankly, I considered that the provided file **prob1.c** is totally a mess because it has almost 290 lines of code which could be properly separated into more files to improve not only readability of code but also its maintenance.

Furthermore, understanding the provided code took me a little while, so it was a good approach to divide the code in several files.
Honestly, I have to admit this problem was pretty challenging at the beginning, but I really enjoyed solving this problem.
As the problem suggest, it is a good idea to make the calculator work without worrying about parentheses firstly.

##### Difficulties
I had a hard time because the functions **pop()** and **push()** take a pointer to pointer on the top of a stack, and I was passing the pointer on the top of the stack.
After checking the code a couple of times I understood what was going on.

#### Problem 6.2: One-way English to French Dictionary
In this problem one has to implement a one-way English to French dictionary using a data structure called trie.
The input for this program is an English word, and the program will return the translation of this word.
If there is more than one translation for this word, every translation will be returned in a string separated by commas.
On the other hand, if there is no translation for the entered word, a message will be display saying that the word was not found in the dictionary.

##### Observations
I have to say that the information provided in the exercise is not so clear and not enough to have a deep understanding of what a trie is, so I strongly recommend to read or watch videos about tries.
First, I got a little confused after reading the information provided, but after watching a video uploaded by CS50 on Youtube, I totally understood what I had to do.
This exercise it is easier than it seems, and it is pretty interesting to see how useful tries could be.

##### Difficulties
I spent almost an hour trying to figure out why my program was not working properly.
First, I thought I was not calling free properly to release the memory space I allocated.
However, my program was freeing really well, so I was drawing blanks on what to do.
Thus, I decided to see the solution in order to compare, and my code was pretty similar that at the beginning I was not able to figure out what happened.
Finally, I realized that I was performing a casting from a char to unsigned int which turns out to be not as simple as possible.
After changing this casting my problem was solved.

## Problem Set 6 - Part B
### Function Pointers and Hash Table
This problem set was really easy, but it was worthy.
It was pretty useful having read chapter 7 of Head First C previously, and watched the CS50 video about hash tables.

#### Problem 6.1: Implementing callback functions
The purpose of this exercise was to implement callback functions to sort a list of students depending on his name, and last name.
In addition, a function that prints records depending upon the age of students has to be implemented.

##### Observations
This problem is really straightforward.
In fact, I spent more time organizing the file in separate files than actually solving the problem.

##### Difficulties
None.

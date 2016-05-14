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

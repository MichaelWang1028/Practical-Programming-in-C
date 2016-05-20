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

#### Problem 6.1: Word frequency counter
The goal of this problem is to count the frequency of words within a file using a hash table.

##### Observations
Again the problem is really straightforward, and I spent more time separating the code than solving the problem.

##### Difficulties
The only tricky thing is when implementing the function **cleartable()** because you should free not only the node of the linked list, but also the word associated with this node.

## Lab 2
### Data compression
This lab was both challenging and exciting.
As usually, the information provided was not enough, so I had to make my own research.
The purpose of this lab was to understand and develop Huffman coding.

#### Part A: Implementing a Huffman decoder
Given a file that contains symbols and a their binary strings, a corresponding Huffman code tree should be created.
In addition, a function **decode()** should be implemented which uses the Huffman code tree previously generated to decode input from a file.

##### Observations
Understanding the purpose of the Huffman code tree took me a little while.
However, after I understood, I implemented these functions really quickly.
My knowledge of trees was useful because I clearly knew that I had to use post-order traversal to free the nodes of a binary tree.
I spent almost the same amount of time implementing the functions than separating the code into files.

##### Difficulties
Because of the lack of information provided in the pdf, I had to do extra research.

#### Part B: Implementing a Huffman encoder
A Huffman encoder should be implemented.
The symbols and their frequencies are given.
A priority queue is used to build the tree.
Once the tree is generated, the string for each symbol should be output to a file **code.txt**.

##### Observations
Completing this task took me almost the same amount of time than separating the provided code into files.
It was great when I saw that my **code.txt** file has the same table than the one provided in the pdf.

##### Difficulties
Understanding the problem and the provided code took me some time.
I got a couple of segmentation faults.

#### Part C: Compressing a larger file
Given a file **book.txt**, one has to generate the Huffman code tree, and the frequencies are not provided.
Once generated, the file information has to be encoded, and posteriorly decoded into a file **decoded.txt** which must have the same information of **book.txt**.

##### Observations
Although it seems pretty simple at the beginning, it was necessary to implement a couple of helper functions.
I tried to reuse the implemented code for encode and decode as much as possible.
It was really useful to write down the solution on a piece of paper.
A compression of approximately 57% was obtained.
I was really happy after encoding and decoding **book.txt** and getting exactly the same file.

##### Difficulties
I got constantly segmentation faults which I could solve by debugging using **printf()**.
Once again the casting from int to unsigned char was tricky.

## Problem Set 7
### Using and creating libraries. B-trees and priority queues.
This problem set has just one problem.
Although the tittle suggests it covers priority queues, it doesn't.

#### Problem 7.1: Using the library sqlite3 and load database in a B-Tree
This exercise has four items.
The first one is basically to use some functions from the library sqlite3.
The second one is the one that is challenging which is to complete some functions to load the data base on a B-tree.
The third one is to complete a function that allows to look for a movie on the b-tree.
Finally, the fourth one is to implement a static or dynamic library implementing some functions which prototypes are provided.
##### Observations
It took me some time to understand what a b-tree is.
I found a really useful information about it on a website called [Geek for Geeks](http://www.geeksforgeeks.org/b-tree-set-1-introduction-2/).
Although I didn't check exhaustively the algorithms for insertion and deletion, I could notice that they are not so easy to implement.
As always it is useful to separate the provided code into files, i.e., to create a header file for preprocessor, structs and global variable definitions and a file for the main function which is used for testing.

Fortunately, one does not have to implement the whole algorithm for creating a b-tree.
Understanding a b-tree could take some time, but after reading for a while I learnt not only its properties, but also why they are useful.
It turns out that they are used to store the content of databases and files in order to increase the speed at which they are accessed.
I wonder why not using a hash map, and it seem both b-trees and hash maps are used with databases.
The former allows applying comparison operators which answer is a range of values while the latter allows using == <=> and LIKE operators.
Implementing the function **find_index()** made me realized that in the end the value that should be returned when a having a new key is **L** which is the left index after applying the binary search.
I created a Makefile that allows me to compile both a program that uses either a dynamic or a static library.

##### Difficulties
The difficult part is to understand what a b-tree is, so I highly recommend to read and understand at least the basics of b-trees.
Though it was not difficult I struggle a little bit when I was implementing the function to print the b-tree nodes in-order.
The problem in the end was that I wanted to implement a similar algorithm that was used with a binary tree, but I did not remembered it properly, so I was not printing the leaves of the b-tree.
Fortunately, after checking the solutions I realized of my mistake and I correct it immediately.
Besides this mistake I did not find another one, and as all of the problem sets of this course I enjoyed it a lot.

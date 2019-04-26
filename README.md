# Googla Document Finder - TP1-AEDS2-UFV

![Running Googla](https://i.imgur.com/98RVWt6.png)

Googla is a document finder written in pure C. It can index all documents inside of how many folders do you want and retrieve then by term search with autofill, like Google or DuckDuckGo, using TF-IDF (Term frequency - Inverse document frequency).
The example texts inside the code are the Queen's musicography (all rights reserved).
This is a pratical work for AEDS 2 discipline of bachelor's degree in computer science from the Federal University of Viçosa.


# About used programming language and graphical interface

The present code was written in pure C, using only native libraries like stdio, stdlib, dirent etc and it runs inside Terminal/Console.

# Okay, cool, but there is no executable. How can I run this?

To avoid compatible errors, no executable was distributed with this code, but you can make for you own.
You have two ways to do this:

## 1 - Optimal: Using Clang

If you don't have Clang installed or you're not sure about this, run those commands:

### On Ubuntu based distros
    sudo apt install clang
    
### On Arch based distros
    su
    pacman -Sy clang
After that, simple clone this repository, compile and run using these commands:

    git clone https://github.com/mateusps10/Googla_DocumentFinder-TP1-AEDS2-UFV
    make clang
    make run
   For more information about Clang, please visit they [homepage](https://clang.llvm.org/)
## 2 - Without installing anything (or almost this): Using GCC

### On Linux or MAC based systems
    git clone https://github.com/mateusps10/Googla_DocumentFinder-TP1-AEDS2-UFV
    make
    make run

### On Windows based systems
Download Clion or CodeBlocks, follow installation steps and run *main.c* from there
\
\
\
***IMPORTANT:** Note that you can download the zipfile instead of cloning the rep if you don't have git installed on your PC.*




# About data structs and why I chose them
Googla uses a PATRICIA (Practical Algorithm To Retrieve Information Coded in Alphanumeric) to index document words, because it is flattened and specific to store all kind of words from any size, with an inverted chained list to store terms occurrence of each file. Also, Googla uses a TST Trie (Ternary search tree) to complete autofill task because of its suitable work for that application handling radical and sufixes. To present search results, Googla has a built-in dual criteria BST (binary search tree), who uses TF-IDF and alphabetical order as its criteriums. Lastly, Googla has some linked lists to make other fuctions.

# Complexity Analysis
Since the most expensive primary struct is threes, the complexity of the code is **O(logN)**.

# Who am I?
My name is **Mateus Pinto da Silva**, I'm a Brazilian redhead computer scientist (currently graduating), who loves to program in Python using Object-oriented Programming and to describe hardware in Verilog HDL. I'm a data science enthusiast, current intern of a Brazilian Enterprise called Cinnecta. I like to train models in TensorFlowAPI when I have nothing better to do, and if you check my github profile, you will see that I usually don't have nothing better to do in fact. I study on Federal University of Viçosa.

## About my trajectory with C
All that I learned from C language came from my university lessons of AEDS I and AEDS II (Algorithms and Data Structures) and obviously from standalone researchs that I made, especially in "*The C Programming Language*", by Brian W. Kernighan and Dennis M. Ritchie


> Written with [StackEdit](https://stackedit.io/).

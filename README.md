# push_swap

A project made for the 19 coding school, part of the 42 network. 

The main goal of this project was to get familiar with time complexity of programs and to find creative ways to work with algorithms.

The program will take a list of integers as argument and sort them in ascending order. In order to sort them we were only allowed to use two different stacks (stack_a and stack_b in my code) and a very limited set of instructions we could perform on the stack. For more details check the subject file attached to this repository. (note: given the functions we were allowed to use on the stack it as actually more of a queue than a stack.) The intructions needed to sort stack_a need to be printed to the terminal.

As with all projects for the 19 coding school we were only allowed to use a very limited set of functions.

# Usage

You can compile the push swap program with make, remove the objects with clean and remove everything with fclean. The program will compile using gcc and -Wall -Wextra -Werror flags.

The list of integers can either be entered as different arguments or a string in which the different integers are seperated by spaces (1 or more).

# Approach

To solve this problem there are a few steps I decided to take.

First we will check if the input is valid, if a single string is provided we will translate it into an array of integers, using a self written split function. After which we will traverse the arguments and check if they are valid integers.

If the arguments pass the parsing they will be stored as a linked list to represent the stack. I chose a linked list as the sizes of the stacks will change a lot during the program for which linked lists are more suited.

Next we will check the amount of arguments and use a different algorithm for 3 different cases:

- If there are 3 or less integers, there are only 6 possibilities for a possible solution. The program will check which solution is needed.
- If there are in between 4-6 integers the program will find the lowest element in the stack, it will find out if it is in the bottom or top half of the stack and move it to the top of the stack accordingly. After which it will push it to stack_b. It will keep doing this until only 3 elements remain in stack_a after which it will sort those elements using the algorithm for 3 integers. When this is done all arguments from stack_b will be pushed back to the top of stack_a.
- For all bigger cases I opted for a radix sort, since we only have two stacks to store our elements we will be looking at them in a binairy way, using bitwise operators to sort them. For effiency's sake I also added an index to the elements of the linked list depending on the order they should end up in. The program performs the bitwise comparisons on this index and will either push them to stack_b or moce them to the bottom of stack_a accordingly.

The goal of this lab is to analyze a binary tree and count how many nodes have zero, one, or two
valid children. Use the attached code as template. You should only edit the "count()" function.

I've used Python in an effort to simplify things a bit for you.

Run your code from the command line using:
python lab_05.py

Submit your code using
./submit

Note that only the file <lab_05.py> will be submitted


instructions
    One way of determining if a tree is well balanced is to count how many of the nodes
    have zero children, one child, or two children. Well-balanced trees will have very few
    nodes with just one child. A degenerate tree will have all nodes with one child, except the
    very last node which will have zero children.

    Write the function count() which will count the occurrences of nodes with zero, one, or two
    children. You may only edit the count() function. No other edits are permissable.

    There are three test cases. The first two are simple enough that you can manually validate
    your results. The third cases reads 1000 randomly generated ints out of a file and puts them
    in the tree. My results are:

        Nodes with 0 children: 345
        Nodes with 1 children: 311
        Nodes with 2 children: 344

    Your code should return the same. Is this a well-balanced tree? If the tree was _perfectly_ balanced,
    what would the node counts be?

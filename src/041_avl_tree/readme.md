# Assignment 041

> 
> NOTE: There is no automatic grader for this assignment. It is provided for you to practice. To receive assistance or request a code review, push your code to Gitlab and create a merge request as usual. Then, open your merge request in Gitlab, and either 1) add a comment to your merge request and tag the instructor / TA or 2) click the edit button next to Reviewer and select an instructor / TA
>


## Instructions
For this assignment, you will write a fully-functional AVL tree class.

As discussed in AoP Chapter 27, the AVL tree is a self-balanced BST. In an AVL tree, the heights of the two child substrees of any node differ by at most one. If any time they differ by more than one, rebalancing is done to restore this property.

Your AVL tree class should support the basic operations like insertion, deletion and an interesting function as suggested in `avl_tree.hpp`.

For the node insertion, we would highly recommand you to write a helper function, which would be much easier for you to implement the insertion. A suggested helper function is like:

```cpp
  AVLNode* insertHelper(AVLNode *curr, int val);
```

For example, when you try to insert 3 into your AVL tree

    	     1	      	     	    2
	      \		->	   / \
	       2		  1   3
	       
where 1's node is passed in, and it returns 2's node.

A helper function also helps a lot for the deletion, and it is like:

```cpp
  AVLNode* deleteHelper(AVLNode *curr, int val);
```

For example, when you try to delete 2 from your AVL tree

    	     2	      	     	    3
	    / \		-> 	   / 
	   1   3		  1
	   
where 2's node is passed in, and it returns 3's node.

One thing needs attention - if the node we want to delete has two children, we try to find the minimum node in its right subtree, which is 3 in the above example.

Do not forget the four different types of self-balancing rotations, which are left rotation, right rotation, left-right rotation and right-left rotation. Make sure your rotation functions works well before implementing the insert or delete operation. You should also update the height of nodes when you do the operations like rotation, insertion and deletion.

Of particular interest is the templated `preOrderFold` function. 

It takes a generic function as a parameter to achieve different purposes based on the passed-in function. For example, if we want to implement an adder in this AVL tree, we invoke this function by passing an adder function, which is as simple as the following: 

```cpp
  preOrderFold<int>([](const int & sum, int data) -> int { return sum + data; }, 0);
```

The returned value will be the total sum of all nodes value in this AVL tree.

Add any other helper functions in `AVLTree` class as necessary and implement all methods along with your helper functions in `avl_tree.cpp` file. 

Also, remember the `Rule of Three` and make some abstraction to avoid the duplicate code when you are implementing you AVL tree class.

Your destructor should delete all nodes in the current AVL tree. 

Submit your code and make sure it is valgrind clean.

A simple program to traverse through a binary tree in level order or BREADTH FIRST, preorder, inorder and postorder.

LEVEL ORDER TRAVERSAL:

 Queue is used by including its header file 'queue'. The children of a node is pushed into a queue and and is printed out in FIFO (First in First out) order.

The example tree and queue is shown below:

![Level Order Traversal](https://user-images.githubusercontent.com/86644466/144174760-c7c3ee76-127b-48a3-a50c-384bb4bb9ab1.png)

The final order should be as: F D J B E G K A C I H


PREORDER, INORDER, POSTORDER TRAVERSAL

Recursion is used to traverse through the tree in the desired manner.

![Traversal](https://user-images.githubusercontent.com/86644466/144174990-760fd71c-ae72-4c64-bc9c-a502d8f7da95.png)

The final preorder should be as: F D B A C E J G I H K

The final inorder should be as: A B C D E F G H I J K

The final postorder should be as: A C B E D H I G K J F

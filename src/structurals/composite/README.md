# Hierarchical Structure For A File System Application 

This repository solves the problem of having to deal with multiple objects as they are a single structure, so we can uniform the manipulation of those objects, this allows us to automate the iteration process for example, it also makes possible to nest multiples objects recursively, among other operation that is enabled because of this tree-like structure that we are going to achieve with this pattern. And for achieving it, we use the Composite design pattern.

## The Problem:

"You are building a file system applicattion that needs to represent files and directories in a hierarchical structure. The application should allow users to perform commom file system operations, such as creating, deleting, moving, and copying files and directories. The application should also support operations that can be applied to both individual files and entire directories, such as calculating the total size of a directory and displaying the contents of a directory. You need to implement a Composite design pattern to represent files and directories as a tree-like structure, and allow for uniform treatment of both individual files and directories as components of the file system."

## The Solution:

We just need to implement a common interface for the directories and files, then we can implement the concrete classes for one of those, just remeber to add a state to hold the children (files) for each directory, then we instantiate the root and add the needed repositories to the system. The interface might declare the common methods for both directory and files, like deleting, copying, etc.

## Pros:
 
  ✅ It makes easier to recursively iterate over multiple objects.

  ✅ Follows the Open Closed Principle guidelines.

## Cons:

  ❌ May be difficult to implement in an already existent system.


### **Resource:**

 🔗 [Refactoring Guru (Composite)](https://refactoring.guru/design-patterns/composite)

# Hierarchical Structure For A File System Application 

This

## The Problem:

"You are building a file system applicattion that needs to represent files and directories in a hierarchical structure. The application should allow users to perform commom file system operations, such as creating, deleting, moving, and copying files and directories. The application should also support operations that can be applied to both individual files and entire directories, such as calculating the total size of a directory and displaying the contents of a directory. You need to implement a Composite design pattern to represent files and directories as a tree like structure, and allow for uniform treatment of both individual files and directories as components of the file system."

## The Solution:

Based.

## Pros:
 
 ✅ You can work with complex tree structures more conveniently: use polymorphism and recursion to your advantage.

  ✅ Open/Closed Principle. You can introduce new element types into the app without breaking the existing code, which now works with the object tree.

## Cons:

 ❌ It might be difficult to provide a common interface for classes whose functionality differs too much. In certain scenarios, you’d need to overgeneralize the component interface, making it harder to comprehend.


### **Resource:**

 🔗 [Refactoring Guru (Composite)](https://refactoring.guru/design-patterns/composite)

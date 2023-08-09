# File Management System Proxy

This repository solves the problem of.

## The Problem:

"You are building a file management system that allows users to access and manipulate files stored on a remote file server. The file server is accessed over a network connection, and file operation can be time-consuming and resource-intensive. To improve performace and security, you need to implement a Proxy design pattern that provides a virtual proxy for the remote file server.

The Virtual proxy acts as an intermediary between the client and the remote file server, and handles tasks such as authentication, caching, abd access control. The proxy should provide a transparent interface to the client, so that the client can perform file operations just as if it were acceccing the remote file to improve performance, and enforce access control policies to restrict unauthorized access to files."

## The Solution:

Based.

## Pros:
 
 ✅ You can control the service object without clients knowing about it.

 ✅ You can manage the lifecycle of the service object when clients don’t care about it.

 ✅ The proxy works even if the service object isn’t ready or is not available.

 ✅ Open/Closed Principle. You can introduce new proxies without changing the service or clients.

## Cons:

 ❌ The code may become more complicated since you need to introduce a lot of new classes.

 ❌ The response from the service might get delayed.


### **Resource:**

 🔗 [Refactoring Guru (Proxy)](https://refactoring.guru/design-patterns/proxy)

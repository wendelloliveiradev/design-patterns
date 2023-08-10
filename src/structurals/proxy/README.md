# File Management System Proxy

This repository solves the problem of needing to have extra control over the communication between a given client and service, like adding an auth system or storing results of the communication.

## The Problem:

"You are building a file management system that allows users to access and manipulate files stored on a remote file server. The file server is accessed over a network connection, and file operation can be time-consuming and resource-intensive. To improve performace and security, you need to implement a Proxy design pattern that provides a virtual proxy for the remote file server.

The Virtual proxy acts as an intermediary between the client and the remote file server, and handles tasks such as authentication, caching, abd access control. The proxy should provide a transparent interface to the client, so that the client can perform file operations just as if it were acceccing the remote file to improve performance, and enforce access control policies to restrict unauthorized access to files."

## The Solution:

We want to introduce a proxy object between the file management system and the client that make the request, then inside the same proxy object we are gonna to add the control to other intermediare service such as authentication and caching.

## Pros:
 
 ✅ Really simple implementation with lots of applicability.

 ✅ Make possible to control and costumize the communication between a stablished client/service communication.

 ✅ Can be used as a cached system service.

 ✅ Follows the open closed principle guidelines.

## Cons:

 ❌ It can increase code complexity.



### **Resource:**

 🔗 [Refactoring Guru (Proxy)](https://refactoring.guru/design-patterns/proxy)

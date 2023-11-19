# Introduction
This repo contains personal software development projects I have worked on. Each subfolder contains a pesonal project to some level. 

## BUtility 
- `BUtility` stands for "Blake's Utility" which is meant to be a folder to host any common C++ code that could be shared among different projects. 
- Currently, there is only one function here which assists in parsing command line arguments. 

## Helloworld gRPC 
- A starter project for building gRPC client,  server, and deploying the server on an AWS Machine.  
- It also provided a good exercise on how to build C++ applications with CMake. 

## Redtangle 
- Redtangle is a board game similar to chess that has been converted into a desktop application. 
- The game supports playing verse another player remotely, via communication with a gRPC server.
- You can also play two player mode (specified at compile time) on the same computer by sharing a mouse. 
- See [TUTORIAL.md](redtangle/TUTORIAL.md) for a walk through of the game.
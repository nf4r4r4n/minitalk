# 42 School: Minitalk
The project minitalk is a 42 School Project, that has to be written in C, that aims to understand and create a **minitalk** protocol. This is a mini transmission protocol that uses signals to establish transmission between two processes (server and client).

## 📡 What are signals ?
Signal is an asynchrone event that is sent to a process (= program execution). When a signal is sent to a process, this signal will do a specific action by default.
Let's take an example. When we run a program in linux, this program has a specific id (= called the process id or **pid**). When we press on **Ctrl + C** of the keyboard, the program will be interupted. This signal is the signal **SIGINT** that interupts a process.

## 🚧 How about the project ?
Here are the rules:
- You must realize a project that is a communication program as **client** and **server**
- The **server** must be run first and print its **PID**
- The **client** takes 2 arguments: the **PID** of the server and the message that we want to pass to as a string
- The **client** must communicate the string passed to the argument to the **server**, so that after receiving the whole string, the **server** must print it
- The **server** must be able to print the string quickly
- Your server must be able to receive strings from many clients without restarting it
- The communication between your programs must be only done by using UNIX signals
- You can only use SIGUSR1 and SIGUSR2 signals in your programs

## 🛠️ Requirements
You must run this project in linux. I don't have Mac or Windows version yet.
You also have to have C compiler like GCC or Clang.
You must have **make** utils.

## 📖 Usage
- Clone this project
```sh
git clone https://github.com/nf4r4r4n/minitalk
```
- then compile
```sh
# compile both client and server
make
# compile only client
make client
# compile only server
make serve
```
- run the **server** program first
```sh
./server
# Example of the output:
# [SERVER PID: <here_is_the_pid>]
```
- then run the client:
```sh
./client <server_pid> <string_to_communicate>
```

# Enjoy 🤓 💻
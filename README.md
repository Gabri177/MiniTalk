# Minitalk Project

## Introduction

The `minitalk` project is part of the 42 school curriculum, designed to create a simple communication system between a client and a server using UNIX signals. This project aims to deepen the understanding of process communication, signal handling, and server-client architecture in C programming.

## Objective

The main goal of this project is to code a small data exchange program using UNIX signals. The program consists of a server and a client. The server must be launched first to display its PID, and the client will then use this PID to send a string to the server, which will then print it.

## Technologies & Languages Used

- **Language:** C
- **Concepts:** UNIX signals, Process Communication, Client-Server Architecture
- **Compilation:** Makefile for easy compilation and cleaning up object files
- **Supported OS:** Unix/Linux-based systems


## Features

- Lightweight client-server communication using UNIX signals.
- Handles communication through SIGUSR1 and SIGUSR2 signals.
- The server can display the client's message by decoding the signal-based communication.
- Includes a Makefile for easy compilation.

## Usage

1. **Compilation**: Navigate to the project directory and run `make` to compile the server and client programs.
2. **Server**: Run `./server` to start the server. Note down the displayed PID.
3. **Client**: Execute `./client [server PID] [message]` to send a message to the server.

Example:

```bash
# Terminal 1
./server
Server PID: 1234

# Terminal 2
./client 1234 "Hello, Minitalk!"
```

## Installation
Clone the repository and compile the project:
```bash
git clone https://github.com/Gabri177/minitalk.git
cd minitalk
make
```

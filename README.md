# Delivery Dispatch System (C++)

Console app that assigns packages to delivery drivers using custom queue data structures.

## How it works

- **Priority queue** for packages – the most urgent package is always dispatched first
- **Regular FIFO queue** for delivery drivers – drivers are assigned in the order they become available
- Both data structures are implemented from scratch (`pqueue.cpp`, `queue.cpp`)

## Run

Open `priority_queues.sln` in Visual Studio, or compile the files in `priority_queues/` with any C++ compiler.

Data Structures course project – Misr International University (2023).

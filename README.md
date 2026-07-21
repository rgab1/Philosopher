*This project has been created as part of the 42 curriculum by grivault.*

# Philosopher

## Description

This project is a multi-threaded simulation of the classic **Dining Philosophers Problem**, a famous
computer science puzzle illustrating synchronization issues and resource allocation in concurrent
programming.The implementation models each philosopher as an independent thread running concurrently.
The forks on the table are represented using **POSIX Mutexes**, meaning two adjacent
philosophers cannot eat at the same time. The primary goal is to keep all philosophers alive through
highly precise time-tracking and synchronization management while strictly avoiding **deadlocks**
(where everyone holds one fork and waits forever) and **data races** (where threads access shared
memory concurrently without synchronization).

To achieve those objectives this program relies on:

- **POSIX Mutexes protection**: every variable that is used by multiple threads can fall victim to
**data races** if at least one of those threads tries to write to it, therefore they have to be
protected by mutexes. Mutexes are also used to protect fds so that no two threads try to print at 
the same time and end up with their outputs mixed up.
- **Asymmetric fork allocation**: even-numbered philosophers will go for their right fork first, while
odd-numbered philosophers go for their left fork first, making structural **deadlocks mathematically
impossible**.
- **Dedicated supervision thread**: the main thread continuously tracks starvation thresholds and 
meal milestone (if defined), ensuring the whole simulation cleanly stops the moment a death is
registered or the completion goal is reached.
- **Responsive smart sleep loops**: slices structural wait windows into granular micro-steps to
maintain hyper-responsive exit readiness without anchoring or burning CPU cycles.
- **Quick dumb sleep**: Staggers initial start times to eliminate **lock contention** (preventing
adjacent threads from aggressively competing for the same fork mutexes at 0ms), while also serving
as a micro-yield during thinking and monitoring routines to prevent CPU thrashing.


## Instructions

### Compilation

To compile the binary, execute:

```bash
make
```

### Execution

./philo [number_philos] [time_to_die] [time_to_eat] [time_to_sleep] [max_meals]

The Program can be executed with either 4 or 5 arguments with the following arguments :
- **first arg:** number_philos: number of philosophers that will exist in the
simulation, each philosopher is given a single fork.
- **second arg:** time_to_die: time before a philosopher die of starvation.
The philosphers will check if their time has expired while any of the other
actions are going.
- **third arg:** time_to_eat: time a philosopher takes to eat before sleeping.
- **fourth arg:** time_to_sleep: time a philosopher takes to sleep before
thinking.
- **fifth arg (optional):** max_meals: if all philosopher eat this amount of
time, the simulation stops.

Every argument has to be a positive integer greater than one to be accepted.

Examples:
standard run (survives indefinitely)
```bash
./philo 4 410 200 200
```

run with meal limit (stops automatically)
```bash
./philo 4 410 200 200 4
```

single philosopher edge case (dies at 410ms)
```bash
./philo 1 410 200 200
```

## Resources

- POSIX Threads Documentation: both in the man and online
- Mutex Synchronization Documentation: both in the man and online
- Precise Unix Time Tracking: both in the man and online
- Philosopher's problem explainations 
- AI as a learning tool to first comprehend what a thread is and to create this README


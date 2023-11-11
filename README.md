# [RTOS Implementation](https://github.com/t0ti20/My_Implementation/tree/master/RTOS/STM32F103C8/Library/RTOS)
Welcome to the repository for a custom-built RTOS designed to function on both ARM and AVR platforms. 

## Description
This RTOS has been crafted to enable multitasking capabilities in embedded systems. It provides foundational mechanisms such as task scheduling, mutex support for synchronization, context switching, and delay functionalities.

## Features
- **Task Management**: Create, run, and manage multiple tasks with unique priorities.
- **Mutex Support**: Provides a locking mechanism to ensure that resources are accessed mutually exclusively. Helpful for synchronization.
- **Task Delay**: Facilitates tasks to delay their execution for a specified number of ticks.
- **Idle Task**: Executes a customizable function when the system goes into the idle state.
- **Context Switching**: Monitors and logs context switches with an optional hook function.

## Test Cases
This RTOS has been extensively tested. Here are the test cases provided:

### Test Case 1
- Three tasks are created (`Task_1`, `Task_2`, `Task_3`) all with the same priority.
- On each context switch, GPIO port A is written with a zero value.
- During the idle state, Pin 0 of GPIO port A is set to high.
- ![Screenshot 2023-10-08 151040](https://github.com/t0ti20/My_Implementation/assets/61616031/da795197-9941-4436-ab82-ecb56eb0260f)

### Test Case 2
- Three tasks are created with different priorities (`Task_1` having the highest and `Task_3` the lowest).
- Each task toggles a unique pin on GPIO port A, and then delays its execution.
- ![Untitled](https://github.com/t0ti20/My_Implementation/assets/61616031/39e7164c-8bea-409c-bf59-6d301b376240)

### Test Case 3: Priority Inversion
- A mutex, `Mutex_1`, is introduced.
- `Task_1`, the highest priority task, attempts to acquire `Mutex_1` and toggle a pin. 
- `Task_3`, a lower-priority task than `Task_1`, also attempts to acquire `Mutex_1`. It manages to acquire the mutex before `Task_1`, leading to a situation where `Task_1` is blocked, waiting for `Task_3` to release the mutex.
- Meanwhile, `Task_2`, which has a priority between `Task_1` and `Task_3`, runs independently, toggling its pin and then delaying its execution.
- This creates a priority inversion scenario where the higher priority `Task_1` is blocked by a lower priority `Task_3` due to the mutex acquisition. During this time, `Task_2` preempts and runs its operations, extending the time `Task_1` is blocked.
- `Task_3` eventually releases the mutex after toggling a pin and activating `Task_1`.
- Note: This priority inversion scenario will be addressed and handled in the upcoming versions of this RTOS.
- ![Screenshot 2023-10-08 150836](https://github.com/t0ti20/My_Implementation/assets/61616031/9fe45f9d-1efe-455d-8f43-1a48e71abfed)

## 📊 Utilization Statistics
![Screenshot 2023-10-08 151136](https://github.com/t0ti20/My_Implementation/assets/61616031/9e6a3529-7319-4745-bf75-8f52b2003112)


## Video Demonstration
For a more comprehensive overview and a demonstration of the RTOS in action, please [watch this video](https://github.com/t0ti20/My_Implementation/assets/61616031/aeda3607-0c42-4388-ad27-9464ceeb5848).


[Video](https://github.com/t0ti20/My_Implementation/assets/61616031/aeda3607-0c42-4388-ad27-9464ceeb5848)


---

Created by Khaled El-Sayed [@t0ti20](https://github.com/t0ti20).

# CampusMessenger CLI (C++)

A terminal-based messaging platform built in C++ to demonstrate Object-Oriented Programming (OOP) concepts from a 2nd semester university course.

> Originally started as a "Facebook clone" exercise, but the core product is clearly a **messenger-focused system** (friend requests + direct messages + inbox/outbox persistence).

## Why This Project

This project showcases:
- OOP design in C++ (`Platform`, `User`, `Message`, `TextMessage`, `Post`)
- Encapsulation of user state, relationships, and messages
- Polymorphism with an abstract `Message` base class
- Basic persistence with text files (`users.txt`, `Friends.txt`, `messages.txt`)
- CLI-driven product flow (register, login, message, manage friends)

## Features

- User registration and login
- Friend request workflow (send, accept, decline)
- Direct text messaging between users
- Inbox and outbox views
- Message persistence across runs
- Basic post creation (secondary feature)

## Project Structure

- `main.cpp` - CLI menu and user interaction flow
- `Platform.h` / `Platform.cpp` - app controller and orchestration logic
- `User.h` / `User.cpp` - user model, friendship, and message boxes
- `Message.h` / `Message.cpp` - abstract message base class
- `TextMessage.h` / `TextMessage.cpp` - concrete text message implementation
- `Post.h` / `Post.cpp` - simple post model

## OOP Concepts Demonstrated

- **Abstraction**: `Message` interface defines common behavior for message types.
- **Inheritance**: `TextMessage` extends `Message`.
- **Polymorphism**: messages are handled through `std::shared_ptr<Message>`.
- **Encapsulation**: user data and social graph managed inside `User`.
- **Composition**: `Platform` manages `User` instances and routes interactions.

## Build and Run

Requirements:
- C++17-compatible compiler (`g++` or `clang++`)

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Platform.cpp User.cpp Message.cpp TextMessage.cpp Post.cpp -o campus_messenger
./campus_messenger
```

## Example Demo Flow

1. Register two users.
2. Login as user A and send a friend request to user B.
3. Login as user B and accept the request.
4. Send messages between A and B.
5. Restart the app and verify messages are restored from `messages.txt`.

## Current Limitations (Honest Engineering Notes)

- Passwords are stored in plaintext (learning-project tradeoff)
- Input validation can be improved for invalid/non-numeric menu input
- Posts are currently not persisted to disk
- Error handling and tests are minimal in current version

##  Skills Highlighted

- C++ OOP and class design
- Working with STL containers and smart pointers
- File I/O and serialization format design
- Building a complete CLI product loop from scratch
- Iterative improvement mindset (known issues documented + roadmap)

## Suggested Next Improvements

- Add robust input validation and recovery
- Hash passwords before saving
- Persist posts and add a feed view
- Add unit tests for `User` and message serialization
- Refactor naming/style for consistency

---


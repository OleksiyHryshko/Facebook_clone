/**
 * @file Message.cpp
 * @brief Implementation of the Message base class for the Facebook Clone application.
 *
 * @details
 * This file contains the implementation of the abstract Message base class, which defines the interface and core behavior for all message types
 * in the Facebook Clone social network system. Derived classes such as TextMessage extend this class to provide concrete implementations.
 *
 * Usage Example:
 * @code
 * // Abstract base class, not instantiated directly
 * // std::unique_ptr<Message> msg = std::make_unique<TextMessage>("Alice", "Bob", "Hi");
 * @endcode
 *
 * @see Message
 * @see TextMessage
 * @ingroup Messaging
 *
 * @author Your Name
 * @date 2025-06-22
 */
#include "Message.h"

/**
 * @brief Constructs a new Message object.
 *
 * @details
 * Initializes the sender and receiver fields for a message. This constructor is protected and is intended to be called by derived classes.
 *
 * @param from The sender's username.
 * @param to The recipient's username.
 * @throws std::invalid_argument if either @p from or @p to is an empty string.
 *
 * Usage Example:
 * @code
 * // Called from derived class constructor
 * TextMessage msg("Alice", "Bob", "Hello");
 * @endcode
 *
 * @ingroup Messaging
 */
Message::Message(const std::string& from, const std::string& to)
    : sender(from), receiver(to) {
    if (from.empty() || to.empty()) {
        throw std::invalid_argument("Sender and receiver usernames cannot be empty.");
    }
}

/**
 * @brief Virtual destructor for Message.
 *
 * @details
 * Ensures proper cleanup of derived message objects. Required for safe polymorphic deletion.
 *
 * @remark
 * The destructor is declared virtual to ensure that the correct derived class destructor is called when deleting a message object through a base class pointer.
 *
 * Usage Example:
 * @code
 * std::unique_ptr<Message> msg = std::make_unique<TextMessage>("A", "B", "Hi");
 * // ...
 * // msg is deleted safely
 * @endcode
 *
 * @throws None
 * @ingroup Messaging
 */
Message::~Message() {}

/**
 * @brief Gets the sender's username.
 *
 * @details
 * Returns the username of the user who sent the message.
 *
 * @return The sender's username.
 * @throws None
 *
 * Usage Example:
 * @code
 * std::string from = msg.getSender();
 * @endcode
 *
 * @ingroup Messaging
 */
std::string Message::getSender() const {
    return sender;
}

/**
 * @brief Gets the receiver's username.
 *
 * @details
 * Returns the username of the user who is the recipient of the message.
 *
 * @return The receiver's username.
 * @throws None
 *
 * Usage Example:
 * @code
 * std::string to = msg.getReceiver();
 * @endcode
 *
 * @ingroup Messaging
 */
std::string Message::getReceiver() const {
    return receiver;
}
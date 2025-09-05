/**
 * @file Message.h
 * @brief Declaration of the Message base class for the Facebook Clone application.
 *
 * @details
 * This file contains the declaration of the abstract Message base class, which defines the interface and common properties for all message types
 * in the Facebook Clone social network system. Derived classes such as TextMessage extend this class to provide concrete implementations.
 *
 * Usage Example:
 * @code
 * // Abstract base class, not instantiated directly
 * // std::unique_ptr<Message> msg = std::make_unique<TextMessage>("Alice", "Bob", "Hi");
 * @endcode
 *
 * @see TextMessage
 * @ingroup Messaging
 *
 * @author Your Name
 * @date 2025-06-22
 * @version 1.0
 */

#pragma once
#include <iostream>
#include <string>


/**
 * @class Message
 * @brief Abstract base class representing a message in the system.
 *
 * @details
 * The Message class defines the interface for all message types in the Facebook Clone application. It stores the sender and receiver information
 * and enforces implementation of the display() method in derived classes. Used as a base for polymorphic message handling.
 *
 * @see TextMessage
 * @ingroup Messaging
 */
class Message {
protected:
    std::string sender;
    std::string receiver;
    

public:
    /**
     * @brief Constructs a new Message object
     * @param from The sender's username
     * @param to The recipient's username
     */
    Message(const std::string& from, const std::string& to);
    
    /**
     * @brief Virtual destructor to ensure proper cleanup of derived classes
     */
    virtual ~Message();

    /**
     * @brief Pure virtual function to display the message
     */
    virtual void display() const = 0;
    
    /**
     * @brief Sets the sender's username
     * @param s The new sender's username
     */
    void setSender(const std::string& s) { sender = s; }
    
    /**
     * @brief Sets the recipient's username
     * @param r The new recipient's username
     */
    void setReceiver(const std::string& r) { receiver = r; }

    /**
     * @brief Gets the sender's username
     * @return std::string The sender's username
     */
    std::string getSender() const;
    
    /**
     * @brief Gets the recipient's username
     * @return std::string The recipient's username
     */
    std::string getReceiver() const;
};

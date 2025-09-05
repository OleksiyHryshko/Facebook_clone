/**
 * @file Platform.h
 * @brief Declaration of the Platform class for the Facebook Clone application.
 *
 * @details
 * This file contains the declaration of the Platform class, which acts as the main controller for the Facebook Clone social network system.
 * The Platform class manages all users, authentication, friend requests, messaging, and posts. It is responsible for all high-level
 * interactions and data persistence in the application.
 *
 * Usage Example:
 * @code
 * Platform app;
 * app.registerUser("Alice", "password");
 * app.login("Alice", "password");
 * app.sendFriendRequest("Bob");
 * @endcode
 *
 * @see User
 * @see Message
 * @see Post
 * @ingroup PlatformModule
 *
 * @author Your Name
 * @date 2025-06-22
 * @version 1.0
 */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "User.h"
#include <set>
#include <memory>
#include <map>
#include "Message.h"
#include "TextMessage.h"


/**
 * @class Platform
 * @brief Main controller class for the Facebook Clone application.
 *
 * @details
 * The Platform class encapsulates all core functionality of the Facebook Clone system, including:
 * - User registration and authentication
 * - Friend request management
 * - Messaging between users
 * - Post creation and display
 * - Data persistence for users, friends, and messages
 *
 * This class is the primary interface for all user actions and system operations.
 *
 * @see User
 * @see Message
 * @see Post
 * @ingroup PlatformModule
 */
class Platform {
private:
	std::map < std::string, std::shared_ptr<User>> users;
	std::shared_ptr<User> loggedInUser;
public:
    /**
     * @brief Default constructor
     */
    Platform();
    
    /**
     * @brief Registers a new user
     * @param uname The username for the new user
     * @param password The password for the new user
     * @return true if registration was successful, false otherwise
     */
    bool registerUser(const std::string& uname, const std::string& password);
    
    /**
     * @brief Logs in a user
     * @param uname The username
     * @param password The password
     * @return true if login was successful, false otherwise
     */
    bool login(const std::string& uname, const std::string& password);
    
    /**
     * @brief Logs out the current user
     */
    void logout();

    // Friend management
    
    /**
     * @brief Sends a friend request to another user
     * @param toname The username to send the request to
     */
    void sendFriendRequest(const std::string& toname);
    
    /**
     * @brief Accepts a pending friend request
     * @param fromname The username of the friend request to accept
     */
    void acceptFriendRequest(const std::string& fromname);
    
    /**
     * @brief Declines a pending friend request
     * @param fromname The username of the friend request to decline
     */
    void declineFriendRequest(const std::string& fromname);

    // Display functions
    
    /**
     * @brief Displays all registered users
     */
    void displayUsers() const;
    
    /**
     * @brief Displays pending friend requests for the logged-in user
     */
    void displayPendingRequests() const;
    
    /**
     * @brief Displays friends of the logged-in user
     */
    void displayFriends() const;

    // File operations
    
    /**
     * @brief Saves all users' credentials to a file
     */
    void saveAllUsersnamepassw();
    
    /**
     * @brief Saves all users' friend lists to a file
     */
    void saveAllUsersFriend();
    
    /**
     * @brief Loads basic user data from file
     */
    void loadUsersBasic();
    
    /**
     * @brief Loads friend relationships from file
     */
    void loadUsersFriends();

    // Messaging
    
    /**
     * @brief Sends a message to another user
     * @param toUser The recipient's username
     * @param content The message content
     */
    void sendMessage(const std::string& toUser, const std::string& content);
    
    /**
     * @brief Displays all messages for the logged-in user
     */
    void displayMessages() const;

    // Message persistence
    
    /**
     * @brief Saves all messages to files
     */
    void saveAllMessages();
    
    /**
     * @brief Loads all messages from files
     */
    void loadAllMessages();
    
    // Post functionality
    
    /**
     * @brief Creates a new post for the logged-in user
     * @param content The content of the post
     */
    void createPost(const std::string& content);
};
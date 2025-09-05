/**
 * @file User.h
 * @brief Declaration of the User class for the Facebook Clone application.
 *
 * @details
 * This file contains the declaration of the User class, which represents a user in the Facebook Clone social network system.
 * The User class manages user data, authentication, friend management, messaging, and posts. It is used by the Platform class to perform all user-related actions.
 *
 * Usage Example:
 * @code
 * User alice("Alice", "password");
 * alice.addFriend("Bob");
 * alice.addPost(std::make_shared<Post>("Alice", "Hello!"));
 * @endcode
 *
 * @see Platform
 * @see Post
 * @see Message
 * @ingroup Users
 */

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Message.h"
#include "TextMessage.h"
#include "Post.h"



/**
 * @class User
 * @brief Represents a user in the social network system.
 *
 * @details
 * The User class encapsulates all user-related data and operations including authentication, friend management, messaging, and post management.
 * It provides methods for sending and accepting friend requests, sending and receiving messages, and managing posts. Used by the Platform class
 * to manage users and their interactions.
 *
 * @see Platform
 * @see Post
 * @see Message
 * @ingroup Users
 */
class User {
private:
    std::string name;                                ///< The username of the user
    std::string password;                            ///< The user's password (stored in plaintext, not secure for production)

    std::vector<std::string> friends;                ///< List of confirmed friends' usernames
    std::vector<std::string> pendingRequests;        ///< List of pending friend requests received
    std::vector<std::string> sentRequests;           ///< List of friend requests sent by this user

    std::vector<std::shared_ptr<Message>> inbox;     ///< Incoming messages
    std::vector<std::shared_ptr<Message>> outbox;    ///< Sent messages
    
    std::vector<std::shared_ptr<Post>> posts;        ///< User's posts

public:
    /**
     * @brief Constructs a new User object
     * @param uname The username for the new user
     * @param passw The password for the new user
     */
    User(std::string uname, std::string passw);
    
    /**
     * @brief Gets the username
     * @return std::string The username
     */
    std::string Getname() const;
    
    /**
     * @brief Validates a password against the user's stored password
     * @param upassw The password to check
     * @return true if the password matches, false otherwise
     */
    bool Checkpassw(std::string upassw);
    
    /**
     * @brief Sends a friend request to another user
     * @param toname The username to send the request to
     */
    void sendrequest(std::string toname);
    
    /**
     * @brief Called when this user receives a friend request
     * @param fromname The username of the requester
     */
    void gotrequest(std::string fromname);
    
    /**
     * @brief Accepts a pending friend request
     * @param fromUsername The username of the friend request to accept
     */
    void acceptRequest(std::string fromUsername);
    
    /**
     * @brief Declines a pending friend request
     * @param fromUsername The username of the friend request to decline
     */
    void declineRequest(std::string fromUsername);
    
    /**
     * @brief Checks if a specific user has a pending friend request
     * @param fromUsername The username to check
     * @return true if there's a pending request, false otherwise
     */
    bool hasPendingRequest(std::string fromUsername);
    
    /**
     * @brief Adds a user to this user's friend list
     * @param friendName The username to add as a friend
     */
    void addFriend(const std::string& friendName);
    
    /**
     * @brief Called when a friend request is declined
     * @param friendName The username that declined the request
     */
    void urrequestwasdeclined(const std::string& friendName);
    
    /**
     * @brief Gets the list of pending friend requests
     * @return const std::vector<std::string>& Reference to the list of pending requests
     */
    const std::vector<std::string>& getPendingRequests() const;
    
    /**
     * @brief Gets the list of friends
     * @return const std::vector<std::string>& Reference to the list of friends
     */
    const std::vector<std::string>& getFriends() const;
    
    /**
     * @brief Saves user credentials to a stream
     * @param out The output stream to write to
     */
    void saveToStreamUsersnamepassw(std::ostream& out) const;
    
    /**
     * @brief Saves friend information to a stream
     * @param out The output stream to write to
     */
    void saveToStreamFriend(std::ostream& out) const;
    //for loading
    /**
     * @brief Sets the list of friends
     * @param f The new list of friends
     */
    void setFriends(const std::vector<std::string>& f);
    
    /**
     * @brief Sets the list of pending friend requests
     * @param p The new list of pending requests
     */
    void setPendingRequests(const std::vector<std::string>& p);
    
    /**
     * @brief Sets the list of sent friend requests
     * @param s The new list of sent requests
     */
    void setSentRequests(const std::vector<std::string>& s);
    // Messaging
    /**
     * @brief Sends a message to another user
     * @param message The message to send
     */
    void sendMessage(const std::shared_ptr<Message>& message);
    
    /**
     * @brief Adds a message to the outbox
     * @param message The message to add
     */
    void addToOutbox(const std::shared_ptr<Message>& message);
    
    /**
     * @brief Gets the list of incoming messages
     * @return const std::vector<std::shared_ptr<Message>>& Reference to the list of incoming messages
     */
    const std::vector<std::shared_ptr<Message>>& getInbox() const { return inbox; }
    
    /**
     * @brief Gets the list of sent messages
     * @return const std::vector<std::shared_ptr<Message>>& Reference to the list of sent messages
     */
    const std::vector<std::shared_ptr<Message>>& getOutbox() const { return outbox; }
    
    /**
     * @brief Saves messages to a file
     * @param out The output file stream to write to
     */
    void saveMessagesToFile(std::ofstream& out) const;
    
    /**
     * @brief Loads messages from a file
     * @param in The input file stream to read from
     */
    void loadMessagesFromFile(std::ifstream& in);
    
    /**
     * @brief Adds a post to the user's list of posts
     * @param post The post to add
     */
    void addPost(const std::shared_ptr<Post>& post);
    
    /**
     * @brief Gets the list of posts
     * @return const std::vector<std::shared_ptr<Post>>& Reference to the list of posts
     */
    const std::vector<std::shared_ptr<Post>>& getPosts() const;

};
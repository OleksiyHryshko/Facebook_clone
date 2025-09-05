/**
 * @file Post.h
 * @brief Declaration of the Post class for the Facebook Clone application.
 *
 * @details
 * This file contains the declaration of the Post class, which represents a single user post in the Facebook Clone social network system.
 * The Post class encapsulates the author's username and the content of the post, providing methods for access and manipulation.
 *
 * Usage Example:
 * @code
 * Post post("Alice", "This is my first post!");
 * std::cout << post.getContent();
 * @endcode
 *
 * @see User
 * @ingroup Posting
 *
 * @author Your Name
 * @date 2025-06-22
 * @version 1.0
 */

#pragma once
#include <iostream>
#include <vector>

/**
 * @class Post
 * @brief Represents a user's post in the social network.
 *
 * @details
 * The Post class encapsulates the data and functionality related to user posts in the Facebook Clone application.
 * It stores the author's username and the content of the post, and provides accessors for these fields. Used by the User and Platform classes
 * to manage and display posts.
 *
 * @see User
 * @ingroup Posting
 */
class Post {
private:
    /**
     * @brief The username of the post's author.
     */
    std::string author;
    /**
     * @brief The content of the post.
     */
    std::string content;
    
public:
    /**
     * @brief Constructs a new Post object
     * @param author The username of the post's author
     * @param content The content of the post
     */
    Post(const std::string& author, const std::string& content);
    
    /**
     * @brief Gets the author's username
     * @return const std::string& The author's username
     */
    const std::string& getAuthor() const { return author; }
    
    /**
     * @brief Gets the post content
     * @return const std::string& The post content
     */
    const std::string& getContent() const { return content; }
};
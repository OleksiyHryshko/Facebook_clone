

#pragma once
#include "Message.h"
#include <string>
#include <fstream>


class TextMessage : public Message {
private:
    
    std::string content;

public:
    
    TextMessage(const std::string& from, const std::string& to, const std::string& text);
    
   
    TextMessage() : Message("", ""), content("") {}
    
    
    void display() const override;
   
    const std::string& getContent() const { return content; }
    
    /**
     * @brief Saves the message to a file.
     *
     * @details
     * Serializes the message to the specified output file stream. The format includes the sender, receiver, and content.
     *
     * Usage Example:
     * @code
     * std::ofstream out("messages.txt");
     * msg.savetoFile(out);
     * @endcode
     *
     * @param out The output file stream to write to. Must be open for writing.
     * @throws std::runtime_error if the stream is not open or writing fails.
     * @remark Used by the Platform and User classes to persist messages.
     * @see loadFromFile()
     * @ingroup Messaging
     */
    void savetoFile(std::ofstream& out);
    
    /**
     * @brief Loads the message from a file.
     *
     * @details
     * Reads the message fields from the specified input file stream and populates the object. The format must match that used by savetoFile().
     *
     * Usage Example:
     * @code
     * std::ifstream in("messages.txt");
     * msg.loadFromFile(in);
     * @endcode
     *
     * @param in The input file stream to read from. Must be open for reading.
     * @throws std::runtime_error if the stream is not open or reading fails.
     * @remark Used by the Platform and User classes to restore messages.
     * @see savetoFile()
     * @ingroup Messaging
     */
    void loadFromFile(std::ifstream& in);
    
    /**
     * @brief Sets the message content.
     *
     * @details
     * Updates the content of the message. Does not affect sender or receiver. Used for editing or initializing empty messages.
     *
     * Usage Example:
     * @code
     * msg.setContent("New message text");
     * @endcode
     *
     * @param c The new message content.
     * @see getContent()
     * @ingroup Messaging
     */
    void setContent(const std::string& c) { content = c; }
};

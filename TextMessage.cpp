/**
 * @file TextMessage.cpp
 * @brief Implementation of the TextMessage class for the Facebook Clone application.
 *
 * This file contains the implementation of the TextMessage class, which represents a text-based message
 * and provides methods for displaying, saving, and loading messages in the Facebook Clone system.
 *
 * @author Your Name
 * @date 2025-06-22
 */
#include "TextMessage.h"
#include <iostream>


TextMessage::TextMessage(const std::string& from, const std::string& to, const std::string& text)
    : Message(from, to), content(text) {
}

void TextMessage::display() const {
    std::cout << sender << " - " << receiver << ": " << content << std::endl;
}
void TextMessage::savetoFile(std::ofstream& out) {
    if (!out.is_open()) {
        throw std::runtime_error("Cannot save: Output file stream is not open");
    }

    
    out << "TEXT\n";
    
    out << getSender() << "\n";
    out << getReceiver() << "\n";
    out << getContent() << "\n";
   
   

    if (out.fail()) {
        throw std::runtime_error("Failed to write message to file");
    }
}
void TextMessage::loadFromFile(std::ifstream& in) {
    std::string sender, receiver, content;

    std::getline(in, sender);
    std::getline(in, receiver);
    std::getline(in, content);

    setSender(sender);
    setReceiver(receiver);
    setContent(content);
}

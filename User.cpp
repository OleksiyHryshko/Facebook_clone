/**
 * @file User.cpp
 * @brief Implementation of the User class for the Facebook Clone application.
 *
 * This file contains the implementation of the User class, which manages user data, authentication,
 * friend requests, messaging, and posts within the Facebook Clone social network system.
 *
 * @author Your Name
 * @date 2025-06-22
 */
#include "User.h"



User::User(std::string uname, std::string pass)
	: name(uname),
	password(pass),
	friends(),
	pendingRequests(),
	sentRequests(),
	inbox(),
	outbox(),
	posts() // Initialize posts
{
}





std::string User::Getname() const {
	return name;
}
bool User::Checkpassw(std::string upassw) {
	return upassw == password;
}
void User::sendrequest(std::string toname){
	if (name != toname && std::find(sentRequests.begin(), sentRequests.end(), toname) == sentRequests.end()) {
		sentRequests.push_back(toname);
	}
}
void User::gotrequest(std::string fromname){
	if (name != fromname && std::find(pendingRequests.begin(), pendingRequests.end(), fromname)==pendingRequests.end()) {
		pendingRequests.push_back(fromname);
	}
}
void User::acceptRequest(std::string fromUsername) {
	if (std::find(friends.begin(), friends.end(), fromUsername) == friends.end()) {
		friends.push_back(fromUsername);
	}

	auto it = std::find(pendingRequests.begin(), pendingRequests.end(), fromUsername);
	if (it != pendingRequests.end()) {
		pendingRequests.erase(it);
	}

}
void User::declineRequest(std::string fromUsername) {
	auto it = std::find(pendingRequests.begin(), pendingRequests.end(), fromUsername);
	if (it != pendingRequests.end()) {
		pendingRequests.erase(it);
	}
}
bool User::hasPendingRequest(std::string fromUsername) {
	return std::find(pendingRequests.begin(), pendingRequests.end(), fromUsername)!=pendingRequests.end();
}



void User::addFriend(const std::string& friendName) {
	if (std::find(friends.begin(), friends.end(), friendName) == friends.end()) {
		friends.push_back(friendName);
	}
	auto it = std::find(sentRequests.begin(), sentRequests.end(), friendName);
	if (it != sentRequests.end()) {
		sentRequests.erase(it);
	}
	auto pit = std::find(pendingRequests.begin(), pendingRequests.end(), friendName);
	if (pit != pendingRequests.end()) {
		pendingRequests.erase(pit);
	}
}
void User::urrequestwasdeclined(const std::string& friendName) {
	auto it = std::find(sentRequests.begin(), sentRequests.end(), friendName);
	if (it != sentRequests.end()) {
		sentRequests.erase(it);
	}
}

const std::vector<std::string>& User::getPendingRequests() const {
	return pendingRequests;
}
const std::vector<std::string>& User::getFriends() const {
	return friends;
}

//Files
void User::saveToStreamUsersnamepassw(std::ostream& out) const {
	out << name << "\n";
	out << password << "\n";

	
}
void User::saveToStreamFriend(std::ostream& out) const {
	out << name << "\n";

	out << friends.size();
	for (const auto& f : friends)
		out << " " << f;
	out << "\n";

	out << pendingRequests.size();
	for (const auto& r : pendingRequests)
		out << " " << r;
	out << "\n";

	out << sentRequests.size();
	for (const auto& r : sentRequests)
		out << " " << r;
	out << "\n";
}
void User::setFriends(const std::vector<std::string>& f) {
	friends = f;
}
void User::setPendingRequests(const std::vector<std::string>& p) {
	pendingRequests = p;
}
void User::setSentRequests(const std::vector<std::string>& s) {
	sentRequests = s;
}

// Messaging

void User::sendMessage(const std::shared_ptr<Message>& message) {
	if (!message) return;
	inbox.push_back(message);
}

void User::addToOutbox(const std::shared_ptr<Message>& message) {
	if (!message) return;
	
	outbox.push_back(message);
}
//Messaging storing


void User::saveMessagesToFile(std::ofstream& out) const {
	if (!out.is_open()) return;

	
	out << "OUTBOX " << outbox.size() << "\n";
	for (const auto& msg : outbox) {
		if (auto textMsg = std::dynamic_pointer_cast<TextMessage>(msg)) {
			textMsg->savetoFile(out);
		}
	}

	
	out << "INBOX " << inbox.size() << "\n";
	for (const auto& msg : inbox) {
		if (auto textMsg = std::dynamic_pointer_cast<TextMessage>(msg)) {
			textMsg->savetoFile(out);
		}
	}
}
void User::loadMessagesFromFile(std::ifstream& in) {
	std::string label;
	size_t count;

	in >> label >> count;
	in.ignore(); 

	if (label == "OUTBOX") {
		for (size_t i = 0; i < count; ++i) {
			std::string type;
			std::getline(in, type);
			if (type == "TEXT") {
				auto msg = std::make_shared<TextMessage>();
				msg->loadFromFile(in);
				outbox.push_back(msg);
			}
		}
	}

	in >> label >> count;
	in.ignore(); // newline

	if (label == "INBOX") {
		for (size_t i = 0; i < count; ++i) {
			std::string type;
			std::getline(in, type);
			if (type == "TEXT") {
				auto msg = std::make_shared<TextMessage>();
				msg->loadFromFile(in);
				inbox.push_back(msg);
			}
		}
	}
}
//Post 
void User::addPost(const std::shared_ptr<Post>& post) {
	if (post) posts.push_back(post);
}

const std::vector<std::shared_ptr<Post>>& User::getPosts() const {
	return posts;
}


/**
 * @file Platform.cpp
 * @brief Implementation of the Platform class for the Facebook Clone application.
 *
 * @details
 * This file contains the implementation of the Platform class, which acts as the main controller for the Facebook Clone social network system.
 * It manages users, authentication, friend requests, messaging, and posts. All user actions and data persistence are handled through this class.
 *
 * Usage Example:
 * @code
 * Platform app;
 * app.registerUser("Alice", "password");
 * app.login("Alice", "password");
 * app.sendFriendRequest("Bob");
 * @endcode
 *
 * @see Platform
 * @see User
 * @see Message
 * @see Post
 * @ingroup PlatformModule
 *
 * @author Your Name
 * @date 2025-06-22
 */
#include "Platform.h"


/**
 * @brief Constructs a new Platform object.
 *
 * @details
 * Initializes the platform with no logged-in user. Sets up the internal data structures for managing users, friends, messages, and posts.
 *
 * Usage Example:
 * @code
 * Platform app;
 * @endcode
 *
 * @ingroup PlatformModule
 */
Platform::Platform(): loggedInUser(nullptr){}

/**
 * @brief Registers a new user with the platform.
 *
 * @details
 * Adds a new user to the platform with the specified username and password. If the username already exists, registration fails.
 *
 * Usage Example:
 * @code
 * bool success = app.registerUser("Alice", "password");
 * @endcode
 *
 * @param uname The desired username. Must be unique.
 * @param password The password for the new account.
 * @return true if registration was successful.
 * @return false if username already exists.
 * @remark Usernames are case-sensitive.
 * @see login()
 * @ingroup PlatformModule
 */
bool Platform::registerUser(const std::string& uname, const std::string& password) {
	if (users.find(uname) != users.end()) {
		std::cout << "User already exists.\n";
		return false;
	}
	users[uname] = std::make_shared<User>(uname, password);
	std::cout << "User " << uname << " registered successfully.\n";
	return true;
}
/**
 * @brief Authenticates and logs in a user.
 *
 * @details
 * Verifies the provided credentials and logs in the user if successful. Updates the loggedInUser pointer.
 *
 * Usage Example:
 * @code
 * bool loggedIn = app.login("Alice", "password");
 * @endcode
 *
 * @param uname The username to log in with.
 * @param password The password to verify.
 * @return true if login was successful.
 * @return false if login failed (invalid credentials or user not found).
 * @remark Only one user can be logged in at a time.
 * @see logout()
 * @ingroup PlatformModule
 */
bool Platform::login(const std::string& uname, const std::string& password) {
	auto it = users.find(uname);
	if (it != users.end() && it->second->Checkpassw(password)) {
		loggedInUser=it->second;
		std::cout << "Logged in as " << uname << ".\n";
		return true;


	}
	std::cout << "Login failed.\n";
	return false;
}

/**
 * @brief Logs out the currently logged-in user.
 *
 * @details
 * Clears the current user session and notifies of logout. After calling this method, no user will be logged in until login() is called again.
 *
 * Usage Example:
 * @code
 * app.logout();
 * @endcode
 *
 * @throws None
 * @remark If no user is logged in, a message is displayed.
 * @see login()
 * @ingroup PlatformModule
 */
void Platform::logout(){
	if (loggedInUser) {
		std::cout << loggedInUser->Getname() << " logged out.\n";
		loggedInUser = nullptr;
	}
	else {
		std::cout << "No user is logged in.\n";
	}
}
/**
 * @brief Sends a friend request to another user.
 *
 * @details
 * Sends a friend request from the currently logged-in user to another user. Updates both users' pending and sent request lists.
 *
 * Usage Example:
 * @code
 * app.sendFriendRequest("Bob");
 * @endcode
 *
 * @param toname The username to send the friend request to.
 * @throws None
 * @remark The recipient must exist and the sender must be logged in.
 * @see acceptFriendRequest()
 * @see declineFriendRequest()
 * @ingroup PlatformModule
 */
void Platform::sendFriendRequest(const std::string& toname) {
	if (!loggedInUser) {
		std::cout << "Please log in first.\n";
		return;
	}
	auto it = users.find(toname);
		if (it != users.end()) {
			loggedInUser->sendrequest(toname);
			it->second->gotrequest(loggedInUser->Getname());
			std::cout << "Friend request sent to " << toname << ".\n";
	}
		else {
			std::cout << "User not found.\n";
		}
}


/**
 * @brief Accepts a pending friend request
 * 
 * @param fromname The username whose friend request to accept
 */
void Platform::acceptFriendRequest(const std::string& fromname) {
	if (!loggedInUser) {
		std::cout << "Please log in first.\n";
		return;
	}
	if (!loggedInUser->hasPendingRequest(fromname)) {
		std::cout << "No friend request from " << fromname << ".\n";
		return;
	}
	loggedInUser->acceptRequest(fromname);
	auto it = users.find(fromname);
	if (it != users.end()) {
		it->second->addFriend(loggedInUser->Getname());
	}
	std::cout << "Friend request from " << fromname << " accepted.\n";

}


/**
 * @brief Declines a pending friend request
 * 
 * @param fromname The username whose friend request to decline
 */
void Platform::declineFriendRequest(const std::string& fromname) {
	if (!loggedInUser) {
		std::cout << "Please log in first.\n";
		return;
	}
	if (!loggedInUser->hasPendingRequest(fromname)) {
		std::cout << "No friend request from " << fromname << ".\n";
		return;
	}
	loggedInUser->declineRequest(fromname);
	auto it = users.find(fromname);
	if (it != users.end()) {
		it->second->urrequestwasdeclined(loggedInUser->Getname());
	}
	std::cout << "Friend request from " << fromname << " declined.\n";

}

/**
 * @brief Displays all registered users
 * 
 * Outputs a list of all usernames in the system
 */
void Platform::displayUsers() const {
	std::cout << "Registered Users:\n";
	for (const auto& pair : users) {
		std::cout << "- " << pair.first << std::endl;
	}
}
/**
 * @brief Displays pending friend requests for the logged-in user
 * 
 * Shows all users who have sent friend requests to the current user
 */
void Platform::displayPendingRequests() const {
	if (!loggedInUser) {
		std::cout << "Please log in first.\n";
		return;
	}
	std::cout << "Pending Friend Requests:\n";
	const auto& pending = loggedInUser->getPendingRequests();
	for (const auto& name : pending) {
		std::cout << "- " << name << std::endl;
	}
	

}
/**
 * @brief Displays all friends of the logged-in user
 * 
 * Shows a list of all confirmed friends
 */
void Platform::displayFriends() const {
	if (!loggedInUser) {
		std::cout << "Please log in first.\n";
		return;
	}
	std::cout << "Your Friends:\n";
	const auto& friends = loggedInUser->getFriends();
	for (const auto& name : friends) {
		std::cout << "- " << name << '\n';
	}
}

// files
/**
 * @brief Saves all usernames and passwords to a file
 * 
 * Writes user credentials to 'users.txt' in the working directory
 */
void Platform::saveAllUsersnamepassw() {
	std::ofstream out("users.txt");
	if (!out) {
		std::cerr << "Can't save users.\n";
		return;
	}
	out << users.size() << "\n";
	

	for (const auto& pair : users) {
		std::shared_ptr<User> user = pair.second;
		user->saveToStreamUsersnamepassw(out);
	}
}
/**
 * @brief Saves all friend relationships to a file
 * 
 * Writes friend lists to 'Friends.txt' in the working directory
 */
void Platform::saveAllUsersFriend() {
	std::ofstream out("Friends.txt");
	if (!out) {
		std::cerr << "Can't save friends data.\n";
		return;
	}

	for (const auto& pair : users) {
		std::shared_ptr<User> user = pair.second;
		user->saveToStreamFriend(out);
	}
}

/**
 * @brief Loads basic user data from file
 * 
 * Reads usernames and passwords from 'users.txt'
 */
void Platform::loadUsersBasic() {
	std::ifstream in("users.txt");
	if (!in) {
		std::cerr << "Can't open users.txt\n";
		return;
	}
	in.seekg(0, std::ios::end); 
	if (in.tellg() == 0) {
		
		std::cout << "users.txt is empty. No users to load.\n";
		return;
	}

	in.seekg(0);

	size_t count;
	in >> count;
	in.ignore(); 

	for (size_t i = 0; i < count; ++i) {
		std::string name, password;
		std::getline(in, name);
		std::getline(in, password);
		if (name.empty() || password.empty()) {
			std::cerr << "Invalid user data for user #" << i << "\n";
			continue;
		}

		users[name] = std::make_shared<User>(name, password);
	}
}

/**
 * @brief Loads friend relationships from file
 * 
 * Reads friend lists from 'Friends.txt' and updates user relationships
 */
void Platform::loadUsersFriends() {
	std::ifstream in("Friends.txt");
	if (!in) {
		std::cerr << "Can't open Friends.txt\n";
		return;
	}
	in.seekg(0, std::ios::end); 
	if (in.tellg() == 0) {
		
		std::cout << "Friends.txt is empty. No users to load.\n";
		return;
	}

	in.seekg(0);
	auto readList = [&](std::istream& stream) -> std::vector<std::string> {
		size_t n;
		stream >> n;
		std::vector<std::string> v(n);
		for (size_t i = 0; i < n; ++i) {
			stream >> v[i];
		}
		stream.ignore(); 
		return v;
		};

	while (in) {
		std::string name;
		std::getline(in, name);
		if (name.empty()) continue;

		auto it = users.find(name);
		if (it == users.end()) {
			std::cerr << "User " << name << " not found\n";
			
			continue;
		}

		auto user = it->second;
		user->setFriends(readList(in));           
		user->setPendingRequests(readList(in));
		user->setSentRequests(readList(in));
	}
}

// Messeging
/**
 * @brief Sends a message to another user
 * 
 * @param toUser The recipient's username
 * @param content The message content to send
 */
void Platform::sendMessage(const std::string& toUser, const std::string& content) {
	auto it = users.find(toUser);
	if (it == users.end()) {
		std::cout << "User " << toUser << " not found.\n";
		return;
	}

	auto recipient = it->second;
	auto message = std::make_shared<TextMessage>(loggedInUser->Getname(), toUser, content);

	// Add to sender's outbox
	loggedInUser->addToOutbox(message);
	// Add to recipient's inbox
	recipient->sendMessage(message);

	std::cout << "Message sent to " << toUser << ".\n";

	// Save messages after sending
	saveAllMessages();
}
/**
 * @brief Displays all messages for the logged-in user
 * 
 * Shows both received (inbox) and sent (outbox) messages
 */
void Platform::displayMessages() const{
	
	auto inbox = loggedInUser->getInbox();
	auto outbox = loggedInUser->getOutbox();

	std::cout << "=== Inbox (" << inbox.size() << " messages) ===\n";
	if (inbox.empty()) {
		std::cout << "No incoming messages.\n";
	}
	else {
		for (const auto& msg : inbox) {
			if (auto textMsg = std::dynamic_pointer_cast<TextMessage>(msg)) {
				std::cout << "From: " << textMsg->getSender() << " | "
					<< textMsg->getContent()  << "\n";
			}
		}
	}
	std::cout << "\n=== Sent Messages (" << outbox.size() << " messages) ===\n";
	if (outbox.empty()) {
		std::cout << "No sent messages.\n";
	}
	else {
		for (const auto& msg : outbox) {
			if (auto textMsg = std::dynamic_pointer_cast<TextMessage>(msg)) {
				std::cout << "To: " << textMsg->getReceiver() << " | "
					<< textMsg->getContent() << "\n";
			}
		}
	}
}

/**
 * @brief Saves all messages to a file
 * 
 * Persists all user messages to 'messages.txt'
 */
void Platform::saveAllMessages() {
	std::ofstream out("messages.txt");
	if (!out) {
		std::cerr << "Failed to open messages.txt for writing\n";
		return;
	}

	// Save all users' messages
	out << users.size() << "\n";
	for (const auto& pair : users) {
		const auto& user = pair.second;
		out << user->Getname() << "\n";
		user->saveMessagesToFile(out);
	}
}

/**
 * @brief Loads all messages from file
 * 
 * Restores messages from 'messages.txt' to user inboxes/outboxes
 */
void Platform::loadAllMessages() {
	std::ifstream in("messages.txt");
	if (!in) {
		std::cerr << "Failed to open messages.txt for reading\n";
		return;
	}

	size_t userCount;
	in >> userCount;
	in.ignore(); 

	for (size_t i = 0; i < userCount; ++i) {
		std::string username;
		std::getline(in, username);

		auto it = users.find(username);
		if (it != users.end()) {
			it->second->loadMessagesFromFile(in);
		}
		else {
			std::cerr << "User not found while loading messages: " << username << "\n";
			
		}
	}
}

/**
 * @brief Creates a new post for the logged-in user
 * 
 * @param content The content of the post to create
 */
void Platform::createPost(const std::string& content) {
	if (!loggedInUser) {
		std::cout << "No user logged in.\n";
		return;
	}
	auto post = std::make_shared<Post>(loggedInUser->Getname(), content);
	loggedInUser->addPost(post);
	std::cout << "Post created!\n";
}



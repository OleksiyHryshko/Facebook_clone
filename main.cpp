

#include "Platform.h"



int main() {
   Platform app; 
   
   app.loadUsersBasic();
   app.loadUsersFriends();
   app.loadAllMessages();
   std::string username, password;
   bool loggedIn = false;

   while (!loggedIn) {
       std::cout << "\n--- Welcome to CampusMessenger CLI ---\n";
       std::cout << "1. Register\n";
       std::cout << "2. Login\n";
       std::cout << "0. Exit\n";
       std::cout << "Choose: ";

       int choice;
       std::cin >> choice;
       std::cin.ignore();

       switch (choice) {
       case 1:
           std::cout << "New Username: "; std::getline(std::cin, username);
           std::cout << "New Password: "; std::getline(std::cin, password);
           if (app.registerUser(username, password)) {
               std::cout << "Registration successful! Please log in.\n";
           }
           break;

       case 2:
           std::cout << "Username: "; std::getline(std::cin, username);
           std::cout << "Password: "; std::getline(std::cin, password);
           if (app.login(username, password)) {
               loggedIn = true;
           }
           else {
               std::cout << "Login failed. Try again.\n";
           }
           break;

       case 0:
           std::cout << "Goodbye!\n";
           return 0;

       default:
           std::cout << "Invalid choice.\n";
       }
   }

  
   int choice;
   do {
       std::cout << "\n--- Logged in as " << username << " ---\n";
       std::cout << "1. Send Friend Request\n";
       std::cout << "2. Accept Friend Request\n";
       std::cout << "3. View Friends\n";
       std::cout << "4. View Pending Requests\n";
       std::cout << "5. Send Message\n";
       std::cout << "6. View Messages\n";     
       std::cout << "7. Make Post\n";
       std::cout << "0. Logout and Exit\n";
       std::cout << "Choose: ";
       std::cin >> choice;
       std::cin.ignore();

       std::string target, message;

       switch (choice) {
       case 1:
           std::cout << "Send request to: "; std::getline(std::cin, target);
           app.sendFriendRequest(target);
           break;

       case 2:
           std::cout << "Accept request from: "; std::getline(std::cin, target);
           app.acceptFriendRequest(target);
           break;

       case 3:
           app.displayFriends();
           break;

       case 4:
           app.displayPendingRequests();
           break;

       case 5:
           std::cout << "Send message to: "; std::getline(std::cin, target);
           std::cout << "Message content: "; std::getline(std::cin, message);
           app.sendMessage(target, message);
           break;

       case 6:
           app.displayMessages();
           break;
       case 7:
           std::cout << "Post text: "; std::getline(std::cin, message);
           app.createPost(message);
           break;

       case 0:
           std::cout << "Saving all users...\n";
           app.saveAllUsersnamepassw();
           app.saveAllUsersFriend();
           std::cout << "Goodbye!\n";
           break;

       default:
           std::cout << "Invalid choice.\n";
       }

   } while (choice != 0);
}



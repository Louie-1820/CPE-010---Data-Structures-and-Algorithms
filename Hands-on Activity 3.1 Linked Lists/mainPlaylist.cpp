#include <iostream>
#include <string>
#include "playlist_ll.h"

void displayMenu() {
    std::cout << "\n====================================" << std::endl;
    std::cout << "       MUSIC PLAYLIST MENU          "  << std::endl
    std::cout << "====================================" << std::endl;
    std::cout << "1. Insert Song at Beginning"  << std::endl;
    std::cout << "2. Insert Song at End" << std::endl;
    std::cout << "3. Next Song" << std::endl;
    std::cout << "4. Previous Song" << std::endl;
    std::cout << "5. Display Currently Playing Song" << std::endl;
    std::cout << "6. Play All Songs (Loop Traversal)" << std::endl;
    std::cout << "7. Remove a Song" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Enter choice: ";
}

int main() {
    circList<std::string>* playlistHead = nullptr;
    circList<std::string>* currentSong = nullptr;
    
    int choice = 0;
    std::string songTitle;

    while (true) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin.ignore(); // Clear newline left in buffer

        switch (choice) {
            case 1:
                std::cout << "Enter song title to insert at start: ";
                std::getline(std::cin, songTitle);
                insertHead(songTitle, &playlistHead);
                
                // Set currentSong to head if this is the first song inserted
                if (currentSong == nullptr) {
                    currentSong = playlistHead;
                }
                std::cout << "\"" << songTitle << "\" added to the start.\n";
                break;

            case 2:
                std::cout << "Enter song title to insert at end: ";
                std::getline(std::cin, songTitle);
                
                if (playlistHead == nullptr) {
                    insertHead(songTitle, &playlistHead);
                    currentSong = playlistHead;
                } else {
                    insertEnd(songTitle, playlistHead);
                }
                std::cout << "\"" << songTitle << "\" added to the end.\n";
                break;

            case 3:
                if (currentSong == nullptr) {
                    std::cout << "Playlist is empty." << std::endl;
                } else {
                    nextSong(&currentSong);
                    std::cout << "Now playing: " << currentSong->data << "\n";
                }
                break;

            case 4:
                if (currentSong == nullptr) {
                    std::cout << "Playlist is empty." << std::endl;
                } else {
                    prevSong(&currentSong);
                    std::cout << "Now playing: " << currentSong->data << "\n";
                }
                break;

            case 5:
                std::cout << "Currently Playing: ";
                displayCurrent(currentSong);
                break;

            case 6:
                std::cout << "\n--- Playing All Songs --- " << std::endl;
                playAll(playlistHead);
                break;

            case 7:
                if (playlistHead == nullptr) {
                    std::cout << "Playlist is empty." << std::endl;
                    break;
                }
                std::cout << "Enter song title to remove: ";
                std::getline(std::cin, songTitle);
                deleteNode(songTitle, &playlistHead, &currentSong);
                break;

            case 8:
                std::cout << "Cleaning up memory and exiting..." << std::endl;
                destroyList(&playlistHead);
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
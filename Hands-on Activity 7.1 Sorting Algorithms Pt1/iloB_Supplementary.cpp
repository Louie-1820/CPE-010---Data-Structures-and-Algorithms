#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ilob_Supplementary_Header.h"

const int total_votes = 100;

int main() {
    int votes[total_votes];
    int counts[6] = {0}; 
    
    std::string candidates[] = {
        "",
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    srand(time(0));

    for (int i = 0; i < total_votes; i++) {
        votes[i] = (rand() % 5) + 1;
    }

    // Sorting of votes array
    insertionSort(votes, total_votes);

    // Counting of votes sequentially
    for (int i = 0; i < total_votes; i++) {
        counts[votes[i]]++;
    }

    // Display the Sorted Array
    std::cout << "==========================================" << std::endl;
    std::cout << "Sorted Array of Votes:\n";
    for (int i = 0; i < total_votes; i++) {
        std::cout << votes[i] << " ";
        if ((i + 1) % 20 == 0) std::cout << "\n";
    }
    std::cout << "==========================================" << std::endl;

    // Display Vote Counts and check who is the  Winner
    std::cout << "\n ============== ELECTION RESULTS ============== \n";
    int maxVotes = -1;
    int winnerID = 1;

    for (int i = 1; i <= 5; i++) {
        std::cout << "Candidate " << i << " (" << candidates[i] << "): " << counts[i] << " votes\n";
        if (counts[i] > maxVotes) {
            maxVotes = counts[i];
            winnerID = i;
        }
    }

    std::cout << "\nWINNING CANDIDATE: " << candidates[winnerID] << " with " << maxVotes << " votes!\n";
    std::cout << "==========================================";

    return 0;
}
#include <iostream>
#include "printer.h"

// Simulating a Scenario
int main() {
    Printer officePrinter;

    std::cout << "======================================" << std::endl;
    std::cout << "      OFFICE PRINTER SIMULATION       " << std::endl;
    std::cout << "======================================" << std::endl;

    // Adding print requests from users
    officePrinter.addJob(1, "Johrel (CPE)", 5);
    officePrinter.addJob(2, "Louie (IT)", 12);
    officePrinter.addJob(3, "Silao (CS)", 2);

    // Printing individual job
    std::cout << "\n--- Processing ---\n";
    officePrinter.processNextJob();

    // Adding more requests while queue is active
    std::cout << "\n--- Incoming Requests ---\n";
    officePrinter.addJob(4, "Johlo (ARCHITECT)", 8);
    officePrinter.addJob(5, "Joh (ENGINEER)", 15);

    // Printing all remaining jobs
    officePrinter.processAllJobs();

    return 0;
}
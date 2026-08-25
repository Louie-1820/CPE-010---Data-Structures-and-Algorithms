#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include "job.h"

// Node structure for custom Linked List Queue
struct JobNode {
    Job job;
    JobNode* next;
    JobNode(const Job& j) : job(j), next(nullptr) {}
};

// 2. Creation of Printer Class and Implementation
class Printer {
private:
    JobNode* frontPtr;
    JobNode* backPtr;
    int pendingJobsCount;

public:
    Printer() : frontPtr(nullptr), backPtr(nullptr), pendingJobsCount(0) {}

    ~Printer() {
        while (hasPendingJobs()) {
            processNextJob();
        }
    }

    bool hasPendingJobs() const {
        return frontPtr != nullptr;
    }

    // Enqueue 
    void addJob(int id, const std::string& user, int pages) {
        Job newJob(id, user, pages);
        JobNode* newNode = new JobNode(newJob);

        if (hasPendingJobs()) {
            backPtr->next = newNode;
            backPtr = newNode;
        } else {
            frontPtr = newNode;
            backPtr = newNode;
        }
        pendingJobsCount++;
        newJob.printDetails();
        std::cout << " added to print queue." << std::endl;
    }

    // Dequeue 
    void processNextJob() {
        if (!hasPendingJobs()) {
            std::cout << "No pending print jobs." << std::endl;
            return;
        }

        JobNode* temp = frontPtr;
        std::cout << "Printing job for " << temp->job.getUser() << " (" << temp->job.getPageCount() << " pages)... Done!\n";

        frontPtr = frontPtr->next;
        if (frontPtr == nullptr) {
            backPtr = nullptr;
        }

        delete temp;
        pendingJobsCount--;
    }

    void processAllJobs() {
        std::cout << "\n--- Print Job Execution ---\n";
        while (hasPendingJobs()) {
            processNextJob();
        }
        std::cout << std::endl;
        std::cout << "--- All Printed Jobs Are Completed ---";
    }
};

#endif // PRINTER_H
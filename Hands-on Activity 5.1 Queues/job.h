#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <string>

// 1. Creating a class called Job
class Job {
private:
    int jobID;
    std::string userName;
    int numberofpage;

public:
    Job(int id = 0, const std::string& user = "", int pages = 0)
        : jobID(id), userName(user), numberofpage(pages) {}

    void printDetails() const {
        std::cout << "Job ID: " << jobID << " | User: " << userName << " | Pages: " << numberofpage;
    }

    int getPageCount() const { return numberofpage; }
    std::string getUser() const { return userName; }
    int getJobID() const { return jobID; }
};

#endif
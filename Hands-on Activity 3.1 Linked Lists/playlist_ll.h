#ifndef PLAYLIST_LL_H
#define PLAYLIST_LL_H
#include <iostream>
#include <string> 

template<typename T>
class circList{
    public: 
        T data;
        circList<T>*next = nullptr;
        circList<T>*prev = nullptr;
};  

template<typename T>
circList<T>* CreateNewNode(T newData){
 
    circList<T> *newNode = new circList<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

template<typename T>
void playAll(circList<T>* head){
    if(head == nullptr){
        std::cout<<"The playlist is empty." << std::endl;
        return;
    }
    circList<T>* currentNode = head;
    do{
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }while(currentNode != head);
    std::cout << std::endl;
}

template<typename T>
void insertHead(T newData, circList<T>** currentHead){
    circList<T>* newNode = CreateNewNode(newData);

    if(*currentHead == nullptr){
    newNode->next = newNode;
    newNode->prev = newNode;
    *currentHead = newNode;

    return;
    }else{
        newNode->next = *currentHead;
        newNode->prev = (*currentHead)->prev; 
        newNode->prev->next = newNode; 
    (*currentHead)->prev = newNode; 
    *currentHead = newNode;

    }
}

template<typename T>
void insertEnd(T newData, circList<T>* currentHead){
    circList<T>* newNode = CreateNewNode(newData);
    circList<T>* lastNode = currentHead->prev;
    newNode->prev = lastNode;
    newNode->next = currentHead;
    lastNode->next = newNode;
    currentHead->prev = newNode;
}

template<typename T>
void nextSong(circList<T>** PlaySong){ 
    *PlaySong = (*PlaySong)->next; 
    // move forward 
}

template<typename T>
void prevSong(circList<T>** PlaySong){
    *PlaySong = (*PlaySong)->prev;
    // move backward 
}

template<typename T>
void displayCurrent(circList<T>* PlaySong){
    if(PlaySong == nullptr){
        std::cout<<"There is no song playing." <<std::endl;
        return;
    }
    std::cout<<PlaySong->data;
    std::cout<<std::endl;
}

template<typename T>
void deleteNode(T findData, circList<T>** head, circList<T>** PlaySong){
    if(*head == nullptr){
        std::cout << "The playlist is empty." <<std::endl;
        return;
    }

    circList<T>* currNode = *head;
    do{
        if(currNode->data == findData) break;
        currNode = currNode->next;
    }while(currNode != *head);

    if(currNode->data != findData){
        std::cout << "Song not found." <<std::endl;
        return;
    }

    if(currNode->next == currNode){
        *head = nullptr;
        *PlaySong = nullptr;
        delete currNode;
        return;
    }
   
    if(currNode == *head){
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
        *head = currNode->next;
        if(*PlaySong == currNode){
            *PlaySong = currNode->next;
            
        }
        delete currNode;
        return;

    }else{
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
        if(*PlaySong == currNode){
            *PlaySong = currNode->next;
        }
        delete currNode;
    }
}

template<typename T>
void destroyList(circList<T>** head){
    if(*head == nullptr) return;

    circList<T>* currNode = *head;
    do{

        circList<T>* temp = currNode;
        currNode = currNode->next;
        delete temp;

    } while(currNode != *head);

    *head = nullptr;
}

#endif 
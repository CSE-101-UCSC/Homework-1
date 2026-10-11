#ifndef MOVIES_H
#define MOVIES_H

#include <string>

// One line of the input file: Year | Title | Actor
struct Movie {
    int year;
    std::string title;
    std::string actor;
};

// One node of the doubly linked list
struct Node {
    Movie data;
    Node* prev = nullptr;
    Node* next = nullptr;
};

// The list itself
struct MovieList {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
};

// Functions you must implement
void appendNode(MovieList& list, const Movie& m);    // add a node at the tail
bool comesBefore(const Movie& a, const Movie& b);   // year, then title, then actor
void sortList(MovieList& list);                      // insertion sort or merge sort
void removeDuplicates(MovieList& list);
void printList(const MovieList& list);
// year == 0 means no year filter; empty actor means no actor filter
void printFiltered(const MovieList& list, int year, const std::string& actor);
void clearList(MovieList& list);

#endif

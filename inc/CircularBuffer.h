#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

/**
 * @class CircularBuffer
 * @brief A circular buffer implementation with fixed capacity.
 */
class CircularBuffer {
  private:
    vector<char> buffer;
    int head;
    int tail;
    int capacity;

  public:
    /**
    * @brief Constructs a CircularBuffer with the given capacity.
    * @param capacity The maximum number of elements the buffer can hold.
    */

    CircularBuffer(int capacity);

    /**
    * @brief Adds an element to the buffer.
    * @param element The element to be added to the buffer.
    * 
    * If the buffer is full, the oldest element will be overwritten.
    */ 
    void push(char element);

    /**
    * @brief Removes and retrieves the oldest element from the buffer.
    * @return The oldest element in the buffer.
    * @throw std::out_of_range If the buffer is empty.
    */
    char pop();

    /**
    * @brief Checks if the buffer is empty.
    * @return true if the buffer is empty, false otherwise.
    */
    bool empty() const;

    /**
    * @brief Checks if the buffer is full.
    * @return true if the buffer is full, false otherwise.
    */
    bool full() const;

    /**
    * @brief Returns the number of elements in the buffer.
    * @return The number of elements currently in the buffer.
    */
    int size() const;

  
};

#endif // CIRCULARBUFFER_H
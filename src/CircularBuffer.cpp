#include "CircularBuffer.h"



CircularBuffer::CircularBuffer(int capacity)
{
  this->capacity = capacity;
  this->head = 0;
  this->tail = 0;
  buffer.resize(capacity);
}

void CircularBuffer::push(char element)
{
  buffer[head] = element;
  head = (head + 1) % capacity;
  if(head == tail) {
    tail = (tail + 1) % capacity;
  }
}

char CircularBuffer::pop()
{
  if(empty()) {
    throw out_of_range("Buffer is empty");
  }
  char value = buffer[tail];
  tail = (tail + 1) % capacity;
  return value;
}

bool CircularBuffer::empty() const
{
  return head == tail;
}

bool CircularBuffer::full() const 
{
  return (head +1) % capacity == tail;
}

int CircularBuffer::size() const 
{
  if (head >= tail) {
    return head - tail;
  }
  return capacity - (tail - head);
}
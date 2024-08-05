#ifndef FLOATBYTES_H
#define FLOATBYTES_H

/**
* @brief A union for accessing the bytes of a float.
* 
* The `FloatBytes` union allows a `float` value to be accessed as an array of 4 `char` bytes.
* This can be useful for tasks such as byte-level manipulation or data serialization.
*/
union FloatBytes {
  float value;
  char bytes[4];
};

#endif // FLOATBYTES_H
#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include "file_filter.h"

class Encryptor : public FileFilter
{
protected:
  int encryption_key_; // controls the rule of encryption
  
  /* Function */
  // filter engine
  virtual char Transform(char ch)
  {
    return static_cast<char>(ch + encryption_key_);
  }
  
public:
  /* Constructor */
  // default constructor, will set the encryption_key_ to 1
  // call default file filter constructor 
  Encryptor() : FileFilter()
  { encryption_key_ = 1; }
  
  /* Mutator */
  void set_encryption_key(int e_k)
  { encryption_key_ = e_k; }
  
  /* Accessor */
  int encryption_key() const 
  { return encryption_key_; }  
  
};


#endif
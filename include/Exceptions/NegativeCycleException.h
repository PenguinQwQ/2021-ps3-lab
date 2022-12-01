#ifndef NEG_EXCEPTION
#define NEG_EXCEPTION

#include <iostream>
#include <exception>
#include <string>
#include <cstring>
#include <Exceptions/GLException.h>
 
class NegativeCycleException : public GLException {
};

/*
class NegativeCycleException : public GLException {
  public:
  char err_buf[128];
  public:
  explicit NegativeCycleException(const std::string &s);
  NegativeCycleException(char *str)
  {
    memset(err_buf, 0, sizeof(err_buf));
    strcpy(err_buf, str);
  }

};
*/

#endif


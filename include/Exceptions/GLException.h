#ifndef GL_EXCEPTION
#define GL_EXCEPTION

#include <iostream>
#include <exception>
#include <string>
#include <cstring>
 
class GLException : public std::exception {
 
 protected:
  std::string message;
 public:
  explicit GLException(const std::string &s);
  virtual std::string GetMessage() const;
};

std::ostream &operator<<(std::ostream &os, const GLException &e);


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


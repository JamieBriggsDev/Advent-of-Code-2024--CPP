//
// Created by Jamie Briggs on 13/12/2024.
//

#ifndef AOCEXCEPTION_H
#define AOCEXCEPTION_H
#include <exception>
#include <string>

namespace core {

class AocException : public std::exception{

  std::string message;
  public:
    explicit AocException(const std::string& msg) : message(msg) {}

    // Overriding the what() method from std::exception
    const char* what() const noexcept override {
      return message.c_str();
    }
  };

} // core

#endif //AOCEXCEPTION_H

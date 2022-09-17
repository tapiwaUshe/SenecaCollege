// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 5
#include "Message.h"

w5::Message::Message(std::ifstream& in, char c) {
  std::string line;
  getline(in, line, c);
  std::istringstream is(line);
  
  if(user.empty()) {
    is >> user;
    if((int) user.find('@') > 0) {
      user.clear();
    }
  }
  if(reply.empty()) {
    is >> reply;
    if((int) reply.find('@') < 0) {
      tweet = reply;
      reply.clear();
    }
  }
  if(tweet.empty()) {
    getline(is, tweet);
  }
  is.clear();  
}  

bool w5::Message::empty() const {
  return user.empty() || tweet.empty();
}

void w5::Message::display(std::ostream& os) const {
  os << "Message" << std::endl;
  os << " User  : " << user << std::endl;
  if(!reply.empty()) {
    os << " Reply : " << reply << std::endl;    
  }
  os << " Tweet : " << tweet << std::endl;
  os << std::endl;
}

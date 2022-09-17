// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 5: Containers
#include "Notifications.h"

w5::Notifications::Notifications() {
  messages.clear();
}

w5::Notifications::Notifications(const w5::Notifications& notifications) : Notifications() {  
  messages = notifications.messages;
}

w5::Notifications& w5::Notifications::operator=(const w5::Notifications& notifications) {
  if(this != &notifications) {
    messages = notifications.messages;
  }
  return *this;
}

w5::Notifications::Notifications(w5::Notifications&& notifications) {
  messages = notifications.messages;
  notifications.messages.clear();
}

w5::Notifications&& w5::Notifications::operator=(w5::Notifications&& notifications) {
  if(this != &notifications) {
    messages = std::move(notifications.messages);
  }
  return std::move(*this);
}

w5::Notifications::~Notifications() {
  messages.clear();
}

void w5::Notifications::operator+=(const w5::Message& message) {
  messages.push_back(message);
}

void w5::Notifications::display(std::ostream& os) const {
  for(auto message = messages.begin(); message != messages.end(); ++message) {
    message->display(os);
  }
}

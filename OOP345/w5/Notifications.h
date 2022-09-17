// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 5: Containers
#ifndef W5_NOTIFICATIONS_H
#define W5_NOTIFICATIONS_H
#include "Message.h"

namespace w5 {
  class Notifications {
    std::vector<Message> messages;
  public:
    Notifications();
    Notifications(const Notifications&);
    Notifications& operator=(const Notifications&);
    Notifications(Notifications&&);
    Notifications&& operator=(Notifications&&);
    ~Notifications();
    void operator+=(const Message& msg);
    void display(std::ostream& os) const;
  };
}

#endif

//
// OrderInfo.hpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 18:19:49 2016 Victor Le
// Last update Sat Apr 16 00:15:34 2016 sayavong frederic
//

#ifndef ORDERINFO_HPP_
# define ORDERINFO_HPP_

/// Enumeration about information to retrieve into files
enum	Information
  {
    NO_INFO = -1,
    PHONE_NUMBER = 0,
    EMAIL_ADDRESS,
    IP_ADDRESS
  };

typedef enum Information t_info;

#endif /* !ORDERINFO_HPP_ */

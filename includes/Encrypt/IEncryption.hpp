//
// IEncryption.hpp for plazza in /home/sayavo_f/test/plazza/include
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Tue Apr 12 20:10:56 2016 sayavong frederic
// Last update Sat Apr 23 09:18:35 2016 Victor Le
//

#ifndef IENCRYPTION_H_
# define IENCRYPTION_H_

# include <string>
# include "OrderInfo.hpp"

class	IEncryption
{
public:
  virtual		~IEncryption() {};
  virtual void		decipherLine(const t_info &info, const std::string &line) = 0;
  virtual std::map<int, int>	&getKeys() = 0;
  virtual std::multimap<int, std::string>	&possibilities() = 0;
};

#endif /* !IENCRYPTION_H_ */

//
// NoEncryption.hpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sat Apr 16 13:23:38 2016 Victor Le
// Last update Tue Apr 19 19:21:44 2016 sayavong frederic
//

#ifndef NOENCRYPTION_HPP_
# define NOENCRYPTION_HPP_

# include <string>
# include "AEncryption.hpp"
# include "OrderInfo.hpp"

class	NoEncryption : public AEncryption
{
public:
  NoEncryption(void);
  virtual ~NoEncryption(void);
  virtual void	decipherLine(const t_info &info, const std::string &line);
  virtual void	check_on_map(const t_info &info, const std::string &line);
  virtual std::map<int, int>	&getKeys();
  virtual std::multimap<int, std::string>	&possibilities();
private:
  std::map<int, int>			noEncrypt_keys;
  std::multimap<int, std::string>	noEncrypt_possibilities;
};

#endif /* !NOENCRYPTION_HPP_ */

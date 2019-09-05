//
// AEncryption.hpp for plazza in /home/le_l/Workspace/cpp_plazza/srcs/encryption
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sat Apr 16 12:49:58 2016 Victor Le
// Last update Sat Apr 23 09:17:07 2016 Victor Le
//

#ifndef AENCRYPTION_HPP_
# define AENCRYPTION_HPP_

# include <string>
# include <map>
# include "IEncryption.hpp"

class	AEncryption: public IEncryption
{
public:
  AEncryption();
  virtual ~AEncryption(void);
  virtual void			decipherLine(const t_info &info, const std::string &line) = 0;
  virtual void			check_on_map(const t_info &info, const std::string &line) = 0;
  virtual std::map<int, int>	&getKeys() = 0;
  virtual std::multimap<int, std::string>	&possibilities() = 0;

  bool				check_regex(const std::string &to_find, const t_info &info, std::string &sentence);
private:
  std::string	convertInfoToRegexStr(const t_info &info);
};

#endif /* !AENCRYPTION_HPP_ */

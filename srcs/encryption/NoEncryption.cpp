//
// NoEncryption.cpp for plazza in /home/le_l/Workspace/cpp_plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sat Apr 16 13:24:34 2016 Victor Le
// Last update Sat Apr 23 09:04:42 2016 Victor Le
//

#include "NoEncryption.hpp"

NoEncryption::NoEncryption(void):
  AEncryption()
{}

NoEncryption::~NoEncryption(void)
{}

std::map<int, int>	&NoEncryption::getKeys()
{
  return (this->noEncrypt_keys);
}

std::multimap<int, std::string>		&NoEncryption::possibilities()
{
  return (this->noEncrypt_possibilities);
}

void	NoEncryption::check_on_map(const t_info &, const std::string &)
{}

void	NoEncryption::decipherLine(const t_info &info, const std::string &line)
{
  std::string	str("");

  if (check_regex(line, info, str) == true)
    {
      if (noEncrypt_possibilities.empty())
	noEncrypt_keys.insert(std::pair<int, int>(0, 1));
      else
	noEncrypt_keys[0] = noEncrypt_keys[0] + 1;
      noEncrypt_possibilities.insert(std::pair<int, std::string>(0, str));
    }
}

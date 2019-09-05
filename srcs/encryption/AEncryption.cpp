//
// AEncryption.cpp for plazza in /home/le_l/Workspace/cpp_plazza/srcs/encryption
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sat Apr 16 12:53:08 2016 Victor Le
// Last update Sat Apr 23 08:58:39 2016 Victor Le
//

#include "AEncryption.hpp"
#include "Regex.hpp"

AEncryption::AEncryption(void):
  IEncryption()
{}

AEncryption::~AEncryption(void)
{}

bool		AEncryption::check_regex(const std::string &to_find, const t_info &info, std::string &sentence)
{
  Regex		reg(convertInfoToRegexStr(info), REG_EXTENDED | REG_ICASE);
  int		i;

  sentence.clear();
  if (reg.tryMatch(to_find) == false)
    return (false);
  i = reg.getMatchOffsets().rm_so;
  while (i < reg.getMatchOffsets().rm_eo)
    sentence += to_find[i++];
  return (true);
}

// Private
std::string	AEncryption::convertInfoToRegexStr(const t_info &info)
{
  if (info == PHONE_NUMBER)
    return ("0[1-9]( ?[0-9][0-9] ?){4}");
  else if (info == EMAIL_ADDRESS)
    return ("[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,}");
  else if (info == IP_ADDRESS)
    return ("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");
  return ("");
}

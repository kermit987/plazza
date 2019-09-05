//
// Xor.hpp for plazza in /home/sayavo_f/test/plazza/include
//
// Made by sayavong frederic
// Login   <sayavo_f@epitech.net>
//
// Started on  Tue Apr 12 19:34:44 2016 sayavong frederic
// Last update Tue Apr 19 18:53:21 2016 sayavong frederic
//

#ifndef XOR_H_
# define XOR_H_

# include <string>
# include <map>
# include "IEncryption.hpp"
# include "AEncryption.hpp"
# include "OrderInfo.hpp"

class	XorCipher : public AEncryption
{
  public:
  XorCipher();
  virtual ~XorCipher();
  virtual void			check_on_map(const t_info &info, const std::string &line);
  virtual void		decipherLine(const t_info &info, const std::string &line);
  void			Union_xor_changes(const std::string &line, std::string &tmp, const int &key);
  virtual std::map<int, int>	&getKeys();
  virtual std::multimap<int, std::string>	&possibilities();
  bool			no_match_check(const t_info &, const std::string &);
private:
  std::map<int, int>		xor_keys;
  std::multimap<int, std::string>	xor_possibilities;

  bool			make_changes(const std::string &line, std::string &to_copy, const int &key, const t_info &info);
};

#endif /* !XOR_H_ */

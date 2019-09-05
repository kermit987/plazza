//
// CmdParser.hpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 15:44:42 2016 Victor Le
// Last update Thu Apr 14 11:54:00 2016 Victor Le
//

#ifndef CMDPARSER_HPP_
# define CMDPARSER_HPP_

# include <string>
# include <vector>
# include "Order.hpp"

///Command parser for Plazza class.
class	CmdParser
{
public:
  /// Constructor.
  CmdParser(void);

  /// Destructor.
  ~CmdParser(void);

  /// Parse the given command.
  /**
     \param cmd The command to parse
     \return Indicates if there is an order.
  */
  bool	parseCmd(const std::string &cmd, std::vector<Order> &orders);

private:
  /// Check if the string is an information type to search.
  /**
     \param str A string.
     \return The value of the corresponding information type.
  */
  t_info	isInfoType(const std::string &str);

  /// Check if a character is a blank character.
  /**
     \param c A character.
     \return true if 'c' is a blank char.
  */
  bool		isBlank(const char c);

  /// Increments 'i' until str[i] is not a blank or 'i' reach end of string.
  /**
     \param str A string.
     \param i An index associated with 'str'.
  */
  void		skipBlank(const std::string &str, unsigned int &i);

  /// Return the next token starting from 'i'.
  /**
     A token is a succession of non-blank character.

     \param str The string from which the token will be extracted.
     \param i The current offset associated with 'str'.
     \return The token.
  */
  std::string	getNextToken(const std::string &str, unsigned int &i);

  /// Return an order from a command.
  /**
     \param cmd A command to parse.
     \param i The offset from where to search the order.
     \return An order.
  */
  Order		getOrder(const std::string &cmd, unsigned int &i);

  /// Set the current order according a token.
  /**
     \param order The order to modify.
     \param token A token.
     \return false when we re-set the infoType field of the order when already setted.
  */
  bool		setOrder(Order &order, const std::string &token);
};

#endif /* !CMDPARSER_HPP_ */

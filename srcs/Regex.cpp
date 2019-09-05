//
// Regex.cpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 10:31:27 2016 Victor Le
// Last update Sat Apr 16 13:04:33 2016 Victor Le
//

#include <string>
#include "Regex.hpp"
#include "InvalidArgument.hpp"

Regex::Regex(void):
  m_regStr(""), m_flags(0), m_regex(), m_error(),
  m_deleted(true), m_setted(false), m_noSub(false), m_match()
{}

Regex::Regex(const std::string &strRegex, const int flags):
  m_regStr(strRegex), m_flags(flags), m_regex(), m_error(),
  m_deleted(true), m_setted(false), m_noSub(false), m_match()
{
  computeReg();
}

Regex::~Regex(void)
{
  manualDeletion();
}

void	Regex::manualDeletion(void)
{
  if (!m_deleted)
    {
      regfree(&m_regex);
      m_deleted = true;
      m_setted = false;
      m_noSub = false;
    }
}

void	Regex::setStrRegex(const std::string &strRegex)
{
  if (m_setted)
    manualDeletion();
  m_regStr = strRegex;
  computeReg();
}

bool	Regex::tryMatch(const std::string &str)
{
  int	nbMatch;

  if (m_noSub)
    nbMatch = regexec(&m_regex, str.c_str(), 0, NULL, 0);
  else
    nbMatch = regexec(&m_regex, str.c_str(), 1, &m_match, 0);
  if (nbMatch == 0)
    return (true);
  else if (nbMatch == REG_NOMATCH)
    return (false);
  m_error.generateError(nbMatch, &m_regex);
  throw InvalidArgument(getError());
}

const regmatch_t	&Regex::getMatchOffsets(void) const
{
  return (m_match);
}

const std::string	&Regex::getError(void) const
{
  return (m_error.getError());
}

//Private
void	Regex::computeReg(void)
{
  int		err;

  err = regcomp(&m_regex, m_regStr.c_str(), m_flags);
  if (err)
    {
      m_error.generateError(err, &m_regex);
      throw InvalidArgument(getError());
    }
  m_setted = true;
  m_deleted = false;
  if (m_flags & REG_NOSUB)
    m_noSub = true;
}

//Nested class RegError implementation
Regex::RegError::RegError(void): m_errStr()
{}

Regex::RegError::~RegError(void)
{}

void	Regex::RegError::generateError(const int err, const regex_t *regex)
{
  int	sizeBuf;
  char	*buf;

  sizeBuf = regerror(err, regex, NULL, 0);
  buf = new char[sizeBuf];
  regerror(err, regex, buf, sizeBuf);
  m_errStr = buf;
  delete buf;
}

const std::string	&Regex::RegError::getError(void) const
{
  return (m_errStr);
}

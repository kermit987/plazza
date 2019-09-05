//
// Regex.hpp for plazza in /home/le_l/Workspace/plazza
//
// Made by Victor Le
// Login   <le_l@epitech.net>
//
// Started on  Sun Apr 10 10:30:40 2016 Victor Le
// Last update Sat Apr 16 13:04:13 2016 Victor Le
//

#ifndef REGEX_HPP_
# define REGEX_HPP_

# include <regex.h>

/// C Regex wrapper class.
class	Regex
{
public:
  /// Basic constructor.
  Regex(void);

  /// Constructor.
  /**
     \param strRegex A regex pattern to check.
     \param flags The flags to send to regcomp function.
   */
  Regex(const std::string &strRegex, const int flags);

  /// Destructor.
  ~Regex(void);

  /// Do the same thing as the destructor.
  /**
     The main purpose of this is to be used during a try...catch block.
     It will not conflict with the destructor.
   */
  void			manualDeletion(void);

  /// Set the regex string of the object.
  /**
     \param strRegex The regex to handle.

     Throw InvalidArgument on error.
  */
  void			setStrRegex(const std::string &strRegex);

  /// Check if the given string match with the regex.
  /**
     \param str A string to compare with the regex.
     \return true or false if it matches the regex or not.
     Throw InvalidArgument exception on error.
   */
  bool			tryMatch(const std::string &str);

  /// Return the structure with the offsets of the last match regex.
  /**
     \return The regmatch_t structure.
  */
  const regmatch_t	&getMatchOffsets(void) const;

  /// Get the last error encountered with regex.
  /**
     \return An indication about the last error.
  */
  const std::string	&getError(void) const;

private:
  /// Regex error class handler
  class RegError
  {
  public:
    /// Basic construtor.
    RegError(void);

    /// Destructor
    ~RegError(void);

    /// Generate the regex message error according the error value.
    /**
       \param err The current error.
       \param regex The regex which cause this error.
     */
    void		generateError(const int err, const regex_t *regex);

    /// Get the message error of the current error.
    /**
       \return The current error.
    */
    const std::string	&getError(void) const;

  private:
    std::string		m_errStr; /**< String which keeps the last error generate. */
  };

private:
  std::string		m_regStr; /**< The current regex. */
  int			m_flags; /**< The current flag. */
  regex_t		m_regex; /**< C struct regex. */
  RegError		m_error; /**< Regex error manager. */
  bool			m_deleted; /**< Bool to check if deletion was already done. */
  bool			m_setted; /**< Indicates if regcomp had been called. */
  bool			m_noSub; /**< Indicates if the flag REG_NOSUB is on. */
  regmatch_t		m_match; /**< The structure with the offsets of the substring which match. */

  /// Compute the current regex.
  /**
     Throw InvalidArgument on error.
   */
  void			computeReg(void);
};

#endif /* !REGEX_HPP_ */

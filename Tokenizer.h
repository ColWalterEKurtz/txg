// -----------------------------------------------------------------------------
// Tokenizer.h                                                       Tokenizer.h
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the definition of the @ref Tokenizer class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-11-08
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// One-Definition-Rule                                       One-Definition-Rule
// -----------------------------------------------------------------------------
#ifndef TOKENIZER_H_INCLUDE_NO1
#define TOKENIZER_H_INCLUDE_NO1


// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include <vector>
#include <string>
#include <istream>


// ---------
// Tokenizer
// ---------
/**
 * @brief  This class reads a line from stdin and saves all words in an array.
 */
class Tokenizer
{

public:

  // ---------------------------------------------------------------------------
  // Construction                                                   Construction
  // ---------------------------------------------------------------------------

  // ---------
  // Tokenizer
  // ---------
  /**
   * @brief  The standard-constructor.
   */
  Tokenizer();


  // ---------------------------------------------------------------------------
  // Handling                                                           Handling
  // ---------------------------------------------------------------------------

  // --------
  // readLine
  // --------
  /**
   * @brief  Supercalifragilisticexpialidocious
   */
  bool readLine(std::istream& stream);


  // ---------------------------------------------------------------------------
  // Getter methods                                               Getter methods
  // ---------------------------------------------------------------------------

  // -------
  // getLine
  // -------
  /**
   * @brief  Supercalifragilisticexpialidocious
   */
  std::string getLine() const;

  // ---------
  // getIndent
  // ---------
  /**
   * @brief  Supercalifragilisticexpialidocious
   */
  std::string getIndent() const;

  // -------------
  // getTokenCount
  // -------------
  /**
   * @brief  Supercalifragilisticexpialidocious
   */
  unsigned getTokenCount() const;

  // --------
  // getToken
  // --------
  /**
   * @brief  Supercalifragilisticexpialidocious
   */
  std::string getToken(int index) const;


protected:

  // ---------------------------------------------------------------------------
  // Internal methods                                           Internal methods
  // ---------------------------------------------------------------------------

  // ------
  // isendl
  // ------
  /**
   * @brief  Supercalifragilisticexpialidocious
   */
  bool isendl(char c) const;

  // -------
  // isspace
  // -------
  /**
   * @brief  Supercalifragilisticexpialidocious
   */
  bool isspace(char c) const;

  // -------
  // iscntrl
  // -------
  /**
   * @brief  Supercalifragilisticexpialidocious
   */
  bool iscntrl(char c) const;


private:

  // ---------------------------------------------------------------------------
  // Attributes                                                       Attributes
  // ---------------------------------------------------------------------------

  /// maximum number of bytes allowed per token
  const unsigned MAX_TOKEN;

  /// maximum number of tokens allowed
  const unsigned MAX_TOKEN_COUNT;

  /// the complete line recently read
  std::string m_line;

  /// all blanks from the beginning of the recently read line
  std::string m_indent;

  /// the list of all tokens from the recently read line
  std::vector<std::string> m_tokens;

};

#endif  /* #ifndef TOKENIZER_H_INCLUDE_NO1 */


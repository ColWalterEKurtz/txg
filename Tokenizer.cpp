// -----------------------------------------------------------------------------
// Tokenizer.cpp                                                   Tokenizer.cpp
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the implementation of the @ref Tokenizer class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-11-08
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include "message.h"
#include "Tokenizer.h"


// -----------------------------------------------------------------------------
// Used namespaces                                               Used namespaces
// -----------------------------------------------------------------------------
using namespace std;


// -----------------------------------------------------------------------------
// Construction                                                     Construction
// -----------------------------------------------------------------------------

// ---------
// Tokenizer
// ---------
/*
 *
 */
Tokenizer::Tokenizer()
: MAX_TOKEN(100),
  MAX_TOKEN_COUNT(100)
{
  // nothing
}


// -----------------------------------------------------------------------------
// Handling                                                             Handling
// -----------------------------------------------------------------------------

// --------
// readLine
// --------
/*
 *
 */
bool Tokenizer::readLine(istream& stream)
{
  // reset
  m_line = "";
  m_indent = "";
  m_tokens.clear();

  // check stream state
  if ( !stream ) 
  {
    // don't parse invalid streams
    return false;
  }

  // the parser's state
  enum
  {
    READ_INDENT,
    READ_VISIBLE,
    SKIP_SPACE,
    CORRUPTED
  }
  state = READ_INDENT;

  // the current byte from stdin
  char c = 0;

  // input buffer
  string token = "";

  // read bytes from stdin
  while( stream.get(c) )
  {
    // end of line
    if ( isendl(c) )
    {
      // stop parsing
      break;
    }

    // control character
    if (iscntrl(c))
    {
      // notify user
      msg::err("invalid characters read from stdin");

      // set final state
      state = CORRUPTED;

      // stop parsing
      break;
    }

    // append valid character
    m_line += c;

    // READ_INDENT
    if (state == READ_INDENT)
    {
      // blank
      if (isspace(c))
      {
        // append character
        m_indent += c;

        // check character limit
        if (m_indent.size() > MAX_TOKEN)
        {
          // notify user
          msg::err("indent too long");

          // set final state
          state = CORRUPTED;

          // stop parsing
          break;
        }
      }

      // first real character found
      else
      {
        // start next token
        token = c;

        // next state
        state = READ_VISIBLE;
      }
    }

    // READ_VISIBLE
    else if (state == READ_VISIBLE)
    {
      // blank
      if (isspace(c))
      {
        if ( !token.empty() )
        {
          // append token
          m_tokens.push_back(token);

          // check token limit
          if (token.size() > MAX_TOKEN_COUNT)
          {
            // notify user
            msg::err("too many tokens per line");

            // set final state
            state = CORRUPTED;

            // stop parsing
            break;
          }

          // reset buffer
          token = "";
        }

        // next state
        state = SKIP_SPACE;
      }

      // visible character
      else
      {
        // append character
        token += c;

        // check character limit
        if (token.size() > MAX_TOKEN)
        {
          // notify user
          msg::err("token too long");

          // set final state
          state = CORRUPTED;

          // stop parsing
          break;
        }
      }
    }

    // SKIP_SPACE
    else if (state == SKIP_SPACE)
    {
      if ( !isspace(c) )
      {
        // start next token
        token = c;

        // next state
        state = READ_VISIBLE;
      }
    }
  }

  // invalid line
  if (state == CORRUPTED)
  {
    // signalize trouble
    return false;
  }

  // last token not yet added
  if ( !token.empty() )
  {
    // append token
    m_tokens.push_back(token);

    // check token limit
    if (token.size() > MAX_TOKEN_COUNT)
    {
      // notify user
      msg::err("too many tokens per line");

      // signalize trouble
      return false;
    }
  }

  // signalize success
  return true;
}


// -----------------------------------------------------------------------------
// Getter methods                                                 Getter methods
// -----------------------------------------------------------------------------

// -------
// getLine
// -------
/*
 *
 */
string Tokenizer::getLine() const
{
  return m_line;
}

// ---------
// getIndent
// ---------
/*
 * @brief  Supercalifragilisticexpialidocious
 */
string Tokenizer::getIndent() const
{
  return m_indent;
}

// -------------
// getTokenCount
// -------------
/*
 * @brief  Supercalifragilisticexpialidocious
 */
unsigned Tokenizer::getTokenCount() const
{
  return m_tokens.size();
}

// --------
// getToken
// --------
/*
 * @brief  Supercalifragilisticexpialidocious
 */
string Tokenizer::getToken(int index) const
{
  return m_tokens[index];
}


// -----------------------------------------------------------------------------
// Internal methods                                             Internal methods
// -----------------------------------------------------------------------------

// ------
// isendl
// ------
/*
 *
 */
bool Tokenizer::isendl(char c) const
{
  switch(c)
  {
    case 10: return true;
    case 13: return true;
  }

  return false;
}

// -------
// isspace
// -------
/*
 *
 */
bool Tokenizer::isspace(char c) const
{
  switch(c)
  {
    case  9: return true;
    case 32: return true;
  }

  return false;
}

// -------
// iscntrl
// -------
/*
 *
 */
bool Tokenizer::iscntrl(char c) const
{
  switch(c)
  {
    case  0: return true;
    case  1: return true;
    case  2: return true;
    case  3: return true;
    case  4: return true;
    case  5: return true;
    case  6: return true;
    case  7: return true;
    case  8: return true;
    //    9: TAB
    //   10: LF
    case 11: return true;
    case 12: return true;
    //   13: CR
    case 14: return true;
    case 15: return true;
    case 16: return true;
    case 17: return true;
    case 18: return true;
    case 19: return true;
    case 20: return true;
    case 21: return true;
    case 22: return true;
    case 23: return true;
    case 24: return true;
    case 25: return true;
    case 26: return true;
    case 27: return true;
    case 28: return true;
    case 29: return true;
    case 30: return true;
    case 31: return true;
  }

  return false;
}


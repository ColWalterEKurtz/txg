// -----------------------------------------------------------------------------
// NewCommandTable.cpp                                       NewCommandTable.cpp
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the implementation of the @ref NewCommandTable class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-11-18
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include <sstream>
#include <iostream>
#include "message.h"
#include "Tokenizer.h"
#include "NewCommandTable.h"


// -----------------------------------------------------------------------------
// Used namespaces                                               Used namespaces
// -----------------------------------------------------------------------------
using namespace std;


// -----------------------------------------------------------------------------
// Construction                                                     Construction
// -----------------------------------------------------------------------------

// ---------------
// NewCommandTable
// ---------------
/*
 *
 */
NewCommandTable::NewCommandTable(const string& trigger)
: Generator(trigger)
{
  m_nrows = 0;
  m_ncols = 0;
}


// ---------------------------------------------------------------------------
// Overridables                                                   Overridables
// ---------------------------------------------------------------------------

// --------
// showCode
// --------
/*
 *
 */
bool NewCommandTable::showCode(const Tokenizer& tokenizer)
{
  if ( !init(tokenizer) )
  {
    return false;
  }

  // start center environment
  cout << m_indent << "\\begin{center}" << endl;

  // create command for table headings
  cout << m_indent << "  \\newcommand{\\coltop}[1]{#1}%" << endl;

  // create commands
  for(unsigned j = 0; j < m_ncols; j++)
  {
    cout << m_indent << "  % column " << (j + 1) << endl;

    for(unsigned i = 0; i < m_nrows; i++)
    {
      if (i > 0)
      {
        cout << m_indent << "  \\newcommand{" << getCommand(i, j) << "}{}%" << endl;
      }

      else
      {
        cout << m_indent << "  \\newcommand{" << getCommand(i, j) << "}{\\coltop{}}%" << endl;
      }
    }
  }

  // start tabular environment
  cout << m_indent << "  \\begin{tabular}{";

  // write column definition
  for(unsigned j = 0; j < m_ncols; j++)
  {
    cout << "c";
  }

  cout << "}" << endl;

  // create table
  for(unsigned i = 0; i < m_nrows; i++)
  {
    cout << m_indent << "    ";

    for(unsigned j = 0; j < m_ncols; j++)
    {
      if (j > 0)
      {
        cout << " & ";
      }

      cout << getCommand(i, j);
    }

    if ((i + 1) < m_nrows)
    {
      cout << " \\\\";
    }

    cout << endl;
  }

  // close tabular environment
  cout << m_indent << "  \\end{tabular}" << endl;

  // close center environment
  cout << m_indent << "\\end{center}" << endl;

  // signalize success
  return true;
}

// --------
// showHelp
// --------
/*
 *
 */
void NewCommandTable::showHelp(bool verbose) const
{
  cout << getTrigger() << " nrows ncols" << endl;
}


// -----------------------------------------------------------------------------
// Internal methods                                             Internal methods
// -----------------------------------------------------------------------------

// ----
// init
// ----
/*
 *
 */
bool NewCommandTable::init(const Tokenizer& tokenizer)
{
  // reset
  m_indent = "";
  m_nrows = 0;
  m_ncols = 0;

  // get indent from tokenizer
  m_indent = tokenizer.getIndent();

  // get number of tokens
  unsigned ntokens = tokenizer.getTokenCount();

  // check minimum number of tokens
  if (ntokens < 3)
  {
    // notify user
    msg::err(getTrigger() + " needs two arguments");

    // signalize trouble
    return false;
  }

  // check maximum number of tokens
  if (ntokens > 3)
  {
    // notify user
    msg::wrn("too many arguments passed");
  }

  // use string stream for type conversion
  stringstream fifo;

  // initialize fifo
  fifo << tokenizer.getToken(1);
  fifo << " ";
  fifo << tokenizer.getToken(2);

  // try to convert string to unsigned
  if ( !(fifo >> m_nrows >> m_ncols) )
  {
    // notify user
    msg::err("you have to pass numeric values for the number of rows and columns");

    // signalize trouble
    return false;
  }

  // check limits
  if ((m_nrows < 1) || (m_nrows > 26))
  {
    // notify user
    msg::err("the number of rows must be from [1..26]");

    // signalize trouble
    return false;
  }

  // check limits
  if ((m_ncols < 1) || (m_ncols > 26))
  {
    // notify user
    msg::err("the number of columns must be from [1..26]");

    // signalize trouble
    return false;
  }

  // signalize success
  return true;
}

// ----------
// getCommand
// ----------
/*
 *
 */
string NewCommandTable::getCommand(unsigned i, unsigned j)
{
  // index out of limits
  if (i > 25) return "";
  if (j > 25) return "";

  return string("\\") + static_cast<char>('A' + i) + static_cast<char>('a' + j);
}



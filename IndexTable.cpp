// -----------------------------------------------------------------------------
// IndexTable.cpp                                                 IndexTable.cpp
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the implementation of the @ref IndexTable class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-12-31
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include <sstream>
#include <iostream>
#include <iomanip>
#include "message.h"
#include "Tokenizer.h"
#include "IndexTable.h"


// -----------------------------------------------------------------------------
// Used namespaces                                               Used namespaces
// -----------------------------------------------------------------------------
using namespace std;


// -----------------------------------------------------------------------------
// Construction                                                     Construction
// -----------------------------------------------------------------------------

// ----------
// IndexTable
// ----------
/*
 *
 */
IndexTable::IndexTable(const string& trigger)
: Generator(trigger)
{
  // do nothing by default
  m_operation = NONE;
}


// -----------------------------------------------------------------------------
// Overridables                                                     Overridables
// -----------------------------------------------------------------------------

// --------
// showCode
// --------
/*
 *
 */
bool IndexTable::showCode(const Tokenizer& tokenizer)
{
  // check tokens from extracted line
  if ( !init(tokenizer) )
  {
    // signalize trouble
    return false;
  }

  if (m_operation == TABLE)
  {
    showTable();
  }

  // signalize success
  return true;
}

// --------
// showHelp
// --------
/*
 *
 */
void IndexTable::showHelp(bool verbose) const
{
  cout << getTrigger() << " v1 [v2 ... v10] | f1 [f2 ...]" << endl;
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
bool IndexTable::init(const Tokenizer& tokenizer)
{
  // reset
  m_indent = "";
  m_operation = NONE;
  m_inputs.clear();
  m_functions.clear();

  // get indent from tokenizer
  m_indent = tokenizer.getIndent();

  // the tokens context
  enum { INPUTS, FUNCTIONS } context = INPUTS;

  // get number of tokens
  unsigned tokens = tokenizer.getTokenCount();

  // deploy tokens
  for(unsigned i = 1; i < tokens; i++)
  {
    // get current token
    const string& token = tokenizer.getToken(i);

    if (context == INPUTS)
    {
      // separator found
      if (token == "|")
      {
        // switch context
        context = FUNCTIONS;
      }

      // special value found
      else if (token == "bash")
      {
        // no input variables read yet
        if ( m_inputs.empty() )
        {
          // create bash code
          m_operation = BASH;

          // signalize success
          return true;
        }

        else
        {
          // signalize trouble
          return false;
        }
      }

      else
      {
        // check maximum number of input variables
        if (m_inputs.size() == 10)
        {
          // notify user
          msg::err("at most 10 input variables allowed");

          // signalize trouble
          return false;
        }

        // append input variable
        m_inputs.push_back(token);
      }
    }

    else if (context == FUNCTIONS)
    {
      // separator found
      if (token == "|")
      {
        // notify user
        msg::err("too many pipe characters given");

        // signalize trouble
        return false;
      }

      else
      {
        // append function
        m_functions.push_back(token);
      }
    }
  }

  // no input variables given
  if (m_inputs.empty())
  {
    // notify user
    msg::err("no input variables given (forgotten pipe character?)");

    // signalize trouble
    return false;
  }

  // no function names given
  if (m_functions.empty())
  {
    // notify user
    msg::err("no functions given (forgotten pipe character?)");

    // signalize trouble
    return false;
  }

  // create table
  m_operation = TABLE;

  // valid line given
  return true;
}

// ---------
// showTable
// ---------
/*
 *
 */
void IndexTable::showTable() const
{
  // start table
  cout << m_indent << "\\begin{tabular}";

  // Index column
  cout << "{r|";

  // one column for each input variable
  for(unsigned i = 0; i < m_inputs.size(); i++)
  {
    cout << "c";
  }

  // separate columns with two lines
  cout << "|";

  // one column for each function
  for(unsigned i = 0; i < m_functions.size(); i++)
  {
    cout << "c";
  }

  // close column definition
  cout << "}" << endl;

  // start first row
  cout << m_indent << "  Index & ";

  // show names of input variables
  for(unsigned i = 0; i < m_inputs.size(); i++)
  {
    // separate subsequent columns
    if (i > 0)
    {
      cout << " & ";
    }

    // show name
    cout << m_inputs[i];
  }

  cout << " & ";

  // show names of functions
  for(unsigned i = 0; i < m_functions.size(); i++)
  {
    // separate subsequent columns
    if (i > 0)
    {
      cout << " & ";
    }

    // show name
    cout << m_functions[i];
  }

  // end first row
  cout << " \\\\" << endl;

  // insert horizontal line
  cout << m_indent << "  \\hline" << endl;

  // nrows = 2^inputs
  unsigned nrows = (1 << m_inputs.size());

  // create table
  for (unsigned i = 0; i < nrows; i++)
  {
    // index in decimal notation
    cout << m_indent << setw(7) << right << i;

    cout << " & ";

    // index in binary notation
    cout << getBitPattern(i);

    cout << " & ";

    // functions
    for(unsigned j = 0; j < m_functions.size(); j++)
    {
      // separate subsequent columns
      if (j > 0)
      {
        cout << " & ";
      }

      // show default value
      cout << setw(m_functions[j].size()) << right << "?";
    }

    // finish row
    if (i < (nrows - 1))
    {
      // end line in LaTeX
      cout << " \\\\";

      // insert horizontal line
      if ((i + 1) % 4 == 0)
      {
        cout << endl << m_indent << "  \\hline";
      }
    }

    // finish row
    cout << endl;
  }

  // close LaTeX environment
  cout << m_indent << "\\end{tabular}" << endl;
}

// -------------
// getBitPattern
// -------------
/*
 *
 */
string IndexTable::getBitPattern(unsigned i) const
{
  stringstream pattern;

  for(unsigned s = m_inputs.size(); s > 0; s--)
  {
    if (i & (1 << (s - 1)))
    {
      pattern << setw( m_inputs[m_inputs.size() - s].size() ) << right << "1";
    }

    else
    {
      pattern << setw( m_inputs[m_inputs.size() - s].size() ) << right << "0";
    }

    if (s > 1)
    {
      pattern << " & ";
    }
  }

  return pattern.str();
}


// -----------------------------------------------------------------------------
// Document.cpp                                                     Document.cpp
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the implementation of the @ref Document class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-11-20
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include <iostream>
#include "message.h"
#include "Tokenizer.h"
#include "Document.h"


// -----------------------------------------------------------------------------
// Used namespaces                                               Used namespaces
// -----------------------------------------------------------------------------
using namespace std;


// -----------------------------------------------------------------------------
// Construction                                                     Construction
// -----------------------------------------------------------------------------

// --------
// Document
// --------
/*
 *
 */
Document::Document(const string& trigger)
: Generator(trigger)
{
  // nothing
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
bool Document::showCode(const Tokenizer& tokenizer)
{
  if ( !init(tokenizer) )
  {
    // signalize trouble
    return false;
  }

  cout << "% layout and global options" << endl;
  cout << "\\documentclass" << endl;
  cout << "[" << endl;
  cout << "  draft    = true," << endl;
  cout << "  fontsize = 11pt," << endl;
  cout << "  parskip  = half-," << endl;
  cout << "  BCOR     = 0pt," << endl;
  cout << "  DIV      = 11," << endl;
  cout << "  ngerman," << endl;
  cout << "  dvipsnames" << endl;
  cout << "]" << endl;
  cout << "{scrartcl}" << endl;
  cout << endl;
  cout << "% default packages" << endl;
  cout << "\\usepackage[utf8]{inputenc}" << endl;
  cout << "\\usepackage[T1]{fontenc}" << endl;
  cout << "\\usepackage{lmodern}" << endl;
  cout << "\\usepackage{babel}" << endl;
  cout << "% extra packages" << endl;
  cout << "\\usepackage{amsmath}" << endl;
  cout << "\\usepackage{amssymb}" << endl;
  cout << "\\usepackage{enumerate}" << endl;
  cout << "\\usepackage{graphicx}" << endl;
  cout << "\\usepackage{ifthen}" << endl;
  cout << "\\usepackage{siunitx}" << endl;
  cout << "\\usepackage{tikz}" << endl;
  cout << "\\usepackage{url}" << endl;
  cout << endl;
  cout << "% basic calculations in TikZ" << endl;
  cout << "\\usetikzlibrary{calc}" << endl;
  cout << endl;
  cout << "% use comma as decimal separator" << endl;
  cout << "\\sisetup{locale=DE, group-minimum-digits=4}" << endl;
  cout << endl;
  cout << "% ------------------------------------------------------------------------------" << endl;
  cout << "\\begin{document}" << endl;
  cout << "% ------------------------------------------------------------------------------" << endl;
  cout << endl;
  cout << "Template" << endl;
  cout << endl;
  cout << "% ------------------------------------------------------------------------------" << endl;
  cout << "\\end{document}" << endl;
  cout << "% ------------------------------------------------------------------------------" << endl;

  // signalize success
  return true;
}

// --------
// showHelp
// --------
/*
 *
 */
void Document::showHelp(bool verbose) const
{
  cout << getTrigger() << endl;
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
bool Document::init(const Tokenizer& tokenizer)
{
  // check number of tokens
  if (tokenizer.getTokenCount() > 1)
  {
    msg::wrn("too many tokens given");
  }

  // signalize success
  return true;
}


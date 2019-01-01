// -----------------------------------------------------------------------------
// Makefile.cpp                                                     Makefile.cpp
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the implementation of the @ref Makefile class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-11-14
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include <iostream>
#include "message.h"
#include "Tokenizer.h"
#include "Makefile.h"


// -----------------------------------------------------------------------------
// Used namespaces                                               Used namespaces
// -----------------------------------------------------------------------------
using namespace std;


// -----------------------------------------------------------------------------
// Construction                                                     Construction
// -----------------------------------------------------------------------------

// --------
// Makefile
// --------
/*
 *
 */
Makefile::Makefile(const string& trigger)
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
bool Makefile::showCode(const Tokenizer& tokenizer)
{
  if ( !init(tokenizer) )
  {
    // signalize trouble
    return false;
  }

  // makefile code
  cout << "# filename and extensions" << endl;
  cout << "FILE    = " << m_filename << endl;
  cout << "EXT_IN  = tex" << endl;
  cout << "EXT_OUT = pdf" << endl;
  cout << "EXT_LOG = log" << endl;
  cout << "EXT_TMP = tmp" << endl;
  cout << endl;
  cout << "# tools and options" << endl;
  cout << "TEX     = pdflatex" << endl;
  cout << "BIB     = bibtex" << endl;
  cout << "IDX     = makeindex" << endl;
  cout << "IFLAGS  =" << endl;
  cout << "EYE     = xreader" << endl;
  cout << "DEL     = rm -f" << endl;
  cout << "REN     = mv -f" << endl;
  cout << "CNV     = iconv" << endl;
  cout << "CFLAGS  = --from-code ISO_8859-1 --to-code UTF-8" << endl;
  cout << endl;
  cout << "# always create these targets" << endl;
  cout << ".PHONY: all clean" << endl;
  cout << endl;
  cout << "# show pdf file" << endl;
  cout << "all: $(FILE).$(EXT_OUT)" << endl;
  cout << "\t$(EYE) $(FILE).$(EXT_OUT)" << endl;
  cout << endl;
  cout << "# create pdf file from all tex files in the current directory" << endl;
  cout << "$(FILE).$(EXT_OUT): *.$(EXT_IN)" << endl;
  cout << "#\t$(TEX) $(FILE).$(EXT_IN)" << endl;
  cout << "#\t$(BIB) $(FILE)" << endl;
  cout << "#\t$(IDX) $(IFLAGS) $(FILE)" << endl;
  cout << "\t$(TEX) $(FILE).$(EXT_IN)" << endl;
  cout << "\t$(TEX) $(FILE).$(EXT_IN)" << endl;
  cout << "\t$(CNV) $(CFLAGS) $(FILE).$(EXT_LOG) > $(FILE).$(EXT_TMP)" << endl;
  cout << "\t$(DEL) $(FILE).$(EXT_LOG)" << endl;
  cout << "\t$(REN) $(FILE).$(EXT_TMP) $(FILE).$(EXT_LOG)" << endl;
  cout << endl;
  cout << "# remove temporary files" << endl;
  cout << "clean:" << endl;
  cout << "\t$(DEL) *.aux *.toc *.lof *.lot *.bbl *.blg *.idx *.ilg *.ind *.log *.thm $(FILE).$(EXT_OUT)" << endl;

  // signalize success
  return true;
}

// --------
// showHelp
// --------
/*
 *
 */
void Makefile::showHelp(bool verbose) const
{
  cout << getTrigger() << " [filename]" << endl;
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
bool Makefile::init(const Tokenizer& tokenizer)
{
  // set default filename
  m_filename = "document";

  // check number of tokens
  if (tokenizer.getTokenCount() > 2)
  {
    msg::wrn("too many tokens given");
  }

  // try to get filename from tokenizer
  if (tokenizer.getTokenCount() > 1)
  {
    // use second token as filename
    m_filename = tokenizer.getToken(1);
  }

  // signalize success
  return true;
}


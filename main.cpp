// -----------------------------------------------------------------------------
// main.cpp                                                             main.cpp
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the program's showHelp(), showVersion()
 *             and main() function and doxygen's main page.
 * @author     Col. Walter E. Kurtz
 * @version    2018-12-31
 * @copyright  GNU General Public License - Version 3.0
 *
 * @mainpage
 *
 * @section issue What is the issue here?
 *   txg generates LaTeX code. It parses lines from stdin and pushes the
 *   generated code to stdout.
 */

// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include <vector>
#include <iostream>
#include "message.h"
#include "cli.h"
#include "Tokenizer.h"
#include "Makefile.h"
#include "Document.h"
#include "NewCommandTable.h"
#include "IndexTable.h"
#include "KVMap.h"


// -----------------------------------------------------------------------------
// Used namespaces                                               Used namespaces
// -----------------------------------------------------------------------------
using namespace std;


// -----------------------------------------------------------------------------
// Functions                                                           Functions
// -----------------------------------------------------------------------------

// -----------
// showVersion
// -----------
/**
 * @brief  This function shows the program's version.
 */
void showVersion()
{
  cout << "2018-12-31" << endl;
}

// ----
// init
// ----
/**
 * @brief  This functions registers all known generators
 */
void init(vector<Generator*>& generators)
{
  // register all known generators
  generators.push_back( new Makefile        ("make")  );
  generators.push_back( new Document        ("doc")   );
  generators.push_back( new NewCommandTable ("nctab") );
  generators.push_back( new IndexTable      ("itab")  );
  generators.push_back( new KVMap           ("kv")    );
}

// -----
// clear
// -----
/**
 * @brief  This function deletes all Generators from the passed container.
 */
void clear(vector<Generator*>& generators)
{
  // delete current generators
  for(unsigned i = 0; i < generators.size(); i++)
  {
    delete generators[i];
  }

  // remove current pointers
  generators.clear();
}

// ----
// main
// ----
/**
 * @brief  The program starts in this function.
 *
 * @param argc  holds the number of passed command-line arguments.
 * @param argv  holds the list of passed command-line arguments.
 *
 * @return
 * Value | Meaning
 * ----: | :------
 *     0 | The requested operation finished successfully.
 *     1 | The requested operation failed.
 */
int main(int argc, char** argv)
{
  // create command-line parser
  cli cmdl;

  // parse command-line
  if ( cmdl.parse(argc, argv) )
  {
    // SHOW_HELP
    if (cmdl.operation == cli::SHOW_HELP)
    {
      // create all known generators
      vector<Generator*> generators;
      init(generators);

      for(unsigned i = 0; i < generators.size(); i++)
      {
        generators[i]->showHelp();
      }

      clear(generators);
    }

    // SHOW_VERSION
    else if (cmdl.operation == cli::SHOW_VERSION)
    {
      showVersion();
    }

    // DEFAULT
    else if (cmdl.operation == cli::DEFAULT)
    {
      // create all known generators
      vector<Generator*> generators;
      init(generators);

      Tokenizer tokenizer;

      // read all lines from stdin
      while ( tokenizer.readLine(cin) )
      {
        // skip empty lines
        if (tokenizer.getTokenCount() == 0)
        {
          continue;
        }

        // some flags that observe the operation
        bool triggered = false;
        bool generated = false;

        // check all generators
        for(unsigned i = 0; i < generators.size(); i++)
        {
          // get current generator
          Generator* gen = generators[i];

          // try to trigger this generator
          if ( gen->isResponsible(tokenizer) )
          {
            // update flag
            triggered = true;

            // try to generate related code
            if ( gen->showCode(tokenizer) )
            {
              // update flag
              generated = true;
            }

            // don't trigger other generators
            break;
          }
        }

        // check flag
        if (!triggered)
        {
          // notify user
          msg::err("unknown trigger");

          // stop reading more lines from stdin
          break;
        }

        // check flag
        if (!generated)
        {
          // stop reading more lines from stdin
          break;
        }
      }

      // free memory
      clear(generators);
    }
  }

  // invalid command-line
  else
  {
    // signalize trouble
    return 1;
  }

  // signalize success
  return 0;
}


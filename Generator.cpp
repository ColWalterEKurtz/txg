// -----------------------------------------------------------------------------
// Generator.cpp                                                   Generator.cpp
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the implementation of the @ref Generator class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-11-13
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include "Tokenizer.h"
#include "Generator.h"


// -----------------------------------------------------------------------------
// Used namespaces                                               Used namespaces
// -----------------------------------------------------------------------------
using namespace std;


// -----------------------------------------------------------------------------
// Construction                                                     Construction
// -----------------------------------------------------------------------------

// ---------
// Generator
// ---------
/*
 *
 */
Generator::Generator(const string& trigger)
: m_trigger(trigger)
{
  // nothing
}

// ----------
// ~Generator
// ----------
/*
 *
 */
Generator::~Generator()
{
  // nothing
}


// -----------------------------------------------------------------------------
// Handling                                                             Handling
// -----------------------------------------------------------------------------

// -------------
// isResponsible
// -------------
/*
 *
 */
bool Generator::isResponsible(const Tokenizer& tokenizer) const
{
  // no tokens available
  if (tokenizer.getTokenCount() == 0)
  {
    return false;
  }

  // check first token
  if (m_trigger == tokenizer.getToken(0))
  {
    return true;
  }

  // trigger doesn't match first token
  return false;
}


// -----------------------------------------------------------------------------
// Getter methods                                                 Getter methods
// -----------------------------------------------------------------------------

// ----------
// getTrigger
// ----------
/*
 *
 */
string Generator::getTrigger() const
{
  return m_trigger;
}


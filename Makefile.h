// -----------------------------------------------------------------------------
// Makefile.h                                                         Makefile.h
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the definition of the @ref Makefile class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-11-14
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// One-Definition-Rule                                       One-Definition-Rule
// -----------------------------------------------------------------------------
#ifndef MAKEFILE_H_INCLUDE_NO1
#define MAKEFILE_H_INCLUDE_NO1


// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include "Generator.h"


// --------
// Makefile
// --------
/**
 * @brief  This class generates makefiles that can compile pdf files from LaTeX.
 */
class Makefile : public Generator
{

public:

  // ---------------------------------------------------------------------------
  // Construction                                                   Construction
  // ---------------------------------------------------------------------------

  // --------
  // Makefile
  // --------
  /**
   * @brief  The constructor sets the generator's trigger.
   */
  Makefile(const std::string& trigger);


  // ---------------------------------------------------------------------------
  // Overridables                                                   Overridables
  // ---------------------------------------------------------------------------

  // --------
  // showCode
  // --------
  /**
   * @brief  This method pushes the generator's code to stdout.
   */
  virtual bool showCode(const Tokenizer& tokenizer);

  // --------
  // showHelp
  // --------
  /**
   * @brief  This method pushes the generator's syntax to stdout.
   */
  virtual void showHelp(bool verbose = false) const;


protected:

  // ---------------------------------------------------------------------------
  // Internal methods                                           Internal methods
  // ---------------------------------------------------------------------------

  // ----
  // init
  // ----
  /**
   * @brief  This method analyses the passed tokens.
   */
  bool init(const Tokenizer& tokenizer);


private:

  // ---------------------------------------------------------------------------
  // Attributes                                                       Attributes
  // ---------------------------------------------------------------------------

  /// the file to compile
  std::string m_filename;

};

#endif  /* #ifndef MAKEFILE_H_INCLUDE_NO1 */


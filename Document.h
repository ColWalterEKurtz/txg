// -----------------------------------------------------------------------------
// Document.h                                                         Document.h
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the definition of the @ref Document class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-11-14
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// One-Definition-Rule                                       One-Definition-Rule
// -----------------------------------------------------------------------------
#ifndef DOCUMENT_H_INCLUDE_NO1
#define DOCUMENT_H_INCLUDE_NO1


// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include "Generator.h"


// --------
// Document
// --------
/**
 * @brief  This class generates a default LaTeX document file.
 */
class Document : public Generator
{

public:

  // ---------------------------------------------------------------------------
  // Construction                                                   Construction
  // ---------------------------------------------------------------------------

  // --------
  // Document
  // --------
  /**
   * @brief  The constructor sets the generator's trigger.
   */
  Document(const std::string& trigger);


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

};

#endif  /* #ifndef DOCUMENT_H_INCLUDE_NO1 */


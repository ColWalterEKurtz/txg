// -----------------------------------------------------------------------------
// NewCommandTable.h                                           NewCommandTable.h
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the definition of the @ref NewCommandTable class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-11-17
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// One-Definition-Rule                                       One-Definition-Rule
// -----------------------------------------------------------------------------
#ifndef NEWCOMMANDTABLE_H_INCLUDE_NO1
#define NEWCOMMANDTABLE_H_INCLUDE_NO1


// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include "Generator.h"


// ---------------
// NewCommandTable
// ---------------
/**
 * @brief  This class generates a tabular environment with a command in each cell.
 */
class NewCommandTable : public Generator
{

public:

  // ---------------------------------------------------------------------------
  // Construction                                                   Construction
  // ---------------------------------------------------------------------------

  // ---------------
  // NewCommandTable
  // ---------------
  /**
   * @brief  The constructor sets the generator's trigger.
   */
  NewCommandTable(const std::string& trigger);


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

  // ----------
  // getCommand
  // ----------
  /**
   * @brief  This method returns the command for row i and column j.
   */
  std::string getCommand(unsigned i, unsigned j);


private:

  // ---------------------------------------------------------------------------
  // Attributes                                                       Attributes
  // ---------------------------------------------------------------------------

  /// the minimum indent for each line
  std::string m_indent;

  /// number of rows to create
  unsigned m_nrows;

  /// number of columns to create
  unsigned m_ncols;

};

#endif  /* #ifndef NEWCOMMANDTABLE_H_INCLUDE_NO1 */


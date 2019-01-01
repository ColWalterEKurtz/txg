// -----------------------------------------------------------------------------
// IndexTable.h                                                     IndexTable.h
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the definition of the @ref IndexTable class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-12-31
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// One-Definition-Rule                                       One-Definition-Rule
// -----------------------------------------------------------------------------
#ifndef INDEXTABLE_H_INCLUDE_NO1
#define INDEXTABLE_H_INCLUDE_NO1


// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include <vector>
#include "Generator.h"


// ----------
// IndexTable
// ----------
/**
 * @brief  This class generates index tables.
 */
class IndexTable : public Generator
{

public:

  // ---------------------------------------------------------------------------
  // Construction                                                   Construction
  // ---------------------------------------------------------------------------

  // ----------
  // IndexTable
  // ----------
  /**
   * @brief  The constructor sets the generator's trigger.
   */
  IndexTable(const std::string& trigger);


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

  // ---------
  // showTable
  // ---------
  /**
   * @brief  This method pushes the LaTeX code of the index table to stdout.
   */
  void showTable() const;

  // -------------
  // getBitPattern
  // -------------
  /**
   * @brief  This method returns the bit pattern of the passed integer.
   *
   * @param i  number to decode
   *
   * @return  0 & 1 & 1 & ... & 0
   */
  std::string getBitPattern(unsigned i) const;


private:

  // ---------------------------------------------------------------------------
  // Attributes                                                       Attributes
  // ---------------------------------------------------------------------------

  /// the minimum indent for each line
  std::string m_indent;

  /// the parsed operation
  enum { NONE, TABLE, BASH } m_operation;

  /// the list of input names
  std::vector<std::string> m_inputs;

  /// the list of function names
  std::vector<std::string> m_functions;

};

#endif  /* #ifndef INDEXTABLE_H_INCLUDE_NO1 */


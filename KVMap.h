// -----------------------------------------------------------------------------
// KVMap.h                                                               KVMap.h
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the definition of the @ref KVMap class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-12-31
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// One-Definition-Rule                                       One-Definition-Rule
// -----------------------------------------------------------------------------
#ifndef KVMAP_H_INCLUDE_NO1
#define KVMAP_H_INCLUDE_NO1


// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include <vector>
#include "Generator.h"


// -----
// KVMap
// -----
/**
 * @brief  This class generates the code to draw Karnaugh-Veitch maps
 *         (both definition and usage).
 */
class KVMap : public Generator
{

public:

  // ---------------------------------------------------------------------------
  // Construction                                                   Construction
  // ---------------------------------------------------------------------------

  // -----
  // KVMap
  // -----
  /**
   * @brief  The constructor sets the generator's trigger.
   */
  KVMap(const std::string& trigger);


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
  // show4x4def
  // ----------
  /**
   * @brief  This method shows the definition of a 4 times 4 KV-map.
   */
  void show4x4def() const;

  // ----------
  // show4x8def
  // ----------
  /**
   * @brief  This method shows the definition of a 4 times 8 KV-map.
   */
  void show4x8def() const;

  // ----------
  // show4x4map
  // ----------
  /**
   * @brief  This method shows a 4 times 4 KV-map.
   */
  void show4x4map() const;

  // ----------
  // show4x8map
  // ----------
  /**
   * @brief  This method shows a 4 times 8 KV-map.
   */
  void show4x8map() const;


private:

  // ---------------------------------------------------------------------------
  // Attributes                                                       Attributes
  // ---------------------------------------------------------------------------

  /// the minimum indentation of each line
  std::string m_indent;

  /// the name of the shown function
  std::string m_function;

  /// the names of the variables
  std::vector<std::string> m_variables;

};

#endif  /* #ifndef KVMAP_H_INCLUDE_NO1 */


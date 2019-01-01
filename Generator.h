// -----------------------------------------------------------------------------
// Generator.h                                                       Generator.h
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the definition of the @ref Generator class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-11-14
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// One-Definition-Rule                                       One-Definition-Rule
// -----------------------------------------------------------------------------
#ifndef GENERATOR_H_INCLUDE_NO1
#define GENERATOR_H_INCLUDE_NO1


// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include <string>


// ---------
// Tokenizer
// ---------
/*
 * Forward declaration
 */
class Tokenizer;


// ---------
// Generator
// ---------
/**
 * @brief  The base class of all code generators.
 */
class Generator
{

public:

  // ---------------------------------------------------------------------------
  // Construction                                                   Construction
  // ---------------------------------------------------------------------------

  // ---------
  // Generator
  // ---------
  /**
   * @brief  The constructor defines the generator's trigger.
   */
  Generator(const std::string& trigger);

  // ----------
  // ~Generator
  // ----------
  /**
   * @brief  The destructor is virtual.
   */
  virtual ~Generator();


  // ---------------------------------------------------------------------------
  // Overridables                                                   Overridables
  // ---------------------------------------------------------------------------

  // -------------
  // isResponsible
  // -------------
  /**
   * @brief  This method checks if the Generator can handle the parsed line.
   */
  virtual bool isResponsible(const Tokenizer& tokenizer) const;

  // --------
  // showCode
  // --------
  /**
   * @brief  This method pushes the generator's code to stdout.
   */
  virtual bool showCode(const Tokenizer& tokenizer) = 0;

  // --------
  // showHelp
  // --------
  /**
   * @brief  This method pushes the generator's syntax to stdout.
   */
  virtual void showHelp(bool verbose = false) const = 0;


  // ---------------------------------------------------------------------------
  // Getter methods                                               Getter methods
  // ---------------------------------------------------------------------------

  // ----------
  // getTrigger
  // ----------
  /**
   * @brief  This method returns the generator's trigger.
   */
  std::string getTrigger() const;


private:

  // ---------------------------------------------------------------------------
  // Attributes                                                       Attributes
  // ---------------------------------------------------------------------------

  /// the generator's trigger
  std::string m_trigger;

};

#endif  /* #ifndef GENERATOR_H_INCLUDE_NO1 */


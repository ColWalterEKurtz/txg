// -----------------------------------------------------------------------------
// KVMap.cpp                                                           KVMap.cpp
// -----------------------------------------------------------------------------
/**
 * @file
 * @brief      This file holds the implementation of the @ref KVMap class.
 * @author     Col. Walter E. Kurtz
 * @version    2018-12-31
 * @copyright  GNU General Public License - Version 3.0
 */

// -----------------------------------------------------------------------------
// Includes                                                             Includes
// -----------------------------------------------------------------------------
#include <iostream>
#include "message.h"
#include "Tokenizer.h"
#include "KVMap.h"


// -----------------------------------------------------------------------------
// Used namespaces                                               Used namespaces
// -----------------------------------------------------------------------------
using namespace std;


// -----------------------------------------------------------------------------
// Construction                                                     Construction
// -----------------------------------------------------------------------------

// -----
// KVMap
// -----
/*
 *
 */
KVMap::KVMap(const string& trigger)
:Generator(trigger)
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
bool KVMap::showCode(const Tokenizer& tokenizer)
{
  if ( !init(tokenizer) )
  {
    // signalize trouble
    return false;
  }

  if (m_variables.empty())
  {
    show4x4def();
    cout << endl;
    show4x8def();
  }

  else if (m_variables.size() == 4)
  {
    show4x4map();
  }

  else if (m_variables.size() == 5)
  {
    show4x8map();
  }

  else
  {
    // notify user
    msg::err("A KV-map of this size cannot be generated (yet).");

    // signalize trouble
    return false;
  }
  
  // signalize success
  return true;
}

// --------
// showHelp
// --------
/*
 *
 */
void KVMap::showHelp(bool verbose) const
{
  cout << getTrigger() << endl;
  cout << getTrigger() << " function v1 v2 v3 v4 [v5]" << endl;
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
bool KVMap::init(const Tokenizer& tokenizer)
{
  // reset
  m_indent = "";
  m_function = "";
  m_variables.clear();

  // set current indent
  m_indent = tokenizer.getIndent();

  // get number of extracted tokens
  const unsigned ntokens = tokenizer.getTokenCount();

  // only trigger given
  if (ntokens == 1)
  {
    // show definitions
    return true;
  }

  // at least name of the function given
  if (ntokens > 1)
  {
    // use second token as name of the function
    m_function = tokenizer.getToken(1);
  }

  // set names of the variables
  for(unsigned i = 2; i < ntokens; i++)
  {
    // get current token
    const string& token = tokenizer.getToken(i);

    // append next variable
    m_variables.push_back(token);
  }

  // check if function name is followed by variables
  if (m_variables.empty())
  {
    // notify user
    msg::err("no variables given");

    // signalize trouble
    return false;
  }

  // signalize success
  return true;
}

// ----------
// show4x4def
// ----------
/*
 *
 */
void KVMap::show4x4def() const
{
  cout << m_indent << "% ----" << endl;
  cout << m_indent << "% KV16" << endl;
  cout << m_indent << "% ----" << endl;
  cout << m_indent << "%" << endl;
  cout << m_indent << "% This environment draws a 4x4 KV-map within a tikz environment." << endl;
  cout << m_indent << "%" << endl;
  cout << m_indent << "\\newenvironment{KV16}" << endl;
  cout << m_indent << "{%" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % Public functions                                            Public functions" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  % nolabels" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % disable input labels" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\nolabels}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\showlabels}{FALSE}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ---------" << endl;
  cout << m_indent << "  % noindices" << endl;
  cout << m_indent << "  % ---------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % disable index numbers" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\noindices}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\showindices}{FALSE}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  % clearoutput" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % empty all function values" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\clearoutput}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\setoutput{0}{}%" << endl;
  cout << m_indent << "    \\setoutput{1}{}%" << endl;
  cout << m_indent << "    \\setoutput{2}{}%" << endl;
  cout << m_indent << "    \\setoutput{3}{}%" << endl;
  cout << m_indent << "    \\setoutput{4}{}%" << endl;
  cout << m_indent << "    \\setoutput{5}{}%" << endl;
  cout << m_indent << "    \\setoutput{6}{}%" << endl;
  cout << m_indent << "    \\setoutput{7}{}%" << endl;
  cout << m_indent << "    \\setoutput{8}{}%" << endl;
  cout << m_indent << "    \\setoutput{9}{}%" << endl;
  cout << m_indent << "    \\setoutput{10}{}%" << endl;
  cout << m_indent << "    \\setoutput{11}{}%" << endl;
  cout << m_indent << "    \\setoutput{12}{}%" << endl;
  cout << m_indent << "    \\setoutput{13}{}%" << endl;
  cout << m_indent << "    \\setoutput{14}{}%" << endl;
  cout << m_indent << "    \\setoutput{15}{}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  % function" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the function" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\function}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valuefname}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  % inputA" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % set the name of the input variable that toggles with the lowest frequency" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the variable" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\inputA}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valueinputA}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  % inputB" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the variable" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\inputB}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valueinputB}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  % inputC" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the variable" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\inputC}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valueinputC}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  % inputD" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % set the name of the input variable that toggles with the highest frequency" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the variable" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\inputD}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valueinputD}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -------" << endl;
  cout << m_indent << "  % minterm" << endl;
  cout << m_indent << "  % -------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  minterm number 0 ... 15" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\minterm}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\setoutput{##1}{1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -------" << endl;
  cout << m_indent << "  % maxterm" << endl;
  cout << m_indent << "  % -------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  maxterm number 0 ... 15" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\maxterm}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\setoutput{##1}{0}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  % dontcare" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  don't care number 0 ... 15" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\dontcare}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\setoutput{##1}{X}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -----" << endl;
  cout << m_indent << "  % areas" << endl;
  cout << m_indent << "  % -----" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % define areas to fill" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\areas}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\printareas}{##1}" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  % colorize" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1 top row          (1..m)" << endl;
  cout << m_indent << "  % #2 left column      (1..n)" << endl;
  cout << m_indent << "  % #3 width            (number of columns)" << endl;
  cout << m_indent << "  % #4 height           (number of rows)" << endl;
  cout << m_indent << "  % #5 top    reduction (pt, cm, ...)" << endl;
  cout << m_indent << "  % #6 bottom reduction (pt, cm, ...)" << endl;
  cout << m_indent << "  % #7 left   reduction (pt, cm, ...)" << endl;
  cout << m_indent << "  % #8 right  reduction (pt, cm, ...)" << endl;
  cout << m_indent << "  % #9 color" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\colorize}[9]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\begin{scope}[xshift=0cm + (##2 - 1) * 1cm, yshift=4cm - (##1 - 1) * 1cm]" << endl;
  cout << m_indent << "      % background" << endl;
  cout << m_indent << "      \\ifthenelse{\\equal{\\showtype}{FILL}}%" << endl;
  cout << m_indent << "      {%" << endl;
  cout << m_indent << "        \\fill" << endl;
  cout << m_indent << "        [" << endl;
  cout << m_indent << "          opacity=0.5," << endl;
  cout << m_indent << "          fill=##9," << endl;
  cout << m_indent << "          rounded corners" << endl;
  cout << m_indent << "        ] (0cm + ##7, 0cm - ##5) rectangle (1cm * ##3 - ##8, -1cm * ##4 + ##6);" << endl;
  cout << m_indent << "      }%" << endl;
  cout << m_indent << "      {\\relax}%" << endl;
  cout << m_indent << "      % border" << endl;
  cout << m_indent << "      \\ifthenelse{\\equal{\\showtype}{DRAW}}%" << endl;
  cout << m_indent << "      {%" << endl;
  cout << m_indent << "        \\draw" << endl;
  cout << m_indent << "        [" << endl;
  cout << m_indent << "          draw=##9," << endl;
  cout << m_indent << "          line width=1pt," << endl;
  cout << m_indent << "          rounded corners" << endl;
  cout << m_indent << "        ] (0cm + ##7, 0cm - ##5) rectangle (1cm * ##3 - ##8, -1cm * ##4 + ##6);" << endl;
  cout << m_indent << "      }%" << endl;
  cout << m_indent << "      {\\relax}%" << endl;
  cout << m_indent << "    \\end{scope}" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % Internal functions                                        Internal functions" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % ---------" << endl;
  cout << m_indent << "  % setoutput" << endl;
  cout << m_indent << "  % ---------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % used my minterm, maxterm and dontcare" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  index: 0 .. 15" << endl;
  cout << m_indent << "  % #2  text" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\setoutput}[2]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    % map index to matrix position" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{0}} {\\renewcommand{\\valueoutputAA}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{1}} {\\renewcommand{\\valueoutputAB}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{2}} {\\renewcommand{\\valueoutputAD}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{3}} {\\renewcommand{\\valueoutputAC}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{4}} {\\renewcommand{\\valueoutputBA}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{5}} {\\renewcommand{\\valueoutputBB}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{6}} {\\renewcommand{\\valueoutputBD}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{7}} {\\renewcommand{\\valueoutputBC}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{8}} {\\renewcommand{\\valueoutputDA}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{9}} {\\renewcommand{\\valueoutputDB}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{10}}{\\renewcommand{\\valueoutputDD}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{11}}{\\renewcommand{\\valueoutputDC}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{12}}{\\renewcommand{\\valueoutputCA}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{13}}{\\renewcommand{\\valueoutputCB}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{14}}{\\renewcommand{\\valueoutputCD}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{15}}{\\renewcommand{\\valueoutputCC}{##2}}{\\relax}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  % printlabels" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % print all input labels" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\printlabels}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\draw[|-|] ( 4.3,  0.0) -- node[right] {\\valueinputA} ( 4.3,  2.0);" << endl;
  cout << m_indent << "    \\draw[|-|] (-0.3,  1.0) -- node[left]  {\\valueinputB} (-0.3,  3.0);" << endl;
  cout << m_indent << "    \\draw[|-|] ( 1.0, -0.3) -- node[below] {\\valueinputD} ( 3.0, -0.3);" << endl;
  cout << m_indent << "    \\draw[|-|] ( 2.0,  4.3) -- node[above] {\\valueinputC} ( 4.0,  4.3);" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------------" << endl;
  cout << m_indent << "  % printindices" << endl;
  cout << m_indent << "  % ------------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % print all index numbers" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\printindices}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\begin{scope}[xshift=2mm, yshift=8mm]" << endl;
  cout << m_indent << "      % 1. row (top)" << endl;
  cout << m_indent << "      \\node at (0, 3) {{\\tiny\\sffamily  0}};" << endl;
  cout << m_indent << "      \\node at (1, 3) {{\\tiny\\sffamily  1}};" << endl;
  cout << m_indent << "      \\node at (2, 3) {{\\tiny\\sffamily  3}};" << endl;
  cout << m_indent << "      \\node at (3, 3) {{\\tiny\\sffamily  2}};" << endl;
  cout << m_indent << "      % 2. row" << endl;
  cout << m_indent << "      \\node at (0, 2) {{\\tiny\\sffamily  4}};" << endl;
  cout << m_indent << "      \\node at (1, 2) {{\\tiny\\sffamily  5}};" << endl;
  cout << m_indent << "      \\node at (2, 2) {{\\tiny\\sffamily  7}};" << endl;
  cout << m_indent << "      \\node at (3, 2) {{\\tiny\\sffamily  6}};" << endl;
  cout << m_indent << "      % 3. row" << endl;
  cout << m_indent << "      \\node at (0, 1) {{\\tiny\\sffamily 12}};" << endl;
  cout << m_indent << "      \\node at (1, 1) {{\\tiny\\sffamily 13}};" << endl;
  cout << m_indent << "      \\node at (2, 1) {{\\tiny\\sffamily 15}};" << endl;
  cout << m_indent << "      \\node at (3, 1) {{\\tiny\\sffamily 14}};" << endl;
  cout << m_indent << "      % 4. row (bottom)" << endl;
  cout << m_indent << "      \\node at (0, 0) {{\\tiny\\sffamily  8}};" << endl;
  cout << m_indent << "      \\node at (1, 0) {{\\tiny\\sffamily  9}};" << endl;
  cout << m_indent << "      \\node at (2, 0) {{\\tiny\\sffamily 11}};" << endl;
  cout << m_indent << "      \\node at (3, 0) {{\\tiny\\sffamily 10}};" << endl;
  cout << m_indent << "    \\end{scope}" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  % printoutput" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % show all output values" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\printoutput}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\begin{scope}[xshift=0.5cm, yshift=0.5cm]" << endl;
  cout << m_indent << "      % 1. row (top)" << endl;
  cout << m_indent << "      \\node at (0, 3) {\\valueoutputAA};" << endl;
  cout << m_indent << "      \\node at (1, 3) {\\valueoutputAB};" << endl;
  cout << m_indent << "      \\node at (2, 3) {\\valueoutputAC};" << endl;
  cout << m_indent << "      \\node at (3, 3) {\\valueoutputAD};" << endl;
  cout << m_indent << "      % 2. row" << endl;
  cout << m_indent << "      \\node at (0, 2) {\\valueoutputBA};" << endl;
  cout << m_indent << "      \\node at (1, 2) {\\valueoutputBB};" << endl;
  cout << m_indent << "      \\node at (2, 2) {\\valueoutputBC};" << endl;
  cout << m_indent << "      \\node at (3, 2) {\\valueoutputBD};" << endl;
  cout << m_indent << "      % 3. row" << endl;
  cout << m_indent << "      \\node at (0, 1) {\\valueoutputCA};" << endl;
  cout << m_indent << "      \\node at (1, 1) {\\valueoutputCB};" << endl;
  cout << m_indent << "      \\node at (2, 1) {\\valueoutputCC};" << endl;
  cout << m_indent << "      \\node at (3, 1) {\\valueoutputCD};" << endl;
  cout << m_indent << "      % 4. row (bottom)" << endl;
  cout << m_indent << "      \\node at (0, 0) {\\valueoutputDA};" << endl;
  cout << m_indent << "      \\node at (1, 0) {\\valueoutputDB};" << endl;
  cout << m_indent << "      \\node at (2, 0) {\\valueoutputDC};" << endl;
  cout << m_indent << "      \\node at (3, 0) {\\valueoutputDD};" << endl;
  cout << m_indent << "    \\end{scope}" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ----------" << endl;
  cout << m_indent << "  % printareas" << endl;
  cout << m_indent << "  % ----------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % show all colorized areas" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\printareas}{\\relax}%" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % Attributes                                                        Attributes" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % some common colors" << endl;
  cout << m_indent << "  \\definecolor{C1}{named}{Red}%" << endl;
  cout << m_indent << "  \\definecolor{C2}{named}{Green}%" << endl;
  cout << m_indent << "  \\definecolor{C3}{named}{Blue}%" << endl;
  cout << m_indent << "  \\definecolor{C4}{named}{Sepia}%" << endl;
  cout << m_indent << "  \\definecolor{C5}{named}{Cyan}%" << endl;
  cout << m_indent << "  \\definecolor{C6}{named}{Magenta}%" << endl;
  cout << m_indent << "  \\definecolor{C7}{named}{Yellow}%" << endl;
  cout << m_indent << "  \\definecolor{C8}{named}{Gray}%" << endl;
  cout << m_indent << "  % flags" << endl;
  cout << m_indent << "  \\newcommand{\\showlabels}{TRUE}%" << endl;
  cout << m_indent << "  \\newcommand{\\showindices}{TRUE}%" << endl;
  cout << m_indent << "  % name of the function" << endl;
  cout << m_indent << "  \\newcommand{\\valuefname}{\\relax}%" << endl;
  cout << m_indent << "  % names of the four input variables" << endl;
  cout << m_indent << "  \\newcommand{\\valueinputA}{$e_3$}%" << endl;
  cout << m_indent << "  \\newcommand{\\valueinputB}{$e_2$}%" << endl;
  cout << m_indent << "  \\newcommand{\\valueinputC}{$e_1$}%" << endl;
  cout << m_indent << "  \\newcommand{\\valueinputD}{$e_0$}%" << endl;
  cout << m_indent << "  % output values (matrix positions)" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAA}{0}% 0" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAB}{0}% 1" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAC}{0}% 3" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAD}{0}% 2" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBA}{0}% 4" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBB}{0}% 5" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBC}{0}% 7" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBD}{0}% 6" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCA}{0}% 12" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCB}{0}% 13" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCC}{0}% 15" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCD}{0}% 14" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDA}{0}% 8" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDB}{0}% 9" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDC}{0}% 11" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDD}{0}% 10" << endl;
  cout << m_indent << "}%" << endl;
  cout << m_indent << "{%" << endl;
  cout << m_indent << "  \\begingroup" << endl;
  cout << m_indent << "    % show colored areas first (lowest layer)" << endl;
  cout << m_indent << "    \\begin{scope}" << endl;
  cout << m_indent << "      % clip colored areas" << endl;
  cout << m_indent << "      \\clip (-0.15, -0.15) rectangle (4.15, 4.15);" << endl;
  cout << m_indent << "      % show background" << endl;
  cout << m_indent << "      {\\newcommand{\\showtype}{FILL}\\printareas}%" << endl;
  cout << m_indent << "      % show border" << endl;
  cout << m_indent << "      {\\newcommand{\\showtype}{DRAW}\\printareas}%" << endl;
  cout << m_indent << "    \\end{scope}" << endl;
  cout << m_indent << "    % show grid" << endl;
  cout << m_indent << "    \\draw (0, 0) grid (4, 4);" << endl;
  cout << m_indent << "    % name of the function" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{\\valuefname}{\\relax}}{\\relax}{\\node at (-0.5, 4.5) {\\valuefname};}" << endl;
  cout << m_indent << "    % labels" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{\\showlabels}{TRUE}}{\\printlabels}{\\relax}" << endl;
  cout << m_indent << "    % indices" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{\\showindices}{TRUE}}{\\printindices}{\\relax}" << endl;
  cout << m_indent << "    % output values" << endl;
  cout << m_indent << "    \\printoutput" << endl;
  cout << m_indent << "  \\endgroup" << endl;
  cout << m_indent << "}%" << endl;
}

// ----------
// show4x8def
// ----------
/*
 *
 */
void KVMap::show4x8def() const
{
  cout << m_indent << "% ----" << endl;
  cout << m_indent << "% KV32" << endl;
  cout << m_indent << "% ----" << endl;
  cout << m_indent << "%" << endl;
  cout << m_indent << "% This environment draws a 4x8 KV-map within a tikz environment." << endl;
  cout << m_indent << "%" << endl;
  cout << m_indent << "\\newenvironment{KV32}" << endl;
  cout << m_indent << "{%" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % Public functions                                            Public functions" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  % nolabels" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % disable input labels" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\nolabels}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\showlabels}{FALSE}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ---------" << endl;
  cout << m_indent << "  % noindices" << endl;
  cout << m_indent << "  % ---------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % disable index numbers" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\noindices}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\showindices}{FALSE}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  % clearoutput" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % empty all function values" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\clearoutput}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\setoutput{0}{}%" << endl;
  cout << m_indent << "    \\setoutput{1}{}%" << endl;
  cout << m_indent << "    \\setoutput{2}{}%" << endl;
  cout << m_indent << "    \\setoutput{3}{}%" << endl;
  cout << m_indent << "    \\setoutput{4}{}%" << endl;
  cout << m_indent << "    \\setoutput{5}{}%" << endl;
  cout << m_indent << "    \\setoutput{6}{}%" << endl;
  cout << m_indent << "    \\setoutput{7}{}%" << endl;
  cout << m_indent << "    \\setoutput{8}{}%" << endl;
  cout << m_indent << "    \\setoutput{9}{}%" << endl;
  cout << m_indent << "    \\setoutput{10}{}%" << endl;
  cout << m_indent << "    \\setoutput{11}{}%" << endl;
  cout << m_indent << "    \\setoutput{12}{}%" << endl;
  cout << m_indent << "    \\setoutput{13}{}%" << endl;
  cout << m_indent << "    \\setoutput{14}{}%" << endl;
  cout << m_indent << "    \\setoutput{15}{}%" << endl;
  cout << m_indent << "    \\setoutput{16}{}%" << endl;
  cout << m_indent << "    \\setoutput{17}{}%" << endl;
  cout << m_indent << "    \\setoutput{18}{}%" << endl;
  cout << m_indent << "    \\setoutput{19}{}%" << endl;
  cout << m_indent << "    \\setoutput{20}{}%" << endl;
  cout << m_indent << "    \\setoutput{21}{}%" << endl;
  cout << m_indent << "    \\setoutput{22}{}%" << endl;
  cout << m_indent << "    \\setoutput{23}{}%" << endl;
  cout << m_indent << "    \\setoutput{24}{}%" << endl;
  cout << m_indent << "    \\setoutput{25}{}%" << endl;
  cout << m_indent << "    \\setoutput{26}{}%" << endl;
  cout << m_indent << "    \\setoutput{27}{}%" << endl;
  cout << m_indent << "    \\setoutput{28}{}%" << endl;
  cout << m_indent << "    \\setoutput{29}{}%" << endl;
  cout << m_indent << "    \\setoutput{30}{}%" << endl;
  cout << m_indent << "    \\setoutput{31}{}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  % function" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the function" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\function}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valuefname}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  % inputA" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % set the name of the input variable that toggles with the lowest frequency" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the variable" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\inputA}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valueinputA}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  % inputB" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the variable" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\inputB}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valueinputB}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  % inputC" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the variable" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\inputC}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valueinputC}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  % inputD" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the variable" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\inputD}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valueinputD}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  % inputE" << endl;
  cout << m_indent << "  % ------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % set the name of the input variable that toggles with the highest frequency" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  name of the variable" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\inputE}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\valueinputE}{##1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -------" << endl;
  cout << m_indent << "  % minterm" << endl;
  cout << m_indent << "  % -------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  minterm number 0 ... 31" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\minterm}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\setoutput{##1}{1}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -------" << endl;
  cout << m_indent << "  % maxterm" << endl;
  cout << m_indent << "  % -------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  maxterm number 0 ... 31" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\maxterm}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\setoutput{##1}{0}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  % dontcare" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  don't care number 0 ... 31" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\dontcare}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\setoutput{##1}{X}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -----" << endl;
  cout << m_indent << "  % areas" << endl;
  cout << m_indent << "  % -----" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % define areas to fill" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\areas}[1]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\renewcommand{\\printareas}{##1}" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  % colorize" << endl;
  cout << m_indent << "  % --------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1 top row          (1..m)" << endl;
  cout << m_indent << "  % #2 left column      (1..n)" << endl;
  cout << m_indent << "  % #3 width            (number of columns)" << endl;
  cout << m_indent << "  % #4 height           (number of rows)" << endl;
  cout << m_indent << "  % #5 top    reduction (pt, cm, ...)" << endl;
  cout << m_indent << "  % #6 bottom reduction (pt, cm, ...)" << endl;
  cout << m_indent << "  % #7 left   reduction (pt, cm, ...)" << endl;
  cout << m_indent << "  % #8 right  reduction (pt, cm, ...)" << endl;
  cout << m_indent << "  % #9 color" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\colorize}[9]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\begin{scope}[xshift=0cm + (##2 - 1) * 1cm, yshift=4cm - (##1 - 1) * 1cm]" << endl;
  cout << m_indent << "      % background" << endl;
  cout << m_indent << "      \\ifthenelse{\\equal{\\showtype}{FILL}}%" << endl;
  cout << m_indent << "      {%" << endl;
  cout << m_indent << "        \\fill" << endl;
  cout << m_indent << "        [" << endl;
  cout << m_indent << "          opacity=0.5," << endl;
  cout << m_indent << "          fill=##9," << endl;
  cout << m_indent << "          rounded corners" << endl;
  cout << m_indent << "        ] (0cm + ##7, 0cm - ##5) rectangle (1cm * ##3 - ##8, -1cm * ##4 + ##6);" << endl;
  cout << m_indent << "      }%" << endl;
  cout << m_indent << "      {\\relax}%" << endl;
  cout << m_indent << "      % border" << endl;
  cout << m_indent << "      \\ifthenelse{\\equal{\\showtype}{DRAW}}%" << endl;
  cout << m_indent << "      {%" << endl;
  cout << m_indent << "        \\draw" << endl;
  cout << m_indent << "        [" << endl;
  cout << m_indent << "          draw=##9," << endl;
  cout << m_indent << "          line width=1pt," << endl;
  cout << m_indent << "          rounded corners" << endl;
  cout << m_indent << "        ] (0cm + ##7, 0cm - ##5) rectangle (1cm * ##3 - ##8, -1cm * ##4 + ##6);" << endl;
  cout << m_indent << "      }%" << endl;
  cout << m_indent << "      {\\relax}%" << endl;
  cout << m_indent << "    \\end{scope}" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % Internal functions                                        Internal functions" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % ---------" << endl;
  cout << m_indent << "  % setoutput" << endl;
  cout << m_indent << "  % ---------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % used my minterm, maxterm and dontcare" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % #1  index: 0 .. 31" << endl;
  cout << m_indent << "  % #2  text" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\setoutput}[2]" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    % map index to matrix position" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{0}} {\\renewcommand{\\valueoutputAA}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{1}} {\\renewcommand{\\valueoutputAB}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{2}} {\\renewcommand{\\valueoutputAD}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{3}} {\\renewcommand{\\valueoutputAC}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{4}} {\\renewcommand{\\valueoutputBA}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{5}} {\\renewcommand{\\valueoutputBB}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{6}} {\\renewcommand{\\valueoutputBD}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{7}} {\\renewcommand{\\valueoutputBC}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{8}} {\\renewcommand{\\valueoutputDA}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{9}} {\\renewcommand{\\valueoutputDB}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{10}}{\\renewcommand{\\valueoutputDD}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{11}}{\\renewcommand{\\valueoutputDC}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{12}}{\\renewcommand{\\valueoutputCA}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{13}}{\\renewcommand{\\valueoutputCB}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{14}}{\\renewcommand{\\valueoutputCD}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{15}}{\\renewcommand{\\valueoutputCC}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{16}}{\\renewcommand{\\valueoutputAH}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{17}}{\\renewcommand{\\valueoutputAG}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{18}}{\\renewcommand{\\valueoutputAE}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{19}}{\\renewcommand{\\valueoutputAF}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{20}}{\\renewcommand{\\valueoutputBH}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{21}}{\\renewcommand{\\valueoutputBG}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{22}}{\\renewcommand{\\valueoutputBE}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{23}}{\\renewcommand{\\valueoutputBF}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{24}}{\\renewcommand{\\valueoutputDH}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{25}}{\\renewcommand{\\valueoutputDG}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{26}}{\\renewcommand{\\valueoutputDE}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{27}}{\\renewcommand{\\valueoutputDF}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{28}}{\\renewcommand{\\valueoutputCH}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{29}}{\\renewcommand{\\valueoutputCG}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{30}}{\\renewcommand{\\valueoutputCE}{##2}}{\\relax}%" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{##1}{31}}{\\renewcommand{\\valueoutputCF}{##2}}{\\relax}%" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  % printlabels" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % print all input labels" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\printlabels}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\draw[|-|] ( 8.3,  0.0) -- node[right] {\\valueinputB} ( 8.3,  2.0);" << endl;
  cout << m_indent << "    \\draw[|-|] (-0.3,  1.0) -- node[left]  {\\valueinputC} (-0.3,  3.0);" << endl;
  cout << m_indent << "    \\draw[|-|] ( 1.0, -0.3) -- node[below] {\\valueinputE} ( 3.0, -0.3);" << endl;
  cout << m_indent << "    \\draw[|-|] ( 5.0, -0.3) -- node[below] {\\valueinputE} ( 7.0, -0.3);" << endl;
  cout << m_indent << "    \\draw[|-|] ( 2.0,  4.3) -- node[above] {\\valueinputD} ( 6.0,  4.3);" << endl;
  cout << m_indent << "    \\draw[|-|] ( 4.0,  5.0) -- node[above] {\\valueinputA} ( 8.0,  5.0);" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ------------" << endl;
  cout << m_indent << "  % printindices" << endl;
  cout << m_indent << "  % ------------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % print all index numbers" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\printindices}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\begin{scope}[xshift=2mm, yshift=8mm]" << endl;
  cout << m_indent << "      % 1. row (top)" << endl;
  cout << m_indent << "      \\node at (0, 3) {{\\tiny\\sffamily  0}};" << endl;
  cout << m_indent << "      \\node at (1, 3) {{\\tiny\\sffamily  1}};" << endl;
  cout << m_indent << "      \\node at (2, 3) {{\\tiny\\sffamily  3}};" << endl;
  cout << m_indent << "      \\node at (3, 3) {{\\tiny\\sffamily  2}};" << endl;
  cout << m_indent << "      \\node at (4, 3) {{\\tiny\\sffamily 18}};" << endl;
  cout << m_indent << "      \\node at (5, 3) {{\\tiny\\sffamily 19}};" << endl;
  cout << m_indent << "      \\node at (6, 3) {{\\tiny\\sffamily 17}};" << endl;
  cout << m_indent << "      \\node at (7, 3) {{\\tiny\\sffamily 16}};" << endl;
  cout << m_indent << "      % 2. row" << endl;
  cout << m_indent << "      \\node at (0, 2) {{\\tiny\\sffamily  4}};" << endl;
  cout << m_indent << "      \\node at (1, 2) {{\\tiny\\sffamily  5}};" << endl;
  cout << m_indent << "      \\node at (2, 2) {{\\tiny\\sffamily  7}};" << endl;
  cout << m_indent << "      \\node at (3, 2) {{\\tiny\\sffamily  6}};" << endl;
  cout << m_indent << "      \\node at (4, 2) {{\\tiny\\sffamily 22}};" << endl;
  cout << m_indent << "      \\node at (5, 2) {{\\tiny\\sffamily 23}};" << endl;
  cout << m_indent << "      \\node at (6, 2) {{\\tiny\\sffamily 21}};" << endl;
  cout << m_indent << "      \\node at (7, 2) {{\\tiny\\sffamily 20}};" << endl;
  cout << m_indent << "      % 3. row" << endl;
  cout << m_indent << "      \\node at (0, 1) {{\\tiny\\sffamily 12}};" << endl;
  cout << m_indent << "      \\node at (1, 1) {{\\tiny\\sffamily 13}};" << endl;
  cout << m_indent << "      \\node at (2, 1) {{\\tiny\\sffamily 15}};" << endl;
  cout << m_indent << "      \\node at (3, 1) {{\\tiny\\sffamily 14}};" << endl;
  cout << m_indent << "      \\node at (4, 1) {{\\tiny\\sffamily 30}};" << endl;
  cout << m_indent << "      \\node at (5, 1) {{\\tiny\\sffamily 31}};" << endl;
  cout << m_indent << "      \\node at (6, 1) {{\\tiny\\sffamily 29}};" << endl;
  cout << m_indent << "      \\node at (7, 1) {{\\tiny\\sffamily 28}};" << endl;
  cout << m_indent << "      % 4. row (bottom)" << endl;
  cout << m_indent << "      \\node at (0, 0) {{\\tiny\\sffamily  8}};" << endl;
  cout << m_indent << "      \\node at (1, 0) {{\\tiny\\sffamily  9}};" << endl;
  cout << m_indent << "      \\node at (2, 0) {{\\tiny\\sffamily 11}};" << endl;
  cout << m_indent << "      \\node at (3, 0) {{\\tiny\\sffamily 10}};" << endl;
  cout << m_indent << "      \\node at (4, 0) {{\\tiny\\sffamily 26}};" << endl;
  cout << m_indent << "      \\node at (5, 0) {{\\tiny\\sffamily 27}};" << endl;
  cout << m_indent << "      \\node at (6, 0) {{\\tiny\\sffamily 25}};" << endl;
  cout << m_indent << "      \\node at (7, 0) {{\\tiny\\sffamily 24}};" << endl;
  cout << m_indent << "    \\end{scope}" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  % printoutput" << endl;
  cout << m_indent << "  % -----------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % show all output values" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\printoutput}" << endl;
  cout << m_indent << "  {%" << endl;
  cout << m_indent << "    \\begin{scope}[xshift=0.5cm, yshift=0.5cm]" << endl;
  cout << m_indent << "      % 1. row (top)" << endl;
  cout << m_indent << "      \\node at (0, 3) {\\valueoutputAA};" << endl;
  cout << m_indent << "      \\node at (1, 3) {\\valueoutputAB};" << endl;
  cout << m_indent << "      \\node at (2, 3) {\\valueoutputAC};" << endl;
  cout << m_indent << "      \\node at (3, 3) {\\valueoutputAD};" << endl;
  cout << m_indent << "      \\node at (4, 3) {\\valueoutputAE};" << endl;
  cout << m_indent << "      \\node at (5, 3) {\\valueoutputAF};" << endl;
  cout << m_indent << "      \\node at (6, 3) {\\valueoutputAG};" << endl;
  cout << m_indent << "      \\node at (7, 3) {\\valueoutputAH};" << endl;
  cout << m_indent << "      % 2. row" << endl;
  cout << m_indent << "      \\node at (0, 2) {\\valueoutputBA};" << endl;
  cout << m_indent << "      \\node at (1, 2) {\\valueoutputBB};" << endl;
  cout << m_indent << "      \\node at (2, 2) {\\valueoutputBC};" << endl;
  cout << m_indent << "      \\node at (3, 2) {\\valueoutputBD};" << endl;
  cout << m_indent << "      \\node at (4, 2) {\\valueoutputBE};" << endl;
  cout << m_indent << "      \\node at (5, 2) {\\valueoutputBF};" << endl;
  cout << m_indent << "      \\node at (6, 2) {\\valueoutputBG};" << endl;
  cout << m_indent << "      \\node at (7, 2) {\\valueoutputBH};" << endl;
  cout << m_indent << "      % 3. row" << endl;
  cout << m_indent << "      \\node at (0, 1) {\\valueoutputCA};" << endl;
  cout << m_indent << "      \\node at (1, 1) {\\valueoutputCB};" << endl;
  cout << m_indent << "      \\node at (2, 1) {\\valueoutputCC};" << endl;
  cout << m_indent << "      \\node at (3, 1) {\\valueoutputCD};" << endl;
  cout << m_indent << "      \\node at (4, 1) {\\valueoutputCE};" << endl;
  cout << m_indent << "      \\node at (5, 1) {\\valueoutputCF};" << endl;
  cout << m_indent << "      \\node at (6, 1) {\\valueoutputCG};" << endl;
  cout << m_indent << "      \\node at (7, 1) {\\valueoutputCH};" << endl;
  cout << m_indent << "      % 4. row (bottom)" << endl;
  cout << m_indent << "      \\node at (0, 0) {\\valueoutputDA};" << endl;
  cout << m_indent << "      \\node at (1, 0) {\\valueoutputDB};" << endl;
  cout << m_indent << "      \\node at (2, 0) {\\valueoutputDC};" << endl;
  cout << m_indent << "      \\node at (3, 0) {\\valueoutputDD};" << endl;
  cout << m_indent << "      \\node at (4, 0) {\\valueoutputDE};" << endl;
  cout << m_indent << "      \\node at (5, 0) {\\valueoutputDF};" << endl;
  cout << m_indent << "      \\node at (6, 0) {\\valueoutputDG};" << endl;
  cout << m_indent << "      \\node at (7, 0) {\\valueoutputDH};" << endl;
  cout << m_indent << "    \\end{scope}" << endl;
  cout << m_indent << "  }%" << endl;
  cout << m_indent << "  % ----------" << endl;
  cout << m_indent << "  % printareas" << endl;
  cout << m_indent << "  % ----------" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  % show all colorized areas" << endl;
  cout << m_indent << "  %" << endl;
  cout << m_indent << "  \\newcommand{\\printareas}{\\relax}%" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % Attributes                                                        Attributes" << endl;
  cout << m_indent << "  % ----------------------------------------------------------------------------" << endl;
  cout << m_indent << "  % some common colors" << endl;
  cout << m_indent << "  \\definecolor{C1}{named}{Red}%" << endl;
  cout << m_indent << "  \\definecolor{C2}{named}{Green}%" << endl;
  cout << m_indent << "  \\definecolor{C3}{named}{Blue}%" << endl;
  cout << m_indent << "  \\definecolor{C4}{named}{Sepia}%" << endl;
  cout << m_indent << "  \\definecolor{C5}{named}{Cyan}%" << endl;
  cout << m_indent << "  \\definecolor{C6}{named}{Magenta}%" << endl;
  cout << m_indent << "  \\definecolor{C7}{named}{Yellow}%" << endl;
  cout << m_indent << "  \\definecolor{C8}{named}{Gray}%" << endl;
  cout << m_indent << "  % flags" << endl;
  cout << m_indent << "  \\newcommand{\\showlabels}{TRUE}%" << endl;
  cout << m_indent << "  \\newcommand{\\showindices}{TRUE}%" << endl;
  cout << m_indent << "  % name of the function" << endl;
  cout << m_indent << "  \\newcommand{\\valuefname}{\\relax}%" << endl;
  cout << m_indent << "  % names of the five input variables" << endl;
  cout << m_indent << "  \\newcommand{\\valueinputA}{$e_4$}%" << endl;
  cout << m_indent << "  \\newcommand{\\valueinputB}{$e_3$}%" << endl;
  cout << m_indent << "  \\newcommand{\\valueinputC}{$e_2$}%" << endl;
  cout << m_indent << "  \\newcommand{\\valueinputD}{$e_1$}%" << endl;
  cout << m_indent << "  \\newcommand{\\valueinputE}{$e_0$}%" << endl;
  cout << m_indent << "  % output values (matrix positions)" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAA}{$0$}% 0" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAB}{$0$}% 1" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAC}{$0$}% 3" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAD}{$0$}% 2" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAE}{$0$}% 18" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAF}{$0$}% 19" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAG}{$0$}% 17" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputAH}{$0$}% 16" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBA}{$0$}% 4" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBB}{$0$}% 5" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBC}{$0$}% 7" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBD}{$0$}% 6" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBE}{$0$}% 22" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBF}{$0$}% 23" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBG}{$0$}% 21" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputBH}{$0$}% 20" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCA}{$0$}% 12" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCB}{$0$}% 13" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCC}{$0$}% 15" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCD}{$0$}% 14" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCE}{$0$}% 30" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCF}{$0$}% 31" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCG}{$0$}% 29" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputCH}{$0$}% 28" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDA}{$0$}% 8" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDB}{$0$}% 9" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDC}{$0$}% 11" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDD}{$0$}% 10" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDE}{$0$}% 26" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDF}{$0$}% 27" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDG}{$0$}% 25" << endl;
  cout << m_indent << "  \\newcommand{\\valueoutputDH}{$0$}% 24" << endl;
  cout << m_indent << "}%" << endl;
  cout << m_indent << "{%" << endl;
  cout << m_indent << "  \\begingroup" << endl;
  cout << m_indent << "    % show colored areas first (lowest layer)" << endl;
  cout << m_indent << "    \\begin{scope}" << endl;
  cout << m_indent << "      % clip colored areas" << endl;
  cout << m_indent << "      \\clip (-0.15, -0.15) rectangle (8.15, 4.15);" << endl;
  cout << m_indent << "      % show background" << endl;
  cout << m_indent << "      {\\newcommand{\\showtype}{FILL}\\printareas}%" << endl;
  cout << m_indent << "      % show border" << endl;
  cout << m_indent << "      {\\newcommand{\\showtype}{DRAW}\\printareas}%" << endl;
  cout << m_indent << "    \\end{scope}" << endl;
  cout << m_indent << "    % show grid" << endl;
  cout << m_indent << "    \\draw (0, 0) grid (8, 4);" << endl;
  cout << m_indent << "    % name of the function" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{\\valuefname}{\\relax}}{\\relax}{\\node at (-0.5, 4.5) {\\valuefname};}" << endl;
  cout << m_indent << "    % labels" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{\\showlabels}{TRUE}}{\\printlabels}{\\relax}" << endl;
  cout << m_indent << "    % indices" << endl;
  cout << m_indent << "    \\ifthenelse{\\equal{\\showindices}{TRUE}}{\\printindices}{\\relax}" << endl;
  cout << m_indent << "    % output values" << endl;
  cout << m_indent << "    \\printoutput" << endl;
  cout << m_indent << "  \\endgroup" << endl;
  cout << m_indent << "}%" << endl;
}

// ----------
// show4x4map
// ----------
/*
 *
 */
void KVMap::show4x4map() const
{
  cout << m_indent << "\\begin{center}" << endl;
  cout << m_indent << "  \\begin{tikzpicture}" << endl;
  cout << m_indent << "    \\begin{KV16}" << endl;
  cout << m_indent << "      %\\nolabels" << endl;
  cout << m_indent << "      %\\noindices" << endl;
  cout << m_indent << "      %\\clearoutput" << endl;
  cout << m_indent << "      \\function{" << m_function << "}" << endl;
  cout << m_indent << "      \\inputA{" << m_variables[0] << "}" << endl;
  cout << m_indent << "      \\inputB{" << m_variables[1] << "}" << endl;
  cout << m_indent << "      \\inputC{" << m_variables[2] << "}" << endl;
  cout << m_indent << "      \\inputD{" << m_variables[3] << "}" << endl;
  cout << m_indent << "      %printf \"\\\\minterm{%d}\\n\"  {0..15}" << endl;
  cout << m_indent << "      %printf \"\\\\maxterm{%d}\\n\"  {0..15}" << endl;
  cout << m_indent << "      %printf \"\\\\dontcare{%d}\\n\" {0..15}" << endl;
  cout << m_indent << "      %\\areas" << endl;
  cout << m_indent << "      %{" << endl;
  cout << m_indent << "        %\\colorize{i}{j}{w}{h}{t}{b}{l}{r}{C1}" << endl;
  cout << m_indent << "      %}" << endl;
  cout << m_indent << "    \\end{KV16}" << endl;
  cout << m_indent << "  \\end{tikzpicture}" << endl;
  cout << m_indent << "\\end{center}" << endl;
}

// ----------
// show4x8map
// ----------
/*
 *
 */
void KVMap::show4x8map() const
{
  cout << m_indent << "\\begin{center}" << endl;
  cout << m_indent << "  \\begin{tikzpicture}" << endl;
  cout << m_indent << "    \\begin{KV32}" << endl;
  cout << m_indent << "      %\\nolabels" << endl;
  cout << m_indent << "      %\\noindices" << endl;
  cout << m_indent << "      %\\clearoutput" << endl;
  cout << m_indent << "      \\function{" << m_function << "}" << endl;
  cout << m_indent << "      \\inputA{" << m_variables[0] << "}" << endl;
  cout << m_indent << "      \\inputB{" << m_variables[1] << "}" << endl;
  cout << m_indent << "      \\inputC{" << m_variables[2] << "}" << endl;
  cout << m_indent << "      \\inputD{" << m_variables[3] << "}" << endl;
  cout << m_indent << "      \\inputE{" << m_variables[4] << "}" << endl;
  cout << m_indent << "      %printf \"\\\\minterm{%d}\\n\"  {0..31}" << endl;
  cout << m_indent << "      %printf \"\\\\maxterm{%d}\\n\"  {0..31}" << endl;
  cout << m_indent << "      %printf \"\\\\dontcare{%d}\\n\" {0..31}" << endl;
  cout << m_indent << "      %\\areas" << endl;
  cout << m_indent << "      %{" << endl;
  cout << m_indent << "        %\\colorize{i}{j}{w}{h}{t}{b}{l}{r}{C1}" << endl;
  cout << m_indent << "      %}" << endl;
  cout << m_indent << "    \\end{KV32}" << endl;
  cout << m_indent << "  \\end{tikzpicture}" << endl;
  cout << m_indent << "\\end{center}" << endl;
}


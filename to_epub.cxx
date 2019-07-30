#!/usr/bin/env rooki
// rooki:flags -pedantic -std=c++11
// rooki:flags -x c++
// rooki:spell g++ $flags $f -o $bin
//
#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char *argv[])
{
  std::cout << "Converting to epub" << std::endl;

  std::vector<std::string> contents {
    "splash.html ",
    "contents.html ",
    "chapter1_introduction.html ",
    "chapter2_installation.html ",
    "chapter3_basics.html ",
    "chapter4_interactive_prompt.html ",
    "chapter5_languages.html ",
    "chapter6_parsing.html ",
    "chapter7_evaluation.html ",
    "chapter8_error_handling.html ",
    "chapter9_s_expressions.html ",
    "chapter10_q_expressions.html ",
    "chapter11_variables.html ",
    "chapter12_functions.html ",
    "chapter13_conditionals.html ",
    "chapter14_strings.html ",
    "chapter15_standard_library.html ",
    "chapter16_bonus_projects.html ",
    "credits.html ",
    "appendix_a_hand_rolled_parser.html ",
  };

  std::string cmd{
    "pandoc "
    "--epub-stylesheet=mystyle.css "
    "-S -o main.epub "
  };

  cmd = std::accumulate(contents.begin(), contents.end(), cmd);

  std::cout << cmd << std::endl;
  system(cmd.c_str());

  return 0;
}

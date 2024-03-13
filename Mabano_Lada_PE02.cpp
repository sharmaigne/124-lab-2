/**
 * Legolas Tyrael B. Lada | 2022-04734
 * Sharmaigne Angelie C. Mabano | 2022-03464
 * 2-BSCS
 *
 * CMSC 124 PE02: String Expansion/Compression
 */
#include "definitions.h"
#include <cctype>
#include <iostream>
#include <sstream>

using namespace std;

int main(void) {
  system("clear||cls");
  bool running = true;

  while (running) {
    system("clear||cls");
    switch (menu()) {
      case PROG_DESC:
        programDescription();
        break;
      case EXPANSION:
        expansionLoop();
        break;
      case COMPRESSION:
        compressionLoop();
        break;
      case EXIT:
        running = false;
        break;
      default:
        cout << "\nInvalid input, try again.\n";
    }
  }
  return 0;
}

char menu(void) {
  char ret;
  cout << "\n\nWelcome to this String Expansion/Compression program! Please choose an action to perform...\n"
          "[P] Program Description\n"
          "[E] String Expansion\n"
          "[C] String Compression\n"
          "[X] Exit\n"
          "\nChoice: ";
  cin >> ret;
  cin.ignore(1000, '\n');

  system("clear||cls");
  return toupper(ret); /* lowercase versions of P E C X should be valid */
}

void programDescription(void) {
  cout << "\n\n\t\t==== PROGRAM DESCRIPTION ====\n\n"
          "Legolas Tyrael B. Lada       | 2022-04734\n"
          "Sharmaigne Angelie C. Mabano | 2022-03464\n"
          "March 12, 2024 - March 13, 2024\n"
          "\n=====\n"
          "Menu Descriptions:\n\n"
          "- [P] Program Description: Prints out the program description to "
          "stdout.\n"
          "- [E] String Expansion: Enters loop to expand strings.\n"
          "Each iteration asks for a string and displays its expanded version if input is valid.\n"
          "- [C] String Compression: Enters loop to compress strings.\n"
          "Each iteration asks for a string and displays its compressed version if input is valid.\n"
          "- [X] Exit: Terminates the program.\n"
          "\n=====\n"
          "Work distribution:\n"
          "Tyrael: compression, testing\n"
          "Sharmaigne: boilerplate code, expansion\n\n"
          "\n=====\n"
          "Additional information:\n"
          "It was decided that string expansion translates both \"1a\" and \"a\" as \"a\" and accepts \"0a\" as \"\".\n\n"
          "\t\t============================\n\n";
  char exit;
  cout << "Enter any key to continue: ";
  cin >> exit;
  cin.ignore(1000, '\n');
}

void expansionLoop() {
  string s;
  char exit;

  cout << "\n\n\t\t==== STRING EXPANSION ====\n\n"
          "For each valid compressed string of format: { <nX> | <X> } \n"
          "where n is a positive number (0 to INT MAX) and X is a character in the english alphabet.\n\n"
          "\t\t==========================\n\n";
  

  while (true) {
    cout << "\nEnter a compressed string: ";
    getline(cin, s);
    
    string result = expandString(s);
    if (result == INVALID)
      cout << "\nInvalid input, please follow specified format for compressed strings.";
    else
      cout << "Expanded form: " << result;

    cout << "\n\nDo you want to expand another string?\n\n"
            "[X] NO\n"
            "[other] YES\n"
            "Choice: ";

    cin >> exit;
    cin.ignore(1000, '\n');
    if (toupper(exit) == EXIT)
      return;
  }
}

void compressionLoop() {
  string s;
  char exit;

  cout << "\n\n\t\t==== STRING COMPRESSION ====\n\n"
          "For each valid expanded string of format: { X } \n"
          "where X is a character in the english alphabet.\n\n"
          "\t\t============================\n\n";
  

  while (true) {
    cout << "\nEnter an expanded string: ";
    getline(cin, s);

    cout << "Compressed form: " << compressString(s);

    cout << "\n\nDo you want to compress another string?\n\n"
            "[X] NO\n"
            "[other] YES\n"
            "Choice: ";

    cin >> exit;
    cin.ignore(1000, '\n');
    if (toupper(exit) == EXIT)
      return;
  }
}

string expandString(const string s) {
  string expandedString = "";
  string prefixNum = "";
  for (int i = 0; i < s.size(); i++) {

    /* while digit, collect into prefixNum */
    while (isdigit(s[i]))
      prefixNum += s[i++];
    
    /*  i >= s.size() : if gets here if the string ends with a digit (invalid)
        !isalpha(s[i]) : invalid character (non alpha-numeric)*/
    /* TODO: add check for if stoi(prefixNum) > INT_MAX (throws out_of_range error) */
    if (i >= s.size() || !isalpha(s[i]))
      return INVALID;

    /* appends to expandedString the character s[i] prefixNum times
      NOTE: can be done more elegantly with string constructor */
    if (prefixNum == "")
      prefixNum = "1";
    for (int _ = 0; _ < stoi(prefixNum); _++)
      expandedString += s[i];
    
    prefixNum = "";
  }

  return expandedString;
}

string compressString(const string s) {
  stringstream ss;    // we use a stringstream for easy formatting
  int currCount = 1;
  char previous = s[0];

  /* s[0] is the only character not caught by the check inside the for loop */
  if (!isalpha(s[0]))
    return INVALID;

  for (size_t i = 1; i < s.length(); i++) {
    if (!isalpha(s[i]))
      return INVALID;

    if (previous == s[i]) {
      currCount++;
      continue;
    }

    if (currCount == 1)
      ss << previous;
    else
      ss << currCount << previous;

    previous = s[i];
    currCount = 1;
  }
  previous = s[s.length() - 1];
  // last grouping
  if (currCount == 1)
    ss << previous;
  else
    ss << currCount << previous;

  return ss.str();
}

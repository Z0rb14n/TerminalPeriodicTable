//
//  ElementsInput.h
//  PeriodicTable
//
//  Created by Jonathan Nah on 2020-08-30.
//  Copyright (c) 2020 Jonathan Nah. All rights reserved.
//

#ifndef __PeriodicTable__ElementsInput__
#define __PeriodicTable__ElementsInput__

#include <string>
#include <vector>
#include "Element.h"

class ElementsInput {
public:
  const static std::string WEEBLY_WEBSITE_FILE;
  const static std::string GITHUB_WEBSITE_FILE;
  const static std::string INPUT_FILE_NAME;
  const static std::string INPUT_FILE;
  const static std::string FILE_NOT_FOUND;
  const static bool githubServer = true;
  const static bool weeblyWebsite = false;
  static std::vector<Element> getElements();
  static std::vector<Element> readFromInputFile();
  static std::vector<Element> readFromWebFile();
  static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

#endif /* defined(__PeriodicTable__ElementsInput__) */

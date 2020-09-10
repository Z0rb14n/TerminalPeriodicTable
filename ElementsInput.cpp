//
//  ElementsInput.cpp
//  PeriodicTable
//
//  Created by Jonathan Nah on 2020-08-30.
//  Copyright (c) 2020 Jonathan Nah. All rights reserved.
//

#include "ElementsInput.h"
#include "Element.h"

#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <curl/curl.h>

const std::string ElementsInput::FILE_NOT_FOUND =  "404: Not Found\n";
const std::string ElementsInput::WEEBLY_WEBSITE_FILE = "https:/z0rb14nservers.weebly.com/uploads/6/6/2/9/66291023/fatboi.txt";
const std::string ElementsInput::GITHUB_WEBSITE_FILE = "https://raw.githubusercontent.com/Z0rb14n/TerminalPeriodicTable/master/data.txt";
const std::string ElementsInput::INPUT_FILE_NAME = "data.txt";
const std::string ElementsInput::INPUT_FILE = "./Desktop/Useful Stuff/Coding/programs/PeriodicTable/" + ElementsInput::INPUT_FILE_NAME;

std::vector<Element> ElementsInput::getElements() {
  try {
    return readFromWebFile();
  } catch (std::exception & e) {
    return readFromInputFile();
  }
}

std::vector<Element> ElementsInput::readFromWebFile() {
  CURL *curl;
  CURLcode res;
  std::string readBuffer;
  curl = curl_easy_init();
  if (curl) {
    if (weeblyWebsite) curl_easy_setopt(curl, CURLOPT_URL, WEEBLY_WEBSITE_FILE.c_str());
    else curl_easy_setopt(curl, CURLOPT_URL, GITHUB_WEBSITE_FILE.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    if (readBuffer == FILE_NOT_FOUND) {
      if (weeblyWebsite) {
        curl_easy_setopt(curl, CURLOPT_URL, GITHUB_WEBSITE_FILE.c_str());
      } else {
        curl_easy_setopt(curl, CURLOPT_URL, WEEBLY_WEBSITE_FILE.c_str());
      }
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      if (readBuffer == FILE_NOT_FOUND) throw new std::invalid_argument("Could not access Weebly/Github.");
    }
    curl_easy_cleanup(curl);
  }
  std::istringstream onlineStream(readBuffer);
  std::string line;
  std::vector<Element> elements;
  while (getline(onlineStream,line)) elements.push_back(Element(line));
  return elements;
}

std::vector<Element> ElementsInput::readFromInputFile() {
  std::string line;
  std::ifstream myfile (INPUT_FILE);
  std::vector<Element> elements;
  if (myfile.is_open()){
    while ( getline (myfile,line)) elements.push_back(Element(line));
    myfile.close();
    return elements;
  }
  else throw new std::invalid_argument("Cannot open input file.");
}

size_t ElementsInput::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}
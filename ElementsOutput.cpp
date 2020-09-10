//
//  ElementsOutput.cpp
//  PeriodicTable
//
//  Created by Jonathan Nah on 2020-08-30.
//  Copyright (c) 2020 Jonathan Nah. All rights reserved.
//

#include "ElementsOutput.h"
#include "ElementsInput.h"
#include "Element.h"
#include <string>
#include <sstream>
#include <fstream>

const std::string ElementsOutput::INPUT_FILE_NAME = ElementsInput::INPUT_FILE_NAME;
const std::string ElementsOutput::REVISION_DIR = "./Desktop/Useful Stuff/Coding/programs/PeriodicTable/Revisions/";
const std::string ElementsOutput::SAVED_REVISION_DIR = "./Desktop/Useful Stuff/Coding/programs/PeriodicTable/Saved Revisions/";
const std::string ElementsOutput::LATEST_REVISION_NAME = "latest.txt";

void ElementsOutput::deleteRevisions(){
  std::string temp = REVISION_DIR;
  std::string final = "";
  std::istringstream stream(temp);
  unsigned short int i = 0;
  while(stream.good()){
    std::string piece;
    stream >> piece;
    if (i != 0) final = final + "\\" + " " + piece;
    else final = piece;
    i++;
  }
  final = final + "*";
  system(("exec rm -r " + final).c_str());
}

void ElementsOutput::makeRevision(std::vector<Element> elements){
  std::ofstream someFile;
  someFile.open(REVISION_DIR + LATEST_REVISION_NAME);
  if(someFile.is_open()){
    for(unsigned int i = 0; i < elements.size(); i++){
      std::string fatOutput;
      Element element = elements[i];
      if (i == 0) fatOutput = element.serialize();
      else fatOutput = "\n" + element.serialize();
      someFile << fatOutput;
    }
    someFile.close();
  } else throw std::invalid_argument("Could not write fo file.");
}

void ElementsOutput::addRevision(std::string fileName, std::vector<Element> elements) {
  std::string wantedFile = REVISION_DIR + fileName;
  std::ifstream infile(wantedFile);
  std::istringstream stream(fileName);
  std::string filePrefix;
  unsigned int number = 0;
  stream >> filePrefix >> number;
  if (infile.good()){
    if(fileName == LATEST_REVISION_NAME) addRevision("Revision 1.txt", elements);
    else{
      std::string lol = "Revision " + std::to_string(number+ 1) + ".txt";
      addRevision(lol,elements);
    }
  }
  if(fileName == LATEST_REVISION_NAME){
    makeRevision(elements);
    return;
  } else if (number == 1){
    if (rename((REVISION_DIR + LATEST_REVISION_NAME).c_str(), (REVISION_DIR + "Revision 1.txt").c_str()) == 0){
    } else throw std::invalid_argument("Could not rename file.");
    return;
  } else {
    std::string temp = REVISION_DIR + "Revision " + std::to_string(number - 1) + ".txt";
    std::string temp2 = REVISION_DIR + "Revision " + std::to_string(number) + ".txt";
    if (rename(temp.c_str(), temp2.c_str()) == 0){
    } else throw std::invalid_argument("Could not rename file.");
  }
  infile.close();
}

void ElementsOutput::saveRevision(std::vector<Element> elements) {
  saveRevision("keptRevision.txt",elements);
}

void ElementsOutput::saveRevision(std::string fileName, std::vector<Element> elements) {
  std::string wantedFile = SAVED_REVISION_DIR + fileName;
  std::ifstream infile(wantedFile);
  std::istringstream stream(fileName);
  std::string filePrefix;
  unsigned int number = 0;
  stream >> filePrefix >> number;
  if (infile.good()){
    if(fileName == "keptRevision.txt") saveRevision("keptRevision 1.txt",elements);
    else{
      std::string lol = "keptRevision " + std::to_string(number+ 1) + ".txt";
      saveRevision(lol,elements);
    }
  }
  if(fileName == "keptRevision.txt"){
    //Copies the latext revision into saved revision folder
    if (rename((REVISION_DIR + LATEST_REVISION_NAME).c_str(), (SAVED_REVISION_DIR + "keptRevision.txt").c_str()) == 0){
      std::ifstream fin(SAVED_REVISION_DIR + "keptRevision.txt") ;
      std::ofstream fout(REVISION_DIR + LATEST_REVISION_NAME);
      if(fin.is_open() && fout.is_open()){
        std::string temp;
        while(std::getline(fin, temp)) fout << temp << std::endl;
      } else throw std::invalid_argument("Could not open file.");
    } else throw std::invalid_argument("Could not rename file.");
    return;
  } else if (number == 1){
    if (rename((SAVED_REVISION_DIR + "keptRevision.txt").c_str(), (SAVED_REVISION_DIR + "keptRevision 1.txt").c_str()) == 0){
    } else throw std::invalid_argument("Could not rename file.");
    return;
  } else {
    std::string temp = SAVED_REVISION_DIR + "keptRevision " + std::to_string(number - 1) + ".txt";
    std::string temp2 = SAVED_REVISION_DIR + "keptRevision " + std::to_string(number) + ".txt";
    if (rename(temp.c_str(), temp2.c_str()) == 0){
    } else throw std::invalid_argument("Could not rename file.");
  }
}

bool ElementsOutput::hasRevision(){
  std::ifstream infile(REVISION_DIR + LATEST_REVISION_NAME);
  return infile.good();
}
#include "ELF.h"

#include <vector>
#include <fstream>
#include <iostream>

ElfHeaderBase PullHeaderBase(char* buffer) {
  return *((ElfHeaderBase*)buffer);
}

Elf::Elf(std::string filename) {
  std::ifstream file(filename, std::ios::binary | std::ios::ate);
  std::streamsize size = file.tellg();
  file.seekg(0, std::ios::beg);

  std::vector<char> buffer(size);
  if (!file.read(buffer.data(), size))
  {
    // make a better exception or get rid of the exception
    throw std::invalid_argument("There was a problem while reading the file :(");
  }

  auto base = PullHeaderBase(buffer.data());
  std::cout << base.MagicNumber << std::endl;
  std::cout << (uint16_t)base.ObjectFileType << std::endl;
  std::cout << (uint16_t)base.Architecture << std::endl;
}
#include <iostream>

#include "ELF.h"

int main(int argc, char **argv) {
  std::cout << "Hello World" << std::endl;

  auto elf = Elf("samples/elf-Linux-Mips4-bash");
}
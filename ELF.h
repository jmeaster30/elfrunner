#pragma once

#include <cstdint>
#include <string>

enum class ABI : char {
  SystemV,
  HPUX,
  NETBSD,
  LINUX,
  GNUHURD,
  SOLARIS = 6,
  AIX,
  IRIX,
  FREEBSD,
  TRU64,
  NOVELLMODESTO,
  OPENBSD,
  OPENVMS,
  NONSTOPKERNEL,
  AROS,
  FENIXOS,
  NUXICLOUDABI,
  STRATUSOPENVOS
};

enum class Type : uint16_t {
  ET_NONE,
  ET_REL,
  ET_EXEC,
  ET_DYN,
  ET_CORE,
  // ET_LOOS
  // ET_HIOS
  // ET_LOPROC
  // ET_HIPROC
};

enum class ISA : uint16_t {
  None = 0,
  ATT,
  SPARC,
  x86,
  M68K,
  M88K,
  INTELMCU,
  INTEL80860,
  MIPS,
  IBMSYS370,
  MIPSRS3000LE,
  HPPARISC = 16,
  INTEL80960 = 19,
  POWERPC,
  POWERPC64,
  S390,
  IBMSPU,
  NECV800 = 36,
  FUJITSUFR20,
  TRWRH32,
  MRCE,
  ARM,
  DIGITALALPHA,
  SUPERH,
  SPARC9,
  SIEMENSTRICORE,
  ARGONAUTRISC,
  H8300,
  H8300H,
  H8S,
  H8500,
  IA64,
  MIPSX,
  COLDFIRE,
  M68HC12,
  FUJITSUMMA,
  SIEMENSPCP,
  SONYNCPU,
  NDR1,
  STARCORE,
  TOYOTAME16,
  ST100,
  TINYJ,
  AMDX8664,
  SONYDSP,
  PDP10,
  PDP11,
  SIEMENSFX66,
  ST9P,
  ST7,
  MC68HC16,
  MC68HC11,
  MC68HC08,
  MC68HC05,
  SILICONSVX,
  ST19,
  DIGITALVAX,
  AXIS32,
  INFINEON32,
  ELEMENT1464,
  LSILOGIC16,
  TMS320C6000 = 0x8C,
  MCSTELBRUSE2K = 0xAF,
  Z80 = 0xDC,
  RISCV = 0xF3,
  BERKLEYPF = 0xF7,
  WDC65C816 = 0x101
};

struct ElfHeaderBase {
  uint32_t MagicNumber; // 7F 45 4C 46
  uint8_t Class;           // 1 = 32bit, 2 = 64bit
  uint8_t Endianness;      // 1 = Little, 2 = Big
  uint8_t Version1;
  ABI TargetABI;
  uint8_t ABIVersion;
  uint8_t Padding[7];
  Type ObjectFileType;
  ISA Architecture;
  uint32_t Version2;
};

struct Elf32HeaderInfo { 
  uint32_t Entry;
  uint32_t ProgramHeaderOffset;
  uint32_t SectionHeaderOffset;
  uint32_t Flags;
  uint16_t HeaderSize;
  uint16_t ProgramHeaderTableEntrySize;
  uint16_t ProgramHeaderTableSize;
  uint16_t SectionHeaderTableEntrySize;
  uint16_t SectionHeaderTableSize;
  uint16_t SectionNamesIndex;
};

struct Elf64HeaderInfo { 
  uint64_t Entry;
  uint64_t ProgramHeaderOffset;
  uint64_t SectionHeaderOffset;
  uint32_t Flags;
  uint16_t HeaderSize;
  uint16_t ProgramHeaderTableEntrySize;
  uint16_t ProgramHeaderTableSize;
  uint16_t SectionHeaderTableEntrySize;
  uint16_t SectionHeaderTableSize;
  uint16_t SectionNamesIndex;
};

struct ElfHeader {
  ElfHeaderBase Base;
  union {
    Elf32HeaderInfo HeaderInfo32;
    Elf64HeaderInfo HeaderInfo64;
  } HeaderInfo;
};

class Elf
{
public:
  ElfHeader Header;

  Elf(std::string filename);
};
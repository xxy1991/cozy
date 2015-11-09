#ifndef __COZY_ELF_ENUM__
#define __COZY_ELF_ENUM__

#include "CozyDef.h"

namespace CozyElf
{
    enum class COZY_API ElfClass : unsigned char
    {
        Unknow = 0,
        Bit32 ,
        Bit64,
    };

    enum class COZY_API ElfEndianess : unsigned char
    {
        Unknow = 0,
        LittleEndian,
        BigEndian,
    };

    enum class COZY_API ElfFileType : Elf32_Half
    {
        None = 0,
        Relocatable,
        Executable,
        SharedObject,
        Core
    };

    enum class COZY_API ElfMachineType : Elf32_Half
    {
        None = 0, // No machine
        M32 = 1, // AT&T WE 32100
        SPARC = 2, // SPARC
        Intel386 = 3, // Intel 386
        M68K = 4, // Motorola 68000
        M88K = 5, // Motorola 88000
        Intel486 = 6, // Intel 486 (deprecated)
        Intel860 = 7, // Intel 80860
        MIPS = 8, // MIPS R3000
        S370 = 9, // IBM System/370
        MIPSRS3LE = 10, // MIPS RS3000 Little-endian
        PARISC = 15, // Hewlett-Packard PA-RISC
        VPP500 = 17, // Fujitsu VPP500
        SPARC32Plus = 18, // Enhanced instruction set SPARC
        Intel960 = 19, // Intel 80960
        PPC = 20, // PowerPC
        PPC64 = 21, // PowerPC64
        S390 = 22, // IBM System/390
        SPU = 23, // IBM SPU/SPC
        V800 = 36, // NEC V800
        FR20 = 37, // Fujitsu FR20
        RH32 = 38, // TRW RH-32
        RCE = 39, // Motorola RCE
        ARM = 40, // ARM
        Alpha = 41, // DEC Alpha
        SuperH = 42, // Hitachi SH
        SPARCv9 = 43, // SPARC V9
        TriCore = 44, // Siemens TriCore
        ARC = 45, // Argonaut RISC Core
        H8300 = 46, // Hitachi H8/300
        H8300H = 47, // Hitachi H8/300H
        H8S = 48, // Hitachi H8S
        H8500 = 49, // Hitachi H8/500
        IA64 = 50, // Intel IA-64 processor architecture
        MIPSX = 51, // Stanford MIPS-X
        ColdFire = 52, // Motorola ColdFire
        M68HC12 = 53, // Motorola M68HC12
        MMA = 54, // Fujitsu MMA Multimedia Accelerator
        PCP = 55, // Siemens PCP
        NCPU = 56, // Sony nCPU embedded RISC processor
        NDR1 = 57, // Denso NDR1 microprocessor
        StarCore = 58, // Motorola Star*Core processor
        ME16 = 59, // Toyota ME16 processor
        ST100 = 60, // STMicroelectronics ST100 processor
        TinyJ = 61, // Advanced Logic Corp. TinyJ embedded processor family
        AMD64 = 62, // AMD x86-64 architecture
        PDSP = 63, // Sony DSP Processor
        PDP10 = 64, // Digital Equipment Corp. PDP-10
        PDP11 = 65, // Digital Equipment Corp. PDP-11
        FX66 = 66, // Siemens FX66 microcontroller
        ST9PLUS = 67, // STMicroelectronics ST9+ 8/16 bit microcontroller
        ST7 = 68, // STMicroelectronics ST7 8-bit microcontroller
        M68HC16 = 69, // Motorola MC68HC16 Microcontroller
        M68HC11 = 70, // Motorola MC68HC11 Microcontroller
        M68HC08 = 71, // Motorola MC68HC08 Microcontroller
        M68HC05 = 72, // Motorola MC68HC05 Microcontroller
        SVX = 73, // Silicon Graphics SVx
        ST19 = 74, // STMicroelectronics ST19 8-bit microcontroller
        VAX = 75, // Digital VAX
        CRIS = 76, // Axis Communications 32-bit embedded processor
        Javelin = 77, // Infineon Technologies 32-bit embedded processor
        FirePath = 78, // Element 14 64-bit DSP Processor
        ZSP = 79, // LSI Logic 16-bit DSP Processor
        MMIX = 80, // Donald Knuth's educational 64-bit processor
        HUANY = 81, // Harvard University machine-independent object files
        PRISM = 82, // SiTera Prism
        AVR = 83, // Atmel AVR 8-bit microcontroller
        FR30 = 84, // Fujitsu FR30
        D10V = 85, // Mitsubishi D10V
        D30V = 86, // Mitsubishi D30V
        V850 = 87, // NEC v850
        M32R = 88, // Mitsubishi M32R
        MN10300 = 89, // Matsushita MN10300
        MN10200 = 90, // Matsushita MN10200
        PicoJava = 91, // picoJava
        OpenRISC = 92, // OpenRISC 32-bit embedded processor
        ARCompact = 93, // ARC International ARCompact processo
        Xtensa = 94, // Tensilica Xtensa Architecture
        VideoCore = 95, // Alphamosaic VideoCore processor
        TMMGPP = 96, // Thompson Multimedia General Purpose Processor
        NS32K = 97, // National Semiconductor 32000 series
        TPC = 98, // Tenor Network TPC processor
        SNP1k = 99, // Trebia SNP 1000 processor
        ST200 = 100, // STMicroelectronics (www.st.com) ST200
        IP2K = 101, // Ubicom IP2xxx microcontroller family
        MAX = 102, // MAX Processor
        CompactRISC = 103, // National Semiconductor CompactRISC microprocessor
        F2MC16 = 104, // Fujitsu F2MC16
        MSP430 = 105, // Texas Instruments embedded microcontroller msp430
        Blackfin = 106, // Analog Devices Blackfin (DSP) processor
        S1C33 = 107, // S1C33 Family of Seiko Epson processors
        SEP = 108, // Sharp embedded microprocessor
        ArcaRISC = 109, // Arca RISC Microprocessor
        UNICORE = 110, // Microprocessor series from PKU-Unity Ltd. and MPRC of Peking University
        Excess = 111, // eXcess: 16/32/64-bit configurable embedded CPU
        DXP = 112, // Icera Semiconductor Inc. Deep Execution Processor
        AlteraNios2 = 113, // Altera Nios II soft-core processor
        CRX = 114, // National Semiconductor CompactRISC CRX
        XGATE = 115, // Motorola XGATE embedded processor
        C166 = 116, // Infineon C16x/XC16x processor
        M16C = 117, // Renesas M16C series microprocessors
        DSPIC30F = 118, // Microchip Technology dsPIC30F Digital Signal
                        // Controller
        EngineRISC = 119, // Freescale Communication Engine RISC core
        M32C = 120, // Renesas M32C series microprocessors
        TSK3000 = 131, // Altium TSK3000 core
        RS08 = 132, // Freescale RS08 embedded processor
        SHARC = 133, // Analog Devices SHARC family of 32-bit DSP processors
        ECOG2 = 134, // Cyan Technology eCOG2 microprocessor
        Score7 = 135, // Sunplus S+core7 RISC processor
        DSP24 = 136, // New Japan Radio (NJR) 24-bit DSP Processor
        VideoCore3 = 137, // Broadcom VideoCore III processor
        LatticeMico32 = 138, // RISC processor for Lattice FPGA architecture
        SeikoEpsonC17 = 139, // Seiko Epson C17 family
        TIC6000 = 140, // The Texas Instruments TMS320C6000 DSP family
        TIC2000 = 141, // The Texas Instruments TMS320C2000 DSP family
        TIC5500 = 142, // The Texas Instruments TMS320C55x DSP family
        MMDSPPlus = 160, // STMicroelectronics 64bit VLIW Data Signal Processor
        CypressM8C = 161, // Cypress M8C microprocessor
        R32C = 162, // Renesas R32C series microprocessors
        TriMedia = 163, // NXP Semiconductors TriMedia architecture family
        Hexagon = 164, // Qualcomm Hexagon processor
        Intel8051 = 165, // Intel 8051 and variants
        STxP7x = 166, // STMicroelectronics STxP7x family of configurable and extensible RISC processors
        NDS32 = 167, // Andes Technology compact code size embedded RISC processor family
        ECOG1 = 168, // Cyan Technology eCOG1X family
        ECOG1X = 168, // Cyan Technology eCOG1X family
        MAXQ30 = 169, // Dallas Semiconductor MAXQ30 Core Micro-controllers
        XIMO16 = 170, // New Japan Radio (NJR) 16-bit DSP Processor
        MANIK = 171, // M2000 Reconfigurable RISC Microprocessor
        CrayNV2 = 172, // Cray Inc. NV2 vector architecture
        RX = 173, // Renesas RX family
        METAG = 174, // Imagination Technologies META processor architecture
        MCSTElbrus = 175, // MCST Elbrus general purpose hardware architecture
        ECOG16 = 176, // Cyan Technology eCOG16 family
        CR16 = 177, // National Semiconductor CompactRISC CR16 16-bit microprocessor
        ETPU = 178, // Freescale Extended Time Processing Unit
        SLE9X = 179, // Infineon Technologies SLE9X core
        L10M = 180, // Intel L10M
        K10M = 181, // Intel K10M
        AArch64 = 183, // ARM AArch64
        AVR32 = 185, // Atmel Corporation 32-bit microprocessor family
        STM8 = 186, // STMicroeletronics STM8 8-bit microcontroller
        TILE64 = 187, // Tilera TILE64 multicore architecture family
        TILEPro = 188, // Tilera TILEPro multicore architecture family
        CUDA = 190, // NVIDIA CUDA architecture
        TILEGx = 191, // Tilera TILE-Gx multicore architecture family
        CloudShield = 192, // CloudShield architecture family
        CoreA1st = 193, // KIPO-KAIST Core-A 1st generation processor family
        CoreA2nd = 194, // KIPO-KAIST Core-A 2nd generation processor family
        ARCompact2 = 195, // Synopsys ARCompact V2
        Open8 = 196, // Open8 8-bit RISC soft processor core
        RL78 = 197, // Renesas RL78 family
        VideoCore5 = 198, // Broadcom VideoCore V processor
        R78KOR = 199, // Renesas 78KOR family
        F56800EX = 200 // Freescale 56800EX Digital Signal Controller (DSC)
    };

    enum class COZY_API SegmentFlags : Elf32_Word
    {
        Execute = 1,
        Write = 2,
        Read = 4
    };

    enum class ProgramHeaderType : Elf32_Word
    {
        PT_LOAD = 1,
        PT_DYNAMIC = 2,
        PT_INTERP = 3,
        PT_NOTE = 4,
        PT_SHLIB = 5,
        PT_PHDR = 6,
        PT_LOPROC = 0x70000000,
        PT_HIPROC = 0x7fffffff,
        PT_MIPS_REGINFO = 0x70000000,
        PT_MIPS_OPTIONS = 0x70000001,
    };

    enum class SectionFlags : Elf32_Word
    {
        Writable = 1,
        Allocatable = 2,
        Executable = 4
    };

    enum SectionType : Elf32_Word
    {
        Null = 0,
        ProgBits,
        SymbolTable,
        StringTable,
        RelocationAddends,
        HashTable,
        Dynamic,
        Note,
        NoBits,
        Relocation,
        Shlib,
        DynamicSymbolTable,
    };
}

#endif // __COZY_ELF_ENUM__

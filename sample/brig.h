/* Copyright 2014 HSA Foundation Inc.  All Rights Reserved.
 *
 * HSAF is granting you permission to use this software and documentation (if
 * any) (collectively, the "Materials") pursuant to the terms and conditions
 * of the Software License Agreement included with the Materials.  If you do
 * not have a copy of the Software License Agreement, contact the  HSA Foundation for a copy.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE SOFTWARE.
 */

#pragma once

#include <stdint.h>

typedef uint32_t BrigVersion32_t;

enum BrigVersion { 
    BRIG_VERSION_HSAIL_MAJOR = 0,
    BRIG_VERSION_HSAIL_MINOR = 20140528,
    BRIG_VERSION_BRIG_MAJOR = 0,
    BRIG_VERSION_BRIG_MINOR = 20140528
};

typedef uint8_t BrigAlignment8_t; 

typedef uint8_t BrigAllocation8_t; 

typedef uint16_t BrigAluModifier16_t;

typedef uint8_t BrigAtomicOperation8_t;

typedef uint32_t BrigCodeOffset32_t; 

typedef uint8_t BrigCompareOperation8_t;

typedef uint16_t BrigControlDirective16_t;

typedef uint32_t BrigDataOffset32_t; 

typedef BrigDataOffset32_t BrigDataOffsetCodeList32_t; 

typedef BrigDataOffset32_t BrigDataOffsetOperandList32_t; 

typedef BrigDataOffset32_t BrigDataOffsetString32_t; 

typedef uint8_t BrigExecutableModifier8_t;

typedef uint8_t BrigImageChannelOrder8_t; 

typedef uint8_t BrigImageChannelType8_t; 

typedef uint8_t BrigImageGeometry8_t; 

typedef uint8_t BrigImageQuery8_t;

typedef uint16_t BrigKinds16_t;

typedef uint8_t BrigLinkage8_t; 

typedef uint8_t BrigMachineModel8_t; 

typedef uint8_t BrigMemoryModifier8_t;

typedef uint8_t BrigMemoryOrder8_t; 

typedef uint8_t BrigMemoryScope8_t; 

typedef uint16_t BrigOpcode16_t;

typedef uint32_t BrigOperandOffset32_t; 

typedef uint8_t BrigPack8_t; 

typedef uint8_t BrigProfile8_t; 

typedef uint16_t BrigRegisterKind16_t;

typedef uint8_t BrigRound8_t;

typedef uint8_t BrigSamplerAddressing8_t; 

typedef uint8_t BrigSamplerCoordNormalization8_t;

typedef uint8_t BrigSamplerFilter8_t;

typedef uint8_t BrigSamplerQuery8_t;

typedef uint32_t BrigSectionIndex32_t;

typedef uint8_t BrigSegCvtModifier8_t;

typedef uint8_t BrigSegment8_t; 

typedef uint32_t BrigStringOffset32_t; 

typedef uint16_t BrigType16_t;

typedef uint8_t BrigVariableModifier8_t;

typedef uint8_t BrigWidth8_t;

enum BrigKinds {
    BRIG_KIND_NONE = 0x0000, 
    BRIG_KIND_DIRECTIVE_BEGIN = 0x1000, 
    BRIG_KIND_DIRECTIVE_ARG_BLOCK_END = 0x1000, 
    BRIG_KIND_DIRECTIVE_ARG_BLOCK_START = 0x1001, 
    BRIG_KIND_DIRECTIVE_COMMENT = 0x1002,
    BRIG_KIND_DIRECTIVE_CONTROL = 0x1003, 
    BRIG_KIND_DIRECTIVE_EXTENSION = 0x1004, 
    BRIG_KIND_DIRECTIVE_FBARRIER = 0x1005,
    BRIG_KIND_DIRECTIVE_FUNCTION = 0x1006, 
    BRIG_KIND_DIRECTIVE_INDIRECT_FUNCTION = 0x1007, 
    BRIG_KIND_DIRECTIVE_KERNEL = 0x1008, 
    BRIG_KIND_DIRECTIVE_LABEL = 0x1009, 
    BRIG_KIND_DIRECTIVE_LOC = 0x100a,
    BRIG_KIND_DIRECTIVE_PRAGMA = 0x100b,
    BRIG_KIND_DIRECTIVE_SIGNATURE = 0x100c, 
    BRIG_KIND_DIRECTIVE_VARIABLE = 0x100d,
    BRIG_KIND_DIRECTIVE_VERSION = 0x100e, 
    BRIG_KIND_DIRECTIVE_END = 0x100f, 

    BRIG_KIND_INST_BEGIN = 0x2000, 
    BRIG_KIND_INST_ADDR = 0x2000,
    BRIG_KIND_INST_ATOMIC = 0x2001,
    BRIG_KIND_INST_BASIC = 0x2002,
    BRIG_KIND_INST_BR = 0x2003,
    BRIG_KIND_INST_CMP = 0x2004,
    BRIG_KIND_INST_CVT = 0x2005,
    BRIG_KIND_INST_IMAGE = 0x2006,
    BRIG_KIND_INST_LANE = 0x2007,
    BRIG_KIND_INST_MEM = 0x2008,
    BRIG_KIND_INST_MEM_FENCE = 0x2009,
    BRIG_KIND_INST_MOD = 0x200a,
    BRIG_KIND_INST_QUERY_IMAGE = 0x200b,
    BRIG_KIND_INST_QUERY_SAMPLER = 0x200c,
    BRIG_KIND_INST_QUEUE = 0x200d,
    BRIG_KIND_INST_SEG = 0x200e,
    BRIG_KIND_INST_SEG_CVT = 0x200f,
    BRIG_KIND_INST_SIGNAL = 0x2010,
    BRIG_KIND_INST_SOURCE_TYPE = 0x2011,
    BRIG_KIND_INST_END = 0x2012, 

    BRIG_KIND_OPERAND_BEGIN = 0x3000, 
    BRIG_KIND_OPERAND_ADDRESS = 0x3000,
    BRIG_KIND_OPERAND_DATA = 0x3001,
    BRIG_KIND_OPERAND_CODE_LIST = 0x3002,
    BRIG_KIND_OPERAND_CODE_REF = 0x3003,
    BRIG_KIND_OPERAND_IMAGE_PROPERTIES = 0x3004,
    BRIG_KIND_OPERAND_OPERAND_LIST = 0x3005,
    BRIG_KIND_OPERAND_REG = 0x3006,
    BRIG_KIND_OPERAND_SAMPLER_PROPERTIES = 0x3007,
    BRIG_KIND_OPERAND_STRING = 0x3008,
    BRIG_KIND_OPERAND_WAVESIZE = 0x3009,
    BRIG_KIND_OPERAND_END = 0x300a 
};

enum BrigAlignment {
    BRIG_ALIGNMENT_NONE = 0, 
    BRIG_ALIGNMENT_1 = 1,  
    BRIG_ALIGNMENT_2 = 2,
    BRIG_ALIGNMENT_4 = 3,
    BRIG_ALIGNMENT_8 = 4,
    BRIG_ALIGNMENT_16 = 5,
    BRIG_ALIGNMENT_32 = 6,
    BRIG_ALIGNMENT_64 = 7,
    BRIG_ALIGNMENT_128 = 8,
    BRIG_ALIGNMENT_256 = 9,
    BRIG_ALIGNMENT_LAST, 
    BRIG_ALIGNMENT_MAX = BRIG_ALIGNMENT_LAST - 1 
};

enum BrigAllocation {
    BRIG_ALLOCATION_NONE = 0, 
    BRIG_ALLOCATION_PROGRAM = 1,
    BRIG_ALLOCATION_AGENT = 2,
    BRIG_ALLOCATION_AUTOMATIC = 3
};

enum BrigAluModifierMask {
    BRIG_ALU_ROUND = 31,
    BRIG_ALU_FTZ = 32
};

enum BrigAtomicOperation { 
    BRIG_ATOMIC_ADD = 0,
    BRIG_ATOMIC_AND = 1,
    BRIG_ATOMIC_CAS = 2,
    BRIG_ATOMIC_EXCH = 3,
    BRIG_ATOMIC_LD = 4,
    BRIG_ATOMIC_MAX = 5,
    BRIG_ATOMIC_MIN = 6,
    BRIG_ATOMIC_OR = 7,
    BRIG_ATOMIC_ST = 8,
    BRIG_ATOMIC_SUB = 9,
    BRIG_ATOMIC_WRAPDEC = 10,
    BRIG_ATOMIC_WRAPINC = 11,
    BRIG_ATOMIC_XOR = 12,
    BRIG_ATOMIC_WAIT_EQ = 13,
    BRIG_ATOMIC_WAIT_NE = 14,
    BRIG_ATOMIC_WAIT_LT = 15,
    BRIG_ATOMIC_WAIT_GTE = 16,
    BRIG_ATOMIC_WAITTIMEOUT_EQ = 17,
    BRIG_ATOMIC_WAITTIMEOUT_NE = 18,
    BRIG_ATOMIC_WAITTIMEOUT_LT = 19,
    BRIG_ATOMIC_WAITTIMEOUT_GTE = 20
};

enum BrigCompareOperation { 
    BRIG_COMPARE_EQ = 0,
    BRIG_COMPARE_NE = 1,
    BRIG_COMPARE_LT = 2,
    BRIG_COMPARE_LE = 3,
    BRIG_COMPARE_GT = 4,
    BRIG_COMPARE_GE = 5,
    BRIG_COMPARE_EQU = 6,
    BRIG_COMPARE_NEU = 7,
    BRIG_COMPARE_LTU = 8,
    BRIG_COMPARE_LEU = 9,
    BRIG_COMPARE_GTU = 10,
    BRIG_COMPARE_GEU = 11,
    BRIG_COMPARE_NUM = 12,
    BRIG_COMPARE_NAN = 13,
    BRIG_COMPARE_SEQ = 14,
    BRIG_COMPARE_SNE = 15,
    BRIG_COMPARE_SLT = 16,
    BRIG_COMPARE_SLE = 17,
    BRIG_COMPARE_SGT = 18,
    BRIG_COMPARE_SGE = 19,
    BRIG_COMPARE_SGEU = 20,
    BRIG_COMPARE_SEQU = 21,
    BRIG_COMPARE_SNEU = 22,
    BRIG_COMPARE_SLTU = 23,
    BRIG_COMPARE_SLEU = 24,
    BRIG_COMPARE_SNUM = 25,
    BRIG_COMPARE_SNAN = 26,
    BRIG_COMPARE_SGTU = 27
};

enum BrigControlDirective {
    BRIG_CONTROL_NONE = 0, 
    BRIG_CONTROL_ENABLEBREAKEXCEPTIONS = 1,
    BRIG_CONTROL_ENABLEDETECTEXCEPTIONS = 2,
    BRIG_CONTROL_MAXDYNAMICGROUPSIZE = 3,
    BRIG_CONTROL_MAXFLATGRIDSIZE = 4,
    BRIG_CONTROL_MAXFLATWORKGROUPSIZE = 5,
    BRIG_CONTROL_REQUESTEDWORKGROUPSPERCU = 6,
    BRIG_CONTROL_REQUIREDDIM = 7,
    BRIG_CONTROL_REQUIREDGRIDSIZE = 8,
    BRIG_CONTROL_REQUIREDWORKGROUPSIZE = 9,
    BRIG_CONTROL_REQUIRENOPARTIALWORKGROUPS = 10
};

enum BrigExecutableModifierMask {
    BRIG_EXECUTABLE_DEFINITION = 1
};

enum BrigImageChannelOrder {
    BRIG_CHANNEL_ORDER_A = 0,
    BRIG_CHANNEL_ORDER_R = 1,
    BRIG_CHANNEL_ORDER_RX = 2,
    BRIG_CHANNEL_ORDER_RG = 3,
    BRIG_CHANNEL_ORDER_RGX = 4,
    BRIG_CHANNEL_ORDER_RA = 5,
    BRIG_CHANNEL_ORDER_RGB = 6,
    BRIG_CHANNEL_ORDER_RGBX = 7,
    BRIG_CHANNEL_ORDER_RGBA = 8,
    BRIG_CHANNEL_ORDER_BGRA = 9,
    BRIG_CHANNEL_ORDER_ARGB = 10,
    BRIG_CHANNEL_ORDER_ABGR = 11,
    BRIG_CHANNEL_ORDER_SRGB = 12,
    BRIG_CHANNEL_ORDER_SRGBX = 13,
    BRIG_CHANNEL_ORDER_SRGBA = 14,
    BRIG_CHANNEL_ORDER_SBGRA = 15,
    BRIG_CHANNEL_ORDER_INTENSITY = 16,
    BRIG_CHANNEL_ORDER_LUMINANCE = 17,
    BRIG_CHANNEL_ORDER_DEPTH = 18,
    BRIG_CHANNEL_ORDER_DEPTH_STENCIL = 19,
    BRIG_CHANNEL_ORDER_UNKNOWN 
};

enum BrigImageChannelType {
    BRIG_CHANNEL_TYPE_SNORM_INT8 = 0,
    BRIG_CHANNEL_TYPE_SNORM_INT16 = 1,
    BRIG_CHANNEL_TYPE_UNORM_INT8 = 2,
    BRIG_CHANNEL_TYPE_UNORM_INT16 = 3,
    BRIG_CHANNEL_TYPE_UNORM_INT24 = 4,
    BRIG_CHANNEL_TYPE_UNORM_SHORT_555 = 5,
    BRIG_CHANNEL_TYPE_UNORM_SHORT_565 = 6,
    BRIG_CHANNEL_TYPE_UNORM_INT_101010 = 7,
    BRIG_CHANNEL_TYPE_SIGNED_INT8 = 8,
    BRIG_CHANNEL_TYPE_SIGNED_INT16 = 9,
    BRIG_CHANNEL_TYPE_SIGNED_INT32 = 10,
    BRIG_CHANNEL_TYPE_UNSIGNED_INT8 = 11,
    BRIG_CHANNEL_TYPE_UNSIGNED_INT16 = 12,
    BRIG_CHANNEL_TYPE_UNSIGNED_INT32 = 13,
    BRIG_CHANNEL_TYPE_HALF_FLOAT = 14,
    BRIG_CHANNEL_TYPE_FLOAT = 15,
    BRIG_CHANNEL_TYPE_UNKNOWN 
};

enum BrigImageGeometry { 
    BRIG_GEOMETRY_1D = 0,
    BRIG_GEOMETRY_2D = 1,
    BRIG_GEOMETRY_3D = 2,
    BRIG_GEOMETRY_1DA = 3,
    BRIG_GEOMETRY_2DA = 4,
    BRIG_GEOMETRY_1DB = 5,
    BRIG_GEOMETRY_2DDEPTH = 6,
    BRIG_GEOMETRY_2DADEPTH = 7,
    BRIG_GEOMETRY_UNKNOWN 
};

enum BrigImageQuery {
    BRIG_IMAGE_QUERY_WIDTH = 0,
    BRIG_IMAGE_QUERY_HEIGHT = 1,
    BRIG_IMAGE_QUERY_DEPTH = 2,
    BRIG_IMAGE_QUERY_ARRAY = 3,
    BRIG_IMAGE_QUERY_CHANNELORDER = 4,
    BRIG_IMAGE_QUERY_CHANNELTYPE = 5
};

enum BrigLinkage {
    BRIG_LINKAGE_NONE = 0,
    BRIG_LINKAGE_PROGRAM = 1,
    BRIG_LINKAGE_MODULE = 2,
    BRIG_LINKAGE_FUNCTION = 3,
    BRIG_LINKAGE_ARG = 4
};

enum BrigMachineModel {
    BRIG_MACHINE_SMALL = 0, 
    BRIG_MACHINE_LARGE = 1, 
    BRIG_MACHINE_UNDEF = 2 
};

enum BrigMemoryModifierMask {
    BRIG_MEMORY_CONST = 1
};

enum BrigMemoryOrder {
    BRIG_MEMORY_ORDER_NONE = 0, 
    BRIG_MEMORY_ORDER_RELAXED = 1, 
    BRIG_MEMORY_ORDER_SC_ACQUIRE = 2, 
    BRIG_MEMORY_ORDER_SC_RELEASE = 3, 
    BRIG_MEMORY_ORDER_SC_ACQUIRE_RELEASE = 4 
};

enum BrigMemoryScope {
    BRIG_MEMORY_SCOPE_NONE = 0, 
    BRIG_MEMORY_SCOPE_WORKITEM = 1, 
    BRIG_MEMORY_SCOPE_WAVEFRONT = 2, 
    BRIG_MEMORY_SCOPE_WORKGROUP = 3, 
    BRIG_MEMORY_SCOPE_COMPONENT = 4, 
    BRIG_MEMORY_SCOPE_SYSTEM = 5 
};

enum BrigMemoryScope2 { 
    BRIG_MEMORY_SCOPE2_NONE = 0, 
    BRIG_MEMORY_SCOPE2_WORKITEM = 1, 
    BRIG_MEMORY_SCOPE2_WAVEFRONT = 2, 
    BRIG_MEMORY_SCOPE2_WORKGROUP = 3, 
    BRIG_MEMORY_SCOPE2_COMPONENT = 4, 
    BRIG_MEMORY_SCOPE2_SYSTEM = 5 
};

enum BrigOpcode { 
    BRIG_OPCODE_NOP = 0, 
    BRIG_OPCODE_ABS = 1, 
    BRIG_OPCODE_ADD = 2, 
    BRIG_OPCODE_BORROW = 3, 
    BRIG_OPCODE_CARRY = 4, 
    BRIG_OPCODE_CEIL = 5, 
    BRIG_OPCODE_COPYSIGN = 6, 
    BRIG_OPCODE_DIV = 7, 
    BRIG_OPCODE_FLOOR = 8, 
    BRIG_OPCODE_FMA = 9, 
    BRIG_OPCODE_FRACT = 10, 
    BRIG_OPCODE_MAD = 11, 
    BRIG_OPCODE_MAX = 12, 
    BRIG_OPCODE_MIN = 13, 
    BRIG_OPCODE_MUL = 14, 
    BRIG_OPCODE_MULHI = 15, 
    BRIG_OPCODE_NEG = 16, 
    BRIG_OPCODE_REM = 17, 
    BRIG_OPCODE_RINT = 18, 
    BRIG_OPCODE_SQRT = 19, 
    BRIG_OPCODE_SUB = 20, 
    BRIG_OPCODE_TRUNC = 21, 
    BRIG_OPCODE_MAD24 = 22, 
    BRIG_OPCODE_MAD24HI = 23, 
    BRIG_OPCODE_MUL24 = 24, 
    BRIG_OPCODE_MUL24HI = 25, 
    BRIG_OPCODE_SHL = 26, 
    BRIG_OPCODE_SHR = 27, 
    BRIG_OPCODE_AND = 28, 
    BRIG_OPCODE_NOT = 29, 
    BRIG_OPCODE_OR = 30, 
    BRIG_OPCODE_POPCOUNT = 31, 
    BRIG_OPCODE_XOR = 32, 
    BRIG_OPCODE_BITEXTRACT = 33, 
    BRIG_OPCODE_BITINSERT = 34, 
    BRIG_OPCODE_BITMASK = 35, 
    BRIG_OPCODE_BITREV = 36, 
    BRIG_OPCODE_BITSELECT = 37, 
    BRIG_OPCODE_FIRSTBIT = 38, 
    BRIG_OPCODE_LASTBIT = 39, 
    BRIG_OPCODE_COMBINE = 40, 
    BRIG_OPCODE_EXPAND = 41, 
    BRIG_OPCODE_LDA = 42, 
    BRIG_OPCODE_MOV = 43, 
    BRIG_OPCODE_SHUFFLE = 44, 
    BRIG_OPCODE_UNPACKHI = 45, 
    BRIG_OPCODE_UNPACKLO = 46, 
    BRIG_OPCODE_PACK = 47, 
    BRIG_OPCODE_UNPACK = 48, 
    BRIG_OPCODE_CMOV = 49, 
    BRIG_OPCODE_CLASS = 50, 
    BRIG_OPCODE_NCOS = 51, 
    BRIG_OPCODE_NEXP2 = 52, 
    BRIG_OPCODE_NFMA = 53, 
    BRIG_OPCODE_NLOG2 = 54, 
    BRIG_OPCODE_NRCP = 55, 
    BRIG_OPCODE_NRSQRT = 56, 
    BRIG_OPCODE_NSIN = 57, 
    BRIG_OPCODE_NSQRT = 58, 
    BRIG_OPCODE_BITALIGN = 59, 
    BRIG_OPCODE_BYTEALIGN = 60, 
    BRIG_OPCODE_PACKCVT = 61, 
    BRIG_OPCODE_UNPACKCVT = 62, 
    BRIG_OPCODE_LERP = 63, 
    BRIG_OPCODE_SAD = 64, 
    BRIG_OPCODE_SADHI = 65, 
    BRIG_OPCODE_SEGMENTP = 66, 
    BRIG_OPCODE_FTOS = 67, 
    BRIG_OPCODE_STOF = 68, 
    BRIG_OPCODE_CMP = 69, 
    BRIG_OPCODE_CVT = 70, 
    BRIG_OPCODE_LD = 71, 
    BRIG_OPCODE_ST = 72, 
    BRIG_OPCODE_ATOMIC = 73, 
    BRIG_OPCODE_ATOMICNORET = 74, 
    BRIG_OPCODE_SIGNAL = 75, 
    BRIG_OPCODE_SIGNALNORET = 76, 
    BRIG_OPCODE_MEMFENCE = 77, 
    BRIG_OPCODE_RDIMAGE = 78, 
    BRIG_OPCODE_LDIMAGE = 79, 
    BRIG_OPCODE_STIMAGE = 80, 
    BRIG_OPCODE_QUERYIMAGE = 81, 
    BRIG_OPCODE_QUERYSAMPLER = 82, 
    BRIG_OPCODE_CBR = 83, 
    BRIG_OPCODE_BR = 84, 
    BRIG_OPCODE_SBR = 85,    
    BRIG_OPCODE_BARRIER = 86, 
    BRIG_OPCODE_WAVEBARRIER = 87, 
    BRIG_OPCODE_ARRIVEFBAR = 88, 
    BRIG_OPCODE_INITFBAR = 89, 
    BRIG_OPCODE_JOINFBAR = 90, 
    BRIG_OPCODE_LEAVEFBAR = 91, 
    BRIG_OPCODE_RELEASEFBAR = 92, 
    BRIG_OPCODE_WAITFBAR = 93, 
    BRIG_OPCODE_LDF = 94,
    BRIG_OPCODE_ACTIVELANECOUNT = 95, 
    BRIG_OPCODE_ACTIVELANEID = 96, 
    BRIG_OPCODE_ACTIVELANEMASK = 97, 
    BRIG_OPCODE_ACTIVELANESHUFFLE = 98, 
    BRIG_OPCODE_CALL = 99, 
    BRIG_OPCODE_SCALL = 100,  
    BRIG_OPCODE_ICALL = 101, 
    BRIG_OPCODE_LDI = 102,
    BRIG_OPCODE_RET = 103, 
    BRIG_OPCODE_ALLOCA = 104, 
    BRIG_OPCODE_CURRENTWORKGROUPSIZE = 105,
    BRIG_OPCODE_DIM = 106,
    BRIG_OPCODE_GRIDGROUPS = 107,
    BRIG_OPCODE_GRIDSIZE = 108,
    BRIG_OPCODE_PACKETCOMPLETIONSIG = 109,
    BRIG_OPCODE_PACKETID = 110,
    BRIG_OPCODE_WORKGROUPID = 111,
    BRIG_OPCODE_WORKGROUPSIZE = 112,
    BRIG_OPCODE_WORKITEMABSID = 113,
    BRIG_OPCODE_WORKITEMFLATABSID = 114,
    BRIG_OPCODE_WORKITEMFLATID = 115,
    BRIG_OPCODE_WORKITEMID = 116,
    BRIG_OPCODE_CLEARDETECTEXCEPT = 117,  
    BRIG_OPCODE_GETDETECTEXCEPT = 118,
    BRIG_OPCODE_SETDETECTEXCEPT = 119,  
    BRIG_OPCODE_ADDQUEUEWRITEINDEX = 120, 
    BRIG_OPCODE_AGENTCOUNT = 121,
    BRIG_OPCODE_AGENTID = 122,
    BRIG_OPCODE_CASQUEUEWRITEINDEX = 123, 
    BRIG_OPCODE_LDK = 124,
    BRIG_OPCODE_LDQUEUEREADINDEX = 125, 
    BRIG_OPCODE_LDQUEUEWRITEINDEX = 126, 
    BRIG_OPCODE_QUEUEID = 127,
    BRIG_OPCODE_QUEUEPTR = 128,
    BRIG_OPCODE_STQUEUEREADINDEX = 129, 
    BRIG_OPCODE_STQUEUEWRITEINDEX = 130, 
    BRIG_OPCODE_CLOCK = 131,
    BRIG_OPCODE_CUID = 132,
    BRIG_OPCODE_DEBUGTRAP = 133,  
    BRIG_OPCODE_GROUPBASEPTR = 134,
    BRIG_OPCODE_KERNARGBASEPTR = 135,
    BRIG_OPCODE_LANEID = 136,
    BRIG_OPCODE_MAXCUID = 137,
    BRIG_OPCODE_MAXWAVEID = 138,
    BRIG_OPCODE_NULLPTR = 139, 
    BRIG_OPCODE_WAVEID = 140,

    BRIG_OPCODE_GCNMADU = (1u << 15) | 0, 
    BRIG_OPCODE_GCNMADS = (1u << 15) | 1, 
    BRIG_OPCODE_GCNMAX3 = (1u << 15) | 2, 
    BRIG_OPCODE_GCNMIN3 = (1u << 15) | 3, 
    BRIG_OPCODE_GCNMED3 = (1u << 15) | 4, 
    BRIG_OPCODE_GCNFLDEXP = (1u << 15) | 5, 
    BRIG_OPCODE_GCNFREXP_EXP = (1u << 15) | 6, 
    BRIG_OPCODE_GCNFREXP_MANT = (1u << 15) | 7, 
    BRIG_OPCODE_GCNTRIG_PREOP = (1u << 15) | 8, 
    BRIG_OPCODE_GCNBFM = (1u << 15) | 9, 
    BRIG_OPCODE_GCNLD = (1u << 15) | 10, 
    BRIG_OPCODE_GCNST = (1u << 15) | 11, 
    BRIG_OPCODE_GCNATOMIC = (1u << 15) | 12, 
    BRIG_OPCODE_GCNATOMICNORET = (1u << 15) | 13, 
    BRIG_OPCODE_GCNSLEEP = (1u << 15) | 14, 
    BRIG_OPCODE_GCNPRIORITY = (1u << 15) | 15, 
    BRIG_OPCODE_GCNREGIONALLOC = (1u << 15) | 16, 
    BRIG_OPCODE_GCNMSAD = (1u << 15) | 17, 
    BRIG_OPCODE_GCNQSAD = (1u << 15) | 18, 
    BRIG_OPCODE_GCNMQSAD = (1u << 15) | 19, 
    BRIG_OPCODE_GCNMQSAD4 = (1u << 15) | 20, 
    BRIG_OPCODE_GCNSADW = (1u << 15) | 21, 
    BRIG_OPCODE_GCNSADD = (1u << 15) | 22, 
    BRIG_OPCODE_GCNCONSUME = (1u << 15) | 23, 
    BRIG_OPCODE_GCNAPPEND = (1u << 15) | 24, 
    BRIG_OPCODE_GCNB4XCHG = (1u << 15) | 25, 
    BRIG_OPCODE_GCNB32XCHG = (1u << 15) | 26, 
    BRIG_OPCODE_GCNMAX = (1u << 15) | 27, 
    BRIG_OPCODE_GCNMIN = (1u << 15) | 28,
};

enum BrigPack { 
    BRIG_PACK_NONE = 0, 
    BRIG_PACK_PP = 1,
    BRIG_PACK_PS = 2,
    BRIG_PACK_SP = 3,
    BRIG_PACK_SS = 4,
    BRIG_PACK_S = 5,
    BRIG_PACK_P = 6,
    BRIG_PACK_PPSAT = 7,
    BRIG_PACK_PSSAT = 8,
    BRIG_PACK_SPSAT = 9,
    BRIG_PACK_SSSAT = 10,
    BRIG_PACK_SSAT = 11,
    BRIG_PACK_PSAT = 12
};

enum BrigProfile {
    BRIG_PROFILE_BASE = 0,
    BRIG_PROFILE_FULL = 1,
    BRIG_PROFILE_UNDEF = 2 
};

enum BrigRegisterKind {
    BRIG_REGISTER_CONTROL = 0, 
    BRIG_REGISTER_SINGLE = 1,  
    BRIG_REGISTER_DOUBLE = 2,  
    BRIG_REGISTER_QUAD = 3     
};

enum BrigRound {
    BRIG_ROUND_NONE = 0,
    BRIG_ROUND_FLOAT_NEAR_EVEN = 1, 
    BRIG_ROUND_FLOAT_ZERO = 2, 
    BRIG_ROUND_FLOAT_PLUS_INFINITY = 3, 
    BRIG_ROUND_FLOAT_MINUS_INFINITY = 4, 
    BRIG_ROUND_INTEGER_NEAR_EVEN = 5, 
    BRIG_ROUND_INTEGER_ZERO = 6, 
    BRIG_ROUND_INTEGER_PLUS_INFINITY = 7, 
    BRIG_ROUND_INTEGER_MINUS_INFINITY = 8, 
    BRIG_ROUND_INTEGER_NEAR_EVEN_SAT = 9, 
    BRIG_ROUND_INTEGER_ZERO_SAT = 10, 
    BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT = 11, 
    BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT = 12, 
    BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN = 13, 
    BRIG_ROUND_INTEGER_SIGNALLING_ZERO = 14, 
    BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY = 15, 
    BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY = 16, 
    BRIG_ROUND_INTEGER_SIGNALLING_NEAR_EVEN_SAT = 17, 
    BRIG_ROUND_INTEGER_SIGNALLING_ZERO_SAT = 18, 
    BRIG_ROUND_INTEGER_SIGNALLING_PLUS_INFINITY_SAT = 19, 
    BRIG_ROUND_INTEGER_SIGNALLING_MINUS_INFINITY_SAT = 20 
};

enum BrigSamplerAddressing {
    BRIG_ADDRESSING_UNDEFINED = 0,
    BRIG_ADDRESSING_CLAMP_TO_EDGE = 1,
    BRIG_ADDRESSING_CLAMP_TO_BORDER = 2,
    BRIG_ADDRESSING_REPEAT = 3,
    BRIG_ADDRESSING_MIRRORED_REPEAT = 4
};

enum BrigSamplerCoordNormalization {
    BRIG_COORD_UNNORMALIZED = 0,
    BRIG_COORD_NORMALIZED = 1
};

enum BrigSamplerFilter {
    BRIG_FILTER_NEAREST = 0,
    BRIG_FILTER_LINEAR = 1
};

enum BrigSamplerQuery {
    BRIG_SAMPLER_QUERY_ADDRESSING = 0,
    BRIG_SAMPLER_QUERY_COORD = 1,
    BRIG_SAMPLER_QUERY_FILTER = 2
};

enum BrigSectionIndex {
    BRIG_SECTION_INDEX_DATA = 0,
    BRIG_SECTION_INDEX_CODE = 1,
    BRIG_SECTION_INDEX_OPERAND = 2,
    BRIG_SECTION_INDEX_BEGIN_IMPLEMENTATION_DEFINED = 3,
    BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED = BRIG_SECTION_INDEX_BEGIN_IMPLEMENTATION_DEFINED 
};

enum BrigSegCvtModifierMask {
    BRIG_SEG_CVT_NONULL = 1 
};

enum BrigSegment {
    BRIG_SEGMENT_NONE = 0, 
    BRIG_SEGMENT_FLAT = 1, 
    BRIG_SEGMENT_GLOBAL = 2,
    BRIG_SEGMENT_READONLY = 3,
    BRIG_SEGMENT_KERNARG = 4,
    BRIG_SEGMENT_GROUP = 5,
    BRIG_SEGMENT_PRIVATE = 6,
    BRIG_SEGMENT_SPILL = 7,
    BRIG_SEGMENT_ARG = 8,
    BRIG_SEGMENT_EXTSPACE0 = 9, 
};

enum BrigPackedTypeBits {
    BRIG_TYPE_PACK_SHIFT = 5,
    BRIG_TYPE_BASE_MASK = (1 << BRIG_TYPE_PACK_SHIFT) - 1,
    BRIG_TYPE_PACK_MASK = 3 << BRIG_TYPE_PACK_SHIFT,
    BRIG_TYPE_PACK_NONE = 0 << BRIG_TYPE_PACK_SHIFT,
    BRIG_TYPE_PACK_32 = 1 << BRIG_TYPE_PACK_SHIFT,
    BRIG_TYPE_PACK_64 = 2 << BRIG_TYPE_PACK_SHIFT,
    BRIG_TYPE_PACK_128 = 3 << BRIG_TYPE_PACK_SHIFT
};

enum BrigTypeX {
    BRIG_TYPE_NONE = 0, 
    BRIG_TYPE_U8 = 1, 
    BRIG_TYPE_U16 = 2, 
    BRIG_TYPE_U32 = 3, 
    BRIG_TYPE_U64 = 4, 
    BRIG_TYPE_S8 = 5, 
    BRIG_TYPE_S16 = 6, 
    BRIG_TYPE_S32 = 7, 
    BRIG_TYPE_S64 = 8, 
    BRIG_TYPE_F16 = 9, 
    BRIG_TYPE_F32 = 10, 
    BRIG_TYPE_F64 = 11, 
    BRIG_TYPE_B1 = 12, 
    BRIG_TYPE_B8 = 13, 
    BRIG_TYPE_B16 = 14, 
    BRIG_TYPE_B32 = 15, 
    BRIG_TYPE_B64 = 16, 
    BRIG_TYPE_B128 = 17, 
    BRIG_TYPE_SAMP = 18, 
    BRIG_TYPE_ROIMG = 19, 
    BRIG_TYPE_WOIMG = 20, 
    BRIG_TYPE_RWIMG = 21, 
    BRIG_TYPE_SIG32 = 22, 
    BRIG_TYPE_SIG64 = 23, 

    BRIG_TYPE_U8X4 = BRIG_TYPE_U8 | BRIG_TYPE_PACK_32, 
    BRIG_TYPE_U8X8 = BRIG_TYPE_U8 | BRIG_TYPE_PACK_64, 
    BRIG_TYPE_U8X16 = BRIG_TYPE_U8 | BRIG_TYPE_PACK_128, 
    BRIG_TYPE_U16X2 = BRIG_TYPE_U16 | BRIG_TYPE_PACK_32, 
    BRIG_TYPE_U16X4 = BRIG_TYPE_U16 | BRIG_TYPE_PACK_64, 
    BRIG_TYPE_U16X8 = BRIG_TYPE_U16 | BRIG_TYPE_PACK_128, 
    BRIG_TYPE_U32X2 = BRIG_TYPE_U32 | BRIG_TYPE_PACK_64, 
    BRIG_TYPE_U32X4 = BRIG_TYPE_U32 | BRIG_TYPE_PACK_128, 
    BRIG_TYPE_U64X2 = BRIG_TYPE_U64 | BRIG_TYPE_PACK_128, 
    BRIG_TYPE_S8X4 = BRIG_TYPE_S8 | BRIG_TYPE_PACK_32, 
    BRIG_TYPE_S8X8 = BRIG_TYPE_S8 | BRIG_TYPE_PACK_64, 
    BRIG_TYPE_S8X16 = BRIG_TYPE_S8 | BRIG_TYPE_PACK_128, 
    BRIG_TYPE_S16X2 = BRIG_TYPE_S16 | BRIG_TYPE_PACK_32, 
    BRIG_TYPE_S16X4 = BRIG_TYPE_S16 | BRIG_TYPE_PACK_64, 
    BRIG_TYPE_S16X8 = BRIG_TYPE_S16 | BRIG_TYPE_PACK_128, 
    BRIG_TYPE_S32X2 = BRIG_TYPE_S32 | BRIG_TYPE_PACK_64, 
    BRIG_TYPE_S32X4 = BRIG_TYPE_S32 | BRIG_TYPE_PACK_128, 
    BRIG_TYPE_S64X2 = BRIG_TYPE_S64 | BRIG_TYPE_PACK_128, 
    BRIG_TYPE_F16X2 = BRIG_TYPE_F16 | BRIG_TYPE_PACK_32, 
    BRIG_TYPE_F16X4 = BRIG_TYPE_F16 | BRIG_TYPE_PACK_64, 
    BRIG_TYPE_F16X8 = BRIG_TYPE_F16 | BRIG_TYPE_PACK_128, 
    BRIG_TYPE_F32X2 = BRIG_TYPE_F32 | BRIG_TYPE_PACK_64, 
    BRIG_TYPE_F32X4 = BRIG_TYPE_F32 | BRIG_TYPE_PACK_128, 
    BRIG_TYPE_F64X2 = BRIG_TYPE_F64 | BRIG_TYPE_PACK_128, 
    
    BRIG_TYPE_INVALID = -1 
};

enum BrigVariableModifierMask {
    BRIG_SYMBOL_DEFINITION = 1,
    BRIG_SYMBOL_CONST = 2,
    BRIG_SYMBOL_ARRAY = 4,
    BRIG_SYMBOL_FLEX_ARRAY = 8
};

enum BrigWidth {
    BRIG_WIDTH_NONE = 0,
    BRIG_WIDTH_1 = 1,
    BRIG_WIDTH_2 = 2,
    BRIG_WIDTH_4 = 3,
    BRIG_WIDTH_8 = 4,
    BRIG_WIDTH_16 = 5,
    BRIG_WIDTH_32 = 6,
    BRIG_WIDTH_64 = 7,
    BRIG_WIDTH_128 = 8,
    BRIG_WIDTH_256 = 9,
    BRIG_WIDTH_512 = 10,
    BRIG_WIDTH_1024 = 11,
    BRIG_WIDTH_2048 = 12,
    BRIG_WIDTH_4096 = 13,
    BRIG_WIDTH_8192 = 14,
    BRIG_WIDTH_16384 = 15,
    BRIG_WIDTH_32768 = 16,
    BRIG_WIDTH_65536 = 17,
    BRIG_WIDTH_131072 = 18,
    BRIG_WIDTH_262144 = 19,
    BRIG_WIDTH_524288 = 20,
    BRIG_WIDTH_1048576 = 21,
    BRIG_WIDTH_2097152 = 22,
    BRIG_WIDTH_4194304 = 23,
    BRIG_WIDTH_8388608 = 24,
    BRIG_WIDTH_16777216 = 25,
    BRIG_WIDTH_33554432 = 26,
    BRIG_WIDTH_67108864 = 27,
    BRIG_WIDTH_134217728 = 28,
    BRIG_WIDTH_268435456 = 29,
    BRIG_WIDTH_536870912 = 30,
    BRIG_WIDTH_1073741824 = 31,
    BRIG_WIDTH_2147483648 = 32,
    BRIG_WIDTH_WAVESIZE = 33,
    BRIG_WIDTH_ALL = 34
};

typedef struct BrigUInt64 BrigUInt64;
struct BrigUInt64 { 
    uint32_t lo;     
    uint32_t hi;     
};

typedef struct BrigAluModifier BrigAluModifier;
struct BrigAluModifier { 
    BrigAluModifier16_t allBits; 
};

typedef struct BrigBase BrigBase;
struct BrigBase { 
    uint16_t byteCount;
    BrigKinds16_t kind;
};

typedef struct BrigCode BrigCode;
struct BrigCode { 
    uint16_t byteCount;
    BrigKinds16_t kind;
};

typedef struct BrigData BrigData;
struct BrigData {
    uint32_t byteCount;
    uint8_t bytes[1];
};

typedef struct BrigExecutableModifier BrigExecutableModifier;
struct BrigExecutableModifier { 
    BrigExecutableModifier8_t allBits; 
};

typedef struct BrigMemoryModifier BrigMemoryModifier;
struct BrigMemoryModifier { 
    BrigMemoryModifier8_t allBits; 
};

typedef struct BrigSegCvtModifier BrigSegCvtModifier;
struct BrigSegCvtModifier { 
    BrigSegCvtModifier8_t allBits; 
};

typedef struct BrigVariableModifier BrigVariableModifier;
struct BrigVariableModifier { 
    BrigVariableModifier8_t allBits; 
};

typedef struct BrigDirective BrigDirective;
struct BrigDirective { 
    uint16_t byteCount;
    BrigKinds16_t kind;
};

typedef struct BrigDirectiveArgBlockEnd BrigDirectiveArgBlockEnd;
struct BrigDirectiveArgBlockEnd {
    uint16_t byteCount;
    BrigKinds16_t kind;
};

typedef struct BrigDirectiveArgBlockStart BrigDirectiveArgBlockStart;
struct BrigDirectiveArgBlockStart {
    uint16_t byteCount;
    BrigKinds16_t kind;
};

typedef struct BrigDirectiveComment BrigDirectiveComment;
struct BrigDirectiveComment {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t name;
};

typedef struct BrigDirectiveControl BrigDirectiveControl;
struct BrigDirectiveControl {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigControlDirective16_t control;
    uint16_t reserved; 
    BrigDataOffsetOperandList32_t operands;
};

typedef struct BrigDirectiveExecutable BrigDirectiveExecutable;
struct BrigDirectiveExecutable { 
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t name;
    uint16_t outArgCount; 
    uint16_t inArgCount;  
    BrigCodeOffset32_t firstInArg;
    BrigCodeOffset32_t firstCodeBlockEntry;
    BrigCodeOffset32_t nextModuleEntry;
    uint32_t codeBlockEntryCount;  
    BrigExecutableModifier modifier; 
    BrigLinkage8_t linkage;
    uint16_t reserved; 
};

typedef struct BrigDirectiveExtension BrigDirectiveExtension;
struct BrigDirectiveExtension {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t name;
};

typedef struct BrigDirectiveFbarrier BrigDirectiveFbarrier;
struct BrigDirectiveFbarrier {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t name;
    BrigExecutableModifier modifier; 
    BrigLinkage8_t linkage;
    uint16_t reserved; 
};

typedef struct BrigDirectiveFunction BrigDirectiveFunction;
struct BrigDirectiveFunction { 
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t name;
    uint16_t outArgCount; 
    uint16_t inArgCount;  
    BrigCodeOffset32_t firstInArg;
    BrigCodeOffset32_t firstCodeBlockEntry;
    BrigCodeOffset32_t nextModuleEntry;
    uint32_t codeBlockEntryCount; 
    BrigExecutableModifier modifier; 
    BrigLinkage8_t linkage;
    uint16_t reserved; 
};

typedef struct BrigDirectiveIndirectFunction BrigDirectiveIndirectFunction;
struct BrigDirectiveIndirectFunction { 
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t name;
    uint16_t outArgCount; 
    uint16_t inArgCount;  
    BrigCodeOffset32_t firstInArg;
    BrigCodeOffset32_t firstCodeBlockEntry;
    BrigCodeOffset32_t nextModuleEntry;
    uint32_t codeBlockEntryCount; 
    BrigExecutableModifier modifier; 
    BrigLinkage8_t linkage;
    uint16_t reserved; 
};

typedef struct BrigDirectiveKernel BrigDirectiveKernel;
struct BrigDirectiveKernel { 
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t name;
    uint16_t outArgCount; 
    uint16_t inArgCount;  
    BrigCodeOffset32_t firstInArg;
    BrigCodeOffset32_t firstCodeBlockEntry;
    BrigCodeOffset32_t nextModuleEntry;
    uint32_t codeBlockEntryCount; 
    BrigExecutableModifier modifier; 
    BrigLinkage8_t linkage;
    uint16_t reserved; 
};

typedef struct BrigDirectiveSignature BrigDirectiveSignature;
struct BrigDirectiveSignature { 
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t name;
    uint16_t outArgCount; 
    uint16_t inArgCount;  
    BrigCodeOffset32_t firstInArg;
    BrigCodeOffset32_t firstCodeBlockEntry;
    BrigCodeOffset32_t nextModuleEntry;
    uint32_t codeBlockEntryCount; 
    BrigExecutableModifier modifier; 
    BrigLinkage8_t linkage;
    uint16_t reserved; 
};

typedef struct BrigDirectiveLabel BrigDirectiveLabel;
struct BrigDirectiveLabel {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t name;
};

typedef struct BrigDirectiveLoc BrigDirectiveLoc;
struct BrigDirectiveLoc {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t filename;
    uint32_t line;
    uint32_t column; 
};

typedef struct BrigDirectiveNone BrigDirectiveNone;
struct BrigDirectiveNone { 
    uint16_t byteCount;
    BrigKinds16_t kind;
};

typedef struct BrigDirectivePragma BrigDirectivePragma;
struct BrigDirectivePragma {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetOperandList32_t operands;
};

typedef struct BrigDirectiveVariable BrigDirectiveVariable;
struct BrigDirectiveVariable {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t name;
    BrigOperandOffset32_t init;
    BrigType16_t type;
    BrigSegment8_t segment;
    BrigAlignment8_t align;
    BrigUInt64 dim; 
    BrigVariableModifier modifier; 
    BrigLinkage8_t linkage;
    BrigAllocation8_t allocation;
    uint8_t reserved; 
};

typedef struct BrigDirectiveVersion BrigDirectiveVersion;
struct BrigDirectiveVersion {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigVersion32_t hsailMajor; 
    BrigVersion32_t hsailMinor; 
    BrigVersion32_t brigMajor;  
    BrigVersion32_t brigMinor;  
    BrigProfile8_t profile;
    BrigMachineModel8_t machineModel;
    uint16_t reserved; 
};

typedef struct BrigInst BrigInst;
struct BrigInst { 
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
};

typedef struct BrigInstAddr BrigInstAddr;
struct BrigInstAddr {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigSegment8_t segment;
    uint8_t reserved[3]; 
};

typedef struct BrigInstAtomic BrigInstAtomic;
struct BrigInstAtomic {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigSegment8_t segment;
    BrigMemoryOrder8_t memoryOrder;
    BrigMemoryScope8_t memoryScope;
    BrigAtomicOperation8_t atomicOperation;
    uint8_t equivClass;
    uint8_t reserved[3]; 
};

typedef struct BrigInstBasic BrigInstBasic;
struct BrigInstBasic {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
};

typedef struct BrigInstBr BrigInstBr;
struct BrigInstBr {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigWidth8_t width;
    uint8_t reserved[3]; 
};

typedef struct BrigInstCmp BrigInstCmp;
struct BrigInstCmp {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigType16_t sourceType;
    BrigAluModifier modifier; 
    BrigCompareOperation8_t compare;
    BrigPack8_t pack;
    uint16_t reserved; 
};

typedef struct BrigInstCvt BrigInstCvt;
struct BrigInstCvt {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigType16_t sourceType;
    BrigAluModifier modifier; 
};

typedef struct BrigInstImage BrigInstImage;
struct BrigInstImage {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigType16_t imageType;
    BrigType16_t coordType;
    BrigImageGeometry8_t geometry;
    uint8_t equivClass;
    uint16_t reserved; 
};

typedef struct BrigInstLane BrigInstLane;
struct BrigInstLane {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigType16_t sourceType;
    BrigWidth8_t width;
    uint8_t reserved; 
};

typedef struct BrigInstMem BrigInstMem;
struct BrigInstMem {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigSegment8_t segment;
    BrigAlignment8_t align;
    uint8_t equivClass;
    BrigWidth8_t width;
    BrigMemoryModifier modifier; 
    uint8_t reserved[3]; 
};

typedef struct BrigInstMemFence BrigInstMemFence;
struct BrigInstMemFence {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigMemoryOrder8_t memoryOrder;
    BrigMemoryScope8_t globalSegmentMemoryScope;
    BrigMemoryScope8_t groupSegmentMemoryScope;
    BrigMemoryScope8_t imageSegmentMemoryScope;
};

typedef struct BrigInstMod BrigInstMod;
struct BrigInstMod {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigAluModifier modifier; 
    BrigPack8_t pack;
    uint8_t reserved; 
};

typedef struct BrigInstQueryImage BrigInstQueryImage;
struct BrigInstQueryImage {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigType16_t imageType;
    BrigImageGeometry8_t geometry;
    BrigImageQuery8_t imageQuery;
};

typedef struct BrigInstQuerySampler BrigInstQuerySampler;
struct BrigInstQuerySampler {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigSamplerQuery8_t samplerQuery;
    uint8_t reserved[3]; 
};

typedef struct BrigInstQueue BrigInstQueue;
struct BrigInstQueue {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigSegment8_t segment;
    BrigMemoryOrder8_t memoryOrder;
    uint16_t reserved; 
};

typedef struct BrigInstSeg BrigInstSeg;
struct BrigInstSeg {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigSegment8_t segment;
    uint8_t reserved[3]; 
};

typedef struct BrigInstSegCvt BrigInstSegCvt;
struct BrigInstSegCvt {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigType16_t sourceType;
    BrigSegment8_t segment;
    BrigSegCvtModifier modifier; 
};

typedef struct BrigInstSignal BrigInstSignal;
struct BrigInstSignal {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigType16_t signalType;
    BrigMemoryOrder8_t memoryOrder;
    BrigAtomicOperation8_t signalOperation;
};

typedef struct BrigInstSourceType BrigInstSourceType;
struct BrigInstSourceType {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigOpcode16_t opcode;
    BrigType16_t type;
    BrigDataOffsetOperandList32_t operands;
    BrigType16_t sourceType;
    uint16_t reserved; 
};

typedef struct BrigOperand BrigOperand;
struct BrigOperand { 
    uint16_t byteCount;
    BrigKinds16_t kind;
};


typedef struct BrigOperandAddress BrigOperandAddress;
struct BrigOperandAddress {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigCodeOffset32_t symbol; 
    BrigOperandOffset32_t reg; 
    BrigUInt64 offset; 
};

typedef struct BrigOperandCodeList BrigOperandCodeList;
struct BrigOperandCodeList {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetCodeList32_t elements;
};

typedef struct BrigOperandCodeRef BrigOperandCodeRef;
struct BrigOperandCodeRef {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigCodeOffset32_t ref;
};

typedef struct BrigOperandData BrigOperandData;
struct BrigOperandData {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t data; 
};

typedef struct BrigOperandImageProperties BrigOperandImageProperties;
struct BrigOperandImageProperties {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigUInt64 width;  
    BrigUInt64 height; 
    BrigUInt64 depth;  
    BrigUInt64 array;  
    BrigImageGeometry8_t geometry;
    BrigImageChannelOrder8_t channelOrder;
    BrigImageChannelType8_t channelType;
    uint8_t reserved; 
};

typedef struct BrigOperandOperandList BrigOperandOperandList;
struct BrigOperandOperandList {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetOperandList32_t elements;
};

typedef struct BrigOperandReg BrigOperandReg;
struct BrigOperandReg {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigRegisterKind16_t regKind;
    uint16_t regNum;
};

typedef struct BrigOperandSamplerProperties BrigOperandSamplerProperties;
struct BrigOperandSamplerProperties {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigSamplerCoordNormalization8_t coord;
    BrigSamplerFilter8_t filter;
    BrigSamplerAddressing8_t addressing;
    uint8_t reserved; 
};

typedef struct BrigOperandString BrigOperandString;
struct BrigOperandString {
    uint16_t byteCount;
    BrigKinds16_t kind;
    BrigDataOffsetString32_t string;
};

typedef struct BrigOperandWavesize BrigOperandWavesize;
struct BrigOperandWavesize {
    uint16_t byteCount;
    BrigKinds16_t kind;
};

typedef struct BrigSectionHeader BrigSectionHeader;
struct BrigSectionHeader {
    uint32_t byteCount;
    uint32_t headerByteCount;
    uint32_t nameLength;
    uint8_t name[1];
};

typedef struct BrigModule BrigModule;
struct BrigModule {
    uint32_t sectionCount;
    BrigSectionHeader* section[1];
};

enum BrigMemoryFenceSegments { 
    BRIG_MEMORY_FENCE_SEGMENT_GLOBAL = 0,
    BRIG_MEMORY_FENCE_SEGMENT_GROUP = 1,
    BRIG_MEMORY_FENCE_SEGMENT_IMAGE = 2,
    BRIG_MEMORY_FENCE_SEGMENT_LAST = 3 
};

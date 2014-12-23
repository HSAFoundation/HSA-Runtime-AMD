// Copyright 2014 HSA Foundation Inc.  All Rights Reserved.
//
// HSAF is granting you permission to use this software and documentation (if
// any) (collectively, the "Materials") pursuant to the terms and conditions
// of the Software License Agreement included with the Materials.  If you do
// not have a copy of the Software License Agreement, contact the  HSA Foundation for a copy.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE SOFTWARE.




/// @todo kzhuravl 6/23/2014 hsa_ext_finalize.h is temporarily located in
/// sc/Interface. move it to drivers/inc/shared once hsa.h is moved there.
/// If including both hsa.h and hsa_ext_finalize.h, hsa.h HAS TO BE INCLUDED
/// FIRST to avoid redefinitions.
#ifndef HSA_EXT_FINALIZE_H
#define HSA_EXT_FINALIZE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/// @todo kzhuravl 6/23/2014 partially redefine some of the definitions from
/// hsa.h until hsa.h is moved to drivers/inc/shared. Once hsa.h is moved to
/// drivers/inc/shared following #if block can be substituted with #include
/// hsa.h.
#ifndef OBSIDIAN_RUNTIME

/// Placeholder for calling convention.
#define HSA_API

///------------------------------------------------------------------------///
/// status.
///------------------------------------------------------------------------///

/**
 * TODO
 */
typedef enum {
  /**
   * The function has been executed successfully.
   */
  HSA_STATUS_SUCCESS = 0,

  /**
   * A traversal over a list of elements has been interrupted by the
   * application before completing.
   */
  HSA_STATUS_INFO_BREAK = 0x1,

  /**
   * An initialization attempt failed due to prior initialization.
   */
  HSA_EXT_STATUS_INFO_ALREADY_INITIALIZED = 0x4000,

  /**
   * The finalization options cannot be recognized.
   */
  HSA_EXT_STATUS_INFO_UNRECOGNIZED_OPTIONS = 0x4001,

  /**
   * A generic error has occurred.
   */
  HSA_STATUS_ERROR = 0x10000,

  /**
   * One of the actual arguments does not meet a precondition stated in the
   * documentation of the corresponding formal argument.
   */
  HSA_STATUS_ERROR_INVALID_ARGUMENT = 0x10001,

  /**
   * The requested queue creation is not valid.
   */
  HSA_STATUS_ERROR_INVALID_QUEUE_CREATION = 0x10002,

  /**
   * The requested allocation is not valid.
   */
  HSA_STATUS_ERROR_INVALID_ALLOCATION = 0x10003,

  /**
   * The agent is invalid.
   */
  HSA_STATUS_ERROR_INVALID_AGENT = 0x10004,

  /**
   * The memory region is invalid.
   */
  HSA_STATUS_ERROR_INVALID_REGION = 0x10005,

  /**
   * The signal is invalid.
   */
  HSA_STATUS_ERROR_INVALID_SIGNAL = 0x10006,

  /**
   * The queue is invalid.
   */
  HSA_STATUS_ERROR_INVALID_QUEUE = 0x10007,

  /**
   * The runtime failed to allocate the necessary resources. This error
   * may also occur when the core runtime library needs to spawn threads or
   * create internal OS-specific events.
   */
  HSA_STATUS_ERROR_OUT_OF_RESOURCES = 0x10008,

  /**
   * The AQL packet is malformed.
   */
  HSA_STATUS_ERROR_INVALID_PACKET_FORMAT = 0x10009,

  /**
   * An error has been detected while releasing a resource.
   */
  HSA_STATUS_ERROR_RESOURCE_FREE = 0x1000A,

  /**
   * An API other than ::hsa_init has been invoked while the reference count
   * of the HSA runtime is zero.
   */
  HSA_STATUS_ERROR_NOT_INITIALIZED = 0x1000B,

  /**
   * The maximum reference count for the object has been reached.
   */
  HSA_STATUS_ERROR_REFCOUNT_OVERFLOW = 0x1000C,

  /**
   * Mismatch between a directive in the control directive structure and in
   * the HSAIL kernel.
   */
  HSA_EXT_STATUS_ERROR_DIRECTIVE_MISMATCH = 0x14000,

  /**
   * Image format is not supported.
   */
  HSA_EXT_STATUS_ERROR_IMAGE_FORMAT_UNSUPPORTED = 0x14001,

  /**
   * Image size is not supported.
   */
  HSA_EXT_STATUS_ERROR_IMAGE_SIZE_UNSUPPORTED = 0x14002
} hsa_status_t;

///------------------------------------------------------------------------///
/// agentinfo.
///------------------------------------------------------------------------///

/**
 * @brief Opaque handle representing an agent, a device that participates in the
 * HSA memory model. An agent can submit AQL packets for execution, and might
 * also accept AQL packets for execution (Agent Dispatch packets or Dispatch
 * packets launching HSAIL-derived binaries).
 */
typedef uint64_t hsa_agent_t;

///------------------------------------------------------------------------///
/// common.
///------------------------------------------------------------------------///

/**
 * @brief Value expressed as a power of 2.
 */
typedef uint8_t hsa_powertwo8_t;

/**
 * @brief Power of two between 1 and 256.
 */
typedef enum {
  HSA_POWERTWO_1 = 0,
  HSA_POWERTWO_2 = 1,
  HSA_POWERTWO_4 = 2,
  HSA_POWERTWO_8 = 3,
  HSA_POWERTWO_16 = 4,
  HSA_POWERTWO_32 = 5,
  HSA_POWERTWO_64 = 6,
  HSA_POWERTWO_128 = 7,
  HSA_POWERTWO_256 = 8
} hsa_powertwo_t;

/**
 * @brief Three-dimensional coordinate.
 */
typedef struct hsa_dim3_s {
  /**
   * X dimension.
   */
  uint32_t x;

  /**
   * Y dimension.
   */
  uint32_t y;

  /**
   * Z dimension.
   */
  uint32_t z;
} hsa_dim3_t;

/**
* @brief Dimensions in a 3D space.
*/
typedef enum {
  /**
   * X dimension.
   */
  HSA_DIM_X = 0,

  /**
   * Y dimension.
   */
  HSA_DIM_Y = 1,

  /**
   * Z dimension.
   */
  HSA_DIM_Z = 2
} hsa_dim_t;

/**
 * @brief Opaque pointer that is passed to all runtime functions that use
 * callbacks. The runtime passes this pointer as the first argument to all
 * callbacks made by the function.
 */
typedef struct hsa_runtime_caller_s {
  /**
   * Opaque pointer that is passed as the first argument to callback
   * functions invoked by a runtime function.
   */
  uint64_t caller;
} hsa_runtime_caller_t;

/**
 * @brief Call back function for allocating data.
 */
typedef hsa_status_t (*hsa_runtime_alloc_data_callback_t)(
  hsa_runtime_caller_t caller,
  size_t byte_size,
  void **address);

#endif // OBSIDIAN_RUNTIME

///------------------------------------------------------------------------///
/// finalizer.
///------------------------------------------------------------------------///

/**
 * @brief Profile is used to specify the kind of profile. This controls what
 * features of HSAIL are supported. For more information see HSA Programmer's
 * Reference Manual.
 */
typedef uint8_t hsa_ext_brig_profile8_t;

/**
 * @brief Profile kinds. For more information see HSA Programmer's
 * Reference Manual.
 */
typedef enum {
  /**
   * Base profile.
   */
  HSA_EXT_BRIG_PROFILE_BASE = 0,

  /**
   * Full profile.
   */
  HSA_EXT_BRIG_PROFILE_FULL = 1
} hsa_ext_brig_profile_t;

/**
 * @brief Machine model type. This controls the size of addresses used for
 * segment and flat addresses. For more information see HSA Programmer's
 * Reference Manual.
 */
typedef uint8_t hsa_ext_brig_machine_model8_t;

/**
 * @brief Machine model kinds. For more information see HSA Programmer's
 * Reference Manual.
 */
typedef enum {
  /**
   * Use 32 bit addresses for global segment and flat addresses.
   */
  HSA_EXT_BRIG_MACHINE_SMALL = 0,

  /**
   * Use 64 bit addresses for global segment and flat addresses.
   */
  HSA_EXT_BRIG_MACHINE_LARGE = 1
} hsa_ext_brig_machine_model_t;

/**
 * @brief BRIG section id. The index into the array of sections in a BRIG
 * module.
 */
typedef uint32_t hsa_ext_brig_section_id32_t;

/**
 * @brief Predefined BRIG section kinds.
 */
typedef enum {
  /**
   * Textual character strings and byte data used in the module.
   * Also contains variable length arrays of offsets into other sections that
   * are used by entries in the hsa_code and hsa_operand sections. For more
   * information see HSA Programmer's Reference Manual.
   */
  HSA_EXT_BRIG_SECTION_DATA = 0,

  /**
   * All of the directives and instructions of the module. Most
   * entries contain offsets to the hsa_operand or hsa_data sections. Directives
   * provide information to the finalizer, and instructions correspond to HSAIL
   * operations which the finalizer uses to generate executable ISA code.
   * For more information see HSA Programmer's Reference Manual.
   */
  HSA_EXT_BRIG_SECTION_CODE = 1,

  /**
   * The operands of directives and instructions in the code
   * section. For example, immediate constants, registers and address
   * expressions. For more information see HSA Programmer's
   * Reference Manual.
   */
  HSA_EXT_BRIG_SECTION_OPERAND = 2
} hsa_ext_brig_section_id_t;

/**
 * @brief BRIG section header. Every section starts with a
 * ::hsa_ext_brig_section_header_t which contains the section size, name and
 * offset to the first entry. For more information see HSA Programmer's
 * Reference Manual.
 */
typedef struct hsa_ext_brig_section_header_s {
  /**
   * Size in bytes of the section, including the size of the
   * ::hsa_ext_brig_section_header_t. Must be a multiple of 4.
   */
  uint32_t byte_count;

  /**
   * Size of the header in bytes, which is also equal to the offset of the
   * first entry in the section. Must be a multiple of 4.
   */
  uint32_t header_byte_count;

  /**
   * Length of the section name in bytes.
   */
  uint32_t name_length;

  /**
   * Section name, @a name_length bytes long.
   */
  uint8_t name[1];
} hsa_ext_brig_section_header_t;

/**
 * @brief A module is the basic building block for HSAIL programs. When HSAIL
 * is generated it is represented as a module.
 */
typedef struct hsa_ext_brig_module_s {
  /**
   * Number of sections in the module. Must be at least 3.
   */
  uint32_t section_count;

  /**
   * A variable-sized array containing pointers to the BRIG sections. Must have
   * @a section_count elements. Indexed by ::hsa_ext_brig_section_id32_t. The
   * first three elements must be for the following predefined sections in
   * the following order: ::HSA_EXT_BRIG_SECTION_DATA,
   * ::HSA_EXT_BRIG_SECTION_CODE, ::HSA_EXT_BRIG_SECTION_OPERAND.
   */
  hsa_ext_brig_section_header_t *section[1];
} hsa_ext_brig_module_t;

/**
 * @brief An opaque handle to the ::hsa_ext_brig_module_t.
 */
typedef struct hsa_ext_brig_module_handle_s {
  /**
   * HSA component specific handle to the brig module.
   */
  uint64_t handle;
} hsa_ext_brig_module_handle_t;

/**
 * @brief An entry offset into the code section of the BRIG module. The value
 * is the byte offset relative to the start of the section to the beginning of
 * the referenced entry. The value 0 is reserved to indicate that the offset
 * does not reference any entry.
 */
typedef uint32_t hsa_ext_brig_code_section_offset32_t;

/**
 * @brief The set of exceptions supported by HSAIL. This is represented as a
 * bit set.
 */
typedef uint16_t hsa_ext_exception_kind16_t;

/**
 * @brief HSAIL exception kinds. For more information see HSA Programmer's
 * Reference Manual.
 */
typedef enum {
  /**
   * Operations are performed on values for which the results are not defined.
   * These are:
   *   - Operations on signaling NaN (sNaN) floating-point values.
   *   - Signalling comparisons: comparisons on quiet NaN (qNaN)
   *     floating-point values.
   *   - Multiplication: mul(0.0, infinity) or mul(infinity, 0.0).
   *   - Fused multiply add: fma(0.0, infinity, c) or fma(infinity, 0.0, c)
   *     unless c is a quiet NaN, in which case it is implementation-defined
   *     if an exception is generated.
   *   - Addition, subtraction, or fused multiply add: magnitude subtraction
   *     of infinities, such as: add(positive infinity, negative infinity),
   *     sub(positive infinity, positive infinity).
   *   - Division: div(0.0, 0.0) or div(infinity, infinity).
   *   - Square root: sqrt(negative).
   *   - Conversion: A cvt with a floating-point source type, an integer
   *     destination type, and a nonsaturating rounding mode, when the source
   *     value is a NaN, infinity, or the rounded value, after any flush to
   *     zero, cannot be represented precisely in the integer type of the
   *     destination.
   */
  HSA_EXT_EXCEPTION_INVALID_OPERATION = 1,

  /**
   * A finite non-zero floating-point value is divided by zero. It is
   * implementation defined if integer div or rem operations with a divisor of
   * zero will generate a divide by zero exception.
   */
  HSA_EXT_EXCEPTION_DIVIDE_BY_ZERO = 2,

  /**
   * The floating-point exponent of a value is too large to be represented.
   */
  HSA_EXT_EXCEPTION_OVERFLOW = 4,

  /**
   * A non-zero tiny floating-point value is computed and either the ftz
   * modifier is specified, or the ftz modifier was not specified and the value
   * cannot be represented exactly.
   */
  HSA_EXT_EXCEPTION_UNDERFLOW = 8,

  /**
   * A computed floating-point value is not represented exactly in the
   * destination. This can occur due to rounding. In addition, it is
   * implementation defined if operations with the ftz modifier that cause a
   * value to be flushed to zero generate the inexact exception.
   */
  HSA_EXT_EXCEPTION_INEXACT = 16
} hsa_ext_exception_kind_t;

/**
 * @brief Bit set of control directives supported in HSAIL. See HSA Programmer's
 * Reference Manual description of control directives with the same name for
 * more information. For control directives that have an associated value, the
 * value is given by the field in hsa_ext_control_directives_t. For control
 * directives that are only present of absent (such as
 * requirenopartialworkgroups) they have no corresponding field as the presence
 * of the bit in this mask is sufficient.
 */
typedef uint64_t hsa_ext_control_directive_present64_t;

/**
 * @brief HSAIL control directive kinds. For more information see HSA
 * Programmer's Reference Manual.
 */
typedef enum {
  /**
   * If not enabled then must be 0, otherwise must be non-0 and specifies the
   * set of HSAIL exceptions that must have the BREAK policy enabled.  If this
   * set is not empty then the generated code may have lower performance than if
   * the set is empty. If the kernel being finalized has any
   * enablebreakexceptions control directives, then the values specified by this
   * argument are unioned with the values in these control directives.  If any
   * of the functions the kernel calls have an enablebreakexceptions control
   * directive, then they must be equal or a subset of, this union.
   */
  HSA_EXT_CONTROL_DIRECTIVE_ENABLE_BREAK_EXCEPTIONS = 0,

  /**
   * If not enabled then must be 0, otherwise must be non-0 and specifies the
   * set of HSAIL exceptions that must have the DETECT policy enabled.  If this
   * set is not empty then the generated code may have lower performance than if
   * the set is empty. However, an implementation should endeavour to make the
   * performance impact small. If the kernel being finalized has any
   * enabledetectexceptions control directives, then the values specified by
   * this argument are unioned with the values in these control directives. If
   * any of the functions the kernel calls have an enabledetectexceptions
   * control directive, then they must be equal or a subset of, this union.
   */
  HSA_EXT_CONTROL_DIRECTIVE_ENABLE_DETECT_EXCEPTIONS = 1,

  /**
   * If not enabled then must be 0, and any amount of dynamic group segment can
   * be allocated for a dispatch, otherwise the value specifies the maximum
   * number of bytes of dynamic group segment that can be allocated for a
   * dispatch. If the kernel being finalized has any maxdynamicsize control
   * directives, then the values must be the same, and must be the same as this
   * argument if it is enabled. This value can be used by the finalizer to
   * determine the maximum number of bytes of group memory used by each
   * work-group by adding this value to the group memory required for all group
   * segment variables used by the kernel and all functions it calls, and group
   * memory used to implement other HSAIL features such as fbarriers and the
   * detect exception operations. This can allow the finalizer to determine the
   * expected number of work-groups that can be executed by a compute unit and
   * allow more resources to be allocated to the work-items if it is known that
   * fewer work-groups can be executed due to group memory limitations.
   */
  HSA_EXT_CONTROL_DIRECTIVE_MAX_DYNAMIC_GROUP_SIZE = 2,

  /**
   * If not enabled then must be 0, otherwise must be greater than 0. Specifies
   * the maximum number of work-items that will be in the grid when the kernel
   * is dispatched. For more information see HSA Programmer's Reference Manual.
   */
  HSA_EXT_CONTROL_DIRECTIVE_MAX_FLAT_GRID_SIZE = 4,

  /**
   * If not enabled then must be 0, otherwise must be greater than 0. Specifies
   * the maximum number of work-items that will be in the work-group when the
   * kernel is dispatched. For more information see HSA Programmer's Reference
   * Manual.
   */
  HSA_EXT_CONTROL_DIRECTIVE_MAX_FLAT_WORKGROUP_SIZE = 8,

  /**
   * If not enabled then must be 0, and the finalizer is free to generate ISA
   * that may result in any number of work-groups executing on a single compute
   * unit. Otherwise, the finalizer should attempt to generate ISA that will
   * allow the specified number of work-groups to execute on a single compute
   * unit. This is only a hint and can be ignored by the finalizer. If the
   * kernel being finalized, or any of the functions it calls, has a requested
   * control directive, then the values must be the same. This can be used to
   * determine the number of resources that should be allocated to a single
   * work-group and work-item. For example, a low value may allow more resources
   * to be allocated, resulting in higher per work-item performance, as it is
   * known there will never be more than the specified number of work-groups
   * actually executing on the compute unit.  Conversely, a high value may
   * allocate fewer resources, resulting in lower per work-item performance,
   * which is offset by the fact it allows more work-groups to actually execute
   * on the compute unit.
   */
  HSA_EXT_CONTROL_DIRECTIVE_REQUESTED_WORKGROUPS_PER_CU = 16,

  /**
   * If not enabled then all elements for Dim3 must be 0, otherwise every
   * element must be greater than 0. Specifies the grid size that will be used
   * when the kernel is dispatched. For more information see HSA Programmer's
   * Reference Manual.
   */
  HSA_EXT_CONTROL_DIRECTIVE_REQUIRED_GRID_SIZE = 32,

  /**
   * If not enabled then all elements for Dim3 must be 0, and the produced code
   * can be dispatched with any legal work-group range consistent with the
   * dispatch dimensions. Otherwise, the code produced must always be dispatched
   * with the specified work-group range. No element of the specified range must
   * be 0. It must be consistent with required_dimensions and
   * max_flat_workgroup_size. If the kernel being finalized, or any of the
   * functions it calls, has a requiredworkgroupsize control directive, then the
   * values must be the same. Specifying a value can allow the finalizer to
   * optimize work-group id operations, and if the number of work-items in the
   * work-group is less tha the WAVESIZE then barrier operations can be
   * optimized to just a memory fence.
   */
  HSA_EXT_CONTROL_DIRECTIVE_REQUIRED_WORKGROUP_SIZE = 64,

  /**
   * If not enabled then must be 0 and the produced kernel code can be
   * dispatched with 1, 2 or 3 dimensions. If enabled then the value is 1..3 and
   * the code produced must only be dispatched with a dimension that
   * matches. Other values are illegal. If the kernel being finalized, or any of
   * the functions it calls, has a requireddimsize control directive, then the
   * values must be the same. This can be used to optimize the code generated to
   * compute the absolute and flat work-group and work-item id, and the dim
   * HSAIL operations.
   */
  HSA_EXT_CONTROL_DIRECTIVE_REQUIRED_DIM = 128,

  /**
   * Specifies that the kernel must be dispatched with no partial work-groups.
   * It can be placed in either a kernel or a function code block. This is only
   * a hint and can be ignored by the finalizer.
   *
   * It is undefined if the kernel is dispatched with any dimension of the grid
   * size not being an exact multiple of the corresponding dimension of the
   * work-group size.
   *
   * A finalizer might be able to generate better code for currentworkgroupsize
   * if it knows there are no partial work-groups, because the result becomes
   * the same as the workgroupsize operation. An HSA component might be able to
   * dispatch a kernel more efficiently if it knows there are no partial
   * work-groups.
   *
   * The control directive applies to the whole kernel and all functions it
   * calls. It can appear multiple times in a kernel or function. If it appears
   * in a function (including external functions), then it must also appear in
   * all kernels that call that function (or have been specified when the
   * finalizer was invoked), either directly or indirectly.
   *
   * If require no partial work-groups is specified when the finalizer is
   * invoked, the kernel behaves as if the requirenopartialworkgroups control
   * directive has been specified.
   *
   * \note require_no_partial_work_groups does not have a field since having the
   * bit set in enabledControlDirectives indicates that the cpntrol directive is
   * present.
   */
  HSA_EXT_CONTROL_DIRECTIVE_REQUIRE_NO_PARTIAL_WORKGROUPS = 256
} hsa_ext_control_directive_present_t;

/**
 * @brief The hsa_ext_control_directives_t specifies the values for the HSAIL
 * control directives. These control how the finalizer generates code. This
 * struct is used both as an argument to hsaFinalizeKernel to specify values for
 * the control directives, and is used in HsaKernelCode to record the values of
 * the control directives that the finalize used when generating the code which
 * either came from the finalizer argument or explicit HSAIL control
 * directives. See the definition of the control directives in HSA Programmer's
 * Reference Manual which also defines how the values specified as finalizer
 * arguments have to agree with the control directives in the HSAIL code.
 */
typedef struct hsa_ext_control_directives_s {
  /**
   * This is a bit set indicating which control directives have been
   * specified. If the value is 0 then there are no control directives specified
   * and the rest of the fields can be ignored. The bits are accessed using the
   * hsa_ext_control_directives_present_mask_t. Any control directive that is not
   * enabled in this bit set must have the value of all 0s.
   */
  hsa_ext_control_directive_present64_t enabled_control_directives;

  /**
   * If enableBreakExceptions is not enabled then must be 0, otherwise must be
   * non-0 and specifies the set of HSAIL exceptions that must have the BREAK
   * policy enabled. If this set is not empty then the generated code may have
   * lower performance than if the set is empty. If the kernel being finalized
   * has any enablebreakexceptions control directives, then the values specified
   * by this argument are unioned with the values in these control
   * directives. If any of the functions the kernel calls have an
   * enablebreakexceptions control directive, then they must be equal or a
   * subset of, this union.
   */
  hsa_ext_exception_kind16_t enable_break_exceptions;

  /**
   * If enableDetectExceptions is not enabled then must be 0, otherwise must be
   * non-0 and specifies the set of HSAIL exceptions that must have the DETECT
   * policy enabled. If this set is not empty then the generated code may have
   * lower performance than if the set is empty. However, an implementation
   * should endeavour to make the performance impact small. If the kernel being
   * finalized has any enabledetectexceptions control directives, then the
   * values specified by this argument are unioned with the values in these
   * control directives. If any of the functions the kernel calls have an
   * enabledetectexceptions control directive, then they must be equal or a
   * subset of, this union.
   */
  hsa_ext_exception_kind16_t enable_detect_exceptions;

  /**
   * If maxDynamicGroupSize is not enabled then must be 0, and any amount of
   * dynamic group segment can be allocated for a dispatch, otherwise the value
   * specifies the maximum number of bytes of dynamic group segment that can be
   * allocated for a dispatch. If the kernel being finalized has any
   * maxdynamicsize control directives, then the values must be the same, and
   * must be the same as this argument if it is enabled. This value can be used
   * by the finalizer to determine the maximum number of bytes of group memory
   * used by each work-group by adding this value to the group memory required
   * for all group segment variables used by the kernel and all functions it
   * calls, and group memory used to implement other HSAIL features such as
   * fbarriers and the detect exception operations. This can allow the finalizer
   * to determine the expected number of work-groups that can be executed by a
   * compute unit and allow more resources to be allocated to the work-items if
   * it is known that fewer work-groups can be executed due to group memory
   * limitations.
   */
  uint32_t max_dynamic_group_size;

  /**
   * If maxFlatGridSize is not enabled then must be 0, otherwise must be greater
   * than 0. See HSA Programmer's Reference Manual description of
   * maxflatgridsize control directive.
   */
  uint32_t max_flat_grid_size;

  /**
   * If maxFlatWorkgroupSize is not enabled then must be 0, otherwise must be
   * greater than 0. See HSA Programmer's Reference Manual description of
   * maxflatworkgroupsize control directive.
   */
  uint32_t max_flat_workgroup_size;

  /**
   * If requestedWorkgroupsPerCu is not enabled then must be 0, and the
   * finalizer is free to generate ISA that may result in any number of
   * work-groups executing on a single compute unit. Otherwise, the finalizer
   * should attempt to generate ISA that will allow the specified number of
   * work-groups to execute on a single compute unit. This is only a hint and
   * can be ignored by the finalizer. If the kernel being finalized, or any of
   * the functions it calls, has a requested control directive, then the values
   * must be the same. This can be used to determine the number of resources
   * that should be allocated to a single work-group and work-item. For example,
   * a low value may allow more resources to be allocated, resulting in higher
   * per work-item performance, as it is known there will never be more than the
   * specified number of work-groups actually executing on the compute
   * unit. Conversely, a high value may allocate fewer resources, resulting in
   * lower per work-item performance, which is offset by the fact it allows more
   * work-groups to actually execute on the compute unit.
   */
  uint32_t requested_workgroups_per_cu;

  /**
   * If not enabled then all elements for Dim3 must be 0, otherwise every
   * element must be greater than 0. See HSA Programmer's Reference Manual
   * description of requiredgridsize control directive.
   */
  hsa_dim3_t required_grid_size;

  /**
   * If requiredWorkgroupSize is not enabled then all elements for Dim3 must be
   * 0, and the produced code can be dispatched with any legal work-group range
   * consistent with the dispatch dimensions. Otherwise, the code produced must
   * always be dispatched with the specified work-group range. No element of the
   * specified range must be 0. It must be consistent with required_dimensions
   * and max_flat_workgroup_size. If the kernel being finalized, or any of the
   * functions it calls, has a requiredworkgroupsize control directive, then the
   * values must be the same. Specifying a value can allow the finalizer to
   * optimize work-group id operations, and if the number of work-items in the
   * work-group is less than the WAVESIZE then barrier operations can be
   * optimized to just a memory fence.
   */
  hsa_dim3_t required_workgroup_size;

  /**
   * If requiredDim is not enabled then must be 0 and the produced kernel code
   * can be dispatched with 1, 2 or 3 dimensions. If enabled then the value is
   * 1..3 and the code produced must only be dispatched with a dimension that
   * matches. Other values are illegal. If the kernel being finalized, or any of
   * the functions it calls, has a requireddimsize control directive, then the
   * values must be the same. This can be used to optimize the code generated to
   * compute the absolute and flat work-group and work-item id, and the dim
   * HSAIL operations.
   */
  uint8_t required_dim;

  /**
   * Reserved. Must be 0.
   */
  uint8_t reserved[75];
} hsa_ext_control_directives_t;

/**
 * @brief The kinds of code objects that can be contained in
 * ::hsa_ext_code_descriptor_t.
 */
typedef uint32_t hsa_ext_code_kind32_t;

/**
 * @brief Kinds of code object. For more information see HSA Programmer's
 * Reference Manual.
 */
typedef enum {
  /**
   * Not a code object.
   */
  HSA_EXT_CODE_NONE = 0,

  /**
   * HSAIL kernel that can be used with an AQL dispatch packet.
   */
  HSA_EXT_CODE_KERNEL = 1,

  /**
   * HSAIL indirect function.
   */
  HSA_EXT_CODE_INDIRECT_FUNCTION = 2,

  /**
   * HSA runtime code objects. For example, partially linked code objects.
   */
  HSA_EXT_CODE_RUNTIME_FIRST = 0x40000000,
  HSA_EXT_CODE_RUNTIME_LAST = 0x7fffffff,

  /**
   * Vendor specific code objects.
   */
  HSA_EXT_CODE_VENDOR_FIRST = 0x80000000,
  HSA_EXT_CODE_VENDOR_LAST = 0xffffffff
} hsa_ext_code_kind_t;

/**
 * @brief Each HSA component can support one or more call conventions. For
 * example, an HSA component may have different call conventions that each use
 * a different number of isa registers to allow different numbers of
 * wavefronts to execute on a compute unit.
 */
typedef uint32_t hsa_ext_program_call_convention_id32_t;

/**
 * @brief Kinds of program call convention IDs.
 */
typedef enum {
 /**
  * Finalizer determined call convention ID.
  */
  HSA_EXT_PROGRAM_CALL_CONVENTION_FINALIZER_DETERMINED = -1
} hsa_ext_program_call_convention_id_t;

/**
 * @brief The 64-bit opaque code handle to the finalized code that includes the
 * executable ISA for the HSA component. It can be used for the kernel
 * dispatch packet kernel object address field.
 */
typedef struct hsa_ext_code_handle_s {
  /**
   * HSA component specific handle to the code.
   */
  uint64_t handle;
} hsa_ext_code_handle_t;

/**
 * @brief An opaque handle to the debug information.
 */
typedef struct hsa_ext_debug_information_handle_s {
  /**
   * HSA component specific handle to the debug information.
   */
  uint64_t handle;
} hsa_ext_debug_information_handle_t;

/**
 * @brief Provides the information about a finalization of the kernel or
 * indirect function for a specific HSA component, and for indirect functions,
 * a specific call convention of that HSA component
 */
typedef struct hsa_ext_code_descriptor_s {
  /**
   * Type of code object this code descriptor associated with.
   */
  hsa_ext_code_kind32_t code_type;

  /**
   * The amount of group segment memory required by a work-group in bytes. This
   * does not include any dynamically allocated group segment memory that may be
   * added when the kernel is dispatched.
   */
  uint32_t workgroup_group_segment_byte_size;

  /**
   * The size in bytes of the kernarg segment that holds the values of the
   * arguments to the kernel.
   */
  uint64_t kernarg_segment_byte_size;

  /**
   * The amount of memory required for the combined private, spill and arg
   * segments for a work-item in bytes.
   */
  uint32_t workitem_private_segment_byte_size;

  /**
   * Number of fbarrier's used in the kernel and all functions it calls. If the
   * implementation uses group memory to allocate the fbarriers then that amount
   * must already be included in the workgroupGroupSegmentByteSize total.
   */
  uint32_t workgroup_fbarrier_count;

  /**
   * The 64-bit opaque code handle to the finalized code that includes the
   * executable ISA for the HSA component. It can be used for the kernel
   * dispatch packet kernel object address field.
   */
  hsa_ext_code_handle_t code;

  /**
   * The maximum byte alignment of variables used by the kernel in the kernarg
   * memory segment. Expressed as a power of two. Must be at least
   * HSA_POWERTWO_16
   */
  hsa_powertwo8_t kernarg_segment_alignment;

  /**
   * The maximum byte alignment of variables used by the kernel in the group
   * memory segment. Expressed as a power of two. Must be at least
   * HSA_POWERTWO_16
   */
  hsa_powertwo8_t group_segment_alignment;

  /**
   * The maximum byte alignment of variables used by the kernel in the private
   * memory segment. Expressed as a power of two. Must be at least
   * HSA_POWERTWO_16
   */
  hsa_powertwo8_t private_segment_alignment;

  /**
   * Wavefront size expressed as a power of two. Must be a power of 2 in range
   * 1..64 inclusive. Used to support runtime query that obtains wavefront size,
   * which may be used by application to allocated dynamic group memory and set
   * the dispatch work-group size.
   */
  hsa_powertwo8_t wavefront_size;

  /**
   * Program call convention id this code descriptor holds.
   */
  hsa_ext_program_call_convention_id32_t program_call_convention;

  /**
   * BRIG module handle this code descriptor associated with.
   */
  hsa_ext_brig_module_handle_t module;

  /**
   * BRIG directive offset this code descriptor associated with.
   */
  hsa_ext_brig_code_section_offset32_t symbol;

  /**
   * The HSAIL profile defines which features are used. This information is from
   * the HSAIL version directive. If this ::hsa_ext_code_descriptor_t is not
   * generated from an ::hsa_ext_finalize then must still indicate what
   * profile is being used.
   */
  hsa_ext_brig_profile8_t hsail_profile;

  /**
   * The HSAIL machine model gives the address sizes used by the code. This
   * information is from the HSAIL version directive. If this
   * ::hsa_ext_code_descriptor_t is not generated from an ::hsa_ext_finalize
   * then must still indicate for what machine mode the code is generated.
   */
  hsa_ext_brig_machine_model8_t hsail_machine_model;

  /**
   * Reserved for BRIG target options if any are defined in the future. Must
   * be 0.
   */
  uint16_t reserved1;

  /**
   * Opaque handle to debug information.
   */
  hsa_ext_debug_information_handle_t debug_information;

  /**
   * The vendor of the HSA Component on which this Kernel Code object can
   * execute. ISO/IEC 624 character encoding must be used. If the
   * name is less than 24 characters then remaining characters must
   * be set to 0.
   */
  char agent_vendor[24];

  /**
   * The vendor's name of the HSA Component on which this Kernel Code object can
   * execute. ISO/IEC 624 character encoding must be used. If the name is less
   * than 24 characters then remaining characters must be set to 0.
   */
  char agent_name[24];

  /**
   * The HSAIL major version. This information is from the HSAIL version
   * directive. If this ::hsa_ext_code_descriptor_t is not generated from an
   * ::hsa_ext_finalize then must be 0.
   */
  uint32_t hsail_version_major;

  /**
   * The HSAIL minor version. This information is from the HSAIL version
   * directive. If this ::hsa_ext_code_descriptor_t is not generated from an
   * ::hsa_ext_finalize then must be 0.
   */
  uint32_t hsail_version_minor;

  /**
   * Reserved. Must be 0.
   */
  uint64_t reserved2;

  /**
   * The values should be the actually values used by the finalizer in
   * generating the code. This may be the union of values specified as finalizer
   * arguments and explicit HSAIL control directives. If the finalizer chooses
   * to ignore a control directive, and not generate constrained code, then the
   * control directive should not be marked as enabled even though it was
   * present in the HSAIL or finalizer argument. The values are intended to
   * reflect the constraints that the code actually requires to correctly
   * execute, not the values that were actually specified at finalize time.
   */
  hsa_ext_control_directives_t control_directive;
} hsa_ext_code_descriptor_t;

/**
 * @brief Finalization request. Holds information about the module needed
 * to be finalized. If the module contains an indirect function, also holds
 * information about call convention id.
 */
typedef struct hsa_ext_finalization_request_s {
  /**
   * Handle to the ::hsa_ext_brig_module_t, which needs to be finalized.
   */
  hsa_ext_brig_module_handle_t module;
  /**
   * Entry offset into the code section.
   */
  hsa_ext_brig_code_section_offset32_t symbol;
  /**
   * If this finalization request is for indirect function, desired program
   * call convention.
   */
  hsa_ext_program_call_convention_id32_t program_call_convention;
} hsa_ext_finalization_request_t;

/**
 * @brief Finalization handle is the handle to the object produced by the
 * Finalizer that contains the isa code and related information needed to
 * execute that code for a specific agent for the set of  kernels/indirect
 * functions specified in the finalization request.
 */
typedef struct hsa_ext_finalization_handle_s {
  /**
   * HSA component specific handle to the finalization information.
   */
  uint64_t handle;
} hsa_ext_finalization_handle_t;

/**
 * @brief Callback function to get the definition of a module scope
 * variable/fbarrier or kernel/function.
 */
typedef hsa_status_t (*hsa_ext_symbol_definition_callback_t)(
  hsa_runtime_caller_t caller,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  hsa_ext_brig_module_handle_t *definition_module,
  hsa_ext_brig_module_t **definition_module_brig,
  hsa_ext_brig_code_section_offset32_t *definition_symbol);

/**
 * @brief Callback function to get the address of global segment variables,
 * kernel table variable, indirect function table variable.
 */
typedef hsa_status_t (*hsa_ext_symbol_address_callback_t)(
  hsa_runtime_caller_t caller,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  uint64_t *symbol_address);

/**
 * @brief Callback function to get the string representation of the error
 * message.
 */
typedef hsa_status_t (*hsa_ext_error_message_callback_t)(
  hsa_runtime_caller_t caller,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t statement,
  uint32_t indent_level,
  const char *message);

/**
 * @brief Finalizes provided list of kernel and/or indirect functions.
 *
 * @details Invokes the finalizer on the provided list of kernels and indirect
 * functions. A kernel can only be finalized once per program per agent.
 * An indirect function can only be finalized once per program per agent per
 * call convention. Only code for the HSA components specified when the
 * program was created can be requested. The program must contain a definition
 * for the requested kernels and indirect functions amongst the modules that
 * have been added to the program.
 *
 * @param[in] caller Opaque pointer and will be passed to all callback
 * functions made by this call.
 *
 * @param[in] agent HSA agents for which code must be produced.
 *
 * @param[in] program_agent_id Program agent id.
 *
 * @param[in] program_agent_count Number of program agents.
 *
 * @param[in] finalization_request_count The number of kernels and/or
 * indirect needed to be finalized.
 *
 * @param[in] finalization_request_list List of kernels and/or indirect
 * functions needed to be finalized.
 *
 * @param[in] control_directives The control directives that can be specified to
 * influence how the finalizer generates code. If NULL then no control
 * directives are used. If this call is successful and control_directives is not
 * NULL, then the resulting hsa_ext_code_descriptor_t object will have control
 * directives which were used by the finalizer.
 *
 * @param[in] symbol_definition_callback Callback function to get the
 * definition of a module scope variable/fbarrier or kernel/function.
 *
 * @param[in] symbol_address_callback Callback function to get the address of
 * global segment variables, kernel table variables, indirect function table
 * variable.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message.
 *
 * @param[in] optimization_level An implementation defined value that control
 * the level of optimization performed by the finalizer.
 *
 * @param[in] options Implementation defined options that can be specified to
 * the finalizer.
 *
 * @param[in] debug_information The flag for including/excluding the debug
 * information for @a finalization. 0 - exclude debug information, 1 - include
 * debug information.
 *
 * @param[out] finalization Handle to the object produced that contains the
 * isa code and related information needed to execute that code for the
 * specific @a agent for the set of kernels/indirect functions specified in the
 * @a finalization_request.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
 *
 * @retval ::HSA_EXT_STATUS_ERROR_DIRECTIVE_MISMATCH If the directive in the
 * control directive structure and in the HSAIL kernel mismatch or if the same
 * directive is used with a different value in one of the functions used by
 * this kernel.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If @a finalization_request_list
 * is NULL or invalid.
 *
 * @retval ::HSA_STATUS_ERROR_OUT_OF_RESOURCES If the finalize API cannot
 * allocate memory for @a finalization.
 *
 * @retval ::HSA_EXT_STATUS_INFO_UNRECOGNIZED_OPTIONS If the options are not
 * recognized, no error is returned, just an info status is used to indicate
 * invalid options.
 */
hsa_status_t HSA_API hsa_ext_finalize(
  hsa_runtime_caller_t caller,
  hsa_agent_t agent,
  uint32_t program_agent_id,
  uint32_t program_agent_count,
  size_t finalization_request_count,
  hsa_ext_finalization_request_t *finalization_request_list,
  hsa_ext_control_directives_t *control_directives,
  hsa_ext_symbol_definition_callback_t symbol_definition_callback,
  hsa_ext_symbol_address_callback_t symbol_address_callback,
  hsa_ext_error_message_callback_t error_message_callback,
  uint8_t optimization_level,
  const char *options,
  int debug_information,
  hsa_ext_finalization_handle_t *finalization);

/**
 * @brief Queries the total number of kernel and indirect functions that
 * have been finalized as part of the finalization object.
 *
 * @param[in] agent Agent for which the finalization object contains code.
 *
 * @param[in] finalization Finalization handle that references the finalization
 * object for @a agent.
 *
 * @param[out] code_descriptor_count Number of kernel and indirect functions that
 * have been finalized as part of the finalization object.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and number of code descriptors is queried.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a agent is
 * NULL or not valid. If @a finalization points to invalid finalization. If
 * @a code_descriptor_count is NULL.
 */
hsa_status_t hsa_ext_query_finalization_code_descriptor_count(
  hsa_agent_t agent,
  hsa_ext_finalization_handle_t finalization,
  uint32_t *code_descriptor_count);

/**
 * @brief Queries information about one of the kernel or indirect functions that
 * have been finalized as part of a finalization object.
 *
 * @param[in] agent Agent for which the finalization object contains code.
 *
 * @param[in] finalization Finalization handle that references the finalization
 * object for @a agent.
 *
 * @param[in] index Specifies which kernel or indirect function information is
 * being requested. Must be in the range 0 to
 * ::hsa_ext_query_finalization_code_descriptor_count – 1.
 *
 * @param[out] code_descriptor The information about the requested kernel or
 * indirect function.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and code descriptor is queried.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a agent is
 * NULL or not valid. If @a finalization points to invalid finalization. If
 * @a code_descriptor_count is NULL.
 */
hsa_status_t hsa_ext_query_finalization_code_descriptor(
  hsa_agent_t agent,
  hsa_ext_finalization_handle_t finalization,
  uint32_t index,
  hsa_ext_code_descriptor_t *code_descriptor);

/**
 * @brief Destroys a finalization. This may reclaim the memory occupied by the
 * finalization object, and remove corresponding isa code from the associated
 * agent. Once destroyed, all code that is part of the finalization object is
 * invalidated. It is undefined if any dispatch is executing, or will
 * subsequently be executed, when the finalization containing its code is
 * destroyed.
 *
 * @param[in] agent Agent for which the finalization object contains code.
 *
 * @param[in] finalization Handle to the finalization to be destroyed.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If @a finalization
 * is NULL or does not point to a valid finalization structure.
 *
 * @retval ::HSA_STATUS_ERROR_RESOURCE_FREE If some of the resources consumed
 * during initialization by the runtime could not be freed.
 */
hsa_status_t HSA_API hsa_ext_destroy_finalization(
  hsa_agent_t agent,
  hsa_ext_finalization_handle_t finalization);

/**
 * @brief Serializes the finalization.
 *
 * @details Serializes finalization descriptor for specified @a agent. The
 * caller can set @a debug_information to 1 in order to include debug
 * information of this finalization descriptor in the serialized object.
 *
 * @param[in] caller Opaque pointer and will be passed to all callback
 * functions made by this call.
 *
 * @param[in] agent The HSA agent for which @a finalization must be
 * serialized.
 *
 * @param[in] finalization Handle to the finalization to be serialized.
 *
 * @param[in] alloc_serialize_data_callback Callback function for allocation.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message.
 *
 * @param[in] debug_information The flag for including/excluding the debug
 * information for @a finalization. 0 - exclude debug information, 1 - include
 * debug information.
 *
 * @param[out] serialized_object Pointer to the serialized object.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If @a finalization
 * is either NULL or does not point to a valid finalization descriptor object.
 *
 * @retval ::HSA_STATUS_ERROR_OUT_OF_RESOURCES If no memory can be allocated
 * for @a serialized_object.
 */
hsa_status_t HSA_API hsa_ext_serialize_finalization(
  hsa_runtime_caller_t caller,
  hsa_agent_t agent,
  hsa_ext_finalization_handle_t finalization,
  hsa_runtime_alloc_data_callback_t alloc_serialize_data_callback,
  hsa_ext_error_message_callback_t error_message_callback,
  int debug_information,
  void *serialized_object);

/**
 * @brief Deserializes the finalization.
 *
 * @details Deserializes finalization descriptor for specified @a agent. The
 * caller can set @a debug_information to 1 in order to include debug
 * information of this finalization descriptor from the serialized object.
 *
 * @param[in] caller Opaque pointer and will be passed to all callback
 * functions made by this call.
 *
 * @param[in] serialized_object Serialized object to be deserialized.
 *
 * @param[in] agent The HSA agent for which @a finalization must be
 * serialized.
 *
 * @param[in] program_agent_id TODO.
 *
 * @param[in] program_agent_count TODO.
 *
 * @param[in] symbol_address_callback Callback function to get the address of
 * global segment variables, kernel table variables, indirect function table
 * variable.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message.
 *
 * @param[in] debug_information The flag for including/excluding the debug
 * information for @a finalization. 0 - exclude debug information, 1 - include
 * debug information.
 *
 * @param[out] finalization Handle to the deserialized finalization.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If @a serialized_object is
 * either NULL, or is not valid, or the size is 0.
 *
 * @retval ::HSA_STATUS_ERROR_OUT_OF_RESOURCES If no memory can be allocated
 * for @a finalization.
 */
hsa_status_t HSA_API hsa_ext_deserialize_finalization(
  hsa_runtime_caller_t caller,
  void *serialized_object,
  hsa_agent_t agent,
  uint32_t program_agent_id,
  uint32_t program_agent_count,
  hsa_ext_symbol_address_callback_t symbol_address_callback,
  hsa_ext_error_message_callback_t error_message_callback,
  int debug_information,
  hsa_ext_finalization_handle_t *finalization);

///------------------------------------------------------------------------///
/// linker.
///------------------------------------------------------------------------///

/**
 * @brief An opaque handle to the HSAIL program.
 *
 * @details An application can use the HSA runtime to create zero or more
 * HSAIL programs, to which it can add zero or more HSAIL modules. HSAIL
 * program manages linking of symbol declaration to symbol definitions
 * between modules. In addition, the application can provide symbol definitions
 * to an HSAIL program, and can obtain the address of symbols defined by the
 * HSAIL program using the HSA runtime. An HSAIL program can be created with
 * ::hsa_ext_program_create, which returns a handle to the created program
 * ::hsa_ext_program_handle_t. A program handle has to be further used to
 * add particular modules to the program using ::hsa_ext_add_module, perform
 * various define, query and validation operations, finalize the program using
 * ::hsa_ext_finalize_program. A program has to be destroyed once not needed
 * any more using ::hsa_ext_program_destroy.
 */
typedef struct hsa_ext_program_handle_s {
  /**
   * HSA component specific handle to the program.
   */
  uint64_t handle;
} hsa_ext_program_handle_t;

/**
 * ID of an agent within a program that it is a member. It is used to index
 * a kernel descriptor to access the code descriptor for the agent. An agent
 * can be a member of multiple programs and can have different
 * ::hsa_ext_program_agent_id_t in each program.
 */
typedef uint32_t hsa_ext_program_agent_id_t;

/**
 * @brief Creates an HSAIL program.
 *
 * @details Creates an HSAIL program. When an HSAIL program is created, one
 * or more HSA components that are part of the HSA platform must be specified
 * (::hsa_agent_t), together with the machine model
 * (::hsa_ext_brig_machine_model8_t) and profile (::hsa_ext_brig_profile8_t).
 * The set of agents associated with the HSAIL being created cannot be changed
 * after the program is created. The machine model address size for the global
 * segment must match the size used by the application. All modules added to
 * the program must have the same machine model and profile as the program.
 * Once the program is created, the program handle (::hsa_ext_program_handle_t)
 * is returned. See ::hsa_ext_program_handle_t for more details.
 *
 * @param[in] agents One or more HSA components that are part of the HSA
 * platform to create a program for.
 *
 * @param[in] agent_count Number of HSA components to create an HSAIL program
 * for.
 *
 * @param[in] machine_model The kind of machine model this HSAIL program is
 * created for. The machine model address size for the global segment must
 * match the size used by the applications. All module added to the program
 * must have the same machine model.
 *
 * @param[in] profile The kind of profile this HSAIL program is created for.
 * All modules added to the program must have the same profile as the program.
 *
 * @param[out] program A valid pointer to a program handle for the HSAIL
 * program created.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and an HSAIL program is created.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If @a agent is NULL, or not
 * valid. If @a agent_count is 0. If @a machine_model is not valid. If
 * @a profile is not valid. In this case @a program will be NULL.
 *
 * @retval ::HSA_STATUS_ERROR_OUT_OF_RESOURCES If there is a failure to
 * allocate resources required for program creation.
 *
 * @retval ::HSA_EXT_STATUS_INFO_ALREADY_INITIALIZED If @a program is already a
 * valid program. No error is returned, just an info status is used to indicate
 * invalid options.
 */
hsa_status_t HSA_API hsa_ext_program_create(
  hsa_agent_t *agents,
  uint32_t agent_count,
  hsa_ext_brig_machine_model8_t machine_model,
  hsa_ext_brig_profile8_t profile,
  hsa_ext_program_handle_t *program);

/**
 * @brief Destroys an HSAIL program.
 *
 * @details Destroys an HSAIL program pointed to by program handle @a program.
 * When the program is destroyed, member code objects are destroyed as well.
 *
 * @param[in] program Program handle for the HSAIL program to be destroyed.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and an HSAIL program is destroyed.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If @a program is not a valid
 * ::hsa_ext_program_handle_t object.
 *
 * @retval ::HSA_STATUS_ERROR_RESOURCE_FREE If @a program is already destroyed
 * or has never been created.
 */
hsa_status_t HSA_API hsa_ext_program_destroy(
  hsa_ext_program_handle_t program);

/**
 * @brief Adds an existing HSAIL module to an existing HSAIL program.
 *
 * @details Adds an existing HSAIL module to an existing HSAIL program. An
 * HSAIL module is the unit of HSAIL generation, and can contain multiple
 * symbol declarations and definitions. An HSAIL module can be added to zero
 * or more HSAIL programs. Distinct instances of the symbols it defines are
 * created within each program, and symbol declarations are only linked to
 * the definitions provided by other modules in the same program. The same
 * HSAIL module can be added to multiple HSAIL programs, which allows multiple
 * instances of the same kernel and indirect functions that reference distinct
 * allocations of global segment variables. The same HSAIL module cannot be
 * added to the same HSAIL program more than once. The machine model and
 * profile of the HSAIL module that is being added has to match the machine
 * model and profile of the HSAIL program it is added to. HSAIL modules and
 * their handles can be queried from the program using several query
 * operations.
 *
 * @param[in] program HSAIL program to add HSAIL module to.
 *
 * @param[in] brig_module HSAIL module to add to the HSAIL program.
 *
 * @param[out] module The handle for the @a brig_module.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and the module is added successfully.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If the @a program is not a valid
 * HSAIL program. If the @a brig_module is not a valid HSAIL module. If the
 * machine model and/or profile of the @a brig_module do not match the
 * machine model and/or profile @a program.
 *
 * @retval ::HSA_STATUS_ERROR_OUT_OF_RESOURCES If there is a failure to
 * allocate resources required for module addition.
 *
 * @retval ::HSA_EXT_STATUS_INFO_ALREADY_INITIALIZED If the @a brig_module is
 * already added to the HSAIL program. No error is returned, just an info
 * status is used to indicate invalid options.
 */
hsa_status_t HSA_API hsa_ext_add_module(
  hsa_ext_program_handle_t program,
  hsa_ext_brig_module_t *brig_module,
  hsa_ext_brig_module_handle_t *module);

/**
 * @brief Finalizes provided HSAIL program.
 *
 * @details Finalizes provided HSAIL program. The HSA runtime finalizer
 * can be used to generate code for kernels and indirect functions from a
 * specific program for a specific HSA component. A kernel can only be
 * finalized once per program per agent. An indirect function can only
 * finalized once per program per agent per call convention. Only code for
 * HSA components specified when the program was created can be requested. The
 * program must contain a definition for the requested kernels and indirect
 * functions amongst the modules that have been added to the program. The
 * modules of the program must collectively define all variables, fbarriers,
 * kernels and functions referenced by operations in the code block. In
 * addition, the caller of this function can specify control directives as
 * an input argument, which will be passed to the finalizer. These control
 * directives can be used for low-level performance tuning, for more
 * information on control directives see HSA Programmer's Reference Manual.
 *
 * @param[in] program HSAIL program to be finalized.
 *
 * @param[in] agent Specific HSA component(s) to finalize program for.
 *
 * @param[in] finalization_request_count The number of kernels and indirect
 * functions that are requested to be finalized.
 *
 * @param[in] finalization_request_list List of kernels and indirect functions
 * that are requested to be finalized.
 *
 * @param[in] control_directives The control directives that can be specified to
 * influence how the finalizer generates code. If NULL then no control
 * directives are used. If this call is successful and control_directives is not
 * NULL, then the resulting hsa_ext_code_descriptor_t object will have control
 * directives which were used by the finalizer.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message.
 *
 * @param[in] optimization_level An implementation defined value that control
 * the level of optimization performed by the finalizer. For more information
 * see HSA Programmer's Reference Manual.
 *
 * @param[in] options Implementation defined options that can be passed to
 * the finalizer. For more information HSA Programmer's Reference Manual.
 *
 * @param[in] debug_information The flag for including/excluding the debug
 * information for. 0 - exclude debug information, 1 - include debug
 * information.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and the requested list of kernels/functions is finalized.
 *
 * @retval ::HSA_EXT_STATUS_ERROR_DIRECTIVE_MISMATCH If the directive in the
 * control directive structure and in the HSAIL kernel mismatch or if the same
 * directive is used with a different value in one of the functions used by
 * this kernel. The @a error_message_callback can be used to get the string
 * representation of the error.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If @a agent is NULL or invalid
 * (if one of the specified HSA components is not the part of the HSAIL
 * program). If the @a program is not a valid HSAIL program. If
 * @a finalization_request_list is NULL or invalid.
 * If @a finalization_request_count is 0. The @a error_message_callback can
 * be used to get the string representation of the error.
 *
 * @retval ::HSA_STATUS_ERROR_OUT_OF_RESOURCES If there is a failure to
 * allocate resources required for finalization. The @a error_message_callback
 * can be used to get the string representation of the error.
 *
 * @retval ::HSA_EXT_STATUS_INFO_UNRECOGNIZED_OPTIONS If the @a options or
 * @a optimization_level are not recognized. No error is returned, just an
 * info status is used to indicate invalid options.
 */
hsa_status_t HSA_API hsa_ext_finalize_program(
  hsa_ext_program_handle_t program,
  hsa_agent_t agent,
  size_t finalization_request_count,
  hsa_ext_finalization_request_t *finalization_request_list,
  hsa_ext_control_directives_t *control_directives,
  hsa_ext_error_message_callback_t error_message_callback,
  uint8_t optimization_level,
  const char *options,
  int debug_information);

/**
 * @brief Queries HSA component's id for specified HSA component contained in
 * specified HSAIL program.
 *
 * @param[in] program HSAIL program to query HSA component's id from.
 *
 * @param[in] agent HSA component for which the id is queried.
 *
 * @param[out] program_agent_id HSA component's id contained in specified
 * HSAIL program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and HSA component's id is queried.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program or
 * @a agent is not valid. If @a program_agent_id is NULL.
 */
hsa_status_t HSA_API hsa_ext_query_program_agent_id(
  hsa_ext_program_handle_t program,
  hsa_agent_t agent,
  hsa_ext_program_agent_id_t *program_agent_id);

/**
 * @brief Queries the number of HSA components contained in specified
 * HSAIL program.
 *
 * @param[in] program HSAIL program to query number of HSA components from.
 *
 * @param[out] program_agent_count Number of HSA components contained in
 * specified HSAIL program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and number of HSA components in the HSAIL program is queried.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * not valid. If @a program_agent_count is NULL.
 */
hsa_status_t HSA_API hsa_ext_query_program_agent_count(
  hsa_ext_program_handle_t program,
  uint32_t *program_agent_count);

/**
 * @brief Queries specified number of HSA components contained in specified
 * HSAIL program.
 *
 * @param[in] program HSAIL program to query HSA agents from.
 *
 * @param[in] program_agent_count Number of HSA agents to query.
 *
 * @param[out] agents HSA agents contained in specified HSAIL program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and HSA agents contained in the HSAIL program are queried.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * invalid.
 */
hsa_status_t HSA_API hsa_ext_query_program_agents(
  hsa_ext_program_handle_t program,
  uint32_t program_agent_count,
  hsa_agent_t *agents);

/**
 * @brief Queries the number of HSAIL modules contained in the HSAIL program.
 *
 * @param[in] program HSAIL program to query number of HSAIL modules from.
 *
 * @param[out] program_module_count Number of HSAIL modules in specified HSAIL
 * program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and the number of HSAIL modules contained in the HSAIL program is queried.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * invalid. If @a program_module_count is NULL.
 */
hsa_status_t HSA_API hsa_ext_query_program_module_count(
  hsa_ext_program_handle_t program,
  uint32_t *program_module_count);

/**
 * @brief Queries specified number of HSAIL module handles contained in
 * specified HSAIL program.
 *
 * @param[in] program HSAIL program to query HSAIL module handles from.
 *
 * @param[in] program_module_count Number of HSAIL module handles to query.
 *
 * @param[out] modules HSAIL module handles in specified HSAIL program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and HSAIL module handles contained in the HSAIL program are queried.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * invalid. If @a modules is NULL.
 */
hsa_status_t HSA_API hsa_ext_query_program_modules(
  hsa_ext_program_handle_t program,
  uint32_t program_module_count,
  hsa_ext_brig_module_handle_t *modules);

/**
 * @brief Queries HSAIL module with specified handle that contained in
 * specified HSAIL program.
 *
 * @param[in] program HSAIL program to query HSAIL modules from.
 *
 * @param[in] module HSAIL module handle for which to query the HSAIL module.
 *
 * @param[out] brig_module HSAIL module contained in specified HSAIL program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and HSAIL module contained in the HSAIL program is queried.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * invalid, or @a module is invalid.
 */
hsa_status_t HSA_API hsa_ext_query_program_brig_module(
  hsa_ext_program_handle_t program,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_module_t **brig_module);

/**
 * @brief Queries call convention IDs used for a specified HSA agent of a
 * specified HSAIL program.
 *
 * @param[in] program HSAIL program to query call convention IDs from.
 *
 * @param[in] agent HSA agent to query call convention IDs for.
 *
 * @param[out] first_call_convention_id Set of call convention IDs for
 * specified HSA agent of a specified HSAIL program.
 *
 * @param[out] call_convention_count Number of call convention IDs
 * available for specified HSA agent of a specified program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and call convention IDs contained in the HSAIL program are queried.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * not valid. If @a agent is not valid or NULL. If @a first_call_convention_id
 * is NULL. If @a call_convention_count is NULL.
 */
hsa_status_t HSA_API hsa_ext_query_call_convention(
  hsa_ext_program_handle_t program,
  hsa_agent_t agent,
  hsa_ext_program_call_convention_id32_t *first_call_convention_id,
  uint32_t *call_convention_count);

/**
 * @brief Queries the definition of a module scope variable/fbarrier or
 * kernel/function for a specified HSAIL program.
 *
 * @param[in] program HSAIL program to query symbol definition from.
 *
 * @param[in] module HSAIL module to query symbol definition from.
 *
 * @param[in] symbol Offset to query symbol definition from.
 *
 * @param[out] definition_module Queried HSAIL module handle.
 *
 * @param[out] definition_module_brig Queried HSAIL module.
 *
 * @param[out] definition_symbol Queried symbol.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and symbol definition contained in the HSAIL program is queried.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * not valid.
 */
hsa_status_t HSA_API hsa_ext_query_symbol_definition(
  hsa_ext_program_handle_t program,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  hsa_ext_brig_module_handle_t *definition_module,
  hsa_ext_brig_module_t **definition_module_brig,
  hsa_ext_brig_code_section_offset32_t *definition_symbol);

/**
 * @brief Defines global variable address in specified HSAIL program. Allows
 * direct access to host variables from HSAIL.
 *
 * @param[in] program HSAIL program to define global variable address for.
 *
 * @param[in] module HSAIL module to define global variable address for.
 *
 * @param[in] symbol Offset in the HSAIL module to put the address on.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message.
 *
 * @param[in] address Address to define in HSAIL program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and specified global variable address is defined in specified HSAIL program.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * not valid. If @a module is not valid. If @a address is NULL.
 */
hsa_status_t HSA_API hsa_ext_define_program_allocation_global_variable_address(
  hsa_ext_program_handle_t program,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  hsa_ext_error_message_callback_t error_message_callback,
  void *address);

/**
 * @brief Queries global variable address from specified HSAIL program. Allows
 * host program to directly access variables.
 *
 * @param[in] program HSAIL program to query global variable address from.
 *
 * @param[in] module HSAIL module to query global variable address from.
 *
 * @param[in] symbol Offset in the HSAIL module to get the address from.
 *
 * @param[out] address Queried address.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and the global variable address is queried from specified HSAIL program.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * invalid, or @a module is invalid.
 */
hsa_status_t HSA_API hsa_ext_query_program_allocation_global_variable_address(
  hsa_ext_program_handle_t program,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  void** address);

/**
 * @brief Defines global variable address for specified HSA agent in specified
 * HSAIL program. Allows direct access to host variables from HSAIL.
 *
 * @param[in] program HSAIL program to define global variable address for.
 *
 * @param[in] agent HSA agent to define global variable address for.
 *
 * @param[in] module HSAIL module to define global variable address for.
 *
 * @param[in] symbol Offset in the HSAIL module to put the address on.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message.
 *
 * @param[in] address Address to define for HSA agent in HSAIL program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and specified global variable address is defined for specified HSA agent in
 * specified HSAIL program.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * not valid. If @a agent is NULL or not valid If @a module is not valid.
 * If @a address is NULL.
 */
hsa_status_t HSA_API hsa_ext_define_agent_allocation_global_variable_address(
  hsa_ext_program_handle_t program,
  hsa_agent_t agent,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  hsa_ext_error_message_callback_t error_message_callback,
  void *address);

/**
 * @brief Queries global variable address for specified HSA agent from
 * specified HSAIL program. Allows host program to directly access variables.
 *
 * @param[in] program HSAIL program to query global variable address from.
 *
 * @param[in] agent HSA agent to query global variable address from.
 *
 * @param[in] module HSAIL module to query global variable address from.
 *
 * @param[in] symbol Offset in the HSAIL module to get the address from.
 *
 * @param[out] address Queried address.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and the global variable address is queried from specified HSAIL program.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * not valid. If @a agent is NULL or not valid If @a module is not valid.
 * If @a address is NULL.
 */
hsa_status_t HSA_API hsa_ext_query_agent_global_variable_address(
  hsa_ext_program_handle_t program,
  hsa_agent_t agent,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  void** address);

/**
 * @brief Defines readonly variable address for specified HSA agent in
 * specified HSAIL program. Allows direct access to host variables from HSAIL.
 *
 * @param[in] program HSAIL program to define readonly variable address for.
 *
 * @param[in] agent HSA agent to define readonly variable address for.
 *
 * @param[in] module HSAIL module to define readonly variable address for.
 *
 * @param[in] symbol Offset in the HSAIL module to put the address on.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message.
 *
 * @param[in] address Address to define for HSA agent in HSAIL program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and specified readonly variable address is defined for specified HSA agent
 * in specified HSAIL program.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * not valid. If @a agent is NULL or not valid If @a module is not valid.
 * If @a address is NULL.
 */
hsa_status_t HSA_API hsa_ext_define_readonly_variable_address(
  hsa_ext_program_handle_t program,
  hsa_agent_t agent,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  hsa_ext_error_message_callback_t error_message_callback,
  void* address);

/**
 * @brief Queries readonly variable address for specified HSA agent from
 * specified HSAIL program. Allows host program to directly access variables.
 *
 * @param[in] program HSAIL program to query readonly variable address from.
 *
 * @param[in] agent HSA agent to query readonly variable address from.
 *
 * @param[in] module HSAIL module to query readonly variable address from.
 *
 * @param[in] symbol Offset in the HSAIL module to get the address from.
 *
 * @param[out] address Queried address.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and the readonly variable address is queried from specified HSAIL program.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * not valid. If @a agent is NULL or not valid If @a module is not valid.
 * If @a address is NULL.
 */
hsa_status_t HSA_API hsa_ext_query_readonly_variable_address(
  hsa_ext_program_handle_t program,
  hsa_agent_t agent,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  void** address);

/**
 * @brief Queries kernel descriptor address from specified HSAIL program.
 * Needed to create a dispatch packet.
 *
 * @param[in] program HSAIL program to query kernel descriptor address from.
 *
 * @param[in] module HSAIL module to query kernel descriptor address from.
 *
 * @param[in] symbol Offset in the HSAIL module to get the address from.
 *
 * @param[out] kernel_descriptor The address of the kernel descriptor for the
 * requested kernel, which is an array of ::hsa_ext_code_descriptor_t
 * indexed by ::hsa_ext_program_agent_id_t.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and the kernel descriptor address is queried from specified HSAIL program.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * invalid, or @a module is invalid.
 */
hsa_status_t HSA_API hsa_ext_query_kernel_descriptor_address(
  hsa_ext_program_handle_t program,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  hsa_ext_code_descriptor_t** kernel_descriptor);

/**
 * @brief Queries indirect function descriptor address from specified HSAIL
 * program. Allows host program to perform indirect function table variable
 * initialization.
 *
 * @param[in] program HSAIL program to query indirect function descriptor
 * address from.
 *
 * @param[in] module HSAIL module to query indirect function descriptor address
 * from.
 *
 * @param[in] symbol Offset in the HSAIL module to get the address from.
 *
 * @param[out] indirect_function_descriptor The address of the indirect
 * function descriptor for the requested indirect function, which is an array
 * of ::hsa_ext_code_descriptor_t indexed by
 * ::hsa_ext_program_call_convention_id32_t.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and the indirect function descriptor address is queried from specified HSAIL
 * program.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If provided @a program is
 * invalid, or @a module is invalid.
 */
hsa_status_t HSA_API hsa_ext_query_indirect_function_descriptor_address(
  hsa_ext_program_handle_t program,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_brig_code_section_offset32_t symbol,
  hsa_ext_code_descriptor_t** indirect_function_descriptor);

/**
 * @brief Validates HSAIL program with specified HSAIL program handle. Checks
 * if all declarations and definitions match, if there is at most one
 * definition. The caller decides when to call validation routines. For
 * example, it can be done in the debug mode.
 *
 * @param[in] program HSAIL program to validate.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and specified HSAIL program is a valid program.
 *
 * @retval ::HSA_STATUS_ERROR If specified HSAIL program is not valid, refer to
 * the error callback function to get string representation of the failure.
 */
hsa_status_t HSA_API hsa_ext_validate_program(
  hsa_ext_program_handle_t program,
  hsa_ext_error_message_callback_t error_message_callback);

/**
 * @brief Validates specified HSAIL module with specified HSAIL module handle
 * for specified HSAIL program. Checks if BRIG for specified module is legal:
 * operation operand type rules, etc. For more information about BRIG see HSA
 * Programmer's Reference Manual. The caller decides when to call validation
 * routines. For example, it can be done in the debug mode.
 *
 * @param[in] program HSAIL program to validate HSAIL module in.
 *
 * @param[in] module HSAIL module handle to validate.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and specified HSAIL module is a valid module..
 *
 * @retval ::HSA_STATUS_ERROR If the module is not valid, refer to the error
 * callback function to get string representation of the failure.
 */
hsa_status_t HSA_API hsa_ext_validate_program_module(
  hsa_ext_program_handle_t program,
  hsa_ext_brig_module_handle_t module,
  hsa_ext_error_message_callback_t error_message_callback);

/**
 * @brief Serializes specified HSAIL program. Used for offline compilation.
 *
 * @param[in] caller Opaque pointer to the caller of this function.
 *
 * @param[in] program HSAIL program to be serialized.
 *
 * @param[in] alloc_serialize_data_callback Callback function for memory
 * allocation.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message (if any).
 *
 * @param[in] debug_information The flag for including/excluding the debug
 * information for @a finalization. 0 - exclude debug information, 1
 * - include debug information.
 *
 * @param[out] serialized_object Pointer to the serialized object.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and specified program is serialized.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If @a program is not a valid
 * program.
 *
 * @retval ::HSA_STATUS_ERROR_OUT_OF_RESOURCES If there is a failure to
 * allocate resources required for serialization. The @a error_message_callback
 * can be used to get the string representation of the error.
 */
hsa_status_t HSA_API hsa_ext_serialize_program(
  hsa_runtime_caller_t caller,
  hsa_ext_program_handle_t program,
  hsa_runtime_alloc_data_callback_t alloc_serialize_data_callback,
  hsa_ext_error_message_callback_t error_message_callback,
  int debug_information,
  void *serialized_object);

/**
 * @brief Callback function to get program's address of global segment
 * variables, kernel table variable, indirect function table variable based
 * on the symbolic name.
 */
typedef hsa_status_t (*hsa_ext_program_allocation_symbol_address_t)(
  hsa_runtime_caller_t caller,
  const char *name,
  uint64_t *symbol_adress);

/**
 * @brief Callback function to get agents's address of global segment
 * variables, kernel table variable, indirect function table variable based
 * on the symbolic name.
 */
typedef hsa_status_t (*hsa_ext_agent_allocation_symbol_address_t)(
  hsa_runtime_caller_t caller,
  hsa_agent_t agent,
  const char *name,
  uint64_t *symbol_adress);

/**
 * @brief Deserializes the HSAIL program from a given serialized object. Used
 * for offline compilation. Includes callback functions, where callback
 * functions take symbolic name, this allows symbols defined by application
 * to be relocated.
 *
 * @param[in] caller Opaque pointer to the caller of this function.
 *
 * @param[in] serialized_object Serialized HSAIL program.
 *
 * @param[in] program_allocation_symbol_address Callback function to get
 * program's address of global segment variables, kernel table variable,
 * indirect function table variable based on the symbolic name. Allows symbols
 * defined by application to be relocated.
 *
 * @param[in] agent_allocation_symbol_address Callback function to get agent's
 * address of global segment variables, kernel table variable, indirect
 * function table variable based on the symbolic name. Allows symbols defined
 * by application to be relocated.
 *
 * @param[in] error_message_callback Callback function to get the string
 * representation of the error message.
 *
 * @param[in] debug_information The flag for including/excluding the debug
 * information for @a finalization. 0 - exclude debug information, 1 - include
 * debug information.
 *
 * @param[out] program Deserialized HSAIL program.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully,
 * and HSAIL program is deserialized.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT If @a serialized_object is
 * either NULL, or is not valid, or the size is 0.
 *
 * @retval ::HSA_STATUS_ERROR_OUT_OF_RESOURCES If there is a failure to
 * allocate resources required for deserialization. The
 * @a error_message_callback can be used to get the string representation
 * of the error.
 */
hsa_status_t HSA_API hsa_ext_deserialize_program(
  hsa_runtime_caller_t caller,
  void *serialized_object,
  hsa_ext_program_allocation_symbol_address_t program_allocation_symbol_address,
  hsa_ext_agent_allocation_symbol_address_t agent_allocation_symbol_address,
  hsa_ext_error_message_callback_t error_message_callback,
  int debug_information,
  hsa_ext_program_handle_t **program);

#ifdef __cplusplus
} // extern "C" block
#endif // __cplusplus

#endif // HSA_EXT_FINALIZE_H

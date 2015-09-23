////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2014 ADVANCED MICRO DEVICES, INC.
//
// AMD is granting you permission to use this software and documentation (if
// any) (collectively, the "Materials") pursuant to the terms and conditions of
// the Software License Agreement included with the Materials. If you do not
// have a copy of the Software License Agreement, contact your AMD
// representative for a copy.
//
// You agree that you will not reverse engineer or decompile the Materials, in
// whole or in part, except as allowed by applicable law.
//
// WARRANTY DISCLAIMER: THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND. AMD DISCLAIMS ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY,
// INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE, NON - INFRINGEMENT, THAT THE
// SOFTWARE WILL RUN UNINTERRUPTED OR ERROR - FREE OR WARRANTIES ARISING FROM
// CUSTOM OF TRADE OR COURSE OF USAGE. THE ENTIRE RISK ASSOCIATED WITH THE USE
// OF THE SOFTWARE IS ASSUMED BY YOU. Some jurisdictions do not allow the
// exclusion of implied warranties, so the above exclusion may not apply to You.
//
// LIMITATION OF LIABILITY AND INDEMNIFICATION: AMD AND ITS LICENSORS WILL NOT,
// UNDER ANY CIRCUMSTANCES BE LIABLE TO YOU FOR ANY PUNITIVE, DIRECT,
// INCIDENTAL, INDIRECT, SPECIAL OR CONSEQUENTIAL DAMAGES ARISING FROM USE OF
// THE SOFTWARE OR THIS AGREEMENT EVEN IF AMD AND ITS LICENSORS HAVE BEEN
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. In no event shall AMD's total
// liability to You for all damages, losses, and causes of action (whether in
// contract, tort (including negligence) or otherwise) exceed the amount of $100
// USD. You agree to defend, indemnify and hold harmless AMD and its licensors,
// and any of their directors, officers, employees, affiliates or agents from
// and against any and all loss, damage, liability and other expenses (including
// reasonable attorneys' fees), resulting from Your use of the Software or
// violation of the terms and conditions of this Agreement.
//
// U.S.GOVERNMENT RESTRICTED RIGHTS: The Materials are provided with
// "RESTRICTED RIGHTS." Use, duplication, or disclosure by the Government is
// subject to the restrictions as set forth in FAR 52.227 - 14 and DFAR252.227 -
// 7013, et seq., or its successor. Use of the Materials by the Government
// constitutes acknowledgement of AMD's proprietary rights in them.
//
// EXPORT RESTRICTIONS: The Materials may be subject to export restrictions as
//                      stated in the Software License Agreement.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef AMD_HSA_QUEUE_H
#define AMD_HSA_QUEUE_H

#include "amd_hsa_common.h"
#include "hsa.h"

// AMD Queue Properties.
typedef uint32_t amd_queue_properties32_t;
enum amd_queue_properties_t {
  AMD_HSA_BITS_CREATE_ENUM_ENTRIES(AMD_QUEUE_PROPERTIES_ENABLE_TRAP_HANDLER, 0, 1),
  AMD_HSA_BITS_CREATE_ENUM_ENTRIES(AMD_QUEUE_PROPERTIES_IS_PTR64, 1, 1),
  AMD_HSA_BITS_CREATE_ENUM_ENTRIES(AMD_QUEUE_PROPERTIES_ENABLE_TRAP_HANDLER_DEBUG_SGPRS, 2, 1),
  AMD_HSA_BITS_CREATE_ENUM_ENTRIES(AMD_QUEUE_PROPERTIES_ENABLE_PROFILING, 3, 1),
  AMD_HSA_BITS_CREATE_ENUM_ENTRIES(AMD_QUEUE_PROPERTIES_RESERVED1, 4, 28)
};

// AMD Queue.
#define AMD_QUEUE_ALIGN_BYTES 64
#define AMD_QUEUE_ALIGN __ALIGNED__(AMD_QUEUE_ALIGN_BYTES)
typedef AMD_QUEUE_ALIGN struct amd_queue_s {
  hsa_queue_t hsa_queue;
  uint32_t reserved1[4];
  volatile uint64_t write_dispatch_id;
  uint32_t group_segment_aperture_base_hi;
  uint32_t private_segment_aperture_base_hi;
  uint32_t max_cu_id;
  uint32_t max_wave_id;
  volatile uint64_t max_legacy_doorbell_dispatch_id_plus_1;
  volatile uint32_t legacy_doorbell_lock;
  uint32_t reserved2[9];
  volatile uint64_t read_dispatch_id;
  uint32_t read_dispatch_id_field_base_byte_offset;
  uint32_t compute_tmpring_size;
  uint32_t scratch_resource_descriptor[4];
  uint64_t scratch_backing_memory_location;
  uint64_t scratch_backing_memory_byte_size;
  uint32_t scratch_workitem_byte_size;
  amd_queue_properties32_t queue_properties;
  uint32_t reserved3[2];
  hsa_signal_t queue_inactive_signal;
  uint32_t reserved4[14];
} amd_queue_t;

#endif // AMD_HSA_QUEUE_H

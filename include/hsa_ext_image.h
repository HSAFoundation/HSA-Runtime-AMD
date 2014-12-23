////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2014 ADVANCED MICRO DEVICES, INC.
//
// AMD is granting you permission to use this software and documentation(if any)
// (collectively, the "Materials") pursuant to the terms and conditions of the
// Software License Agreement included with the Materials.If you do not have a
// copy of the Software License Agreement, contact your AMD representative for a
// copy.
//
// You agree that you will not reverse engineer or decompile the Materials, in
// whole or in part, except as allowed by applicable law.
//
// WARRANTY DISCLAIMER : THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND.AMD DISCLAIMS ALL WARRANTIES, EXPRESS, IMPLIED, OR STATUTORY,
// INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE, NON - INFRINGEMENT, THAT THE
// SOFTWARE WILL RUN UNINTERRUPTED OR ERROR - FREE OR WARRANTIES ARISING FROM
// CUSTOM OF TRADE OR COURSE OF USAGE.THE ENTIRE RISK ASSOCIATED WITH THE USE OF
// THE SOFTWARE IS ASSUMED BY YOU.Some jurisdictions do not allow the exclusion
// of implied warranties, so the above exclusion may not apply to You.
//
// LIMITATION OF LIABILITY AND INDEMNIFICATION : AMD AND ITS LICENSORS WILL NOT,
// UNDER ANY CIRCUMSTANCES BE LIABLE TO YOU FOR ANY PUNITIVE, DIRECT,
// INCIDENTAL, INDIRECT, SPECIAL OR CONSEQUENTIAL DAMAGES ARISING FROM USE OF
// THE SOFTWARE OR THIS AGREEMENT EVEN IF AMD AND ITS LICENSORS HAVE BEEN
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.In no event shall AMD's total
// liability to You for all damages, losses, and causes of action (whether in
// contract, tort (including negligence) or otherwise) exceed the amount of $100
// USD.  You agree to defend, indemnify and hold harmless AMD and its licensors,
// and any of their directors, officers, employees, affiliates or agents from
// and against any and all loss, damage, liability and other expenses (including
// reasonable attorneys' fees), resulting from Your use of the Software or
// violation of the terms and conditions of this Agreement.
//
// U.S.GOVERNMENT RESTRICTED RIGHTS : The Materials are provided with
// "RESTRICTED RIGHTS." Use, duplication, or disclosure by the Government is
// subject to the restrictions as set forth in FAR 52.227 - 14 and DFAR252.227 -
// 7013, et seq., or its successor.Use of the Materials by the Government
// constitutes acknowledgement of AMD's proprietary rights in them.
//
// EXPORT RESTRICTIONS: The Materials may be subject to export restrictions as
//                      stated in the Software License Agreement.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef HSA_EXT_IMAGE_H
#define HSA_EXT_IMAGE_H

#include "hsa.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum hsa_ext_image_format_capability_s {
  HSA_EXT_IMAGE_FORMAT_NOT_SUPPORTED = 0x0,
  HSA_EXT_IMAGE_FORMAT_READ_ONLY = 0x1,
  HSA_EXT_IMAGE_FORMAT_WRITE_ONLY = 0x2,
  HSA_EXT_IMAGE_FORMAT_READ_WRITE = 0x4,
  HSA_EXT_IMAGE_FORMAT_READ_MODIFY_WRITE = 0x8,
  HSA_EXT_IMAGE_FORMAT_ACCESS_INVARIANT_IMAGE_DATA = 0x10
} hsa_ext_image_format_capability_t;

typedef enum hsa_ext_image_access_permission_s {
  HSA_EXT_IMAGE_ACCESS_PERMISSION_READ_ONLY,
  HSA_EXT_IMAGE_ACCESS_PERMISSION_WRITE_ONLY,
  HSA_EXT_IMAGE_ACCESS_PERMISSION_READ_WRITE
} hsa_ext_image_access_permission_t;

typedef enum hsa_ext_image_geometry_s {
  HSA_EXT_IMAGE_GEOMETRY_1D = 0,
  HSA_EXT_IMAGE_GEOMETRY_2D = 1,
  HSA_EXT_IMAGE_GEOMETRY_3D = 2,
  HSA_EXT_IMAGE_GEOMETRY_1DA = 3,
  HSA_EXT_IMAGE_GEOMETRY_2DA = 4,
  HSA_EXT_IMAGE_GEOMETRY_1DB = 5,
  HSA_EXT_IMAGE_GEOMETRY_2DDEPTH = 6,
  HSA_EXT_IMAGE_GEOMETRY_2DADEPTH = 7
} hsa_ext_image_geometry_t;

typedef enum hsa_ext_image_channel_type_s {
  HSA_EXT_IMAGE_CHANNEL_TYPE_SNORM_INT8 = 0,
  HSA_EXT_IMAGE_CHANNEL_TYPE_SNORM_INT16 = 1,
  HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_INT8 = 2,
  HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_INT16 = 3,
  HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_INT24 = 4,
  HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_SHORT_555 = 5,
  HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_SHORT_565 = 6,
  HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_SHORT_101010 = 7,
  HSA_EXT_IMAGE_CHANNEL_TYPE_SIGNED_INT8 = 8,
  HSA_EXT_IMAGE_CHANNEL_TYPE_SIGNED_INT16 = 9,
  HSA_EXT_IMAGE_CHANNEL_TYPE_SIGNED_INT32 = 10,
  HSA_EXT_IMAGE_CHANNEL_TYPE_UNSIGNED_INT8 = 11,
  HSA_EXT_IMAGE_CHANNEL_TYPE_UNSIGNED_INT16 = 12,
  HSA_EXT_IMAGE_CHANNEL_TYPE_UNSIGNED_INT32 = 13,
  HSA_EXT_IMAGE_CHANNEL_TYPE_HALF_FLOAT = 14,
  HSA_EXT_IMAGE_CHANNEL_TYPE_FLOAT = 15
} hsa_ext_image_channel_type_t;

typedef enum hsa_ext_image_channel_order_s {
  HSA_EXT_IMAGE_CHANNEL_ORDER_A = 0,
  HSA_EXT_IMAGE_CHANNEL_ORDER_R = 1,
  HSA_EXT_IMAGE_CHANNEL_ORDER_RX = 2,
  HSA_EXT_IMAGE_CHANNEL_ORDER_RG = 3,
  HSA_EXT_IMAGE_CHANNEL_ORDER_RGX = 4,
  HSA_EXT_IMAGE_CHANNEL_ORDER_RA = 5,
  HSA_EXT_IMAGE_CHANNEL_ORDER_RGB = 6,
  HSA_EXT_IMAGE_CHANNEL_ORDER_RGBX = 7,
  HSA_EXT_IMAGE_CHANNEL_ORDER_RGBA = 8,
  HSA_EXT_IMAGE_CHANNEL_ORDER_BGRA = 9,
  HSA_EXT_IMAGE_CHANNEL_ORDER_ARGB = 10,
  HSA_EXT_IMAGE_CHANNEL_ORDER_ABGR = 11,
  HSA_EXT_IMAGE_CHANNEL_ORDER_SRGB = 12,
  HSA_EXT_IMAGE_CHANNEL_ORDER_SRGBX = 13,
  HSA_EXT_IMAGE_CHANNEL_ORDER_SRGBA = 14,
  HSA_EXT_IMAGE_CHANNEL_ORDER_SBGRA = 15,
  HSA_EXT_IMAGE_CHANNEL_ORDER_INTENSITY = 16,
  HSA_EXT_IMAGE_CHANNEL_ORDER_LUMINANCE = 17,
  HSA_EXT_IMAGE_CHANNEL_ORDER_DEPTH = 18,
  HSA_EXT_IMAGE_CHANNEL_ORDER_DEPTH_STENCIL = 19
} hsa_ext_image_channel_order_t;

typedef enum hsa_ext_sampler_addressing_mode_s {
  HSA_EXT_SAMPLER_ADDRESSING_UNDEFINED = 0,
  HSA_EXT_SAMPLER_ADDRESSING_CLAMP_TO_EDGE = 1,
  HSA_EXT_SAMPLER_ADDRESSING_CLAMP_TO_BORDER = 2,
  HSA_EXT_SAMPLER_ADDRESSING_REPEAT = 3,
  HSA_EXT_SAMPLER_ADDRESSING_MIRRORED_REPEAT = 4
} hsa_ext_sampler_addressing_mode_t;

typedef enum hsa_ext_sampler_coordinate_mode_s {
  HSA_EXT_SAMPLER_COORD_NORMALIZED = 0,
  HSA_EXT_SAMPLER_COORD_UNNORMALIZED = 1
} hsa_ext_sampler_coordinate_mode_t;

typedef enum hsa_ext_sampler_filter_mode_s {
  HSA_EXT_SAMPLER_FILTER_NEAREST = 0,
  HSA_EXT_SAMPLER_FILTER_LINEAR = 1
} hsa_ext_sampler_filter_mode_t;

typedef struct hsa_ext_image_handle_s {
  uint64_t handle;
} hsa_ext_image_handle_t;

typedef struct hsa_ext_image_info_s {
  size_t image_size;
  size_t image_alignment;
} hsa_ext_image_info_t;

typedef struct hsa_ext_image_format_s {
  hsa_ext_image_channel_type_t channel_type;
  hsa_ext_image_channel_order_t channel_order;
} hsa_ext_image_format_t;

typedef struct hsa_ext_image_descriptor_s {
  hsa_ext_image_geometry_t geometry;
  size_t width;
  size_t height;
  size_t depth;
  size_t array_size;
  hsa_ext_image_format_t format;
} hsa_ext_image_descriptor_t;

typedef struct hsa_ext_image_range_s {
  uint32_t width;
  uint32_t height;
  uint32_t depth;
} hsa_ext_image_range_t;

typedef struct hsa_ext_image_region_s {
  hsa_dim3_t image_offset;
  hsa_ext_image_range_t image_range;
} hsa_ext_image_region_t;

typedef struct hsa_ext_sampler_handle_s {
  uint64_t handle;
} hsa_ext_sampler_handle_t;

typedef struct hsa_ext_sampler_descriptor_s {
  hsa_ext_sampler_coordinate_mode_t coordinate_mode;
  hsa_ext_sampler_filter_mode_t filter_mode;
  hsa_ext_sampler_addressing_mode_t address_mode;
} hsa_ext_sampler_descriptor_t;

hsa_status_t HSA_API hsa_ext_get_image_info_max_dim(hsa_agent_t component,
                                      hsa_agent_info_t attribute, void* value);

hsa_status_t HSA_API hsa_ext_image_get_format_capability(
    hsa_agent_t agent, const hsa_ext_image_format_t* image_format,
    hsa_ext_image_geometry_t image_geometry, uint32_t* capability_mask);

hsa_status_t HSA_API
    hsa_ext_image_get_info(hsa_agent_t agent,
                           const hsa_ext_image_descriptor_t* image_descriptor,
                           hsa_ext_image_access_permission_t access_permission,
                           hsa_ext_image_info_t* image_info);

hsa_status_t HSA_API hsa_ext_image_create_handle(
    hsa_agent_t agent, const hsa_ext_image_descriptor_t* image_descriptor,
    const void* image_data, hsa_ext_image_access_permission_t access_permission,
    hsa_ext_image_handle_t* image_handle);

hsa_status_t HSA_API
    hsa_ext_image_import(hsa_agent_t agent, const void* src_memory,
                         size_t src_row_pitch, size_t src_slice_pitch,
                         hsa_ext_image_handle_t dst_image_handle,
                         const hsa_ext_image_region_t* image_region,
                         const hsa_signal_t* completion_signal);

hsa_status_t HSA_API
    hsa_ext_image_export(hsa_agent_t agent,
                         hsa_ext_image_handle_t src_image_handle,
                         void* dst_memory, size_t dst_row_pitch,
                         size_t dst_slice_pitch,
                         const hsa_ext_image_region_t* image_region,
                         const hsa_signal_t* completion_signal);

hsa_status_t HSA_API
    hsa_ext_image_copy(hsa_agent_t agent,
                       hsa_ext_image_handle_t src_image_handle,
                       hsa_ext_image_handle_t dst_image_handle,
                       const hsa_ext_image_region_t* image_region,
                       const hsa_signal_t* completion_signal);

hsa_status_t HSA_API
    hsa_ext_image_clear(hsa_agent_t agent, hsa_ext_image_handle_t image_handle,
                        const float data[4],
                        const hsa_ext_image_region_t* image_region,
                        const hsa_signal_t* completion_signal);

hsa_status_t HSA_API hsa_ext_image_copy_split_offset(
    hsa_agent_t agent, hsa_ext_image_handle_t src_image_handle,
    hsa_ext_image_handle_t dst_image_handle, const hsa_dim3_t src_origin,
    const hsa_dim3_t dst_origin, const hsa_ext_image_range_t size,
    const hsa_signal_t* completion_signal);

hsa_status_t HSA_API
    hsa_ext_image_clear_generic_data(hsa_agent_t agent,
                                     hsa_ext_image_handle_t image_handle,
                                     const void* data,
                                     const hsa_ext_image_region_t* image_region,
                                     const hsa_signal_t* completion_signal);

hsa_status_t HSA_API
    hsa_ext_image_destroy_handle(hsa_agent_t agent,
                                 hsa_ext_image_handle_t* image_handle);

hsa_status_t HSA_API hsa_ext_sampler_create_handle(
    hsa_agent_t agent, const hsa_ext_sampler_descriptor_t* sampler_descriptor,
    hsa_ext_sampler_handle_t* sampler_handle);

hsa_status_t HSA_API
    hsa_ext_sampler_destroy_handle(hsa_agent_t agent,
                                   hsa_ext_sampler_handle_t* sampler_handle);

#ifdef __cplusplus
}  // end extern "C" block
#endif

#endif

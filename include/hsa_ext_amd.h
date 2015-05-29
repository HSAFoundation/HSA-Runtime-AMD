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

// HSA AMD extension.

#ifndef HSA_RUNTIME_EXT_AMD_H_
#define HSA_RUNTIME_EXT_AMD_H_

#include "hsa.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Agent attributes.
 */
typedef enum hsa_amd_agent_info_s {
  /**
   * Chip identifier. The type of this attribute is uint32_t.
   */
  HSA_AMD_AGENT_INFO_CHIP_ID = 0xA000,
  /**
   * Size of a cacheline in bytes. The type of this attribute is uint32_t.
   */
  HSA_AMD_AGENT_INFO_CACHELINE_SIZE = 0xA001,
  /**
   * The number of compute unit available in the agent. The type of this
   * attribute is uint32_t.
   */
  HSA_AMD_AGENT_INFO_COMPUTE_UNIT_COUNT = 0xA002,
  /**
   * The maximum clock frequency of the agent in MHz. The type of this
   * attribute is uint32_t.
   */
  HSA_AMD_AGENT_INFO_MAX_CLOCK_FREQUENCY = 0xA003,
  /**
   * Internal driver node identifier. The type of this attribute is uint32_t.
   */
  HSA_AMD_AGENT_INFO_DRIVER_NODE_ID = 0xA004,
  /**
   * Max number of watch points on memory address ranges to generate exception
   * events when the watched addresses are accessed.
   */
  HSA_AMD_AGENT_INFO_MAX_ADDRESS_WATCH_POINTS = 0xA005
} hsa_amd_agent_info_t;

/**
 * @brief Region attributes.
 */
typedef enum hsa_amd_region_info_s {
  /**
   * Determine if host can access the region. The type of this attribute
   * is bool.
   */
  HSA_AMD_REGION_INFO_HOST_ACCESSIBLE = 0xA000,
  /**
   * Base address of the region in flat address space.
   */
  HSA_AMD_REGION_INFO_BASE = 0xA001
} hsa_amd_region_info_t;

/**
 * @brief Coherency attributes of fine grain region.
 */
typedef enum hsa_amd_coherency_type_s {
  /**
   * Coherent region.
   */
  HSA_AMD_COHERENCY_TYPE_COHERENT = 0,
  /**
   * Non coherent region.
   */
  HSA_AMD_COHERENCY_TYPE_NONCOHERENT = 1
} hsa_amd_coherency_type_t;

/**
* @brief Get the coherency type of the fine grain region of an agent.
*
* @param[in] agent A valid agent.
*
* @param[out] type Pointer to a memory location where the HSA runtime will
* store the coherency type of the fine grain region.
*
* @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
*
* @retval ::HSA_STATUS_ERROR_NOT_INITIALIZED The HSA runtime has not been
* initialized.
*
* @retval ::HSA_STATUS_ERROR_INVALID_AGENT The agent is invalid.
*
* @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT @p type is NULL.
*/
hsa_status_t HSA_API hsa_amd_coherency_get_type(hsa_agent_t agent,
                                                hsa_amd_coherency_type_t* type);

/**
* @brief Set the coherency type of the fine grain region of an agent.
*
* @param[in] agent A valid agent.
*
* @param[in] type The coherency type to be set.
*
* @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
*
* @retval ::HSA_STATUS_ERROR_NOT_INITIALIZED The HSA runtime has not been
* initialized.
*
* @retval ::HSA_STATUS_ERROR_INVALID_AGENT The agent is invalid.
*
* @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT @p type is invalid.
*/
hsa_status_t HSA_API hsa_amd_coherency_set_type(hsa_agent_t agent,
                                                hsa_amd_coherency_type_t type);

/**
 * @brief Structure containing profiling dispatch time information.
 */
typedef struct hsa_amd_profiling_dispatch_time_s {
  /**
   * Profiling start time.
   */
  uint64_t start;
  /**
   * Profiling end time.
   */
  uint64_t end;
} hsa_amd_profiling_dispatch_time_t;

/**
* @brief Enable or disable profiling capability of a queue.
*
* @param[in] queue A valid queue.
*
* @param[in] enable 1 to enable profiling. 0 to disable profiling.
*
* @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
*
* @retval ::HSA_STATUS_ERROR_NOT_INITIALIZED The HSA runtime has not been
* initialized.
*
* @retval ::HSA_STATUS_ERROR_INVALID_QUEUE The queue is invalid.
*
* @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT @p queue is NULL.
*/
hsa_status_t HSA_API
    hsa_amd_profiling_set_profiler_enabled(hsa_queue_t* queue, int enable);

/**
* @brief Retrieve profiling dispatch time information.
*
* @param[in] agent A valid agent.
*
* @param[in] signal A valid signal associated with a dispatch.
*
* @param[out] time Profiling result.
*
* @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
*
* @retval ::HSA_STATUS_ERROR_NOT_INITIALIZED The HSA runtime has not been
* initialized.
*
* @retval ::HSA_STATUS_ERROR_INVALID_AGENT The agent is invalid.
*
* @retval ::HSA_STATUS_ERROR_INVALID_SIGNAL The signal is invalid.
*
* @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT @p time is NULL.
*/
hsa_status_t HSA_API hsa_amd_profiling_get_dispatch_time(
    hsa_agent_t agent, hsa_signal_t signal,
    hsa_amd_profiling_dispatch_time_t* time);

/**
 * @brief Create a user mode SDMA queue.
 *
 * @details This SDMA queue allows application to submit SDMA PM4 packets.
 * Application is responsible to allocate/free the queue buffer.
 *
 * @param[in] agent Agent where to create the queue.
 *
 * @param[in] buffer_size Size of the queue buffer. Must be multiple of a page
 * size.
 *
 * @param[in] buffer_addr Address of the queue buffer. Must be multiple of a
 * page size.
 *
 * @param[out] queue_id SDMA queue identifier.
 *
 * @param[out] read_ptr Read pointer.
 *
 * @param[out] write_ptr Write pointer.
 *
 * @param[out]doorbell Doorbell.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
 *
 * @retval ::HSA_STATUS_ERROR_NOT_INITIALIZED The HSA runtime has not been
 * initialized.
 *
 * @retval ::HSA_STATUS_ERROR_OUT_OF_RESOURCES There is failure to allocate
 * the resources required by the implementation.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_AGENT The agent is invalid.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_QUEUE_CREATION @p agent does not
 * support queues of the given type.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT @p buffer_size is not multiple
 * of a page size, @p buffer_addr is not multiple of a page size, @p queue_id
 * is NULL, @p read_ptr is NULL, @p write_ptr is NULL, @p doorbell is NULL.
 *
 */
hsa_status_t HSA_API
    hsa_amd_queue_sdma_create(hsa_agent_t agent, size_t buffer_size,
                              void* buffer_addr, uint64_t* queue_id,
                              uint32_t** read_ptr, uint32_t** write_ptr,
                              uint32_t** doorbell);

/**
 * @brief Destroy a user mode SDMA queue.
 *
 * @details It is the responsibility of the application to ensure that
 * all pending queue operations are finished if their results are required.
 * Application is also responsible to free the queue buffer.
 *
 * @param[in] queue_id SDMA queue identier returned by
 * hsa_amd_queue_create_sdma.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
 *
 * @retval ::HSA_STATUS_ERROR_NOT_INITIALIZED The HSA runtime has not been
 * initialized.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_QUEUE @p queue_id is invalid.
 *
 */
hsa_status_t HSA_API hsa_amd_queue_sdma_destroy(uint64_t queue_id);

/**
 * @brief Asyncronous signal handler function type.
 *
 * @details Type definition of callback function to be used with
 * hsa_amd_signal_async_handler. This callback is invoked if the associated
 * signal and condition are met. The callback receives the value of the signal
 * which satisfied the associated wait condition and a user provided value. If
 * the callback returns true then the callback will be called again if the
 * associated signal and condition are satisfied again. If the callback returns
 * false then it will not be called again.
 *
 * @param[in] value Contains the value of the signal observed by
 * hsa_amd_signal_async_handler which caused the signal handler to be invoked.
 *
 * @param[in] arg Contains the user provided value given when the signal handler
 * was registered with hsa_amd_signal_async_handler
 * 
 * @retval true resumes monitoring the signal with this handler (as if calling
 * hsa_amd_signal_async_handler again with identical parameters)
 *
 * @retval false stops monitoring the signal with this handler (handler will
 * not be called again for this signal)
 *
 */
typedef bool (*hsa_amd_signal_handler)(hsa_signal_value_t value, void* arg);

/**
 * @brief Register asynchronous signal handler function.
 *
 * @details Allows registering a callback function and user provided value with
 * a signal and wait condition. The callback will be invoked if the associated
 * signal and wait condition are satisfied. Callbacks will be invoked serially
 * but in an arbitrary order so callbacks should be independent of each other.
 * After being invoked a callback may continue to wait for its associated signal
 * and condition and, possibly, be invoked again. Or the callback may stop
 * waiting. If the callback returns true then it will continue waiting and may
 * be called again. If false then the callback will not wait again and will not
 * be called again for the associated signal and condition. It is possible to
 * register the same callback multiple times with the same or different signals
 * and/or conditions. Each registration of the callback will be treated entirely
 * independently.
 *
 * @param[in] signal hsa signal to be asynchronously monitored
 *
 * @param[in] cond condition value to monitor for
 *
 * @param[in] value signal value used in condition expression
 *
 * @param[in] handler asynchronous signal handler invoked when signal's
 * condition is met
 *
 * @param[in] arg user provided value which is provided to handler when handler
 * is invoked
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
 *
 * @retval ::HSA_STATUS_ERROR_NOT_INITIALIZED The HSA runtime has not been
 * initialized.
 * 
 * @retval ::HSA_STATUS_ERROR_INVALID_SIGNAL signal is not a valid hsa_signal_t
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_ARGUMENT handler is invalid (NULL)
 *
 * @retval ::HSA_STATUS_ERROR_OUT_OF_RESOURCES The HSA runtime is out of
 * resources or blocking signals are not supported by the HSA driver component.
 *
 */
hsa_status_t HSA_API
    hsa_amd_signal_async_handler(hsa_signal_t signal,
                                 hsa_signal_condition_t cond,
                                 hsa_signal_value_t value,
                                 hsa_amd_signal_handler handler, void* arg);

/**
 * @brief Wait for any signal-condition pair to be satisfied.
 *
 * @details Allows waiting for any of several signal and conditions pairs to be
 * satisfied. The function returns the index into the list of signals of the
 * first satisfying signal-condition pair. The value of the satisfying signal’s
 * value is returned in satisfying_value unless satisfying_value is NULL. This
 * function provides only relaxed memory semantics.
 */
uint32_t HSA_API
    hsa_amd_signal_wait_any(uint32_t signal_count, hsa_signal_t* signals,
                            hsa_signal_condition_t* conds,
                            hsa_signal_value_t* values, uint64_t timeout_hint,
                            hsa_wait_state_t wait_hint,
                            hsa_signal_value_t* satisfying_value);

/**
 * @brief Query image limits.
 *
 * @param[in] agent A valid agent.
 *
 * @param[in] attribute HSA image info attribute to query.
 *
 * @param[out] value Pointer to an application-allocated buffer where to store
 * the value of the attribute. If the buffer passed by the application is not
 * large enough to hold the value of @p attribute, the behavior is undefined.
 *
 * @retval ::HSA_STATUS_SUCCESS The function has been executed successfully.
 *
 * @retval ::HSA_STATUS_ERROR_NOT_INITIALIZED The HSA runtime has not been
 * initialized.
 *
 * @retval ::HSA_STATUS_ERROR_INVALID_QUEUE @p value is NULL or @p attribute <
 * HSA_EXT_AGENT_INFO_IMAGE_1D_MAX_ELEMENTS or @p attribute >
 * HSA_EXT_AGENT_INFO_IMAGE_ARRAY_MAX_LAYERS.
 *
 */
hsa_status_t HSA_API hsa_amd_image_get_info_max_dim(hsa_agent_t agent,
                                                    hsa_agent_info_t attribute,
                                                    void* value);

#ifdef __cplusplus
}  // end extern "C" block
#endif

#endif  // header guard

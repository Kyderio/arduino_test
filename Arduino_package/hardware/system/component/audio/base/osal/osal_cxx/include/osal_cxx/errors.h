/*
 * Copyright (c) 2021 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AMEBA_BASE_OSAL_OSAL_CXX_INCLUDE_OSAL_CXX_OSAL_CXX_ERRORS_H
#define AMEBA_BASE_OSAL_OSAL_CXX_INCLUDE_OSAL_CXX_OSAL_CXX_ERRORS_H

#include <sys/types.h>
#include <errno.h>

namespace ameba {

// use this type to return error codes
typedef int32_t res_t;

/*
 * Error codes.
 * All error codes are negative values.s
 */
enum {
    OK                  = 0,
    NO_ERROR            = 0,

    NO_MEMORY           = -12,  // -ENOMEM
    INVALID_OPERATION   = -88,  // -ENOSYS
    BAD_VALUE           = -22,  // -EINVAL
    NOT_FOUND           = -2,   // -ENOENT
    PERMISSION_DENIED   = -1,   // -EPERM
    NO_INIT             = -19,  // -ENODEV
    ALREADY_EXISTS      = -17,  // -EEXIST
    DEAD_OBJECT         = -32,  // -EPIPE
    BAD_INDEX           = -139, // -EOVERFLOW
    NOT_ENOUGH_DATA     = -61,  // -ENODATA
    WOULD_BLOCK         = -11,  // -EWOULDBLOCK
    TIMED_OUT           = -116, // -ETIMEDOUT
    UNKNOWN_TRANSACTION = -77,  // -EBADMSG,

    UNKNOWN_ERROR       = (-2147483647 - 1), // INT32_MIN value

    OPERATION_FAIL      = (UNKNOWN_ERROR + 1),
    NOT_SUPPORT         = (UNKNOWN_ERROR + 2),
};

}; // namespace ameba

#endif // AMEBA_BASE_OSAL_OSAL_CXX_INCLUDE_OSAL_CXX_OSAL_CXX_ERRORS_H

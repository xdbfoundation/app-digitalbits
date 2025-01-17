/*****************************************************************************
 *   Ledger DigitalBits  App.
 *   (c) 2022 Ledger SAS.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *****************************************************************************/

#include <stdint.h>  // uint*_t
#include <limits.h>  // UINT8_MAX
#include <assert.h>  // _Static_assert

#include "../io.h"
#include "../sw.h"
#include "../types.h"
#include "../settings.h"
#include "../common/buffer.h"

int handler_get_app_configuration() {
    PRINTF("handler_get_app_configuration invoked\n");

    _Static_assert(APP_VERSION_SIZE == 3, "Length of (MAJOR || MINOR || PATCH) must be 3!");
    _Static_assert(MAJOR_VERSION >= 0 && MAJOR_VERSION <= UINT8_MAX,
                   "MAJOR version must be between 0 and 255!");
    _Static_assert(MINOR_VERSION >= 0 && MINOR_VERSION <= UINT8_MAX,
                   "MINOR version must be between 0 and 255!");
    _Static_assert(PATCH_VERSION >= 0 && PATCH_VERSION <= UINT8_MAX,
                   "PATCH version must be between 0 and 255!");

    return io_send_response(
        &(const buffer_t){.ptr =
                              (uint8_t[APP_CONFIGURATION_SIZE + APP_VERSION_SIZE]){
                                  (uint8_t) HAS_SETTING(S_HASH_SIGNING_ENABLED),
                                  (uint8_t) MAJOR_VERSION,
                                  (uint8_t) MINOR_VERSION,
                                  (uint8_t) PATCH_VERSION},
                          .size = APP_CONFIGURATION_SIZE + APP_VERSION_SIZE,
                          .offset = 0},
        SW_OK);
}

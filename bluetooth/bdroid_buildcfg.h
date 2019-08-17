/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H

#if !defined(OS_GENERIC)
#undef PROPERTY_VALUE_MAX
#include <cutils/properties.h>
#include <string.h>

static inline const char* getBTDefaultName()
{
    // system/bt/osi/include/properties.h
    // #define PROPERTY_VALUE_MAX 92
    char device[92];
    property_get("ro.boot.hardware", device, "");

    if (!strcmp("maple", device)) {
        return "Xperia XZ Premium";
    }

    if (!strcmp("poplar", device)) {
        return "Xperia XZ1";
    }

    if (!strcmp("lilac", device)) {
        return "Xperia XZ1 Compact";
    }

    return "Xperia";
}

#define BTM_DEF_LOCAL_NAME getBTDefaultName()
#endif // OS_GENERIC

#undef PROPERTY_VALUE_MAX

// Wide-band speech support
#define BTM_WBS_INCLUDED TRUE
#define BTIF_HF_WBS_PREFERRED TRUE

// QCOM power management workaround
#define BT_CLEAN_TURN_ON_DISABLED TRUE

// Vendor extensions
#define BLE_VND_INCLUDED TRUE

#endif

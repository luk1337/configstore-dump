/*
 * Copyright (C) 2019 The LineageOS Project
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

#include <android/hardware/configstore/1.0/ISurfaceFlingerConfigs.h>
#include <android/hardware/configstore/1.1/ISurfaceFlingerConfigs.h>
#include <android/hardware/configstore/1.1/types.h>

#include <iostream>

using android::hardware::configstore::V1_0::OptionalBool;
using android::hardware::configstore::V1_0::OptionalInt32;
using android::hardware::configstore::V1_0::OptionalInt64;
using android::hardware::configstore::V1_0::OptionalString;
using android::hardware::configstore::V1_0::OptionalUInt32;
using android::hardware::configstore::V1_0::OptionalUInt64;
using android::hardware::configstore::V1_1::DisplayOrientation;
using android::hardware::configstore::V1_1::ISurfaceFlingerConfigs;
using android::hardware::configstore::V1_1::OptionalDisplayOrientation;
using android::hardware::Return;

using android::sp;

int main() {
    sp<ISurfaceFlingerConfigs> sfConfigs = ISurfaceFlingerConfigs::getService();

    sfConfigs->vsyncEventPhaseOffsetNs([](OptionalInt64 arg) {
        if (arg.specified) {
            std::cout << "VSYNC_EVENT_PHASE_OFFSET_NS := " << arg.value << std::endl;
        }
    });

    sfConfigs->vsyncSfEventPhaseOffsetNs([](OptionalInt64 arg) {
        if (arg.specified) {
            std::cout << "SF_VSYNC_EVENT_PHASE_OFFSET_NS := " << arg.value << std::endl;
        }
    });

    sfConfigs->useContextPriority([](OptionalBool arg) {
        if (arg.specified) {
            std::cout << "TARGET_USE_CONTEXT_PRIORITY := " << std::boolalpha << arg.value << std::endl;
        }
    });

    sfConfigs->hasWideColorDisplay([](OptionalBool arg) {
        if (arg.specified && arg.value) {
            std::cout << "TARGET_HAS_WIDE_COLOR_DISPLAY := " << std::boolalpha << arg.value << std::endl;
        }
    });

    sfConfigs->hasHDRDisplay([](OptionalBool arg) {
        if (arg.specified && arg.value) {
            std::cout << "TARGET_HAS_HDR_DISPLAY := " << std::boolalpha << arg.value << std::endl;
        }
    });

    sfConfigs->presentTimeOffsetFromVSyncNs([](OptionalInt64 arg) {
        if (arg.specified && arg.value != 0) {
            std::cout << "PRESENT_TIME_OFFSET_FROM_VSYNC_NS := " << arg.value << std::endl;
        }
    });

    sfConfigs->useHwcForRGBtoYUV([](OptionalBool arg) {
        if (arg.specified && arg.value) {
            std::cout << "TARGET_FORCE_HWC_FOR_VIRTUAL_DISPLAYS := true" << std::endl;
        }
    });

    sfConfigs->maxVirtualDisplaySize([](OptionalUInt64 arg) {
        if (arg.specified) {
            std::cout << "MAX_VIRTUAL_DISPLAY_DIMENSION := " << arg.value << std::endl;
        }
    });

    sfConfigs->hasSyncFramework([](OptionalBool arg) {
        if (arg.specified && !arg.value) {
            std::cout << "RUNNING_WITHOUT_SYNC_FRAMEWORK := true" << std::endl;
        }
    });

    sfConfigs->useVrFlinger([](OptionalBool arg) {
        if (arg.specified) {
            std::cout << "USE_VR_FLINGER := " << std::boolalpha << arg.value << std::endl;
        }
    });

    sfConfigs->maxFrameBufferAcquiredBuffers([](OptionalInt64 arg) {
        if (arg.specified) {
            std::cout << "NUM_FRAMEBUFFER_SURFACE_BUFFERS := " << arg.value << std::endl;
        }
    });

    sfConfigs->startGraphicsAllocatorService([](OptionalBool arg) {
        if (arg.specified && arg.value) {
            std::cout << "START_GRAPHICS_ALLOCATOR_SERVICE := true" << std::endl;
        }
    });

    sfConfigs->primaryDisplayOrientation([](OptionalDisplayOrientation arg) {
        if (arg.specified) {
            switch (arg.value) {
                case DisplayOrientation::ORIENTATION_0:
                    std::cout << "PRIMARY_DISPLAY_ORIENTATION := 0" << std::endl;
                    break;
                case DisplayOrientation::ORIENTATION_90:
                    std::cout << "PRIMARY_DISPLAY_ORIENTATION := 90" << std::endl;
                    break;
                case DisplayOrientation::ORIENTATION_180:
                    std::cout << "PRIMARY_DISPLAY_ORIENTATION := 180" << std::endl;
                    break;
                case DisplayOrientation::ORIENTATION_270:
                    std::cout << "PRIMARY_DISPLAY_ORIENTATION := 270" << std::endl;
                    break;
            }
        }
    });

    return 0;
}
/*
 * Copyright© 2021–2022 Beijing OSWare Technology Co., Ltd
 * This file contains confidential and proprietary information of
 * OSWare Technology Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HOS_CAMERA_BM2835_H
#define HOS_CAMERA_BM2835_H

#include "isensor.h"
#include "create_sensor_factory.h"
#include "device_manager_adapter.h"

namespace OHOS::Camera {
class Mx6s : public ISensor {
    DECLARE_SENSOR(Mx6s)
public:
    Mx6s();
    virtual ~Mx6s();
    void InitSensitivityRange(Camera::CameraMetadata& camera_meta_data);
    void InitAwbModes(Camera::CameraMetadata& camera_meta_data);
    void InitCompensationRange(Camera::CameraMetadata& camera_meta_data);
    void InitFpsTarget(Camera::CameraMetadata& camera_meta_data);
    void InitAvailableModes(Camera::CameraMetadata& camera_meta_data);
    void InitAntiBandingModes(Camera::CameraMetadata& camera_meta_data);
    void InitPhysicalSize(Camera::CameraMetadata& camera_meta_data);
    void Init(Camera::CameraMetadata& camera_meta_data);
};
} // namespace OHOS::Camera
#endif

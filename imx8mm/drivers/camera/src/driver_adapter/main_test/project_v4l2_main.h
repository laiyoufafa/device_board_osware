/*
 * Copyright (C) 2021–2022 Beijing OSWare Technology Co., Ltd
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

#ifndef HOS_CAMERA_PROJET_HARDWARE_H
#define HOS_CAMERA_PROJET_HARDWARE_H
#include <linux/videodev2.h>

namespace OHOS::Camera {
#define PREVIEW_PIXEL_FORMAT V4L2_PIX_FMT_YUYV
#define CAPTURE_PIXEL_FORMAT V4L2_PIX_FMT_YUYV
#define VIDEO_PIXEL_FORMAT   V4L2_PIX_FMT_YUYV

#define TEST_SENSOR_NAME     "mx6s-csi"

#define FB_DEV_PATH          "/dev/graphics/fb0"
} // namespace OHOS::Camera
#endif

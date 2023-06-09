/*
 * Copyright (C) 2021–2022 Beijing OSWare Technology Co., Ltd
 * This file contains confidential and proprietary information of
 * OSWare Technology Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "audio_dsp_base.h"
#include "audio_core.h"
#include "dsp_ops.h"
#include "audio_dsp_if.h"
#include "audio_driver_log.h"
#include "osal_io.h"

#define HDF_LOG_TAG dsp_adapter

struct DspData g_dspData = {
    .drvDspName = "dsp_service_0",
    .DspInit = DspDeviceInit,
    .Read = DspDeviceReadReg,
    .Write = DspDeviceWriteReg,
    .Decode = DspDecodeAudioStream,
    .Encode = DspEncodeAudioStream,
    .Equalizer = DspEqualizerActive,
};

struct AudioDaiOps g_dspDaiDeviceOps = {
    .Startup = DspDaiStartup,
    .HwParams = DspDaiHwParams,
};

struct DaiData g_dspDaiData = {
    .drvDaiName = "dsp_dai",
    .DaiInit = DspDaiDeviceInit,
    .ops = &g_dspDaiDeviceOps,
};

static int32_t DspDriverBind(struct HdfDeviceObject *device)
{
    AUDIO_DRIVER_LOG_INFO("entry");

    if (device == NULL) {
        AUDIO_DRIVER_LOG_ERR("device is NULL.");
        return HDF_ERR_INVALID_OBJECT;
    }

    struct AudioHost *audioHost = AudioHostCreateAndBind(device);
    if (audioHost == NULL) {
        AUDIO_DRIVER_LOG_ERR("audioHost create failed!");
        return HDF_FAILURE;
    }

    AUDIO_DRIVER_LOG_INFO("success");
    return HDF_SUCCESS;
}

static int32_t DspDriverInit(struct HdfDeviceObject *device)
{
    int32_t ret;

    AUDIO_DRIVER_LOG_INFO("entry");

    if (device == NULL) {
        AUDIO_DRIVER_LOG_ERR("device is NULL.");
        return HDF_ERR_INVALID_OBJECT;
    }

    ret = AudioRegisterDsp(device, &g_dspData, &g_dspDaiData);
    if (ret !=  HDF_SUCCESS) {
        return ret;
    }

    AUDIO_DRIVER_LOG_INFO("success");
    return HDF_SUCCESS;
}


static void DspDriverRelease(struct HdfDeviceObject *device)
{
    AUDIO_DRIVER_LOG_INFO("entry");
    if (device == NULL) {
        AUDIO_DRIVER_LOG_ERR("device is NULL");
        return;
    }

    struct DspHost *dspHost = (struct DspHost *)device->service;
    if (dspHost == NULL) {
        AUDIO_DRIVER_LOG_ERR("DspHost is NULL");
        return;
    }
    if (dspHost->priv != NULL) {
        OsalMemFree(dspHost->priv);
    }
    OsalMemFree(dspHost);
    AUDIO_DRIVER_LOG_INFO("success");
}

/* HdfDriverEntry definitions */
struct HdfDriverEntry g_dspDriverEntry = {
    .moduleVersion = 1,
    .moduleName = "DSP",
    .Bind = DspDriverBind,
    .Init = DspDriverInit,
    .Release = DspDriverRelease,
};
HDF_INIT(g_dspDriverEntry);

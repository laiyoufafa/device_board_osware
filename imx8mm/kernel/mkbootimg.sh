#!/bin/bash
# Copyright (C) 2021–2022 Beijing OSWare Technology Co., Ltd
# This file contains confidential and proprietary information of
# OSWare Technology Co., Ltd
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
function main()
{
    dd if=/dev/zero of=boot.img bs=1M count=83
    mkfs.fat boot.img
    mkdir tmp
    mount boot.img tmp/
    cp -rf Image ./dtb/* tmp/
    umount tmp
    rm -rf tmp
}

main
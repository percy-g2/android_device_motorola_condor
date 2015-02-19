/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char radio[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

	property_set("ro.product.model", "Moto E");
    property_get("ro.boot.radio", radio);
    if (ISMATCH(radio, "0x1")) {
        /* xt1021 */
        property_set("ro.product.device", "condor_umts");
        property_set("ro.build.product", "condor_umts");
        property_set("ro.build.description", "condor_retgb-user 4.4.4 KXC21.5-40 46 release-keys");
        property_set("ro.build.fingerprint", "motorola/condor_retgb/condor_umts:4.4.4/KXC21.5-40/46:user/release-keys");
        property_set("ro.mot.build.customerid", "retgb");
        property_set("persist.radio.multisim.config", "");
    } else if (ISMATCH(radio, "0x5")) {
        /* xt1022 */
        property_set("ro.product.device", "condor_umtsds");
        property_set("ro.build.product", "condor_umtsds");
        property_set("ro.build.description", "condor_retaildsds-user 4.4.4 KXC21.5-40 46 release-keys");
        property_set("ro.build.fingerprint", "motorola/condor_retaildsds/condor_umtsds:4.4.4/KXC21.5-40/46:user/release-keys");
        property_set("ro.mot.build.customerid", "retaildsdsall");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("persist.radio.plmn_name_cmp", "1");
    } else if (ISMATCH(radio, "0x6")) {
        /* xt1023 */
        property_set("ro.product.device", "condor_umts");
        property_set("ro.build.product", "condor_umts");
        property_set("ro.build.description", "condor_retuaws-user 4.4.3 KXC21.5-34 26 release-keys");
        property_set("ro.build.fingerprint", "motorola/condor_retuaws/condor_umts:4.4.3/KXC21.5-34/26:user/release-keys");
        property_set("ro.mot.build.customerid", "retusa_aws");
        property_set("persist.radio.multisim.config", "");
    }
    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found radio id: %s setting build properties for %s device\n", radio, devicename);
}

# Inherit some common phone stuff.
$(call inherit-product, device/motorola/condor/full_condor.mk)

# Inherit some common gummy stuff.
$(call inherit-product, vendor/Gummy/config/common_full_phone.mk)


## Device identifier. This must come after all inclusions
PRODUCT_NAME := tg_condor
PRODUCT_RELEASE_NAME := MOTO E

PRODUCT_BUILD_PROP_OVERRIDES += BUILD_UTC_DATE=0

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

arm_cflags := -DOPENSSL_BN_ASM_MONT -DAES_ASM -DSHA1_ASM -DSHA256_ASM -DSHA512_ASM
arm_src_files := \
    aes/asm/aes-armv4.S \
    bn/asm/armv4-mont.S \
    sha/asm/sha1-armv4-large.S \
    sha/asm/sha256-armv4.S \
    sha/asm/sha512-armv4.S
non_arm_src_files := aes/aes_core.c

#################################################################################################
MY_FILES_PATH  :=  $(LOCAL_PATH)
MY_FILES_SUFFIX := %.c
# 递归遍历目录下的所有的文件
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# 获取相应的源文件
MY_ALL_FILES := $(foreach src_path,$(MY_FILES_PATH), $(call rwildcard,$(src_path),*.*) ) 
MY_ALL_FILES := $(MY_ALL_FILES:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)
MY_SRC_LIST  := $(filter $(MY_FILES_SUFFIX),$(MY_ALL_FILES)) 
MY_SRC_LIST  := $(MY_SRC_LIST:$(LOCAL_PATH)/%=%)

# 去除字串的重复单词
define uniq =
  $(eval seen :=)
  $(foreach _,$1,$(if $(filter $_,${seen}),,$(eval seen += $_)))
  ${seen}
endef

# 递归遍历获取所有目录
#MY_ALL_DIRS := $(dir $(foreach src_path,$(MY_FILES_PATH), $(call rwildcard,$(src_path),*/) ) )
#MY_ALL_DIRS := $(call uniq,$(MY_ALL_DIRS))

MY_SRC_LIST -= LPdir_nyi.c
# 赋值给NDK编译系统
LOCAL_SRC_FILES  := $(MY_SRC_LIST)

##################################################################################################
	
ifeq ($(TARGET_ARCH),arm)
	LOCAL_SRC_FILES += $(arm_src_files)
	LOCAL_CFLAGS += $(arm_cflags)
else
	LOCAL_SRC_FILES += $(non_arm_src_files)
endif
	
#LOCAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_CFLAGS += -O3 -fstrict-aliasing -fprefetch-loop-arrays \
    -DANDROID -DANDROID_TILE_BASED_DECODE -DENABLE_ANDROID_NULL_CONVERT
	
# From CLFAG=	
LOCAL_CFLAGS += -DOPENSSL_THREADS -D_REENTRANT -DDSO_DLFCN -DHAVE_DLFCN_H -DL_ENDIAN #-DTERMIO

# From DEPFLAG=
LOCAL_CFLAGS += -DOPENSSL_NO_CAMELLIA -DOPENSSL_NO_CAPIENG -DOPENSSL_NO_CAST -DOPENSSL_NO_CMS -DOPENSSL_NO_GMP -DOPENSSL_NO_IDEA -DOPENSSL_NO_JPAKE -DOPENSSL_NO_MD2 -DOPENSSL_NO_MDC2 -DOPENSSL_NO_RC5 -DOPENSSL_NO_SHA0 -DOPENSSL_NO_RFC3779 -DOPENSSL_NO_SEED -DOPENSSL_NO_STORE -DOPENSSL_NO_WHIRLPOOL

# Extra
LOCAL_CFLAGS += -DOPENSSL_NO_HW -DOPENSSL_NO_ENGINE 
#LOCAL_CFLAGS += -DZLIB

#Disable crypto Algorithm
#LOCAL_CFLAGS += -DOPENSSL_NO_AES #-DOPENSSL_NO_BIO

# Debug
# LOCAL_CFLAGS += -DCIPHER_DEBUG	
	
local_c_includes := \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/asn1 \
	$(LOCAL_PATH)/evp \
	$(LOCAL_PATH)/modes \
	$(LOCAL_PATH)/stack \
	$(LOCAL_PATH)/include \
	$(LOCAL_PATH)/include/openssl \
	$(LOCAL_PATH)/include/internal
	
local_c_flags := -DNO_WINDOWS_BRAINDEATH
LOCAL_CFLAGS += $(local_c_flags)

LOCAL_C_INCLUDES += $(local_c_includes)	

LOCAL_MODULE := libcrypto

LOCAL_MODULE_TAGS := optional

# unbundled branch, built against NDK.
LOCAL_SDK_VERSION := 17

include $(BUILD_SHARED_LIBRARY)
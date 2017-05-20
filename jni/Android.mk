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

LOCAL_SRC_FILES :=\
	cryptlib.c \
	mem.c \
	mem_clr.c \
	o_init.c \
	ex_data.c \
	bio/b_print.c \
	bio/b_sock.c \
	bio/bf_buff.c \
	bio/bf_nbio.c \
	bio/bf_null.c \
	bio/bio_cb.c \
	bio/bio_err.c \
	bio/bio_lib.c \
	bio/bss_acpt.c \
	bio/bss_bio.c \
	bio/bss_conn.c \
	bio/bss_dgram.c \
	bio/bss_fd.c \
	bio/bss_file.c \
	bio/bss_log.c \
	bio/bss_mem.c \
	bio/bss_null.c \
	bio/bss_sock.c \
	des/cbc_cksm.c \
	des/cbc_enc.c \
	des/cfb64ede.c \
	des/cfb64enc.c \
	des/cfb_enc.c \
	des/des_enc.c \
	des/des_old.c \
	des/des_old2.c \
	des/ecb3_enc.c \
	des/ecb_enc.c \
	des/ede_cbcm_enc.c \
	des/enc_read.c \
	des/enc_writ.c \
	des/fcrypt.c \
	des/fcrypt_b.c \
	des/ofb64ede.c \
	des/ofb64enc.c \
	des/ofb_enc.c \
	des/pcbc_enc.c \
	des/qud_cksm.c \
	des/rand_key.c \
	des/read2pwd.c \
	des/rpc_enc.c \
	des/set_key.c \
	des/str2key.c \
	des/xcbc_enc.c \
	err/err.c \
	evp/bio_b64.c \
	evp/encode.c \
	lhash/lhash.c \
	rand/rand_lib.c \
	stack/stack.c \
	buffer/buffer.c \
	buffer/buf_str.c

	
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
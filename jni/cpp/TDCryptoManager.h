//
// Created by yangyinglong on 2017/5/18.
//

#ifndef ENCRYPTJNILIB_TDCRYPTOMANAGER_H
#define ENCRYPTJNILIB_TDCRYPTOMANAGER_H
#include <jni.h>
#include "TD3DES.h"
#include "TDRSACrypto.h"

#define ONLY_3DES false //是否仅仅支持3DES算法

class TDCryptoManager{
public:
    TDCryptoManager();
    jstring MD5(JNIEnv *env, jobject instance, jstring msg_);
    jstring encryptDES(JNIEnv *env, jobject instance, jstring msg_);
    jstring decryptDES(JNIEnv *env, jobject instance, jstring msg_);
    jstring encrypt3DES(JNIEnv *env, jobject instance, jstring msg_);
    jstring decodeAES(JNIEnv *env, jobject instance, jstring msg_);
    jstring encodeAES(JNIEnv *env, jobject instance, jstring msg_);
    jstring decryptBase64(JNIEnv *env, jobject instance, jstring msg_);
    jstring encryptBase64(JNIEnv *env, jobject instance, jstring msg_);
    jstring encryptRSA(JNIEnv *env, jobject instance, jstring msg_);
    jstring decryptRSA(JNIEnv *env, jobject instance, jstring msg_);
    jstring rsaSha1Sign(JNIEnv *env,jobject instance,jstring msg_);
    jstring Sha1(JNIEnv *env, jobject instance, jstring msg_);
    ~TDCryptoManager();
private:
    TD3DES *td3DES;
    /**
     * RSA_SHA1签名对象
     */
    TDRSACrypto *tdrsaCrypto;
};

#endif //ENCRYPTJNILIB_TDCRYPTOMANAGER_H

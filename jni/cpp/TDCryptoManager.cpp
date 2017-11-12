//
// Created by yangyinglong on 2017/5/18.
//

#include <jni.h>
#include <string>
#include "TDCryptoManager.h"
#include "TDMD5.h"
#include "TD3DES.h"
#include "TDBASE64.h"
#include "TDAES.h"
#include "TDRSA.h"
#include "Log.h"
#include "TDSha1.h"

#undef PRINT_KEY
#define PRINT_KEY false
TDCryptoManager::TDCryptoManager() {
    td3DES = new TD3DES();
    tdrsaCrypto = new TDRSACrypto();
}

/**
 * 生成MD5值
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
jstring TDCryptoManager::MD5(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);
    std::string msgC;
    msgC.assign(msg);

    std::string f;// = TDMD5::encryptMD5(msgC);
#if !ONLY_3DES
    f = TDMD5::encryptMD5(msgC);
#endif

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(f.c_str());
}

/**
 * 3DES加密算法
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
jstring TDCryptoManager::encryptDES(JNIEnv *env, jobject instance, jstring msg_){
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);
    int length;
    //防止密钥写在一起时，编译后密钥保持在常量区，容易一眼看出来
    std::string a = "i^F";//1
    std::string b = "Bup";//8
    std::string c = "gWO";//2
    std::string d = "&eS";//7
    std::string e = "B8I";//3
    std::string f = "a^^";//6
    std::string g = "sN4";//4
    std::string h = "7zj";//5
    char * keyTemp = (char *) malloc(24);
    memcpy(&keyTemp[0],a.c_str(),3);
    memcpy(&keyTemp[3],c.c_str(),3);
    memcpy(&keyTemp[6],e.c_str(),3);
    memcpy(&keyTemp[9],g.c_str(),3);
    memcpy(&keyTemp[12],h.c_str(),3);
    memcpy(&keyTemp[15],f.c_str(),3);
    memcpy(&keyTemp[18],d.c_str(),3);
    memcpy(&keyTemp[21],b.c_str(),3);
    std::string key(keyTemp,24);
    free(keyTemp);
//    std::string key = a + c + e + g + h + f + d + b;//"i^FgWOB8IsN47zja^^&eSBup";
//    std::string key = "i^FgWOB8IsN47zja^^&eSBup";


#if PRINT_KEY
    const char *temp = key.c_str();
    char* string = (char *) malloc(key.length());
    memcpy(string,temp,strlen(key.c_str()));
    LOGD("nativeKey%s",string);
#endif

    std::string des = td3DES->encryptDES(msgC, key, &length);


    std::string base64 = TDBASE64::base64_encodestring(des);


    env->ReleaseStringUTFChars(msg_, msg);
#if PRINT_KEY
    free(string);
#endif
    return env->NewStringUTF(base64.c_str());
}

/**
 * 3DES解密算法
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
jstring TDCryptoManager::decryptDES(JNIEnv *env, jobject instance, jstring msg_){
    const char *msg = env->GetStringUTFChars(msg_, 0);


    std::string msgC;
    msgC.assign(msg);
    std::string a = "i^F";//1
    std::string b = "Bup";//8
    std::string c = "gWO";//2
    std::string d = "&eS";//7
    std::string e = "B8I";//3
    std::string f = "a^^";//6
    std::string g = "sN4";//4
    std::string h = "7zj";//5
    std::string key = a + c + e + g + h + f + d + b;//"i^FgWOB8IsN47zja^^&eSBup";
    int length;
#if PRINT_KEY
    const char *temp = key.c_str();
     char* string = (char *) malloc(key.length());
    memcpy(string,temp,strlen(key.c_str()));
     jbyte *sadf = (jbyte *) ( char *) "aa";
    LOGD("%s",string);
#endif
    std::string base64 = TDBASE64::base64_decodestring(msgC);

    std::string des = td3DES->decryptDES(base64, key, base64.length());

    env->ReleaseStringUTFChars(msg_, msg);
#if PRINT_KEY
    free(string);
#endif
    return env->NewStringUTF(des.c_str());
}

/**
 * 暂无实现
 * @deprecated
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
jstring TDCryptoManager::encrypt3DES(JNIEnv *env, jobject instance, jstring msg_){
    return NULL;
}

/**
 *  AES解密算法
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
jstring TDCryptoManager::decodeAES(JNIEnv *env, jobject instance, jstring msg_){
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);

    int length;
    std::string base64 = TDBASE64::base64_decodestring(msgC);


    std::string aes;// = TDAES::decodeAES("1234567812345678", base64);
#if !ONLY_3DES
    aes = TDAES::decodeAES("1234567812345678", base64);
#endif

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(aes.c_str());
}

/**
 *  AES加密算法
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
jstring TDCryptoManager::encodeAES(JNIEnv *env, jobject instance, jstring msg_){
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);


    std::string aes ;//= TDAES::encodeAES("1234567812345678", msgC);//密码长度必须大于16 位
#if !ONLY_3DES
    aes = TDAES::encodeAES("1234567812345678", msgC);//密码长度必须大于16 位
#endif

    std::string base64 = TDBASE64::base64_encodestring(aes);


    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(base64.c_str());
}

/**
 * BASE64解码
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
jstring TDCryptoManager::decryptBase64(JNIEnv *env, jobject instance, jstring msg_){
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);


    std::string base64 ;//= TDBASE64::base64_decodestring(msgC);
#if !ONLY_3DES
    base64 = TDBASE64::base64_decodestring(msgC);
#endif

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(base64.c_str());
}

/**
 * BASE64加密
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
jstring TDCryptoManager::encryptBase64(JNIEnv *env, jobject instance, jstring msg_){
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);


    std::string base64 ;//= TDBASE64::base64_encodestring(msgC);
#if !ONLY_3DES
    base64 = TDBASE64::base64_encodestring(msgC);
#endif

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(base64.c_str());
}

/**
 * RSA加密算法
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
jstring TDCryptoManager::encryptRSA(JNIEnv *env, jobject instance, jstring msg_){
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);

    std::string rsa ;//= TDRSA::encryptRSA(msgC, NULL);
#if !ONLY_3DES
    rsa = TDRSA::encryptRSA(msgC, NULL);
#endif

    std::string base64 = TDBASE64::base64_encodestring(rsa);

    env->ReleaseStringUTFChars(msg_, msg);


    return env->NewStringUTF(base64.c_str());
}

/**
 * RSA解密算法
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
jstring TDCryptoManager::decryptRSA(JNIEnv *env, jobject instance, jstring msg_){
    /**************************************************************/
//    const char *msg = env->GetStringUTFChars(msg_, 0);
//
//    std::string msgC;
//    msgC.assign(msg);
//
//    std::string base64 = TDBASE64::base64_decodestring(msgC);
//
//    std::string rsa ;//= TDRSA::decryptRSA(base64);
//#if !ONLY_3DES
//    rsa = TDRSA::decryptRSA(base64);
//#endif
//
//    env->ReleaseStringUTFChars(msg_, msg);
//
//    return env->NewStringUTF(rsa.c_str());
    /**************************************************************/
//    const char *msg = env->GetStringUTFChars(msg_,0);
//    std::string msgC;
//    msgC.assign(msg);
//
//    std::string base64 = TDBASE64::base64_decodestring(msgC);
//
//    std::string rsa ;//= TDRSA::decryptRSA(base64);
//    rsa = tdrsaCrypto->decrypt(base64);
//    env->ReleaseStringUTFChars(msg_, msg);
//    return env->NewStringUTF(rsa.c_str());
    std::string plaint = tdrsaCrypto->javaRelfectDecrypt(env,instance,msg_);
    return env->NewStringUTF(plaint.c_str());
}

jstring TDCryptoManager::rsaSha1Sign(JNIEnv *env, jobject instance, jstring msg_) {
    std::string string;
    const char *c_msg_ = env->GetStringUTFChars(msg_,0);
    string.assign(c_msg_);
    std::string signString = tdrsaCrypto->rsaSha1Sign(&string);
    env->ReleaseStringUTFChars(msg_,c_msg_);
    return env->NewStringUTF(signString.c_str());
}

jstring TDCryptoManager::Sha1(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);
    std::string msgC;
    msgC.assign(msg);

    std::string f;
#if !ONLY_3DES
    f = TDSha1::sha1(msgC);
#endif
    env->ReleaseStringUTFChars(msg_,msg);
    return env->NewStringUTF(f.c_str());
}

/**
 * 析构函数，释放对象占用内存
 */
TDCryptoManager::~TDCryptoManager() {
//    delete(td3DES);
//    delete(tdrsaCrypto);
}


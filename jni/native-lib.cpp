#include <jni.h>
#include <string>
#include "MyRSA.h"
#include <android/log.h>
#include <iostream>
#include <des.h>
#include "MyBASE64.h"
#include "My3DES.h"
#include "MyMD5.h"
#include "Log.h"
#include "MyAES.h"
#include <sys/ptrace.h>
#include <assert.h>
#define JNIREG_CLASS "demo/rsa/gkbn/rsademo/JniDemo"

#ifdef __cpluscplus
extern "C" {
#endif
jstring getStringc(JNIEnv *env, jobject obj);
jstring MD5       (JNIEnv *env, jobject instance, jstring msg_);
jstring encryptDES(JNIEnv *env, jobject instance, jstring msg_);
jstring decryptDES(JNIEnv *env, jobject instance, jstring msg_);
jstring encrypt3DES(JNIEnv *env, jobject instance, jstring msg_);
jstring decodeAES(JNIEnv *env, jobject instance, jstring msg_);
jstring encodeAES(JNIEnv *env, jobject instance, jstring msg_);
jstring decryptBase64(JNIEnv *env, jobject instance, jstring msg_);
jstring encryptBase64(JNIEnv *env, jobject instance, jstring msg_);
jstring encryptRSA(JNIEnv *env, jobject instance, jstring msg_);
jstring decryptRSA(JNIEnv *env, jobject instance, jstring msg_);
int xxx_3des_encrypt(const char* datain, char* dataout, const unsigned char* keyin, int keyin_len);

static JNINativeMethod gMethods[] = {
        {"getStringFromNative"  ,"()Ljava/lang/String;", (void*)getStringc},
        {"nativeMD5"            ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)MD5},
        {"nativeEncryptDES"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encryptDES},
        {"nativeDecryptDES"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decryptDES},
        {"nativeEncrypt3DES"    ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encrypt3DES},
        {"nativeDecodeAES"      ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decodeAES},
        {"nativeEncodeAES"      ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encodeAES},
        {"nativeDecryptBase64"  ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decryptBase64},
        {"nativeEncryptBase64"  ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encryptBase64},
        {"nativeEncryptRSA"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encryptRSA},
        {"nativeDecryptRSA"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decryptRSA}
};

/**
 * base64加密
 */

//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring encryptBase64(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);


    std::string base64 = MyBASE64::base64_encodestring(msgC);

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(base64.c_str());
}

/**
 * base64 解密
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring decryptBase64(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);


    std::string base64 = MyBASE64::base64_decodestring(msgC);

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(base64.c_str());
}




/**
 * MD5加密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
jstring MD5(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);


    std::string msgC;
    msgC.assign(msg);

    std::string f ;//= MyMD5::encryptMD5(msgC);

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(f.c_str());
}



/**
 * AES加密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring encodeAES(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);


    std::string aes ;//= MyAES::encodeAES("1234567812345678", msgC);//密码长度必须大于16 位


    std::string base64 = MyBASE64::base64_encodestring(aes);


    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(base64.c_str());
}




/**
 * AES解密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring decodeAES(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);

    int length;
    std::string base64 = MyBASE64::base64_decodestring(msgC);


    std::string aes ;//= MyAES::decodeAES("1234567812345678", base64);

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(aes.c_str());
}

/**
 * DES加密算法
 * @param msg_ 待加密明文
 * @return 加密后的密文
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring encryptDES(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);

    int length;
    std::string key = "i^FgWOB8IsN47zja^^&eSBup";
    std::string des = My3DES::encryptDES(msgC, key, &length);


    std::string base64 = MyBASE64::base64_encodestring(des);


    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(base64.c_str());
}


/**
 *
 * DES解密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring decryptDES(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);


    std::string msgC;
    msgC.assign(msg);

    std::string key = "i^FgWOB8IsN47zja^^&eSBup";
    int length;
    std::string base64 = MyBASE64::base64_decodestring(msgC);

    std::string des = My3DES::decryptDES(base64, key, base64.length());

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(des.c_str());
}




/**
 * RSA解密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring decryptRSA(JNIEnv *env, jobject instance, jstring msg_) {
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);

    std::string base64 = MyBASE64::base64_decodestring(msgC);

    std::string rsa;// = MyRSA::decryptRSA(base64);


    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(rsa.c_str());
}


/**
 * RSA  加密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring encryptRSA(JNIEnv *env, jobject instance, jstring msg_) {

    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);

    std::string rsa ;//= MyRSA::encryptRSA(msgC, NULL);


    std::string base64 = MyBASE64::base64_encodestring(rsa);

    env->ReleaseStringUTFChars(msg_, msg);


    return env->NewStringUTF(base64.c_str());

}

//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring encrypt3DES(JNIEnv *env, jobject instance, jstring msg_){
    const char* datain;
    char * dataout = (char *) malloc(32);
    int length = env->GetStringUTFLength(msg_);
    jstring encryptKey = env->NewStringUTF("i^FgWOB8IsN47zja^^&eSBup") ;
    const unsigned char* encryptKeyChars = (const unsigned char *) env->GetStringUTFChars(encryptKey, 0);
    datain = env->GetStringUTFChars(msg_, 0);

    xxx_3des_encrypt(datain,dataout,encryptKeyChars,length);
    env->ReleaseStringUTFChars(encryptKey, (const char *) encryptKeyChars);
    env->ReleaseStringUTFChars(msg_,datain);
    jstring en = env->NewStringUTF(dataout);
    free(dataout);
    return en;
}
/************************************************************************
** 本例采用：
**    3des-ecb加密方式；
**    24位密钥，不足24位的右补'0'；
**    加密内容8位补齐，补齐方式为：少1位补一个0x01,少2位补两个0x02,...
**        本身已8位对齐的，后面补八个0x08。
************************************************************************/
int xxx_3des_encrypt(const char* datain, char* dataout, const unsigned char* keyin, int keyin_len)
{
    int docontinue = 1;

    int data_len;
    int data_rest;
    unsigned char ch;

    unsigned char *src = NULL; /* 补齐后的明文 */
    unsigned char *dst = NULL; /* 解密后的明文 */
    int len;
    unsigned char tmp[8];
    unsigned char in[8];
    unsigned char out[8];

    int key_len;
#define LEN_OF_KEY              24
    unsigned char key[LEN_OF_KEY]; /* 补齐后的密钥 */
    unsigned char block_key[9];
    DES_key_schedule ks,ks2,ks3;

/* 构造补齐后的密钥 */
    key_len = strlen((const char*)keyin);
    memcpy(key, keyin, key_len);
    memset(key + key_len, '0', LEN_OF_KEY - key_len);

/* 分析补齐明文所需空间及补齐填充数据 */
    data_len = strlen(datain);
    data_rest = data_len % 8;
    len = data_len + (8 - data_rest);
    ch = 8 - data_rest;

    src = (unsigned char *) malloc(len);
    dst = (unsigned char *) malloc(len);
    if (NULL == src || NULL == dst)
    {
        docontinue = 0;
    }
    if (docontinue)
    {
        int count;
        int i;

        /* 构造补齐后的加密内容 */
        memset(src, 0, len);
        memcpy(src, datain, data_len);
        memset(src + data_len, ch, 8 - data_rest);

        /* 密钥置换 */
        memset(block_key, 0, sizeof(block_key));
        memcpy(block_key, key + 0, 8);
        DES_set_key_unchecked((const_DES_cblock*)block_key, &ks);
        memcpy(block_key, key + 8, 8);
        DES_set_key_unchecked((const_DES_cblock*)block_key, &ks2);
        memcpy(block_key, key + 16, 8);
        DES_set_key_unchecked((const_DES_cblock*)block_key, &ks3);

        /* 循环加密/解密，每8字节一次 */
        count = len / 8;
        for (i = 0; i < count; i++)
        {
            memset(tmp, 0, 8);
            memset(in, 0, 8);
            memset(out, 0, 8);
            memcpy(tmp, src + 8 * i, 8);

            /* 加密 */
            DES_ecb3_encrypt((const_DES_cblock*)tmp, (DES_cblock*)(dst+8*i), &ks, &ks2, &ks3, DES_ENCRYPT);

        }

    }

    int j = 0;
    for(j=0; j<len; j++)
    {
        snprintf(dataout+ j*2, 3, "%02X", dst[j]);
    }

    if (NULL != src)
    {
        free(src);
        src = NULL;
    }
    if (NULL != dst)
    {
        free(dst);
        dst = NULL;
    }

    return 0;
}
//jstring JNICALL Java_com_example_zbb_test01_MainActivity_getStringFromNative(JNIEnv *env, jobject obj, jstring str) __attribute__((section(".mytext")));
//JNIEXPORT jstring JNICALL Java_com_example_zbb_test01_MainActivity_getStringFromNative
__attribute__((section (".mytext")))   jstring getStringc
        (JNIEnv *env, jobject obj)
{
    return env->NewStringUTF( "asdfasdfwe");
}


static int registerNativeMethods(JNIEnv* env, const char* className,
                                 JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;
    clazz = env->FindClass( className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}
static int registerNatives(JNIEnv* env)
{
    if (!registerNativeMethods(env, JNIREG_CLASS, gMethods,
                               sizeof(gMethods) / sizeof(gMethods[0])))
        return JNI_FALSE;

    return JNI_TRUE;
}
void anti_debug(){
    ptrace(PTRACE_TRACEME,0,0,0);
}

//__attribute ((visibility ("default")))
jint JNI_OnLoad(JavaVM* vm,void* reserved){
    //anti_debug();
    JNIEnv* env;
    if (vm->GetEnv((void**)(&env), JNI_VERSION_1_6) != JNI_OK)

    {
        return -1;
    }
    assert(env != NULL);

    if (!registerNatives(env)) {//注册
        return -1;
    }

    return JNI_VERSION_1_6;
}

//__attribute ((visibility ("default")))
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    //   __android_log_print(ANDROID_LOG_ERROR, "tag", "library was unload");
}

#ifdef __cpluscplus
}
#endif
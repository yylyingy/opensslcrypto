#include <jni.h>
#include <string>
#include <android/log.h>
#include <des.h>
#include "TDBASE64.h"
#include "Log.h"
#include <sys/ptrace.h>
#include <assert.h>
#include <pem.h>
#include <aes.h>
#include "CashLoanConfig.h"
#define JNIREG_CLASS "com/paisheng/lib/security/JNICrypto"

#define ONLY_AES

//#ifdef __cpluscplus
//extern "C" {
//#endif

#define ONLY_3DES false //是否仅仅支持3DES算法

//TDCryptoManager* handle = NULL;
//static const char* RELEASE_SIGN ;//= "3082036d30820255a00302010202047a2d8d08300d06092a864886f70d01010b05003066310b300906035504061302383631123010060355040813096775616e67646f6e673111300f06035504071308646f6e676775616e3110300e060355040a13077475616e6461693111300f060355040b13087061697368656e67310b30090603550403130274643020170d3137303630383036323232315a180f32323137303432313036323232315a3066310b300906035504061302383631123010060355040813096775616e67646f6e673111300f06035504071308646f6e676775616e3110300e060355040a13077475616e6461693111300f060355040b13087061697368656e67310b300906035504031302746430820122300d06092a864886f70d01010105000382010f003082010a0282010100c16e982b1e0742ab56e930451bd35829197dcc5d2b6bee33bef19c50f52f559b5eaeaaa884edfbb402059927e0df80d8bd1e98e4ea93a73c1f13709b970d938ba153d265fccc95d5843f270dac144eaf541dff0fa12112a93cfd9b1726f0b6075ee0142c781fd4e4f5b1c3e02611f5d7018364b965f9bf0457315b1a45cdf562ef7eb23a6e5ceb998e1b42f4424025a0d307d60ff47cf2c75e9f17d40d4cc784ff3b4928baafb1c28ee125b32c9e5733ebde3a73180ecf44a5f16fc1204f8725561e5f4005391c39e2e2163515b5955b4bd4c1ce0e60355ad575a0ad00563036ea00257b76f767b5acf670dc4c658be2df793cf49bdc8bbb03bebafe00c1212b0203010001a321301f301d0603551d0e0416041440de9535fa835090b8a87ed9db7581004ddc249e300d06092a864886f70d01010b050003820101007b8cdbac7c1e85839e944435a7d39a557e72a6f6fd571015e7b43948b6fb64de279d79a426e82168f9ea7d62e689b2a93040e54f113e5a58a99c4f533a8357e8714fe87615ebd7d6fa7a5180980bb9372ed1305d4143cbf15bf53e160dece8eaaf174a12a317f62780e0113429b0782e87c679b24c27fc5e71b9de32a1b54e2a3dc6941fe99a86d943c2f0e4a7b4e4ce514e238fcf75363b04482af6f891d11393e6ddf66d02b18cc2f57cf50f64233de8cfb7ab8dada75ce50a13193103106ac656eaaa61cb64008a453623c51b3a03d8608b76fee45248a7893c6e04025b403bf72807f184705453e0e4ef6abd0d4fbae2c1d6ba9184aaf858bd6f77adb75a";
void totalTest(JNIEnv* env,jobject thiz);
#ifndef ONLY_AES
bool evpVerify(JNIEnv *env,jobject instance,jstring sign,jstring content);
jstring getRealmKey(JNIEnv *env,jobject instance);
jstring rsaDecrypt(JNIEnv *env,jobject instance,jstring msg_);
jstring rsaSha1Sign(JNIEnv *env,jobject instance,jstring msg_);
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
#endif
void init(JNIEnv* env,jobject thiz,jobject context);
void destroy(JNIEnv* env,jobject thiz);
jstring rsaVerify(JNIEnv *env,jobject instance,jstring sign,jstring content);

static JNINativeMethod gMethods[] = {
        {"nativeTotalTest"      ,"()V"                                ,(void*)totalTest},
#ifndef ONLY_AES
        {"getStringFromNative"  ,"()Ljava/lang/String;", (void*)getStringc},
        {"nativeVerify"         ,"(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;",(void*)rsaVerify},
        {"nativeEvpVerify"      ,"(Ljava/lang/String;Ljava/lang/String;)Z",(void*)evpVerify},
        {"nativeGetRealmKey"    ,"()Ljava/lang/String;"                 ,(void*)getRealmKey},
        {"nativeSimuDecrypt"    ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)rsaDecrypt},
        {"nativeRSASHA1Sign"    ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)rsaSha1Sign},
        {"nativeMD5"            ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)MD5},
        {"nativeEncryptDES"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encryptDES},
        {"nativeDecryptDES"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decryptDES},
        {"nativeDecodeAES"      ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decodeAES},
        {"nativeEncodeAES"      ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encodeAES},
        {"nativeDecryptBase64"  ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decryptBase64},
        {"nativeEncryptBase64"  ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encryptBase64},
        {"nativeEncryptRSA"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encryptRSA},
        {"nativeDecryptRSA"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decryptRSA},
#endif
        {"nativeInit"           ,"(Landroid/content/Context;)V"          ,(void*)init},
        {"nativeDestroy"        ,"()V"                                   ,(void*)destroy}
};

int aes_decrypt(char* in, char* key,char *iv, char* out)
{
    if(!in || !key || !out) return 0;

    AES_KEY aes;
    if(AES_set_decrypt_key((unsigned char*)key, 256, &aes) < 0)
    {
        return 0;
    }
    int len=strlen(in);
    AES_cbc_encrypt((unsigned char*)in, (unsigned char*)out, len, &aes, (unsigned char *) iv, AES_DECRYPT);
    return 1;
}

void test() {
    unsigned char key[32] = "12345678";
    unsigned char iv[17] = "0102030405060708";
    unsigned char *inStr = (unsigned char *) "测试ceshi123";
    int inLen = strlen((const char *) inStr);
    int encLen = 0;
    int outlen = 0;
    unsigned char encData[1024] = {0};

    printf("source: %s\n",inStr);

    //加密
//    EVP_CIPHER_CTX *ctx;
//    ctx = EVP_CIPHER_CTX_new();
//
//    EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv, 1);
//    EVP_CipherUpdate(ctx, encData, &outlen, inStr, inLen);
//    encLen = outlen;
//    EVP_CipherFinal(ctx, encData+outlen, &outlen);
//    encLen += outlen;
//    EVP_CIPHER_CTX_free(ctx);
//
//    std::string enstr;
//    enstr.assign((char*)encData);
//    std::string base64 = TDBASE64::base64_encodestring(enstr);
//    LOGD("evp:%s:end",base64.c_str());
    //解密
    std::string cryptoText = TDBASE64::base64_decodestring("zOBJcuR1IoUZBITd2Y7m6ltKZ0VDtf/IOyEzQoJ4DbQPlSiQJ4R3cRA6dQEOCW1eGXpsvzWDb2aONGc0YXqZdhRHPBxueassEy2u4kQCxntdOZ0YGlPIhCDs4KbjBoP5QRzgWb0/cn5hHgnotKIm4fB4/bMD4E4KIny/chGSv2ldmOTSlz7xnqwvHLZVCjdxAe6+HQOsaC6eqXvXOfEF4jDIryvEJ5s4GL6bUajWcQ/9ZPjxF2ojrTudmye3z2rB6K3vHAl9GyqGQfebeUaHCpPIoxSVk769WZgUYvd6fe60xh6wIx3BCT9b9p/66sn+P8hphe8zdHMXm+OaPu+ZUi6YaCH4TEvyO6eyS8apsnbRDB/wP0p50c3ciRtFXZWTDka0xNtW2UpIsm733AokUvRVbrydFk0TAZrPvrwAQOo7nf/j2roOkA3L0idrag1Q18YALxveJXbBqq9SUMUPv19TIvsTn9/eVKByBamoP4QhJjSSuTQ6U6B6uldSIKBEmzRXcdME9F0ibYxAIEHxLx0EfNTDKRSXxhJtPjZCnq7JzW+EiXxwd6osBifOWgaxnNhNrBYvVpaVvh6UI/j2sayccjRzu1XqL9f83FfiVHU=");
    int cryptoTextLen = cryptoText.length();
    int decLen = 0;
    outlen = 0;
    unsigned char decData[1024] = {0};
    EVP_CIPHER_CTX *ctx2;
    ctx2 = EVP_CIPHER_CTX_new();
    EVP_CipherInit_ex(ctx2, EVP_aes_256_cbc(), NULL, key, iv, 0);
    EVP_CipherUpdate(ctx2, decData, &outlen, (const unsigned char *) cryptoText.c_str(), cryptoTextLen);
    decLen = outlen;
    EVP_CipherFinal(ctx2, decData+outlen, &outlen);
    decLen += outlen;
    EVP_CIPHER_CTX_free(ctx2);
    std::string decodeResult;
    int size = strlen(cryptoText.c_str()) / AES_BLOCK_SIZE;
    decodeResult.append((const char *) decData, (unsigned int) decLen);
    LOGD("解密：%s",decodeResult.c_str());
}

JNIEXPORT void totalTest(JNIEnv* env,jobject thiz) {
    test();
    char encrypt_string[4096] = { 0 };
    AES_KEY aes;
    //32位密钥,32*8 = 256位aes加密,c语言中最后一位补'\0',所以是33长度
    char key[33] = "12345678";//"quck7295abvdefgh";
    char iv[17] = "0102030405060708";
    std::string input_string = "测试ceshi123";
    int nLen = input_string.length();

    int nBei = nLen / AES_BLOCK_SIZE + 1;
    int nTotal = nBei * AES_BLOCK_SIZE;
    char *enc_s = (char*)malloc(nTotal);
    int nNumber;
    if (nLen % 16 > 0)
        nNumber = nTotal - nLen;
    else
        nNumber = 16;
    memset(enc_s, nNumber, nTotal);
    memcpy(enc_s, input_string.data(), nLen);

    if (AES_set_encrypt_key((unsigned char*)key, 256, &aes) < 0) {
        fprintf(stderr, "Unable to set encryption key in AES\n");
        exit(-1);
    }

    AES_cbc_encrypt((unsigned char *)enc_s, (unsigned char*)encrypt_string, nBei * 16, &aes, (unsigned char*)iv, AES_ENCRYPT);

    std::string enstr;
    enstr.assign(encrypt_string);
    std::string base64 = TDBASE64::base64_encodestring(enstr);
    LOGD("%s",base64.c_str());
    //解密测试
    char decrypt_string[4096] = { 0 };
    aes_decrypt(encrypt_string, key, iv, decrypt_string);
    std::string dnstr;
    dnstr.assign(decrypt_string);
    LOGD("%s",dnstr.c_str());
}



/*
    根据context对象,获取签名字符串
*/
static const char* getSignString(JNIEnv *env,jobject contextObject) {
    jclass contextClass;
    jclass signatureClass = (jclass)env->NewGlobalRef((env)->FindClass("android/content/pm/Signature"));
    jclass packageNameClass = (jclass)env->NewGlobalRef((env)->FindClass("android/content/pm/PackageManager"));
    jclass packageInfoClass = (jclass)env->NewGlobalRef((env)->FindClass("android/content/pm/PackageInfo"));
    contextClass = (jclass)env->NewGlobalRef((env)->FindClass("android/content/Context"));
    jmethodID getPackageManagerId = (env)->GetMethodID(contextClass, "getPackageManager","()Landroid/content/pm/PackageManager;");
    jmethodID getPackageNameId = (env)->GetMethodID(contextClass, "getPackageName","()Ljava/lang/String;");
    jmethodID signToStringId = (env)->GetMethodID(signatureClass, "toCharsString","()Ljava/lang/String;");
    jmethodID getPackageInfoId = (env)->GetMethodID(packageNameClass, "getPackageInfo","(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");
    jobject packageManagerObject =  (env)->CallObjectMethod(contextObject, getPackageManagerId);
    jstring packNameString =  (jstring)(env)->CallObjectMethod(contextObject, getPackageNameId);
    jobject packageInfoObject = (env)->CallObjectMethod(packageManagerObject, getPackageInfoId,packNameString, 64);
    jfieldID signaturefieldID =(env)->GetFieldID(packageInfoClass,"signatures", "[Landroid/content/pm/Signature;");
    jobjectArray signatureArray = (jobjectArray)(env)->GetObjectField(packageInfoObject, signaturefieldID);
    jobject signatureObject =  (env)->GetObjectArrayElement(signatureArray,0);
    return (env)->GetStringUTFChars((jstring)(env)->CallObjectMethod(signatureObject, signToStringId),0);
}

__attribute__((section (".tdtext")))
JNIEXPORT void init(JNIEnv* env,jobject thiz,jobject context){
//    const char* signStrng =  getSignString(env,context);
//    //std::string 的c_str()有长度限制,测试时1700左右长度会丢失几百个字符
//    int result = getApkSign().compare(signStrng);
//    if (IS_LOG_OUT_MSG) {
//        LOGD("%s",getApkSign().c_str());
//        LOGD("%s",signStrng);
//    }
//    if(result == 0) {//签名一致,初始化
//        //防止多次实例化对象，造成内存泄露
//        if (handle != NULL) {
//            delete(handle);
//        }
//        handle = new TDCryptoManager();
//    }else {//签名不一致，抛异常
//        jclass clz = env->FindClass("java/lang/IllegalStateException");
//        jmethodID methodId = env->GetMethodID(clz, "<init>", "(Ljava/lang/String;)V");
//        jthrowable throwable = (jthrowable) env->NewObject(clz, methodId,env->NewStringUTF("The sign is not match!"));
//        env->Throw(throwable);
//    }
}

JNIEXPORT void destroy(JNIEnv* env,jobject thiz){
//    delete(handle);
//    handle = NULL;
}



//jstring JNICALL Java_com_example_zbb_test01_MainActivity_getStringFromNative(JNIEnv *env, jobject obj, jstring str) __attribute__((section(".TDtext")));
//JNIEXPORT jstring JNICALL Java_com_example_zbb_test01_MainActivity_getStringFromNative
__attribute__((section (".tdtext")))
jstring getStringc(JNIEnv *env, jobject obj)
{
    return NULL;//env->NewStringUTF( "asdfasdfwe");
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

//#ifdef __cpluscplus
//}
//#endif


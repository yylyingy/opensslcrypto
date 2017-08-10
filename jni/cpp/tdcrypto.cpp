#include <jni.h>
#include <string>
#include "TDRSA.h"
#include <android/log.h>
#include <des.h>
#include "TDBASE64.h"
#include "TD3DES.h"
#include "TDMD5.h"
#include "Log.h"
#include "TDAES.h"
#include <sys/ptrace.h>
#include <assert.h>
#include "TDCryptoManager.h"
#define JNIREG_CLASS "com/paisheng/lib/crypto/JNICrypto"

//#ifdef __cpluscplus
//extern "C" {
//#endif

#define ONLY_3DES false //是否仅仅支持3DES算法

TDCryptoManager* handle = NULL;
//static const char* RELEASE_SIGN ;//= "3082036d30820255a00302010202047a2d8d08300d06092a864886f70d01010b05003066310b300906035504061302383631123010060355040813096775616e67646f6e673111300f06035504071308646f6e676775616e3110300e060355040a13077475616e6461693111300f060355040b13087061697368656e67310b30090603550403130274643020170d3137303630383036323232315a180f32323137303432313036323232315a3066310b300906035504061302383631123010060355040813096775616e67646f6e673111300f06035504071308646f6e676775616e3110300e060355040a13077475616e6461693111300f060355040b13087061697368656e67310b300906035504031302746430820122300d06092a864886f70d01010105000382010f003082010a0282010100c16e982b1e0742ab56e930451bd35829197dcc5d2b6bee33bef19c50f52f559b5eaeaaa884edfbb402059927e0df80d8bd1e98e4ea93a73c1f13709b970d938ba153d265fccc95d5843f270dac144eaf541dff0fa12112a93cfd9b1726f0b6075ee0142c781fd4e4f5b1c3e02611f5d7018364b965f9bf0457315b1a45cdf562ef7eb23a6e5ceb998e1b42f4424025a0d307d60ff47cf2c75e9f17d40d4cc784ff3b4928baafb1c28ee125b32c9e5733ebde3a73180ecf44a5f16fc1204f8725561e5f4005391c39e2e2163515b5955b4bd4c1ce0e60355ad575a0ad00563036ea00257b76f767b5acf670dc4c658be2df793cf49bdc8bbb03bebafe00c1212b0203010001a321301f301d0603551d0e0416041440de9535fa835090b8a87ed9db7581004ddc249e300d06092a864886f70d01010b050003820101007b8cdbac7c1e85839e944435a7d39a557e72a6f6fd571015e7b43948b6fb64de279d79a426e82168f9ea7d62e689b2a93040e54f113e5a58a99c4f533a8357e8714fe87615ebd7d6fa7a5180980bb9372ed1305d4143cbf15bf53e160dece8eaaf174a12a317f62780e0113429b0782e87c679b24c27fc5e71b9de32a1b54e2a3dc6941fe99a86d943c2f0e4a7b4e4ce514e238fcf75363b04482af6f891d11393e6ddf66d02b18cc2f57cf50f64233de8cfb7ab8dada75ce50a13193103106ac656eaaa61cb64008a453623c51b3a03d8608b76fee45248a7893c6e04025b403bf72807f184705453e0e4ef6abd0d4fbae2c1d6ba9184aaf858bd6f77adb75a";
//获取车全测试apk签名
static std::string getApkSign();

jstring getRealmKey(JNIEnv *env,jobject instance);
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
int xxx_3des_encrypt(const char* datain, char* dataout, const unsigned char* keyin, int keyin_len);
void init(JNIEnv* env,jobject thiz,jobject context);
void destroy(JNIEnv* env,jobject thiz);

static JNINativeMethod gMethods[] = {
        {"getStringFromNative"  ,"()Ljava/lang/String;", (void*)getStringc},
        {"nativeGetRealmKey"    ,"()Ljava/lang/String;"                 ,(void*)getRealmKey},
        {"nativeRSASHA1Sign"    ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)rsaSha1Sign},
        {"nativeMD5"            ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)MD5},
        {"nativeEncryptDES"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encryptDES},
        {"nativeDecryptDES"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decryptDES},
        {"nativeEncrypt3DES"    ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encrypt3DES},
        {"nativeDecodeAES"      ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decodeAES},
        {"nativeEncodeAES"      ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encodeAES},
        {"nativeDecryptBase64"  ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decryptBase64},
        {"nativeEncryptBase64"  ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encryptBase64},
        {"nativeEncryptRSA"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)encryptRSA},
        {"nativeDecryptRSA"     ,"(Ljava/lang/String;)Ljava/lang/String;",(void*)decryptRSA},
        {"nativeInit"           ,"(Landroid/content/Context;)V"          ,(void*)init},
        {"nativeDestroy"        ,"()V"                                   ,(void*)destroy}
};

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
    const char* signStrng =  getSignString(env,context);
    //std::string 的c_str()有长度限制,测试时1700左右长度会丢失几百个字符
//    RELEASE_SIGN = getApkSign().c_str();
    LOGD("%s",getApkSign().c_str());
    int result = getApkSign().compare(signStrng);
    if(result == 0) {//签名一致,初始化
        //防止多次实例化对象，造成内存泄露
        if (handle != NULL) {
            delete(handle);
        }
        handle = new TDCryptoManager();
    }else {//签名不一致，抛异常
        jclass clz = env->FindClass("java/lang/IllegalStateException");
        jmethodID methodId = env->GetMethodID(clz, "<init>", "(Ljava/lang/String;)V");
        jthrowable throwable = (jthrowable) env->NewObject(clz, methodId,env->NewStringUTF("The sign is not match!"));
        env->Throw(throwable);
    }
}

JNIEXPORT void destroy(JNIEnv* env,jobject thiz){
    delete(handle);
    handle = NULL;
}
/**
 * base64加密
 */

//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring encryptBase64(JNIEnv *env, jobject instance, jstring msg_) {
    return handle->encryptBase64(env,instance,msg_);
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

__attribute__((section (".tdtext")))
jstring getRealmKey(JNIEnv *env,jobject instance) {
    return env->NewStringUTF("TDafpw3er2j34;k;wekr;wekr;k!@#@%#StuandaiGDSFGDAFGa215@#$@#%#@$%");
}

__attribute__((section (".tdtext")))
JNIEXPORT jstring rsaSha1Sign(JNIEnv *env,jobject instance,jstring msg_) {

    return handle->rsaSha1Sign(env,instance,msg_);
}

/**
 * base64 解密
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring decryptBase64(JNIEnv *env, jobject instance, jstring msg_) {
    return handle->decryptBase64(env,instance,msg_);
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
 * MD5加密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
jstring MD5(JNIEnv *env, jobject instance, jstring msg_) {
    return handle->MD5(env,instance,msg_);
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
 * AES加密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring encodeAES(JNIEnv *env, jobject instance, jstring msg_) {
    return handle->encodeAES(env,instance,msg_);
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
 * AES解密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring decodeAES(JNIEnv *env, jobject instance, jstring msg_) {
    handle->decodeAES(env,instance,msg_);
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
 * DES加密算法
 * @param msg_ 待加密明文
 * @return 加密后的密文
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring encryptDES(JNIEnv *env, jobject instance, jstring msg_) {
    return handle->encryptDES(env,instance,msg_);
//    const char *msg = env->GetStringUTFChars(msg_, 0);
//
//    std::string msgC;
//    msgC.assign(msg);
//    std::string a = "i^F";//1
//    std::string b = "Bup";//8
//    std::string c = "gWO";//2
//    std::string d = "&eS";//7
//    std::string e = "B8I";//3
//    std::string f = "a^^";//6
//    std::string g = "sN4";//4
//    std::string h = "7zj";//5
//
//
//    int length;
//    std::string key = a + c + e + g + h + f + d + b;//"i^FgWOB8IsN47zja^^&eSBup";
//    std::string des = TD3DES::encryptDES(msgC, key, &length);
//
//
//    std::string base64 = TDBASE64::base64_encodestring(des);
//
//
//    env->ReleaseStringUTFChars(msg_, msg);
//
//    return env->NewStringUTF(base64.c_str());
}


/**
 *
 * DES解密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring decryptDES(JNIEnv *env, jobject instance, jstring msg_) {
    return handle->decryptDES(env,instance,msg_);
//    const char *msg = env->GetStringUTFChars(msg_, 0);
//    std::string msgC;
//    msgC.assign(msg);
//    std::string a = "i^F";//1
//    std::string b = "Bup";//8
//    std::string c = "gWO";//2
//    std::string d = "&eS";//7
//    std::string e = "B8I";//3
//    std::string f = "a^^";//6
//    std::string g = "sN4";//4
//    std::string h = "7zj";//5
//    std::string key = a + c + e + g + h + f + d + b;//"i^FgWOB8IsN47zja^^&eSBup";
//#define PRINT_KEY false
//
//    int length;
//#if PRINT_KEY
//    const char *temp = key.c_str();
//     char* string = (char *) malloc(strlen(key.c_str()));
//    memcpy(string,temp,strlen(key.c_str()));
//     jbyte *sadf = (jbyte *) ( char *) "aa";
//    LOGD("%s",string);
//    LOGD("af");
//#endif
//    std::string base64 = TDBASE64::base64_decodestring(msgC);
//
//    std::string des = TD3DES::decryptDES(base64, key, base64.length());
//
//    env->ReleaseStringUTFChars(msg_, msg);
//#if PRINT_KEY
//    free(string);
//#endif
//    return env->NewStringUTF(des.c_str());
}




/**
 * RSA解密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring decryptRSA(JNIEnv *env, jobject instance, jstring msg_) {
    return handle->decryptRSA(env,instance,msg_);
    const char *msg = env->GetStringUTFChars(msg_, 0);

    std::string msgC;
    msgC.assign(msg);

    std::string base64 = TDBASE64::base64_decodestring(msgC);

    std::string rsa ;//= TDRSA::decryptRSA(base64);
#if !ONLY_3DES
    rsa = TDRSA::decryptRSA(base64);
#endif

    env->ReleaseStringUTFChars(msg_, msg);

    return env->NewStringUTF(rsa.c_str());
}


/**
 * RSA  加密算法
 */
//__attribute ((visibility ("default")))
__attribute__((section (".tdtext")))
JNIEXPORT jstring encryptRSA(JNIEnv *env, jobject instance, jstring msg_) {
    return handle->encryptRSA(env,instance,msg_);
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

//__attribute ((visibility ("default")))
/**
 * @deprecated
 * @param env
 * @param instance
 * @param msg_
 * @return
 */
__attribute__((section (".tdtext")))
JNIEXPORT jstring encrypt3DES(JNIEnv *env, jobject instance, jstring msg_){
    return handle->encrypt3DES(env,instance,msg_);
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
 * @deprecated
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

static std::string getApkSign() {
    std::string key0 = "3082036d30820255a003";
    std::string key20 = "02010202047a2d8d0830";
    std::string key40 = "0d06092a864886f70d01";
    std::string key60 = "010b05003066310b3009";
    std::string key80 = "06035504061302383631";
    std::string key100 = "12301006035504081309";
    std::string key120 = "6775616e67646f6e6731";
    std::string key140 = "11300f06035504071308";
    std::string key160 = "646f6e676775616e3110";
    std::string key180 = "300e060355040a130774";
    std::string key200 = "75616e6461693111300f";
    std::string key220 = "060355040b1308706169";
    std::string key240 = "7368656e67310b300906";
    std::string key260 = "03550403130274643020";
    std::string key280 = "170d3137303630383036";
    std::string key300 = "323232315a180f323231";
    std::string key320 = "37303432313036323232";
    std::string key340 = "315a3066310b30090603";
    std::string key360 = "55040613023836311230";
    std::string key380 = "10060355040813096775";
    std::string key400 = "616e67646f6e67311130";
    std::string key420 = "0f06035504071308646f";
    std::string key440 = "6e676775616e3110300e";
    std::string key460 = "060355040a1307747561";
    std::string key480 = "6e6461693111300f0603";
    std::string key500 = "55040b13087061697368";
    std::string key520 = "656e67310b3009060355";
    std::string key540 = "04031302746430820122";
    std::string key560 = "300d06092a864886f70d";
    std::string key580 = "01010105000382010f00";
    std::string key600 = "3082010a0282010100c1";
    std::string key620 = "6e982b1e0742ab56e930";
    std::string key640 = "451bd35829197dcc5d2b";
    std::string key660 = "6bee33bef19c50f52f55";
    std::string key680 = "9b5eaeaaa884edfbb402";
    std::string key700 = "059927e0df80d8bd1e98";
    std::string key720 = "e4ea93a73c1f13709b97";
    std::string key740 = "0d938ba153d265fccc95";
    std::string key760 = "d5843f270dac144eaf54";
    std::string key780 = "1dff0fa12112a93cfd9b";
    std::string key800 = "1726f0b6075ee0142c78";
    std::string key820 = "1fd4e4f5b1c3e02611f5";
    std::string key840 = "d7018364b965f9bf0457";
    std::string key860 = "315b1a45cdf562ef7eb2";
    std::string key880 = "3a6e5ceb998e1b42f442";
    std::string key900 = "4025a0d307d60ff47cf2";
    std::string key920 = "c75e9f17d40d4cc784ff";
    std::string key940 = "3b4928baafb1c28ee125";
    std::string key960 = "b32c9e5733ebde3a7318";
    std::string key980 = "0ecf44a5f16fc1204f87";
    std::string key1000 = "25561e5f4005391c39e2";
    std::string key1020 = "e2163515b5955b4bd4c1";
    std::string key1040 = "ce0e60355ad575a0ad00";
    std::string key1060 = "563036ea00257b76f767";
    std::string key1080 = "b5acf670dc4c658be2df";
    std::string key1100 = "793cf49bdc8bbb03beba";
    std::string key1120 = "fe00c1212b0203010001";
    std::string key1140 = "a321301f301d0603551d";
    std::string key1160 = "0e0416041440de9535fa";
    std::string key1180 = "835090b8a87ed9db7581";
    std::string key1200 = "004ddc249e300d06092a";
    std::string key1220 = "864886f70d01010b0500";
    std::string key1240 = "03820101007b8cdbac7c";
    std::string key1260 = "1e85839e944435a7d39a";
    std::string key1280 = "557e72a6f6fd571015e7";
    std::string key1300 = "b43948b6fb64de279d79";
    std::string key1320 = "a426e82168f9ea7d62e6";
    std::string key1340 = "89b2a93040e54f113e5a";
    std::string key1360 = "58a99c4f533a8357e871";
    std::string key1380 = "4fe87615ebd7d6fa7a51";
    std::string key1400 = "80980bb9372ed1305d41";
    std::string key1420 = "43cbf15bf53e160dece8";
    std::string key1440 = "eaaf174a12a317f62780";
    std::string key1460 = "e0113429b0782e87c679";
    std::string key1480 = "b24c27fc5e71b9de32a1";
    std::string key1500 = "b54e2a3dc6941fe99a86";
    std::string key1520 = "d943c2f0e4a7b4e4ce51";
    std::string key1540 = "4e238fcf75363b04482a";
    std::string key1560 = "f6f891d11393e6ddf66d";
    std::string key1580 = "02b18cc2f57cf50f6423";
    std::string key1600 = "3de8cfb7ab8dada75ce5";
    std::string key1620 = "0a13193103106ac656ea";
    std::string key1640 = "aa61cb64008a453623c5";
    std::string key1660 = "1b3a03d8608b76fee452";
    std::string key1680 = "48a7893c6e04025b403b";
    std::string key1700 = "f72807f184705453e0e4";
    std::string key1720 = "ef6abd0d4fbae2c1d6ba";
    std::string key1740 = "9184aaf858bd6f77adb7";
    std::string key1760 = "5a";
    std::string key = key0.append(key20).append(key40).append(key60).append(key80).append(key100).append(key120).append(key140).append(key160).append(key180).append(key200)
            .append(key220).append(key240).append(key260).append(key280).append(key300).append(key320).append(key340).append(key360).append(key380).append(key400)
            .append(key420).append(key440).append(key460).append(key480).append(key500).append(key520).append(key540).append(key560).append(key580).append(key600)
            .append(key620).append(key640).append(key660).append(key680).append(key700).append(key720).append(key740).append(key760).append(key780).append(key800)
            .append(key820).append(key840).append(key860).append(key880).append(key900).append(key920).append(key940).append(key960).append(key980).append(key1000)
            .append(key1020).append(key1040).append(key1060).append(key1080).append(key1100).append(key1120).append(key1140).append(key1160).append(key1180).append(key1200)
            .append(key1220).append(key1240).append(key1260).append(key1280).append(key1300).append(key1320).append(key1340).append(key1360).append(key1380).append(key1400)
            .append(key1420).append(key1440).append(key1460).append(key1480).append(key1500).append(key1520).append(key1540).append(key1560).append(key1580).append(key1600)
            .append(key1620).append(key1640).append(key1660).append(key1680).append(key1700).append(key1720).append(key1740).append(key1760) ;
//    key.append("test");
//    //删除所有换行符
//    for (unsigned int j = 0; j < key.size(); ++j) {
//        if (key[j] == '\n') {
//            key.erase(j,1);
//        }
//    }
//    key.compare()
////    unsigned char* temp = malloc(key.size());
//    LOGD("key length:%d",key.size());
    LOGD("char length:%d",strlen(key.c_str()));
    LOGD("key:%s",key.data());
    return key;
}
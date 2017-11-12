//
// Created by Yangyl on 2017/8/5.
//

#include "TDRSACrypto.h"
#include <jni.h>
#include <evp.h>
#include <rsa.h>
#include <pem.h>
#include <jni.h>
#include "Log.h"
#include "TDBASE64.h"
#include "TDAES.h"
#include "Config.h"



//私钥，后面会用aes加密保存
//#define PRIVATE_KEY "-----BEGIN RSA PRIVATE KEY-----\nMIIBVQIBADANBgkqhkiG9w0BAQEFAASCAT8wggE7AgEAAkEAuKQVsu9bCyEvkZXM0FXzAgb/uWcPKKuTeULip32LWbUz2qBZRKhi+m3HU3vXEIcaq3Td8t9dJC+HR6PhdM/q7wIDAQABAkAIZgZKplKI1hCY2ayASXiNPg5Bu6tX2T4TBPTUU4SUJvMRrrvq8d1PsHHS6QMh8eqaoclWPVG7nxc0v42Xm0NpAiEA4yUjXiw1ykSFesGXwz/Ee0Ma3Nn4lhmNscdXfAz7WwMCIQDQGLF8dETjSlMAG9Ll9fDdBTc6CBlcjxHrJ/OR4FQWpQIhANIl9O/WpTlqZbfpzhfVMln7/qlffI6aO67Dx9u8QvyzAiAOYxaqRxOYL0RLxqCvG3Dapwipb3PpbU7M1kdFt5+4rQIhALQhBipwK0P5hswUeDuPTdky1SKLYcZYLuFunn2g3k2B\n-----END RSA PRIVATE KEY-----\n"

//#define PRIVATE_KEY "-----BEGIN RSA PRIVATE KEY-----\nMIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAMYC6ECqZv8VlIExd6q1Shis7VzZWflOV6dlqw0XFpqbbUwNNkLvgTN/QiHueBmbMvvfKB+6dSIbgdVleRnDb2UCYn5Dn8UynzOEl5oufQDUf3q61sgwzyZGS98UahplHs6PhoVW43884uk9nWGGISTmOL5MdcAugMI9D+Y0isLlAgMBAAECgYEApxEG4qCjnC+aB9Mz811Yci9dagydBGMcQ8ndI4NKeBIRiqxPDvTDHy8NHlH1FS3EO40SborEj42D4wflwF4L2kIxFRAypfuQLiJS/EAtOR/luwhcAaWaAjooRpgN7x0QMxd6hlwY8w2QOt0Ega+8L7xhUY9lxkUDECNWojOANqECQQDuqNG/v1WcsaauL4cq/QaaRt1Q+W//Fhlt4+QFDkoCJ4mOmjoDMwspbPfosr+7wYgF0DY8m+sCPg9bEC+/K32dAkEA1GYDh4DLX5Vm3L57B1hSk2BPdT+4pGllkYJQz11DKD282ZAfPWoO1MErP47V3UqEhF1fyOPGNL2aYphITZd76QJAIRzxRT6B3WTUsJRNl8xVjzBH4sVJIcZqLtIQwBbUc+oSbuO9KtZ5NP02hGXQrndSrSPPcqdbewsrTEI5rbeWDQJBAIuGE+1wWqiIcRCzBAh4KY5sZuXjnPxLzA/A5irB3frSS3szpIHoaKOz3SAcSTrb159H40MI9Uvx/TelR2HJD/kCQEsuREeuUNxspUUk2x4sP0w7A51VuExnBg2Cmk5kx6yykbNxdp5zCK0S3CCSrtKXwAx7vDjUUSpdqiICQJj65bc=\n-----END RSA PRIVATE KEY-----\n"
//双重aes加密密文,需要解密成明文,明文才是需要的text
//#define CRYPTO_TEXT "2ZBHFW5fA06In/rGyvXrw0707aPFvwlxRlyo7ILLpqx4ZMOGzoZkbyRcg9gK6goxq1EbzlDGeoUa8wqMKWbr8rJFCSi0hsi/Xn+XdIbPyyezVYJ1fxxuQCdsxQCStB9gY32unHpu7YlBa+mXJHAykwFfUKfqE+mO5iuUanesPqOzer5ajN4L9EFZUFbheBM9F7/wTrhxZIjWf8vBXGq78Mlhu25AYruHTVvS0W47qXd9HjomvnC4d5JOchwQKzxC4Bk/Z5PqFIPL9Q1aHsa+t5WI1t/LHJ8AwtaDgaHlm9rz1KRToH94StB0PmvEdPTxQZafI5hadLXNuXunog080EZ5UQ5lVt3td/m0rgf3ClN6XEZWKFQSWVRnJE4BLrcnQVl1BRAgaG4w3bamyCbzzhQ2cGiMH1gOIoUl+C0/RwobHPlOd/fqySveQZHKnVPiiQDqwks9MADRMUBcL9Oou6UbM/5PQ3LQs3rSsaJG/pPgvkJ48U9zIKP/T5i+l4QQZi4OrcI5eEyzfKOH5ovjAGrE3h7esXczHegwomV3WNMLxrqWDstgoAVTnM/MdQjvRKHCyRBU0wcZIV+OTxMHh9e0W0KPp6KlgC5kGZEgxKqpkB2c4A5oW30161IIgm0HVbV+95Ek7xSsRko537A6qpEJb2BIwcauc7eK3FHbZq99cEd2++/aq4Uex+YBLcIiD7Xi6+kan/dLLOqo11UIumL6L5CbPXhvQtYwhlgn9To5Lj6SzgNKkfjWmx6AVoKM3vD+a6Khbg6DCQGK4y3/kKcAxAQ75AFlAf9QVqJVwguFQMHxFBf8C2m7a1SZc9r2GZHDcUTGq6qifuNZdUf9HxXDe/IJdRJXWku2lOqplkfOwK3GmeaxIgK9uz3HpBPBdnsu5mtkJtUiwWLPfOBowShl+t5o7tWeZhoSTKXISWDGe6VgSE8HA9Upnvx0+cUDHiZNBqFJfTgL1th34QLKOJ9T7nyWVXsRNVd7U7yB1CoZuK80wMbhkN7CGp+HgbzfXksmGa7qkNgLiPkgD8++nB/1rPgixR+O/gH1V0l4QtEV/YmaWLSAxl+dd2D95Kr4q5Yp9yYJxG+vSinI1g3bMUXy8ffmhblga6PckKbqLb1gRshIFnWsW40I0yC2WKDutoFCwkpwouPAgqMkXcbyIfEb2rh7qznIGamU0cIocFRMGN5ZtZk3m6u5JAOjiI5qVh6GqslB2w889bLXAcwe2ZFovWRvM+VxZA7A0ahtVtHSLlAxEKVwbLGRrDTz5NlFKBFgG3xQOyUw8Zx7GmMCZEFTQryRakDSiJ/9p/LITcTvt0Mi59Uuz2pbHjsNyApvgKRYH5st4zKGLCGyWZHYD1XbsBkM+bJ3CUtu+6YlD60jDSIPDT73cT9Wg4iWCIUD44740yXvFZT1xRvWakzGOeD8B19GW+KxBr/lSu7IhbCpXpeh1En1AW8+gh7KWLlMuhmz2mkBBk5pMcVjcN3WP0kE/dwMcwCV7BK6xVMHLBx7PH6gQJK/ZUIKiV0LmN3WduSyA0Ky1lgUl4fc0R3n79yYkTgmS0zuilY9IKiNHcN6K0/JEfPFZXSacSix0k+GxDTDwpIUKwreNZzb4qf+/qnTqhvgB2ry7m7UtOrEGXeuBffYtN3n/hgSiso175GS"

//#define SUMURELEASE   "-----BEGIN RSA PRIVATE KEY-----\nMIIBVAIBADANBgkqhkiG9w0BAQEFAASCAT4wggE6AgEAAkEAvYICEmiR60l0sG5i6pTRu93MeMVBKsk4k+x9sovRYOqWl5hFtAswDKeEwrV8nYxO5em+SZVPRoHnZ+nFSKRupwIDAQABAkB4cQxIDtXOqBzVlRKg7Hxv3gN6LkPAoaqnuQIaW+pyoQ2gyPVXOAQaDAp13R03Zf0burrm2rl8+5eNsdjrMWhBAiEA3gt0/1AnUvoLW4tPwnS+MzDXwLgRbvwa2De6fkgNtn8CIQDafM4/h61QfCaq9mXt9MOoGYYvnO/f2ZOzptJUz/7D2QIgBZOoFpl+w1jAXEY9dJbWCBcb9B0rYuw2CGQt7OoGXiUCIQCYkJvoqtIwKHFL4kCs18SkJiaYKsspkaHcyfmHNbJdiQIgKEMwkJMP/etaolnP45wvw3U++ZsMbXEVScaKNpxsZ9A=\n-----END RSA PRIVATE KEY-----\n"

#if APP == SIMU
#include "SimuConfig.h"
#endif

#if APP == SULAIDAI
#include "CashLoanConfig.h"
#endif

//#define KEY_DEBUG "-----BEGIN PRIVATE KEY-----\nMIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAMYC6ECqZv8VlIExd6q1Shis7VzZWflOV6dlqw0XFpqbbUwNNkLvgTN/QiHueBmbMvvfKB+6dSIbgdVleRnDb2UCYn5Dn8UynzOEl5oufQDUf3q61sgwzyZGS98UahplHs6PhoVW43884uk9nWGGISTmOL5MdcAugMI9D+Y0isLlAgMBAAECgYEApxEG4qCjnC+aB9Mz811Yci9dagydBGMcQ8ndI4NKeBIRiqxPDvTDHy8NHlH1FS3EO40SborEj42D4wflwF4L2kIxFRAypfuQLiJS/EAtOR/luwhcAaWaAjooRpgN7x0QMxd6hlwY8w2QOt0Ega+8L7xhUY9lxkUDECNWojOANqECQQDuqNG/v1WcsaauL4cq/QaaRt1Q+W//Fhlt4+QFDkoCJ4mOmjoDMwspbPfosr+7wYgF0DY8m+sCPg9bEC+/K32dAkEA1GYDh4DLX5Vm3L57B1hSk2BPdT+4pGllkYJQz11DKD282ZAfPWoO1MErP47V3UqEhF1fyOPGNL2aYphITZd76QJAIRzxRT6B3WTUsJRNl8xVjzBH4sVJIcZqLtIQwBbUc+oSbuO9KtZ5NP02hGXQrndSrSPPcqdbewsrTEI5rbeWDQJBAIuGE+1wWqiIcRCzBAh4KY5sZuXjnPxLzA/A5irB3frSS3szpIHoaKOz3SAcSTrb159H40MI9Uvx/TelR2HJD/kCQEsuREeuUNxspUUk2x4sP0w7A51VuExnBg2Cmk5kx6yykbNxdp5zCK0S3CCSrtKXwAx7vDjUUSpdqiICQJj65bc=\n-----END PRIVATE KEY-----"


std::string TDRSACrypto::javaRelfectDecrypt(JNIEnv *env,jobject instance,jstring crypto) {
#if HAS_DOUBLE_AES
    //第一重aes解密
    std::string de_base64 = TDBASE64::base64_decodestring(getCrypto());
    std::string plainText2 = TDAES::decodeAES(getKey2(),de_base64);
#if IS_LOG_OUT_MSG
    LOGD("第一次aes解密：%s",plainText2.c_str());
#endif
    //第二重aes解密
    std::string de_base64_2 = TDBASE64::base64_decodestring(plainText2);
    std::string plainText1 = TDAES::decodeAES(getKey1(),de_base64_2);
#if IS_LOG_OUT_MSG
    LOGD("最终明文private key:%s",plainText1.c_str());
#endif
    //java反射，不需要-----BEGIN RSA PRIVATE KEY-----\n头尾
    const char *simu = plainText1.c_str();
    plainText1 = plainText1.replace(0,32,"");
//    LOGD("去掉start:%s",plainText1.c_str());
    plainText1 = plainText1.replace(plainText1.size() - 1 - 33 - 1 - 1,plainText1.size() - 1,"");
#elif !HAS_DOUBLE_AES
    const char *simu = "MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAMYC6ECqZv8VlIExd6q1Shis7VzZWflOV6dlqw0XFpqbbUwNNkLvgTN/QiHueBmbMvvfKB+6dSIbgdVleRnDb2UCYn5Dn8UynzOEl5oufQDUf3q61sgwzyZGS98UahplHs6PhoVW43884uk9nWGGISTmOL5MdcAugMI9D+Y0isLlAgMBAAECgYEApxEG4qCjnC+aB9Mz811Yci9dagydBGMcQ8ndI4NKeBIRiqxPDvTDHy8NHlH1FS3EO40SborEj42D4wflwF4L2kIxFRAypfuQLiJS/EAtOR/luwhcAaWaAjooRpgN7x0QMxd6hlwY8w2QOt0Ega+8L7xhUY9lxkUDECNWojOANqECQQDuqNG/v1WcsaauL4cq/QaaRt1Q+W//Fhlt4+QFDkoCJ4mOmjoDMwspbPfosr+7wYgF0DY8m+sCPg9bEC+/K32dAkEA1GYDh4DLX5Vm3L57B1hSk2BPdT+4pGllkYJQz11DKD282ZAfPWoO1MErP47V3UqEhF1fyOPGNL2aYphITZd76QJAIRzxRT6B3WTUsJRNl8xVjzBH4sVJIcZqLtIQwBbUc+oSbuO9KtZ5NP02hGXQrndSrSPPcqdbewsrTEI5rbeWDQJBAIuGE+1wWqiIcRCzBAh4KY5sZuXjnPxLzA/A5irB3frSS3szpIHoaKOz3SAcSTrb159H40MI9Uvx/TelR2HJD/kCQEsuREeuUNxspUUk2x4sP0w7A51VuExnBg2Cmk5kx6yykbNxdp5zCK0S3CCSrtKXwAx7vDjUUSpdqiICQJj65bc=";
#endif

//    plainText1.erase(plainText1.size() - 1,1);
//    LOGD("去掉end:%s",plainText1.c_str());
//    const char *simu = "MIIBVQIBADANBgkqhkiG9w0BAQEFAASCAT8wggE7AgEAAkEAuKQVsu9bCyEvkZXM0FXzAgb/uWcPKKuTeULip32LWbUz2qBZRKhi+m3HU3vXEIcaq3Td8t9dJC+HR6PhdM/q7wIDAQABAkAIZgZKplKI1hCY2ayASXiNPg5Bu6tX2T4TBPTUU4SUJvMRrrvq8d1PsHHS6QMh8eqaoclWPVG7nxc0v42Xm0NpAiEA4yUjXiw1ykSFesGXwz/Ee0Ma3Nn4lhmNscdXfAz7WwMCIQDQGLF8dETjSlMAG9Ll9fDdBTc6CBlcjxHrJ/OR4FQWpQIhANIl9O/WpTlqZbfpzhfVMln7/qlffI6aO67Dx9u8QvyzAiAOYxaqRxOYL0RLxqCvG3Dapwipb3PpbU7M1kdFt5+4rQIhALQhBipwK0P5hswUeDuPTdky1SKLYcZYLuFunn2g3k2B";
    jstring privateKey = env->NewStringUTF(simu);

    jclass base64 = env->FindClass("android/util/Base64");
    jmethodID base64decodem = env->GetStaticMethodID(base64,"decode","(Ljava/lang/String;I)[B");
    jbyteArray base64byte = (jbyteArray) env->CallStaticObjectMethod(base64, base64decodem, privateKey, 0);

    jclass PKCS8EncodedKeySpec = env->FindClass("java/security/spec/PKCS8EncodedKeySpec");
    jmethodID constructPKCS8 = env->GetMethodID(PKCS8EncodedKeySpec, "<init>", "([B)V");
    jobject pkcs8Obj = env->NewObject(PKCS8EncodedKeySpec,constructPKCS8,base64byte);

    jclass KeyFactory = env->FindClass("java/security/KeyFactory");
    jmethodID getInstanceKeyFac = env->GetStaticMethodID(KeyFactory,"getInstance","(Ljava/lang/String;)Ljava/security/KeyFactory;");
    jobject keyFactoryInstance = env->CallStaticObjectMethod(KeyFactory,getInstanceKeyFac,env->NewStringUTF("RSA"));

    jmethodID generatePrivate = env->GetMethodID(KeyFactory,"generatePrivate","(Ljava/security/spec/KeySpec;)Ljava/security/PrivateKey;");
    jobject   myprikey = env->CallObjectMethod(keyFactoryInstance,generatePrivate,pkcs8Obj);

    jclass Cipher = env->FindClass("javax/crypto/Cipher");
    jmethodID getInstanceCipher = env->GetStaticMethodID(Cipher,"getInstance","(Ljava/lang/String;)Ljavax/crypto/Cipher;");
    jobject cipherObj = env->CallStaticObjectMethod(Cipher,getInstanceCipher,env->NewStringUTF("RSA"));
    jmethodID cipherObjinit = env->GetMethodID(Cipher,"init","(ILjava/security/Key;)V");
    env->CallVoidMethod(cipherObj,cipherObjinit,2,myprikey);

    jbyteArray base64CryptoData = (jbyteArray) env->CallStaticObjectMethod(base64, base64decodem, crypto, 0);
    jmethodID doFinal = env->GetMethodID(Cipher,"doFinal","([B)[B");
    jbyteArray output = (jbyteArray) env->CallObjectMethod(cipherObj, doFinal, base64CryptoData);

    jclass String = env->FindClass("java/lang/String");
    jmethodID StringConstruct = env->GetMethodID(String,"<init>","([B)V");
    jstring decryptoString = (jstring) env->NewObject(String, StringConstruct, output);
    const char *string = env->GetStringUTFChars(decryptoString,0);
    std::string result;
    result.clear();
    result.assign(string);
    env->ReleaseStringUTFChars(decryptoString,string);
    return result;
}

/**
 *
 * @param data
 * @return
 * @deprecated
 */
std::string TDRSACrypto::decrypt(const std::string& data){
    //第一重aes解密
    std::string de_base64 = TDBASE64::base64_decodestring(getCrypto());
    std::string plainText2 = TDAES::decodeAES(getKey2(),de_base64);
#if IS_LOG_OUT_MSG
    LOGD("第一次aes解密：%s",plainText2.c_str());
#endif
    //第二重aes解密
    std::string de_base64_2 = TDBASE64::base64_decodestring(plainText2);
    std::string plainText1 = TDAES::decodeAES(getKey1(),de_base64_2);
#if IS_LOG_OUT_MSG
    LOGD("最终明文private key:%s",plainText1.c_str());
#endif
    const char *key = plainText1.c_str();
    LOGD("key:%s",key);
//    LOGD("src:%s",TDBASE64::base64_encodestring();

    int ret, flen;
    BIO *bio = NULL;
    RSA *r = NULL;

    if ((bio = BIO_new_mem_buf((void *)key, -1)) == NULL)       //从字符串读取RSA公钥
    {
        LOGE("BIO_new_mem_buf failed!\n");
        return NULL;
    }

    r = PEM_read_bio_RSAPrivateKey(bio, NULL, NULL, NULL);


    flen = RSA_size(r);


    static std::string gkbn;
    gkbn.clear();



    const char *gkbnP=gkbn.c_str();


    const char *dataP=data.c_str();


    ret =RSA_private_decrypt(flen ,(const unsigned char *)dataP, ( unsigned char *)gkbnP, r,
                             RSA_PKCS1_PADDING);//RSA_NO_PADDING //RSA_PKCS1_PADDING

    RSA_free(r);

    CRYPTO_cleanup_all_ex_data(); //清除管理CRYPTO_EX_DATA的全局hash表中的数据，避免内存泄漏


    return  gkbn;
}

/**
 * 签名实现函数
 * @param src 待签名字符串
 * @return
 */


std::string TDRSACrypto::rsaSha1Sign(const std::string *src) {
//    /**********************测试生成rsa pri key密文************************/
//    std::string crypto1 = TDAES::encodeAES(getKey1(),KEY_DEBUG);
//    std::string crypto1_base64 = TDBASE64::base64_encodestring(crypto1);
//    LOGD("crypto1:%s",crypto1_base64.c_str());
//    std::string crypto2 = TDAES::encodeAES(getKey2(),crypto1_base64);
//    std::string crypto2_base64 = TDBASE64::base64_encodestring(crypto2);
//    LOGD("需要保存的crypto2length%d\n:%s",crypto2_base64.length(),crypto2_base64.c_str());
//    /**********************测试生成rsa pri key密文************************/
#if HAS_DOUBLE_AES
    //第一重aes解密
    std::string de_base64 = TDBASE64::base64_decodestring(getCrypto());
    std::string plainText2 = TDAES::decodeAES(getKey2(),de_base64);
#if IS_LOG_OUT_MSG
    LOGD("第一次aes解密：%s",plainText2.c_str());
#endif
    //第二重aes解密
    std::string de_base64_2 = TDBASE64::base64_decodestring(plainText2);
    std::string plainText1 = TDAES::decodeAES(getKey1(),de_base64_2);
    const char *key = plainText1.c_str();
#if IS_LOG_OUT_MSG
    LOGD("第二次解密最终明文长度%d\nprivate key:%s",plainText1.length(),plainText1.c_str());

#endif
#elif !HAS_DOUBLE_AES
    std::string cryptoKey = getCrypto();
    const char *key = cryptoKey.c_str();"-----BEGIN PRIVATE KEY-----\nMIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAMYC6ECqZv8VlIExd6q1Shis7VzZWflOV6dlqw0XFpqbbUwNNkLvgTN/QiHueBmbMvvfKB+6dSIbgdVleRnDb2UCYn5Dn8UynzOEl5oufQDUf3q61sgwzyZGS98UahplHs6PhoVW43884uk9nWGGISTmOL5MdcAugMI9D+Y0isLlAgMBAAECgYEApxEG4qCjnC+aB9Mz811Yci9dagydBGMcQ8ndI4NKeBIRiqxPDvTDHy8NHlH1FS3EO40SborEj42D4wflwF4L2kIxFRAypfuQLiJS/EAtOR/luwhcAaWaAjooRpgN7x0QMxd6hlwY8w2QOt0Ega+8L7xhUY9lxkUDECNWojOANqECQQDuqNG/v1WcsaauL4cq/QaaRt1Q+W//Fhlt4+QFDkoCJ4mOmjoDMwspbPfosr+7wYgF0DY8m+sCPg9bEC+/K32dAkEA1GYDh4DLX5Vm3L57B1hSk2BPdT+4pGllkYJQz11DKD282ZAfPWoO1MErP47V3UqEhF1fyOPGNL2aYphITZd76QJAIRzxRT6B3WTUsJRNl8xVjzBH4sVJIcZqLtIQwBbUc+oSbuO9KtZ5NP02hGXQrndSrSPPcqdbewsrTEI5rbeWDQJBAIuGE+1wWqiIcRCzBAh4KY5sZuXjnPxLzA/A5irB3frSS3szpIHoaKOz3SAcSTrb159H40MI9Uvx/TelR2HJD/kCQEsuREeuUNxspUUk2x4sP0w7A51VuExnBg2Cmk5kx6yykbNxdp5zCK0S3CCSrtKXwAx7vDjUUSpdqiICQJj65bc=\n-----END PRIVATE KEY-----";
#endif

    unsigned char sign_value[1024]; //保存签名值的数组
    unsigned int sign_len;           //签名值长度
    EVP_MD_CTX mdctx;       //摘要算法上下文变量
    const char *mess1 = (*src).c_str();
    RSA *rsa=NULL;          //RSA结构体变量
    EVP_PKEY *evpKey=NULL;      //EVP KEY结构体变量
    int i;

#if IS_LOG_OUT_MSG
    LOGD("正在产生RSA密钥...");
#endif
//    rsa = RSA_generate_key(1024,RSA_F4,NULL,NULL);//产生一个1024位的RSA密钥//LOGD ("bits: %d\n", BN_num_bits (rsa->n));//返回n的二进制位数！1024！
    /*************************/
    BIO *bio = NULL;
    if ((bio = BIO_new_mem_buf((void *)key, -1)) == NULL)       //从字符串读取RSA公私钥
    {
        LOGE("BIO_new_mem_buf failed!\n");
        return NULL;
    }

//    rsa = PEM_read_bio_RSAPrivateKey(bio, NULL, NULL, NULL);
    rsa = RSA_new();
    PEM_read_bio_RSAPrivateKey(bio,&rsa,0,0);//读取私钥
    int flen = RSA_size(rsa);//测试多少位加密
//    LOGD("bit加密位数:%d",flen);
    /********************8*****/

    if(rsa == NULL)
    {
        LOGD("gen rsa err\n");
        return NULL;
    }
#if IS_LOG_OUT_MSG
    LOGD(" 成功.\n");
#endif
    evpKey = EVP_PKEY_new();//新建一个EVP_PKEY变量
    if(evpKey == NULL)
    {
        LOGD("EVP_PKEY_new err\n");
        RSA_free(rsa);
        return NULL;
    }
    if(EVP_PKEY_set1_RSA(evpKey,rsa) != 1)  //保存RSA结构体到EVP_PKEY结构体
    {
        LOGD("EVP_PKEY_set1_RSA err\n");
        RSA_free(rsa);
        EVP_PKEY_free(evpKey);
        return NULL;
    }
    //以下是计算签名代码
    EVP_MD_CTX_init(&mdctx);//初始化摘要上下文
    if(!EVP_SignInit_ex(&mdctx, EVP_sha1(), NULL))//签名初始化，设置摘要算法，本例为sha1
    {
        LOGD("err\n");
        EVP_PKEY_free(evpKey);
        RSA_free(rsa);
        return NULL;
    }
    if(!EVP_SignUpdate(&mdctx, mess1, strlen(mess1)))//计算签名（摘要）Update
    {
        LOGD("err\n");
        EVP_PKEY_free(evpKey);
        RSA_free(rsa);
        return NULL;
    }
    if(!EVP_SignFinal(&mdctx, sign_value, &sign_len, evpKey))  //签名输出
    {
        LOGD("err\n");
        EVP_PKEY_free(evpKey);
        RSA_free(rsa);
        return NULL;
    }
#if IS_LOG_OUT_MSG
    LOGD("消息\"%s\"的签名值是: \n",mess1);
    for(i = 0; i < sign_len; i++)
    {
        if(i%16==0)
            LOGD("\n%08xH: ",i);
        LOGD("%02x ", sign_value[i]);
    }
    LOGD("\n");
#endif
    /*******************************/
    std::string msgC;
    char * t = (char *) sign_value;
    msgC.assign(t,sign_len);
    std::string base64 = TDBASE64::base64_encodestring(msgC);
#if IS_LOG_OUT_MSG
    LOGD("%s:",base64.c_str());
#endif
    /********************************/
    EVP_MD_CTX_cleanup(&mdctx);

#if IS_VERFY_SIGN
    LOGD("\n正在验证签名...\n");
    //以下是验证签名代码
    EVP_MD_CTX_init(&mdctx);//初始化摘要上下文
    if(!EVP_VerifyInit_ex(&mdctx, EVP_sha1(), NULL))//验证初始化，设置摘要算法，一定要和签名一致。
    {
        LOGD("EVP_VerifyInit_ex err\n");
        EVP_PKEY_free(evpKey);
        RSA_free(rsa);
        return NULL;
    }
    if(!EVP_VerifyUpdate(&mdctx, mess1, strlen(mess1)))//验证签名（摘要）Update
    {
        LOGD("err\n");
        EVP_PKEY_free(evpKey);
        RSA_free(rsa);
        return NULL;
    }
    if(!EVP_VerifyFinal(&mdctx,sign_value,sign_len,evpKey))//验证签名
    {
        LOGD("verify err\n");
        EVP_PKEY_free(evpKey);
        RSA_free(rsa);
        return NULL;
    }
    else
    {
        LOGD("验证签名正确.\n");
    }
#endif
    //释放内存
    EVP_PKEY_free(evpKey);
    RSA_free(rsa);
    EVP_MD_CTX_cleanup(&mdctx);
    //删除所有换行符
    for (unsigned int j = 0; j < base64.size(); ++j) {
        if (base64[j] == '\n') {
            base64.erase(j,1);
        }
    }
    return base64;
}

/**
 * 析构函数，释放对象时自动调用
 */
TDRSACrypto::~TDRSACrypto() {

}

/**
 * 构造函数
 * @return
 */
TDRSACrypto::TDRSACrypto() {

}


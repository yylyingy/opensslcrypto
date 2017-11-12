//
// Created by gzbd on 2016/12/7.
//

#include "TDMD5.h"
#include "Log.h"
//#include <algorithm>
#include <md5.h>
#include <string.h>
#include <stdio.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <pem.h>

static void testSign() ;

std::string TDMD5::encryptMD5(const std::string& msg){


    std::string md5Result;

    unsigned  char  md[16];
    int  i;
    char  tmp[3]={ '\0' },buf[33]={ '\0' };
    MD5((const unsigned char *) msg.c_str(), msg.length(), md);
    for  (i = 0; i < 16; i++){
//        LOGD (tmp, "%2.2x" ,md[i]);
        strcat (buf,tmp);
    }
//    LOGD ( "%s\n" ,buf);
    md5Result.assign(buf);

//    transform(md5Result.begin(), md5Result.end(), md5Result.begin(), ::toupper);//转大写

//    testSign();
    return  md5Result;


}

//#define PRIVATE_KEY "MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAMYC6ECqZv8VlIExd6q1Shis7VzZWflOV6dlqw0XFpqbbUwNNkLvgTN/QiHueBmbMvvfKB+6dSIbgdVleRnDb2UCYn5Dn8UynzOEl5oufQDUf3q61sgwzyZGS98UahplHs6PhoVW43884uk9nWGGISTmOL5MdcAugMI9D+Y0isLlAgMBAAECgYEApxEG4qCjnC+aB9Mz811Yci9dagydBGMcQ8ndI4NKeBIRiqxPDvTDHy8NHlH1FS3EO40SborEj42D4wflwF4L2kIxFRAypfuQLiJS/EAtOR/luwhcAaWaAjooRpgN7x0QMxd6hlwY8w2QOt0Ega+8L7xhUY9lxkUDECNWojOANqECQQDuqNG/v1WcsaauL4cq/QaaRt1Q+W//Fhlt4+QFDkoCJ4mOmjoDMwspbPfosr+7wYgF0DY8m+sCPg9bEC+/K32dAkEA1GYDh4DLX5Vm3L57B1hSk2BPdT+4pGllkYJQz11DKD282ZAfPWoO1MErP47V3UqEhF1fyOPGNL2aYphITZd76QJAIRzxRT6B3WTUsJRNl8xVjzBH4sVJIcZqLtIQwBbUc+oSbuO9KtZ5NP02hGXQrndSrSPPcqdbewsrTEI5rbeWDQJBAIuGE+1wWqiIcRCzBAh4KY5sZuXjnPxLzA/A5irB3frSS3szpIHoaKOz3SAcSTrb159H40MI9Uvx/TelR2HJD/kCQEsuREeuUNxspUUk2x4sP0w7A51VuExnBg2Cmk5kx6yykbNxdp5zCK0S3CCSrtKXwAx7vDjUUSpdqiICQJj65bc="
//
//static void testSign() {
//    uint8_t sign_value[1024];
//    uint32_t sign_len;
//    EVP_MD_CTX md_ctx;
//    char* msg = "Test Message";
//    EVP_PKEY* evp_key = NULL;
//
//
//    RSA *rsa = NULL;
//    LOGD("正在产生rsa...\n");
//    rsa = RSA_generate_key(1024, RSA_F4, NULL, NULL);
//    BIO *bio = NULL;
//    if ((bio = BIO_new_mem_buf((void *)PRIVATE_KEY, -1)) == NULL)       //从字符串读取RSA公钥
//    {
//        LOGE("BIO_new_mem_buf failed!\n");
//    }
//
//    rsa = PEM_read_bio_RSAPrivateKey(bio, NULL, NULL, NULL);
////    if (rsa == NULL) {
////        LOGD("RSA_generate_key_ex error\n");
////        return;
////    }
//    LOGD("产生rsa成功\n");
//
//    evp_key = EVP_PKEY_new();
//    if (evp_key == NULL) {
//        LOGD("EVP_PKEY_new error\n");
//        RSA_free(rsa);
//        return;
//    }
//
//
//    if (!EVP_PKEY_set1_RSA(evp_key, rsa)) {
//        RSA_free(rsa);
//        EVP_PKEY_free(evp_key);
//    }
//
//
//    EVP_MD_CTX_init(&md_ctx);
//
//
//    EVP_SignInit_ex(&md_ctx, EVP_sha1(), NULL);
//
//
//    EVP_SignUpdate(&md_ctx, msg, strlen(msg));
//
//
//    EVP_SignFinal(&md_ctx, sign_value, &sign_len, evp_key);
//
//
//    LOGD("签名信息：");
//
//
//    for (int i = 0 ; i < sign_len; i++) {
//        if (i%16 == 0)
//            LOGD("\n%08xH: ", i);
//        LOGD("0x%02x ", sign_value[i]);
//    }
//    LOGD("\n");
//
//
//    EVP_MD_CTX_cleanup(&md_ctx);
//
//
//    EVP_MD_CTX_init(&md_ctx);
//
//
//    EVP_VerifyInit(&md_ctx, EVP_md5());
//
//
//    EVP_VerifyUpdate(&md_ctx, msg, strlen(msg));
//
//
//    LOGD("开始验证...\n");
//    int ret = EVP_VerifyFinal(&md_ctx, sign_value, sign_len, evp_key);
//    LOGD("验证结果: ");
//    if (ret == 1) {
//        LOGD("签名验证正确\n");
//    } else {
//        LOGD("签名验证错误\n");
//    }
//
//
//    EVP_PKEY_free(evp_key);
//    RSA_free(rsa);
//    EVP_MD_CTX_cleanup(&md_ctx);
//    return;
//}
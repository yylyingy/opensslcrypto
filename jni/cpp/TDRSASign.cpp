//
// Created by Yangyl on 2017/8/5.
//

#include "TDRSASign.h"
#include <evp.h>
#include <rsa.h>
#include <pem.h>
#include "Log.h"
#include "TDBASE64.h"
#include "TDAES.h"
//私钥，后面会用aes加密保存
//#define PRIVATE_KEY "-----BEGIN RSA PRIVATE KEY-----\nMIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAMYC6ECqZv8VlIExd6q1Shis7VzZWflOV6dlqw0XFpqbbUwNNkLvgTN/QiHueBmbMvvfKB+6dSIbgdVleRnDb2UCYn5Dn8UynzOEl5oufQDUf3q61sgwzyZGS98UahplHs6PhoVW43884uk9nWGGISTmOL5MdcAugMI9D+Y0isLlAgMBAAECgYEApxEG4qCjnC+aB9Mz811Yci9dagydBGMcQ8ndI4NKeBIRiqxPDvTDHy8NHlH1FS3EO40SborEj42D4wflwF4L2kIxFRAypfuQLiJS/EAtOR/luwhcAaWaAjooRpgN7x0QMxd6hlwY8w2QOt0Ega+8L7xhUY9lxkUDECNWojOANqECQQDuqNG/v1WcsaauL4cq/QaaRt1Q+W//Fhlt4+QFDkoCJ4mOmjoDMwspbPfosr+7wYgF0DY8m+sCPg9bEC+/K32dAkEA1GYDh4DLX5Vm3L57B1hSk2BPdT+4pGllkYJQz11DKD282ZAfPWoO1MErP47V3UqEhF1fyOPGNL2aYphITZd76QJAIRzxRT6B3WTUsJRNl8xVjzBH4sVJIcZqLtIQwBbUc+oSbuO9KtZ5NP02hGXQrndSrSPPcqdbewsrTEI5rbeWDQJBAIuGE+1wWqiIcRCzBAh4KY5sZuXjnPxLzA/A5irB3frSS3szpIHoaKOz3SAcSTrb159H40MI9Uvx/TelR2HJD/kCQEsuREeuUNxspUUk2x4sP0w7A51VuExnBg2Cmk5kx6yykbNxdp5zCK0S3CCSrtKXwAx7vDjUUSpdqiICQJj65bc=\n-----END RSA PRIVATE KEY-----\n"
//双重aes加密密文,需要解密成明文,明文才是需要的text
//#define CRYPTO_TEXT "2ZBHFW5fA06In/rGyvXrw0707aPFvwlxRlyo7ILLpqx4ZMOGzoZkbyRcg9gK6goxq1EbzlDGeoUa8wqMKWbr8rJFCSi0hsi/Xn+XdIbPyyezVYJ1fxxuQCdsxQCStB9gY32unHpu7YlBa+mXJHAykwFfUKfqE+mO5iuUanesPqOzer5ajN4L9EFZUFbheBM9F7/wTrhxZIjWf8vBXGq78Mlhu25AYruHTVvS0W47qXd9HjomvnC4d5JOchwQKzxC4Bk/Z5PqFIPL9Q1aHsa+t5WI1t/LHJ8AwtaDgaHlm9rz1KRToH94StB0PmvEdPTxQZafI5hadLXNuXunog080EZ5UQ5lVt3td/m0rgf3ClN6XEZWKFQSWVRnJE4BLrcnQVl1BRAgaG4w3bamyCbzzhQ2cGiMH1gOIoUl+C0/RwobHPlOd/fqySveQZHKnVPiiQDqwks9MADRMUBcL9Oou6UbM/5PQ3LQs3rSsaJG/pPgvkJ48U9zIKP/T5i+l4QQZi4OrcI5eEyzfKOH5ovjAGrE3h7esXczHegwomV3WNMLxrqWDstgoAVTnM/MdQjvRKHCyRBU0wcZIV+OTxMHh9e0W0KPp6KlgC5kGZEgxKqpkB2c4A5oW30161IIgm0HVbV+95Ek7xSsRko537A6qpEJb2BIwcauc7eK3FHbZq99cEd2++/aq4Uex+YBLcIiD7Xi6+kan/dLLOqo11UIumL6L5CbPXhvQtYwhlgn9To5Lj6SzgNKkfjWmx6AVoKM3vD+a6Khbg6DCQGK4y3/kKcAxAQ75AFlAf9QVqJVwguFQMHxFBf8C2m7a1SZc9r2GZHDcUTGq6qifuNZdUf9HxXDe/IJdRJXWku2lOqplkfOwK3GmeaxIgK9uz3HpBPBdnsu5mtkJtUiwWLPfOBowShl+t5o7tWeZhoSTKXISWDGe6VgSE8HA9Upnvx0+cUDHiZNBqFJfTgL1th34QLKOJ9T7nyWVXsRNVd7U7yB1CoZuK80wMbhkN7CGp+HgbzfXksmGa7qkNgLiPkgD8++nB/1rPgixR+O/gH1V0l4QtEV/YmaWLSAxl+dd2D95Kr4q5Yp9yYJxG+vSinI1g3bMUXy8ffmhblga6PckKbqLb1gRshIFnWsW40I0yC2WKDutoFCwkpwouPAgqMkXcbyIfEb2rh7qznIGamU0cIocFRMGN5ZtZk3m6u5JAOjiI5qVh6GqslB2w889bLXAcwe2ZFovWRvM+VxZA7A0ahtVtHSLlAxEKVwbLGRrDTz5NlFKBFgG3xQOyUw8Zx7GmMCZEFTQryRakDSiJ/9p/LITcTvt0Mi59Uuz2pbHjsNyApvgKRYH5st4zKGLCGyWZHYD1XbsBkM+bJ3CUtu+6YlD60jDSIPDT73cT9Wg4iWCIUD44740yXvFZT1xRvWakzGOeD8B19GW+KxBr/lSu7IhbCpXpeh1En1AW8+gh7KWLlMuhmz2mkBBk5pMcVjcN3WP0kE/dwMcwCV7BK6xVMHLBx7PH6gQJK/ZUIKiV0LmN3WduSyA0Ky1lgUl4fc0R3n79yYkTgmS0zuilY9IKiNHcN6K0/JEfPFZXSacSix0k+GxDTDwpIUKwreNZzb4qf+/qnTqhvgB2ry7m7UtOrEGXeuBffYtN3n/hgSiso175GS"


/**
 * 获取双重aes加密密文，需要解密成明文,明文才是需要的key
 * @return 密文
 */
static std::string getCrypto();

/**
 * 计算key2
 * @return key2
 */
static std::string getKey2() {
    std::string key0 = "f";
    std::string key1 = "2";
    std::string key2 = "8";
    std::string key3 = "9";
    std::string key4 = "d";
    std::string key5 = "0";
    std::string key6 = "2";
    std::string key7 = "1";
    std::string key8 = "8";
    std::string key9 = "1";
    std::string key10 = "2";
    std::string key11 = "c";
    std::string key12 = "e";
    std::string key13 = "a";
    std::string key14 = "6";
    std::string key15 = "1";
    std::string key16 = "d";
    std::string key17 = "d";
    std::string key18 = "0";
    std::string key19 = "8";
    std::string key20 = "5";
    std::string key21 = "2";
    std::string key22 = "8";
    std::string key23 = "b";
    std::string key24 = "9";
    std::string key25 = "e";
    std::string key26 = "f";
    std::string key27 = "5";
    std::string key28 = "b";
    std::string key29 = "6";
    std::string key30 = "6";
    std::string key31 = "b";
    std::string key32 = "2";
    std::string key33 = "2";
    std::string key34 = "b";
    std::string key35 = "6";
    std::string key36 = "3";
    std::string key37 = "a";
    std::string key38 = "9";
    std::string key39 = "7";
    std::string key40 = "d";
    std::string key41 = "3";
    std::string key42 = "7";
    std::string key43 = "b";
    std::string key44 = "4";
    std::string key45 = "8";
    std::string key46 = "6";
    std::string key47 = "c";
    std::string key48 = "7";
    std::string key49 = "0";
    std::string key50 = "7";
    std::string key51 = "c";
    std::string key52 = "d";
    std::string key53 = "2";
    std::string key54 = "c";
    std::string key55 = "a";
    std::string key56 = "c";
    std::string key57 = "e";
    std::string key58 = "b";
    std::string key59 = "a";
    std::string key60 = "c";
    std::string key61 = "6";
    std::string key62 = "d";
    std::string key63 = "7";
    std::string key = key0 + key1 + key2 + key3 + key4 + key5 + key6 + key7 + key8 + key9 + key10 + key11 + key12 + key13 + key14 + key15 + key16 + key17 + key18 + key19 + key20 + key21 + key22 + key23 + key24 + key25 + key26 + key27 + key28 + key29 + key30 + key31 + key32 + key33 + key34 + key35 + key36 + key37 + key38 + key39 + key40 + key41 + key42 + key43 + key44 + key45 + key46 + key47 + key48 + key49 + key50 + key51 + key52 + key53 + key54 + key55 + key56 + key57 + key58 + key59 + key60 + key61 + key62 + key63 ;
    return key;
}

/**
 * 计算key1
 * @return key1
 */
static std::string getKey1() {
    std::string key0 = "c";
    std::string key1 = "c";
    std::string key2 = "c";
    std::string key3 = "4";
    std::string key4 = "2";
    std::string key5 = "1";
    std::string key6 = "6";
    std::string key7 = "a";
    std::string key8 = "4";
    std::string key9 = "0";
    std::string key10 = "a";
    std::string key11 = "3";
    std::string key12 = "7";
    std::string key13 = "e";
    std::string key14 = "d";
    std::string key15 = "0";
    std::string key16 = "4";
    std::string key17 = "a";
    std::string key18 = "6";
    std::string key19 = "a";
    std::string key20 = "4";
    std::string key21 = "9";
    std::string key22 = "7";
    std::string key23 = "d";
    std::string key24 = "1";
    std::string key25 = "8";
    std::string key26 = "b";
    std::string key27 = "a";
    std::string key28 = "9";
    std::string key29 = "a";
    std::string key30 = "c";
    std::string key31 = "b";
    std::string key32 = "1";
    std::string key33 = "7";
    std::string key34 = "2";
    std::string key35 = "b";
    std::string key36 = "9";
    std::string key37 = "a";
    std::string key39 = "c";
    std::string key38 = "3";
    std::string key40 = "6";
    std::string key41 = "0";
    std::string key42 = "b";
    std::string key43 = "d";
    std::string key44 = "2";
    std::string key45 = "e";
    std::string key47 = "8";
    std::string key46 = "5";
    std::string key48 = "9";
    std::string key49 = "c";
    std::string key50 = "c";
    std::string key51 = "a";
    std::string key52 = "6";
    std::string key53 = "b";
    std::string key54 = "0";
    std::string key55 = "3";
    std::string key56 = "e";
    std::string key57 = "e";
    std::string key58 = "8";
    std::string key59 = "1";
    std::string key60 = "3";
    std::string key61 = "c";
    std::string key62 = "3";
    std::string key63 = "c";
    std::string key = key0 + key1 + key2 + key3 + key4 + key5 + key6 + key7 + key8 + key9 + key10 + key11 + key12 + key13 + key14 + key15 + key16 + key17 + key18 + key19 + key20 + key21 + key22 + key23 + key24 + key25 + key26 + key27 + key28 + key29 + key30 + key31 + key32 + key33 + key34 + key35 + key36 + key37 + key38 + key39 + key40 + key41 + key42 + key43 + key44 + key45 + key46 + key47 + key48 + key49 + key50 + key51 + key52 + key53 + key54 + key55 + key56 + key57 + key58 + key59 + key60 + key61 + key62 + key63 ;
    return key;
}

/**
 * 签名实现函数
 * @param src 待签名字符串
 * @return
 */

std::string TDRSASign::rsaSha1Sign(const std::string *src) {
    /**********************测试生成rsa pri key密文以及解密************************/
//    std::string crypto1 = TDAES::encodeAES(getKey1(),PRIVATE_KEY);
//    std::string crypto1_base64 = TDBASE64::base64_encodestring(crypto1);
//    LOGD("crypto1:%s",crypto1_base64.c_str());
//    std::string crypto2 = TDAES::encodeAES(getKey2(),crypto1_base64);
//    std::string crypto2_base64 = TDBASE64::base64_encodestring(crypto2);
//    LOGD("需要保存的crypto2:%s",crypto2_base64.c_str());
    /**********************测试生成rsa pri key密文以及解密************************/
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
    if ((bio = BIO_new_mem_buf((void *)key, -1)) == NULL)       //从字符串读取RSA公钥
    {
        LOGE("BIO_new_mem_buf failed!\n");
    }

//    rsa = PEM_read_bio_RSAPrivateKey(bio, NULL, NULL, NULL);
    rsa = RSA_new();
    PEM_read_bio_RSAPrivateKey(bio,&rsa,0,0);
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
TDRSASign::~TDRSASign() {

}

/**
 * 构造函数
 * @return
 */
TDRSASign::TDRSASign() {

}

/**
 * 获取双重aes加密密文，需要解密成明文,明文才是需要的key
 * @return 密文
 */
static std::string getCrypto() {
    std::string crypto0 = "2ZBHFW5fA0";
    std::string crypto10 = "6In/rGyvXr";
    std::string crypto20 = "w0707aPFvw";
    std::string crypto30 = "lxRlyo7ILL";
    std::string crypto40 = "pqx4ZMOGzo";
    std::string crypto50 = "ZkbyRcg9gK";
    std::string crypto70 = "DGeoUa8wqM";
    std::string crypto60 = "6goxq1Ebzl";
    std::string crypto80 = "KWbr8rJFCS";
    std::string crypto90 = "i0hsi/Xn+X";
    std::string crypto100 = "dIbPyyezVY";
    std::string crypto110 = "J1fxxuQCds";
    std::string crypto120 = "xQCStB9gY3";
    std::string crypto130 = "2unHpu7YlB";
    std::string crypto140 = "a+mXJHAykw";
    std::string crypto150 = "FfUKfqE+mO";
    std::string crypto160 = "5iuUanesPq";
    std::string crypto170 = "Ozer5ajN4L";
    std::string crypto180 = "9EFZUFbheB";
    std::string crypto190 = "M9F7/wTrhx";
    std::string crypto200 = "ZIjWf8vBXG";
    std::string crypto210 = "q78Mlhu25A";
    std::string crypto220 = "YruHTVvS0W";
    std::string crypto230 = "47qXd9Hjom";
    std::string crypto240 = "vnC4d5JOch";
    std::string crypto250 = "wQKzxC4Bk/";
    std::string crypto260 = "Z5PqFIPL9Q";
    std::string crypto270 = "1aHsa+t5WI";
    std::string crypto280 = "1t/LHJ8Awt";
    std::string crypto290 = "aDgaHlm9rz";
    std::string crypto300 = "1KRToH94St";
    std::string crypto310 = "B0PmvEdPTx";
    std::string crypto320 = "QZafI5hadL";
    std::string crypto330 = "XNuXunog08";
    std::string crypto340 = "0EZ5UQ5lVt";
    std::string crypto350 = "3td/m0rgf3";
    std::string crypto360 = "ClN6XEZWKF";
    std::string crypto370 = "QSWVRnJE4B";
    std::string crypto380 = "LrcnQVl1BR";
    std::string crypto390 = "AgaG4w3bam";
    std::string crypto400 = "yCbzzhQ2cG";
    std::string crypto410 = "iMH1gOIoUl";
    std::string crypto420 = "+C0/RwobHP";
    std::string crypto430 = "lOd/fqySve";
    std::string crypto440 = "QZHKnVPiiQ";
    std::string crypto450 = "Dqwks9MADR";
    std::string crypto460 = "MUBcL9Oou6";
    std::string crypto470 = "UbM/5PQ3LQ";
    std::string crypto480 = "s3rSsaJG/p";
    std::string crypto490 = "PgvkJ48U9z";
    std::string crypto500 = "IKP/T5i+l4";
    std::string crypto510 = "QQZi4OrcI5";
    std::string crypto520 = "eEyzfKOH5o";
    std::string crypto530 = "vjAGrE3h7e";
    std::string crypto540 = "sXczHegwom";
    std::string crypto550 = "V3WNMLxrqW";
    std::string crypto560 = "DstgoAVTnM";
    std::string crypto570 = "/MdQjvRKHC";
    std::string crypto580 = "yRBU0wcZIV";
    std::string crypto590 = "+OTxMHh9e0";
    std::string crypto600 = "W0KPp6KlgC";
    std::string crypto610 = "5kGZEgxKqp";
    std::string crypto620 = "kB2c4A5oW3";
    std::string crypto630 = "0161IIgm0H";
    std::string crypto640 = "VbV+95Ek7x";
    std::string crypto650 = "SsRko537A6";
    std::string crypto660 = "qpEJb2BIwc";
    std::string crypto670 = "auc7eK3FHb";
    std::string crypto680 = "Zq99cEd2++";
    std::string crypto690 = "/aq4Uex+YB";
    std::string crypto700 = "LcIiD7Xi6+";
    std::string crypto710 = "kan/dLLOqo";
    std::string crypto720 = "11UIumL6L5";
    std::string crypto730 = "CbPXhvQtYw";
    std::string crypto740 = "hlgn9To5Lj";
    std::string crypto750 = "6SzgNKkfjW";
    std::string crypto760 = "mx6AVoKM3v";
    std::string crypto770 = "D+a6Khbg6D";
    std::string crypto780 = "CQGK4y3/kK";
    std::string crypto790 = "cAxAQ75AFl";
    std::string crypto800 = "Af9QVqJVwg";
    std::string crypto810 = "uFQMHxFBf8";
    std::string crypto820 = "C2m7a1SZc9";
    std::string crypto830 = "r2GZHDcUTG";
    std::string crypto840 = "q6qifuNZdU";
    std::string crypto850 = "f9HxXDe/IJ";
    std::string crypto860 = "dRJXWku2lO";
    std::string crypto870 = "qplkfOwK3G";
    std::string crypto880 = "meaxIgK9uz";
    std::string crypto890 = "3HpBPBdnsu";
    std::string crypto900 = "5mtkJtUiwW";
    std::string crypto910 = "LPfOBowShl";
    std::string crypto920 = "+t5o7tWeZh";
    std::string crypto930 = "oSTKXISWDG";
    std::string crypto940 = "e6VgSE8HA9";
    std::string crypto950 = "Upnvx0+cUD";
    std::string crypto960 = "HiZNBqFJfT";
    std::string crypto970 = "gL1th34QLK";
    std::string crypto980 = "OJ9T7nyWVX";
    std::string crypto990 = "sRNVd7U7yB";
    std::string crypto1000 = "1CoZuK80wM";
    std::string crypto1010 = "bhkN7CGp+H";
    std::string crypto1020 = "gbzfXksmGa";
    std::string crypto1030 = "7qkNgLiPkg";
    std::string crypto1040 = "D8++nB/1rP";
    std::string crypto1050 = "gixR+O/gH1";
    std::string crypto1060 = "V0l4QtEV/Y";
    std::string crypto1070 = "maWLSAxl+d";
    std::string crypto1080 = "d2D95Kr4q5";
    std::string crypto1090 = "Yp9yYJxG+v";
    std::string crypto1100 = "SinI1g3bMU";
    std::string crypto1110 = "Xy8ffmhblg";
    std::string crypto1120 = "a6PckKbqLb";
    std::string crypto1130 = "1gRshIFnWs";
    std::string crypto1140 = "W40I0yC2WK";
    std::string crypto1150 = "DutoFCwkpw";
    std::string crypto1160 = "ouPAgqMkXc";
    std::string crypto1170 = "byIfEb2rh7";
    std::string crypto1180 = "qznIGamU0c";
    std::string crypto1200 = "tZk3m6u5JA";
    std::string crypto1190 = "IocFRMGN5Z";
    std::string crypto1210 = "OjiI5qVh6G";
    std::string crypto1220 = "qslB2w889b";
    std::string crypto1230 = "LXAcwe2ZFo";
    std::string crypto1240 = "vWRvM+VxZA";
    std::string crypto1250 = "7A0ahtVtHS";
    std::string crypto1260 = "LlAxEKVwbL";
    std::string crypto1270 = "GRrDTz5NlF";
    std::string crypto1280 = "KBFgG3xQOy";
    std::string crypto1290 = "Uw8Zx7GmMC";
    std::string crypto1300 = "ZEFTQryRak";
    std::string crypto1310 = "DSiJ/9p/LI";
    std::string crypto1320 = "TcTvt0Mi59";
    std::string crypto1330 = "Uuz2pbHjsN";
    std::string crypto1340 = "yApvgKRYH5";
    std::string crypto1350 = "st4zKGLCGy";
    std::string crypto1360 = "WZHYD1XbsB";
    std::string crypto1370 = "kM+bJ3CUtu";
    std::string crypto1380 = "+6YlD60jDS";
    std::string crypto1390 = "IPDT73cT9W";
    std::string crypto1400 = "g4iWCIUD44";
    std::string crypto1410 = "740yXvFZT1";
    std::string crypto1420 = "xRvWakzGOe";
    std::string crypto1430 = "D8B19GW+Kx";
    std::string crypto1440 = "Br/lSu7Ihb";
    std::string crypto1450 = "CpXpeh1En1";
    std::string crypto1460 = "AW8+gh7KWL";
    std::string crypto1470 = "lMuhmz2mkB";
    std::string crypto1480 = "Bk5pMcVjcN";
    std::string crypto1490 = "3WP0kE/dwM";
    std::string crypto1500 = "cwCV7BK6xV";
    std::string crypto1510 = "MHLBx7PH6g";
    std::string crypto1520 = "QJK/ZUIKiV";
    std::string crypto1530 = "0LmN3WduSy";
    std::string crypto1540 = "A0Ky1lgUl4";
    std::string crypto1550 = "fc0R3n79yY";
    std::string crypto1560 = "kTgmS0zuil";
    std::string crypto1570 = "Y9IKiNHcN6";
    std::string crypto1580 = "K0/JEfPFZX";
    std::string crypto1590 = "SacSix0k+G";
    std::string crypto1600 = "xDTDwpIUKw";
    std::string crypto1610 = "reNZzb4qf+";
    std::string crypto1620 = "/qnTqhvgB2";
    std::string crypto1630 = "ry7m7UtOrE";
    std::string crypto1640 = "GXeuBffYtN";
    std::string crypto1650 = "3n/hgSiso1";
    std::string crypto1660 = "75GS";
    std::string APIKey_Crypto_Text = crypto0.append(crypto10).append(crypto20).append(crypto30).append(crypto40).append(crypto50).append(crypto60).append(crypto70).append(crypto80).append(crypto90).append(crypto100)
            .append(crypto110).append(crypto120).append(crypto130).append(crypto140).append(crypto150).append(crypto160).append(crypto170).append(crypto180).append(crypto190).append(crypto200)
            .append(crypto210).append(crypto220).append(crypto230).append(crypto240).append(crypto250).append(crypto260).append(crypto270).append(crypto280).append(crypto290).append(crypto300)
            .append(crypto310).append(crypto320).append(crypto330).append(crypto340).append(crypto350).append(crypto360).append(crypto370).append(crypto380).append(crypto390).append(crypto400)
            .append(crypto410).append(crypto420).append(crypto430).append(crypto440).append(crypto450).append(crypto460).append(crypto470).append(crypto480).append(crypto490).append(crypto500)
            .append(crypto510).append(crypto520).append(crypto530).append(crypto540).append(crypto550).append(crypto560).append(crypto570).append(crypto580).append(crypto590).append(crypto600)
            .append(crypto610).append(crypto620).append(crypto630).append(crypto640).append(crypto650).append(crypto660).append(crypto670).append(crypto680).append(crypto690).append(crypto700)
            .append(crypto710).append(crypto720).append(crypto730).append(crypto740).append(crypto750).append(crypto760).append(crypto770).append(crypto780).append(crypto790).append(crypto800)
            .append(crypto810).append(crypto820).append(crypto830).append(crypto840).append(crypto850).append(crypto860).append(crypto870).append(crypto880).append(crypto890).append(crypto900)
            .append(crypto910).append(crypto920).append(crypto930).append(crypto940).append(crypto950).append(crypto960).append(crypto970).append(crypto980).append(crypto990).append(crypto1000)
            .append(crypto1010).append(crypto1020).append(crypto1030).append(crypto1040).append(crypto1050).append(crypto1060).append(crypto1070).append(crypto1080).append(crypto1090).append(crypto1100)
            .append(crypto1110).append(crypto1120).append(crypto1130).append(crypto1140).append(crypto1150).append(crypto1160).append(crypto1170).append(crypto1180).append(crypto1190).append(crypto1200)
            .append(crypto1210).append(crypto1220).append(crypto1230).append(crypto1240).append(crypto1250).append(crypto1260).append(crypto1270).append(crypto1280).append(crypto1290).append(crypto1300)
            .append(crypto1310).append(crypto1320).append(crypto1330).append(crypto1340).append(crypto1350).append(crypto1360).append(crypto1370).append(crypto1380).append(crypto1390).append(crypto1400)
            .append(crypto1410).append(crypto1420).append(crypto1430).append(crypto1440).append(crypto1450).append(crypto1460).append(crypto1470).append(crypto1480).append(crypto1490).append(crypto1500)
            .append(crypto1510).append(crypto1520).append(crypto1530).append(crypto1540).append(crypto1550).append(crypto1560).append(crypto1570).append(crypto1580).append(crypto1590).append(crypto1600)
            .append(crypto1610).append(crypto1620).append(crypto1630).append(crypto1640).append(crypto1650).append(crypto1660) ;
    return APIKey_Crypto_Text;
}


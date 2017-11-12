//
// Created by yangyinglong on 2017/7/13.
//

#include <sha.h>
#include <string.h>
#include <crypto.h>
#include <string>
#include "TDSha1.h"

// 打印前， 有必要转换
void TDSha1::printHash(unsigned char *md, int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        printf("%02x", md[i]);
    }

    printf("\n");
}

std::string  TDSha1::sha1(const std::string& msg)
{
    std::string sha1Result;
    SHA_CTX c;
    unsigned char md[SHA_DIGEST_LENGTH];
    char  tmp[3]={ '\0' },buf[SHA_DIGEST_LENGTH * 2 + 1]={ '\0' };
    SHA1((unsigned char *)msg.c_str(), msg.length(), md);
//    printHash(md, SHA_DIGEST_LENGTH);

    SHA1_Init(&c);
    SHA1_Update(&c, msg.c_str(), msg.length());
    SHA1_Final(md, &c);
    OPENSSL_cleanse(&c, sizeof(c));
    for  (int i = 0; i < SHA_DIGEST_LENGTH; i++){
        sprintf (tmp, "%2.2x" ,md[i]);
        strcat (buf,tmp);
    }
    sha1Result.assign(buf);
//    transform(sha1Result.begin(), sha1Result.end(), sha1Result.begin(), ::toupper);//转大写
    return sha1Result;
//    printHash(md, SHA_DIGEST_LENGTH);
}
//
// Created by yangyinglong on 2017/7/13.
//

#ifndef LIVECRYPTO_TDSHA1_H
#define LIVECRYPTO_TDSHA1_H

class TDSha1 {
public:
    static std::string sha1(const std::string& msg);
    static void printHash(unsigned char *md, int len);
};


#endif //LIVECRYPTO_TDSHA1_H

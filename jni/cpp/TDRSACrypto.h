//
// Created by Yangyl on 2017/8/5.
//

#ifndef ENCRYPTJNILIB_TDRSASIGN_H
#define ENCRYPTJNILIB_TDRSASIGN_H

#include <string>
#include <jni.h>

#define IS_VERFY_SIGN false
#define IS_LOG_OUT_MSG false
class TDRSACrypto {
public:
    TDRSACrypto();
    std::string decrypt(const std::string& data);
    std::string rsaSha1Sign(const std::string *src);
    std::string javaRelfectDecrypt(JNIEnv *env,jobject instance,jstring crypto);
    ~TDRSACrypto();
};

#endif //ENCRYPTJNILIB_TDRSASIGN_H

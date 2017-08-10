//
// Created by Yangyl on 2017/8/5.
//

#ifndef ENCRYPTJNILIB_TDRSASIGN_H
#define ENCRYPTJNILIB_TDRSASIGN_H

#include <string>

#define IS_VERFY_SIGN false
#define IS_LOG_OUT_MSG false
class TDRSASign {
public:
    TDRSASign();
    std::string rsaSha1Sign(const std::string *src);
    ~TDRSASign();
};

#endif //ENCRYPTJNILIB_TDRSASIGN_H

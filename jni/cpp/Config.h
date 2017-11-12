//
// Created by yangyinglong on 2017/8/24.
//

#ifndef ENCRYPTJNILIB_CONFIG_H
#define ENCRYPTJNILIB_CONFIG_H

/********************条件编译，区分非对称加密私钥**************************/
#define SIMU 1
#define CHEQUAN 2
#define SULAIDAI 3

//定义当前针对哪个app的so
#define APP SULAIDAI

#define HAS_DOUBLE_AES false
/********************条件编译,区分非对称加密私钥**************************/

//定义当前so是debug还是release,区分app用的线上还是正式非对称加密私钥，区分debug apk keystore和release key store
#define RELEASE false //改变这里，需要改变keystore配置,实际上改变build.gradle

class Config {

};


#endif //ENCRYPTJNILIB_CONFIG_H

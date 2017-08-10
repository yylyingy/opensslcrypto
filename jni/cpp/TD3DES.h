//
// Created by gzbd on 2016/12/7.
//

#ifndef RSADEMO_MY3DES_H
#define RSADEMO_MY3DES_H

#include <string>
#include <stdio.h>
#include <stdlib.h>


class TD3DES {

public:
    /*
     * 有自定义密码的3DES 加密
    */
    std::string  encryptDES(const std::string& data , std::string  k, int *lenreturn);
    std::string  decryptDES(const std::string& data,  std::string k, int data_len);
    /*
     * 自动生成密码的加解密，密码加解密一次后会自动生成新的，以前的数据解密会失败
     */
    std::string encryptDES(const std::string& data , int *lenreturn);
    std::string decryptDES(const std::string& data , int data_len);


private:

     static std::string getKey();
};


#endif //RSADEMO_MY3DES_H

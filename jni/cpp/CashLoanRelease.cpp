//
// Created by yangyinglong on 2017/9/19.
//

#include <string>
#include "Config.h"
#include "CashLoanConfig.h"
#if APP == SULAIDAI
#if RELEASE

/**
 * 获取apk签名
 * @return apk签名
 */
std::string getApkSign() {
    std::string key0 = "3082037930820261a003020102020450d9aa3830";
    std::string key40 = "0d06092a864886f70d01010b0500306c310b3009";
    std::string key80 = "0603550406130238363112301006035504081309";
    std::string key120 = "6775616e67646f6e673111300f06035504071308";
    std::string key160 = "646f6e676775616e3111300f060355040a130870";
    std::string key200 = "61697368656e673110300e060355040b13077475";
    std::string key240 = "616e6461693111300f0603550403130873756c61";
    std::string key280 = "696461693020170d313730383130303232393533";
    std::string key320 = "5a180f32313137303731373032323935335a306c";
    std::string key360 = "310b300906035504061302383631123010060355";
    std::string key400 = "040813096775616e67646f6e673111300f060355";
    std::string key440 = "04071308646f6e676775616e3111300f06035504";
    std::string key480 = "0a13087061697368656e673110300e060355040b";
    std::string key520 = "13077475616e6461693111300f06035504031308";
    std::string key560 = "73756c616964616930820122300d06092a864886";
    std::string key600 = "f70d01010105000382010f003082010a02820101";
    std::string key640 = "00f07506765a5a15ab10147c79d2c4364b97e18b";
    std::string key680 = "a9e1745a463cfb3d8e4b1b2f756c4f4842965ae9";
    std::string key720 = "84985534f429d94de8b5c593c014b619268266d4";
    std::string key760 = "1c2ab06440a79cdb33137cfb907a6b2a9206c071";
    std::string key800 = "17becf87b73d1657ff9207701ea705125e5bbb9c";
    std::string key840 = "c6da125a199e76609de4d7508d4eb7fc6a7a77ed";
    std::string key880 = "85e931fc73c0d8bb003e70f86a7f2a6cafefe717";
    std::string key920 = "9d40571220f4725bbf45d188cb8009835b5b6ece";
    std::string key960 = "562d913c2a3126d8a3e2a4a39997529a68a2837c";
    std::string key1000 = "e30b673d0bb916818fc4f1d9282cf8789dbbdaa0";
    std::string key1040 = "63863386cc521cf5012042c515f6fa9cf19260a8";
    std::string key1080 = "93a506a30c308c46bb62eb763ab67d4c24722263";
    std::string key1120 = "ba779900cc6e2ca5543332adce95ca75bf020301";
    std::string key1160 = "0001a321301f301d0603551d0e04160414921cf0";
    std::string key1200 = "bd74d296b89a414214ac818fd0a22f0a20300d06";
    std::string key1240 = "092a864886f70d01010b050003820101003894af";
    std::string key1280 = "72e822d9cabd8424e15a343f2084dac33864f8d2";
    std::string key1320 = "58a5e11b7aace2a5b04a710d351c1747206ee626";
    std::string key1360 = "ac80711389aa427aab08f3ae33e62cf158a6f308";
    std::string key1400 = "8497dff37f078bfe5b72fa497c9831652ef50e00";
    std::string key1440 = "f1f8bcf559e46cf2854594351d0a289ecc6ad445";
    std::string key1480 = "e5d4a9fb1639ce395db87686f1470d840693043a";
    std::string key1520 = "98417685dfdad08cb3b3a53e3f304df4230da967";
    std::string key1560 = "6d1fced55bef977e88cc81fecdea5afd74b482ef";
    std::string key1600 = "b639b478068ade324c0739040457a081e4b8012e";
    std::string key1640 = "d18b0d3819af4d107bca4ce2450aec6e0bcbeb1d";
    std::string key1680 = "2e1e4731cf6f32f2a57e28171282dda346ba5c79";
    std::string key1720 = "390a2d557631f5b0d64250053098a37eafaa214d";
    std::string key1760 = "9b323cbe18f90003c71149e0b3";
    std::string key = key0.append(key40).append(key80).append(key120).append(key160).append(key200).append(key240).append(key280).append(key320).append(key360).append(key400)
            .append(key440).append(key480).append(key520).append(key560).append(key600).append(key640).append(key680).append(key720).append(key760).append(key800)
            .append(key840).append(key880).append(key920).append(key960).append(key1000).append(key1040).append(key1080).append(key1120).append(key1160).append(key1200)
            .append(key1240).append(key1280).append(key1320).append(key1360).append(key1400).append(key1440).append(key1480).append(key1520).append(key1560).append(key1600)
            .append(key1640).append(key1680).append(key1720).append(key1760) ;
    return key;
}

/**
 * 计算key2
 * @return key2
 */
std::string getKey2() {
    std::string key0 = "e";
    std::string key1 = "0";
    std::string key2 = "0";
    std::string key3 = "4";
    std::string key4 = "7";
    std::string key5 = "9";
    std::string key6 = "3";
    std::string key7 = "2";
    std::string key8 = "2";
    std::string key9 = "2";
    std::string key10 = "9";
    std::string key11 = "8";
    std::string key12 = "7";
    std::string key13 = "8";
    std::string key14 = "e";
    std::string key15 = "c";
    std::string key16 = "1";
    std::string key17 = "2";
    std::string key18 = "d";
    std::string key19 = "3";
    std::string key20 = "3";
    std::string key21 = "b";
    std::string key22 = "2";
    std::string key23 = "6";
    std::string key24 = "d";
    std::string key25 = "b";
    std::string key26 = "3";
    std::string key27 = "3";
    std::string key28 = "6";
    std::string key29 = "f";
    std::string key30 = "9";
    std::string key31 = "2";
    std::string key32 = "3";
    std::string key33 = "5";
    std::string key34 = "0";
    std::string key35 = "b";
    std::string key36 = "a";
    std::string key37 = "8";
    std::string key38 = "6";
    std::string key39 = "e";
    std::string key40 = "4";
    std::string key41 = "b";
    std::string key42 = "c";
    std::string key43 = "6";
    std::string key44 = "7";
    std::string key45 = "4";
    std::string key46 = "9";
    std::string key47 = "1";
    std::string key48 = "5";
    std::string key49 = "a";
    std::string key50 = "9";
    std::string key51 = "1";
    std::string key52 = "5";
    std::string key53 = "5";
    std::string key54 = "c";
    std::string key55 = "e";
    std::string key56 = "d";
    std::string key57 = "3";
    std::string key58 = "c";
    std::string key59 = "5";
    std::string key60 = "2";
    std::string key61 = "b";
    std::string key62 = "1";
    std::string key63 = "9";
    std::string key = key0.append(key1).append(key2).append(key3).append(key4).append(key5).append(key6).append(key7).append(key8).append(key9).append(key10)
            .append(key11).append(key12).append(key13).append(key14).append(key15).append(key16).append(key17).append(key18).append(key19).append(key20)
            .append(key21).append(key22).append(key23).append(key24).append(key25).append(key26).append(key27).append(key28).append(key29).append(key30)
            .append(key31).append(key32).append(key33).append(key34).append(key35).append(key36).append(key37).append(key38).append(key39).append(key40)
            .append(key41).append(key42).append(key43).append(key44).append(key45).append(key46).append(key47).append(key48).append(key49).append(key50)
            .append(key51).append(key52).append(key53).append(key54).append(key55).append(key56).append(key57).append(key58).append(key59).append(key60)
            .append(key61).append(key62).append(key63) ;
    return key;
}
/**
 * 计算key1
 * @return key1
 */
std::string getKey1() {
    std::string key0 = "6";
    std::string key1 = "8";
    std::string key2 = "d";
    std::string key3 = "d";
    std::string key4 = "4";
    std::string key5 = "2";
    std::string key6 = "7";
    std::string key7 = "3";
    std::string key8 = "3";
    std::string key9 = "5";
    std::string key10 = "d";
    std::string key11 = "f";
    std::string key12 = "5";
    std::string key13 = "c";
    std::string key14 = "f";
    std::string key15 = "3";
    std::string key16 = "5";
    std::string key17 = "c";
    std::string key18 = "b";
    std::string key19 = "a";
    std::string key20 = "7";
    std::string key21 = "4";
    std::string key22 = "8";
    std::string key23 = "e";
    std::string key24 = "2";
    std::string key25 = "c";
    std::string key26 = "f";
    std::string key27 = "f";
    std::string key28 = "a";
    std::string key29 = "a";
    std::string key30 = "a";
    std::string key31 = "4";
    std::string key32 = "0";
    std::string key33 = "8";
    std::string key34 = "d";
    std::string key35 = "3";
    std::string key36 = "b";
    std::string key37 = "3";
    std::string key38 = "5";
    std::string key39 = "0";
    std::string key40 = "6";
    std::string key41 = "2";
    std::string key42 = "c";
    std::string key43 = "f";
    std::string key44 = "d";
    std::string key45 = "e";
    std::string key46 = "1";
    std::string key47 = "2";
    std::string key48 = "6";
    std::string key49 = "9";
    std::string key50 = "5";
    std::string key51 = "3";
    std::string key52 = "4";
    std::string key53 = "5";
    std::string key54 = "1";
    std::string key55 = "4";
    std::string key56 = "9";
    std::string key57 = "6";
    std::string key58 = "c";
    std::string key59 = "c";
    std::string key60 = "4";
    std::string key61 = "8";
    std::string key62 = "c";
    std::string key63 = "3";
    std::string key = key0.append(key1).append(key2).append(key3).append(key4).append(key5).append(key6).append(key7).append(key8).append(key9).append(key10)
            .append(key11).append(key12).append(key13).append(key14).append(key15).append(key16).append(key17).append(key18).append(key19).append(key20)
            .append(key21).append(key22).append(key23).append(key24).append(key25).append(key26).append(key27).append(key28).append(key29).append(key30)
            .append(key31).append(key32).append(key33).append(key34).append(key35).append(key36).append(key37).append(key38).append(key39).append(key40)
            .append(key41).append(key42).append(key43).append(key44).append(key45).append(key46).append(key47).append(key48).append(key49).append(key50)
            .append(key51).append(key52).append(key53).append(key54).append(key55).append(key56).append(key57).append(key58).append(key59).append(key60)
            .append(key61).append(key62).append(key63) ;
    return key;
}
/**
 * 获取双重aes加密密文，需要解密成明文,明文才是需要的key
 * @return 密文
 */
std::string getCrypto() {

    //是否开启双重aes加密
#if !HAS_DOUBLE_AES
    std::string key;
    key.assign("-----BEGIN PRIVATE KEY-----\nMIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAMYC6ECqZv8VlIExd6q1Shis7VzZWflOV6dlqw0XFpqbbUwNNkLvgTN/QiHueBmbMvvfKB+6dSIbgdVleRnDb2UCYn5Dn8UynzOEl5oufQDUf3q61sgwzyZGS98UahplHs6PhoVW43884uk9nWGGISTmOL5MdcAugMI9D+Y0isLlAgMBAAECgYEApxEG4qCjnC+aB9Mz811Yci9dagydBGMcQ8ndI4NKeBIRiqxPDvTDHy8NHlH1FS3EO40SborEj42D4wflwF4L2kIxFRAypfuQLiJS/EAtOR/luwhcAaWaAjooRpgN7x0QMxd6hlwY8w2QOt0Ega+8L7xhUY9lxkUDECNWojOANqECQQDuqNG/v1WcsaauL4cq/QaaRt1Q+W//Fhlt4+QFDkoCJ4mOmjoDMwspbPfosr+7wYgF0DY8m+sCPg9bEC+/K32dAkEA1GYDh4DLX5Vm3L57B1hSk2BPdT+4pGllkYJQz11DKD282ZAfPWoO1MErP47V3UqEhF1fyOPGNL2aYphITZd76QJAIRzxRT6B3WTUsJRNl8xVjzBH4sVJIcZqLtIQwBbUc+oSbuO9KtZ5NP02hGXQrndSrSPPcqdbewsrTEI5rbeWDQJBAIuGE+1wWqiIcRCzBAh4KY5sZuXjnPxLzA/A5irB3frSS3szpIHoaKOz3SAcSTrb159H40MI9Uvx/TelR2HJD/kCQEsuREeuUNxspUUk2x4sP0w7A51VuExnBg2Cmk5kx6yykbNxdp5zCK0S3CCSrtKXwAx7vDjUUSpdqiICQJj65bc=\n-----END PRIVATE KEY-----");
    return key;
#endif
    std::string crypto0 = "7lO72CiPgk";
    std::string crypto10 = "//HnrElxWr";
    std::string crypto20 = "9JXM0W+lBv";
    std::string crypto30 = "b63WS1fwq+";
    std::string crypto40 = "yoYfEQxduC";
    std::string crypto50 = "nEe6oyi+/e";
    std::string crypto60 = "N2Wt+Jbsqa";
    std::string crypto70 = "2uia/C9zLk";
    std::string crypto80 = "9rWQ7lwESf";
    std::string crypto90 = "swIW02gN14";
    std::string crypto100 = "etwjjMBfu2";
    std::string crypto110 = "a3+KWXD90p";
    std::string crypto120 = "igYLnzJCMe";
    std::string crypto130 = "+2AoQIm+gj";
    std::string crypto140 = "HuqIe5FmO4";
    std::string crypto150 = "4+6xWyBoLW";
    std::string crypto160 = "Bogtsz/A3Q";
    std::string crypto170 = "/uicE+zZmy";
    std::string crypto180 = "r7gkBzDu4W";
    std::string crypto190 = "0eMIYr4fIc";
    std::string crypto200 = "kYQe5913B2";
    std::string crypto210 = "YnzF88f7eJ";
    std::string crypto220 = "xVZlvz4YE4";
    std::string crypto230 = "RkPJnx20Eh";
    std::string crypto240 = "N3fMIvr4uv";
    std::string crypto250 = "7BrAad/E7f";
    std::string crypto260 = "xBbxfvbsEu";
    std::string crypto270 = "AtR/d+sFu1";
    std::string crypto280 = "GeN3xBO8jA";
    std::string crypto290 = "yebwyK3hCG";
    std::string crypto300 = "rMoSBeUkNe";
    std::string crypto310 = "AI0ACL75eK";
    std::string crypto320 = "UHpcjGMYpk";
    std::string crypto330 = "LzftHLveMD";
    std::string crypto340 = "SS8/20OudE";
    std::string crypto350 = "6SShpcMxV+";
    std::string crypto360 = "/+d2D8cqfI";
    std::string crypto370 = "/N327WYqMM";
    std::string crypto380 = "gj7mnCDSdg";
    std::string crypto390 = "k1d3fkBJpp";
    std::string crypto400 = "WWwNLHg7r8";
    std::string crypto410 = "/4VtkSiVk9";
    std::string crypto420 = "uE1voXk90G";
    std::string crypto430 = "Djy+ZJ1aiE";
    std::string crypto440 = "f31nz7JKJA";
    std::string crypto450 = "D9BCUWzH4k";
    std::string crypto460 = "7lsFPzhirn";
    std::string crypto470 = "7lrDc/0Oji";
    std::string crypto480 = "z3uahIvI4P";
    std::string crypto490 = "dWwhoafd0m";
    std::string crypto500 = "QBPIKfYQ1q";
    std::string crypto510 = "thMixMkaoP";
    std::string crypto520 = "oZ0bsEa+hv";
    std::string crypto530 = "PgtLQzch/H";
    std::string crypto540 = "lNyYDY64Os";
    std::string crypto550 = "pAqPr+Hfwz";
    std::string crypto560 = "ZZpDif4XvY";
    std::string crypto570 = "HHE8HUvrb8";
    std::string crypto580 = "3DkXd5PD3s";
    std::string crypto590 = "ydJt+rquI3";
    std::string crypto600 = "kx3JUY/1VH";
    std::string crypto610 = "qpJN1NH13k";
    std::string crypto620 = "Q4ZQDX69sb";
    std::string crypto630 = "o1jeUl+fSG";
    std::string crypto640 = "WVbUnrj7tt";
    std::string crypto650 = "c/d9x7qlKQ";
    std::string crypto660 = "3kSRXlv+B3";
    std::string crypto670 = "VTIrTWHVuk";
    std::string crypto680 = "LXsZ+C2eUN";
    std::string crypto690 = "y5DH60r6Uc";
    std::string crypto700 = "zzUL8OAcRH";
    std::string crypto710 = "/ZWf0jKoZm";
    std::string crypto720 = "KDPHX9S1X4";
    std::string crypto730 = "c4M54IS8r3";
    std::string crypto740 = "IP78Vi0vaa";
    std::string crypto750 = "g85gxgya2q";
    std::string crypto760 = "RH+tLw9zHJ";
    std::string crypto770 = "jQdqlVQQUc";
    std::string crypto780 = "GwyuZe4L/p";
    std::string crypto790 = "8ekRwmBpYY";
    std::string crypto800 = "pXRapoYOw3";
    std::string crypto810 = "cXDzYrWgIN";
    std::string crypto820 = "gzwpwZmRF1";
    std::string crypto830 = "KBkItGQjJh";
    std::string crypto840 = "8imND9nGqH";
    std::string crypto850 = "mhEz+LgDw4";
    std::string crypto860 = "rrVW6oEb2u";
    std::string crypto870 = "+Kq8YDPxHu";
    std::string crypto880 = "52f+p6FbyB";
    std::string crypto890 = "mPIPtRHAGk";
    std::string crypto900 = "Xc6yn0DKat";
    std::string crypto910 = "qJEquxx/93";
    std::string crypto920 = "SxF9TSincd";
    std::string crypto930 = "biDl2mVjjy";
    std::string crypto940 = "/VJX9Vk23W";
    std::string crypto950 = "x5bOONnl/6";
    std::string crypto960 = "tqWr5yiBwO";
    std::string crypto970 = "lsz74Lyton";
    std::string crypto980 = "rnYFg";
    std::string APIKey_Crypto_Text = crypto0.append(crypto10).append(crypto20).append(crypto30).append(crypto40).append(crypto50).append(crypto60).append(crypto70).append(crypto80).append(crypto90).append(crypto100)
            .append(crypto110).append(crypto120).append(crypto130).append(crypto140).append(crypto150).append(crypto160).append(crypto170).append(crypto180).append(crypto190).append(crypto200)
            .append(crypto210).append(crypto220).append(crypto230).append(crypto240).append(crypto250).append(crypto260).append(crypto270).append(crypto280).append(crypto290).append(crypto300)
            .append(crypto310).append(crypto320).append(crypto330).append(crypto340).append(crypto350).append(crypto360).append(crypto370).append(crypto380).append(crypto390).append(crypto400)
            .append(crypto410).append(crypto420).append(crypto430).append(crypto440).append(crypto450).append(crypto460).append(crypto470).append(crypto480).append(crypto490).append(crypto500)
            .append(crypto510).append(crypto520).append(crypto530).append(crypto540).append(crypto550).append(crypto560).append(crypto570).append(crypto580).append(crypto590).append(crypto600)
            .append(crypto610).append(crypto620).append(crypto630).append(crypto640).append(crypto650).append(crypto660).append(crypto670).append(crypto680).append(crypto690).append(crypto700)
            .append(crypto710).append(crypto720).append(crypto730).append(crypto740).append(crypto750).append(crypto760).append(crypto770).append(crypto780).append(crypto790).append(crypto800)
            .append(crypto810).append(crypto820).append(crypto830).append(crypto840).append(crypto850).append(crypto860).append(crypto870).append(crypto880).append(crypto890).append(crypto900)
            .append(crypto910).append(crypto920).append(crypto930).append(crypto940).append(crypto950).append(crypto960).append(crypto970).append(crypto980) ;
    return APIKey_Crypto_Text;
}


#endif
#endif

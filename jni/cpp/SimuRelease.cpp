//
// Created by yangyinglong on 2017/8/24.
//

#include <string>
#include "Config.h"
#include "SimuConfig.h"
#if APP == SIMU
#if RELEASE

std::string getApkSign() {
    std::string key0 = "3082037130820259a003";
    std::string key20 = "02010202042966850230";
    std::string key40 = "0d06092a864886f70d01";
    std::string key60 = "010b05003068310b3009";
    std::string key80 = "06035504061302383631";
    std::string key100 = "12301006035504081309";
    std::string key120 = "6775616e67646f6e6731";
    std::string key140 = "11300f06035504071308";
    std::string key160 = "646f6e676775616e3111";
    std::string key180 = "300f060355040a130870";
    std::string key200 = "61697368656e67311030";
    std::string key220 = "0e060355040b13077475";
    std::string key240 = "616e646169310d300b06";
    std::string key260 = "03550403130473696d75";
    std::string key280 = "3020170d313730383130";
    std::string key300 = "3032333431315a180f32";
    std::string key320 = "31313730373137303233";
    std::string key340 = "3431315a3068310b3009";
    std::string key360 = "06035504061302383631";
    std::string key380 = "12301006035504081309";
    std::string key400 = "6775616e67646f6e6731";
    std::string key420 = "11300f06035504071308";
    std::string key440 = "646f6e676775616e3111";
    std::string key460 = "300f060355040a130870";
    std::string key480 = "61697368656e67311030";
    std::string key500 = "0e060355040b13077475";
    std::string key520 = "616e646169310d300b06";
    std::string key540 = "03550403130473696d75";
    std::string key560 = "30820122300d06092a86";
    std::string key580 = "4886f70d010101050003";
    std::string key600 = "82010f003082010a0282";
    std::string key620 = "010100cfb67782001911";
    std::string key640 = "303a41ff67401dada1dd";
    std::string key660 = "6d2c5a75a7e213f4e4c1";
    std::string key680 = "a342ff6f0cec1a8a2d4e";
    std::string key700 = "aacd05056821be7a5d03";
    std::string key720 = "3c1d05247841da224cd6";
    std::string key740 = "09ef2d17d0f472ca832a";
    std::string key760 = "50990a01c64203751f47";
    std::string key780 = "ae6931c71ab6046a8d58";
    std::string key800 = "c663046da4e2f95d9db3";
    std::string key820 = "cba7069c816a257d288b";
    std::string key840 = "d91ffd8a5985bf330a56";
    std::string key860 = "cf80ff300cc22faa448f";
    std::string key880 = "71cdf1a7441601185711";
    std::string key900 = "1aca90048073389df196";
    std::string key920 = "f02550e3786e299463af";
    std::string key940 = "b97ce75f81b90fecf764";
    std::string key960 = "133f31c457358ede3104";
    std::string key980 = "c469d7f6c3864e0def4f";
    std::string key1000 = "3b06a80b083de022ef4e";
    std::string key1020 = "cbef97c83393b5b28222";
    std::string key1040 = "69287252e6563232523a";
    std::string key1060 = "276f27eefa9890825838";
    std::string key1080 = "fcf1f3c3a6cc4916b20e";
    std::string key1100 = "38d4b2ed075ea7060349";
    std::string key1120 = "027ce4f78ebf5c3dc102";
    std::string key1140 = "03010001a321301f301d";
    std::string key1160 = "0603551d0e04160414e4";
    std::string key1180 = "5ebb6f8a1ec9220d3a74";
    std::string key1200 = "d40a5e7de523159b0f30";
    std::string key1220 = "0d06092a864886f70d01";
    std::string key1240 = "010b0500038201010011";
    std::string key1260 = "4aec3d8bd3b8f6dda4eb";
    std::string key1280 = "dbf0f5fbb8e8fccdd8c3";
    std::string key1300 = "0cd6f0e668b7b13f0fba";
    std::string key1320 = "bba8575829aaf2bdcd76";
    std::string key1340 = "88af143ce43414323f03";
    std::string key1360 = "94720d54ef133c77045e";
    std::string key1380 = "40e83522258c489d9588";
    std::string key1400 = "899051afb4a81b2a9ee2";
    std::string key1420 = "81fa5097447ab565c8b4";
    std::string key1440 = "888488a8f3875ce5f17f";
    std::string key1460 = "15f24114ffc3574b7ec1";
    std::string key1480 = "fc2761e926786cb3552c";
    std::string key1500 = "68ed6ea8be82dde6a774";
    std::string key1520 = "d2abbf022dcaf4446a75";
    std::string key1540 = "122145c2811a701c316b";
    std::string key1560 = "ed1c2090ff2fb382bc3e";
    std::string key1580 = "800ba33ab6d5d9db2616";
    std::string key1600 = "7af1fcaaa17920936f09";
    std::string key1620 = "19c444037235ae24d857";
    std::string key1640 = "df08915f6cd0143593c9";
    std::string key1660 = "efc39cd39da9bc87e54c";
    std::string key1680 = "9ce4331cccdfa64ecfd9";
    std::string key1700 = "0ffff694cd4439e46685";
    std::string key1720 = "61909b986ba86ba2ef84";
    std::string key1740 = "761397448818701f1e65";
    std::string key1760 = "84baad5956";
    std::string key = key0.append(key20).append(key40).append(key60).append(key80).append(key100).append(key120).append(key140).append(key160).append(key180).append(key200)
            .append(key220).append(key240).append(key260).append(key280).append(key300).append(key320).append(key340).append(key360).append(key380).append(key400)
            .append(key420).append(key440).append(key460).append(key480).append(key500).append(key520).append(key540).append(key560).append(key580).append(key600)
            .append(key620).append(key640).append(key660).append(key680).append(key700).append(key720).append(key740).append(key760).append(key780).append(key800)
            .append(key820).append(key840).append(key860).append(key880).append(key900).append(key920).append(key940).append(key960).append(key980).append(key1000)
            .append(key1020).append(key1040).append(key1060).append(key1080).append(key1100).append(key1120).append(key1140).append(key1160).append(key1180).append(key1200)
            .append(key1220).append(key1240).append(key1260).append(key1280).append(key1300).append(key1320).append(key1340).append(key1360).append(key1380).append(key1400)
            .append(key1420).append(key1440).append(key1460).append(key1480).append(key1500).append(key1520).append(key1540).append(key1560).append(key1580).append(key1600)
            .append(key1620).append(key1640).append(key1660).append(key1680).append(key1700).append(key1720).append(key1740).append(key1760) ;
    return key;
}

/**
 * 计算key2
 * @return key2
 */
std::string getKey2() {
    std::string key0 = "c";
    std::string key1 = "5";
    std::string key2 = "7";
    std::string key3 = "e";
    std::string key4 = "8";
    std::string key5 = "3";
    std::string key6 = "f";
    std::string key7 = "f";
    std::string key8 = "e";
    std::string key9 = "c";
    std::string key10 = "d";
    std::string key11 = "8";
    std::string key12 = "3";
    std::string key13 = "7";
    std::string key14 = "2";
    std::string key15 = "1";
    std::string key16 = "a";
    std::string key17 = "f";
    std::string key18 = "7";
    std::string key19 = "3";
    std::string key20 = "e";
    std::string key21 = "b";
    std::string key22 = "b";
    std::string key23 = "2";
    std::string key24 = "9";
    std::string key25 = "7";
    std::string key26 = "b";
    std::string key27 = "4";
    std::string key28 = "0";
    std::string key29 = "3";
    std::string key30 = "1";
    std::string key31 = "c";
    std::string key32 = "3";
    std::string key33 = "7";
    std::string key34 = "e";
    std::string key35 = "1";
    std::string key36 = "e";
    std::string key37 = "7";
    std::string key38 = "9";
    std::string key39 = "0";
    std::string key40 = "e";
    std::string key41 = "4";
    std::string key42 = "2";
    std::string key43 = "d";
    std::string key44 = "c";
    std::string key45 = "2";
    std::string key46 = "7";
    std::string key47 = "f";
    std::string key48 = "2";
    std::string key49 = "2";
    std::string key50 = "6";
    std::string key51 = "0";
    std::string key52 = "9";
    std::string key53 = "2";
    std::string key54 = "7";
    std::string key55 = "2";
    std::string key56 = "7";
    std::string key57 = "4";
    std::string key58 = "0";
    std::string key59 = "e";
    std::string key60 = "a";
    std::string key61 = "3";
    std::string key62 = "b";
    std::string key63 = "0";
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
    std::string key0 = "9";
    std::string key1 = "b";
    std::string key2 = "d";
    std::string key3 = "6";
    std::string key4 = "d";
    std::string key5 = "d";
    std::string key6 = "0";
    std::string key7 = "f";
    std::string key8 = "8";
    std::string key9 = "4";
    std::string key10 = "b";
    std::string key11 = "1";
    std::string key12 = "9";
    std::string key13 = "4";
    std::string key14 = "3";
    std::string key15 = "e";
    std::string key16 = "0";
    std::string key17 = "7";
    std::string key18 = "4";
    std::string key19 = "4";
    std::string key20 = "a";
    std::string key21 = "d";
    std::string key22 = "6";
    std::string key23 = "4";
    std::string key24 = "4";
    std::string key25 = "1";
    std::string key26 = "b";
    std::string key27 = "1";
    std::string key28 = "9";
    std::string key29 = "6";
    std::string key30 = "d";
    std::string key31 = "6";
    std::string key32 = "e";
    std::string key33 = "8";
    std::string key34 = "6";
    std::string key35 = "a";
    std::string key36 = "5";
    std::string key37 = "7";
    std::string key38 = "7";
    std::string key39 = "9";
    std::string key40 = "a";
    std::string key41 = "b";
    std::string key42 = "e";
    std::string key43 = "d";
    std::string key44 = "f";
    std::string key45 = "b";
    std::string key46 = "1";
    std::string key47 = "d";
    std::string key48 = "f";
    std::string key49 = "8";
    std::string key50 = "7";
    std::string key51 = "8";
    std::string key52 = "4";
    std::string key53 = "4";
    std::string key54 = "a";
    std::string key55 = "c";
    std::string key56 = "b";
    std::string key57 = "3";
    std::string key58 = "7";
    std::string key59 = "2";
    std::string key60 = "8";
    std::string key61 = "4";
    std::string key62 = "e";
    std::string key63 = "5";
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
    std::string crypto0 = "eJ0G7g7NON";
    std::string crypto10 = "Gf/5tArGqW";
    std::string crypto20 = "HGGyoI7tdt";
    std::string crypto30 = "sMPQZH6fLn";
    std::string crypto40 = "5big9glnf0";
    std::string crypto50 = "/9IrHk1/U5";
    std::string crypto60 = "Po+LzIEoSE";
    std::string crypto70 = "CIsHJH/7Nc";
    std::string crypto80 = "t7Fnwk1vV9";
    std::string crypto90 = "jdNAQ4bMjz";
    std::string crypto100 = "Y8A30+ocHM";
    std::string crypto110 = "C/uuFMNr7Y";
    std::string crypto120 = "KsTm1CO+jH";
    std::string crypto130 = "b9JC7wIfn4";
    std::string crypto140 = "2703Nrbz5j";
    std::string crypto150 = "KmdJotUB8/";
    std::string crypto160 = "gIbWo2ERWt";
    std::string crypto170 = "3CG7W0HndR";
    std::string crypto180 = "5v37PRmu1i";
    std::string crypto190 = "8AGaTRl/WK";
    std::string crypto200 = "vA+vGVQM+P";
    std::string crypto210 = "O3ZdE2ayLd";
    std::string crypto220 = "CUfmj/STbq";
    std::string crypto230 = "lPuFpXnXkQ";
    std::string crypto240 = "k4AutA789O";
    std::string crypto250 = "gwvg92OMld";
    std::string crypto260 = "gqryAUMngD";
    std::string crypto270 = "S/QBOxqUn7";
    std::string crypto280 = "QMBTLOdoSM";
    std::string crypto290 = "ePewPKfZn8";
    std::string crypto300 = "2VcBSgTGAr";
    std::string crypto310 = "WAyBMYFTXm";
    std::string crypto320 = "sPj4lAQCGE";
    std::string crypto330 = "9iwQqsRewA";
    std::string crypto340 = "eSCwb+STro";
    std::string crypto350 = "DlBySF87DR";
    std::string crypto360 = "5yZ5bzErKl";
    std::string crypto370 = "Rys02jSTJs";
    std::string crypto380 = "MAXT/eBdDl";
    std::string crypto390 = "cKTEDB9dgr";
    std::string crypto400 = "/3d2FBMARC";
    std::string crypto410 = "sIMp0c8l1R";
    std::string crypto420 = "KJCYIwZBtM";
    std::string crypto430 = "W6im7EQMDe";
    std::string crypto440 = "EGxnPphtBk";
    std::string crypto450 = "kmXKnQ7+ZY";
    std::string crypto460 = "ZOPYegmPgl";
    std::string crypto470 = "T9DPCuy8rQ";
    std::string crypto480 = "gWhUxfZjSP";
    std::string crypto490 = "9dfuHzliXf";
    std::string crypto500 = "52jLLDU0kG";
    std::string crypto510 = "qPT7Oa8ap3";
    std::string crypto520 = "Jbii2E+P4W";
    std::string crypto530 = "PNk8X93YbO";
    std::string crypto540 = "oc7V4+X/OZ";
    std::string crypto550 = "3lzMJ7/G4e";
    std::string crypto560 = "BYkrh3hHkh";
    std::string crypto570 = "E6bW+p6JEw";
    std::string crypto580 = "wYi263/1tS";
    std::string crypto590 = "ocMa4whOGh";
    std::string crypto600 = "7/DiLfhScs";
    std::string crypto610 = "6i8IJmhZAe";
    std::string crypto620 = "O7MgyuC15A";
    std::string crypto630 = "/rt2O/DC+u";
    std::string crypto640 = "nWkDxD6ppa";
    std::string crypto650 = "woZCjcrjnk";
    std::string crypto660 = "zq/jeSvttR";
    std::string crypto670 = "dWFPgQUicw";
    std::string crypto680 = "Q9f2YrXPEE";
    std::string crypto690 = "ydOk/1GnsA";
    std::string crypto700 = "snS9mGq2nC";
    std::string crypto710 = "YhHlObjJtb";
    std::string crypto720 = "GLcvcx8oCW";
    std::string crypto730 = "cYlV/4xhep";
    std::string crypto740 = "tGG9vx9z3a";
    std::string crypto750 = "b2DozOuZ0S";
    std::string crypto760 = "76lIq0fi1l";
    std::string crypto770 = "zw07Xp3ril";
    std::string crypto780 = "S5+lPqs/8g";
    std::string crypto790 = "6u4NO+nKx4";
    std::string crypto800 = "zUPKBTH9jd";
    std::string crypto810 = "O2ZZJ/LICY";
    std::string crypto820 = "lbk9cvZdVp";
    std::string crypto830 = "YvuXobf+Y+";
    std::string crypto840 = "SbYxYG9097";
    std::string crypto850 = "2aBH2lRRy5";
    std::string crypto860 = "U2zwkCSeXU";
    std::string crypto870 = "ZvCuGd0eNH";
    std::string crypto880 = "zCn1d7r/I0";
    std::string crypto890 = "gEgu8g8AOj";
    std::string crypto900 = "Rr3vlbxdLn";
    std::string crypto910 = "cIV8aWlrij";
    std::string crypto920 = "iHAGSpNioS";
    std::string crypto930 = "ekpF3SlfhY";
    std::string crypto940 = "fh+0mjXoH5";
    std::string crypto950 = "AcP0hnqwKU";
    std::string APIKey_Crypto_Text = crypto0.append(crypto10).append(crypto20).append(crypto30).append(crypto40).append(crypto50).append(crypto60).append(crypto70).append(crypto80).append(crypto90).append(crypto100)
            .append(crypto110).append(crypto120).append(crypto130).append(crypto140).append(crypto150).append(crypto160).append(crypto170).append(crypto180).append(crypto190).append(crypto200)
            .append(crypto210).append(crypto220).append(crypto230).append(crypto240).append(crypto250).append(crypto260).append(crypto270).append(crypto280).append(crypto290).append(crypto300)
            .append(crypto310).append(crypto320).append(crypto330).append(crypto340).append(crypto350).append(crypto360).append(crypto370).append(crypto380).append(crypto390).append(crypto400)
            .append(crypto410).append(crypto420).append(crypto430).append(crypto440).append(crypto450).append(crypto460).append(crypto470).append(crypto480).append(crypto490).append(crypto500)
            .append(crypto510).append(crypto520).append(crypto530).append(crypto540).append(crypto550).append(crypto560).append(crypto570).append(crypto580).append(crypto590).append(crypto600)
            .append(crypto610).append(crypto620).append(crypto630).append(crypto640).append(crypto650).append(crypto660).append(crypto670).append(crypto680).append(crypto690).append(crypto700)
            .append(crypto710).append(crypto720).append(crypto730).append(crypto740).append(crypto750).append(crypto760).append(crypto770).append(crypto780).append(crypto790).append(crypto800)
            .append(crypto810).append(crypto820).append(crypto830).append(crypto840).append(crypto850).append(crypto860).append(crypto870).append(crypto880).append(crypto890).append(crypto900)
            .append(crypto910).append(crypto920).append(crypto930).append(crypto940).append(crypto950) ;
    return APIKey_Crypto_Text;
}


#endif
#endif
//
// Created by yangyinglong on 2017/8/24.
//

#include <string>
#include "Config.h"
#include "SimuConfig.h"
#if APP == SIMU
#if !RELEASE

std::string getApkSign() {
    std::string key0 = "3082036d30820255a003";
    std::string key20 = "02010202047a2d8d0830";
    std::string key40 = "0d06092a864886f70d01";
    std::string key60 = "010b05003066310b3009";
    std::string key80 = "06035504061302383631";
    std::string key100 = "12301006035504081309";
    std::string key120 = "6775616e67646f6e6731";
    std::string key140 = "11300f06035504071308";
    std::string key160 = "646f6e676775616e3110";
    std::string key180 = "300e060355040a130774";
    std::string key200 = "75616e6461693111300f";
    std::string key220 = "060355040b1308706169";
    std::string key240 = "7368656e67310b300906";
    std::string key260 = "03550403130274643020";
    std::string key280 = "170d3137303630383036";
    std::string key300 = "323232315a180f323231";
    std::string key320 = "37303432313036323232";
    std::string key340 = "315a3066310b30090603";
    std::string key360 = "55040613023836311230";
    std::string key380 = "10060355040813096775";
    std::string key400 = "616e67646f6e67311130";
    std::string key420 = "0f06035504071308646f";
    std::string key440 = "6e676775616e3110300e";
    std::string key460 = "060355040a1307747561";
    std::string key480 = "6e6461693111300f0603";
    std::string key500 = "55040b13087061697368";
    std::string key520 = "656e67310b3009060355";
    std::string key540 = "04031302746430820122";
    std::string key560 = "300d06092a864886f70d";
    std::string key580 = "01010105000382010f00";
    std::string key600 = "3082010a0282010100c1";
    std::string key620 = "6e982b1e0742ab56e930";
    std::string key640 = "451bd35829197dcc5d2b";
    std::string key660 = "6bee33bef19c50f52f55";
    std::string key680 = "9b5eaeaaa884edfbb402";
    std::string key700 = "059927e0df80d8bd1e98";
    std::string key720 = "e4ea93a73c1f13709b97";
    std::string key740 = "0d938ba153d265fccc95";
    std::string key760 = "d5843f270dac144eaf54";
    std::string key780 = "1dff0fa12112a93cfd9b";
    std::string key800 = "1726f0b6075ee0142c78";
    std::string key820 = "1fd4e4f5b1c3e02611f5";
    std::string key840 = "d7018364b965f9bf0457";
    std::string key860 = "315b1a45cdf562ef7eb2";
    std::string key880 = "3a6e5ceb998e1b42f442";
    std::string key900 = "4025a0d307d60ff47cf2";
    std::string key920 = "c75e9f17d40d4cc784ff";
    std::string key940 = "3b4928baafb1c28ee125";
    std::string key960 = "b32c9e5733ebde3a7318";
    std::string key980 = "0ecf44a5f16fc1204f87";
    std::string key1000 = "25561e5f4005391c39e2";
    std::string key1020 = "e2163515b5955b4bd4c1";
    std::string key1040 = "ce0e60355ad575a0ad00";
    std::string key1060 = "563036ea00257b76f767";
    std::string key1080 = "b5acf670dc4c658be2df";
    std::string key1100 = "793cf49bdc8bbb03beba";
    std::string key1120 = "fe00c1212b0203010001";
    std::string key1140 = "a321301f301d0603551d";
    std::string key1160 = "0e0416041440de9535fa";
    std::string key1180 = "835090b8a87ed9db7581";
    std::string key1200 = "004ddc249e300d06092a";
    std::string key1220 = "864886f70d01010b0500";
    std::string key1240 = "03820101007b8cdbac7c";
    std::string key1260 = "1e85839e944435a7d39a";
    std::string key1280 = "557e72a6f6fd571015e7";
    std::string key1300 = "b43948b6fb64de279d79";
    std::string key1320 = "a426e82168f9ea7d62e6";
    std::string key1340 = "89b2a93040e54f113e5a";
    std::string key1360 = "58a99c4f533a8357e871";
    std::string key1380 = "4fe87615ebd7d6fa7a51";
    std::string key1400 = "80980bb9372ed1305d41";
    std::string key1420 = "43cbf15bf53e160dece8";
    std::string key1440 = "eaaf174a12a317f62780";
    std::string key1460 = "e0113429b0782e87c679";
    std::string key1480 = "b24c27fc5e71b9de32a1";
    std::string key1500 = "b54e2a3dc6941fe99a86";
    std::string key1520 = "d943c2f0e4a7b4e4ce51";
    std::string key1540 = "4e238fcf75363b04482a";
    std::string key1560 = "f6f891d11393e6ddf66d";
    std::string key1580 = "02b18cc2f57cf50f6423";
    std::string key1600 = "3de8cfb7ab8dada75ce5";
    std::string key1620 = "0a13193103106ac656ea";
    std::string key1640 = "aa61cb64008a453623c5";
    std::string key1660 = "1b3a03d8608b76fee452";
    std::string key1680 = "48a7893c6e04025b403b";
    std::string key1700 = "f72807f184705453e0e4";
    std::string key1720 = "ef6abd0d4fbae2c1d6ba";
    std::string key1740 = "9184aaf858bd6f77adb7";
    std::string key1760 = "5a";
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
    std::string key0 = "8";
    std::string key1 = "1";
    std::string key2 = "f";
    std::string key3 = "d";
    std::string key4 = "c";
    std::string key5 = "2";
    std::string key6 = "e";
    std::string key7 = "7";
    std::string key8 = "f";
    std::string key9 = "0";
    std::string key10 = "e";
    std::string key11 = "d";
    std::string key12 = "4";
    std::string key13 = "3";
    std::string key14 = "6";
    std::string key15 = "3";
    std::string key16 = "e";
    std::string key17 = "a";
    std::string key18 = "0";
    std::string key19 = "9";
    std::string key20 = "a";
    std::string key21 = "b";
    std::string key22 = "0";
    std::string key23 = "2";
    std::string key24 = "0";
    std::string key25 = "5";
    std::string key26 = "9";
    std::string key27 = "a";
    std::string key28 = "e";
    std::string key29 = "d";
    std::string key30 = "8";
    std::string key31 = "f";
    std::string key32 = "4";
    std::string key33 = "e";
    std::string key34 = "3";
    std::string key35 = "6";
    std::string key36 = "0";
    std::string key37 = "c";
    std::string key38 = "d";
    std::string key39 = "8";
    std::string key40 = "f";
    std::string key41 = "9";
    std::string key42 = "3";
    std::string key43 = "7";
    std::string key44 = "c";
    std::string key45 = "b";
    std::string key46 = "d";
    std::string key47 = "6";
    std::string key48 = "2";
    std::string key49 = "4";
    std::string key50 = "e";
    std::string key51 = "c";
    std::string key52 = "5";
    std::string key53 = "b";
    std::string key54 = "1";
    std::string key55 = "7";
    std::string key56 = "5";
    std::string key57 = "8";
    std::string key58 = "c";
    std::string key59 = "a";
    std::string key60 = "c";
    std::string key61 = "b";
    std::string key62 = "6";
    std::string key63 = "6";
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
    std::string key0 = "2";
    std::string key1 = "d";
    std::string key2 = "a";
    std::string key3 = "3";
    std::string key4 = "7";
    std::string key5 = "c";
    std::string key6 = "e";
    std::string key7 = "b";
    std::string key8 = "d";
    std::string key9 = "f";
    std::string key10 = "e";
    std::string key11 = "5";
    std::string key12 = "c";
    std::string key13 = "1";
    std::string key14 = "e";
    std::string key15 = "f";
    std::string key16 = "6";
    std::string key17 = "5";
    std::string key18 = "2";
    std::string key19 = "5";
    std::string key20 = "8";
    std::string key21 = "1";
    std::string key22 = "5";
    std::string key23 = "e";
    std::string key24 = "0";
    std::string key25 = "f";
    std::string key26 = "0";
    std::string key27 = "7";
    std::string key28 = "d";
    std::string key29 = "2";
    std::string key30 = "e";
    std::string key31 = "6";
    std::string key32 = "8";
    std::string key33 = "f";
    std::string key34 = "b";
    std::string key35 = "f";
    std::string key36 = "7";
    std::string key37 = "4";
    std::string key38 = "1";
    std::string key39 = "c";
    std::string key40 = "3";
    std::string key41 = "c";
    std::string key42 = "6";
    std::string key43 = "2";
    std::string key44 = "d";
    std::string key45 = "a";
    std::string key46 = "f";
    std::string key47 = "8";
    std::string key48 = "e";
    std::string key49 = "f";
    std::string key50 = "8";
    std::string key51 = "a";
    std::string key52 = "f";
    std::string key53 = "9";
    std::string key54 = "5";
    std::string key55 = "e";
    std::string key56 = "a";
    std::string key57 = "b";
    std::string key58 = "4";
    std::string key59 = "f";
    std::string key60 = "3";
    std::string key61 = "4";
    std::string key62 = "1";
    std::string key63 = "c";
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
    std::string crypto0 = "nZmA6Y5xPf";
    std::string crypto10 = "pNjVwy+/PC";
    std::string crypto20 = "58s73Lf8YI";
    std::string crypto30 = "0YjjKP6S4G";
    std::string crypto40 = "rf+lGFYPDf";
    std::string crypto50 = "0U87biUKU/";
    std::string crypto60 = "dC4dMI1Dv2";
    std::string crypto70 = "H7spI398vB";
    std::string crypto80 = "oKc2gavt94";
    std::string crypto90 = "LEbGHRcUi+";
    std::string crypto100 = "zALSsuXL5a";
    std::string crypto110 = "NxNSak7V/Z";
    std::string crypto120 = "uvGgsJfsFB";
    std::string crypto130 = "1zSQGBRVAT";
    std::string crypto140 = "rkaz1RxAHJ";
    std::string crypto150 = "CZhnXilIt4";
    std::string crypto160 = "53Hs5ZJ2RD";
    std::string crypto170 = "n0NYaKa+Oe";
    std::string crypto180 = "4Ex20t79jj";
    std::string crypto190 = "oeL0kqj0bl";
    std::string crypto200 = "sl91KoBdBb";
    std::string crypto210 = "tddKJ1BN4O";
    std::string crypto220 = "nGTA3f54ah";
    std::string crypto230 = "FlXh+qNIb6";
    std::string crypto240 = "K1nT59I7GK";
    std::string crypto250 = "px5E+KHzFf";
    std::string crypto260 = "sYZdzgKU0/";
    std::string crypto270 = "R7sxb392yo";
    std::string crypto280 = "mQTGIhECFT";
    std::string crypto290 = "XNWhR9ruyH";
    std::string crypto300 = "vfpdcumXDi";
    std::string crypto310 = "n+fBcNCkfc";
    std::string crypto320 = "O5pQYDl9aw";
    std::string crypto330 = "+QEv6viUkr";
    std::string crypto340 = "9DsRrpFYxZ";
    std::string crypto350 = "7Z0K94TtoW";
    std::string crypto360 = "YAMs6s3Q/l";
    std::string crypto370 = "CvllE+C1de";
    std::string crypto380 = "5xzIWttHZ0";
    std::string crypto390 = "EDgoR0O4IK";
    std::string crypto400 = "Ud+h3hfyi7";
    std::string crypto410 = "OK9tAgoG+f";
    std::string crypto420 = "YIyeC3VAAb";
    std::string crypto430 = "EFRE6YtREq";
    std::string crypto440 = "OcBon3RsYn";
    std::string crypto450 = "kgsHQDDJne";
    std::string crypto460 = "QCUL3iBsxz";
    std::string crypto470 = "qibQ0FsJUt";
    std::string crypto480 = "yzMbYtdHwG";
    std::string crypto490 = "57lNHi4/oe";
    std::string crypto500 = "jT2d0uh7wA";
    std::string crypto510 = "y7xksFQcfi";
    std::string crypto520 = "o8DiBW/VMd";
    std::string crypto530 = "YBtr96OVwM";
    std::string crypto540 = "PHINg2Mu/6";
    std::string crypto550 = "4x5XEKsUoa";
    std::string crypto560 = "onPs3sRZgY";
    std::string crypto570 = "qH8H9FmksN";
    std::string crypto580 = "R5tjzhJKK6";
    std::string crypto590 = "2BWdNkC9ww";
    std::string crypto600 = "7GI2i0VFzR";
    std::string crypto610 = "rNN1mcahe/";
    std::string crypto620 = "7cqB9Kf8Lc";
    std::string crypto630 = "MQ6LBI8akz";
    std::string crypto640 = "rXvnYhCCUe";
    std::string crypto650 = "hWk0DsPqBa";
    std::string crypto660 = "LB2SshJHeb";
    std::string crypto670 = "PUyVj6h3rQ";
    std::string crypto680 = "pk+77RCXSH";
    std::string crypto690 = "pO8yKGk4Lz";
    std::string crypto700 = "YKJkbLHXHs";
    std::string crypto710 = "Rlyrvdf2zU";
    std::string crypto720 = "TXD8WPQM4R";
    std::string crypto730 = "pWG8tTRt9W";
    std::string crypto740 = "lZe9XLLxGg";
    std::string crypto750 = "bVq9OElSj9";
    std::string crypto760 = "wbhSY/Rx2+";
    std::string crypto770 = "nrtbvE/sTe";
    std::string crypto780 = "t1Wf5XnPCO";
    std::string crypto790 = "ibMF7AdzsN";
    std::string crypto800 = "DFkHL4uD9S";
    std::string crypto810 = "2N7pM8MAZs";
    std::string crypto820 = "fIdcwznXNc";
    std::string crypto830 = "38Lf6oM9mk";
    std::string crypto840 = "ttCaso5faO";
    std::string crypto850 = "9LkmDroRUo";
    std::string crypto860 = "Osg9OzxQ3Q";
    std::string crypto870 = "I2YQZ7P+MV";
    std::string crypto880 = "PXqdVWxKlR";
    std::string crypto890 = "iypFDxuLVQ";
    std::string crypto900 = "atKGsF1EgG";
    std::string crypto910 = "TEofyZt5Uv";
    std::string crypto920 = "R8amHYYVuI";
    std::string crypto930 = "mGWuFItRz6";
    std::string crypto940 = "mEmitfDNBl";
    std::string crypto950 = "qdDMYTrIa1";
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

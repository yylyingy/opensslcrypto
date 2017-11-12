APP_ABI  := armeabi armeabi-v7a x86 mips
APP_STL := stlport_static

#注释掉这个，将无法使用gnustl中的大小写转换,以及其他一些特性，但可以缩小so体积
#APP_STL := gnustl_static
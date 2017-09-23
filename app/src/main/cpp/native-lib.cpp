#include <jni.h>
#include <string>
#include <android/log.h>


extern "C" {
//编码
#include "libavcodec/avcodec.h"
//封装格式处理
#include "libavformat/avformat.h"
//像素处理
#include "libswscale/swscale.h"
}

#define FFLOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"ffmpeg",FORMAT,##__VA_ARGS__);
#define FFLOGE(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR,"ffmpeg",FORMAT,##__VA_ARGS__);

extern "C"
JNIEXPORT jstring JNICALL
Java_player_cn_com_netplayer_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_player_cn_com_netplayer_MainActivity_InitFFMPEG(
        JNIEnv* env,
        jobject /* this */) {
    //1.注册所有组件
    av_register_all();

    std::string hello = "av_register_all OK";
    return env->NewStringUTF(hello.c_str());
}
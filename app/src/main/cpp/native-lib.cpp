#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;
//#include <string>
//
//extern "C" JNIEXPORT jstring JNICALL
//Java_learn_kotlin_com_androidopencv_MainActivity_stringFromJNI(
//        JNIEnv* env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_opencvtest_CameraActivity_ConvertRGBtoGray(JNIEnv *env, jobject instance,
                                                                    jlong inputMat,
                                                                    jlong outputMat) {

    // 입력 RGBA 이미지를 GRAY 이미지로 변환

    Mat &inputImage = *(Mat *) inputMat;
    Mat &outputImage = *(Mat *) outputMat;

    cvtColor(inputImage, outputImage, COLOR_RGBA2GRAY);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_opencvtest_MainActivity_detectEdgeJNI(JNIEnv *env, jobject thiz,
                                        jlong inputImage, jlong outputImage,
                                        jint th1, jint th2) {
    // TODO: implement detectEdgeJNI()
    Mat &inputMat = *(Mat*) inputImage;
    Mat &outputMat = *(Mat*) outputImage;

    cvtColor(inputMat, outputMat, COLOR_RGB2GRAY);
    Canny(outputMat, outputMat, th1, th2);

}
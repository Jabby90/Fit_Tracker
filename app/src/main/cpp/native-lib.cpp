#include <jni.h>
#include <string>
#include <sstream>
#include "food_obj.h"

extern "C" JNIEXPORT jstring JNICALL
Java_jabby90_fit_1tracker_MainActivity_stringFromJNI(JNIEnv* env, jobject /* this */)
{
    //std::string hello = "Hello from C++";

    food_dictionary::food_obj tst_food_obj{"нямка", 100, 15, 20, 33};
    std::stringstream ss;
    ss << tst_food_obj.getName() << ' ' << tst_food_obj.getKcal() << ' ' << tst_food_obj.getProteins() << ' '
       << tst_food_obj.getFats() << ' ' << tst_food_obj.getCarbohydrates();

    return env->NewStringUTF(ss.str().c_str());
}
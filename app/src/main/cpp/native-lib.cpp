#include <jni.h>
#include <string>
#include <sstream>
#include "food_obj.h"

#include <fstream>

extern "C" JNIEXPORT jstring JNICALL
Java_jabby90_fit_1tracker_MainActivity_stringFromJNI
	(
		JNIEnv* env
		, jobject /* this */
		, jstring j_path // путь до директории с файлами
		, jstring j_file_name // наименование файла
	)
{
    //std::string hello = "Hello from C++";

    food_dictionary::food_obj tst_food_obj{"нямка", 100, 15, 20, 11};
    std::stringstream ss;
    ss << tst_food_obj.getName() << ' ' << tst_food_obj.getKcal() << ' ' << tst_food_obj.getProteins() << ' '
       << tst_food_obj.getFats() << ' ' << tst_food_obj.getCarbohydrates();

	// Преобразуем jstring в std::string
	const char* path_chars = env->GetStringUTFChars(j_path, nullptr);
	const char* file_chars = env->GetStringUTFChars(j_file_name, nullptr);

	std::string file_full_path = std::string(path_chars) + "/" + std::string(file_chars);

	// Освобождаем память
	env->ReleaseStringUTFChars(j_path, path_chars);
	env->ReleaseStringUTFChars(j_file_name, file_chars);


    std::ofstream out;
    out.open(file_full_path);
    out << ss.str();
    out.close();

	std::string line;
	std::ifstream in;
	in.open(file_full_path);
	std::getline(in, line);
	in.close();

	return env->NewStringUTF(file_full_path.c_str());
    ///return env->NewStringUTF(line.c_str());

}
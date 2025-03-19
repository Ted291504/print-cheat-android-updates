#include <jni.h>
#include "memory/memory.hpp"
#include "print/init.hpp"

auto start() -> void
{
	__android_log_print(ANDROID_LOG_INFO, "PRINT-CHEAT", "Waiting for %s", TARGET_LIB);
	memory::findLibrary(TARGET_LIB);

    init::start();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    __android_log_print(ANDROID_LOG_INFO, "PRINT-CHEAT", "JNI_OnLoad called");

    start();

    return JNI_VERSION_1_6;
}
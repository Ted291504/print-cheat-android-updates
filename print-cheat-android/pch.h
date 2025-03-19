#include <jni.h>
#include <errno.h>

#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#include <android/log.h>

#define TARGET_LIB "libroblox.so" // DO NOT CHANGE THIS UNLESS YOU KNOW WHAT YOU'RE DOING
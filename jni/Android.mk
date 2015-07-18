LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := TestOenGL
LOCAL_CFLAGS    := -Wall
LOCAL_SRC_FILES := JNICode.cpp Renderer.cpp
LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM 

include $(BUILD_SHARED_LIBRARY)

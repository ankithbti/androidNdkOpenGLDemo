#include "com_example_testoengl_MainActivity.h"
#include <jni.h>
#include <stdint.h>
#include <android/native_window.h> // requires ndk r5 or newer
#include <android/native_window_jni.h> // requires ndk r5 or newer
#include "Logger.hpp"
#include "Renderer.hpp"

static ANativeWindow *window = 0;
static Renderer *renderer = 0;

JNIEXPORT void JNICALL Java_com_example_testoengl_MainActivity_nativeOnStart(
		JNIEnv *, jclass) {
	LOG_INFO("nativeOnStart");
	renderer = new Renderer();
	return;
}

/*
 * Class:     com_example_testoengl_MainActivity
 * Method:    nativeOnResume
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_testoengl_MainActivity_nativeOnResume(
		JNIEnv *, jclass) {
	LOG_INFO("nativeOnResume");
	renderer->start();
	return;
}

/*
 * Class:     com_example_testoengl_MainActivity
 * Method:    nativeOnPause
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_testoengl_MainActivity_nativeOnPause(
		JNIEnv *jenv, jclass obj) {
	LOG_INFO("nativeOnPause");
	renderer->stop();
	return;
}

/*
 * Class:     com_example_testoengl_MainActivity
 * Method:    nativeOnStop
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_testoengl_MainActivity_nativeOnStop(
		JNIEnv *jenv, jclass obj) {
	LOG_INFO("nativeOnStop");
	delete renderer;
	renderer = 0;
	return;
}

/*
 * Class:     com_example_testoengl_MainActivity
 * Method:    nativeSetSurface
 * Signature: (Landroid/view/Surface;)V
 */
JNIEXPORT void JNICALL Java_com_example_testoengl_MainActivity_nativeSetSurface(
		JNIEnv *jenv, jclass obj, jobject surface) {
	if (surface != 0) {
		window = ANativeWindow_fromSurface(jenv, surface);
		LOG_INFO("Got window %p", window);
		renderer->setWindow(window);
	} else {
		LOG_INFO("Releasing window");
		ANativeWindow_release(window);
	}

	return;
}

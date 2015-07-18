/*
 * Logger.hpp
 *
 *  Created on: 18-Jul-2015
 *      Author: ankithbti
 */

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <strings.h>
#include <android/log.h>

#define  LOG_TAG    "TestOpenGL"
#define  LOG_INFO(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOG_ERROR(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#endif /* LOGGER_HPP_ */

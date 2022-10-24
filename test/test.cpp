/**
 * @file test.cpp
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com), Sharmitha Ganesan (sharmithaganesan08@gmail.com)
 * @brief Test cases to check methods YoloDetect::preProcess(), YoloDetect::detect()
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <gtest/gtest.h>
#include <iostream>
#include "../include/yoloDetect.h"

// read the test image
Mat test_frame = cv::imread("../data/test_image.jpg");
// read the network
Net test_net = cv::dnn::readNet("../yolov5s/yolov5s.onnx");

YoloDetect test;
/**
 * @brief Test 1 checks if the blobs dimension is (1,3,640,640)
 * 
 */
TEST(Test1, testPreProcess) {
  Mat test_blob = test.preProcess(test_frame);
  auto num = test_blob.size;
  int arr[4] = {1, 3, 640, 640};

  for (int i = 0; i < 4; i++) {
  EXPECT_TRUE(arr[i] == (num[i]));
  }
}

/**
 * @brief Test 2 checks if the detections dimension is (1,25200,85)
 * 
 */
TEST(Test2, testDetect) {
  Mat test_blob = test.preProcess(test_frame);
  auto detection = test.detect(test_blob, test_net);
  auto num = detection[0].size;
  int arr[3] = {1, 25200, 85};
  for (int i = 0; i < 3; i++) {
  EXPECT_TRUE(arr[i] == (num[i]));
  }
}









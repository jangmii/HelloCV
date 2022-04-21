#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main1() { //chap02

	cout << "Hello OpenCV" << CV_VERSION << endl;

	Mat img;
	img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "Image load failed" << endl;
		return -1;
	}
	//namedWindow("image"); // 창 크기 변경 불가능
	//namedWindow("image", WINDOW_NORMAL); // 창 크기 변경 가능
	//namedWindow 없어도 동작함
	imshow("image", img);

	waitKey();

	return 0;
}


int main2() { // 8page Point_ 실습
	cv::Point_<float> pt1(0.1f, 0.1f);
	cv::Point_<float> pt2(0.2f, 0.2f);
	cv::Point_<float> pt3(0.3f, 0.3f);
	cv::Point_<float> pt4(0.4f, 0.4f);
	cv::Point_<float> pt5(0.5f, 0.5f);

	cv::Point ptA1 = pt1 + pt1;
	cv::Point ptA2 = pt2 + pt2;
	cv::Point ptA3 = pt3 + pt3;
	cv::Point ptA4 = pt4 + pt4;
	cv::Point ptA5 = pt5 + pt5;

	std::cout << "ptA1 = " << ptA1 << std::endl; // [0, 0]
	std::cout << "ptA2 = " << ptA2 << std::endl; // [0, 0]
	std::cout << "ptA3 = " << ptA3 << std::endl; // [0, 0]
	std::cout << "ptA4 = " << ptA4 << std::endl; // [1, 1]
	std::cout << "ptA5 = " << ptA5 << std::endl; // [1, 1]

	return 0;
}
int main3() { // 23page Rect_ 실습

	// (30,40)에서 시작하고 크기가 100x200인 사각형
	Rect rectA(30, 40, 100, 200);
	// rectA를 (10,15)만큼 이동하고 20x30 만큼 크기를 늘린 사각형
	Rect rectB = rectA + Point(10, 15) + Size(20, 30);
	// rectA와 rectB를 포함하는 최소 크기 사각형
	Rect rectC = rectA | rectB;
	cout << rectA << endl;
	cout << rectB << endl;
	cout << rectC << endl;

	return 0;
}
int main() { // 24page Point_, Size_ and Rect_

	Mat A(100, 200, CV_8UC1, Scalar(0));
	Rect R(90, 40, 20, 20);

	Rect R1, R2;
	Point P1(-60, -10), P2(40, -10);
	Size S(20, 20);

	R1 = R + S + P1;
	R2 = R + S + P2;

	cout << R1 << endl;
	cout << R2 << endl;
	rectangle(A, R1, Scalar(255));
	rectangle(A, R2, Scalar(255));

	imshow("test", A);
	waitKey(0);
	return 0;
}
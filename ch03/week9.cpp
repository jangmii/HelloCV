#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
//chap5.12page

void brightness2() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat src_color = imread("lenna.bmp", IMREAD_COLOR);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());
	Mat dst2(src.rows, src.cols, src.type());
	Mat dst3(src_color.rows, src_color.cols, src_color.type());
	//Mat dst(); // ¿À·ù
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
	//		//int v = src.at<uchar>(j, i) + 100;
	//		//dst.at<uchar>(j, i) = v > 255 ? 255 : (v < 0 ? 0 : v);  
	//		dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
			dst3.at<Vec3b>(j, i)[0] = src_color.at<Vec3b>(j, i)[0] / 2;
		}
	}
	dst = src + 100;
	dst2 = dst - 100;
	 
	imshow("src", src);
	imshow("dst", dst);
	imshow("dst2", dst2);
	imshow("dst3", dst3);

	waitKey();

	destroyAllWindows();
}
//33page
void contrast2() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
}
int main() {
	//brightness2();
	//contrast2();
	return 0;
}
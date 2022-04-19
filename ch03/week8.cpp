#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
//18page
//int main() {
//	
//	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));
//
//	circle(img, Point(100, 100), 100, Scalar(0, 255, 0), -1, LINE_AA);
//	circle(img, Point(100, 300), 100, Scalar(0, 255, 0), -1, LINE_AA);
//	circle(img, Point(300, 100), 100, Scalar(0, 255, 0), -1, LINE_AA);
//	circle(img, Point(300, 300), 100, Scalar(0, 255, 0), -1, LINE_AA);
//
//	vector<Point> pts;
//	pts.push_back(Point(200, 100));
//	pts.push_back(Point(100, 200));
//	pts.push_back(Point(100, 300));
//	pts.push_back(Point(300, 300));
//	pts.push_back(Point(300, 200));
//	polylines(img, pts, true, Scalar(0, 0, 255), 2);
//
//	imshow("img", img);
//	waitKey(0);
//
//	destroyAllWindows();
//
//}  

//28page
//int main() {
//	Mat img(100, 600, CV_8UC3, Scalar(255, 255, 255));
//	const String s = "skku";
//	const String c = "comedu";
//	int fontFace = FONT_HERSHEY_SIMPLEX;
//	double fontScale = 2.0;
//	int thickness = 1;
//	
//	Size sizeText = getTextSize(s, fontFace, fontScale, thickness, 0);
//	Size sizeText2 = getTextSize(c, fontFace, fontScale, thickness, 0);
//	Size sizeImg = img.size();
//
//	Point org(0, sizeImg.height);
//	Point org2((sizeImg.width - sizeText2.width), sizeImg.height);
//	cout << org << endl << org2 << endl;
//
//	rectangle(img, org, org2 + Point(sizeText2.width, -sizeText2.height), Scalar(255, 0, 0), -1);
//
//	putText(img, s, org, fontFace, fontScale, Scalar(255, 255, 255), thickness);
//	putText(img, c, org2, fontFace, fontScale, Scalar(255, 255, 255), thickness);
//
//	rectangle(img, org + Point(sizeText.width, -sizeText.height), org2, Scalar(0, 0, 255), -1);
//
//	imshow("img", img);
//	waitKey(0);
//}
#include<cstdlib>
int main() {
	Mat img = imread("lenna.bmp");
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}
	namedWindow("img");
	imshow("img", img);
	cout << img.size() << endl;

	while (true) {
		int keycode = waitKey();

		if (keycode == 27) {
			break;
		}
		else if ('a' <= keycode  && keycode <= 'z') {
			const String s = (keycode); // ???
			cout << s;
			img = imread("lenna.bmp");
			putText(img, s, Point(img.size().width/2, img.size().height/2), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255), 1);
			imshow("img", img);
		}
	}
	return 0;
}
#include <iostream>

#include <fstream>

#include <highgui.hpp>


using namespace std;
using namespace cv;


bool isBitSet(char ch, int pos) {
	ch = ch >> pos;
	if(ch & 1)
		return true;
	return false;
}

int main() {

   string ipim;
	ipim = "D:/ins.png";
	Mat image = imread(ipim);
	if(image.empty()) {
		cout << "Image Error\n";
		exit(-1);
	}


    ofstream f1;
    f1.open("D://Decoded.txt",ios::out);
	char ch=0;
	int bit_count = 0;
	for(int row=0; row < image.rows; row++) {
		for(int col=0; col < image.cols; col++) {
			for(int color=0; color < 3; color++) {
				Vec3b pixel = image.at<Vec3b>(Point(row,col));
				if(isBitSet(pixel.val[color],0))
					ch |= 1;
				bit_count++;
				if(bit_count == 8) {
					if(ch == '\0')
						goto OUT;
					bit_count = 0;
					cout << ch;
					f1<<ch;
					ch = 0;
				}
				else {
					ch = ch << 1;
				}

			}
		}
	}
	OUT:;
	f1.close();
    return 0;
}

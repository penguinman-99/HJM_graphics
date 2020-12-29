#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main() {
	ofstream ofile("Ex2.ppm");
	const int img_width = 128;
	const int img_height = 128;


	vector<uint8_t> vec(img_width * img_height * 3);

	for (int i = 0; i < img_height; i++) {
		for (int j = 0; j < img_width; j++) {
			int RGB_3 = (j + i * img_width) * 3;
			if (i <= img_height / 2) {
				vec[RGB_3] = 255;
				vec[RGB_3+1] = 0;
				vec[RGB_3 + 2] = 0;
			}
			else {
				vec[RGB_3] = 0;
				vec[RGB_3 + 1] = 0;
				vec[RGB_3 + 2] = 255;
			}
		}

	}
	ofile << "P3\n" << img_width << " " << img_height << "\n" << "255\n";
	for (int i = 0; i < img_height; i++) {
		for (int j = 0; j < img_width; j++) {
			int RGB_3 = (j + i * img_width) * 3;
			for (int k = 0; k < 3; k++) {
				ofile << static_cast<int>(vec[RGB_3 + k]);
				if (j < img_width - 1 || k < 2)
					ofile << " ";

			}

		}
		ofile << "\n";
	}

	ofile << flush;
	return 0;
}
#include <iostream>
#include "EGBS.h"

using namespace std;

int main(int argc, const char *argv[]) {
    // string imageName("/home/jomian7/Desktop/graph_seg_test.png");
    string imageName("/home/jomian7/Desktop/graph_seg_test_3.png");


    if (argc > 1) {
        imageName = argv[1];
    }

    cv::Mat image = cv::imread(imageName.c_str(), CV_LOAD_IMAGE_COLOR);

    if (image.empty()) {
        cout << "Could not find or open the image" << endl;
        return -1;
    }

    EGBS egbs = EGBS();
    egbs.applySegmentation(image, 500, 50);

    cv::imshow("Modified image", image);
    // cv::imwrite("/home/jomian7/Desktop/output_graph_seg_test.png", image);
    cv::imwrite("/home/jomian7/Desktop/output_graph_seg_test_3.png", image);

    // Wait for a keystroke in the window (otherwise the program would end far too quickly)
    cv::waitKey(0);

    return 0;
}

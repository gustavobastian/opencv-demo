#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
//simple example from opencv page

int main()
{
    std::string image_path = samples::findFile("../resources/brasil.png");
    Mat img = imread(image_path, IMREAD_COLOR);
    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if(k == 's')
    {
        std::cout << "saving"<<"\n";
        imwrite("../resources/brasil.png", img);
    }
    return 0;
}
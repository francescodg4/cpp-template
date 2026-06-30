#include <opencv2/core.hpp>
#include <QApplication>
#include <QLabel>


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    cv::Mat m(200, 200, CV_8UC3);

    QWidget w;
    w.show();

    int ret = a.exec();

    return ret;
}

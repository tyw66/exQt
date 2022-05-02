#include <iostream>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
     QCoreApplication a(argc, argv);

    std::cout << "I Love WangXingJuan !!!" << std::endl;
    std::string flag;
    std::cout << "Do U Love me?(Y/N)" << std::endl;
    while(true)
    {
        std::cin >> flag;
        if(flag == "N" || flag == "n" || flag == "no" ||flag == "NO" ){
            std::cout << "Sad.....Do U Love me?(Y/N)" << std::endl;
        }
        else if(flag == "Y" || flag == "y"  || flag == "yes"  || flag == "YES" ){
            std::cout << "Heiheihei~~I Love U too~ Mua~~~" << std::endl;
            break;
        }
        else{
            std::cout << "enh~~~ Do U Love me?(Y/N)" << std::endl;
        }
    }
    std::cin >> flag;
    return 0;
}

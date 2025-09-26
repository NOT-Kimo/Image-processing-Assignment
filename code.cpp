#include "Image_Class.h"
#include <iostream>
#include <string>

using namespace std;
Image load_image()
{
    cout << "Please enter the Imagename.extension\n";
    string ImageName;
    getline(cin, ImageName);
    Image inp;
    if (inp.loadNewImage(ImageName))
        cout << "Image Loaded Successfully\n";
    else
        cout << "Failed to Load The Image.\n";
    return inp;
}
Image B_and_W(Image &img)
{

    Image output = img;
    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {
            int value = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;
            int bw;
            if (value >= 128)
                bw = 255;
            else
                bw = 0;

            for (int k = 0; k < 3; k++)
            {
                output(i, j, k) = bw;
            }
        }
    }
    return output;
}


Image InvertedImg(Image &img) {

    Image output = img;
    for ( int i =0 ; i < img.width ; i++) {


        for ( int j =0 ; j < img.height; j++) {


            for (int k =0 ; k < 3; k++) {
                output(i,j,k) = 255 -img(i,j,k);

            }

        }
    }
    
    return output;
}
Image Hflip(Image &img)
{

    Image output = img;
    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                output(i, j, k) = img((img.width - i - 1), j, k);
            }
        }
    }
    return output;
}
Image Vflip(Image &img)
{

    Image output = img;
    for (int i = 0; i < img.width; i++)
    {

        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                output(i, j, k) = img(i, img.height - j - 1, k);
            }
        }
    }
    return output;
}
void save(Image &output)
{
    string OutputName;
    cout << "Please enter the NewImageName.extension\n";
    getline(cin, OutputName);
    cout << "\n";
    if (output.saveImage("Results/" + OutputName))
        cout << "Image Saved Successfully!.\n";
    else
        cout << "Failed to Save The Image.\n";
}

void menu(){
    Image img;
    int choice;
    bool exit_flag = false;
    bool img_loaded = false;
    bool saved_flag;
    string menu_str = "0- Load Image\n"
                      "1- Filter 1 //.......\n"
                      "2- Filter 2 //Black & White\n"
                      "3- Filter 3 //Invert\n"
                      "4- Filter 4 //.......\n"
                      "5- Filter 5 //Flip\n"
                      "6- Filter 6 //.......\n"
                      "7- Save the image\n"
                      "8- Exit\n";

    do
    {
        cout << menu_str;
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 0)
        {
            img = load_image();
            img_loaded = true;
            saved_flag = false;
        }
        else if (choice == 2 && img_loaded)
        {
            img = B_and_W(img);
        }

        else if (choice == 3 && img_loaded){
            img = InvertedImg(img);
        }
        else if (choice == 5 && img_loaded)
        {
            cout << "1-Horizontal flip\n2-Vertical Flip\n";
            cin >> choice;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice == 1)
                img = Hflip(img);
            else if (choice == 2)
                img = Vflip(img);
        }
        else if (choice == 7 && img_loaded)
        {
            save(img);
            saved_flag = true;
        }
        else if (choice == 8)
        {
            if (saved_flag == false)
            {
                cout << "Do you want to save current changes?\n1-Yes\n2-No\n";
                cin >> choice;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (choice == 1)
                    save(img);
            }
            exit_flag = true;
        }
        else{
            cout << "Load an Image First.\n";
        }
    } while (exit_flag == false);

}



int main()
{

    menu();
    /*Image img;
    int choice;
    bool exit_flag = false;
    bool img_loaded = false;
    bool saved_flag;
    string menu_str = "0- Load Image\n"
                      "1- Filter 1 //.......\n"
                      "2- Filter 2 //Black & White\n"
                      "3- Filter 3 //Invert\n"
                      "4- Filter 4 //.......\n"
                      "5- Filter 5 //Flip\n"
                      "6- Filter 6 //.......\n"
                      "7- Save the image\n"
                      "8- Exit\n";

    do
    {
        cout << menu_str;
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 0)
        {
            img = load_image();
            img_loaded = true;
            saved_flag = false;
        }
        else if (choice == 2 && img_loaded)
        {
            img = B_and_W(img);
        }

        else if (choice == 3 && img_loaded){
            img = InvertedImg(img);
        }
        else if (choice == 5 && img_loaded)
        {
            cout << "1-Horizontal flip\n2-Vertical Flip\n";
            cin >> choice;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice == 1)
                img = Hflip(img);
            else if (choice == 2)
                img = Vflip(img);
        }
        else if (choice == 7 && img_loaded)
        {
            save(img);
            saved_flag = true;
        }
        else if (choice == 8)
        {
            if (saved_flag == false)
            {
                cout << "Do you want to save current changes?\n1-Yes\n2-No\n";
                cin >> choice;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (choice == 1)
                    save(img);
            }
            exit_flag = true;
        }
        else{
            cout << "Load an Image First.\n";
        }
    } while (exit_flag == false);
*/
    return 0;
}
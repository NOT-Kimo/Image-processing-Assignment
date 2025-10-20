# Image Processing Application

A comprehensive C++ image processing application that provides 18 different filters and effects for image manipulation.

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Filter Documentation](#filter-documentation)
- [Team Members](#team-members)
- [Project Structure](#project-structure)
- [Examples](#examples)
- [License](#license)

## 🎯 Overview

This project is an interactive command-line image processing application developed in C++ that supports various image formats (PNG, BMP, JPG, JPEG, TGA) and provides 18 different filters including basic operations and advanced artistic effects.

## ✨ Features

### Basic Filters (1-13)
- **Grayscaling**: Convert images to grayscale
- **Black & White**: Binary black and white conversion
- **Invert**: Invert image colors
- **Merge**: Combine two images with multiple merge options
- **Flip**: Horizontal and vertical flip operations
- **Rotate**: 90°, 180°, and 270° rotation
- **Brightness**: Darken or lighten by 50%
- **Crop**: Extract specific regions from images
- **Frame**: Add colored frames with custom thickness
- **Edge Detection**: Detect and highlight image edges
- **Resize**: Scale images by ratio or specific dimensions
- **Blur**: Apply Gaussian-style blur effect
- **Sunlight**: Add warm sunlight filter

### Bonus Filters (14-18)
- **Oil Painting**: Artistic oil painting effect
- **Old TV**: Vintage television effect with noise and scanlines
- **Purple**: Purple color tone filter
- **Infrared**: Infrared photography simulation
- **Skew**: Skew image transformation

## 🔧 Requirements

- C++ Compiler (C++11 or higher)
- Image_Class library (included in repository)
- Standard C++ libraries: `<iostream>`, `<algorithm>`, `<string>`

## 📥 Installation

1. Clone the repository:
```bash
git clone https://github.com/NOT-Kimo/Image-processing-Assignment.git
cd Image-processing-Assignment
```

2. Compile the project:
```bash
g++ -std=c++11 code.cpp Image_Class.cpp -o image_processor
```

3. Run the application:
```bash
./image_processor
```

## 🚀 Usage

1. Launch the application
2. Load an image by providing the filename with extension
3. Select a filter from the menu (0-20)
4. Follow the prompts for filter-specific options
5. Save your processed image

### Example Workflow
```
Please enter the Imagename.extension ex: (.png , .bmp , .jpg , .jpeg , .tga )
> myimage.png

[Menu appears]
Choose filter option: 1

[Image is processed]
Save the image? 
1- Overwrite existing image
2- Save new image
```

## 📖 Filter Documentation

### Filter 1: Grayscaling
Converts the image to grayscale by averaging RGB values.

### Filter 2: Black & White
Creates a binary image using threshold at 128.

### Filter 3: Invert
Inverts all color values (255 - original value).

### Filter 4: Merge Two Images
Merges two images with options:
- Equal dimensions: Simple average
- Different dimensions: Choose biggest area or common area

### Filter 5: Flip
- Horizontal flip: Mirror along vertical axis
- Vertical flip: Mirror along horizontal axis

### Filter 6: Rotate
Rotate image clockwise by:
- 90 degrees
- 180 degrees
- 270 degrees

### Filter 7: Brightness
Adjust brightness by:
- Darker: 50% reduction
- Lighter: 50% increase (capped at 255)

### Filter 8: Crop
Extract a rectangular region by specifying:
- Starting point (x, y)
- Dimensions (width, height)

### Filter 9: Add Frame
Add a colored border with:
- Custom thickness
- RGB color values (0-255)

### Filter 10: Edge Detection
Detects edges by comparing adjacent pixels in a black & white image.

### Filter 11: Resize
Two resize options:
- Scale by ratio (e.g., 0.5 = half, 2.0 = double)
- Specify exact dimensions

### Filter 12: Blur
Apply blur effect with adjustable radius (recommended: 30).

### Filter 13: Sunlight
Adds warm sunlight tones to the image.

### Filter 14: Oil Painting (Bonus)
Creates an artistic oil painting effect using intensity binning.

### Filter 15: Old TV (Bonus)
Simulates vintage TV with noise, scanlines, and distortion.

### Filter 16: Purple (Bonus)
Applies a purple color tone filter.

### Filter 17: Infrared (Bonus)
Simulates infrared photography effect.

### Filter 18: Skew (Bonus)
Applies a 45-degree skew transformation.

## 👥 Team Members

**Under Super vision of Dr. Mohamed Elramly**

### Member 1: Karim Mohamed Ramadan
- Filter 2: Black and White
- Filter 5: Horizontal and Vertical Flip
- Filter 8: Crop Image
- Filter 11: Resize Image
- Filter 14: Oil Painting (bonus)
- Filter 17: Infrared (bonus)

### Member 2: Youssef Aly El-Sayed
- Filter 3: Inverted
- Filter 6: Rotate
- Filter 9: Add Frame
- Filter 12: Blur
- Filter 15: Old TV (bonus)
- Filter 18: Skew (bonus)

### Member 3: Omar Ahmed Mostafa Allam
- Filter 1: Grayscaling
- Filter 4: Merge Two Images
- Filter 7: Darken and Lighten Image Brightness
- Filter 10: Detect Image Edges
- Filter 13: Add Sunlight (bonus)
- Filter 16: Purple (bonus)

## 📁 Project Structure

```
Image-processing-Assignment/
├── code.cpp                 # Main source code
├── Image_Class.h           # Image class header
├── Image_Class.cpp         # Image class implementation
├── README.md              # Project documentation
├── examples/              # Example input/output images
│   ├── input/
│   └── output/
└── docs/                  # Additional documentation
    ├── assignment.pdf     # Project assignment details
    └── demo_video.mp4    # Demonstration video
```

## 🖼️ Examples

Place sample input and output images in the `examples/` folder to showcase filter effects.

## 📚 Documentation Links

- [Project Document](https://drive.google.com/file/d/1FwDVUjfuS7G2Unn6V921STSNw6hYHPdt/view?usp=drive_link)
- [Demo Video](https://drive.google.com/file/d/17SbF8XvGnsMIJssaZ5NfepdOoTm9UQzq/view?usp=drive_link)

## 📝 Notes

- Some filters (merge, brightness, resize) include multiple options within the same function
- Supported image formats: PNG, BMP, JPG, JPEG, TGA
- The application includes automatic save prompts to prevent data loss

## 🤝 Contributing

This is an academic project. For contributions or suggestions, please contact the team members.

## 📄 License

This project is created for educational purposes as part of a university assignment.

---

**Course**: Image Processing  
**Institution**: Faculty of Computers and Artificial Intelligence Cairo University
**Academic Year**: 2024

# Environment Setup
### OpenCV 4.8.0
首先，安装需要的依赖
```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install build-essential cmake unzip pkg-config
sudo apt-get install libjpeg-dev libpng-dev libtiff-dev
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get install libv4l-dev libxvidcore-dev libx264-dev
sudo apt-get install libgtk-3-dev
sudo apt-get install libatlas-base-dev gfortran
```
接下来下载Opencv源码
```
https://github.com/opencv/opencv/releases
https://github.com/opencv/opencv_contrib/releases
```
分别解压，文件夹取名为**opencv**和**opencv_contrib**
在opencv文件夹下创建build文件夹，然后使用CMake编译：
```
cd ~/opencv
mkdir build
cd build
```
CMake编译命令，其中CUDA_ARCH_BIN项为GPU的框架版本。
```
cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D OPENCV_GENERATE_PKGCONFIG=ON \
	-D CMAKE_INSTALL_PREFIX=/usr/local \
	-D INSTALL_PYTHON_EXAMPLES=ON \
	-D INSTALL_C_EXAMPLES=OFF \
	-D OPENCV_ENABLE_NONFREE=ON \
	-D WITH_CUDA=ON \
	-D WITH_CUDNN=ON \
	-D OPENCV_DNN_CUDA=ON \
	-D ENABLE_FAST_MATH=1 \
	-D CUDA_FAST_MATH=1 \
	-D CUDA_ARCH_BIN=8.9 \
	-D WITH_CUBLAS=1 \
	-D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
	-D BUILD_EXAMPLES=ON ..
```
从上，WITH_CUDA和WITH_CUDNN项指的是用CUDA和cuDNN。OPENCV_DNN_CUDA项表示我们要编译后的dnn模块支持CUDA。ENABLE_FAST_MATH, CUDA_FAST_MATH和WITH_CUBLAS项是为了优化运算而开启的。**需要注意4.0以上版本默认不在生成opencv.pc文件，需要设置OPENCV_GENERATE_PKGCONFIG=ON** 
之后编译，安装：
```
make -j32
sudo make install
sudo ldconfig
```
最后配置pkg-config
```
sudo gedit /etc/ld.so.conf.d/opencv.conf
# 加入：
/usr/local/lib
####
sudo ldconfig 
sudo gedit /etc/bash.bashrc
# 加入
PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig  
export PKG_CONFIG_PATH
####
source /etc/bash.bashrc
sudo updatedb
pkg-config opencv4 --modversion

```

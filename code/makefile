OPENCV_INCLUDE := D:\opencv\opencv-4.8.0\build\install\include

OPENCV_BIN := D:\opencv\opencv-4.8.0\build\install\x64\mingw\bin

train: ModelTrainer/main.cpp ModelTrainer/DataLoader.cpp ModelTrainer/DataTrainer.cpp ModelTrainer/DataTester.cpp ModelTrainer/DataSaver.cpp
	g++ -g -o train ModelTrainer/main.cpp ModelTrainer/DataLoader.cpp ModelTrainer/DataTrainer.cpp ModelTrainer/DataTester.cpp ModelTrainer/DataSaver.cpp -I ${OPENCV_INCLUDE} -L ${OPENCV_BIN} -l opencv_world480
mkdir -p output/build
cd output/build
cmake ..
make
cd ../..
scp -i ssh/id_rsa output/build/uaserver root@$1:~/
ssh -i ssh/id_rsa -o StrictHostKeyChecking=no root@$1 "nohup ~/uaserver >~/nohup.txt 2>&1 &" 
rm -rf output/build/*
rm output/myUAModel.cpp

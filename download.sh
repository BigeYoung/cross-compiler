echo $1
scp -i ssh/id_rsa output/build/uaserver root@$1:~/
ssh -i ssh/id_rsa -o StrictHostKeyChecking=no root@$1 "nohup ~/uaserver &" 
rm -rf output/build/*
rm output/myUAModel.cpp
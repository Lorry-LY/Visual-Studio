
import matplotlib.pyplot as plt
import numpy as np
from tensorflow.examples.tutorials.mnist import input_data
mnist_data_folder="/MNIST_data"	#指定数据集所在的位置（见上图存放格式）
mnist=input_data.read_data_sets(mnist_data_folder,one_hot=True)	#读取mnist数据集，指定标签格式one_hot=True

#获取数据集的个数
train_nums=mnist.train.num_examples
validation_nums=mnist.validation.num_examples
test_nums=mnist.test.num_examples

#获取数据值
train_data=mnist.train.images   #所有训练数据
val_data=mnist.validation.images    #(5000,784)
test_data=mnist.test.images

#获取标签值
train_labels=mnist.train.labels     #(55000,10)
val_labels=mnist.validation.labels  #(5000,10)
test_labels=mnist.test.labels   #(10000,10)


#批量获取数据和标签  使用 next_batch(batch_size) 
#注意使用改方式时数据是随机读取的，但在同一批次中，数据和标签位置是对应的
'''batch_size=100  #每次批量训练100幅图像
batch_xs,batch_ys=mnist.train.next_batch(batch_size)
testbatch_xs,testbatch_ys=mnist.test.next_batch(batch_size)'''

train_count=1000 #表示要训练的数据集的个数 可以更改
count=0     #count表示查找的次数，不是训练次数

#train_data_new[train_count][785]

five_save=[0]*train_count #five_save表示记录数字5出现的地方
eight_save=[0]*train_count #eight_save表示记录数字8出现的地方

for i in range (30000): #查找5的出现的地方
    if train_labels[i][5]==1:
        five_save[count]=i
        count+=1  
    if count==train_count:
        break
    
count=0

for i in range (30000): #查找8出现的地方
    if train_labels[i][8]==1:
        eight_save[count]=i
        count+=1  
    if count==train_count:
        break

for i in range(train_count):
    train_data[eight_save[i]]=train_data[eight_save[i]]*(-1)#第二类数据反转
    
one=[1]

k=0
c=1
w=[1]*785 #初始化训练条件

all_save=np.append(five_save,eight_save)#表示所有的5和8的统计出现的位置

right=0 #right表示连续正确的个数
right_pause=train_count*2 #right_pause表示连续正确这个次数要中指判断
c=0
while(right!=right_pause):
    #前面train_count个数字表示第一类数据，也就是5；后面train_count个数字表示第二个数字，也就是8;
    if(k<=2*train_count-1):
        if(w @ np.append(train_data[all_save[k]],one)>0):
            w=w
            right=right+1
            k=k+1
            #print(w @ np.append(train_data[all_save[k]],one))
        elif(w @ np.append(train_data[all_save[k]],one)<=0):
            right=0
            for i in range (784):
                w[i]=w[i]+train_data[all_save[k]][i]
            k=k+1
    if(k==right_pause and right!=right_pause):
        k=0
    if(right==right_pause):
        break
#训练完成


#以下进行测试
test_count=100 #test_count表示要测试的数据个数，可以进行更改
find=0 #find表示查找次数
test_five_save=[0]*test_count #test_five_save表示记录数字5出现的地方
test_eight_save=[0]*test_count #test_eight_save表示记录数字8出现的地方
for i in range (10000): #查找5的出现的地方
    if test_labels[i][5]==1:
        test_five_save[find]=i
        find+=1  
    if find==test_count:
        break
for i in range (10000): #查找8出现的地方
    if test_labels[i][8]==1:
        test_eight_save[find]=i
        find+=1  
    if find==test_count:
        break
find=0

all_test_save=np.append(test_five_save,test_eight_save)#表示所有的5和8的统计出现的位置

accurate=0  #表示正确的个数

for i in range ( 2*test_count-1):
    score=0
    for j in range (783):
        score=score+w[j]*test_data[all_test_save[i]][j]
    if(score>0 and i<test_count):
        accurate+=1
    if(score<0 and i>test_count):
        accurate+=1

print("正确率为",(accurate*100)/(2*test_count),"%")
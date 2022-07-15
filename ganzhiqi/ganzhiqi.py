#from keras.datasets import mnist
#import tensorflow as tf
#import numpy as np
#from matplotlib import pyplot as plt

import cv2
# 下面俩行是我当时CPU不够尝试的方法，后面充电跑了一下发现不报错了就直接注释掉了嗯
# import os
# os.environ["CUDA_VISIBLE_DEVICES"]="-1"
import numpy as np
import tensorflow as tf
#import keras
from tensorflow import keras
#from keras import layers
from tensorflow.keras import layers


def load_mnist(): #读取离线的MNIST.npz文件。
    path = r'mnist.npz' #放置mnist.py的目录，这里默认跟本代码在同一个文件夹之下。
    f = np.load(path)
    x_train, y_train = f['x_train'], f['y_train']
    x_test, y_test = f['x_test'], f['y_test']
    f.close()
    return (x_train, y_train), (x_test, y_test)
(train_image,train_label),(test_image,test_label) = load_mnist()
print(train_image.shape)
print(train_label.shape)

#将image映射为784维向量，并映射为[0,1]之间的浮点数
train_image = train_image.reshape([60000,784])
test_image = test_image.reshape([10000,784])
train_image = train_image.astype("float32") / 255
test_image = test_image.astype("float32") / 255

#将label映射为one-hot-key的形式
num_classes = 10
train_label = keras.utils.to_categorical(train_label, num_classes)
test_label = keras.utils.to_categorical(test_label, num_classes)

print(type(train_image),type(train_label))

# #构建模型
model = keras.Sequential(
    [
        keras.Input(shape=(784,)), #这里(784,)的意思是784维向量构成的batch，省略的是batch的大小
        layers.Dense(20, activation="relu"),
        layers.Dense(20, activation="relu"),
        #layers.Dense(10, activation="relu"),
        layers.Dense(num_classes, activation="softmax"),
    ]
)
model.summary()

#模型训练和测试
model.compile(loss="categorical_crossentropy", optimizer="adam", metrics=["accuracy"])
tensorboard_callback = tf.keras.callbacks.TensorBoard(log_dir="logs")
model.fit(x=train_image, y=train_label, batch_size=32, epochs=10, validation_data=(test_image, test_label), verbose=2, callbacks=[tensorboard_callback])
score = model.evaluate(test_image, test_label, verbose=0)
print("Test loss:", score[0])
print("Test accuracy:", score[1])

model.save('model.h5')














#(x_train, y_train), (x_test, y_test) = mnist.load_data()
#print('train:x, y ', x_train.shape,y_train.shape)
#print('test:x, y ', x_test.shape,y_test.shape)

#fig, ax = plt.subplots(nrows=4, ncols=4, sharex='all', sharey='all')
#ax = ax.flatten()
#for i in range(16):
#    img = x_train[i]
#    ax[i].imshow(img,cmap='Greys')
#ax[0].set_xticks([])
#ax[0].set_yticks([])
#plt.tight_layout()
#plt.show()


##初始化变量
#batch_size=128
#nb_classes=10
#nb_epoch=20

##定义加载函数
##def load_data(path='mnist.npz'):
##    """Loads the MNIST dataset
##    #Arguments
##       path:path where to cache the dataset locally
##    #Returns
##       Tuple of Numpy arrays:`(x_train,y_train),(x_text,y_text)`
    
##    """
##    path='.\mnist.npz'
##    f=np.load(path)
##    x_train,y_train=f['x_train'],f['y_train']
##    x_test,y_test=f['x_test'],f['y_test']
##    f.close()
##    return (x_train,y_train),(x_test,y_test)

##数据准备
#(X_train, y_train), (X_test, y_test) = mnist.load_data()
#X_train = X_train.reshape(60000, 784)
#X_test = X_test.reshape(10000, 784)
#X_train = X_train.astype('float32')
#X_test = X_test.astype('float32')
#X_train /= 255
#X_test /= 255
#print(X_train.shape[0], 'train samples')
#print(X_test.shape[0], 'test samples')

## 转化类标记
##Y_train = np_utils.to_categorical(y_train, nb_classes)
##Y_test = np_utils.to_categorical(y_test, nb_classes)



##使用Sequential() model = Sequential() model.add(Dense(512, input_shape=(784,))) model.add(Activation('relu')) model.add(Dropout(0.2)) model.add(Dense(512)) model.add(Activation('relu')) model.add(Dropout(0.2)) model.add(Dense(10)) model.add(Activation('softmax'))

##打印模型
#model.summary()

##绘制结构图，并保存
#plot_model(model,to_file='model.png')

##测试和评估
#model.compile(loss='categorical_crossentropy', optimizer=RMSprop(), metrics=['accuracy'])

##迭代训练
#history = model.fit(X_train, Y_train,
#                    batch_size=batch_size, nb_epoch=nb_epoch,
#                    verbose=1, validation_data=(X_test, Y_test))

##模型估计
#score = model.evaluate(X_test, Y_test, verbose=0)
#print('Test score:', score[0])
#print('Test accuracy:', score[1])

##模型保存
#model.save('mnist-mpl.h5')
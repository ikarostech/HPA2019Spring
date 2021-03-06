from __future__ import print_function

import keras
from keras.datasets import mnist
from keras.models import load_model, Sequential
from keras.layers import Dense,BatchNormalization
from keras.optimizers import Adam

(x_train, y_train), (x_test, y_test) = mnist.load_data()
num_classes = 10

x_train = x_train.reshape(60000, 784)
x_test = x_test.reshape(10000, 784)
x_train = x_train.astype('float32')
x_test = x_test.astype('float32')
x_train /= 255
x_test /= 255
y_train = keras.utils.to_categorical(y_train, num_classes)
y_test = keras.utils.to_categorical(y_test, num_classes)

#model = Sequential()
model = load_model('mnist1.h5')
model.summary()
score = model.evaluate(x_test, y_test, verbose=0)
#print('Test loss:', score[0])
print('Test accuracy:', score[1])
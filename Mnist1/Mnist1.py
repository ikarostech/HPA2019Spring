'''Trains a simple deep NN on the MNIST dataset.
Gets to 98.40% test accuracy after 20 epochs
(there is *a lot* of margin for parameter tuning).
2 seconds per epoch on a K520 GPU.
'''

from __future__ import print_function

import keras
from keras.datasets import mnist
from keras.models import Sequential
from keras.layers import Dense,BatchNormalization
from keras.optimizers import Adam

batch_size = 128
num_classes = 10
epochs = 5

# the data, split between train and test sets
(x_train, y_train), (x_test, y_test) = mnist.load_data()

x_train = x_train.reshape(60000, 784)
x_valid = x_valid.reshape(10000, 784)
x_train = x_train.astype('float32')
x_valid = x_valid.astype('float32')
x_train /= 255
x_valid /= 255
print(x_train.shape[0], 'train samples')
print(x_valid.shape[0], 'test samples')

# convert class vectors to binary class matrices
y_train = keras.utils.to_categorical(y_train, num_classes)
y_valid = keras.utils.to_categorical(y_valid, num_classes)

#Set Neural Network Writing Method
model = Sequential()

#First layer 	(32 Perceptron)
model.add(Dense(32, activation='relu', input_shape=(784,)))
#Second Layer 	(10 Perceptron)
model.add(Dense(num_classes, activation='softmax'))

#Show Neural Network details
model.summary()

#Set Neural Network Learning Condition
model.compile(loss='categorical_crossentropy',
              optimizer=Adam(),
              metrics=['accuracy'])

#Set up TensorBoard Log file
tb_cb = keras.callbacks.TensorBoard(log_dir="./log",hitogram_freq=1)

#Execute Learning
history = model.fit(x_train, y_train,
                    batch_size=batch_size,
                    epochs=epochs,
                    verbose=1,
                    validation_data=(x_valid, y_valid))

#Evaluation
score = model.evaluate(x_valid, y_valid, verbose=0)
print('Test loss:', score[0])
print('Test accuracy:', score[1])

#Save Learned Neural Network as hdf5 file
model.save("mnist1.h5")
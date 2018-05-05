import numpy as np
import matplotlib
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.axes3d import Axes3D

def rstate(seed): return np.random.mtrand.RandomState(seed)

#
#	Various 3-dimensional datasets of N examples
#   with additive noise. Data points are color-
#   coded according to their position on the
#   low-dimensional manifold.
# 
def spiral(N=1000,noise=0.25):
	phi = rstate(1).uniform(2*np.pi,4*np.pi,[N,1])
	x = (phi)*np.cos(phi)
	y = (phi)*np.sin(phi)
	z = rstate(2).uniform(-4,4,phi.shape)
	data = np.hstack([x,y,z])
	return transform(60,30,45,noise)(data),phi

def roll(N=1000,noise=0.25):
	phi = rstate(3).uniform(2*np.pi,4*np.pi,[N,1])
	x = (phi)*np.cos(phi)
	y = (phi)*np.sin(phi)
	z = rstate(4).uniform(-10,10,phi.shape)
	data = np.hstack([x,y,z])
	return transform(60,30,45,noise)(data),phi
	
def wave(N=1000,noise=0.25):
	x=rstate(5).uniform(0,5*np.pi,[N,1])
	y=np.sin(x)
	z=rstate(6).uniform(-4,4,x.shape)
	data=np.hstack([x,y,z])
	return transform(60,30,45,noise)(data),x

def fold(N=1000,noise=0.25):
	x = rstate(7).uniform(-4,4,[N,1])
	y = 2*np.abs(x)-4
	z = rstate(8).uniform(-4,4,x.shape)
	data = np.hstack([x,y,z])
	return transform(60,30,45,noise)(data),x

def transform(x_rotation, y_rotation,z_rotation,noise):

	# normalize from degrees to radians
	x_rotation = np.pi*x_rotation/180.0
	y_rotation = np.pi*y_rotation/180.0
	z_rotation = np.pi*z_rotation/180.0

	# build the rotation matrix
	Rx=np.array([[1,0,0],[0,np.cos(x_rotation),-np.sin(x_rotation)],
		        [0,np.sin(x_rotation),np.cos(x_rotation)]])
	Ry=np.array([[np.cos(y_rotation),0,np.sin(y_rotation)],[0,1,0],
		         [-np.sin(y_rotation),0,np.cos(y_rotation)]])
	Rz=np.array([[np.cos(z_rotation),-np.sin(z_rotation),0],
		         [np.sin(z_rotation),np.cos(z_rotation),0],[0,0,1]])
	R = np.dot(Rx,np.dot(Ry,Rz)).T

	return lambda data: np.dot(data,R)+rstate(9).normal(0,noise,data.shape)

